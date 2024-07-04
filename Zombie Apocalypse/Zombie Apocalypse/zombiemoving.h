#ifndef ZOMBIEMOVING_H_INCLUDED
#define ZOMBIEMOVING_H_INCLUDED

int z1_x=1380,z2_x=1580,z3_x=-100,z4_x=-300,zy=50;
int s_x[5];
int s_y=950;

void zombie(){
	iShowBMP2(z1_x,zy,"images//zombie1.bmp",0);//Zombie1
	iShowBMP2(z2_x,zy,"images//zombie1.bmp",0);//Zombie2
	iShowBMP2(z3_x,zy,"images//zombie2.bmp",0);//Zombie3
	iShowBMP2(z4_x,zy,"images//zombie2.bmp",0);//Zombie4
	/*if(mode==3){
		iShowBMP2(z1_x,zy,"images//zombie1.bmp",0);
		iShowBMP2(z3_x,zy,"images//zombie2.bmp",0);
	}*/
}

void slime(){
	iShowBMP2(s_x[0],s_y,"images//slime.bmp",0);
	iShowBMP2(s_x[1],s_y,"images//slime.bmp",0);
	iShowBMP2(s_x[2],s_y,"images//slime.bmp",0);
	iShowBMP2(s_x[3],s_y,"images//slime.bmp",0);
	iShowBMP2(s_x[4],s_y,"images//slime.bmp",0);
}



void zombie1(){
	z1_x -= 10;
	if(z1_x<0)
		z1_x=1280;
	//iShowBMP2(z1_x,zy,"images//zombie1.bmp",0);

	z2_x -= 10;
	if(z2_x<0)
		z2_x=1580;
		//z2_x=z1_x+(300-(rand()%150));
	//iShowBMP2(z2_x,zy,"images//zombie1.bmp",0);
}


void zombie2(){
	z3_x += 10;
	if(z3_x>1280)
		z3_x=-100;
	//iShowBMP2(z3_x,zy,"images//zombie2.bmp",0);

	z4_x += 10;
	if(z4_x>1280)
		z4_x=-300;
		//z4_x=z3_x-(rand()%150);
	//iShowBMP2(z4_x,zy,"images//zombie2.bmp",0);
}

void slimefalling(){
	s_y -= 10;
	if(s_y<0){
		s_y=950;
		s_x[0]=200-rand()%100;
		s_x[1]=350-rand()%250;
		s_x[2]=550-rand()%250;
		s_x[3]=800-rand()%250;
		s_x[4]=1100-rand()%250;
	}
}


#endif //ZOMBIEMOVING_H_INCLUDED