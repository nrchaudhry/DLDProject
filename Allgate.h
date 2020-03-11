#include "d:\cld\gates.h"

void anddefination(void);
int andnext(void);
void ordefination(void);
int ornext(void);
void notdefination(void);
int notnext(void);
void nanddefination(void);
int nandnext(void);
void nordefination(void);
int nornext(void);
void xordefination(void);
int xornext(void);
void xnordefination(void);
int xnornext(void);

void anddefination(void)
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
		outtextxy(190,4,"AND Gate");
		settextstyle(1,0,2);
		setcolor(1);
		outtextxy(50,120,"For Two inputs,the AND gate is symbolised as :");
		setcolor(4);
		line(200,200,260,200);
		line(200,220,260,220);
		setcolor(9);
		and(290,210);
		setcolor(4);
		line(303,210,380,210);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,190,"A");
		outtextxy(180,210,"B");
		outtextxy(330,190,"A.B");
		outtextxy(420,200,"output,Z");
		outtextxy(50,270,"It is possible for a AND gate to have more then to inputs,");
		outtextxy(20,290,"all inputs must be 1 for the output to be 1. Under any other");
		outtextxy(20,310,"condition the output will be 0.");
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
						controlcom=andnext();
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

int andnext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,120,"Truth Table for the AND gate is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(100,180,500,360);
	rectangle(100,210,500,240);
	rectangle(100,240,500,270);
	rectangle(100,270,500,300);
	rectangle(100,300,500,330);
	rectangle(100,330,500,360);
	line(180,210,180,360);
	line(260,210,260,360);
	line(420,210,420,360);
	outtextxy(150,180,"Inputs");
	outtextxy(135,213,"A");
	outtextxy(135,243,"0");
	outtextxy(135,273,"0");
	outtextxy(135,303,"1");
	outtextxy(135,333,"1");
	outtextxy(210,213,"B");
	outtextxy(210,243,"0");
	outtextxy(210,273,"1");
	outtextxy(210,303,"0");
	outtextxy(210,333,"1");
	outtextxy(300,180,"Output");
	outtextxy(280,213,"A . B    =");
	outtextxy(280,243,"  0      =");
	outtextxy(280,273,"  0      =");
	outtextxy(280,303,"  0      =");
	outtextxy(280,333,"  1      =");
	outtextxy(455,213,"Z");
	outtextxy(455,243,"F");
	outtextxy(455,273,"F");
	outtextxy(455,303,"F");
	outtextxy(455,333,"T");
	settextstyle(1,0,2);
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

void ordefination(void)
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
		outtextxy(210,4,"OR Gate");
		settextstyle(1,0,2);
		setcolor(1);
		outtextxy(50,120,"For Two inputs,the OR gate is symbolised as :");
		setcolor(4);
		line(200,200,258,200);
		line(200,220,258,220);
		setcolor(10);
		or(183,210);
		setcolor(4);
		line(303,210,380,210);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,190,"A");
		outtextxy(180,210,"B");
		outtextxy(330,190,"A+B");
		outtextxy(420,200,"output,Z");
		outtextxy(50,270,"The or gate produces a 1 output if at least one of the");
		outtextxy(30,290,"inputs is 1.The above gate has also a fan-in-of two.");
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
						controlcom=ornext();
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

int ornext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,120,"Truth Table for the OR gate is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(100,180,500,360);
	rectangle(100,210,500,240);
	rectangle(100,240,500,270);
	rectangle(100,270,500,300);
	rectangle(100,300,500,330);
	rectangle(100,330,500,360);
	line(180,210,180,360);
	line(260,210,260,360);
	line(420,210,420,360);
	outtextxy(150,180,"Inputs");
	outtextxy(135,213,"A");
	outtextxy(135,243,"0");
	outtextxy(135,273,"0");
	outtextxy(135,303,"1");
	outtextxy(135,333,"1");
	outtextxy(210,213,"B");
	outtextxy(210,243,"0");
	outtextxy(210,273,"1");
	outtextxy(210,303,"0");
	outtextxy(210,333,"1");
	outtextxy(300,180,"Output");
	outtextxy(280,213,"A + B    =");
	outtextxy(280,243,"  0      =");
	outtextxy(280,273,"  1      =");
	outtextxy(280,303,"  1      =");
	outtextxy(280,333,"  1      =");
	outtextxy(455,213,"Z");
	outtextxy(455,243,"F");
	outtextxy(455,273,"T");
	outtextxy(455,303,"T");
	outtextxy(455,333,"T");
	settextstyle(1,0,2);
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

