#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include "d:\cld\basic.h"
#include "d:\cld\mouse.h"
#include "d:\cld\gets.h"

int bin(void);
int sea1(int x,int y);
void addition(void);
int seaad(int x,int y);
int aditcomm(void);
void substraction(void);
int seasb(int x,int y);
int subcomm(void);
void multiplication(void);
int seamu(int x,int y);
int mulcomm(void);

/*	Variables Section	*/

int col=240,row[4]={150,215,280,345};

void main(int argu)
{
	if (argu != 4)
	{
		printf("This Program Run only in Main File CLD.EXE");
		exit(1);
	}
	int ch40=0,ch41;
	int gdriver=DETECT,gmode;
	registerbgidriver(EGAVGA_driver);
	initgraph(&gdriver,&gmode,"");
//	initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

	while (ch40 != 1)
	{
		ch41=bin();
		if ( ch41==0)
			addition();
		if ( ch41==1)
			substraction();
		if ( ch41==2)
			multiplication();
		if ( ch41==3)
			ch40=1;
	}
}

int bin(void)
{
	int io=0,chio;
	setfillstyle(SOLID_FILL,3);
	bar(0,0,getmaxx(),getmaxy());
	comman(20,10,615,75,7);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(87,4,"Binary Arithmetic");
	outtextxy(88,5,"Binary Arithmetic");
	setcolor(14);
	outtextxy(86,2,"Binary Arithmetic");
	outtextxy(85,2,"Binary Arithmetic");

	setcolor(15);
	comman1(100,115,540,400,3);
	comman1(110,125,530,390,1);

	for (int i=0;i<4;i++)
		comman(col,row[i],col+165,row[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(col+35,row[0],"Addition");
	outtextxy(col+17,row[1],"Subtraction");
	outtextxy(col+5,row[2],"Multiplication");
	outtextxy(col+40,row[3],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chio=(sea1(x,y)))
			{
				case 0:
					press1(col,row[0],col+165,row[0]+35);
					again=0;
				break;
				case 1:
					press1(col,row[1],col+165,row[1]+35);
					again=1;
				break;
				case 2:
					press1(col,row[2],col+165,row[2]+35);
					again=2;
				break;
				case 3:
					press1(col,row[3],col+165,row[3]+35);
					again=3;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(col,row[again],col+165,row[again]+35);
			if (x >= col && x <= col+165 && y >= row[again] && y <= row[again]+35)
			{
				cursoroff();
				sound();
				io=1;
			}
		}
	}
	return(chio);
}

int sea1(int x,int y)
{
	for (int i = 0;i < 4;i++)
	if (x >= col && x <= col+165 && y >= row[i] && y <= row[i]+35)
		return(i);
	return(-1);
}

/*	Functions of Adition	*/

void addition(void)
{
	int addition,adit=0;
	while (adit != 1)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(200,3,"Addition");
		addition=aditcomm();
		if (addition == 0)
		{
			basicstart();
			Flush();
			binaryadition();
			basicend();
		}
		if (addition == 1)
		{
			basicstart();
			Flush();
			bcdadition();
			basicend();
		}
		if (addition == 2)
		{
			basicstart();
			Flush();
			octaladition();
			basicend();
		}
		if (addition == 3)
		{
			basicstart();
			Flush();
			hexaadition();
			basicend();
		}
		if (addition == 4)
			adit=1;
	}
}

int colad=160,rowad[5]={120,185,250,315,380};
int aditcomm(void)
{
	int ioad=0,chioad;
	for (int i=0;i<5;i++)
		comman(colad,rowad[i],colad+275,rowad[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colad+55,rowad[0],"Binary Addition");
	outtextxy(colad+75,rowad[1],"BCD Addition");
	outtextxy(colad+67,rowad[2],"Octal Addition");
	outtextxy(colad+20,rowad[3],"HexaDecmal Addition");
	outtextxy(colad+95,rowad[4],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (ioad != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chioad=(seaad(x,y)))
			{
				case 0:
					press1(colad,rowad[0],colad+275,rowad[0]+35);
					 again=0;
				break;
				case 1:
					press1(colad,rowad[1],colad+275,rowad[1]+35);
					 again=1;
				break;
				case 2:
					press1(colad,rowad[2],colad+275,rowad[2]+35);
					 again=2;
				break;
				case 3:
					press1(colad,rowad[3],colad+275,rowad[3]+35);
					 again=3;
				break;
				case 4:
					press1(colad,rowad[4],colad+275,rowad[4]+35);
					again=4;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colad,rowad[again],colad+275,rowad[again]+35);
			if (x >= colad && x <= colad+275 && y >= rowad[again] && y <= rowad[again]+35)
			{
				cursoroff();
				sound();
				ioad=1;
			}
		}
	}
	return(chioad);
}

