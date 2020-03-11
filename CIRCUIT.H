#include "d:\cld\gates.h"

void orencoder(int x,int y);
void bcdencoder(void);
void decodercircuit(void);

void linedraw(int col1,int row1,int col2,int row2);
void bara(int col,int row);
void barb(int col,int row);
void barc(int col,int row);
void barab(int col,int row);
void ci(int col,int row);
void co(int col,int row);
void barci(int col,int row);
void addsubcircuit(void);

void amul(int,int,int);
void bmul(int,int,int);
void pmul(int,int,int);
void twobit(void);
void threebit(void);

/*	Function of Full Adder	*/

void fulladdercir(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(125,50,"Block Diagram of a Full Adder");
	settextstyle(1,0,5);
	outtextxy(125,125,"a");
	outtextxy(125,175,"b");
	outtextxy(125,225,"c");
	settextstyle(2,0,6);
	outtextxy(145,255,"i");
	settextstyle(1,0,5);
	setcolor(14);
	linedraw(150,157,250,157);
	linedraw(150,207,250,207);
	linedraw(150,257,250,257);
	setcolor(3);
	rectangle(250,125,400,280);
	setcolor(15);
	outtextxy(290,177,"F.A");
	setcolor(14);
	linedraw(401,157,500,157);
	linedraw(401,257,500,257);
	setcolor(15);
	outtextxy(525,127,"S");
	outtextxy(525,227,"C");
	settextstyle(2,0,6);
	outtextxy(549,253,"o");
	settextstyle(1,0,3);
	outtextxy(35,187,"Input");
	outtextxy(515,187,"output");
	settextstyle(7,0,3);
	outtextxy(40,330,"Press Enter to Continue, Press Esc to Quit");
	Flush();
	char chr=getch();
	while((chr!=13)&&(chr!=27))
	{
		sound();
		chr=getch();
	}
	if (chr==13)
	{
		comman2(0,0,getmaxx(),getmaxy(),0);
		settextstyle(7,0,3);
		outtextxy(125,5,"Logic Circuit for Full Adder");
		setcolor(14);
		settextstyle(1,0,3);
		outtextxy(100,50,"S =     +  b   + a    +  ab");

		bara(145,50);barb(163,50);bara(222,50);
		ci(180,50);barci(256,50);
		barb(330,50);barci(350,50);ci(443,50);
		outtextxy(120,85,"= a + ( b +   )");
		ci(270,85);circle(177,101,10);circle(250,101,10);
		co(220,120);
		outtextxy(238,120," = ab + ( a + b )");
		ci(454,120);circle(392,136,10);

		setcolor(15);
		settextstyle(1,0,5);
		outtextxy(25,135,"a");
		outtextxy(25,225,"b");
		outtextxy(25,375,"c");
		settextstyle(2,0,6);
		outtextxy(45,405,"i");
		settextstyle(1,0,5);
		setcolor(14);
		linedraw(50,167,210,167);
		linedraw(50,257,100,257);
		linedraw(100,257,100,387);
		linedraw(100,387,125,387);
		linedraw(50,407,125,407);
		setcolor(13);
		xor(60,397);
		setcolor(14);
		linedraw(181,397,190,397);
		linedraw(190,187,190,397);
		linedraw(190,187,210,187);
		setcolor(13);
		xor(145,177);
		setcolor(14);
		linedraw(266,177,570,177);
		setcolor(15);
		outtextxy(580,150,"S");
		setcolor(14);
		linedraw(120,167,120,347);
		linedraw(120,347,270,347);
		linedraw(75,367,75,407);
		linedraw(75,367,270,367);
		setcolor(9);
		and(301,357);
		setcolor(14);
		linedraw(120,217,270,217);
		linedraw(100,257,140,257);
		linedraw(140,237,140,257);
		linedraw(140,237,270,237);
		setcolor(9);
		and(301,227);
		setcolor(14);
		linedraw(140,257,140,277);
		linedraw(140,277,270,277);
		linedraw(75,297,75,367);
		linedraw(75,297,270,297);
		setcolor(9);
		and(301,287);
		setcolor(14);
		linedraw(315,287,400,287);
		linedraw(315,227,350,227);
		linedraw(350,227,350,277);
		linedraw(350,277,400,277);
		linedraw(315,357,350,357);
		linedraw(350,297,350,357);
		linedraw(350,297,400,297);
		setcolor(10);
		or(324,287);
		setcolor(14);
		linedraw(445,287,570,287);
		setcolor(15);
		outtextxy(580,260,"C");
		settextstyle(2,0,6);
		outtextxy(604,286,"o");
		settextstyle(7,0,3);
		outtextxy(40,430,"Press Enter to Continue, Press Esc to Quit");
		Flush();

		chr=getch();
		while((chr!=13)&&(chr!=27))
		{
			sound();
			chr=getch();
		}
		if (chr==13)
		{
			comman2(0,0,getmaxx(),getmaxy(),0);
			settextstyle(7,0,3);
			outtextxy(5,25,"Logic Circuit for Full Adder the Second Expression");
			setcolor(15);
			settextstyle(1,0,5);
			outtextxy(25,135,"c");
			settextstyle(2,0,6);
			outtextxy(45,165,"i");
			settextstyle(1,0,5);
			outtextxy(25,250,"a");
			outtextxy(25,350,"b");
			setcolor(14);
			linedraw(50,167,250,167);
			linedraw(250,167,250,187);
			linedraw(250,187,350,187);
			linedraw(50,282,100,282);
			linedraw(100,322,150,322);
			linedraw(100,282,100,322);
			linedraw(50,382,100,382);
			linedraw(100,342,100,382);
			linedraw(100,342,150,342);
			setcolor(13);
			xor(85,332);
			setcolor(14);
			linedraw(206,332,250,332);
			linedraw(250,207,250,332);
			linedraw(250,207,350,207);
			setcolor(13);
			xor(285,197);
			setcolor(14);
			linedraw(406,197,570,197);
			setcolor(15);
			outtextxy(580,170,"S");
			setcolor(14);
			linedraw(230,167,230,312);
			linedraw(230,312,300,312);
			linedraw(250,332,300,332);
			setcolor(9);
			and(330,322);
			setcolor(14);
			linedraw(345,322,400,322);
			linedraw(400,322,400,372);
			linedraw(400,372,450,372);
			linedraw(75,282,75,402);
			linedraw(75,402,225,402);
			linedraw(100,382,225,382);
			setcolor(9);
			and(255,392);
			setcolor(14);
			linedraw(270,392,450,392);
			setcolor(10);
			or(376,382);
			setcolor(14);
			linedraw(498,382,570,382);
			setcolor(15);
			outtextxy(580,355,"C");
			settextstyle(2,0,6);
			outtextxy(604,381,"o");
			settextstyle(7,0,3);
			outtextxy(40,430,"Press Enter to Continue, Press Esc to Quit");
			Flush();

			chr=getch();
			while((chr!=13)&&(chr!=27))
			{
				sound();
				chr=getch();
			}
			if (chr==13)
			{
				comman2(0,0,getmaxx(),getmaxy(),0);
				settextstyle(7,0,2);
				outtextxy(20,50,"Construction of a Full Adder using two Half Adder");
				settextstyle(1,0,5);
				outtextxy(25,125,"a");
				outtextxy(25,200,"b");
				outtextxy(25,325,"c");
				settextstyle(2,0,6);
				outtextxy(45,355,"i");
				settextstyle(1,0,5);
				setcolor(14);
				linedraw(50,157,125,157);
				linedraw(50,232,125,232);
				setcolor(3);
				rectangle(125,135,275,255);
				settextstyle(1,0,4);
				setcolor(15);
				outtextxy(160,167,"H.A-1");
				setcolor(14);
				linedraw(276,232,325,232);
				linedraw(325,232,325,337);
				linedraw(325,337,350,337);
				linedraw(50,357,350,357);
				setcolor(3);
				rectangle(351,317,450,377);
				setcolor(15);
				outtextxy(357,327,"H.A-2");
				setcolor(14);
				linedraw(451,357,570,357);
				settextstyle(1,0,5);
				setcolor(15);
				outtextxy(580,327,"S");
				setcolor(14);
				linedraw(276,157,480,157);
				linedraw(451,337,461,337);
				linedraw(461,177,461,337);
				linedraw(461,177,480,177);
				setcolor(10);
				or(405,167);
				setcolor(14);
				linedraw(526,167,570,167);
				setcolor(15);
				outtextxy(580,137,"C");
				settextstyle(2,0,6);
				outtextxy(604,163,"o");
				settextstyle(7,0,3);
				outtextxy(40,390,"Press Enter to Continue, Press Esc to Quit");
				Flush();
				getch();
			}
		}
	}
}