void notdefination(void)
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
		outtextxy(190,4,"NOT Gate");
		settextstyle(2,0,6);
		setcolor(1);
		outtextxy(50,100,"The NOT gate is also known as an inverter or negator and ");
		outtextxy(50,120,"is represented by the following symbol :");
		setcolor(4);
		line(200,210,260,210);
		setcolor(9);
		not(260,198);
		setcolor(4);
		line(298,210,380,210);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,200,"A");
		outtextxy(400,200,"A");
		outtextxy(400,192,"-");
		outtextxy(50,270,"The bubble at the output of the indicates an output which");
		outtextxy(30,290,"is the logical complement of the input.");
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
						controlcom=notnext();
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

int notnext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,120,"Truth Table of the Inverter is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(150,180,470,210);
	rectangle(150,210,470,240);
	rectangle(150,240,470,270);
	line(230,180,230,270);
	line(310,180,310,270);
	line(390,180,390,270);
	outtextxy(185,183,"A");
	outtextxy(185,213,"0");
	outtextxy(185,243,"1");
	outtextxy(265,183,"A");
	outtextxy(265,175,"-");
	outtextxy(265,213,"1");
	outtextxy(265,243,"0");
	outtextxy(345,183,"=");
	outtextxy(345,213,"=");
	outtextxy(345,243,"=");
	outtextxy(425,183,"Z");
	outtextxy(425,213,"T");
	outtextxy(425,243,"F");
	settextstyle(1,0,2);
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

void nanddefination(void)
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
		outtextxy(180,4,"NAND Gate");
		settextstyle(2,0,6);
		outtextxy(50,80,"NAND gate is the complement of the AND operation.Its name");
		outtextxy(30,100,"is an abbraviation of NOT-AND and follows from the rather");
		outtextxy(30,120,"awkward characterization of the circuit as not producing the");
		outtextxy(30,140,"output 1 whenever a=0 and b=0.We can denote by the boolean");
		outtextxy(30,160,"expression :");
		setcolor(1);
		outtextxy(200,170,"Z = a . b");
		line(240,170,280,170);
		outtextxy(80,190,"It is symbolised as :");
		setcolor(4);
		line(200,220,260,220);
		line(200,240,260,240);
		setcolor(12);
		nand(290,230);
		setcolor(4);
		line(315,230,410,230);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,210,"A");
		outtextxy(180,230,"B");
		outtextxy(420,220,"Z");
		setcolor(1);
		outtextxy(80,260,"Infact,it is similar to the circuit :");
		setcolor(4);
		line(180,300,230,300);
		line(180,320,230,320);
		setcolor(1);
		and(260,310);
		setcolor(4);
		line(273,310,350,310);
		setcolor(1);
		not(350,300);
		setcolor(4);
		line(388,312,430,312);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(160,290,"A");
		outtextxy(160,310,"B");
		outtextxy(440,302,"Z");
		setcolor(0);
		outtextxy(50,350,"Thus,a NAND gate is simply an inverted AND operation.");
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
						controlcom=nandnext();
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

int nandnext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,130,"Truth Table for the NAND gate is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(60,210,540,240);
	rectangle(60,240,540,270);
	rectangle(60,270,540,300);
	rectangle(60,300,540,330);
	rectangle(60,330,540,360);
	line(140,210,140,360);
	line(220,210,220,360);
	line(300,210,300,360);
	line(380,210,380,360);
	line(460,210,460,360);
	outtextxy(95,213,"A");
	outtextxy(95,243,"0");
	outtextxy(95,273,"0");
	outtextxy(95,303,"1");
	outtextxy(95,333,"1");
	outtextxy(170,213,"B");
	outtextxy(170,243,"0");
	outtextxy(170,273,"1");
	outtextxy(170,303,"0");
	outtextxy(170,333,"1");
	outtextxy(240,213,"A . B");
	outtextxy(240,243,"  0");
	outtextxy(240,273,"  0");
	outtextxy(240,303,"  0");
	outtextxy(240,333,"  1");
	outtextxy(320,213,"A . B");
	line(320,214,370,214);
	outtextxy(320,243,"  1");
	outtextxy(320,273,"  1");
	outtextxy(320,303,"  1");
	outtextxy(320,333,"  0");
	outtextxy(415,213,"=");
	outtextxy(415,243,"=");
	outtextxy(415,273,"=");
	outtextxy(415,303,"=");
	outtextxy(415,333,"=");
	outtextxy(495,213,"Z");
	outtextxy(495,243,"T");
	outtextxy(495,273,"T");
	outtextxy(495,303,"T");
	outtextxy(495,333,"F");
	settextstyle(1,0,2);
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

