#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
int button;
#include "g:\cld\basic.h"
#include "g:\cld\mouse.h"
#include "g:\cld\arith.h"

void parity(void);

void commulti(void);
void multiplexer(void);
void demultiplexer(void);
void multianddemulti(void);

int combitional(void);
void combinationalcir(void);
int nextcom(void);
int seacom(int x,int y);
void codedefinition(void);

int colcom=130,rowcom[6]={125,175,225,275,325,375};

//void main(void)
//{
void main(int argu)
{
//	if (argu != 4)
  //	{
//		printf("This Program Run only in Main File CLD.EXE");
  //		exit(1);
    //	}
	int ch40=0,ch41;
	int gdriver=DETECT,gmode;
 //	registerbgidriver(EGAVGA_driver);
	initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
//	initgraph(&gdriver,&gmode,"d:\\tc\\bgi");

	while (ch40 != 1)
	{
		ch41=combitional();
		if ( ch41==0)
		{
			cursoroff();
			combinationalcir();
		}
		if ( ch41==1)
		{
			cursoroff();
			arith();
		}
		if ( ch41==2)
		{
			cursoroff();
			codedefinition();
		}
		if ( ch41==3)
		{
			cursoroff();
			parity();
		}
		if ( ch41==4)
		{
			cursoroff();
			commulti();
		}
		if ( ch41==5)
		{
			ch40=1;
			closegraph();
		}
	}
}

int combitional(void)
{
	int io=0,chio;
	setfillstyle(SOLID_FILL,3);
	bar(0,0,getmaxx(),getmaxy());
	comman(20,10,615,75,7);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(37,4,"Combinational Circuit");
	outtextxy(38,5,"Combinational Circuit");
	setcolor(14);
	outtextxy(36,2,"Combinational Circuit");
	outtextxy(35,2,"Combinational Circuit");

	setcolor(15);
	comman1(100,90,540,440,3);
	comman1(110,100,530,430,1);

	for (int i=0;i<6;i++)
		comman(colcom,rowcom[i],colcom+385,rowcom[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colcom+65,rowcom[0],"Combinational Circuit");
	outtextxy(colcom+5,rowcom[1],"Arithmetic and Logic Operations");
	outtextxy(colcom+100,rowcom[2],"Code Converters");
	outtextxy(colcom+9,rowcom[3],"Parity Generators and Checkers");
	outtextxy(colcom+5,rowcom[4],"Multiplexers and Demultiplexers");
	outtextxy(colcom+150,rowcom[5],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again=8;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chio=(seacom(x,y)))
			{
				case 0:
					press1(colcom,rowcom[0],colcom+385,rowcom[0]+35);
					again=0;
				break;
				case 1:
					press1(colcom,rowcom[1],colcom+385,rowcom[1]+35);
					again=1;
				break;
				case 2:
					press1(colcom,rowcom[2],colcom+385,rowcom[2]+35);
					again=2;
				break;
				case 3:
					press1(colcom,rowcom[3],colcom+385,rowcom[3]+35);
					again=3;
				break;
				case 4:
					press1(colcom,rowcom[4],colcom+385,rowcom[4]+35);
					again=4;
				break;
				case 5:
					press1(colcom,rowcom[5],colcom+385,rowcom[5]+35);
					again=5;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colcom,rowcom[again],colcom+385,rowcom[again]+35);
			if (x >= colcom && x <= colcom+385 && y >= rowcom[again] && y <= rowcom[again]+35)
			{
				cursoroff();
				sound();
				io=1;
			}
		}
	}
	return(chio);
}

int seacom(int x,int y)
{
	for (int i = 0;i < 6;i++)
	if (x >= colcom && x <= colcom+385 && y >= rowcom[i] && y <= rowcom[i]+35)
		return(i);
	return(-1);
}

