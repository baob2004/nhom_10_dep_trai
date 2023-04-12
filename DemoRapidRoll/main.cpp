#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "graphics.h"
#include "general.h"
#include "bar.h"
#include "ball.h"
#include "fence.h"
#include "heart.h"
#pragma comment (lib, "graphics.lib")

int main()
{
	BALL b;
	BAR t, t2, t3;
	FENCE f, f2;
	initwindow(Width, Height, "Rapid Roll");
	create_ball(&b);
	create_bar(&t);
	create_bar2(&t2);
	create_bar3(&t3);
	create_fence(&f);
	create_fence2(&f2);
	int page = 0;
	while (1)
	{
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		mark(&m);
		hearts(&h);
		head_fence();
		foot_fence();
		ball_control(&b);
		ball_move(&b, &t, &t2, &t3, &f, &f2);
		bar_move(&t);
		bar_move2(&t2);
		bar_move3(&t3);
		fence_move(&f);
		fence_move(&f2);
		page = 1 - page;
		delay(20);
		if (h == 0)
			the_end();
	}
	_getch();
	closegraph();
	return 0;
}
