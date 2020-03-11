#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <math.h>
#include "d:\cld\basic.h"
#include "d:\cld\mouse.h"
#include "d:\cld\convert.h"
#include "d:\cld\basecon.h"
#include "d:\cld\basecon1.h"

int sea(int x,int y);
int nus(void);
void binary(void);
void decimal(void);
void octal(void);
void hexadecimal(void);
void conversion(void);

void bd(void);
void simplebd(void);
void fractionbd(void);

int convert(void);
int concheck1(int x,int y);
int concheck2(int x,int y);
int concheck3(int x,int y);
void end(void);

/*	Variables Section	*/
int col[6]={140,355,140,355,140,355},row[6]={175,245,315,175,245,315};

void main(int argu)
{
	if (argu != 4)
	{
		printf("This Program Run only in Main File CLD.EXE");
		exit(1);
	}
	int ch40=0,ch41;
	int gd=DETECT,gm;
	registerbgidriver(EGAVGA_driver);
	initgraph(&gd,&gm,"");
//	initgraph(&gd,&gm,"d:\\tc\\bgi");
	while (ch40 != 1)
	{
		ch41=nus();
		if (ch41==0)
			binary();
		if (ch41==3)
			decimal();
		if (ch41==4)
			octal();
		if (ch41==1)
			hexadecimal();
		if (ch41==2)
			conversion();
		if ( ch41==5)
			ch40=1;
	}
}


int nus(void)
{
	int io,chio;
	setfillstyle(SOLID_FILL,3);
	bar(0,0,getmaxx(),getmaxy());
	comman(20,10,615,75,7);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(102,4,"Number System");
	outtextxy(103,5,"Number System");
	setcolor(14);
	outtextxy(101,2,"Number System");
	outtextxy(100,2,"Number System");

	setcolor(15);
	comman1(100,115,540,400,3);
	comman1(110,125,530,390,1);

	for (int i=0;i<6;i++)
		comman(col[i],row[i],col[i]+145,row[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(173,175,"Binary");
	outtextxy(384,175,"Decimal");
	outtextxy(184,245,"Octal");
	outtextxy(358,245,"HexaDecimal");
	outtextxy(150,315,"Conversion");
	outtextxy(384,315,"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button)&&(!flag))
		{
			flag=1;
			switch (chio=(sea(x,y)))
			{
				case 0:
					press1(col[0],row[0],col[0]+145,row[0]+35);
					again=0;
				break;
				case 1:
					press1(col[1],row[1],col[1]+145,row[1]+35);
					again=1;
				break;
				case 2:
					press1(col[2],row[2],col[2]+145,row[2]+35);
					again=2;
				break;
				case 3:
					press1(col[3],row[3],col[3]+145,row[3]+35);
					again=3;
				break;
				case 4:
					press1(col[4],row[4],col[4]+145,row[4]+35);
					again=4;
				break;
				case 5:
					press1(col[5],row[5],col[5]+145,row[5]+35);
					again=5;
				break;
			}
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(col[again],row[again],col[again]+145,row[again]+35);
			if (x >= col[again] && x <= col[again]+145 && y >= row[again] && y <= row[again]+35)
			{
				cursoroff();
				sound();
				io=1;
			}
		}
	}
	return(chio);
}

int sea(int x,int y)
{
	for (int i = 0;i < 6;i++)
	if (x >= col[i] && x <= col[i]+145 && y >= row[i] && y <= row[i]+35)
		return(i);
	return(-1);
}

void binary(void)
{
	cursoroff();
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,15);
	setcolor(0);
	settextstyle(1,0,6);
	outtextxy(120,3,"Binary Number");
	comman(270,400,370,430,7);
	settextstyle(2,0,5);
	outtextxy(50,110,"The Binary Number system has the base 2, and uses only two digits 0 and");
	outtextxy(30,130,"1 for its representation. The digits in binary system are called bits.");
	outtextxy(50,170,"The advantages achieved by using the binary number system for digital");
	outtextxy(30,190,"computer are as follows:");
	outtextxy(30,220,"1)       It is ideally suited for internal processing in computer because of");
	outtextxy(30,240,"         the binary nature of the electronic switches.");
	outtextxy(30,270,"2)       It is responsible for the fantastic speeds of computers.");
	outtextxy(30,300,"3)       Binary computers can be built at less cost than the old decimal");
	outtextxy(30,320,"         computers.");
	settextstyle(1,0,4);
	outtextxy(300,395,"Ok");
	setcursorpos(x,y);
	cursoron();
	end();
}

void decimal(void)
{
	cursoroff();
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,15);
	setcolor(0);
	settextstyle(1,0,6);
	outtextxy(110,3,"Decimal Number");
	comman(270,400,370,430,7);
	settextstyle(2,0,5);
	outtextxy(50,110,"The decimal number system, as mentioned already, uses ten distinct");
	outtextxy(30,140,"symbols: 0,1,2,3,4,5,6,7,8,9. Each symbolis called a digit and has a value");
	outtextxy(30,170,"determined by its position relative to the other digits in that number. The");
	outtextxy(30,200,"meaning of positional value is better understood by writing the given number");
	outtextxy(30,230,"in its positional notation form.");
	settextstyle(1,0,4);
	outtextxy(300,395,"Ok");
	setcursorpos(x,y);
	cursoron();
	end();
}

