#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include "c:\cld\basic.h"


void main(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	comman2(0,0,getmaxx(),getmaxy(),3);
	comman(120,20,515,450,7);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	setcolor(0);
	outtextxy(152,79,"Computer Logic");
	outtextxy(153,80,"Computer Logic");
	outtextxy(202,141,"and Design");
	outtextxy(203,142,"and Design");
	setcolor(1);
	outtextxy(151,78,"Computer Logic");
	outtextxy(150,78,"Computer Logic");
	outtextxy(201,140,"and Design");
	outtextxy(200,140,"and Design");
	settextstyle(SMALL_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(260,290,"Version  1.0");
	outtextxy(170,320,"Copyright (c)  1999 , 2000 by");
	outtextxy(250,350,"Nuaman Riaz Ch.");
	getch();
}
