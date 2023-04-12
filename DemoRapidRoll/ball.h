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

	if (b->y == Height - 20 - b->radius)
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
	if ((b->x + 15 >= t->x && b->x - 15 <= t->x + 150) && (b->y + b->radius == t->y - 30 || b->y + b->radius == t->y - 25))
		return UP;
	else return DOWN;
}

void xu_ly_cham_fence(BALL* b, FENCE* f)
{
	if ((b->x + 15 >= f->x && b->x - 15 <= f->x + 150)
		&& (b->y + b->radius == f->y - 25 || b->y + b->radius == f->y - 20))
	{
		b->x = random(b->radius, Width - b->radius);
		b->y = b->radius + 200;
		h--;
	}
}
