void Bar(int &score,struct bar1 &br1, struct bar2 &br2,struct bar3 &br3 ){
 		draw_bar1(br1.td.x,br1.td.y,br1);
  		br1.td.y-=5;
  		draw_bar2(br2.td.x,br2.td.y,br2);
  		br2.td.y-=5;
  		draw_bar3(br3.td.x,br3.td.y,br3);
  		br3.td.y-=5;
  		if(br1.td.y == 10){
  			br1.td.y+=580;
			br1.td.x = rand()%600;		
		}
  		if(br2.td.y == 10){
  			br2.td.y+=580;
			br2.td.x = rand()%600;		
		}
  		if(br3.td.y == 10){
  			br3.td.y+=580;
			br3.td.x = rand()%600;	
		   score++;	
		}
}
