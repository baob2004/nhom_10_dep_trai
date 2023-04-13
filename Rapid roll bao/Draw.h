void draw_ball(int &x, int &y,struct ball b){
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	circle(b.td.x,b.td.y,40);
	floodfill(b.td.x, b.td.y, RED);
}
void draw_bar1(int &x, int &y,struct bar1 br){
	bar(br.td.x,br.td.y,br.td.x+200,br.td.y+20);
	br.tt = UP;
}
void draw_bar2(int &x, int &y,struct bar2 br){
	bar(br.td.x,br.td.y,br.td.x+200,br.td.y+20);
	br.tt = UP;
}
void draw_bar3(int &x, int &y,struct bar3 br){
	bar(br.td.x,br.td.y,br.td.x+200,br.td.y+20);
	br.tt = UP;
}