void octal(void)
{
	cursoroff();
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,15);
	setcolor(0);
	settextstyle(1,0,6);
	outtextxy(135,3,"Octal Number");
	comman(270,400,370,430,7);
	settextstyle(2,0,5);
	outtextxy(50,110,"Though the binary number is quite useful in computer work. It is not");
	outtextxy(30,140,"suitable for manual aritmetic especially when large binary numbers are to be");
	outtextxy(30,170,"manipulated. A short hand and convenient method to bridge the gap between ");
	outtextxy(30,200,"binary numbers and decimal numbers is to use the Octal number  system. It");
	outtextxy(30,230,"has a base of 8 and uses eight symbols, 0 to 7.This system is useful because");
	outtextxy(30,260,"it is mostly applied in coding and conversion of decimal numbers into binary");
	outtextxy(30,290,"and vice versa.");
	settextstyle(2,0,6);
	outtextxy(170,330,"Symbols is 0,1,2,3,4,5,6,7.");
	settextstyle(1,0,4);
	outtextxy(300,395,"Ok");
	setcursorpos(x,y);
	cursoron();
	end();
}

void hexadecimal(void)
{
	cursoroff();
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,15);
	setcolor(0);
	settextstyle(1,0,6);
	outtextxy(40,3,"HexaDecimal Number");
	comman(270,400,370,430,7);
	settextstyle(2,0,5);
	outtextxy(50,110,"Hexadecimal system (or simly hex) is very important in modern computing");
	outtextxy(30,140,"because of its close relationship with base 2. It has the base of 16. The");
	outtextxy(30,170,"sixteen symbols used in the hexadecimal system are 0 through 9 for the first");
	outtextxy(30,200,"ten bits and the remaining six are denoted by alphabets such as A,B,C,D,E");
	outtextxy(30,230,"and F, to represent the decimal numbers 10,11,12,13,14 and 15 respectively.");
	outtextxy(90,270,"With this, all sixteen hexadecimal symbols are as follows :");
	outtextxy(170,310,"0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F.");
	settextstyle(1,0,4);
	outtextxy(300,395,"Ok");
	setcursorpos(x,y);
	cursoron();
	end();
}

/*	Function of Conversion	*/