void combinationalcir(void)
{
	int controlcom1,controlcom=1;
	while (controlcom)
	{
		controlcom1=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,6);
		setcolor(0);
		outtextxy(30,4,"Combinational Circuit");
		settextstyle(2,0,5);
		outtextxy(50,100,"A Combinational (also called combinatorial) circuit consists of logic gates");
		outtextxy(20,120,"whose outputs at any time are determined directly from the present inputs ");
		outtextxy(20,140,"without regard to the previous inputs.");
		setcolor(9);
		outtextxy(80,170,"A block diagram of a Combinational Circuit is shown below :");
//	  Draw the diagram of a combinational circuit
		setcolor(0);
		line(150,230,225,230);
		line(150,240,225,240);
		line(150,250,225,250);
		line(150,300,225,300);
		rectangle(225,220,375,310);
		for (int i=250;i<285;i+=10)
		{
			outtextxy(185,i,".");
			outtextxy(410,i,".");
		}
		line(375,230,450,230);
		line(375,240,450,240);
		line(375,250,450,250);
		line(375,300,450,300);
		outtextxy(50,260,"n - inputs");
		outtextxy(480,260,"m - outputs");
		setcolor(9);
		outtextxy(250,240,"Combinational");
		outtextxy(250,260,"Logic Circuit");
		settextstyle(1,0,2);
		comman(100,400,200,435,7);
		outtextxy(110,405,"NEXT >>");
		comman(400,400,500,435,7);
		outtextxy(415,405,"Q U I T");
		setcursorpos(x,y);
		cursoron();
		int flag=0,again;
		while (!controlcom1)
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
						controlcom1=1;
						controlcom=nextcom();
					}
				}
				else
				{
					press2(400,400,500,435);
					if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
					{
						sound();
						controlcom1=1;
						controlcom=0;
						cursoroff();
					}
				}
			}
		}
	}
}

int nextcom(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	setcolor(9);
	settextstyle(1,0,3);
	outtextxy(110,100,"Type of Combinational Circuits");
	settextstyle(2,0,5);
	setcolor(0);
	outtextxy(50,150,"In computer system, many type of combinational circuits are used. Some of");
	outtextxy(20,170,"them are discussed under the following headings :");
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(70,200,"a )");
	outtextxy(70,240,"b )");
	outtextxy(70,280,"c )");
	outtextxy(70,320,"d )");
	setcolor(0);
	outtextxy(120,200,"Arithmetic and Logic Operations");
	outtextxy(120,240,"Code Converters");
	outtextxy(120,280,"Parity Generators and Checkers");
	outtextxy(120,320,"Multiplexers and Demultiplexers");
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
					return(1);
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
					return(0);
				}
			}
		}
	}
}