/*	Function of Full Subtractor	*/

void fullsubcir(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(100,50,"Block Diagram of a Full Subtractor");
	settextstyle(1,0,5);
	outtextxy(125,125,"a");
	outtextxy(125,175,"b");
	outtextxy(125,225,"c");
	setcolor(14);
	linedraw(150,157,250,157);
	linedraw(150,207,250,207);
	linedraw(150,257,250,257);
	setcolor(3);
	rectangle(250,125,400,280);
	setcolor(15);
	outtextxy(290,177,"F.S");
	setcolor(14);
	linedraw(401,157,500,157);
	linedraw(401,257,500,257);
	setcolor(15);
	outtextxy(525,127,"D");
	outtextxy(525,227,"B");
	settextstyle(1,0,3);
	outtextxy(35,187,"Input");
	outtextxy(515,187,"output");
	settextstyle(7,0,3);
	outtextxy(40,330,"Press Enter to Continue, Press Esc to Quit");
	Flush();
	char chr=getch();
	while((chr!=13)&&(chr!=27))
	{
		sound();
		chr=getch();
	}
	if (chr==13)
	{
		comman2(0,0,getmaxx(),getmaxy(),0);
		settextstyle(7,0,1);
		outtextxy(20,50,"Logic Circuit for Full Subtractor using two Half Subtractor");
		settextstyle(1,0,5);
		outtextxy(25,125,"a");
		outtextxy(25,200,"b");
		outtextxy(25,325,"c");
		setcolor(14);
		linedraw(50,157,125,157);
		linedraw(50,232,125,232);
		setcolor(3);
		rectangle(125,135,275,255);
		settextstyle(1,0,4);
		setcolor(15);
		outtextxy(160,167,"H.S-1");
		setcolor(14);
		linedraw(276,232,325,232);
		linedraw(325,232,325,337);
		linedraw(325,337,350,337);
		linedraw(50,357,350,357);
		setcolor(3);
		rectangle(351,317,450,377);
		setcolor(15);
		outtextxy(357,327,"H.S-2");
		setcolor(14);
		linedraw(451,357,570,357);
		settextstyle(1,0,5);
		setcolor(15);
		outtextxy(580,327,"D");
		setcolor(14);
		linedraw(276,157,480,157);
		linedraw(451,337,461,337);
		linedraw(461,177,461,337);
		linedraw(461,177,480,177);
		setcolor(10);
		or(405,167);
		setcolor(14);
		linedraw(526,167,570,167);
		setcolor(15);
		outtextxy(580,137,"B");
		settextstyle(7,0,3);
		outtextxy(40,390,"Press Enter to Continue, Press Esc to Quit");
		Flush();
		getch();
	}
}

/*	Function of Half Adder	*/