void conversion(void)
{
	int conversion=0,lastcon;
	while (conversion != 1)
	{
		lastcon=convert();
		if (lastcon==0)
			basecon();
//			system("basecon.exe");
		if (lastcon==1)
			bd();
		if (lastcon==2)
			bo();
		if (lastcon==3)
			bh();
		if (lastcon==4)
			db();
		if (lastcon==5)
			deoc();
		if (lastcon==6)
			dh();
		if (lastcon==7)
			ob();
		if (lastcon==8)
			od();
		if (lastcon==9)
			atoh();
		if (lastcon==10)
			hb();
		if (lastcon==11)
			htod();
		if (lastcon==12)
			htoa();
		if (lastcon==13)
			dbcd();
		if (lastcon==14)
			dbiq();
		if (lastcon==15)
			biqd();
		if (lastcon==16)
			dqui();
		if (lastcon==17)
			quid();
		if (lastcon==18)
			dex();
		if (lastcon==19)
			exd();
		if (lastcon==20)
			bgray();
		if (lastcon==21)
			grayb();
		if (lastcon==23)
			conversion=1;
	}
}

int colcon[3]={27,225,435},rowcon[7]={110,150,190,230,270,310,350};

int convert(void)
{

	int last,conret1,conret2,conret3;
	int set=0,button;
	cursoroff();
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 75,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(182,6,"Conversion");
	outtextxy(183,7,"Conversion");
	setcolor(14);
	outtextxy(181,4,"Conversion");
	outtextxy(180,4,"Conversion");
	comman3(15,76,getmaxx()-15,getmaxy()-15,15);

	line(210,75,210,getmaxy()-75);
	line(420,75,420,getmaxy()-75);
	line(15,getmaxy()-75,getmaxx()-15,getmaxy()-75);

	for (int i=0; i<7; i++)
		comman(colcon[0],rowcon[i],colcon[0]+173,rowcon[i]+20,7);
	for (i=0; i<7; i++)
		comman(colcon[1],rowcon[i],colcon[1]+173,rowcon[i]+20,7);
	for (i=0; i<7; i++)
		comman(colcon[2],rowcon[i],colcon[2]+173,rowcon[i]+20,7);

	settextstyle(2,0,5);
	outtextxy(50,112,"Binary to Decimal");
	outtextxy(56,152,"Binary to Octal");
	outtextxy(38,192,"Binary to HexaDecimal");
	outtextxy(50,232,"Decimal to Binary");
	outtextxy(54,272,"Decimal to Octal");
	outtextxy(33,312,"Decimal to HexaDecimal");
	outtextxy(56,352,"Octal to Binary");
	outtextxy(252,112,"Octal to Decimal");
	outtextxy(240,152,"Octal to HexaDecimal");
	outtextxy(236,192,"HexaDecimal to Binary");
	outtextxy(231,232,"HexaDecimal to Decimal");
	outtextxy(240,272,"HexaDecimal to Octal");
	outtextxy(256,312,"Decimal to BCD");
	outtextxy(240,352,"Decimal to Biquinary");
	outtextxy(447,112,"Biquinary to Decimal");
	outtextxy(447,152,"Decimal to Quibinary");
	outtextxy(447,192,"Quibinary to Decimal");
	outtextxy(447,232,"Decimal to Ex-3 Code");
	outtextxy(447,272,"Ex-3 Code to Decimal");
	outtextxy(447,312,"Binary to Gray'sCode");
	outtextxy(447,352,"Gray'sCode to Binary");

	comman(60,420,375,455,7);
	settextstyle(1,0,3);
	outtextxy(70,420,"One Base to another Base");
	comman(500,420,575,455,7);
	outtextxy(515,420,"Quit");

	setcursorpos(x,y);
	cursoron();
	int flag=0,again,conver;
	while (set != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button)&&(!flag))
		{
			flag=1;
			switch (conret1=concheck1(x,y))
			{
				case 0:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=0;conver=0;
				break;
				case 1:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=1;conver=0;
				break;
				case 2:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=2;conver=0;
				break;
				case 3:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=3;conver=0;
				break;
				case 4:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=4;conver=0;
				break;
				case 5:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=5;conver=0;
				break;
				case 6:
					press1(colcon[0],rowcon[conret1],colcon[0]+173,rowcon[conret1]+20);again=6;conver=0;
				break;
			}
			switch (conret2=concheck2(x,y))
			{
				case 0:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=0;conver=1;
				break;
				case 1:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=1;conver=1;
				break;
				case 2:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=2;conver=1;
				break;
				case 3:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=3;conver=1;
				break;
				case 4:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=4;conver=1;
				break;
				case 5:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=5;conver=1;
				break;
				case 6:
					press1(colcon[1],rowcon[conret2],colcon[1]+173,rowcon[conret2]+20);again=6;conver=1;
				break;
			}
			switch (conret3=concheck3(x,y))
			{
				case 0:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=0;conver=2;
				break;
				case 1:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=1;conver=2;
				break;
				case 2:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=2;conver=2;
				break;
				case 3:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=3;conver=2;
				break;
				case 4:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=4;conver=2;
				break;
				case 5:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=5;conver=2;
				break;
				case 6:
					press1(colcon[2],rowcon[conret3],colcon[2]+173,rowcon[conret3]+20);again=6;conver=2;
				break;
			}
			if (x >= 500 && x <= 575 && y >= 420 && y <= 455)
			{
				press1(500,420,575,455);
				conver=3;
			}
			if (x >= 60 && x <= 375 && y >= 420 && y <= 455)
			{
				press1(60,420,375,455);
				conver=4;
			}
		}

		if ((!button)&&(flag))
		{
			flag=0;
			if (conver==0)
			{
				press2(colcon[0],rowcon[again],colcon[0]+173,rowcon[again]+20);
				if (x >= colcon[0] && y >= rowcon[again] && x <= colcon[0]+173 && y <= rowcon[again]+20)
				{
					cursoroff();
					sound();
					last=again+1;set=1;
				}
			}
			if (conver==1)
			{
				press2(colcon[1],rowcon[again],colcon[1]+173,rowcon[again]+20);
				if (x >= colcon[1] && y >= rowcon[again] && x <= colcon[1]+173 && y <= rowcon[again]+20)
				{
					cursoroff();
					sound();
					last=again+8;set=1;
				}
			}
			if (conver==2)
			{
				press2(colcon[2],rowcon[again],colcon[2]+173,rowcon[again]+20);
				if (x >= colcon[2] && y >= rowcon[again] && x <= colcon[2]+173 && y <= rowcon[again]+20)
				{
					cursoroff();
					sound();
					last=again+15;set=1;
				}
			}
			if (conver==3)
			{
				press2(500,420,575,455);
				if (x >= 500 && x <= 575 && y >= 420 && y <= 455)
				{
					cursoroff();
					sound();last=23;set=1;
				}
			}
			if (conver==4)
			{
				press2(60,420,375,455);
				if (x >= 60 && x <= 375 && y >= 420 && y <= 455)
				{
					cursoroff();
					sound();last=0;set=1;
				}
			}
		}
	}
	return(last);
}

int concheck1(int x,int y)
{
	for (int i=0; i<7; i++)
		if (x >= colcon[0] && y >= rowcon[i] && x <= colcon[0]+173 && y <= rowcon[i]+20)
			return(i);
	return(-1);
}

int concheck2(int x,int y)
{
	for (int i=0; i<7; i++)
		if (x >= colcon[1] && y >= rowcon[i] && x <= colcon[1]+173 && y <= rowcon[i]+20)
			return(i);
	return(-1);
}

int concheck3(int x,int y)
{
	for (int i=0; i<7; i++)
		if (x >= colcon[2] && y >= rowcon[i] && x <= colcon[2]+173 && y <= rowcon[i]+20)
			return(i);
	return(-1);
}

/*	Function of End	*/

void end(void)
{
	int iop=0,flag=0;
	while (iop != 1)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 170 && x <= 370 && y >= 400 && y <= 450)
			{
				press1(270,400,370,430);
			}
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(150);
			if (x >= 170 && x <= 370 && y >= 400 && y <= 450)
			{
				sound();
				iop=1;
				cursoroff();
			}
		}
	}
}
