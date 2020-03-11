#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include "d:\cld\basic.h"
#include "d:\cld\mouse.h"
#include "d:\cld\proof.h"

int bool(void);
int seabool(int x,int y);

void lba(void);
int nextlba(void);
int sealba(int x,int y);
int lbacomm(void);

void pbl(void);
int seapbl(int x,int y);
int seapbl1(int x,int y);
int pblcomm(void);

void truth(void);
int seatt(int x,int y);
int ttcomm(void);
void onett(void);
void twott(void);
void threett(void);
void fourtt(void);

/*	Variables Section	*/

int colbo=170,rowbo[4]={135,210,285,360},button;

void main(int argu)
{
	if (argu != 4)
	{
		printf("This Program Run only in Main File CLD.EXE");
		exit(1);
	}
	int ch42=0,ch43;
	int gd=DETECT,gm;
	registerbgidriver(EGAVGA_driver);
	initgraph(&gd,&gm,"");
//	initgraph(&gd,&gm,"d:\\tc\\bgi");
	while (ch42 != 1)
	{
		ch43=bool();
		if ( ch43==0)
			lba();
		if ( ch43==1)
			pbl();
		if ( ch43==2)
			truth();
		if ( ch43==3)
			ch42=1;
	}
}

int bool(void)
{
	int io=0,chio;
	setfillstyle(SOLID_FILL,3);
	bar(0,0,getmaxx(),getmaxy());
	comman(20,10,615,75,7);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(107,4,"Bolean Algebra");
	outtextxy(108,5,"Bolean Algebra");
	setcolor(14);
	outtextxy(106,2,"Bolean Algebra");
	outtextxy(105,2,"Bolean Algebra");

	setcolor(15);
	comman1(100,90,540,435,3);
	comman1(110,100,530,425,1);

	for (int i=0;i<4;i++)
		comman(colbo,rowbo[i],colbo+295,rowbo[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colbo+10,rowbo[0],"Laws of Boolean Algebra");
	outtextxy(colbo+15,rowbo[1],"Proofs of Boolean Laws");
	outtextxy(colbo+70,rowbo[2],"Truth Tables");
	outtextxy(colbo+105,rowbo[3],"Q U I T");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chio=(seabool(x,y)))
			{
				case 0:
					press1(colbo,rowbo[0],colbo+295,rowbo[0]+35);
					again=0;
				break;
				case 1:
					press1(colbo,rowbo[1],colbo+295,rowbo[1]+35);
					again=1;
				break;
				case 2:
					press1(colbo,rowbo[2],colbo+295,rowbo[2]+35);
					again=2;
				break;
				case 3:
					press1(colbo,rowbo[3],colbo+295,rowbo[3]+35);
					again=3;
				break;
				case 4:
					press1(colbo,rowbo[4],colbo+295,rowbo[4]+35);
					again=4;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colbo,rowbo[again],colbo+295,rowbo[again]+35);
			if (x >= colbo && x <= colbo+295 && y >= rowbo[again] && y <= rowbo[again]+35)
			{
				cursoroff();
				sound();
				 io=1;
			}
		}
	}
	return(chio);
}

int seabool(int x,int y)
{
	for (int i = 0;i < 4;i++)
	if (x >= colbo && x <= colbo+295 && y >= rowbo[i] && y <= rowbo[i]+35)
		return(i);
	return(-1);
}

/*	Functions of Laws of Boolean Algebra	*/

