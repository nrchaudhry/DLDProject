#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <math.h>
#include "g:\cld\basic.h"
#include "g:\cld\mouse.h"
#include "g:\cld\load.h"

void bx(int x1,int y1,int x2,int y2);
void box(void);
int check11(int x,int y);
int check12(int x,int y);
void blink(int cx);
void blink1(int cx);
void blink2(int cx);
int push(void);
void mbar(int selected, int previous );
int menu(void);
int desi(void);
void desion1(void);
void sound(void);

char option[7][40]={" Number System "," Binary Arithmatic", " Boolean Algebra"," Minimization of Boolean Function"," Logic Elements "," Combination Circuit "," Q  U  I  T  " };
int colum = 160,rows[7] = {90,140,190,240,290,340,390};

void main(void)
{
	int gdriver,gmode;
	int ch1=0,result;
	mouseinit();
	gdriver = DETECT;
//	registerbgidriver(EGAVGA_driver);
//	initgraph(&gdriver,&gmode,"");
	initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
	start();

	setcursorpos(getmaxx()/2,getmaxy()/2);

	while (ch1== 0)
	{
		result=menu();
		if (result==0)
		{
			desion1();
			cursoroff();
			system("num-sys.exe c d b");
		}
		if (result==1)
		{
			desion1();
			cursoroff();
			system("bin-art.exe c d b");
		}
		if (result==2)
		{
			desion1();
			cursoroff();
			system("boo-alg.exe c d b");
		}
		if (result==3)
		{
			desion1();
			cursoroff();
			system("boolean.exe c d b");
		}
		if (result==4)
		{
			desion1();
			cursoroff();
			system("gatesfun.exe c d b");
		}
		if (result==5)
		{
			desion1();
			cursoroff();
			system("com-cir.exe c d b");
		}
		if (result==6)
		{
			ch1=desi();
			if (ch1)
			{
//				startup("Good Bye");
  //				getch();
				closegraph();
			}
		}
	}

	closegraph();
}

int menu(void)
{
	int px,py,x1,x2,y1,y2,a,b,c,d;
	char ch;
	int r1,c1,chio;

	setbkcolor(0);
	setfillstyle(SOLID_FILL,0);
	bar(0,0,getmaxx(),getmaxy());

	for (a = 0;a < 10000;a++)
	     putpixel(random(1000),random(1050),3);
	bx(126,62,518,445);

	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(100,15,125,53);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(525,15,550,53);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(125,10,525,50);
	line(125,10,525,10);
	setcolor(0);
	line(125,10,125,53);
	line(124,10,124,53);
	line(525,10,525,53);
	line(526,10,526,53);

	r1 = 15;
	c1 = 78;
	setcolor(7);
	for (int i=0;i<22;i++)
	{
		line(c1,r1,100,32);
		c1++;
	}
	r1 = 32;
	c1 = 100;
	setcolor(7);
	for (i=0;i<22;i++)
	{
		line(c1,r1,100,r1);
		c1--;
		r1++;
	}
	r1 = 32;
	c1 = 575;
	setcolor(7);
	for (i=0;i<25;i++)
	{
		line(550,r1,c1,53);
		c1--;
	}
	r1 = 15;
	c1 = 575;
	setcolor(7);
	for (i=0;i<22;i++)
	{
		line(550,r1,c1,r1);
		c1--;
		r1++;
	}

	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setcolor(0);
	outtextxy(175,10,"M A I N  M E N U");
	outtextxy(176,11,"M A I N  M E N U");
	setcolor(14);
	outtextxy(174,9,"M A I N  M E N U");
	outtextxy(173,9,"M A I N  M E N U");

	setfillstyle(SOLID_FILL,3);
	bar(133,78,517,449);

	settextstyle(1, HORIZ_DIR, 4);
	setfillstyle(SOLID_FILL,7);
	setcolor(0);
	bar(colum,rows[0],colum+335,rows[0]+35);
	outtextxy(203,84,"Number System");
	bar(colum,rows[1],colum+335,rows[1]+35);
	outtextxy(185,134,"Binary Arithmatic");
	bar(colum,rows[2],colum+335,rows[2]+35);
	outtextxy(210,185,"Boolean Algebra");
	bar(colum,rows[4],colum+335,rows[4]+35);
	outtextxy(245,285,"Logic Gates");
	bar(colum,rows[5],colum+335,rows[5]+35);
	outtextxy(170,334,"Combination Circuit");
	bar(colum,rows[6],colum+335,rows[6]+35);
	outtextxy(210,386,"  Q  U  I  T  ");
	settextstyle(1, HORIZ_DIR, 1);
	bar(colum,rows[3],colum+335,rows[3]+35);
	outtextxy(170,245,"Minimization of Boolean Function");
	box();
	cursoron();
	chio=push();
	return(chio);
}


