int Score(int &score, struct ball &b, char lengtharr[]){
	char key_press;
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
                 setcolor(GREEN);
                 lengtharr[0]=48+score/10;
                 lengtharr[1]=48+score%10;
                 lengtharr[2]='\0';
                 outtextxy(750, 10, lengtharr);
	if (b.td.y + 40 > 800 || b.td.y - 40 < 0) {
		b.td.y = 890;
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(550,550,"AN 'ESC' DE THOAT");
                 setcolor(RED);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 7);
        outtextxy(200,250,"GAME OVER");
       	key_press = getch();    
    	if(key_press == 27){
      		return -1;
		}
}
}
