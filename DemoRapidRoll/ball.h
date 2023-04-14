#pragma once
#include "general.h"
#include "bar.h"
#include "fence.h"

typedef struct ball
{
	int x, y, radius;
	trangThai tt;
	int speed;
}BALL;

void create_ball(BALL* b);
void ball_move(BALL* b, BAR* t, BAR* t2, BAR* t3, FENCE* f, FENCE* f2);
void ball_control(BALL* b);
int xu_ly(BALL* b, BAR* t);
void xu_ly_cham_fence(BALL* b, FENCE* f);

void create_ball(BALL* b)
{
	srand((int)time(0));
	b->radius = 20;
	b->x = random(b->radius, Width - b->radius);
	b->y = b->radius + 200;
	b->speed = 5;
}


void ball_move(BALL* b, BAR* t, BAR* t2, BAR* t3, FENCE *f, FENCE *f2)
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(b->x, b->y, b->radius);
	floodfill(b->x, b->y, YELLOW);
	
	if (xu_ly(b, t) == UP || xu_ly(b, t2) == UP || xu_ly(b, t3) == UP)
		b->y -= t->speed;
	else b->y += b->speed;

	xu_ly_cham_fence(b, f);
	xu_ly_cham_fence(b, f2);

	if (b->y >= Height - 20 - b->radius)
	{
		b->y = b->radius + 200;
		b->x = random(b->radius, Width - b->radius);
		h--;
	}
	else if (b->y <= b->radius + 100)
	{
		b->y = b->radius + 200;
		b->x = random(b->radius, Width - b->radius);
		h--;
	}
}

void ball_control(BALL* b)
{
	if (GetAsyncKeyState(VK_LEFT))
		b->x -= (b->speed+2);
	else if (GetAsyncKeyState(VK_RIGHT))
		b->x += (b->speed+2);
	if (b->x >= Width)
		b->x = b->radius;
	else if (b->x <= 0)
		b->x = Width - b->radius;
}

int xu_ly(BALL* b, BAR* t)
{
		if ((b->x + 15 >= t->x && b->x - 15 <= t->x + 150) &&
			(b->y + b->radius == t->y - 34
			|| b->y + b->radius == t->y - 33
			|| b->y + b->radius == t->y - 32
			|| b->y + b->radius == t->y - 31
			|| b->y + b->radius == t->y - 30
			|| b->y + b->radius == t->y - 29
			|| b->y + b->radius == t->y - 28
			|| b->y + b->radius == t->y - 27
			|| b->y + b->radius == t->y - 26
			|| b->y + b->radius == t->y - 25
			|| b->y + b->radius == t->y - 24
			|| b->y + b->radius == t->y - 23
			|| b->y + b->radius == t->y - 22
			|| b->y + b->radius == t->y - 21
			|| b->y + b->radius == t->y - 20
			))
			return UP;
		else return DOWN;
}

void xu_ly_cham_fence(BALL* b, FENCE* f)
{
		if ((b->x + 15 >= f->x && b->x - 15 <= f->x + 150)
			&& (b->y + b->radius == f->y - 22
				|| b->y + b->radius == f->y - 23
				|| b->y + b->radius == f->y - 24
				|| b->y + b->radius == f->y - 25 
				|| b->y + b->radius == f->y - 26
				|| b->y + b->radius == f->y - 27
				|| b->y + b->radius == f->y - 28
				|| b->y + b->radius == f->y - 29
				|| b->y + b->radius == f->y - 30
				|| b->y + b->radius == f->y - 31
				|| b->y + b->radius == f->y - 32
				|| b->y + b->radius == f->y - 33
				|| b->y + b->radius == f->y - 34
				|| b->y + b->radius == f->y - 35))
		{
			b->x = random(b->radius, Width - b->radius);
			b->y = b->radius + 200;
			h--;
		}
}
