#pragma once
#include "general.h"

void score(int *m)
{
	char strTime[1000];
	*m += 3;
	sprintf_s(strTime, "%d", *m);
	char p[10];
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
	strcpy(p, "Score: ");
	outtextxy(500, 40, p);
	outtextxy(600, 40, strTime);
}

void hearts(int *heart)
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	circle(50, 50, 10);
	floodfill(50, 50, YELLOW);
	char c[10];
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
	sprintf_s(c, "%c  %d", 'X', *heart);
	outtextxy(70, 40, c);
}
