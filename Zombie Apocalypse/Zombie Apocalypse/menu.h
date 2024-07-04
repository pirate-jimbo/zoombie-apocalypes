#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


void menu(){
	iShowBMP(0,0,"images//Menubg.bmp");//Background image
	iShowBMP(750,500,"images//newgame.bmp");//new game option
	iShowBMP(750,430,"images//score.bmp");//Highscore
	iShowBMP(750,360,"images//help.bmp");//Controls
	iShowBMP(750,290,"images//exit.bmp");//Exit from the Game
}//Show the menu backgroung and 4 option to select


void BackGrounds()
{
	if(mode==0){
		iShowBMP(0,0,"images//openingbg2.bmp");//Background image
		iSetColor(rand()%255,rand()%150,rand()%200);
		iText(120-(rand()%50),200-(rand()%50),"Press Home Button",GLUT_BITMAP_TIMES_ROMAN_24);//Start button
		iText(850,110,"CREDITS",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(750,70,"MINHAZUL ISLAM   ID:17.01.04.001",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(750,40,"ARAFAT UDDIN       ID:17.01.04.021",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(mode==1){
		menu();//To show the menu background and options to select
	}

	if(mode==2){
		gameplaylvl1();//New game background will show
	}

	if(mode==3){
		gameplaylvl2();//Level 2 background will show
	}

	if(mode==4){
		helpscreen();//Help screen will show about the controls
	}

	if(mode==5){
		showHighScore();//Show the HighScore
	}

	if(mode==6){
			Replay();
	}
	
		//Game over screen, have two option restart and quit
	
	if(mode==7){
		gameover();
	}
	if(mode==8){
		iShowBMP(0,0,"images//levelcomplete1.bmp");
		iSetColor(255,0,0);
		iText(300,100,"PRESS N TO GO FOR THE NEXT LEVEL",GLUT_BITMAP_TIMES_ROMAN_24);
	}//saving score

}


#endif // MENU_H_INCLUDED