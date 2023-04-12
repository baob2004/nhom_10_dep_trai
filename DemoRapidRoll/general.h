#pragma once
#include "graphics.h"
#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define Width 700
#define Height 800
#define POINT 0;
#define HEART 3;

enum trangThai { UP, DOWN, LEFT, RIGHT };

int h = HEART;
int m = POINT;

void the_end()
{
	int last_score = m/10;
	int page = 0;
	while (1)
	{
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		char c[50];
		sprintf(c, "Your score: %d", last_score);
		outtextxy(Width / 3, Height / 2, c);
		page = 1 - page;
		delay(20);
	}
}