void lba(void)
{
	int iolba,mainlba=0;
	while (mainlba != 1)
	{
		iolba=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(50,8,"Laws of Boolean Algebra");
		line(300,70,300,455);
		setcolor(9);
		settextstyle(1,0,3);
		outtextxy(20,75,"1.");
		outtextxy(80,75,"Identity Laws");
		line(78,106,232,106);
		outtextxy(20,170,"2.");
		outtextxy(60,170,"Commutative Laws");
		line(58,200,277,200);
		outtextxy(20,275,"3.");
		outtextxy(70,275,"Distributive Laws");
		line(68,305,267,305);
		outtextxy(320,75,"4.");
		outtextxy(360,75,"Complementory Laws");
		line(358,107,603,107);
		outtextxy(320,170,"5.");
		outtextxy(380,170,"Idempotent Laws");
		line(378,202,573,202);
		outtextxy(320,275,"6.");
		outtextxy(370,275,"Properties of 0 & 1");
		line(368,306,600,306);

		setcolor(0);
		settextstyle(1,0,2);
		outtextxy(40,115,"a)");
		outtextxy(100,115,"x + 0 = x");
		outtextxy(40,145,"b)");
		outtextxy(100,145,"x + 1 = x");

		outtextxy(40,215,"a)");
		outtextxy(100,215,"x + y = y + x");
		outtextxy(40,245,"b)");
		outtextxy(100,245,"x . y  = y . x");

		outtextxy(40,315,"a)");
		outtextxy(80,315,"x+(y.z) = (x+y).(x+z)");
		outtextxy(40,345,"b)");
		outtextxy(80,345,"x.(y+z) = (x.y)+(x.z)");

		outtextxy(330,115,"a)");
		outtextxy(400,115,"x + x = 1");
		outtextxy(330,145,"b)");
		outtextxy(400,145,"x . x  = 0");
		outtextxy(446,108,"-");
		outtextxy(438,138,"-");

		outtextxy(330,215,"a)");
		outtextxy(400,215,"x + x = x");
		outtextxy(330,245,"b)");
		outtextxy(400,245,"x . x  = x");

		outtextxy(330,315,"a)");
		outtextxy(400,315,"x + 1 = 1");
		outtextxy(330,345,"b)");
		outtextxy(400,345,"x . 0  = 0");

		comman(100,400,200,435,7);
		outtextxy(110,405,"NEXT >>");
		comman(400,400,500,435,7);
		outtextxy(415,405,"Q U I T");
		setcursorpos(x,y);
		cursoron();
		int flag=0,again;
		while (iolba != 1)
		{
			button=getcursorpos(&x,&y);
			if ((button==1)&&(!flag))
			{
				flag=1;
				if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
				{
					press1(400,400,500,435);
					again=0;
				}
				if (x >= 100 && x <= 200 && y >= 400 && y <= 435)
				{
					press1(100,400,200,435);
					again=1;
				}
			}
			if ((button==0)&&(flag))
			{
				flag=0;
				if (again)
				{
					press2(100,400,200,435);
					if (x >= 100 && x <= 200 && y >= 400 && y <= 435)
					{
						sound();
						cursoroff();
						mainlba=nextlba();
						iolba=1;
					}
				}
				else
				{
					press2(400,400,500,435);
					if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
					{
						sound();
						iolba=1;
						mainlba=1;
						cursoroff();
					}
				}
			}
		}
	}
}

int nextlba(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	line(300,70,300,455);
	setcolor(9);
	settextstyle(1,0,3);
	outtextxy(20,75,"7.");
	outtextxy(80,75,"Absorption Laws");
	line(78,106,262,106);
	outtextxy(20,170,"8.");
	outtextxy(80,170,"Associative Laws");
	line(78,200,262,200);
	outtextxy(20,275,"9.");
	outtextxy(70,275,"De Morgan's Laws");
	line(68,307,277,307);
	outtextxy(320,75,"10.");
	outtextxy(380,75,"Involution Laws");
	line(378,105,560,105);
	outtextxy(320,170,"11.");
	outtextxy(380,170,"Consensus Laws");
	line(378,200,557,200);

	setcolor(0);
	settextstyle(1,0,2);
	outtextxy(40,115,"a)");
	outtextxy(100,115,"x . (x + y)  = x");
	outtextxy(40,145,"b)");
	outtextxy(100,145,"x + (x + y) = x");

	outtextxy(40,215,"a)");
	outtextxy(100,215,"x+(y+z) = (x+y)+z");
	outtextxy(40,245,"b)");
	outtextxy(100,245,"x.(y.z) = (x.y).z");

	outtextxy(40,315,"a)");
	outtextxy(80,315,"x + y = x . y");
	line(78,320,140,320);
	outtextxy(172,308,"-");
	outtextxy(210,308,"-");

	outtextxy(40,345,"b)");
	outtextxy(80,345,"x . y = x + y");
	line(78,350,130,350);
	outtextxy(164,338,"-");
	outtextxy(210,338,"-");

	outtextxy(410,125,"x  =  x");
	outtextxy(410,112,"-");
	outtextxy(410,116,"-");

	outtextxy(330,215,"a)");
	outtextxy(400,215,"x.y + y.z + x.z");
	outtextxy(400,245,"= x.y + x.z");
	outtextxy(525,208,"-");
	outtextxy(488,238,"-");

	outtextxy(330,275,"b)");
	outtextxy(380,275,"(x + y)(y + z)(x + z)");
	outtextxy(400,305,"= (x + y)(x + z)");
	outtextxy(527,268,"-");
	outtextxy(502,298,"-");

	comman(100,400,200,435,7);
	outtextxy(110,405,"<< BACK");
	comman(400,400,500,435,7);
	outtextxy(415,405,"Q U I T");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (ionext != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
			{
				press1(400,400,500,435);
				again=0;
			}
			if (x >= 100 && x <= 200 && y >= 400 && y <= 435)
			{
				press1(100,400,200,435);
				again=1;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			if (again)
			{
				press2(100,400,200,435);
				if (x >= 100 && x <= 200 && y >= 400 && y <= 435)
				{
					sound();
					cursoroff();
					ionext=1;
					return(0);
				}
			}
			else
			{
				press2(400,400,500,435);
				if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
				{
					sound();
					ionext=1;
					cursoroff();
					return(1);
				}
			}
		}
	}
}