void halfaddercir(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(125,50,"                             ");
	outtextxy(125,50,"Block Diagram of a Half Adder");
	settextstyle(1,0,5);
	outtextxy(125,125,"a");
	outtextxy(125,225,"b");
	setcolor(14);
	linedraw(150,157,250,157);
	linedraw(150,257,250,257);
	setcolor(3);
	rectangle(250,125,400,280);
	setcolor(15);
	outtextxy(290,177,"H.A");
	setcolor(14);
	linedraw(401,157,500,157);
	linedraw(401,257,500,257);
	setcolor(15);
	outtextxy(525,127,"S");
	outtextxy(525,227,"C");
	settextstyle(1,0,3);
	outtextxy(115,187,"Input");
	outtextxy(515,187,"output");
	settextstyle(7,0,3);
	outtextxy(40,330,"Press Enter to Continue, Press Esc to Quit");
	Flush();
	char chr=getch();
	while((chr!=13)&&(chr!=27))
	{
		sound();
		chr=getch();
	}
	if (chr==13)
	{
		comman2(0,0,getmaxx(),getmaxy(),0);
		settextstyle(7,0,3);
		outtextxy(25,50,"Logic Circuit for Half Adder using Basic Gates.");
		settextstyle(1,0,5);
		outtextxy(75,125,"a");
		outtextxy(75,225,"b");
		setcolor(14);
		linedraw(100,157,180,157);
		setcolor(11);
		not(180,145);
		setcolor(14);
		linedraw(219,157,250,157);
		linedraw(250,157,250,180);
		linedraw(250,180,290,180);
		linedraw(100,257,250,257);
		linedraw(250,200,250,257);
		linedraw(250,200,290,200);
		setcolor(9);
		and(320,190);
		setcolor(14);
		linedraw(140,157,140,330);
		linedraw(140,330,290,330);
		linedraw(175,257,175,310);
		linedraw(175,310,200,310);
		setcolor(11);
		not(200,298);
		setcolor(14);
		linedraw(239,310,290,310);
		setcolor(9);
		and(320,320);
		setcolor(14);
		linedraw(335,190,390,190);
		linedraw(390,190,390,245);
		linedraw(390,245,440,245);
		linedraw(335,320,390,320);
		linedraw(390,265,390,320);
		linedraw(390,265,440,265);
		setcolor(10);
		or(365,255);
		setcolor(14);
		linedraw(487,255,540,255);
		settextstyle(1,0,5);
		setcolor(15);
		outtextxy(560,225,"S");
		setcolor(14);
		linedraw(140,330,140,380);
		linedraw(140,380,390,380);
		linedraw(115,257,115,400);
		linedraw(115,400,390,400);
		setcolor(9);
		and(420,390);
		setcolor(14);
		linedraw(435,390,540,390);
		settextstyle(1,0,5);
		setcolor(15);
		outtextxy(560,360,"C");
		settextstyle(7,0,3);
		outtextxy(40,430,"Press Enter to Continue, Press Esc to Quit");
		Flush();
		chr=getch();
		while((chr!=13)&&(chr!=27))
		{
			sound();
			chr=getch();
		}
		if (chr==13)
		{
			comman2(0,0,getmaxx(),getmaxy(),0);
			settextstyle(7,0,3);
			outtextxy(25,5,"Logic Circuit for Half Adder using XOR Gates.");
			setcolor(14);
			settextstyle(1,0,3);
			outtextxy(100,50,"S = a  +  b = (a + b)(  +  )");
			barb(163,50);bara(213,50);
			bara(370,50);barb(413,50);
			outtextxy(120,85,"= (a + b)(    ) = a + b");
			barab(243,85);circle(359,101,10);
			outtextxy(120,120,"C = a . b");
			setcolor(15);
			settextstyle(1,0,5);
			outtextxy(75,125,"a");
			outtextxy(75,225,"b");
			setcolor(14);
			linedraw(100,157,250,157);
			linedraw(250,157,250,180);
			linedraw(250,180,290,180);
			linedraw(100,257,250,257);
			linedraw(250,200,250,257);
			linedraw(250,200,290,200);
			setcolor(13);
			xor(225,190);
			setcolor(14);
			linedraw(347,190,540,190);
			settextstyle(1,0,5);
			setcolor(15);
			outtextxy(560,160,"S");
			setcolor(14);
			linedraw(140,157,140,300);
			linedraw(140,300,290,300);
			linedraw(115,257,115,320);
			linedraw(115,320,290,320);
			setcolor(9);
			and(320,310);
			setcolor(14);
			linedraw(335,310,540,310);
			settextstyle(1,0,5);
			setcolor(15);
			outtextxy(560,280,"C");
			settextstyle(7,0,3);
			outtextxy(40,400,"Press Enter to Continue, Press Esc to Quit");
			Flush();
			chr=getch();
			while((chr!=13)&&(chr!=27))
			{
				sound();
				chr=getch();
			}
			if (chr==13)
			{
				comman2(0,0,getmaxx(),getmaxy(),0);
				settextstyle(7,0,3);
				outtextxy(25,5,"Logic Circuit for Half Adder using NAND Gates.");
				settextstyle(1,0,5);
				outtextxy(50,125,"a");
				outtextxy(50,225,"b");
				setcolor(14);
				settextstyle(1,0,3);
				outtextxy(100,50,"S = a  +  b = a  .   b");
				barb(163,50);bara(213,50);
				line(150,48,240,48);
				line(150,44,240,44);
				barb(290,50);bara(338,50);
				line(278,50,303,50);
				line(340,50,370,50);
				line(278,44,370,44);
				outtextxy(120,100,"C = a . b");
				line(172,100,224,100);
				line(172,96,224,96);
				setcolor(15);
				setcolor(14);
				linedraw(75,157,245,157);
				linedraw(245,157,245,180);
				linedraw(245,180,265,180);
				linedraw(75,257,180,257);
				linedraw(160,257,160,277);
				linedraw(160,277,180,277);
				setcolor(12);
				nand(210,267);
				setcolor(14);
				linedraw(235,267,245,267);
				linedraw(245,200,245,267);
				linedraw(245,200,265,200);
				setcolor(12);
				nand(295,190);
				setcolor(14);
				linedraw(100,157,100,310);
				linedraw(100,310,180,310);
				linedraw(160,310,160,330);
				linedraw(160,330,180,330);
				setcolor(12);
				nand(210,320);
				setcolor(14);
				linedraw(236,320,267,320);
				linedraw(120,257,120,295);
				linedraw(120,295,236,295);
				linedraw(236,295,236,300);
				linedraw(236,300,267,300);
				setcolor(12);
				nand(297,310);
				setcolor(14);
				linedraw(322,190,390,190);
				linedraw(390,190,390,245);
				linedraw(390,245,440,245);
				linedraw(323,310,390,310);
				linedraw(390,265,390,310);
				linedraw(390,265,440,265);
				setcolor(12);
				nand(470,255);
				setcolor(14);
				linedraw(496,255,540,255);
				settextstyle(1,0,5);
				setcolor(15);
				outtextxy(560,225,"S");
				setcolor(14);
				linedraw(100,310,100,380);
				linedraw(100,380,267,380);
				linedraw(80,257,80,400);
				linedraw(80,400,267,400);
				setcolor(12);
				nand(297,390);
				setcolor(14);
				linedraw(323,390,440,390);
				linedraw(420,390,420,400);
				linedraw(420,400,440,400);
				setcolor(12);
				nand(470,395);
				setcolor(14);
				linedraw(496,395,540,395);
				settextstyle(1,0,5);
				setcolor(15);
				outtextxy(560,365,"C");
				settextstyle(7,0,3);
				outtextxy(40,430,"Press Enter to Continue, Press Esc to Quit");
				Flush();
				chr=getch();
				while((chr!=13)&&(chr!=27))
				{
					sound();
					chr=getch();
				}
				if (chr==13)
				{
					comman2(0,0,getmaxx(),getmaxy(),0);
					settextstyle(7,0,3);
					outtextxy(25,5,"Logic Circuit for Half Adder using NOR Gates.");
					setcolor(14);
					settextstyle(1,0,3);
					outtextxy(100,50,"S = a  +  b = (  + b)(a +  )");
					barb(163,50);bara(213,50);
					line(150,48,240,48);
					line(150,44,240,44);
					bara(290,50);barb(413,50);
					line(280,48,430,48);
					outtextxy(120,85,"= (  + b) + (a +  )");
					line(150,83,220,83);
					line(270,83,340,83);
					bara(155,85);barb(320,85);

					outtextxy(220,120,"C = a . b");
					line(272,124,325,124);
					line(272,120,325,120);
					setcolor(15);
					settextstyle(1,0,5);
					outtextxy(25,125,"a");
					outtextxy(25,225,"b");
					setcolor(14);
					linedraw(50,157,100,157);
					linedraw(85,157,85,177);
					linedraw(85,177,100,177);
					setcolor(6);
					nor(25,167);
					setcolor(14);
					linedraw(158,167,215,167);
					linedraw(50,257,190,257);
					linedraw(190,187,190,327);
					linedraw(190,187,215,187);
					setcolor(6);
					nor(140,177);
					setcolor(14);
					linedraw(190,307,215,307);
					linedraw(190,327,215,327);
					setcolor(6);
					nor(140,317);
					setcolor(14);
					linedraw(65,157,65,277);
					linedraw(65,277,305,277);
					linedraw(273,317,285,317);
					linedraw(285,297,285,317);
					linedraw(285,297,305,297);
					setcolor(6);
					nor(230,287);
					setcolor(14);
					linedraw(273,177,380,177);
					linedraw(380,177,380,207);
					linedraw(380,207,400,207);
					linedraw(363,287,380,287);
					linedraw(380,227,380,287);
					linedraw(380,227,400,227);
					setcolor(6);
					nor(326,217);
					setcolor(14);
					linedraw(459,217,490,217);
					linedraw(470,217,470,237);
					linedraw(470,237,490,237);
					setcolor(6);
					nor(416,227);
					setcolor(14);
					linedraw(550,227,590,227);
					settextstyle(1,0,5);
					setcolor(15);
					outtextxy(600,200,"S");
					setcolor(14);
					linedraw(175,167,175,400);
					linedraw(175,400,400,400);
					linedraw(285,317,285,380);
					linedraw(285,380,400,380);
					setcolor(6);
					nor(326,390);
					setcolor(14);
					linedraw(459,390,490,390);
					linedraw(470,390,470,410);
					linedraw(470,410,490,410);
					setcolor(6);
					nor(416,400);
					setcolor(14);
					linedraw(550,400,590,400);
					settextstyle(1,0,5);
					setcolor(15);
					outtextxy(600,370,"C");
					settextstyle(7,0,3);
					outtextxy(40,430,"Press Enter to Continue, Press Esc to Quit");
					getch();
				}
			}
		}
	}

}

