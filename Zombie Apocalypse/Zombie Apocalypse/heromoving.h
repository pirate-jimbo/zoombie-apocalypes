#ifndef HEROMOVING_H_INCLUDED
#define HEROMOVING_H_INCLUDED


void Hero(){
	iShowBMP2(hposx,hposy,"images//hero.bmp",0);
}//Show the hero

void heroright(){
	iShowBMP2(hposx,hposy,"images//hero.bmp",0);
	
	check=1; 
}//hero facing right

void heroleft(){
	iShowBMP2(hposx,hposy,"images//hero1.bmp",0);
	
	check=2;
}//hero facing left

void herojump(){
	if(h_pos==0){
		hposy += 10;
		if(hposy >=300)
			h_pos=1;
	}
	if(h_pos==1){
		hposy -= 10;
		if(hposy == 50){
			h_pos=0;
			iPauseTimer(t);
		}
	}
}

#endif // MENU_H_INCLUDED