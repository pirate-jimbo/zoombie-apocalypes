#ifndef HIGHSCORE_H_INCLUDED
#define HIGHSCORE_H_INCLUDED

struct highscr{
	char name[100];
	int scores;
}player[11];


void saveScore()
{
	
	player[10].scores = score;     //newScore;
	strcpy(player[10].name,name);

	SaveFile = fopen("High Score.txt", "r");

	for(int i = 0; i<10 ; i++)
	{
		fscanf(SaveFile , "%s %d\n" , &player[i].name  , &player[i].scores);
	}

	fclose(SaveFile);

	for (int i = 0 ; i<10 ; i++)
		for(int j = 10 ; j>i ; j--)
		{
			if( player[j].scores > player[j-1].scores )
			{
				temp_score = player[j-1].scores;
				player[j-1].scores = player[j].scores;
				player[j].scores = temp_score;

				strcpy( temp_name , player[j-1].name);
				strcpy( player[j-1].name , player[j].name);
				strcpy( player[j].name , temp_name);
			}
		}

	SaveFile = fopen("High Score.txt", "w");

	for(int i = 0; i<10 ; i++)
	{
		fprintf(SaveFile , "%s %d\r\n" , player[i].name  , player[i].scores);
	}

	fclose(SaveFile);
	//mode=6;
}

void showHighScore()
{
	iShowBMP(0,0,"images//highscorebg.bmp");

	SaveFile = fopen("High Score.txt", "r");

	for(int i = 0; i<10 ; i++)
	{
		fscanf(SaveFile , "%s %d\n" , &player[i].name  , &player[i].scores);
	}

	fclose(SaveFile);

	iSetColor(255 , 0 , 0);

	iText(100 , 500, "NAME", GLUT_BITMAP_TIMES_ROMAN_24);

	iText(500 , 500, "Score", GLUT_BITMAP_TIMES_ROMAN_24);

	for(int i = 0 ; i<5 ; i++)

	{
		iText( 100 , 400 - i*50 , player[i].name , GLUT_BITMAP_TIMES_ROMAN_24);
		
		itoa(player[i].scores , holdHighScore , 10);
		iText( 500 , 400 - i*50 , holdHighScore , GLUT_BITMAP_TIMES_ROMAN_24);
	}


	iSetColor(rand()%150,rand()%200,0);
	iText(120,100,"Press Home Button To Go Back",GLUT_BITMAP_TIMES_ROMAN_24);
	
}

void LifeScore(){
	iSetColor(255,0,0);
	iText(850,680,"LIFE : ",GLUT_BITMAP_TIMES_ROMAN_24);
	iFilledRectangle(950,678,life,24);
	iSetColor(255,0,0);
	iText(850,645,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
	itoa(score , scrCount , 10);
	iText(980,645,scrCount,GLUT_BITMAP_TIMES_ROMAN_24);
}//Shows hero's life and score





#endif //HIGHSCORE_H_INCLUDED