/*	Function of Half Subtractor	*/

void halfsubcir(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(100,50,"Block Diagram of a Half Subtractor");
	settextstyle(1,0,5);
	outtextxy(125,125,"a");
	outtextxy(125,225,"b");
	setcolor(14);
	linedraw(150,157,250,157);
	linedraw(150,257,250,257);
	setcolor(3);
	rectangle(250,125,400,280);
	setcolor(15);
	outtextxy(290,177,"H.S");
	setcolor(14);
	linedraw(401,157,500,157);
	linedraw(401,257,500,257);
	setcolor(15);
	outtextxy(525,127,"D");
	outtextxy(525,227,"B");
	settextstyle(1,0,3);
	outtextxy(115,187,"Input");
	outtextxy(515,187,"output");
	settextstyle(7,0,3);
	outtextxy(40,330,"Press Enter to Continue, Press Esc to Quit");
	Flush();
	char chr=getch();
	while((chr!=13)&&(chr!=27))
	{
		sound();
		chr=getch();
	}
	if (chr==13)
	{
		comman2(0,0,getmaxx(),getmaxy(),0);
		settextstyle(7,0,2);
		outtextxy(25,50,"Logic Circuit for Half Subtractor using Basic Gates.");
		settextstyle(1,0,5);
		outtextxy(75,125,"a");
		outtextxy(75,225,"b");
		setcolor(14);
		linedraw(100,157,180,157);
		setcolor(11);
		not(180,145);
		setcolor(14);
		linedraw(219,157,250,157);
		linedraw(250,157,250,180);
		linedraw(250,180,290,180);
		linedraw(100,257,250,257);
		linedraw(250,200,250,257);
		linedraw(250,200,290,200);
		setcolor(9);
		and(320,190);
		setcolor(14);
		linedraw(140,157,140,330);
		linedraw(140,330,290,330);
		linedraw(175,257,175,310);
		linedraw(175,310,200,310);
		setcolor(11);
		not(200,298);
		setcolor(14);
		linedraw(239,310,290,310);
		setcolor(9);
		and(320,320);
		setcolor(14);
		linedraw(335,190,390,190);
		linedraw(390,190,390,245);
		linedraw(390,245,440,245);
		linedraw(335,320,390,320);
		linedraw(390,265,390,320);
		linedraw(390,265,440,265);
		setcolor(10);
		or(365,255);
		setcolor(14);
		linedraw(487,255,540,255);
		settextstyle(1,0,5);
		setcolor(15);
		outtextxy(560,225,"D");
		setcolor(14);
		linedraw(390,190,540,190);
		setcolor(15);
		outtextxy(560,160,"B");
		settextstyle(7,0,3);
		outtextxy(40,380,"Press Enter to Continue, Press Esc to Quit");
		Flush();
		chr=getch();
		while((chr!=13)&&(chr!=27))
		{
			sound();
			chr=getch();
		}
		if (chr==13)
		{
			comman2(0,0,getmaxx(),getmaxy(),0);
			settextstyle(7,0,3);
			outtextxy(5,5,"Logic Circuit for Half Subtractor using XOR Gates.");
			setcolor(14);
			settextstyle(1,0,3);
			outtextxy(100,50,"D = a  +  b = (a + b)(  +  )");
			barb(163,50);bara(213,50);
			bara(370,50);barb(413,50);
			outtextxy(120,85,"= (a + b)(    ) = a + b");
			barab(243,85);circle(359,101,10);
			outtextxy(120,120,"B =   . b");
			bara(175,120);
			setcolor(15);
			settextstyle(1,0,5);
			outtextxy(75,125,"a");
			outtextxy(75,225,"b");
			setcolor(14);
			linedraw(100,157,250,157);
			linedraw(250,157,250,180);
			linedraw(250,180,290,180);
			linedraw(100,257,250,257);
			linedraw(250,200,250,257);
			linedraw(250,200,290,200);
			setcolor(13);
			xor(225,190);
			setcolor(14);
			linedraw(347,190,540,190);
			settextstyle(1,0,5);
			setcolor(15);
			outtextxy(560,160,"D");
			setcolor(14);
			linedraw(140,157,140,300);
			linedraw(140,300,180,300);
			setcolor(11);
			not(180,288);
			setcolor(14);
			linedraw(220,300,290,300);
			linedraw(115,257,115,320);
			linedraw(115,320,290,320);
			setcolor(9);
			and(320,310);
			setcolor(14);
			linedraw(335,310,540,310);
			settextstyle(1,0,5);
			setcolor(15);
			outtextxy(560,280,"B");
			settextstyle(7,0,3);
			outtextxy(40,400,"Press Enter to Continue, Press Esc to Quit");
			Flush();
			getch();
		}
	}
}

