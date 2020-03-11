#include "g:\cld\circuit.h"

void codeconvertor(void);
void encoder(void);
void decoder(void);

int arithmetic(void);
int artsea(int x,int y);

void binaryadder(void);
void halfadder(void);
void fulladder(void);

void binarysubtractor(void);
void halfsubtractor(void);
void fullsubtractor(void);

void desioncom(void);
int checkpos(void);
int addersubtractor(void);
int basicsea(int x,int y);

void binaddsub(void);
void binmultiplier(void);
int checkbinmul(void);
int binmulsea(int x,int y);

int colbasic=230,rowbasic[4]={170,250,330},checkbasic,controlbasic=0;
int colart=160,rowart[5]={120,185,250,315,380};
void arith(void)
{
	int addition,adit=0;
	while (adit != 1)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,4);
		outtextxy(50,20,"Arithmetic and Logic Opertions");
		addition=arithmetic();
		if (addition == 0)
			binaryadder();
		if (addition == 1)
			binarysubtractor();
		if (addition == 2)
			binaddsub();
		if (addition == 3)
			binmultiplier();
		if (addition == 4)
			adit=1;
	}
}

int arithmetic(void)
{
	int ioad=0,chioad;
	for (int i=0;i<5;i++)
		comman(colart,rowart[i],colart+290,rowart[i]+35,7);
	settextstyle(1,0,3);
	outtextxy(colart+70,rowart[0],"Binary Adder");
	outtextxy(colart+45,rowart[1],"Binary Subtractor");
	outtextxy(colart+3,rowart[2],"Binary Adder-Subtractor");
	outtextxy(colart+50,rowart[3],"Binary Multiplier");
	outtextxy(colart+95,rowart[4],"Q u i t");
	setcursorpos(x,y);
	cursoron();
	int flag=0,again;
	while (ioad != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chioad=(artsea(x,y)))
			{
				case 0:
					press1(colart,rowart[0],colart+290,rowart[0]+35);
					 again=0;
				break;
				case 1:
					press1(colart,rowart[1],colart+290,rowart[1]+35);
					 again=1;
				break;
				case 2:
					press1(colart,rowart[2],colart+290,rowart[2]+35);
					 again=2;
				break;
				case 3:
					press1(colart,rowart[3],colart+290,rowart[3]+35);
					 again=3;
				break;
				case 4:
					press1(colart,rowart[4],colart+290,rowart[4]+35);
					again=4;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colart,rowart[again],colart+290,rowart[again]+35);
			if (x >= colart && x <= colart+290 && y >= rowart[again] && y <= rowart[again]+35)
			{
				cursoroff();
				sound();
				ioad=1;
			}
		}
	}
	return(chioad);
}

int artsea(int x,int y)
{
	for (int i = 0;i < 5;i++)
	if (x >= colart && x <= colart+290 && y >= rowart[i] && y <= rowart[i]+35)
		return(i);
	return(-1);
}

/*	Function of Binary Adder	*/

void binaryadder(void)
{
	controlbasic=0;
	while (!controlbasic)
	{
		desioncom();
		setcolor(0);
		outtextxy(147,4,"Binary Adder");
		outtextxy(148,5,"Binary Adder");
		setcolor(14);
		outtextxy(146,2,"Binary Adder");
		outtextxy(145,2,"Binary Adder");
		setcolor(0);
		settextstyle(1,0,3);
		outtextxy(colbasic+35,rowbasic[0],"Half Adder");
		outtextxy(colbasic+35,rowbasic[1],"Full Adder");
		outtextxy(colbasic+55,rowbasic[2],"Q u i t");
		checkbasic=checkpos();
		if (checkbasic==0)
			halfadder();
		if (checkbasic==1)
			fulladder();
		if (checkbasic==2)
			controlbasic=1;
	}
}

/*	Function of Binary subtractor	*/