void nordefination(void)
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
		outtextxy(190,4,"NOR Gate");
		settextstyle(2,0,6);
		outtextxy(50,100,"NOR gate is the complement of the OR operation. Its name");
		outtextxy(30,120,"is the abbraviation of NOT-OR and its output is 1,when all");
		outtextxy(30,140,"its inputs are 0.");
		setcolor(1);
		outtextxy(200,160,"Z = a + b");
		line(240,160,283,160);
		outtextxy(80,180,"It is symbolised as :");
		setcolor(4);
		line(200,220,260,220);
		line(200,240,260,240);
		setcolor(6);
		nor(185,230);
		setcolor(4);
		line(317,230,410,230);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,210,"A");
		outtextxy(180,230,"B");
		outtextxy(420,220,"Z");
		setcolor(1);
		outtextxy(80,260,"Infact,it is similar to the circuit :");
		setcolor(4);
		line(180,310,230,310);
		line(180,330,230,330);
		setcolor(1);
		or(155,320);
		setcolor(4);
		line(276,320,350,320);
		setcolor(1);
		not(350,310);
		setcolor(4);
		line(388,322,430,322);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(160,300,"A");
		outtextxy(160,320,"B");
		outtextxy(440,312,"Z");
		setcolor(0);
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
						controlcom=nornext();
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

int nornext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,130,"Truth Table for the NOR gate is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(60,210,540,240);
	rectangle(60,240,540,270);
	rectangle(60,270,540,300);
	rectangle(60,300,540,330);
	rectangle(60,330,540,360);
	line(140,210,140,360);
	line(220,210,220,360);
	line(300,210,300,360);
	line(380,210,380,360);
	line(460,210,460,360);
	outtextxy(95,213,"A");
	outtextxy(95,243,"0");
	outtextxy(95,273,"0");
	outtextxy(95,303,"1");
	outtextxy(95,333,"1");
	outtextxy(170,213,"B");
	outtextxy(170,243,"0");
	outtextxy(170,273,"1");
	outtextxy(170,303,"0");
	outtextxy(170,333,"1");
	outtextxy(235,213,"A + B");
	outtextxy(235,243,"  0");
	outtextxy(235,273,"  1");
	outtextxy(235,303,"  1");
	outtextxy(235,333,"  1");
	outtextxy(315,213,"A + B");
	line(320,214,373,214);
	outtextxy(315,243,"  1");
	outtextxy(315,273,"  0");
	outtextxy(315,303,"  0");
	outtextxy(315,333,"  0");
	outtextxy(415,213,"=");
	outtextxy(415,243,"=");
	outtextxy(415,273,"=");
	outtextxy(415,303,"=");
	outtextxy(415,333,"=");
	outtextxy(495,213,"Z");
	outtextxy(495,243,"T");
	outtextxy(495,273,"F");
	outtextxy(495,303,"F");
	outtextxy(495,333,"F");
	settextstyle(1,0,2);
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

void xordefination(void)
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
		outtextxy(70,4,"Exclusive-OR Gate");
		settextstyle(2,0,6);
		outtextxy(50,100,"The distinctive-shape graphic symbol for an XOR gate is");
		outtextxy(30,120,"the OR symbol with an additional curved line on the input");
		outtextxy(30,140,"side.The XOR gate is only a two-inputs gate that producesed");
		outtextxy(30,160,"a 1 on its output when its input are different and a 0,if the");
		outtextxy(30,180,"inputs are the same.");
		setcolor(1);
		outtextxy(60,220,"An exclusive-OR gate is symbolised as :");
		setcolor(4);
		line(200,290,260,290);
		line(200,310,260,310);
		setcolor(13);
		xor(195,300);
		setcolor(4);
		line(315,300,410,300);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,280,"A");
		outtextxy(180,300,"B");
		outtextxy(430,290,"f");
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
						controlcom=xornext();
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