/*	Function of Draw thw Line	*/

void linedraw(int col1,int row1,int col2,int row2)
{
	int i=col1,j=row1;
	while ((i<=col2)&&(j<=row2))
	{
		line(col1,row1,i,j);
		if (row2==row1)
			i++;
		else
			j++;
		delay(10);
	}
}

/*	Function of A Bar	*/

void bara(int col,int row)
{
	outtextxy(col,row,"a");
	outtextxy(col-1,row-8,"-");
}

/*	Function of B Bar	*/

void barb(int col,int row)
{
	outtextxy(col,row,"b");
	outtextxy(col,row-13,"-");
}

/*	Function of C Bar	*/

void barc(int col,int row)
{
	outtextxy(col,row,"c");
	outtextxy(col,row-8,"-");
}

/*	Function of A and B Bar		*/

void barab(int col,int row)
{
	outtextxy(col,row,"ab");
	line(col,row+4,col+25,row+4);
}

void ci(int col,int row)
{
	outtextxy(col,row,"c");
	settextstyle(2,0,6);
	outtextxy(col+12,row+11,"i");
	settextstyle(1,0,3);
}

void co(int col,int row)
{
	outtextxy(col,row,"C");
	settextstyle(2,0,6);
	outtextxy(col+12,row+11,"o");
	settextstyle(1,0,3);
}

void barci(int col,int row)
{
	outtextxy(col,row,"");
	settextstyle(2,0,6);
	outtextxy(col+12,row+11,"i");
	settextstyle(1,0,3);
	outtextxy(col,row-13,"-");
}

/*	Function of Binary Adder-Subtractor Circuit	*/

