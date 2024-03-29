#pragma once
#include "graphics.h"
#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define Width 700
#define Height 800
#define SCORE 0;
#define HEART 3;

enum trangThai { UP, DOWN, LEFT, RIGHT };

int h = HEART;
int m = SCORE;
int restart = 0;

void menu();
void the_end();
void Tutorial();


void menu() {
	srand(time(NULL));
	char c[20];
	cleardevice();
	setcolor(RED);
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 7);
	strcpy(c, "RAPID ROLL");
	outtextxy(100, 50, c);
	setcolor(YELLOW);
	settextstyle(SIMPLEX_FONT, HORIZ_DIR, 3);

	rectangle(210, 175, 460, 275);
	rectangle(209, 174, 461, 276);
	rectangle(208, 173, 462, 277);
	rectangle(207, 172, 463, 278);
	rectangle(206, 171, 464, 279);
	strcpy(c, "BAT DAU");
	setcolor(WHITE);
	outtextxy(265, 215, c);

	setcolor(YELLOW);
	rectangle(210, 325, 460, 425);
	rectangle(209, 324, 461, 426);
	rectangle(208, 323, 462, 427);
	rectangle(207, 322, 463, 428);
	rectangle(206, 321, 464, 429);
	strcpy(c, "HUONG DAN");
	setcolor(WHITE);
	outtextxy(235, 365, c);

	setcolor(YELLOW);
	rectangle(210, 475, 460, 575);
	rectangle(209, 474, 461, 576);
	rectangle(208, 473, 462, 577);
	rectangle(207, 472, 463, 578);
	rectangle(206, 471, 464, 579);
	strcpy(c, "THOAT GAME");
	setcolor(WHITE);
	outtextxy(225, 515, c);
}


void the_end()
{
	int last_score = m;
	int page = 0;
	while (1)
	{
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		char c[50];
		setcolor(WHITE);
		settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
		sprintf(c, "Your score: %d", last_score);
		outtextxy(Width / 3, Height / 2, c);
		strcpy(c, "Press enter to back to menu");
		outtextxy(Width / 3 - 100, Height / 2 + 50, c);
		strcpy(c, "Esc to quit");
		outtextxy(Width / 3 - 100, Height / 2 + 100, c);
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			restart = 1;
			break;
		}
		else if (GetAsyncKeyState(13))
		{
			restart = 2;
			break;
		}
		page = 1 - page;
		delay(20);
	}
}

void Tutorial() {
	srand(time(NULL));
	char c[50];

	cleardevice();
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
	strcpy(c, "AN MUI TEN <= HOAC => DE DI CHUYEN");
	outtextxy(30, 250, c);
	strcpy(c, "CO GANG DUNG BI ROI NHE");
	outtextxy(120, 300, c);
	strcpy(c, "DUNG CHAM VAO GAI");
	outtextxy(150, 350, c);
	delay(5000);

}