void codedefinition(void)
{
	int mainlba=0,fullsub;
	while (!mainlba)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,6);
		setcolor(0);
		outtextxy(100,4,"Code Convertors");
		settextstyle(2,0,5);
		outtextxy(70,110,"A code convertor is a combinational circuit whose inputs and outputs");
		outtextxy(30,130,"are binary numbers representing the same information in different codes.");
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(90,190,"There are two types of such convertors :");
		setcolor(0);
		outtextxy(150,240,"1)           Encoders");
		outtextxy(150,280,"2)           Decoders");
		setcursorpos(x,y);
		cursoron();
		fullsub=addersubtractor();
		if (fullsub==1)
		{
			cursoroff();
			codeconvertor();
		}
		if (fullsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

/*	Function of Parity Generators and Checkers	*/

void parity(void)
{
	char get[9];get[8]='\0';
	int flag=0;
	int btod=1,check;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(80,3,"Parity Generator");
		comman(65,100,575,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(130,120,"Enter the Code Word : ");
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=7)&&(ch!=8))
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
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(380,115,550,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		check=1;
		comman2(cursor,115,550,145,9);
		if (strlen(get)!=7)
		{
			check=0;
			btod=1;
			desion2();
			settextstyle(8,0,4);
			outtextxy(123,135,"<ERROR>");
			settextstyle(2,0,5);
			outtextxy(220,200,"The Current Code use only 7 Bits");
			outtextxy(240,220,"You are Worng enter the Code");
			outtextxy(310,240,"Try Again");
			comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
			setcolor(0);
			settextstyle(1,0,4);
			outtextxy(getmaxx()/2-20,265,"Ok");
			i = 0;
			setcursorpos(x,y);
			cursoron();
			while (!i)
			{
				button=getcursorpos(&x,&y);
				if (button)
				{
					flag=1;
					if (x >= getmaxx()/2-50 && y >= 270 && x <= getmaxx()/2+50 && y <= 300)
						press1(getmaxx()/2-50,270,getmaxx()/2+50,300);
				}
				if ((!button)&&(flag))
				{
					flag=0;
					press2(getmaxx()/2-50,270,getmaxx()/2+50,300);
					if (x >= getmaxx()/2-50 && y >= 270 && x <= getmaxx()/2+50 && y <= 300)
					{
						sound();
						i=strlen(get);
						cursoroff();
					}
				}
			}
		}
		if (check)
		for (i=0;i<strlen(get);i++)
		if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"The Code use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Code");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(x,y);
				cursoron();
				while (!i)
				{
					button=getcursorpos(&x,&y);
					if (button)
					{
						flag=1;
						if (x >= getmaxx()/2-50 && y >= 270 && x <= getmaxx()/2+50 && y <= 300)
							press1(getmaxx()/2-50,270,getmaxx()/2+50,300);
					}
					if ((!button)&&(flag))
					{
						flag=0;
						press2(getmaxx()/2-50,270,getmaxx()/2+50,300);
						if (x >= getmaxx()/2-50 && y >= 270 && x <= getmaxx()/2+50 && y <= 300)
						{
							sound();
							i=strlen(get);
							cursoroff();
						}
					}
				}
			}
	}
	delay(1000);
	get[7]='p';
	outtextxy(160,190,"Parity Number is ");
	outtextxy(350,190,get);
	check=0;
	delay(1000);
	for (int i=0;i<strlen(get);i++)
		if (get[i] == '1')
			check++;
	setcolor(0);
	if (check%2==0)
	{
		outtextxy(220,240,"Parity bit is 0");
		get[7]='0';
	}
	else
	{
		outtextxy(220,240,"Parity bit is 1");
		get[7]='1';
	}
	delay(1000);
	outtextxy(130,270,"The complete Code is");
	outtextxy(350,270,get);
	delay(1000);
	outtextxy(230,300,"Please Wait.......");
	delay(4000);
	comman2(0,0,getmaxx(),getmaxy(),0);
	setcolor(15);
	settextstyle(7,0,3);
	outtextxy(175,200,"Now Check the Parity");
	delay(3000);
	comman2(0,0,getmaxx(),getmaxy(),0);
	settextstyle(7,0,5);
	outtextxy(125,5,"Parity Checker");
	int row=75,number[7];char temp[2];temp[1]='\0';
	settextstyle(1,0,2);
	for (i=0;i<=7;i++)
	{
		setcolor(15);
		amul(25,row,i);
		temp[0]=get[i];
		number[i]=atoi(temp);
		outtextxy(75,row,temp);
		setcolor(14);
		linedraw(88,row+13,150,row+13);
		if (i==1||i==3||i==5)
		{
			setcolor(13);
			xor(86,row);
			setcolor(14);
			line(207,row,230,row);
			if (i==1||i==5)
			{
				line(230,row,230,row+27);
				line(230,row+27,270,row+27);
			}
			else
			{
				line(230,row-27,230,row);
				line(230,row-27,270,row-27);
			}
			row+=50;
		}
		else
			row+=25;
	}
	setcolor(13);
	xor(86,row-25);
	setcolor(14);
	line(207,row-25,230,row-25);
	line(230,row-52,230,row-25);
	line(230,row-52,270,row-52);
	setcolor(15);
	if (number[0]==number[1])
	{
		outtextxy(210,70,"0");
		number[0]=0;
	}
	else
	{
		outtextxy(210,70,"1");
		number[0]=1;
	}
	if (number[2]==number[3])
	{
		outtextxy(210,144,"0");
		number[1]=0;
	}
	else
	{
		outtextxy(210,144,"1");
		number[1]=1;
	}
	if (number[4]==number[5])
	{
		outtextxy(210,218,"0");
		number[2]=0;
	}
	else
	{
		outtextxy(210,218,"1");
		number[2]=1;
	}
	if (number[6]==number[7])
	{
		outtextxy(210,292,"0");
		number[3]=0;
	}
	else
	{
		outtextxy(210,292,"1");
		number[3]=1;
	}
	setcolor(13);
	xor(205,140);
	xor(205,290);
	setcolor(15);
	if (number[0]==number[1])
	{
		outtextxy(330,115,"0");
		number[0]=0;
	}
	else
	{
		outtextxy(330,115,"1");
		number[0]=1;
	}
	if (number[2]==number[3])
	{
		outtextxy(330,295,"0");
		number[1]=0;
	}
	else
	{
		outtextxy(330,295,"1");
		number[1]=1;
	}
	setcolor(14);
	linedraw(326,140,350,140);
	linedraw(326,290,350,290);
	linedraw(350,140,350,205);
	linedraw(350,225,350,290);
	linedraw(350,205,390,205);
	linedraw(350,225,390,225);
	setcolor(13);
	xor(325,215);
	setcolor(14);
	linedraw(446,215,490,215);
	setcolor(15);
	if (number[0]==number[1])
	{
		outtextxy(495,200,"0");
		temp[0]='0';
	}
	else
	{
		outtextxy(495,200,"1");
		temp[0]='1';
	}
	temp[0]=get[7];
	settextstyle(1,0,3);
	outtextxy(40,370,"<<<<< Our Parity bit   is correct >>>>>");
	outtextxy(300,370,temp);
	settextstyle(7,0,3);
	outtextxy(230,420,"Hit a Key !!!!!");
	Flush();
	getch();
}