void addsubcircuit(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(125,25,"A 4-bit adder-subtractor circuit");
	settextstyle(1,0,2);
	for (int i=100;i<=500;i+=125)
		outtextxy(i,75,"A");
	for (i=50;i<=500;i+=125)
		outtextxy(i,75,"B");
	outtextxy(550,95,"T");
	settextstyle(2,0,4);
	outtextxy(114,87,"3");outtextxy(239,87,"2");outtextxy(364,87,"1");outtextxy(489,87,"0");
	outtextxy(64,87,"3");outtextxy(189,87,"2");outtextxy(314,87,"1");outtextxy(439,87,"0");
	setcolor(14);
	linedraw(75,125,580,125);
	linedraw(450,125,450,159);
	linedraw(430,100,430,159);
	setcolor(13);
	xor1(440,160);
	setcolor(14);
	linedraw(480,100,480,250);
	linedraw(440,211,440,250);
	setcolor(3);
	rectangle(420,250,500,275);
	settextstyle(1,0,2);
	setcolor(15);
	outtextxy(445,250,"FA");
	setcolor(14);
	linedraw(555,125,555,260);
	linedraw(501,260,555,260);
	linedraw(460,276,460,325);
	settextstyle(1,0,4);
	setcolor(15);
	outtextxy(455,325,"S");
	settextstyle(2,0,5);
	outtextxy(475,345,"0");
	setcolor(14);
	linedraw(305,100,305,159);
	linedraw(325,125,325,159);
	setcolor(13);
	xor1(315,160);
	setcolor(14);
	linedraw(355,100,355,250);
	linedraw(315,211,315,250);
	setcolor(3);
	rectangle(285,250,375,275);
	settextstyle(1,0,2);
	setcolor(15);
	outtextxy(320,250,"FA");
	setcolor(14);
	linedraw(376,260,419,260);
	linedraw(335,276,335,325);
	settextstyle(1,0,4);
	setcolor(15);
	outtextxy(330,325,"S");
	settextstyle(2,0,5);
	outtextxy(350,345,"1");
	setcolor(14);
	linedraw(180,100,180,159);
	linedraw(200,125,200,159);
	setcolor(13);
	xor1(190,160);
	setcolor(14);
	linedraw(230,100,230,250);
	linedraw(190,211,190,250);
	setcolor(3);
	rectangle(160,250,250,275);
	settextstyle(1,0,2);
	setcolor(15);
	outtextxy(195,250,"FA");
	setcolor(14);
	linedraw(251,260,284,260);
	linedraw(210,276,210,325);
	settextstyle(1,0,4);
	setcolor(15);
	outtextxy(205,325,"S");
	settextstyle(2,0,5);
	outtextxy(225,345,"2");
	setcolor(14);
	linedraw(55,100,55,159);
	linedraw(75,125,75,159);
	setcolor(13);
	xor1(65,160);
	setcolor(14);
	linedraw(105,100,105,250);
	linedraw(65,211,65,250);
	setcolor(3);
	rectangle(45,250,125,275);
	settextstyle(1,0,2);
	setcolor(15);
	outtextxy(70,250,"FA");
	setcolor(14);
	linedraw(126,260,159,260);
	linedraw(85,276,85,325);
	settextstyle(1,0,4);
	setcolor(15);
	outtextxy(80,325,"S");
	settextstyle(2,0,5);
	outtextxy(100,345,"3");
	settextstyle(7,0,3);
	outtextxy(40,390,"Press Enter to Continue, Press Esc to Quit");
	Flush();
	getch();
}

/*	Function of 2-bit multiplier	*/

void twobit(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(150,10,"Multiply 2-bit Numbers");
	settextstyle(1,0,2);
	outtextxy(20,60,"A");outtextxy(20,100,"B");
	amul(100,60,1);amul(130,60,0);
	bmul(100,100,1);bmul(130,100,0);
	setcolor(14);
	line(40,75,90,75);
	line(40,115,90,115);
	line(270,180,450,180);
	line(130,245,450,245);
	outtextxy(410,215,"X");
	setcolor(9);
	outtextxy(500,125,"Multiplicand");
	outtextxy(500,150,"Multiplier");
	outtextxy(500,250,"Product");
	outtextxy(50,250,"Carry = ");
	setcolor(15);
	bmul(300,125,1);bmul(400,125,0);
	amul(300,150,1);amul(400,150,0);
	amul(390,185,0);bmul(420,185,0);
	amul(290,185,0);bmul(320,185,1);
	amul(290,215,1);bmul(320,215,0);
	amul(190,215,1);bmul(220,215,1);
	pmul(140,250,3);pmul(210,250,2);
	pmul(310,250,1);pmul(410,250,0);
	settextstyle(7,0,3);
	outtextxy(230,370,"Hit a Key !!!!!");
	Flush();
	getch();
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(100,10,"Logic circuit for a 2-bit Multiplier");
	settextstyle(1,0,2);
	amul(450,100,0);bmul(480,100,0);
	setcolor(14);
	linedraw(485,125,485,175);
	linedraw(455,125,455,175);
	setcolor(9);
	and1(470,200);
	setcolor(14);
	linedraw(470,219,470,380);
	setcolor(15);
	pmul(465,380,0);
	amul(350,100,0);bmul(380,100,1);
	setcolor(14);
	linedraw(385,125,385,175);
	linedraw(355,125,355,175);
	setcolor(9);
	and1(370,200);
	setcolor(14);
	linedraw(370,219,370,240);
	linedraw(330,240,370,240);
	linedraw(330,240,330,280);
	setcolor(15);
	amul(250,100,1);bmul(280,100,0);
	setcolor(14);
	linedraw(285,125,285,175);
	linedraw(255,125,255,175);
	setcolor(9);
	and1(270,200);
	setcolor(14);
	linedraw(270,219,270,240);
	linedraw(270,240,300,240);
	linedraw(300,240,300,280);
	setcolor(3);
	rectangle(280,281,350,310);
	setcolor(14);
	linedraw(330,311,330,380);
	setcolor(15);
	outtextxy(304,283,"HA");
	pmul(325,380,1);
	setcolor(14);
	linedraw(300,311,300,340);
	linedraw(250,340,300,340);
	linedraw(250,260,250,340);
	linedraw(200,260,250,260);
	linedraw(200,260,200,280);
	setcolor(15);
	amul(150,100,1);bmul(180,100,1);
	setcolor(14);
	linedraw(185,125,185,175);
	linedraw(155,125,155,175);
	setcolor(9);
	and1(170,200);
	setcolor(14);
	linedraw(170,219,170,280);
	setcolor(3);
	rectangle(150,281,220,310);
	setcolor(14);
	linedraw(200,311,200,380);
	linedraw(170,311,170,380);
	setcolor(15);
	outtextxy(174,283,"HA");
	pmul(195,380,2);
	pmul(165,380,3);
	outtextxy(80,380,"Carry =");
	settextstyle(7,0,3);
	outtextxy(230,420,"Hit a Key !!!!!");
	Flush();
	getch();
}

/*	Function of 3-bit multiplier	*/

