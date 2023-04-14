void menu(){
	cleardevice();
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(280,100,"MENU");
	settextstyle(10,0,2);
    rectangle(200,150,400,200);
    outtextxy(250,170,"1. Choi");
    rectangle(200,220,400,270);
    outtextxy(250,240,"2. Huong dan");
    rectangle(200,290,400,340);
    outtextxy(250,310,"3. Thoat");
}
