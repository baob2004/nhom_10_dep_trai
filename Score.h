int Score(int &score, struct ball &b, char lengtharr[],int &heart){
	char key_press;
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
                 setcolor(GREEN);
                 lengtharr[0]=48+score/10;
                 lengtharr[1]=48+score%10;
                 lengtharr[2]='\0';
                 outtextxy(650, 35, lengtharr);
                 
	if (b.td.y + 40 >= 800 || b.td.y - 40 <= 0) {
		b.td.x = rand()%680;
		b.td.y = 200;
		heart--;
}
	if (heart == 0 || heart <0){
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
        outtextxy(480,750,"AN 'ESC' DE THOAT");
        setcolor(RED);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 7);
        outtextxy(150,250,"GAME OVER");
       	key_press = getch();    
    	if(key_press == 27){
      		return -1;
		}else{
			key_press = getch();  
		}
	}
}