void threebit(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(150,10,"Multiply 3-bit Numbers");
	settextstyle(1,0,2);
	outtextxy(20,60,"A");outtextxy(20,100,"B");
	amul(100,60,2);amul(130,60,1);amul(160,60,0);
	bmul(100,100,2);bmul(130,100,1);bmul(160,100,0);
	setcolor(14);
	line(40,75,90,75);
	line(40,115,90,115);
	line(280,180,475,180);
	line(50,275,475,275);
	outtextxy(460,215,"X");
	outtextxy(460,245,"X");
	outtextxy(385,245,"X");
	setcolor(9);
	outtextxy(500,125,"Multiplicand");
	outtextxy(500,150,"Multiplier");
	outtextxy(500,280,"Product");
	outtextxy(1,280,"Carry = ");
	setcolor(15);
	bmul(300,125,2);bmul(375,125,1);bmul(450,125,0);
	amul(300,150,2);amul(375,150,1);amul(450,150,0);

	amul(440,185,0);bmul(470,185,0);
	amul(365,185,1);bmul(395,185,0);
	amul(290,185,2);bmul(320,185,0);

	amul(365,215,0);bmul(395,215,1);
	amul(290,215,1);bmul(320,215,1);
	amul(215,215,2);bmul(245,215,1);

	amul(290,245,0);bmul(320,245,2);
	amul(215,245,1);bmul(245,245,2);
	amul(140,245,2);bmul(170,245,2);

	pmul(85,280,5);pmul(160,280,4);
	pmul(235,280,3);pmul(310,280,2);
	pmul(385,280,1);pmul(460,280,0);
	settextstyle(7,0,3);
	outtextxy(230,370,"Hit a Key !!!!!");
	Flush();
	getch();
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(100,10,"Logic circuit for a 3-bit Multiplier");
	settextstyle(1,0,2);
	amul(555,70,0);bmul(580,70,0);
	setcolor(14);
	linedraw(585,95,585,145);
	linedraw(560,95,560,145);
	setcolor(9);
	and1(572,170);
	setcolor(14);
	linedraw(572,189,572,380);
	setcolor(15);
	pmul(567,380,0);

	amul(495,70,1);bmul(520,70,0);
	setcolor(14);
	linedraw(525,95,525,145);
	linedraw(500,95,500,145);
	setcolor(9);
	and1(513,170);
	setcolor(14);
	linedraw(513,189,513,230);
	setcolor(15);
	amul(435,70,0);bmul(460,70,1);
	setcolor(14);
	linedraw(465,95,465,145);
	linedraw(440,95,440,145);
	setcolor(9);
	and1(453,170);
	setcolor(14);
	linedraw(453,189,453,220);
	linedraw(453,220,482,220);
	linedraw(482,220,482,230);
	setcolor(3);
	rectangle(462,231,532,260);
	setcolor(14);
	linedraw(513,261,513,380);
	setcolor(15);
	outtextxy(485,233,"HA");
	pmul(508,380,1);

	amul(375,70,2);bmul(400,70,0);
	setcolor(14);
	linedraw(405,95,405,145);
	linedraw(380,95,380,145);
	setcolor(9);
	and1(393,170);
	setcolor(14);
	linedraw(393,189,393,230);
	setcolor(15);
	amul(315,70,1);bmul(340,70,1);
	setcolor(14);
	linedraw(345,95,345,145);
	linedraw(320,95,320,145);
	setcolor(9);
	and1(333,170);
	setcolor(14);
	linedraw(333,189,333,220);
	linedraw(333,220,363,220);
	linedraw(363,220,363,230);
	setcolor(3);
	rectangle(343,231,413,260);
	setcolor(14);
	linedraw(393,261,393,300);
	setcolor(15);
	outtextxy(366,233,"HA");

	setcolor(15);
	amul(255,70,0);bmul(280,70,2);
	setcolor(14);
	linedraw(285,95,285,145);
	linedraw(260,95,260,145);
	setcolor(9);
	and1(273,170);
	setcolor(14);
	linedraw(273,189,273,290);
	linedraw(273,290,363,290);
	linedraw(363,290,363,300);
	linedraw(483,261,483,315);
	linedraw(414,315,483,315);
	setcolor(3);
	rectangle(343,301,413,330);
	setcolor(14);
	linedraw(393,331,393,380);
	setcolor(15);
	outtextxy(366,303,"FA");
	pmul(388,380,2);

	setcolor(15);
	amul(195,70,2);bmul(220,70,1);
	setcolor(14);
	linedraw(225,95,225,145);
	linedraw(200,95,200,145);
	setcolor(9);
	and1(213,170);
	setcolor(14);
	linedraw(213,189,213,230);
	setcolor(15);
	amul(135,70,1);bmul(160,70,2);
	setcolor(14);
	linedraw(165,95,165,145);
	linedraw(140,95,140,145);
	setcolor(9);
	and1(153,170);
	setcolor(14);
	linedraw(153,189,153,220);
	linedraw(153,220,183,220);
	linedraw(183,220,183,230);
	linedraw(363,261,363,271);
	linedraw(260,271,363,271);
	linedraw(260,245,260,271);
	linedraw(234,245,260,245);
	setcolor(3);
	rectangle(163,231,233,260);
	setcolor(14);
	linedraw(213,261,213,300);
	setcolor(15);
	outtextxy(186,233,"FA");
	setcolor(14);
	linedraw(363,331,363,350);
	linedraw(270,350,363,350);
	linedraw(270,315,270,350);
	linedraw(244,315,270,315);
	setcolor(3);
	rectangle(183,301,243,330);
	setcolor(14);
	linedraw(223,331,223,380);
	setcolor(15);
	outtextxy(200,303,"HA");
	pmul(218,380,3);
	amul(75,70,2);bmul(100,70,2);
	setcolor(14);
	linedraw(105,95,105,145);
	linedraw(80,95,80,145);
	setcolor(9);
	and1(93,170);
	setcolor(14);
	linedraw(93,189,93,300);
	linedraw(183,261,183,280);
	linedraw(123,280,183,280);
	linedraw(123,280,123,300);
	linedraw(203,331,203,350);
	linedraw(160,350,203,350);
	linedraw(160,315,160,350);
	linedraw(144,315,160,315);
	setcolor(3);
	rectangle(73,301,143,330);
	setcolor(14);
	linedraw(108,331,108,380);
	setcolor(15);
	outtextxy(95,303,"FA");
	pmul(103,380,4);
	setcolor(14);
	linedraw(50,315,72,315);
	setcolor(15);
	outtextxy(5,275,"Carry");
	pmul(25,300,5);
	settextstyle(7,0,3);
	outtextxy(230,420,"Hit a Key !!!!!");
	Flush();
	getch();
}