void bx(int x1,int y1,int x2,int y2)
{
	int a,x,b,c,d;

	setcolor(15);
	settextstyle(2,0,6);
	a = (x1+x2) / 2;
	b = (x1+x2) / 2;
	while ((a <= x2) && (b >= x1))
	{
	     outtextxy(a,y1,"Û");
	     outtextxy(a,y2,"Û");
	     a = a+1;
	     outtextxy(b,y1,"Û");
	     outtextxy(b,y2,"Û");
	     b=b-1;
	}
	for (c = y1;c <= y2; c++)
	{
	     outtextxy(x1,c,"Û");
	     outtextxy(x2,c,"Û");
	}
}

void box(void)
{
	for (int i=0;i<7;i++)
	{
		setcolor(15);
		line(colum,rows[i],colum+335,rows[i]);
		line(colum,rows[i],colum,rows[i]+35);
		setcolor(0);
		line(colum,rows[i]+35,colum+335,rows[i]+35);
		line(colum+335,rows[i],colum+335,rows[i]+35);
	}
}

int push(void)
{
	int io=0,Flag=0,again;
	int cho,button;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!Flag))
		{
			Flag=1;
			switch (cho=(check11(x,y)))
			{
				case 0:
					blink1(cho);again=0;
				break;

				case 1:
					blink1(cho);again=1;
				break;

				case 2:
					blink1(cho);again=2;
				break;

				case 3:
					blink1(cho);again=3;
				break;

				case 4:
					blink1(cho);again=4;
				break;

				case 5:
					blink1(cho);again=5;
				break;

				case 6:
					blink1(cho);again=6;
				break;
			}
		}
		if((button==0)&&(Flag))
		{
			Flag=0;
			blink2(again);
			if (x >= colum && x <= colum+335 && y >= rows[again] && y <= rows[again]+35)
			{
				if (again!=6)
					cursoroff();
				sound();
				io=1;
			}
		}
	}

	return(cho);
}

void blink(int cx)
{
	cursoroff();
	setcolor(0);
	line(colum,rows[cx],colum+335,rows[cx]);
	line(colum,rows[cx],colum,rows[cx]+35);
	setcolor(15);
	line(colum,rows[cx]+35,colum+335,rows[cx]+35);
	line(colum+335,rows[cx],colum+335,rows[cx]+35);
	delay(300);
	setcolor(15);
	line(colum,rows[cx],colum+335,rows[cx]);
	line(colum,rows[cx],colum,rows[cx]+35);
	setcolor(0);
	line(colum,rows[cx]+35,colum+335,rows[cx]+35);
	line(colum+335,rows[cx],colum+335,rows[cx]+35);
	setcursorpos(x,y);
	cursoron();
}

void blink1(int cx)
{
	setcolor(0);
	line(colum,rows[cx],colum+335,rows[cx]);
	line(colum,rows[cx],colum,rows[cx]+35);
	setcolor(15);
	line(colum,rows[cx]+35,colum+335,rows[cx]+35);
	line(colum+335,rows[cx],colum+335,rows[cx]+35);
}

void blink2(int cx)
{
	setcolor(15);
	line(colum,rows[cx],colum+335,rows[cx]);
	line(colum,rows[cx],colum,rows[cx]+35);
	setcolor(0);
	line(colum,rows[cx]+35,colum+335,rows[cx]+35);
	line(colum+335,rows[cx],colum+335,rows[cx]+35);
}

int check11(int x,int y)
{
	for (int i = 0;i < 7;i++)
	if (x >= colum && x <= colum+335 && y >= rows[i] && y <= rows[i]+35)
		return(i);
	return(-1);
}

	/* The Quit Program  */

