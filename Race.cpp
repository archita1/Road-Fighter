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
  setfillstyle(SOLID_FILL,8);
  floodfill(325,getmaxy()/2,RED);
  setcolor(RED);
  rectangle(0,200,120,250);
  gotoxy(2,15);
  cout<<"<Esc> -> Exit";
  for(level=1;(level<=5)&&(life>0);level++)
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
	  }
	 else {
	     gotoxy(2,5);
	     cout<<"Next level.";
	     delay(1000);
	     gotoxy(2,5);
	     cout<<"           ";
	     }
  for(int i=0;(i<15)&&(life>0);i++) {
	if((level==5)&&(i==14)){
	   gotoxy(5,5);
	   cout<<"You have won";
	   gotoxy(5,6);
	   cout<<"Wanna continue <y/n>";
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
	int y1=1,x1=250+((rand()%3)*50);
	int y2=1,x2=250+((rand()%3)*50);
	int y3=1,x3=150+((rand()%5)*50);
	int y4=1,x4=150+((rand()%5)*50);
	score += 10;
	while(y1<getmaxy()-1)
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
		delay(5-level);
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
