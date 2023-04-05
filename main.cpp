#include <stdio.h>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

const int Width = 700;
const int Height = 600;

const int bk = 20;

int score = 0;

enum Trangthai {DOWN, UP, LEFT, RIGHT};

struct Toado {
	int x, y;
};

struct Ball {
	int x, y;
	int speed;
	Trangthai tt;
	bool left = false;
	bool right = false;
	
};

struct Bar {
	int x, y;
	int speed;
	Trangthai tt;
};

void khoitao_br(Bar* bar)
{
	bar->x = rand()%(Width-150);
	bar->y = 550;
	bar->speed = 7;
}

void khoitao(Ball* ball)
{
	ball->x = Width/2;
	ball->y = 100;
	ball->speed = 5;
}

void draw_bar(Bar* bar)
{
	setcolor(GREEN);
	rectangle(bar->x, bar->y, bar->x +150, bar->y +25);
	setfillstyle(SOLID_FILL, GREEN);
	floodfill(bar->x +1, bar->y +1, GREEN);
}

void draw_ball(Ball *ball)
{
	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	setcolor(LIGHTMAGENTA);
	circle(ball->x, ball->y, bk);
	floodfill(ball->x, ball->y, LIGHTMAGENTA);
}


void dieukhien(Ball* ball)
{
	if (kbhit()) {
		char key = getch();
		if (key == 'a')
		{
			ball->left = true;
			ball->right = false;
		}
		else if (key == 'd')
		{
			ball->right = true;
			ball->left = false;
		}
	}

	if (ball->left == true)
	{ 
		ball->x -= 40;
		ball->left = false;
	}
	else if (ball->right == true)
	{ 
		ball->x += 40;
		ball->right = false;
	}

	if (ball->tt == DOWN)
		ball->y += ball->speed;
	else if (ball->tt == UP)
		ball->y -= 7;
	else if (ball->tt == LEFT)
		ball->x -= ball->speed;
	else if (ball->tt == RIGHT)
		ball->x += ball->speed;
		
}


void xuli(Ball* ball)
{
	
	if (ball->x >= Width - bk - 1) {
		ball->x = Width - bk - 1;
	}
	else if (ball->x <= bk) {
		ball->x = bk;
	}
	/*else if (ball->y == 0 || ball->y == Height - bk - 1)
	{	
		cleardevice();
		
		return ;
	}*/
		
}

void xuly_t(Bar* bar)
{
	bar->tt = UP;
	if (bar->tt == UP)
		bar->y -= bar->speed;
	if (bar->y <= 50)
		khoitao_br(bar);
}

void kiemtra(Ball* ball, Bar* bar) {

	int khoang_cach = bar->y - ball->y;
	if (khoang_cach == bk + bk / 2 && ball->x >= bar->x  && ball->x <= bar->x + 150)
		ball->tt = UP;
	else
		ball->tt = DOWN;
}

int main()
{	
	srand(time(NULL));
	Ball b;
	Bar br;
	initwindow(Width, Height,"Rapid Roll", 500);
	khoitao(&b);
	khoitao_br(&br);

	while(1)
	{
		cleardevice();
		// hien thi
		draw_ball(&b);
		draw_bar(&br);
		// dieu khien

		dieukhien(&b);
		// xu li
		kiemtra(&b, &br);
		xuly_t(&br);
		
		xuli(&b);
		delay(20);
	}
	getch();
	cleardevice();
	
	return 0;

}
