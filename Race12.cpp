#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>

void makecar(int x, int y)
 {
  rectangle(x+1,y,x+49,y+100);
  rectangle(x+1,y+25,x+49,y+75);
  setfillstyle(SOLID_FILL,8);
  floodfill((x+x+50)/2,(y+y+100)/2,15);
  }

void clear(int x,int y)
 {
 setcolor(8);
 rectangle(x+1,y,x+49,y+100);
 rectangle(x+1,y+25,x+49,y+75);
 setfillstyle(SOLID_FILL,8);
 floodfill((x+x+50)/2,(y+y+100)/2,8);
 setcolor(15);
 }

void main()
 {
  int driver,mode;
  driver = DETECT;
  initgraph(&driver,&mode,"C:\\TurboC3\\BGI");
  int x=150,y=350,ch,life=3,score=0;
  int level=1;
  char choice;
  for(int m=1;m<25;m++)
	for(int n=1;n<80;n++) {
		gotoxy(n,m);
		cout<<" ";
		}
  setcolor(RED);
  rectangle(0,60,120,120);
  gotoxy(5,21);
  rectangle(150,0,401,getmaxy());
  setfillstyle(SOLID_FILL,0);
  floodfill(325,getmaxy()/2,RED);
  setcolor(RED);
  rectangle(0,200,120,250);
  gotoxy(2,15);
  cout<<"<Esc> -> Exit";
  for(level=1;(level<=4)&&(life>0);level++)
  {
	if(level==1){
	  gotoxy(2,5);
	  cout<<"Starts Now";
	  gotoxy(2,7);
	  cout<<"All the best";
	  delay(1000);
	  gotoxy(2,5);
	  cout<<"          ";
	  gotoxy(2,7);
	  cout<<"            ";
	  rectangle(150,0,401,getmaxy());
	  setfillstyle(SOLID_FILL,8);
	  floodfill(325,getmaxy()/2,RED);
      setcolor(RED);
	  }
	 else
	 if(level==2){
	     gotoxy(2,5);
	     cout<<"Level 2.";
	     delay(1000);
	     gotoxy(2,5);
	     cout<<"           ";
	     setcolor(RED);
		 rectangle(351,0,401,getmaxy());
		 setfillstyle(SOLID_FILL,BLACK);
		 floodfill(360,getmaxy()/2,BLACK);
		 setcolor(RED);
		 rectangle(150,0,350,getmaxy());
		 setfillstyle(SOLID_FILL,8);
		 floodfill(340,getmaxy()/2,RED);

	     }
	 else
	 if(level==3){
	     gotoxy(2,5);
	     cout<<"Level 3.";
	     delay(1000);
	     gotoxy(2,5);
	     cout<<"           ";
		 setcolor(RED);
		 rectangle(301,0,351,getmaxy());
		 setfillstyle(SOLID_FILL,BLACK);
		 floodfill(320,getmaxy()/2,BLACK);
		 setcolor(RED);
		 rectangle(150,0,300,getmaxy());
		 setfillstyle(SOLID_FILL,8);
		 floodfill(240,getmaxy()/2,RED);
	     }
     else
	 if(level==4){
	     gotoxy(2,5);
	     cout<<"Level 4.";
	     delay(1000);
	     gotoxy(2,5);
	     cout<<"           ";
         setcolor(RED);
		 rectangle(251,0,301,getmaxy());
		 setfillstyle(SOLID_FILL,BLACK);
		 floodfill(260,getmaxy()/2,BLACK);
		 setcolor(RED);
		 rectangle(150,0,250,getmaxy());
		 setfillstyle(SOLID_FILL,8);
		 floodfill(240,getmaxy()/2,RED);
	     }
  for(int i=0;(i<3)&&(life>0);i++) {
	if((level==4)&&(i==3)){
	   gotoxy(2,5);
	   cout<<"You have won";
	   gotoxy(2,6);
	   cout<<"Continue <y/n>";
	   cin>>choice;
	   if ((choice=='y')||(choice=='Y'))
		main();
	   else
		exit(0);
	   }
	setcolor(RED);
	rectangle(420,125,550,175);
	gotoxy(55,10);
	cout<<"Level = "<<level;
	rectangle(420,250,550,300);
	gotoxy(55,18);
	cout<<"Lives = "<<life;
	rectangle(420,350,550,400);
	gotoxy(55,24);
	cout<<"Score = "<<score;
	int accident=0;
	int y1=1,x1=150+((rand()%(6-level))*50);
	int y2=1,x2=150+((rand()%(6-level))*50);
	int y3=1,x3=150+((rand()%(6-level))*50);
	int y4=1,x4=150+((rand()%(6-level))*50);

	/*int y5=1,x5=200+((rand()%4)*50);
	int y6=1,x6=200+((rand()%4)*50);
	int y7=1,x7=200+((rand()%4)*50);

	int y8=1,x8=250+((rand()%3)*50);
	int y9=1,x9=250+((rand()%3)*50);
*/

	score += 10;
	while((y1<getmaxy()-1))// || (y5<getmaxy()-1) || (y8<getmaxy()-1))
	{
		if(level==1)
		{
		clear(x1,y1);
		clear(x2,y2);
		clear(x3,y3);
		clear(x4,y4);
		y1++;
		y2++;
		y3++;
		y4++;
		makecar(x1,y1);
		makecar(x2,y2);
		makecar(x3,y3);
		makecar(x4,y4);
		makecar(x,y);
		delay(4-level);
		}
		else
		if(level==2)
		{
		clear(x1,y1);
		clear(x2,y2);
		clear(x3,y3);
		y1++;
		y2++;
		y3++;

		makecar(x1,y1);
		makecar(x2,y2);
		makecar(x3,y3);
		makecar(x,y);
		delay(4-level);
		}
		else
		if(level==3)
		{
		clear(x1,y1);
		clear(x2,y2);
		y1++;
		y2++;
		makecar(x1,y1);
		makecar(x2,y2);
		makecar(x,y);
		delay(4-level);
		}
		else
		if(level==4)
		{
		clear(x1,y1);
		y1++;
		makecar(x1,y1);
		makecar(x,y);
		delay(4-level);
		}
		if(kbhit())
		{
			makecar(x,y);
			ch=getch();
			switch(ch) {
			case 27: exit(0);
			break;
			case 75:clear(x,y);
				if(x>150)
					x=x-50;
				makecar(x,y);
			break;
			case 77:clear(x,y);
				if(x<350)
					x=x+50;
				makecar(x,y);
			break;
			}
		}
		if((x==x1)||(x==x2))
			if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
				accident=1;

	  }
	  if(accident==1){
	    life =life-1;
	    score -= 10;
	    if(life==0) {
	     gotoxy(5,5);
	     cout<<"GAME OVER ";
	     break;
	     }
	    gotoxy(2,5);
	    cout<<"Lost 1 life";
	    delay(3000);
	    gotoxy(2,5);
	    cout<<"           ";
	    }
  }
  }
 getch();
 }
