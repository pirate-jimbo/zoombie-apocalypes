#ifndef HELPSCREEN_H_INCLUDED
#define HELPSCREEN_H_INCLUDED

int change=0;

void helpscreen(){
	iClear();
	iShowBMP(0,0,"images//helpsbg.bmp");
	iSetColor(255,0,0);
	iText(120,80,"Press Home Button To Go Back",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,255);
	iShowBMP2(480,450,"images//control1.bmp",0);
	
	iText(220,410,"-Press Right arrow to move Right",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(220,370,"-Press Left arrow to move Left",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(220,330,"-Press Up arrow to Jump",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(220,250,"-Press Mouse Left button to shoot Bullets",GLUT_BITMAP_TIMES_ROMAN_24);



	
}//The controls are shown in this screen


void gameover(){
	iClear();

	iSetColor(150,0,0);
	iFilledRectangle(0,0,1280,720);

	iShowBMPAlternativeSkipWhite(400,350,"images//game_over.bmp");

	iSetColor(0, 204, 0);
	iRectangle(420 , 200, 500, 70); 

	iSetColor(0 , 0 , 0);

	iText(415 , 325 , "Enter your Name: ( Click to activate the box ) " , GLUT_BITMAP_TIMES_ROMAN_24);
	if(change==1)
	{
	iText(100 , 100 , "Press 'BackSpace' key to delete character " , GLUT_BITMAP_TIMES_ROMAN_24);
		
	iText(440 , 230 , name ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
}




void Replay(){
	iClear();
	iShowBMP(0,0,"images//gameover.bmp");//Background image
	iShowBMP(200,120,"images//restart.bmp");//Restart option
	iShowBMP(800,120,"images//quit.bmp");//Quit option
}//After game Over there will two option to slet restart and quit



#endif //HELPSCREEN_H_INCLUDED