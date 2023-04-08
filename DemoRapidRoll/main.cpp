#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "graphics.h"
#include "general.h"
#include "bar.h"
#include "ball.h"
#pragma comment (lib, "graphics.lib")

int main()
{
	BALL b;
	BAR t, t2, t3;
	initwindow(Width, Height, "Rapid Roll");
	create_ball(&b);
	create_bar(&t);
	create_bar2(&t2);
	create_bar3(&t3);
	int page = 0;
	while (1)
	{
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		ball_control(&b);
		ball_move(&b, &t, &t2, &t3);
		bar_move(&t);
		bar_move2(&t2);
		bar_move3(&t3);
		page = 1-page;
		delay(20);
	}
	_getch();
	closegraph();
	return 0;
}