/*	Functions of Multiplexer and Demultiplexer	*/

void commulti(void)
{
	int mainlba=0,fullsub;
	while (!mainlba)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,4);
		setcolor(0);
		outtextxy(50,15,"Multiplexers and Demultiplexers");
		settextstyle(2,0,5);
		outtextxy(70,110,"Some combinational circuits are used for transferring of data between");
		outtextxy(20,130,"parts of a system.Transferring of data refers to moving or copying operations");
		outtextxy(20,150,"in which no changes are made to the data's logic value,i.e.,no data processing");
		outtextxy(20,170,"takes place. In order to achieve the above objective.");
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(120,200,"We use the following two circuit :");
		setcolor(0);
		outtextxy(150,240,"1)           Multiplexers");
		outtextxy(150,280,"2)           Demultiplexers");
		setcursorpos(x,y);
		cursoron();
		fullsub=addersubtractor();
		if (fullsub==1)
		{
			cursoroff();
			multianddemulti();
		}
		if (fullsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}
void multianddemulti(void)
{
	controlbasic=0;
	while (!controlbasic)
	{
		desioncom();
		setcolor(0);
		settextstyle(1,0,4);
		outtextxy(62,19,"Multiplexer and Demultiplexer");
		outtextxy(63,20,"Multiplexer and Demultiplexer");
		setcolor(14);
		outtextxy(61,17,"Multiplexer and Demultiplexer");
		outtextxy(60,17,"Multiplexer and Demultiplexer");
		setcolor(0);
		settextstyle(1,0,3);
		outtextxy(colbasic+25,rowbasic[0],"Multiplexer");
		outtextxy(colbasic+10,rowbasic[1],"Demultiplexer");
		outtextxy(colbasic+55,rowbasic[2],"Q u i t");
		checkbasic=checkpos();
		if (checkbasic==0)
			multiplexer();
		if (checkbasic==1)
			demultiplexer();
		if (checkbasic==2)
			controlbasic=1;
	}
}

/*	Function of Multiplexer		*/