/*	Functions of Proofs of Boolean Laws	*/

void pbl(void)
{
	int pbl,pb=0;
	while (pb != 1)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(45,8,"Proofs of Boolean Laws");
		pbl=pblcomm();
		if (pbl == 0)
			identity();
		if (pbl == 1)
			commutative();
		if (pbl == 2)
			distributive();
		if (pbl == 3)
			complementory();
		if (pbl == 4)
			absorption();
		if (pbl == 5)
			associative();
		if (pbl == 6)
			properties();
		if (pbl == 7)
			demorgan();
		if (pbl == 8)
			negation();
		if (pbl == 10)
			idempotent();
		if (pbl == 11)
			pb=1;
	}
}

int colpbl=30,colpbl1=320,rowpbl[6]={100,160,220,280,340,400};
int pblcomm(void)
{
	int iopbl=0,comeback;
	line(300,70,300,455);
	for (int i=0;i<6;i++)
		comman(colpbl,rowpbl[i],colpbl+255,rowpbl[i]+35,7);
	for (i=0;i<6;i++)
		comman(colpbl1,rowpbl[i],colpbl1+255,rowpbl[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colpbl+50,rowpbl[0],"Identity Laws");
	outtextxy(colpbl+20,rowpbl[1],"Commutative Laws");
	outtextxy(colpbl+30,rowpbl[2],"Distributive Laws");
	outtextxy(colpbl+5,rowpbl[3],"Complementory Laws");
	outtextxy(colpbl+35,rowpbl[4],"Absorption Laws");
	outtextxy(colpbl+35,rowpbl[5],"Associative Laws");
	outtextxy(colpbl1+15,rowpbl[0],"Properties of 0 & 1");
	outtextxy(colpbl1+30,rowpbl[1],"De Morgan's Laws");
	outtextxy(colpbl1+40,rowpbl[2],"Involution Laws");
	outtextxy(colpbl1+40,rowpbl[3],"Consensus Laws");
	outtextxy(colpbl1+30,rowpbl[4],"Idempotent Laws");
	outtextxy(colpbl1+90,rowpbl[5],"Q U I T");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again1,again2,again;
	while (iopbl != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (seapbl(x,y))
			{
				case 0:
					press1(colpbl,rowpbl[0],colpbl+255,rowpbl[0]+35);
					again=0;again1=0;
				break;
				case 1:
					press1(colpbl,rowpbl[1],colpbl+255,rowpbl[1]+35);
					again=0;again1=1;
				break;
				case 2:
					press1(colpbl,rowpbl[2],colpbl+255,rowpbl[2]+35);
					again=0;again1=2;
				break;
				case 3:
					press1(colpbl,rowpbl[3],colpbl+255,rowpbl[3]+35);
					again=0;again1=3;
				break;
				case 4:
					press1(colpbl,rowpbl[4],colpbl+255,rowpbl[4]+35);
					again=0;again1=4;
				break;
				case 5:
					press1(colpbl,rowpbl[5],colpbl+255,rowpbl[5]+35);
					again=0;again1=5;
				break;
			}

			switch (seapbl1(x,y))
			{
				case 0:
					press1(colpbl1,rowpbl[0],colpbl1+255,rowpbl[0]+35);
					again=1;again2=0;
				break;
				case 1:
					press1(colpbl1,rowpbl[1],colpbl1+255,rowpbl[1]+35);
					again=1;again2=1;
				break;
				case 2:
					press1(colpbl1,rowpbl[2],colpbl1+255,rowpbl[2]+35);
					again=1;again2=2;
				break;
				case 3:
					press1(colpbl1,rowpbl[3],colpbl1+255,rowpbl[3]+35);
					again=1;again2=3;
				break;
				case 4:
					press1(colpbl1,rowpbl[4],colpbl1+255,rowpbl[4]+35);
					again=1;again2=4;
				break;
				case 5:
					press1(colpbl1,rowpbl[5],colpbl1+255,rowpbl[5]+35);
					again=1;again2=5;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			if (!again)
			{
				press2(colpbl,rowpbl[again1],colpbl+255,rowpbl[again1]+35);
				if (x >= colpbl && x <= colpbl+255 && y >= rowpbl[again1] && y <= rowpbl[again1]+35)
				{
					cursoroff();
					sound();
					iopbl=1;comeback=again1;
				}
			}
			else
			{
				press2(colpbl1,rowpbl[again2],colpbl1+255,rowpbl[again2]+35);
				if (x >= colpbl1 && x <= colpbl1+255 && y >= rowpbl[again2] && y <= rowpbl[again2]+35)
				{
					cursoroff();
					sound();
					iopbl=1;comeback=again2+6;
				}
			}
		}
	}
	return(comeback);
}

int seapbl(int x,int y)
{
	for (int i = 0;i < 6;i++)
	if (x >= colpbl && x <= colpbl+255 && y >= rowpbl[i] && y <= rowpbl[i]+35)
		return(i);
	return(-1);
}

int seapbl1(int x,int y)
{
	for (int i = 0;i < 6;i++)
	if (x >= colpbl1 && x <= colpbl1+255 && y >= rowpbl[i] && y <= rowpbl[i]+35)
		return(i);
	return(-1);
}

/*	Functions of Truth Tables	*/

void truth(void)
{
	int tt=0;
	while (tt != 1)
	{
		int truthtable;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(140,3,"Truth Tables");
		truthtable=ttcomm();
		if (truthtable == 0)
			onett();
		if (truthtable == 1)
			twott();
		if (truthtable == 2)
			threett();
		if (truthtable == 3)
			fourtt();
		if (truthtable == 4)
			tt=1;
	}
}

int coltt=130,rowtt[5]={120,185,250,315,380};
int ttcomm(void)
{
	int iott=0,chiott;
	for (int i=0;i<5;i++)
		comman(coltt,rowtt[i],coltt+360,rowtt[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(coltt+14,rowtt[0],"Truth Table of One Variable");
	outtextxy(coltt+12,rowtt[1],"Truth Table of Two Variables");
	outtextxy(coltt+5,rowtt[2],"Truth Table of Three Variables");
	outtextxy(coltt+8,rowtt[3],"Truth Table of Four Variables");
	outtextxy(coltt+135,rowtt[4],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (iott != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chiott=(seatt(x,y)))
			{
				case 0:
					press1(coltt,rowtt[0],coltt+360,rowtt[0]+35);
					again=0;
				break;
				case 1:
					press1(coltt,rowtt[1],coltt+360,rowtt[1]+35);
					again=1;
				break;
				case 2:
					press1(coltt,rowtt[2],coltt+360,rowtt[2]+35);
					again=2;
				break;
				case 3:
					press1(coltt,rowtt[3],coltt+360,rowtt[3]+35);
					again=3;
				break;
				case 4:
					press1(coltt,rowtt[4],coltt+360,rowtt[4]+35);
					again=4;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(coltt,rowtt[again],coltt+360,rowtt[again]+35);
			if (x >= coltt && x <= coltt+360 && y >= rowtt[again] && y <= rowtt[again]+35)
			{
				cursoroff();
				sound();
				iott=1;
			}
		}
	}
	return(chiott);
}

int seatt(int x,int y)
{
	for (int i = 0;i < 5;i++)
	if (x >= coltt && x <= coltt+360 && y >= rowtt[i] && y <= rowtt[i]+35)
		return(i);
	return(-1);
}

void onett(void)
{
	int one=0;
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 75,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	setcolor(0);
	outtextxy(27,12,"Truth Table for One Variable");
	outtextxy(28,13,"Truth Table for One Variable");
	setcolor(14);
	outtextxy(26,10,"Truth Table for One Variable");
	outtextxy(25,10,"Truth Table for One Variable");
	comman3(15,76,getmaxx()-15,getmaxy()-15,15);

	settextstyle(7, 0, 4);
	setcolor(0);
	outtextxy(150,110,"Let x be a Variable.");
	outtextxy(50,160,"Number of Combinations=2 =2");
	settextstyle(7, 0, 2);
	outtextxy(512,150,"1");
	rectangle(275,225,350,350);
	line(276,265,349,265);
	settextstyle(1, 0, 4);
	outtextxy(300,225,"x");
	outtextxy(300,270,"0");
	outtextxy(300,310,"1");
	comman(270,430,370,460,7);
	settextstyle(1,0,4);
	outtextxy(300,425,"Ok");
	setcursorpos(x,y);
	cursoron();
	int flag=0;
	while (one != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
				press1(270,430,370,460);
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(270,430,370,460);
			delay(100);
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
			{
				cursoroff();
				sound();
				one=1;
			}
		}
	}
}

void twott(void)
{
	int two=0;
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 75,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	setcolor(0);
	outtextxy(12,12,"Truth Table for Two Variables");
	outtextxy(13,13,"Truth Table for Two Variables");
	setcolor(14);
	outtextxy(11,10,"Truth Table for Two Variables");
	outtextxy(10,10,"Truth Table for Two Variables");
	comman3(15,76,getmaxx()-15,getmaxy()-15,15);

	settextstyle(7, 0, 4);
	setcolor(0);
	outtextxy(100,100,"Let the Variables be x and y.");
	outtextxy(50,160,"Number of Combinations=2 = 4");
	settextstyle(7, 0, 2);
	outtextxy(512,150,"2");
	rectangle(200,225,425,400);
	line(312,225,312,400);
	line(200,260,425,260);
	settextstyle(1, 0, 4);
	outtextxy(250,220,"x");
	outtextxy(355,215,"y");
	outtextxy(250,260,"0");
	outtextxy(250,290,"0");
	outtextxy(250,320,"1");
	outtextxy(250,350,"1");
	outtextxy(355,260,"0");
	outtextxy(355,290,"1");
	outtextxy(355,320,"0");
	outtextxy(355,350,"1");
	comman(270,430,370,460,7);
	settextstyle(1,0,4);
	outtextxy(300,425,"Ok");
	setcursorpos(x,y);
	cursoron();
	int flag=0;
	while (two != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
				press1(270,430,370,460);
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(270,430,370,460);
			delay(100);
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
			{
				cursoroff();
				sound();
				two=1;
			}
		}
	}
}

void threett(void)
{
	int three=0;
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 50,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setcolor(0);
	outtextxy(62,7,"Truth Table for Three Variables");
	outtextxy(63,8,"Truth Table for Three Variables");
	setcolor(14);
	outtextxy(61,5,"Truth Table for Three Variables");
	outtextxy(60,5,"Truth Table for Three Variables");
	comman3(15,51,getmaxx()-15,getmaxy()-15,15);

	settextstyle(7, 0, 4);
	setcolor(0);
	outtextxy(70,60,"Let the Variables be x, y and z.");
	outtextxy(50,100,"Number of Combinations=2 = 8");
	settextstyle(7, 0, 2);
	outtextxy(512,90,"3");
	rectangle(125,150,525,425);
	line(258,150,258,425);
	line(391,150,391,425);
	line(125,180,525,180);
	settextstyle(1, 0, 4);
	outtextxy(180,140,"x");
	outtextxy(313,139,"y");
	outtextxy(446,140,"z");

	outtextxy(180,180,"0");
	outtextxy(180,210,"0");
	outtextxy(180,240,"0");
	outtextxy(180,270,"0");
	outtextxy(180,300,"1");
	outtextxy(180,330,"1");
	outtextxy(180,360,"1");
	outtextxy(180,390,"1");

	outtextxy(313,180,"0");
	outtextxy(313,210,"0");
	outtextxy(313,240,"1");
	outtextxy(313,270,"1");
	outtextxy(313,300,"0");
	outtextxy(313,330,"0");
	outtextxy(313,360,"1");
	outtextxy(313,390,"1");

	outtextxy(446,180,"0");
	outtextxy(446,210,"1");
	outtextxy(446,240,"0");
	outtextxy(446,270,"1");
	outtextxy(446,300,"0");
	outtextxy(446,330,"1");
	outtextxy(446,360,"0");
	outtextxy(446,390,"1");
	comman(270,430,370,460,7);
	settextstyle(1,0,4);
	outtextxy(300,425,"Ok");
	setcursorpos(x,y);
	cursoron();
	int flag=0;
	while (three != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
				press1(270,430,370,460);
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(270,430,370,460);
			delay(100);
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
			{
				cursoroff();
				sound();
				three=1;
			}
		}
	}
}

