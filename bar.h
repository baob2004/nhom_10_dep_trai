#pragma once
#include "general.h"

typedef struct bar
{
	int x, y;
	trangThai tt;
	int speed;
}BAR;


void create_bar(BAR* t);
void create_bar2(BAR* t);
void create_bar3(BAR* t);
void bar_move(BAR* t);
void bar_move2(BAR* t);
void bar_move3(BAR* t);


void create_bar(BAR* t)
{
	srand((int)time(0));
	t->x = random(350, 550);
	t->y = Height;
	t->speed = 5;
}

void bar_move(BAR* t)
{
	setfillstyle(SOLID_FILL, WHITE);
	bar(t->x, t->y - 20, t->x + 150, t->y);
	if (m >= 1500 && m < 3000) t->speed = 6;
	else if (m >= 3000 && m < 4500) t->speed = 7;
	else if (m >= 4500 && m < 6000) t->speed = 8;
	else if (m >= 6000 && m < 7500) t->speed = 9;
	else if (m >= 7500 && m < 9000)t->speed = 10;
	else if (m >= 9000 && m < 10500) t->speed = 11;
	else if (m >= 10500) t->speed = 12;
	if (t->y >= 0)
		t->tt = UP;
	if (t->tt == UP)
		t->y -= t->speed;
	if (t->y <= 130)
	{
		t->x = random(1, Width - 150);
		t->y = Height;
	}
}

void create_bar2(BAR* t)
{
	srand((int)time(0));
	t->x = random(0, 200);
	t->y = Height + 140;
	t->speed = 5;
}

void bar_move2(BAR* t)
{
	setfillstyle(SOLID_FILL, WHITE);
	bar(t->x, t->y - 20, t->x + 150, t->y);
	if (m >= 1500 && m < 3000) t->speed = 6;
	else if (m >= 3000 && m < 4500) t->speed = 7;
	else if (m >= 4500 && m < 6000) t->speed = 8;
	else if (m >= 6000 && m < 7500) t->speed = 9;
	else if (m >= 7500 && m < 9000)t->speed = 10;
	else if (m >= 9000 && m < 10500) t->speed = 11;
	else if (m >= 10500) t->speed = 12;
	if (t->y >= 0)
		t->tt = UP;
	if (t->tt == UP)
		t->y -= t->speed;
	if (t->y <= 130)
	{
		t->x = random(1, Width - 150);
		t->y = Height;
	}
}

void create_bar3(BAR* t)
{
	srand((int)time(0));
	t->x = random(175, 375);
	t->y = Height + 420;
	t->speed = 5;
}

void bar_move3(BAR* t)
{
	setfillstyle(SOLID_FILL, WHITE);
	bar(t->x, t->y - 20, t->x + 150, t->y);
	if (m >= 1500 && m < 3000) t->speed = 6;
	else if (m >= 3000 && m < 4500) t->speed = 7;
	else if (m >= 4500 && m < 6000) t->speed = 8;
	else if (m >= 6000 && m < 7500) t->speed = 9;
	else if (m >= 7500 && m < 9000)t->speed = 10;
	else if (m >= 9000 && m < 10500) t->speed = 11;
	else if (m >= 10500) t->speed = 12;
	if (t->y >= 0)
		t->tt = UP;
	if (t->tt == UP)
		t->y -= t->speed;
	if (t->y <= 130)
	{
		t->x = random(1, Width - 150);
		t->y = Height;
	}
}
