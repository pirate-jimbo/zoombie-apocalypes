#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED


void gameplaylvl1(){
	iClear();

	iShowBMP(0,0,"images//level1.bmp");

	//iShowBMP(bg2x,0,"images//level2.bmp");
	if(flag1ofbullet1==1){
		bullet1();
	}
	if(flag1ofbullet2==1){
		bullet2();
	}
	if(check==0){
		Hero();
	}
	if(check==1){
		heroright();
	}
	if(check==2){
		heroleft();
	}
	
	zombie();
	bul_col_zom();
	zom_col_hero();
	LifeScore();
	if(life<=0)
	{
		mode=7;
		life=250;
	}
	if(score>500){
		iPauseTimer(t1);
		iPauseTimer(t2);
		mode=8;
	}


}//level 1 background



void gameplaylvl2(){
	iShowBMP(0,0,"images//level2bg.bmp");
	if(flag1ofbullet1==1){
		bullet1();
	}
	if(flag1ofbullet2==1){
		bullet2();
	}
	if(check==0){
		Hero();
	}
	if(check==1){
		heroright();
	}
	if(check==2){
		heroleft();
	}
	
	zombie();
	bul_col_zom();
	zom_col_hero();
	slime();
	slime_col_hero();
	LifeScore();
		if(life<=0){
		mode=7;
		life=250;
	}
	
}//level 2 background 


#endif //GAMEPLAY_H_INCLUDED