void binarysubtractor(void)
{
	controlbasic=0;
	while (!controlbasic)
	{
		desioncom();
		setcolor(0);
		outtextxy(87,4,"Binary Subtractor");
		outtextxy(88,5,"Binary Subtractor");
		setcolor(14);
		outtextxy(86,2,"Binary Subtractor");
		outtextxy(85,2,"Binary Subtractor");
		setcolor(0);
		settextstyle(1,0,3);
		outtextxy(colbasic+5,rowbasic[0],"Half Subtractor");
		outtextxy(colbasic+5,rowbasic[1],"Full Subtractor");
		outtextxy(colbasic+55,rowbasic[2],"Q u i t");
		checkbasic=checkpos();
		if (checkbasic==0)
			halfsubtractor();
		if (checkbasic==1)
			fullsubtractor();
		if (checkbasic==2)
			controlbasic=1;
	}
}

/*	Function of Desion the Background	*/

void desioncom(void)
{
	setfillstyle(SOLID_FILL,3);
	bar(0,0,getmaxx(),getmaxy());
	comman(20,10,615,75,7);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);

	comman1(100,115,540,400,3);
	comman1(110,125,530,390,1);
	for (int i=0;i<3;i++)
		comman(colbasic,rowbasic[i],colbasic+185,rowbasic[i]+35,7);
}

int checkpos(void)
{
	setcursorpos(x,y);
	cursoron();
	int flag=0,again,io=0,chio;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chio=(basicsea(x,y)))
			{
				case 0:
					press1(colbasic,rowbasic[0],colbasic+185,rowbasic[0]+35);
					again=0;
				break;
				case 1:
					press1(colbasic,rowbasic[1],colbasic+185,rowbasic[1]+35);
					again=1;
				break;
				case 2:
					press1(colbasic,rowbasic[2],colbasic+185,rowbasic[2]+35);
					again=2;
				break;
				case 3:
					press1(colbasic,rowbasic[3],colbasic+185,rowbasic[3]+35);
					again=3;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colbasic,rowbasic[again],colbasic+185,rowbasic[again]+35);
			if (x >= colbasic && x <= colbasic+185 && y >= rowbasic[again] && y <= rowbasic[again]+35)
			{
				cursoroff();
				sound();
				io=1;
			}
		}
	}
	return(chio);
}

int basicsea(int x,int y)
{
	for (int i = 0;i < 4;i++)
	if (x >= colbasic && x <= colbasic+185 && y >= rowbasic[i] && y <= rowbasic[i]+35)
		return(i);
	return(-1);
}

/*	Function of Half Adder	*/