int colquit[2]={250,400},rowquit=250;
int desi(void)
{
	int c,r,ch12=0,ch13,button;

	setcolor(15);
	setfillstyle(SOLID_FILL,7);
	bar(100,150,550,300);
	setfillstyle(SOLID_FILL,3);
	bar(101,152,548,190);
	settextstyle(1,0,4);
	outtextxy(123,150,"Warning !");

	setcolor(15);
	line(100,150,550,150);
	line(100,150,100,300);
	setcolor(0);
	line(100,300,550,300);
	line(550,150,550,300);

	setfillstyle(SOLID_FILL,14);
	bar(145,214,205,260);
	setcolor(0);
	line(145,260,205,260);
	line(144,260,175,214);
	line(175,214,206,260);
	setcolor(7);
	c=143;r=174;
	for (int i=0;i<30;i++)
	{
		line(c,260,r,214);
		c--;r--;
	}
	c=176;r=207;
	for (i=0;i<30;i++)
	{
		line(r,260,c,214);
		c++;r++;
	}
	setcolor(0);
	settextstyle(1,0,4);
	outtextxy(173,222,"!");
	settextstyle(2,0,5);
	outtextxy(230,210,"Are You sure You are Quit the Program");

	setcolor(15);
	line(colquit[0],rowquit,colquit[0]+80,rowquit);
	line(colquit[0],rowquit,colquit[0],rowquit+30);
	setcolor(0);
	line(colquit[0],rowquit+30,colquit[0]+80,rowquit+30);
	line(colquit[0]+80,rowquit,colquit[0]+80,rowquit+30);

	setcolor(15);
	line(colquit[1],rowquit,colquit[1]+80,rowquit);
	line(colquit[1],rowquit,colquit[1],rowquit+30);
	setcolor(0);
	line(colquit[1],rowquit+30,colquit[1]+80,rowquit+30);
	line(colquit[1]+80,rowquit,colquit[1]+80,rowquit+30);
	settextstyle(1,0,4);
	outtextxy(263,245,"Yes");
	outtextxy(423,245,"No");
	int flag=0,again;
	while (ch12==0)
	{
		button=getcursorpos(&x,&y);
		if ((button)&&(!flag))
		{
			flag=1;
			switch ((check12(x,y)))
			{
				case 0:
					press1(colquit[0],rowquit,colquit[0]+80,rowquit+30);again=0;
				break;

				case 1:
					press1(colquit[1],rowquit,colquit[1]+80,rowquit+30);again=1;
				break;
			}
		}
		if ((!button)&&(flag))
		{
			flag=0;press2(colquit[again],rowquit,colquit[again]+80,rowquit+30);
			if (x >= colquit[again] && x <= colquit[again]+80 && y >= rowquit && y <= rowquit+30)
			{
				cursoroff();
				sound();
				ch12=1;
				if (again)
					ch13=0;
				else
					ch13=1;
			}
		}
	}
	return(ch13);

}

int check12(int x,int y)
{
	for (int i = 0;i < 2;i++)
	if (x >= colquit[i] && x <= colquit[i]+80 && y >= rowquit && y <= rowquit+30)
		return(i);
	return(-1);
}

void desion1(void)
{
	int c,r;

	cursoroff();
	setcolor(15);
	setfillstyle(SOLID_FILL,7);
	bar(100,150,550,300);
	setfillstyle(SOLID_FILL,3);
	bar(101,152,548,190);
	settextstyle(1,0,4);
	outtextxy(123,150,"Please Wait For Loading....");

	setcolor(15);
	line(100,150,550,150);
	line(100,150,100,300);
	setcolor(0);
	line(100,300,550,300);
	line(550,150,550,300);

	setfillstyle(SOLID_FILL,14);
	bar(145,214,205,260);
	setcolor(0);
	line(145,260,205,260);
	line(144,260,175,214);
	line(175,214,206,260);
	setcolor(7);
	c=143;r=174;
	for (int i=0;i<30;i++)
	{
		line(c,260,r,214);
		c--;r--;
	}
	c=176;r=207;
	for (i=0;i<30;i++)
	{
		line(r,260,c,214);
		c++;r++;
	}
	setcolor(0);
	settextstyle(1,0,4);
	outtextxy(173,222,"!");

	setcolor(0);
	line(240, 225, 515, 225);
	line(240, 225, 240, 250);
	setcolor(15);
	line(240, 250, 515, 250);
	line(515, 225, 515, 250);
	c=242;r=226;
	cursoron();
	for (i=0;i<11;i++)
	{
		getcursorpos(&x,&y);
		if (x >= 240 && x <= 515 && y >= 200 && y <= 250)
			cursoroff();
		setfillstyle(SOLID_FILL,1);
		bar(c,r,c+20,r+22);
		if (x >= 240 && x <= 515 && y >= 200 && y <= 250)
		{
			setcursorpos(x,y);
			cursoron();
		}
		c+=25;
		delay(400);
	}
}