int xornext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,130,"Truth Table for the XOR gate is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(100,210,500,240);
	rectangle(100,240,500,270);
	rectangle(100,270,500,300);
	rectangle(100,300,500,330);
	rectangle(100,330,500,360);
	line(180,210,180,360);
	line(260,210,260,360);
	line(380,210,380,360);
	line(420,210,420,360);
	outtextxy(135,213,"A");
	outtextxy(135,243,"0");
	outtextxy(135,273,"0");
	outtextxy(135,303,"1");
	outtextxy(135,333,"1");
	outtextxy(210,213,"B");
	outtextxy(210,243,"0");
	outtextxy(210,273,"1");
	outtextxy(210,303,"0");
	outtextxy(210,333,"1");
	outtextxy(265,213,"output,f");
	outtextxy(275,243,"    0");
	outtextxy(275,273,"    1");
	outtextxy(275,303,"    1");
	outtextxy(275,333,"    0");
	outtextxy(395,213,"=");
	outtextxy(395,243,"=");
	outtextxy(395,273,"=");
	outtextxy(395,303,"=");
	outtextxy(395,333,"=");
	outtextxy(455,213,"Z");
	outtextxy(455,243,"F");
	outtextxy(455,273,"T");
	outtextxy(455,303,"T");
	outtextxy(455,333,"F");
	settextstyle(1,0,2);
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

void xnordefination(void)
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
		outtextxy(60,4,"Exclusive-NOR Gate");
		settextstyle(2,0,6);
		outtextxy(50,100,"The XNOR gate is only a two-inputs gate that producesed");
		outtextxy(30,120,"a 0,on its output when its input are different and a 1,if the");
		outtextxy(30,140,"inputs are the same.");
		setcolor(1);
		outtextxy(80,170,"It is symbolised as :");
		setcolor(4);
		line(200,220,260,220);
		line(200,240,260,240);
		setcolor(6);
		xnor(195,230);
		setcolor(4);
		line(327,230,410,230);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(180,210,"A");
		outtextxy(180,230,"B");
		outtextxy(420,220,"F");
		setcolor(1);
		outtextxy(80,260,"Infact,it is similar to the circuit :");
		setcolor(4);
		line(180,310,230,310);
		line(180,330,230,330);
		setcolor(1);
		xor(165,320);
		setcolor(4);
		line(286,320,350,320);
		setcolor(1);
		not(350,310);
		setcolor(4);
		line(388,322,430,322);
		settextstyle(2,0,6);
		setcolor(0);
		outtextxy(160,300,"A");
		outtextxy(160,320,"B");
		outtextxy(440,312,"F");
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
						controlcom=xnornext();
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

int xnornext(void)
{
	int ionext=0;
	comman3(15,70,615,455,15);
	settextstyle(1,0,2);
	setcolor(1);
	outtextxy(50,130,"Truth Table for the XNOR gate is shown below :");
	settextstyle(1,0,2);
	setcolor(0);
	rectangle(100,210,500,240);
	rectangle(100,240,500,270);
	rectangle(100,270,500,300);
	rectangle(100,300,500,330);
	rectangle(100,330,500,360);
	line(180,210,180,360);
	line(260,210,260,360);
	line(380,210,380,360);
	line(420,210,420,360);
	outtextxy(135,213,"A");
	outtextxy(135,243,"0");
	outtextxy(135,273,"0");
	outtextxy(135,303,"1");
	outtextxy(135,333,"1");
	outtextxy(210,213,"B");
	outtextxy(210,243,"0");
	outtextxy(210,273,"1");
	outtextxy(210,303,"0");
	outtextxy(210,333,"1");
	outtextxy(265,213,"output,f");
	outtextxy(275,243,"    1");
	outtextxy(275,273,"    0");
	outtextxy(275,303,"    0");
	outtextxy(275,333,"    1");
	outtextxy(395,213,"=");
	outtextxy(395,243,"=");
	outtextxy(395,273,"=");
	outtextxy(395,303,"=");
	outtextxy(395,333,"=");
	outtextxy(455,213,"Z");
	outtextxy(455,243,"T");
	outtextxy(455,273,"F");
	outtextxy(455,303,"F");
	outtextxy(455,333,"T");
	settextstyle(1,0,2);
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

