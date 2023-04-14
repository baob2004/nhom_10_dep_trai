#pragma once
#include "general.h"

typedef struct fence
{
	int x, y;
	trangThai tt;
	int speed;
}FENCE;

void create_fence(FENCE* f);
void create_fence2(FENCE* f);
void fence_move(FENCE* f);
void head_fence();
void foot_fence();

void create_fence(FENCE* f)
{
	srand((int)time(0));
	f->x = random(1, Width - 150);
	f->y = Height - 10 + 280;
	f->speed = 5;
}

void create_fence2(FENCE* f)
{
	srand((int)time(0));
	f->x = random(1, Width - 150);
	f->y = Height - 10 + 560;
	f->speed = 5;
}

void fence_move(FENCE* f)
{
	setfillstyle(SOLID_FILL, LIGHTRED);
	setcolor(LIGHTRED);
	if (m >= 15000 && m < 30000) f->speed = 6;
	else if (m >= 30000 && m < 45000) f->speed = 7;
	else if (m >= 45000 && m < 60000) f->speed = 8;
	else if (m >= 60000 && m < 75000) f->speed = 9;
	else if (m >= 75000) f->speed = 10;
	for (int i = f->x; i <= f->x + 150; i += 20)
	{
		int points[6] = { i, f->y, i + 10, f->y - 20, i + 20, f->y };
		fillpoly(3, points);
	}
	if (f->y >= 0)
		f->tt = UP;
	if (f->tt == UP)
		f->y -= f->speed;
	if (f->y <= 120)
	{
		f->x = random(1, Width - 150);
		f->y = Height - 10;
	}
}

void head_fence()
{
	for (int i = 0; i <= Width - 20; i += 20) 
	{
	
		setfillstyle(SOLID_FILL, RED);
		setcolor(RED);
		int points[6] = { i, 100, i + 10, 110, i + 20, 100 };
		fillpoly(3, points);
	}
}

void foot_fence()
{
	for (int i = 0; i <= Width - 20; i += 20)
	{
		int points[6] = { i, Height - 20, i + 10, Height - 30, i + 20, Height - 20 };
		fillpoly(3, points);
	}
}
