#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

int b_x=hposx+25,bR_x=hposx+100,by=hposy+83,b1_x=hposx;
int flag1ofbullet1=0,flag1ofbullet2=0;

void bullet1(){
	
		b_x -= 50;
		if(b_x<0){
			flag1ofbullet1=0;
			b_x=hposx+25;
		}
	
	
	iShowBMP2(b_x,by,"images//bullet.bmp",0);

}//bullet go to the left

void bullet2(){
	
		bR_x += 50;
		if(bR_x>1280){
			flag1ofbullet2=0;
			bR_x=hposx+100;
		}
	
	iShowBMP2(bR_x,by,"images//bullet1.bmp",0);

}//bullet go to the right

#endif//BULLET_H_INCLUDED