int seaad(int x,int y)
{
	for (int i = 0;i < 5;i++)
	if (x >= colad && x <= colad+275 && y >= rowad[i] && y <= rowad[i]+35)
		return(i);
	return(-1);
}

/*	Function of Subtraction	*/

void substraction(void)
{
	int subtract,sub=0;
	while (sub != 1)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(150,3,"Subtraction");
		subtract=subcomm();
		if (subtract == 0)
		{
			basicstart();
			Flush();
			binarysubtraction();
			basicend();
		}
		if (subtract == 1)
		{
			basicstart();
			Flush();
			bcdsubtraction();
			basicend();
		}
		if (subtract == 2)
		{
			basicstart();
			Flush();
			octalsubtraction();
			basicend();
		}
		if (subtract == 3)
		{
			basicstart();
			Flush();
			hexasubtraction();
			basicend();
		}
		if (subtract == 4)
			sub=1;
	}
}

int colsb=115,rowsb[5]={120,185,250,315,380};
int subcomm(void)
{
	int iosb=0,chiosb;
	for (int i=0;i<5;i++)
		comman(colsb,rowsb[i],colsb+325,rowsb[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colsb+55,rowsb[0],"Binary Subtraction");
	outtextxy(colsb+70,rowsb[1],"BCD Subtraction");
	outtextxy(colsb+67,rowsb[2],"Octal Subtraction");
	outtextxy(colsb+20,rowsb[3],"HexaDecmal Subtraction");
	outtextxy(colsb+120,rowsb[4],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (iosb != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chiosb=(seasb(x,y)))
			{
				case 0:
					press1(colsb,rowsb[0],colsb+325,rowsb[0]+35);
					again=0;
				break;
				case 1:
					press1(colsb,rowsb[1],colsb+325,rowsb[1]+35);
					again=1;
				break;
				case 2:
					press1(colsb,rowsb[2],colsb+325,rowsb[2]+35);
					again=2;
				break;
				case 3:
					press1(colsb,rowsb[3],colsb+325,rowsb[3]+35);
					again=3;
				break;
				case 4:
					press1(colsb,rowsb[4],colsb+325,rowsb[4]+35);
					again=4;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colsb,rowsb[again],colsb+325,rowsb[again]+35);
			if (x >= colsb && x <= colsb+325 && y >= rowsb[again] && y <= rowsb[again]+35)
			{
				cursoroff();
				sound();
				iosb=1;
			}
		}
	}
	return(chiosb);
}

int seasb(int x,int y)
{
	for (int i = 0;i < 5;i++)
	if (x >= colsb && x <= colsb+325 && y >= rowsb[i] && y <= rowsb[i]+35)
		return(i);
	return(-1);
}

/*	Function of Multiplication	*/

void multiplication(void)
{
	int multipli,mul=0;
	while (mul != 1)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(125,3,"Multipliction");
		multipli=mulcomm();
		if (multipli == 0)
		{
			basicstart();
			Flush();
			binarymultiplication();
			basicend();
		}
		if (multipli == 1)
		{
			basicstart();
			Flush();
			bcdmultiplication();
			basicend();
		}
		if (multipli == 2)
			mul=1;
	}
}

int colmu=130,rowmu[3]={150,250,350};
int mulcomm(void)
{
	int iomu=0,chiomu;
	for (int i=0;i<3;i++)
		comman(colmu,rowmu[i],colmu+350,rowmu[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colmu+60,rowmu[0],"Binary Multiplication");
	outtextxy(colmu+75,rowmu[1],"BCD Multiplication");
	outtextxy(colmu+130,rowmu[2],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (iomu != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chiomu=(seamu(x,y)))
			{
				case 0:
					press1(colmu,rowmu[0],colmu+350,rowmu[0]+35);
					 again=0;
				break;
				case 1:
					press1(colmu,rowmu[1],colmu+350,rowmu[1]+35);
					again=1;
				break;
				case 2:
					press1(colmu,rowmu[2],colmu+350,rowmu[2]+35);
					again=2;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colmu,rowmu[again],colmu+350,rowmu[again]+35);
			if (x >= colmu && x <= colmu+350 && y >= rowmu[again] && y <= rowmu[again]+35)
			{
				cursoroff();
				sound();
				iomu=1;
			}
		}
	}
	return(chiomu);
}

int seamu(int x,int y)
{
	for (int i = 0;i < 3;i++)
	if (x >= colmu && x <= colmu+350 && y >= rowmu[i] && y <= rowmu[i]+35)
		return(i);
	return(-1);
}