void halfadder(void)
{
	int mainlba=0,halfadd;
	while (!mainlba)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,6);
		setcolor(0);
		outtextxy(180,4,"Half Adder");
		settextstyle(2,0,5);
		outtextxy(50,100,"A Half Adder is a combinational circuit that accepts two inputs a and b");
		outtextxy(20,120,"and generates two outputs a Sum and a Carry.");
		line(getmaxx()/2,160,getmaxx()/2,455);
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(40,150,"Truth Table : ");
		outtextxy(getmaxx()/2+20,150,"Boolean Expression :");
		setcolor(0);
		settextstyle(2,0,5);
		outtextxy(40,180,"The Truth Table for a Half Adder:");
		rectangle(40,210,getmaxx()/2-20,390);
		line(40,230,getmaxx()/2-20,230);
		line(40,250,getmaxx()/2-20,250);
		line(90,230,90,390);
		line(140,210,140,390);
		line(220,230,220,390);
		outtextxy(70,210,"Inputs");
		outtextxy(200,210,"Outputs");
		outtextxy(60,230,"a");
		outtextxy(115,230,"b");
		outtextxy(170,230,"Sum");
		outtextxy(240,230,"Carry");
		outtextxy(60,260,"0");outtextxy(115,260,"0");outtextxy(180,260,"0");outtextxy(255,260,"0");
		outtextxy(60,290,"0");outtextxy(115,290,"1");outtextxy(180,290,"1");outtextxy(255,290,"0");
		outtextxy(60,320,"1");outtextxy(115,320,"0");outtextxy(180,320,"1");outtextxy(255,320,"0");
		outtextxy(60,350,"1");outtextxy(115,350,"1");outtextxy(180,350,"0");outtextxy(255,350,"1");
		outtextxy(getmaxx()/2+25,200,"Boolean Expression for Sum:");
		outtextxy(getmaxx()/2+25,290,"Boolean Expression for Carry:");
		settextstyle(1,0,1);
		outtextxy(getmaxx()/2+60,240,"S =   b + a");
		bara(420,240);barb(495,240);
		outtextxy(getmaxx()/2+80,330,"C = a . b");
		setcursorpos(x,y);
		line(40,250,getmaxx()/2-20,250);
		halfadd=addersubtractor();
		if (halfadd==1)
		{
			cursoroff();
			halfaddercir();
		}
		if (halfadd==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

/*	Function of Full Adder		*/

void fulladder(void)
{
	int mainlba=0,fulladd;
	while (!mainlba)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,6);
		setcolor(0);
		outtextxy(180,4,"Full Adder");
		settextstyle(2,0,5);
		outtextxy(70,80,"A Full Adder adds three inputs a,b and c a carry-in from previous");
		outtextxy(30,100,"addition and outputs the sum, S and the carry-out, C.");
		line(getmaxx()/2,160,getmaxx()/2,455);
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(40,120,"Truth Table : ");
		outtextxy(getmaxx()/2+20,150,"Boolean Expression :");
		setcolor(0);
		settextstyle(2,0,5);
		outtextxy(40,150,"The Truth Table for a Full Adder:");
		rectangle(20,180,getmaxx()/2-20,390);
		line(20,200,getmaxx()/2-20,200);
		line(20,220,getmaxx()/2-20,220);
		line(60,200,60,390);
		line(100,200,100,390);
		line(165,180,165,390);
		line(225,200,225,390);
		outtextxy(75,180,"Inputs");
		outtextxy(205,180,"Outputs");
		outtextxy(40,200,"a");
		outtextxy(80,200,"b");
		outtextxy(102,200,"carry-in");
		outtextxy(185,200,"Sum");
		outtextxy(230,200,"Carry-out");
		outtextxy(40,230,"0");outtextxy(80,230,"0");outtextxy(130,230,"0");outtextxy(190,230,"0");outtextxy(255,230,"0");
		outtextxy(40,250,"0");outtextxy(80,250,"0");outtextxy(130,250,"1");outtextxy(190,250,"1");outtextxy(255,250,"0");
		outtextxy(40,270,"0");outtextxy(80,270,"1");outtextxy(130,270,"0");outtextxy(190,270,"1");outtextxy(255,270,"0");
		outtextxy(40,290,"0");outtextxy(80,290,"1");outtextxy(130,290,"1");outtextxy(190,290,"0");outtextxy(255,290,"1");
		outtextxy(40,310,"1");outtextxy(80,310,"0");outtextxy(130,310,"0");outtextxy(190,310,"1");outtextxy(255,310,"0");
		outtextxy(40,330,"1");outtextxy(80,330,"0");outtextxy(130,330,"1");outtextxy(190,330,"0");outtextxy(255,330,"1");
		outtextxy(40,350,"1");outtextxy(80,350,"1");outtextxy(130,350,"0");outtextxy(190,350,"0");outtextxy(255,350,"1");
		outtextxy(40,370,"1");outtextxy(80,370,"1");outtextxy(130,370,"1");outtextxy(190,370,"1");outtextxy(255,370,"1");
		outtextxy(getmaxx()/2+25,200,"Boolean Expression for Sum:");
		outtextxy(getmaxx()/2+25,290,"Boolean Expression for Carry:");
		settextstyle(1,0,1);
		outtextxy(getmaxx()/2+30,240,"S =    c +  b  + a   + abc");
		bara(390,240);barb(403,240);
		bara(451,240);barc(478,240);
		barb(524,240);barc(538,240);
		outtextxy(getmaxx()/2+20,330,"C =  bc + a  c + ab  + abc");
		bara(378,330);barb(452,330);barc(527,330);
		setcursorpos(x,y);
		fulladd=addersubtractor();
		if (fulladd==1)
		{
			cursoroff();
			fulladdercir();
		}
		if (fulladd==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

/*	Function of Half Subtractor	*/

void halfsubtractor(void)
{
	int mainlba=0,halfsub;
	while (!mainlba)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,6);
		setcolor(0);
		outtextxy(120,4,"Half Subtractor");
		settextstyle(2,0,5);
		outtextxy(70,100,"A Half Subtractor is a combinational circuit that subtracts two bits");
		outtextxy(30,120,"and produces their Difference and Borrow.");
		line(getmaxx()/2,160,getmaxx()/2,455);
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(40,150,"Truth Table : ");
		outtextxy(getmaxx()/2+20,150,"Boolean Expression :");
		setcolor(0);
		settextstyle(2,0,5);
		outtextxy(30,180,"The Truth Table for a Half Subtractor:");
		rectangle(40,210,getmaxx()/2-20,390);
		line(40,230,getmaxx()/2-20,230);
		line(40,250,getmaxx()/2-20,250);
		line(90,230,90,390);
		line(140,210,140,390);
		line(220,230,220,390);
		outtextxy(70,210,"Inputs");
		outtextxy(200,210,"Outputs");
		outtextxy(60,230,"a");
		outtextxy(115,230,"b");
		outtextxy(145,230,"Difference");
		outtextxy(240,230,"Borrow");
		outtextxy(60,260,"0");outtextxy(115,260,"0");outtextxy(180,260,"0");outtextxy(255,260,"0");
		outtextxy(60,290,"0");outtextxy(115,290,"1");outtextxy(180,290,"1");outtextxy(255,290,"1");
		outtextxy(60,320,"1");outtextxy(115,320,"0");outtextxy(180,320,"1");outtextxy(255,320,"0");
		outtextxy(60,350,"1");outtextxy(115,350,"1");outtextxy(180,350,"0");outtextxy(255,350,"0");
		outtextxy(getmaxx()/2+25,200,"Boolean Expression for Difference:");
		outtextxy(getmaxx()/2+25,290,"Boolean Expression for Borrow:");
		settextstyle(1,0,1);
		outtextxy(getmaxx()/2+60,240,"D =   b + a");
		bara(420,240);barb(495,240);
		outtextxy(getmaxx()/2+80,330,"B =   . b");
		bara(440,330);
		setcursorpos(x,y);
		halfsub=addersubtractor();
		if (halfsub==1)
		{
			cursoroff();
			halfsubcir();
		}
		if (halfsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

/*	Function of Full Subtractor	*/

void fullsubtractor(void)
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
		outtextxy(120,4,"Full Subtractor");
		settextstyle(2,0,5);
		outtextxy(70,80,"A Full Subtractor is a combintional circuit that has three inputs,");
		outtextxy(30,100,"a,b and c and two outputs are D and B representing Difference and Borrow.");
		line(getmaxx()/2,160,getmaxx()/2,455);
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(40,120,"Truth Table : ");
		outtextxy(getmaxx()/2+20,150,"Boolean Expression :");
		setcolor(0);
		settextstyle(2,0,5);
		outtextxy(30,150,"The Truth Table for a Full Subtractor:");
		rectangle(20,180,getmaxx()/2-20,390);
		line(20,200,getmaxx()/2-20,200);
		line(20,220,getmaxx()/2-20,220);
		line(60,200,60,390);
		line(100,200,100,390);
		line(165,180,165,390);
		line(225,200,225,390);
		outtextxy(75,180,"Inputs");
		outtextxy(205,180,"Outputs");
		outtextxy(40,200,"a");
		outtextxy(80,200,"b");
		outtextxy(130,200,"c");
		outtextxy(190,200,"D");
		outtextxy(255,200,"B");
		outtextxy(40,230,"0");outtextxy(80,230,"0");outtextxy(130,230,"0");outtextxy(190,230,"0");outtextxy(255,230,"0");
		outtextxy(40,250,"0");outtextxy(80,250,"0");outtextxy(130,250,"1");outtextxy(190,250,"1");outtextxy(255,250,"1");
		outtextxy(40,270,"0");outtextxy(80,270,"1");outtextxy(130,270,"0");outtextxy(190,270,"1");outtextxy(255,270,"1");
		outtextxy(40,290,"0");outtextxy(80,290,"1");outtextxy(130,290,"1");outtextxy(190,290,"0");outtextxy(255,290,"1");
		outtextxy(40,310,"1");outtextxy(80,310,"0");outtextxy(130,310,"0");outtextxy(190,310,"1");outtextxy(255,310,"0");
		outtextxy(40,330,"1");outtextxy(80,330,"0");outtextxy(130,330,"1");outtextxy(190,330,"0");outtextxy(255,330,"0");
		outtextxy(40,350,"1");outtextxy(80,350,"1");outtextxy(130,350,"0");outtextxy(190,350,"0");outtextxy(255,350,"0");
		outtextxy(40,370,"1");outtextxy(80,370,"1");outtextxy(130,370,"1");outtextxy(190,370,"1");outtextxy(255,370,"1");
		outtextxy(getmaxx()/2+25,200,"Boolean Expression for Difference:");
		outtextxy(getmaxx()/2+25,290,"Boolean Expression for Borrow:");
		settextstyle(1,0,1);
		outtextxy(getmaxx()/2+30,240,"D =    c +  b  + a   + abc");
		bara(390,240);barb(403,240);
		bara(451,240);barc(478,240);
		barb(524,240);barc(538,240);
		outtextxy(getmaxx()/2+20,330,"B =    c +  b  +  bc + abc");
		bara(380,330);barb(395,330);
		bara(445,330);barc(470,330);bara(502,330);
		setcursorpos(x,y);
		fullsub=addersubtractor();
		if (fullsub==1)
		{
			cursoroff();
			fullsubcir();
		}
		if (fullsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

int addersubtractor(void)
{
	int iolba=0,flag=0,again,again1;
	settextstyle(1,0,2);
	comman(100,400,200,435,7);
	outtextxy(110,405,"NEXT >>");
	comman(400,400,500,435,7);
	outtextxy(415,405,"Q U I T");
	cursoron();
	while (!iolba)
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
					again1=1;
					cursoroff();
					iolba=1;
				}
			}
			else
			{
				press2(400,400,500,435);
				if (x >= 400 && x <= 500 && y >= 400 && y <= 435)
				{
					sound();
					again1=0;
					iolba=1;
					cursoroff();
				}
			}
		}
	}
	return(again1);
}

