#include <graphics.h>
#include <time.h>
#include <Windows.h>
#include "General.h"
#include "Draw.h"
#include "Tutorial.h"
#include "Save_score.h"
#include "Ball.h"
#include "Score.h"
#include "Bar.h"
#include "Menu.h"
int main()
{	
	//Khai bao
    initwindow(700,800,"Rapid roll");
	srand(time(NULL));
	struct ball b;
	struct bar1 br1;
	struct bar2 br2;
	struct bar3 br3;
	struct fence f;
	struct fence_head f_h;
    char lengtharr[3],key_press;
    int score = 0,page = 0,speed = 20,heart = 3,x,y;
    //Su kien trong tro choi
meow: menu();
while(1){
   if(GetAsyncKeyState(VK_LBUTTON)){
            x = mousex(); 
			y = mousey();
            if(x>=200 && x<=400 && y>=150 && y<=200){
				    while(1){
				    setactivepage(page);
				    setvisualpage(1-page);   	
				    cleardevice();
					draw_fence_head(f_h.td.x,f_h.td.y,f_h);   
					draw_heart(heart);	
				    setcolor(BLUE);
				    Ball(b,br1,br2,br3,f,heart);
				    Bar(score,speed,br1,br2,br3,f);
					Score(score, b,lengtharr,heart);
					if(Score(score, b,lengtharr,heart) == -1){
						goto quit;
				   			}
				    page = 1-page;
				    delay(speed);
						}
				}	
   		    if(x>=200 && x<=400 && y>=220 && y<=270){
					cleardevice();	
					Tutorial();		
					cleardevice();
					goto meow;	
	   			}
   	 	    if(x>=200 && x<=400 && y>=290 && y<=340){
               		goto quit;
				}
	
   }
   delay(15);
}
quit:
    closegraph();
	Save_score(score);
}
