#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED


void zom_col_hero(){
	if(z1_x<hposx+100 &&  hposy<=zy+139){
		z1_x=1380;
		life -=25;
	}
	if(z2_x<hposx+100 &&  hposy<=zy+139 ){
		z2_x=1580;
		life -=25;
	}
	if(z3_x>hposx-55 &&  hposy<=zy+139){
		z3_x=-100;
		life -=25;
	}
	if(z4_x>hposx-55 &&  hposy<=zy+139){
		z4_x=-300;
		life -=25;
	}

	
}
// Zombie colliding hero
void bul_col_zom(){
	if(b_x<z3_x+55 ){
		z3_x=-100;
		b_x=hposx+25;
		flag1ofbullet1=0;
		score += 5;
	}
	if(b_x<z4_x+55){
		z4_x=-300;
		b_x=hposx+25;
		flag1ofbullet1=0;
		score += 5;
	}
	if(bR_x>z1_x+35){
		z1_x=1380;
		bR_x=hposx+100;
		flag1ofbullet2=0;
		score += 5;
	}
	if(bR_x>z2_x+35){
		z2_x=1580;
		bR_x=hposx+100;
		flag1ofbullet2=0;
		score += 5;
	}

}
//bullet colliding zombie


void slime_col_hero(){
	if((s_x[0]>=hposx && s_x[0]<=hposx+100) && (s_y<=hposy+139 && s_y>=hposy+121)){
		life -= 35;
		score -= 7;
	}
	if((s_x[1]>=hposx && s_x[1]<=hposx+100) && (s_y<=hposy+139 && s_y>=hposy+121)){
		life -= 35;
		score -= 7;
	}
	if((s_x[2]>=hposx && s_x[2]<=hposx+100) && (s_y<=hposy+139 && s_y>=hposy+121)){
		life -= 35;
		score -= 7;
	}
	if((s_x[3]>=hposx && s_x[3]<=hposx+100) && (s_y<=hposy+139 && s_y>=hposy+121)){
		life -= 35;
		score -= 7;
	}
	if((s_x[4]>=hposx && s_x[4]<=hposx+100) && (s_y<=hposy+139 && s_y>=hposy+121)){
		life -= 35;
		score -= 7;
	}

}//slime clash with hero



#endif //COLLISION_H_INCLUDED