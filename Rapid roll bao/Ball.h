#include <graphics.h>
int Ball(struct ball &b,struct bar1 &br1, struct bar2 &br2,struct bar3 &br3){
  	draw_ball(b.td.x,b.td.y,b);
	if (b.td.y + 40 == br1.td.y && b.td.x <= br1.td.x + 200 && b.td.x >= br1.td.x) {
        b.tt = UP; 
	}
	else if (b.td.y + 40 == br2.td.y && b.td.x <= br2.td.x + 200 && b.td.x >= br2.td.x) {
        b.tt = UP; 
	}
	else if (b.td.y + 40 == br3.td.y && b.td.x <= br3.td.x + 200 && b.td.x >= br3.td.x) {
        b.tt = UP; 
	}
	else{b.tt = DOWN;}
	
    if(b.tt == DOWN){
  		b.td.y+=5;
	}
    else if(b.tt == UP){
    	b.td.y -=5;
    }   
    if(GetAsyncKeyState(VK_LEFT)){b.td.x-=7; }
    if(GetAsyncKeyState(VK_RIGHT)){b.td.x+=7; }   
}
