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
fi_choice: menu();
	while (1)
	{
		if (GetAsyncKeyState(VK_LBUTTON)) {
			int x = mousex();
			int y = mousey();
			if (x >= 206 && x <= 464 && y >= 171 && y <= 279)
			{
				while (1)
				{
					again:
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
					if (restart == 1) goto again;
				}
			}
			else if (x >= 206 && x <= 464 && y >= 321 && y <= 429) {
				cleardevice();
				Tutorial();
				cleardevice();
				goto fi_choice;
			}
			if (x >= 206 && x <= 464 && y >= 471 && y <= 579) {
				goto quit;
			}
		}
			delay(20);
	}
	_getch();
	quit:
	closegraph();
	return 0;
}