void multiplexer(void)
{
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,15);
	settextstyle(1,0,6);
	setcolor(0);
	outtextxy(160,4,"Multiplexer");
	settextstyle(2,0,5);
	outtextxy(60,90,"Multiplexing is the technique of putting multiple signals on the same data");
	outtextxy(30,110,"path. A multiplexer is combinational circuit that select binary information");
	outtextxy(30,130,"from one of many input sources and transmits it to a signal output line.");
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(90,160,"The general diagram of a multiplexer");
	outtextxy(280,250,"MUX");
	outtextxy(265,280,"2-to-1");
	outtextxy(100,215,"D");
	outtextxy(100,235,"D");
	outtextxy(100,255,"D");
	outtextxy(100,315,"D");
	settextstyle(2,0,5);
	outtextxy(277,275,"n");
	outtextxy(115,225,"0");
	outtextxy(115,245,"1");
	outtextxy(115,265,"2");
	outtextxy(115,325,"n-1");
	setcolor(0);
	line(150,230,225,230);
	line(150,250,225,250);
	line(150,270,225,270);
	line(150,330,225,330);
	rectangle(225,220,375,350);
	for (int i=275;i<=305;i+=10)
		outtextxy(185,i,".");
	line(375,285,450,285);
	line(245,350,245,400);
	line(265,350,265,400);
	line(285,350,285,400);
	line(355,350,355,400);
	for (i=300;i<=340;i+=10)
		outtextxy(i,365,".");
	outtextxy(50,275,"Inputs");
	outtextxy(25,285,"(Data Lines)");
	outtextxy(490,275,"Output");
	outtextxy(250,405,"n-control lines");
	settextstyle(1,0,2);
	comman(400,400,500,435,7);
	outtextxy(415,405,"Q U I T");
	setcursorpos(x,y);
	cursoron();
	int iop=0,flag=0;
	while (iop != 1)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
			{
				press1(400,400,500,435);
			}
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(400,400,500,435);
			delay(150);
			if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
			{
				sound();
				iop=1;
				cursoroff();
			}
		}
	}
}

/*	Function of Demultiplexer		*/

void demultiplexer(void)
{
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,15);
	settextstyle(1,0,6);
	setcolor(0);
	outtextxy(155,4,"demultiplexer");
	settextstyle(2,0,5);
	outtextxy(60,80,"A Demultiplexer is a digital function that performs the inverse operation");
	outtextxy(30,100,"of a MUX. It is also called a decoder. It take a single input and distributes");
	outtextxy(30,120,"it to one of 2  possible output line. Which is determined by a choice of");
	outtextxy(30,140,"signals on address lines.");
	setcolor(9);
	settextstyle(1,0,2);
	outtextxy(90,160,"The general diagram of a Demultiplexer");
	outtextxy(280,220,"MUX");
	outtextxy(460,235,"D");
	outtextxy(460,255,"D");
	outtextxy(460,275,"D");
	outtextxy(460,295,"D");
	settextstyle(2,0,5);
	outtextxy(475,245,"0");
	outtextxy(475,265,"1");
	outtextxy(475,285,"2");
	outtextxy(475,305,"n-1");
	setcolor(0);
	line(375,250,450,250);
	line(375,270,450,270);
	line(375,290,450,290);
	line(375,310,450,310);
	rectangle(225,220,375,350);
	line(150,285,225,285);
	line(240,268,240,305);
	outtextxy(230,265,"0");
	outtextxy(230,290,"1");
	line(280,350,280,400);
	line(275,335,325,335);
	line(320,350,320,400);
	outtextxy(295,320,"S");
	outtextxy(278,335,"1");
	outtextxy(318,335,"0");
	outtextxy(60,275,"Input Line");
	outtextxy(490,275,"Outputs");
	settextstyle(1,0,2);
	comman(400,400,500,435,7);
	outtextxy(415,405,"Q U I T");
	setcursorpos(x,y);
	cursoron();
	int iop=0,flag=0;
	while (iop != 1)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
			{
				press1(400,400,500,435);
			}
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(400,400,500,435);
			delay(150);
			if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
			{
				sound();
				iop=1;
				cursoroff();
			}
		}
	}
}

