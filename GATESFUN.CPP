#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
int button;
#include "d:\cld\basic.h"
#include "d:\cld\mouse.h"
#include "d:\cld\allgate.h"

int gatesopt(void);
int seapbl(int x,int y);
int seapbl1(int x,int y);

int colpbl=70,colpbl1=360,rowpbl[6]={150,220,290,360};

//void main(void)
//{
void main(int argu)
{
	if (argu != 4)
	{
		printf("This Program Run only in Main File CLD.EXE");
		exit(1);
	}
	int gdriver=DETECT,gmode;
	registerbgidriver(EGAVGA_driver);
	initgraph(&gdriver,&gmode,"");
//	initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
	int pbl,pb=0;
	while (pb != 1)
	{
		comman3(0, 0, getmaxx(), getmaxy(), 11);
		comman(0, 0, getmaxx(), 70,1);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
		setcolor(0);
		outtextxy(182,3,"Logic Gates");
		outtextxy(183,4,"Logic Gates");
		setcolor(14);
		outtextxy(181,1,"Logic Gates");
		outtextxy(180,1,"Logic Gates");
		comman3(15,70,getmaxx()-15,getmaxy()-15,15);
		pbl=gatesopt();
		if (pbl == 0)
			anddefination();
		if (pbl == 1)
			ordefination();
		if (pbl == 2)
			xordefination();
		if (pbl == 3)
			notdefination();
		if (pbl == 4)
			nanddefination();
		if (pbl == 5)
			nordefination();
		if (pbl == 6)
			xnordefination();
		if (pbl == 7)
			pb=1;
	}
}

int gatesopt(void)
{
	int iopbl=0,comeback;
	line(300,71,300,463);
	for (int i=0;i<4;i++)
		comman(colpbl,rowpbl[i],colpbl+175,rowpbl[i]+35,7);
	for (i=0;i<4;i++)
		comman(colpbl1,rowpbl[i],colpbl1+175,rowpbl[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colpbl+35,rowpbl[0],"AND Gate");
	outtextxy(colpbl+42,rowpbl[1],"OR Gate");
	outtextxy(colpbl+30,rowpbl[2],"X-OR Gate");
	outtextxy(colpbl+35,rowpbl[3],"NOT Gate");
	outtextxy(colpbl1+25,rowpbl[0],"NAND Gate");
	outtextxy(colpbl1+32,rowpbl[1],"NOR Gate");
	outtextxy(colpbl1+20,rowpbl[2],"X-NOR Gate");
	outtextxy(colpbl1+45,rowpbl[3],"Q U I T");
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
					press1(colpbl,rowpbl[0],colpbl+175,rowpbl[0]+35);
					again=0;again1=0;
				break;
				case 1:
					press1(colpbl,rowpbl[1],colpbl+175,rowpbl[1]+35);
					again=0;again1=1;
				break;
				case 2:
					press1(colpbl,rowpbl[2],colpbl+175,rowpbl[2]+35);
					again=0;again1=2;
				break;
				case 3:
					press1(colpbl,rowpbl[3],colpbl+175,rowpbl[3]+35);
					again=0;again1=3;
				break;
			}

			switch (seapbl1(x,y))
			{
				case 0:
					press1(colpbl1,rowpbl[0],colpbl1+175,rowpbl[0]+35);
					again=1;again2=0;
				break;
				case 1:
					press1(colpbl1,rowpbl[1],colpbl1+175,rowpbl[1]+35);
					again=1;again2=1;
				break;
				case 2:
					press1(colpbl1,rowpbl[2],colpbl1+175,rowpbl[2]+35);
					again=1;again2=2;
				break;
				case 3:
					press1(colpbl1,rowpbl[3],colpbl1+175,rowpbl[3]+35);
					again=1;again2=3;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			if (!again)
			{
				press2(colpbl,rowpbl[again1],colpbl+175,rowpbl[again1]+35);
				if (x >= colpbl && x <= colpbl+175 && y >= rowpbl[again1] && y <= rowpbl[again1]+35)
				{
					cursoroff();
					sound();
					iopbl=1;comeback=again1;
				}
			}
			else
			{
				press2(colpbl1,rowpbl[again2],colpbl1+175,rowpbl[again2]+35);
				if (x >= colpbl1 && x <= colpbl1+175 && y >= rowpbl[again2] && y <= rowpbl[again2]+35)
				{
					cursoroff();
					sound();
					iopbl=1;comeback=again2+4;
				}

			}
		}
	}
	return(comeback);
}

int seapbl(int x,int y)
{
	for (int i = 0;i < 6;i++)
	if (x >= colpbl && x <= colpbl+175 && y >= rowpbl[i] && y <= rowpbl[i]+35)
		return(i);
	return(-1);
}

int seapbl1(int x,int y)
{
	for (int i = 0;i < 6;i++)
	if (x >= colpbl1 && x <= colpbl1+175 && y >= rowpbl[i] && y <= rowpbl[i]+35)
		return(i);
	return(-1);
}