/*	Function of Binary Adder-Subtractor	*/

void binaddsub(void)
{
	int mainlba=0,fullsub;
	while (!mainlba)
	{
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		settextstyle(1,0,5);
		setcolor(0);
		outtextxy(60,10,"Binary Adder-Subtractor");
		settextstyle(2,0,5);
		outtextxy(70,110,"It is possible to combine the addition and subtraction operations into");
		outtextxy(30,130,"one circuit with one common binary adder. This can be done by including an");
		outtextxy(30,150,"XOR gate with each full adder");
		setcolor(9);
		settextstyle(1,0,2);
		outtextxy(60,190,"A 4-bit adder-subtractor circuit is shown below :");
		setcolor(0);
		outtextxy(40,230,"Two Numbers :");
		setcolor(9);
		outtextxy(175,300,"A");
		outtextxy(425,300,"B");
		setcolor(0);
		for (int i=100;i<=220;i+=40)
			rectangle(i,325,i+40,350);
		for (i=350;i<=470;i+=40)
			rectangle(i,325,i+40,350);
		for (i=115;i<230;i+=38)
			outtextxy(i,325,"A");
		for (i=365;i<480;i+=38)
			outtextxy(i,325,"B");
		settextstyle(2,0,4);
		outtextxy(129,337,"3");outtextxy(167,337,"2");outtextxy(205,337,"1");outtextxy(243,337,"0");
		outtextxy(379,337,"3");outtextxy(417,337,"2");outtextxy(455,337,"1");outtextxy(493,337,"0");
		setcursorpos(x,y);
		fullsub=addersubtractor();
		if (fullsub==1)
		{
			cursoroff();
			addsubcircuit();
		}
		if (fullsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

/*	Function of Binary Multiplier		*/

void binmultiplier(void)
{
	int colmul=150,rowmul[4]={170,250,330};
	int mainlba=0,fullsub;
	while (!mainlba)
	{
		setfillstyle(SOLID_FILL,3);
		bar(0,0,getmaxx(),getmaxy());
		comman(20,10,615,75,7);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);

		comman1(100,135,540,400,3);
		comman1(110,145,530,390,1);
		for (int i=0;i<3;i++)
			comman(colmul,rowmul[i],colmul+320,rowmul[i]+35,7);
		setcolor(0);
		outtextxy(107,4,"Binary Multiplier");
		outtextxy(108,5,"Binary Multiplier");
		setcolor(14);
		outtextxy(106,2,"Binary Multiplier");
		outtextxy(105,2,"Binary Multiplier");
		setcolor(0);
		settextstyle(2,0,5);
		outtextxy(70,90,"Multiplication of two binary numbers is performed in the same way as");
		outtextxy(30,110,"with decimal numbers, i.e, by successive addition and shifting. ");
		settextstyle(1,0,3);
		outtextxy(colmul+15,rowmul[0],"Multtiply 2-bit numbers");
		outtextxy(colmul+15,rowmul[1],"Multtiply 3-bit numbers");
		outtextxy(colmul+125,rowmul[2],"Q u i t");
		setcursorpos(x,y);
		cursoron();
		fullsub=checkbinmul();
		if (fullsub==0)
		{
			cursoroff();
			twobit();
		}
		if (fullsub==1)
		{
			cursoroff();
			threebit();
		}
		if (fullsub==2)
		{
			cursoroff();
			mainlba=1;
		}
	}
}


int checkbinmul(void)
{
	int colmul=150,rowmul[4]={170,250,330};
	setcursorpos(x,y);
	cursoron();
	int flag=0,again,io=0,chio;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (chio=(binmulsea(x,y)))
			{
				case 0:
					press1(colmul,rowmul[0],colmul+320,rowmul[0]+35);
					again=0;
				break;
				case 1:
					press1(colmul,rowmul[1],colmul+320,rowmul[1]+35);
					again=1;
				break;
				case 2:
					press1(colmul,rowmul[2],colmul+320,rowmul[2]+35);
					again=2;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(colmul,rowmul[again],colmul+320,rowmul[again]+35);
			if (x >= colmul && x <= colmul+320 && y >= rowmul[again] && y <= rowmul[again]+35)
			{
				cursoroff();
				sound();
				io=1;
			}
		}
	}
	return(chio);
}

int binmulsea(int x,int y)
{
	int colmul=150,rowmul[4]={170,250,330};
	for (int i = 0;i < 4;i++)
	if (x >= colmul && x <= colmul+320 && y >= rowmul[i] && y <= rowmul[i]+35)
		return(i);
	return(-1);
}

/*	Function of Code Convertor	*/

void codeconvertor(void)
{
	controlbasic=0;
	while (!controlbasic)
	{
		desioncom();
		setcolor(0);
		outtextxy(117,4,"Code Convertors");
		outtextxy(118,5,"Code Convertors");
		setcolor(14);
		outtextxy(116,2,"Code Convertors");
		outtextxy(115,2,"Code Convertors");
		setcolor(0);
		settextstyle(1,0,3);
		outtextxy(colbasic+50,rowbasic[0],"Encoder");
		outtextxy(colbasic+50,rowbasic[1],"Decoder");
		outtextxy(colbasic+55,rowbasic[2],"Q u i t");
		checkbasic=checkpos();
		if (checkbasic==0)
			encoder();
		if (checkbasic==1)
			decoder();
		if (checkbasic==2)
			controlbasic=1;
	}
}

/*	Function of Encoder	*/

void encoder(void)
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
		outtextxy(210,4,"Encoder");
		settextstyle(2,0,5);
		outtextxy(70,90,"The function of an encoder is to translate data from Decimal to Natural");
		outtextxy(30,110,"Binary or BCD. Four binary bits are needed to convert from Decimal to BCD");
		outtextxy(30,130,"for processing.");
		setcolor(9);
		outtextxy(70,160,"A block diagram for generating four binary outputs from ten decimal");
		outtextxy(50,180,"digits is as follows :");
		setcolor(0);
		line(150,230,225,230);
		line(150,250,225,250);
		line(150,270,225,270);
		line(150,330,225,330);
		rectangle(225,220,375,350);
		for (int i=275;i<=305;i+=10)
			outtextxy(185,i,".");
		line(375,240,450,240);
		line(375,270,450,270);
		line(375,300,450,300);
		line(375,330,450,330);
		outtextxy(20,275,"Decimal inputs");
		outtextxy(490,275,"outputs");
		settextstyle(1,0,2);
		amul(125,215,0);amul(125,235,1);amul(125,255,2);amul(125,315,9);
		bmul(455,225,0);bmul(455,255,1);bmul(455,285,2);bmul(455,315,3);
		setcolor(9);
		settextstyle(1,0,3);
		outtextxy(250,230,"Decimal");
		outtextxy(290,270,"to");
		outtextxy(280,310,"BCD");
		setcursorpos(x,y);
		cursoron();
		fullsub=addersubtractor();
		if (fullsub==1)
		{
			cursoroff();
			bcdencoder();
		}
		if (fullsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}

/*	Function of Decoder	*/

void decoder(void)
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
		outtextxy(210,4,"Decoder");
		settextstyle(2,0,5);
		outtextxy(70,90,"The function of a dncoder is essentially the reverse of an encoder. It");
		outtextxy(30,110,"needs one or more inputs to generate one output. Decoders are extensively");
		outtextxy(30,130,"used in memory systems in order to select the word of interest from many");
		outtextxy(30,150,"available.");
		setcolor(9);
		outtextxy(130,180,"A block diagram from BCD to Decimal Decoder.");
		setcolor(0);
		line(150,240,225,240);
		line(150,270,225,270);
		line(150,300,225,300);
		line(150,330,225,330);
		rectangle(225,220,375,350);
		line(375,230,450,230);
		line(375,250,450,250);
		line(375,270,450,270);
		line(375,330,450,330);
		for (int i=275;i<=305;i+=10)
			outtextxy(420,i,".");
		outtextxy(490,275,"Decimal outputs");
		settextstyle(2,0,6);
		outtextxy(75,230,"8(1000)");
		outtextxy(75,260,"4(0100)");
		outtextxy(75,290,"2(0010)");
		outtextxy(75,320,"1(0001)");
		settextstyle(1,0,2);
		bmul(25,225,0);bmul(25,255,1);bmul(25,285,2);bmul(25,315,3);
		amul(455,215,0);amul(455,235,1);amul(455,255,2);amul(455,315,3);
		setcolor(9);
		settextstyle(1,0,3);
		outtextxy(280,240,"BCD");
		outtextxy(290,270,"to");
		outtextxy(250,310,"Decimal");
		setcursorpos(x,y);
		cursoron();
		fullsub=addersubtractor();
		if (fullsub==1)
		{
			cursoroff();
			decodercircuit();
		}
		if (fullsub==0)
		{
			cursoroff();
			mainlba=1;
		}
	}
}