void fourtt(void)
{
	int four=0;
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 50,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setcolor(0);
	outtextxy(72,7,"Truth Table for Four Variables");
	outtextxy(73,8,"Truth Table for Four Variables");
	setcolor(14);
	outtextxy(71,5,"Truth Table for Four Variables");
	outtextxy(70,5,"Truth Table for Four Variables");
	comman3(15,51,getmaxx()-15,getmaxy()-15,15);

	settextstyle(1, 0, 2);
	setcolor(0);
	outtextxy(90,50,"Let the Variables be w, x, y and z.");
	outtextxy(90,80,"Number of Combinations = 2  = 16");
	settextstyle(1, 0, 1);
	outtextxy(392,70,"4");
	rectangle(60,110,593,425);
	line(193,110,193,425);
	line(326,110,326,425);
	line(460,110,460,425);
	line(60,140,593,140);
	settextstyle(1, 0, 4);
	outtextxy(120,100,"w");
	outtextxy(253,100,"x");
	outtextxy(386,99,"y");
	outtextxy(520,100,"z");

	settextstyle(2, 0, 5);
	int r=140;
	for (int i=0; i<8; i++)
	{outtextxy(130,r,"0");r+=18;}
	for (i=0; i<8; i++)
	{outtextxy(130,r,"1");r+=18;}

	r=140;
	for (i=0; i<4; i++)
	{outtextxy(260,r,"0");r+=18;}
	for (i=0; i<4; i++)
	{outtextxy(260,r,"1");r+=18;}
	for (i=0; i<4; i++)
	{outtextxy(260,r,"0");r+=18;}
	for (i=0; i<4; i++)
	{outtextxy(260,r,"1");r+=18;}

	r=140;
	for (i=0; i<2; i++)
	{outtextxy(390,r,"0");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"1");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"0");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"1");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"0");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"1");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"0");r+=18;}
	for (i=0; i<2; i++)
	{outtextxy(390,r,"1");r+=18;}

	r=140;
	for (i=0; i<8; i++)
	{outtextxy(525,r,"0");r+=36;}
	r=158;
	for (i=0; i<8; i++)
	{outtextxy(525,r,"1");r+=36;}

	comman(270,430,370,460,7);
	settextstyle(1,0,4);
	outtextxy(300,425,"Ok");
	setcursorpos(x,y);
	cursoron();
	int flag=0;
	while (four != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
				press1(270,430,370,460);
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(270,430,370,460);
			delay(100);
			if (x >= 170 && x <= 370 && y >= 430 && y <= 460)
			{
				cursoroff();
				sound();
				four=1;
			}
		}
	}
}
