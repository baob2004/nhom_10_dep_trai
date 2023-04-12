#pragma once
#include "general.h"

void mark(int *m)
{
	struct tm* crt_time;
	time_t t = time(NULL);
	crt_time = localtime(&t);
	char strTime[30];
	*m += crt_time->tm_sec;
	sprintf_s(strTime, "%d", *m/10);
	char p[10];
	strcpy(p, "Mark: ");
	outtextxy(550, 40, p);
	outtextxy(600, 40, strTime);
}

void hearts(int *heart)
{
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	circle(50, 50, 10);
	floodfill(50, 50, YELLOW);
	char c[10];
	sprintf_s(c, "%c  %d", 'X', *heart);
	outtextxy(70, 42, c);
}