void amul(int col,int row,int x)
{
	char temp[3];
	itoa(x, temp, 10);
	temp[1]='\0';
	outtextxy(col,row,"A");
	settextstyle(2,0,4);
	outtextxy(col+14,row+12,temp);
	settextstyle(1,0,2);
}

void bmul(int col,int row,int x)
{
	char temp[3];
	itoa(x, temp, 10);
	temp[1]='\0';
	outtextxy(col,row,"B");
	settextstyle(2,0,4);
	outtextxy(col+14,row+12,temp);
	settextstyle(1,0,2);
}

void pmul(int col,int row,int x)
{
	char temp[3];
	itoa(x, temp, 10);
	temp[1]='\0';
	outtextxy(col,row,"P");
	settextstyle(2,0,4);
	outtextxy(col+14,row+12,temp);
	settextstyle(1,0,2);
}

/*	Function of BCD Encoder Circuit		  */

void bcdencoder(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(180,5,"Logic of BCD Encoder");
	settextstyle(2,0,6);
	outtextxy(25,50,"9(1001)");
	outtextxy(25,75,"8(1000)");
	outtextxy(25,100,"7(0111)");
	outtextxy(25,125,"6(0110)");
	outtextxy(25,150,"5(0101)");
	outtextxy(25,175,"4(0100)");
	outtextxy(25,200,"3(0011)");
	outtextxy(25,225,"2(0010)");
	outtextxy(25,250,"1(0001)");
	outtextxy(25,275,"0(0000)");
	setcolor(10);
	orencoder(550,300);
	orencoder(430,300);
	orencoder(310,300);
	orencoder(190,300);
	setcolor(14);
	linedraw(90,60,580,60);
	linedraw(580,60,580,300);
	setcolor(15);
	outtextxy(577,300,"9");
	setcolor(14);
	linedraw(210,60,210,300);
	setcolor(15);
	outtextxy(207,300,"9");
	setcolor(14);
	linedraw(90,85,170,85);
	linedraw(170,85,170,300);
	setcolor(15);
	outtextxy(167,300,"8");
	setcolor(14);
	linedraw(90,110,565,110);
	linedraw(565,110,565,300);
	setcolor(15);
	outtextxy(562,300,"7");
	setcolor(14);
	linedraw(465,110,465,300);
	setcolor(15);
	outtextxy(462,300,"7");
	setcolor(14);
	linedraw(345,110,345,300);
	setcolor(15);
	outtextxy(342,300,"7");
	setcolor(14);
	linedraw(90,135,445,135);
	linedraw(445,135,445,300);
	setcolor(15);
	outtextxy(442,300,"6");
	setcolor(14);
	linedraw(325,135,325,300);
	setcolor(15);
	outtextxy(322,300,"6");
	setcolor(14);
	linedraw(90,160,550,160);
	linedraw(550,160,550,300);
	setcolor(15);
	outtextxy(547,300,"5");
	setcolor(14);
	linedraw(305,160,305,300);
	setcolor(15);
	outtextxy(302,300,"5");
	setcolor(14);
	linedraw(90,185,285,185);
	linedraw(285,185,285,300);
	setcolor(15);
	outtextxy(282,300,"4");
	setcolor(14);
	linedraw(90,210,535,210);
	linedraw(535,210,535,300);
	setcolor(15);
	outtextxy(532,300,"3");
	setcolor(14);
	linedraw(425,210,425,300);
	setcolor(15);
	outtextxy(422,300,"3");
	setcolor(14);
	linedraw(90,235,405,235);
	linedraw(405,235,405,300);
	setcolor(15);
	outtextxy(402,300,"2");
	setcolor(14);
	linedraw(90,260,520,260);
	linedraw(520,260,520,300);
	setcolor(15);
	outtextxy(517,300,"1");

	setcolor(14);
	linedraw(550,381,550,400);
	linedraw(430,381,430,400);
	linedraw(310,381,310,400);
	linedraw(190,381,190,400);
	setcolor(15);
	outtextxy(547,400,"1");
	outtextxy(427,400,"2");
	outtextxy(307,400,"4");
	outtextxy(187,400,"8");
	settextstyle(1,0,2);
	bmul(545,420,0);bmul(425,420,1);bmul(305,420,2);bmul(185,420,3);
	settextstyle(7,0,3);
	outtextxy(230,450,"Hit a Key !!!!!");
	Flush();
	getch();
}

/*	Function of OR Gate Encoder	*/

void orencoder(int x,int y)
{
	ellipse(x, y, 180, 360,50, 25);
	ellipse(x, y, 180, 360,50, 80);
}

/*	Function of Decoder Circuit		*/

void decodercircuit(void)
{
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(180,5,"Logic Circuit of Decoder");
	settextstyle(2,0,6);
	outtextxy(5,75,"8(1000)");
	outtextxy(5,125,"4(0100)");
	outtextxy(5,175,"2(0010)");
	outtextxy(5,225,"1(0001)");
	setcolor(9);
	for (int i=600;i>=120;i-=60)
		and1(i,300);
	setcolor(14);
	linedraw(75,85,610,85);
	linedraw(610,85,610,274);
	linedraw(540,85,540,274);

	linedraw(75,135,495,135);
	linedraw(495,135,495,274);
	linedraw(430,135,430,274);
	linedraw(370,135,370,274);
	linedraw(300,135,300,274);

	linedraw(75,185,480,185);
	linedraw(480,185,480,274);
	linedraw(410,185,410,274);
	linedraw(250,185,250,274);
	linedraw(180,185,180,274);

	linedraw(75,235,590,235);
	linedraw(590,235,590,274);
	linedraw(465,235,465,274);
	linedraw(350,235,350,274);
	linedraw(230,235,230,274);
	linedraw(120,235,120,274);
	char temp[2];int number;
	number=9;temp[1]='\0';
	settextstyle(1,0,2);
	for (i=600;i>=120;i-=60)
	{
		itoa(number,temp,10);
		setcolor(14);
		linedraw(i,319,i,360);
		setcolor(15);
		outtextxy(i-5,360,temp);
		number--;
	}
	settextstyle(7,0,3);
	outtextxy(230,420,"Hit a Key !!!!!");
	Flush();
	getch();
}
