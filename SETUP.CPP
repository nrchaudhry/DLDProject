#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include "d:\cld\basic.h"
#include "d:\cld\mouse.h"

char *pathget(int col,int row,int binrow);

void main(void)
{
	int gdriver=DETECT,gmode,first=1;
	char source[50],destination[50];
	registerbgidriver(EGAVGA_driver);
	initgraph(&gdriver,&gmode,"");
//	initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
	comman2(0,0,getmaxx(),getmaxy(),1);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	setcolor(0);
	outtextxy(32,39,"Computer Logic and Design");
	outtextxy(33,40,"Computer Logic and Design");
	setcolor(14);
	outtextxy(31,38,"Computer Logic and Design");
	outtextxy(30,38,"Computer Logic and Design");
	comman(130,120,515,320,7);
	comman1(260,200,489,220,15);
	setcolor(0);
	settextstyle(2,0,5);
	outtextxy(170,140,"Enter the path of Destination :");
	outtextxy(160,200,"Destination :");
	strcpy(destination,"C:\\CLD");
	comman2(263,203,315,218,19);
	outtextxy(265,203,destination);
	char ch=getch();
	if (ch==13)
	{
		comman2(263,203,320,218,15);
		outtextxy(265,203,destination);
	}
	else
	{
		comman2(263,203,320,218,15);
		strcpy(destination,pathget(265,203,200));
	}
	char copy[20]="copy *.* ",md[20]="md ",del[20]="del ";
	strcat(md,destination);
	strcat(copy,destination);
	strcat(del,destination);
	strcat(del,"\setup.exe");
	system(md);

	system("ren ng000.ng cld.exe");
	system("ren ng001.ng num-sys.exe");
	system("ren ng002.ng bin-art.exe");
	system("ren ng003.ng boo-alg.exe");
	system("ren ng004.ng boolean.exe");
	system("ren ng005.ng gatesfun.exe");
	system("ren ng006.ng com-cir.exe");

	system("ren ng00011.ng bold.chr");
	system("ren ng00012.ng euro.chr");
	system("ren ng00013.ng goth.chr");
	system("ren ng00014.ng lcom.chr");
	system("ren ng00015.ng litt.chr");
	system("ren ng00016.ng sans.chr");
	system("ren ng00017.ng scri.chr");
	system("ren ng00018.ng simp.chr");
	system("ren ng00019.ng trip.chr");
	system("ren ng00020.ng tscr.chr");

	system(copy);

	system("ren cld.exe ng000.ng");
	system("ren num-sys.exe ng001.ng");
	system("ren bin-art.exe ng002.ng");
	system("ren boo-alg.exe ng003.ng");
	system("ren boolean.exe ng004.ng");
	system("ren gatesfun.exe ng005.ng");
	system("ren com-cir.exe ng006.ng");

	system("ren bold.chr ng00011.ng");
	system("ren euro.chr ng00012.ng");
	system("ren goth.chr ng00013.ng");
	system("ren lcom.chr ng00014.ng");
	system("ren litt.chr ng00015.ng");
	system("ren sans.chr ng00016.ng");
	system("ren scri.chr ng00017.ng");
	system("ren simp.chr ng00018.ng");
	system("ren trip.chr ng00019.ng");
	system("ren tscr.chr ng00020.ng");

	system(del);
	closegraph();
}

char *pathget(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if ((i>=16)&&(ch!=8))
			sound();
		else
		{
		get[i] = ch;
		get[i+1] = '\0';
		if ((ch==8)&&(i>0))
		{
			i--;
			get[i] = '\0';
			i--;
			cursor-=16;
		}
		comman1(260,binrow,489,binrow+20,15);
		cursor+=8;
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(260,binrow,489,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}
