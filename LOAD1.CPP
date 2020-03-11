#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include "d:\cld\basic.h"

void start(void);
void end(void);
void startup(char str[]);
void startup1(void);
void nccs(void);

void main(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"d:\\tc\\bgi");
	startup("Good Bye");
	getch();
}
void start(void)
{
	startup1();
	delay(5000);
	nccs();
	delay(5000);
	startup("WelCome");
	delay(5000);
	comman2(0,0,getmaxx(),getmaxy(),0);
	settextstyle(1,0,6);
	setcolor(15);
	outtextxy(150,200,"Please Wait....");
	delay(5000);
}

void nccs(void)
{
	int a1,a2;
	comman2(0,0,getmaxx(),getmaxy(),1);
	a1 = getmaxx ()/2;
	a2 = getmaxx ()/2;
	setcolor (15);
	for(int m=23;m<(getmaxx ()/2) ;m++)
	{
		line(a1,23,a1,448);a1--;
		line(a2,23,a2,448);a2++;
		delay (10);
	}
	setcolor(0);
	line(20,20,615,20);
	line(20,20,20,450);
	line(20,450,615,450);
	line(615,20,615,450);
	setfillstyle(SOLID_FILL,1);
	bar(220,120,415,250);
	setcolor(15);
	line(318,120,318,250);
	line(318,250,415,153);
	line(220,155,315,250);
	setfillstyle(SOLID_FILL,15);
	bar(220,120,255,190);
	bar(378,120,416,190);
	setcolor(15);
	setlinestyle(0, 1, 3);
	line(318,180,437,60);
	line(318,179,437,59);
	line(318,178,437,58);
	line(318,177,437,57);
	line(318,176,437,56);
	line(318,175,437,55);
	line(318,174,437,54);
	line(318,173,437,53);
	line(318,172,437,52);
	line(318,171,437,51);
	line(318,170,437,50);
	line(198,60,318,180);
	line(198,59,318,179);
	line(198,58,318,178);
	line(198,57,318,177);
	line(198,56,318,176);
	line(198,55,318,175);
	line(198,54,318,174);
	line(198,53,318,173);
	line(198,52,318,172);
	line(198,51,318,171);
	bar(260,110,375,120);
	bar(270,110,365,130);
	bar(280,110,355,140);
	bar(290,110,345,150);
	bar(300,110,335,160);
	bar(310,110,325,170);
	setfillstyle(SOLID_FILL,1);
	bar(390,191,445,250);
	bar(188,191,225,250);
	setcolor(15);
	setlinestyle(0, 1, 3);
	line(188,191,247,250);
	line(386,250,445,191);
	setfillstyle(SOLID_FILL,15);
	bar(390,245,445,250);
	bar(400,235,445,250);
	bar(410,225,445,250);
	bar(420,215,445,250);
	bar(430,205,445,250);
	bar(440,195,445,250);
	bar(188,195,193,250);
	bar(188,205,203,250);
	bar(188,215,213,250);
	bar(188,225,223,250);
	bar(188,235,233,250);
	bar(188,245,243,250);
	setlinestyle(0, 1, 3);
	line(188,191,247,250);
	line(188,192,247,251);
	line(188,193,247,252);
	line(188,194,247,253);
	line(188,195,247,254);
	line(188,196,247,255);
	line(188,197,247,256);
	line(386,250,445,191);
	line(386,251,445,192);
	line(386,252,445,193);
	line(386,253,445,194);
	line(386,254,445,195);
	line(386,255,445,196);
	line(386,256,445,197);
    setcolor(1);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	outtextxy(250,250,"N");
	outtextxy(250,251,"N");
	outtextxy(290,250,"C");
	outtextxy(290,251,"C");
	outtextxy(330,250,"C");
	outtextxy(330,251,"C");
	outtextxy(370,250,"S");
	outtextxy(370,251,"S");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setcolor(1);
	outtextxy(135,311,"THE NATIONAL COLLEGE");
	outtextxy(135,312,"THE NATIONAL COLLEGE");
	outtextxy(230,351,"RAWALPINDI.");
	outtextxy(230,352,"RAWALPINDI.");
}
/*	comman2(0,0,getmaxx(),getmaxy(),1);
	comman(125,50,getmaxx()-125,getmaxy()-50,7);
	getch();*/
void startup(char str[])
{
	int a1,a2;
	comman2(0,0,getmaxx(),getmaxy(),1);
	a1 = getmaxx ()/2;
	a2 = getmaxx ()/2;
	setcolor (15);
	for(int m=23;m<(getmaxx ()/2) ;m++)
	{
		line(a1,23,a1,448);a1--;
		line(a2,23,a2,448);a2++;
		delay (10);
	}
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 7);
	setcolor(1);
	outtextxy(164,33,str);
	outtextxy(165,34,str);
	outtextxy(166,35,str);
	outtextxy(167,36,str);
	line(140,110,470,110);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
	setcolor(4);
	outtextxy(32,110,"Gujar's Software Company,");
	outtextxy(33,111,"Gujar's Software Company,");
	outtextxy(34,112,"Gujar's Software Company,");

	outtextxy(377,150,"Wazirabad.");
	outtextxy(378,151,"Wazirabad.");
	outtextxy(379,152,"Wazirabad.");
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	outtextxy(90,230,"Nuaman Riaz Ch.");
	outtextxy(91,231,"Nuaman Riaz Ch.");
	outtextxy(92,232,"Nuaman Riaz Ch.");

	setcolor(3);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	outtextxy(70,295,"Friend's :");
	outtextxy(71,296,"Friend's :");

	outtextxy(30,185,"Presendented By :");
	outtextxy(31,186,"Presendented By :");
	setcolor(1);

	outtextxy(230,315,"Ali Raza Butt.");
	outtextxy(231,316,"Ali Raza Butt.");

	outtextxy(230,360,"Asif Farooq Butt.");
	outtextxy(231,361,"Asif Farooq Butt.");

	outtextxy(230,405,"Gulshan Shahzad.");
	outtextxy(231,406,"Gulshan Shahzad.");
}

void startup1(void)
{
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
}
