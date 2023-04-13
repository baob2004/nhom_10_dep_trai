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
int main()
{	
	//Khai bao
    initwindow(800,600,"Rapid roll");
	struct ball b;
	struct bar1 br1;
	struct bar2 br2;
	struct bar3 br3;
	srand(time(NULL));
    char lengtharr[3],key_press;
    int score = 0,page = 0;
    Tutorial();
    //Su kien trong tro choi
    while(1){
    setactivepage(page);
    setvisualpage(1-page);   	
    cleardevice();   	
    setcolor(BLUE);
    Ball(b,br1,br2,br3);
	Bar(score,br1,br2,br3);
	
	//Score
	Score(score, b,lengtharr);
	if(Score(score, b,lengtharr) == -1){
		break;
	}
	
	//
	page = 1-page;
    delay(15.9999999999999999999999);
	}
    closegraph();
	Save_score(score);
}
