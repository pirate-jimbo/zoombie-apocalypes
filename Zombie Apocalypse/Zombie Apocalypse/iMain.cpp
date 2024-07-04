# include "iGraphics.h"
#include "bitmap_loader.h"

int t,t1,t2,t3,t4;  //  timers

int mode=0; // menu selextion variable

int bgx=0;
int bg2x=1280;//background image rendering

//hero's position
int hposx=450;
int hposy=50;
int px=10;
int check=0;
int h_pos=0;//hero jumping variable
// hero's position

//score count variables
typedef struct highscr highs;



int newScore;
int score=0;
FILE *SaveFile;
int temp_score;
char temp_name[100];

char scrCount[100];
char holdHighScore[100];
char name[100];
char name2[100];
int nameL = 0;
int life=250;
//Score counting variables


#include "heromoving.h"
#include "zombiemoving.h"
#include "bullet.h"
#include "collision.h"
#include "HighScore.h"
#include "gameplay.h"
#include "helpscreen.h"
#include "menu.h"
//#include "bitmap_viewer.h"


int ball_x, ball_y;
int dx, dy;
//int mode=0;

//mode 0 = Starting screen
//mode 1 = Home Screen
//mode 2,3= Gameplay Screen
//mode 4 = Help Screen
//mode 5 = Highscore
//mode 6 = Replay Screen
//mode 7 = game over


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();
	BackGrounds();//Will Call the backgrounds according to the func.
	printf("\n %d",mode);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mode==1)
		{
			if((mx>=750 && mx<=1150) && (my>=500 && my<=550))
			{
				mode=2;
				iResumeTimer(t1);
				iResumeTimer(t2);
			}
			if((mx>=750 && mx<=1150) && (my>=430 && my<=480))
				mode=5;
			if((mx>=750 && mx<=1150) && (my>=360 && my<=410))
				mode=4;
			if((mx>=750 && mx<=1150) && (my>=290 && my<=340))
				exit(0);
		}//Selecting options in menu screen

		if(mode==6)
		{
			if((mx>=200 && mx<=542) && (my>=120 && my<=207))
				mode=1;
			if((mx>=800 && mx<=1126) && (my>=120 && my<=209))
				exit(0);
		}//Selecting options in game over screen
		if(mode== 7)
		{
			if(mx >= 435 && mx <= 795 && my >= 200 && my <= 270 )
		{
			change = 1;
		}
		}
		if(mode==2 || mode==3){
			PlaySound("sound//Gunshot.wav",NULL,SND_ASYNC);
				if(mx<1280 && mx>0 && my<720 && my>0){
					if(check==2){   // hero facing left side
						flag1ofbullet1=1;
					}
					if(check==1){   // herp facing right side
						flag1ofbullet2=1;
					}
				}
		}

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	
	if(mode == 7 && change==1)
	{
        if(key == '\r' )
		{
			
			//strcpy( name2 , name);
			saveScore();
			score = 0;
			//strcpy(scrCount,'\0');
	
			for(int i = 0 ; i < nameL ; i++)
				name[i] = 0;
			nameL = 0;

			mode=6;
			change=0;
			//mode=6;
		}

		else if(key == '\b')
		//if (mode==7 && change==1)
		{
			nameL--;
			name[nameL] = 0;
		}
	
		
		else
		{
			name[nameL] = key;
			nameL++;
			
			
		}
	}
	
	if(key == 'm' && mode==2)
	{
		mode=3;
		//do something with 'q'
		
	}
	if(mode == 8){
		if(key == 'n'){
			mode=3;
			iResumeTimer(t1);
			iResumeTimer(t2);
		}
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_HOME)
	{
		mode=1;
		life=250;
		iPauseTimer(t2);
		iPauseTimer(t1);
	}

	if(key == GLUT_KEY_END)
	{
		mode=7;
	}
	if(key == GLUT_KEY_RIGHT) // hero movement
	{
		if(mode==2 || mode==3){
			heroright();
			if(hposx<1210)
				hposx += px;
		}
	}
	if(key == GLUT_KEY_LEFT) // hero movement
	{
		if(mode==2 || mode==3){
			heroleft();
			if(hposx>10)
				hposx -= px;
		}
	}
	if(key == GLUT_KEY_UP)
	{
		iResumeTimer(t);
	}
	//place your codes for other keys here
}


void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	
	if(mx==2){}       /*Something to do with mx*/
 //else if(my== 2){}   /*Something to do with my*/

}

int main()
{
	//place your own initialization codes here.

	t=iSetTimer(25,herojump);
	t1=iSetTimer(30,zombie1);
	t2=iSetTimer(40,zombie2);
	t3=iSetTimer(15,slimefalling);
	
	iInitialize(1280, 720, "Zombie Apocalypse");

	return 0;
}

