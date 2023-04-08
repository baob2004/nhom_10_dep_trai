#pragma once
#include "general.h"
#include "bar.h"

typedef struct ball
{
	int x, y, radius;
	trangThai tt;
	int speed;
}BALL;

void create_ball(BALL* b)
{
	srand((int)time(0));
	b->radius = 30;
	b->x = random(b->radius, Width - b->radius);
	b->y = b->radius;
	b->speed = 5;
}

int xu_ly(BALL* b, BAR* t);

void ball_move(BALL* b, BAR* t, BAR* t2, BAR* t3)
{
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	circle(b->x, b->y, b->radius);
	floodfill(b->x, b->y, RED);

	if (xu_ly(b, t) == UP || xu_ly(b, t2) == UP || xu_ly(b, t3) == UP)
		b->y -= t->speed;
	else b->y += b->speed;

	if (b->y == Height - b->radius)
	{
		b->y = b->radius;
		b->x = random(b->radius, Width - b->radius);
	}
}

void ball_control(BALL* b)
{
	if (GetAsyncKeyState(VK_LEFT))
		b->x -= b->speed;
	else if (GetAsyncKeyState(VK_RIGHT))
		b->x += b->speed;
}

int xu_ly(BALL* b, BAR* t)
{
	if ((b->x >= t->x && b->x <= t->x + 150) && b->y + b->radius == t->y - 30)
		return UP;
	else return DOWN;
}