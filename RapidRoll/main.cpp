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
again:
	BALL b;
	BAR t, t2, t3;
	FENCE f, f2;
	initwindow(Width, Height, "Rapid Roll", 400);
	create_ball(&b);
	create_bar(&t);
	create_bar2(&t2);
	create_bar3(&t3);
	create_fence(&f);
	create_fence2(&f2);
	int page = 0;

	h = HEART;
	m = SCORE;
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
					setactivepage(page);
					setvisualpage(1 - page);
					cleardevice();
					score(&m);
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
					{
						the_end();
						if (restart == 1)
						{
							closegraph();
							Save_score(m);
							goto out;
						}
						else if (restart == 2)
						{
							cleardevice();
							closegraph();
							Save_score(m);
							goto again;
						}
					}
				}
			}
			else if (x >= 206 && x <= 464 && y >= 321 && y <= 429) {
				cleardevice();
				Tutorial();
				cleardevice();
				goto fi_choice;
			}
			else if (x >= 206 && x <= 464 && y >= 471 && y <= 579) {
				cleardevice();
				Read_score(m);
				cleardevice();
				goto fi_choice;
			}
			else if (x >= 206 && x <= 464 && y >= 621 && y <= 729) {
				goto quit;
			}
		}
		delay(20);
	}
	_getch();
quit:
	closegraph();
out:
	return 0;
}