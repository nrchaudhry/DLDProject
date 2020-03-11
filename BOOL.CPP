#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "c:\cld\mouse.h"
#include "c:\cld\basic.h"

int choice(void);
void one(void);
void minimizationone(void);
int two(void);
void minimizationtwo(void);
int three(void);
void minimizationthree(void);
void empty(void);
void ok(void);
int ok1(int x,int y);
int check(int x,int y);
int check1(int x,int y);
int check2(int x,int y);
int check3(int x,int y);
void good(int x,int y,int check);
int nextboolean(int,int,int,int);
void endbool(int count,int par,int col,int row);

void commanmini(int ,int,int,int,int,int);
void minidesign(void);

struct functionone{
  int x;
  int  xbar;
  int y;
  int  ybar;
  int z;
  int  zbar;
} functionget,stringfun[8],result[8];
int count,count1,count2;
int button;

int col[3]={200,300,400},row[2]={230,250};

void main(void)
{
	int driver=DETECT,mode;
	int button,choice1;

	initgraph(&driver,&mode,"c:/tc/bgi");
	setfillstyle(SOLID_FILL,3);
	bar(0,0,getmaxx(),getmaxy());
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar(20,10,615,75);
	line(20,10,615,10);
	line(20,10,20,75);
	setcolor(0);
	line(20,75,615,75);
	line(615,10,615,75);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(92,4,"Boolean Expression");
	outtextxy(93,5,"Boolean Expression");
	setcolor(14);
	outtextxy(91,2,"Boolean Expression");
	outtextxy(90,2,"Boolean Expression");
	choice1=choice();
	empty();
	cursoroff();
	if (choice1==0)
	{
	      one();
	      minidesign();
	      minimizationone();
	}
	if (choice1==1)
	{
	      count1=two();
	      minidesign();
	      minimizationtwo();
	}
	if (choice1==2)
	{
	      count2=three();
	      minidesign();
	      minimizationthree();
	}
}

int choice(void)
{
	int cho,io=0,button;

	setfillstyle(SOLID_FILL,1);
	bar(110,155,530,290);
	setcolor(0);
	line(110,155,530,155);
	line(110,155,110,290);
	setcolor(15);
	line(110,290,530,290);
	line(530,155,530,290);
	setcolor(0);
	line(100,145,540,145);
	line(100,145,100,300);
	setcolor(15);
	line(100,300,540,300);
	line(540,145,540,300);
	setcolor(15);
	settextstyle(3,0,1);
	outtextxy(121,170,"How many Variables use in Boolean Exprasion?");

	setfillstyle(SOLID_FILL,7);
	for (int i = 0; i < 3; i++)
	{
		bar(col[i],row[0],col[i]+40,row[1]);
		setcolor(15);
		line(col[i],row[0],col[i]+40,row[0]);
		line(col[i],row[0],col[i],row[1]);
		setcolor(0);
		line(col[i],row[1],col[i]+40,row[1]);
		line(col[i]+40,row[0],col[i]+40,row[1]);
	}
	settextstyle(1,0,1);
	outtextxy(col[0]+15,row[0]-2,"1");
	outtextxy(col[1]+15,row[0]-2,"2");
	outtextxy(col[2]+15,row[0]-2,"3");

	mouseinit();
	setcursorpos(getmaxx()/2,getmaxy()/2);
	cursoron();
	int flag=0,again;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			switch (check(x,y))
			{
				case 0:
					press1(col[0],row[0],col[0]+40,row[1]);
					again=0;
				break;
				case 1:
					press1(col[1],row[0],col[1]+40,row[1]);
					again=1;
				break;
				case 2:
					press1(col[2],row[0],col[2]+40,row[1]);
					again=2;
				break;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(col[again],row[0],col[again]+40,row[1]);
			delay(100);
			switch (cho=(check(x,y)))
			{
				case 0:
					io=1;//sound();
				break;
				case 1:
					io=1;//sound();
				break;
				case 2:
					io=1;//sound();
				break;
			}
		}
	}
	return(cho);
}


/*	Function of One variables	*/

void one(void)
{
	int col[2]={258,468},row=214;
	int backfun=1;count=0;
	while(backfun)
	{
		int io=0,cho1=0,cho2=0;
		functionget.x=0;functionget.xbar=0;
		cursoroff();
		setfillstyle(SOLID_FILL,19);
		bar(20,100,615,450);
		setcolor(15);
		setfillstyle(SOLID_FILL,6);
		bar(110,85,530,108);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(110, 82, "   Boolean Expression of One Variable");

		setfillstyle(SOLID_FILL,1);
		bar(120,175,520,270);
		setcolor(0);
		line(120,175,520,175);
		line(120,175,120,270);
		setcolor(15);
		line(120,270,520,270);
		line(520,175,520,270);
		line(320,175,320,270);
		setcolor(0);
		line(110,165,530,165);
		line(110,165,110,280);
		setcolor(15);
		line(110,280,530,280);
		line(530,165,530,280);

		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(150, 200, "x");
		outtextxy(360, 200, "x");
		outtextxy(360, 190, "-");
		comman1(col[0],row,col[0]+22,row+18,15);
		comman1(col[1],row,col[1]+22,row+18,15);
		ok();
		setcursorpos(getmaxx()/2,getmaxy()/2);
		cursoron();
		int Flag=0;
		while (io != 1)
		{
			button=getcursorpos(&x,&y);
			if (button)
			{
				Flag=1;
				if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
					press1(275,415,365,440);
			}
			if((Flag)&&(!button))
			{
				Flag=0;
				switch (check1(x,y))
				{
					case 0:
						cursoroff();
						good(266,228,cho1);
						setcursorpos(x,y);
						cursoron();
						cho1=!cho1;
						functionget.x=cho1;
					break;
					case 1:
						cursoroff();
						good(475,228,cho2);
						setcursorpos(x,y);
						cursoron();
						cho2=!cho2;
						functionget.xbar=cho2;
					break;
				}	/*	End of Switch	*/
				press2(275,415,365,440);
				if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
				{
					cursoroff();
					io=1;//sound();
				}
			}/*	End of If Condition	*/
		}/*	End of While Loop	*/
		stringfun[count].x=functionget.x;
		stringfun[count].xbar=functionget.xbar;
		if ((functionget.xbar==1)||(functionget.x==1))
			count++;
		cursoroff();
		backfun=nextboolean(count,0,200,200);
		if (count==7)
		{
			backfun=0;
			endbool(count,0,180,240);
		}
	}
}/*	End of Function		*/

int check1(int x,int y)
{
	int col[2]={258,468},row=214;
	for (int i = 0;i < 2;i++)
	if (x >= col[i] && x <= col[i]+22 && y >= row && y <= row+18)
		return(i);
	return(-1);
}

void minimizationone(void)
{
	int calculate,i,calcu=0,countmini=count;
	if (count==1)
		commanmini(1,2,count,1,290,170);
	if (count==2)
		commanmini(1,2,count,1,260,170);
	if (count==3)
		commanmini(1,2,count,1,250,170);
	if (count==4)
		commanmini(1,2,count,1,230,170);
	if (count==5)
		commanmini(1,2,count,1,210,170);
	if (count==6)
		commanmini(1,2,count,1,190,170);
	if (count==7)
		commanmini(1,2,count,0,170,170);
	outtextxy(160,130,"Your Boolean Function is :");
	for (i=0;i<count;i++)
		if ((stringfun[i].x==1)&&(stringfun[i].xbar==1))
		{
			calcu=1;countmini--;
			for (calculate=i;calculate<count;calculate++)
			{
				stringfun[calculate].x=stringfun[calculate+1].x;
				stringfun[calculate].xbar=stringfun[calculate+1].xbar;
			}
			i--;
		}
	if (countmini==1)
		commanmini(1,2,count,1,290,220);
	if (countmini==2)
		commanmini(1,2,count,1,260,220);
	if (countmini==3)
		commanmini(1,2,count,1,250,220);
	if (countmini==4)
		commanmini(1,2,count,1,230,220);
	if (countmini==5)
		commanmini(1,2,count,1,210,220);
	if (countmini==6)
		commanmini(1,2,count,1,190,220);
	if (countmini==7)
		commanmini(1,2,count,0,170,220);
	calcu=0;
	for (int j=0;j<count;j++)
		for (i=j+1;i<count;i++)
			if ((stringfun[j].x==1)&&(stringfun[i].x==1))
			{
				calcu=1;countmini--;
				stringfun[i].x=0;
			}
	for (j=0;j<count;j++)
		for (i=j+1;i<count;i++)
			if ((stringfun[j].xbar==1)&&(stringfun[i].xbar==1))
			{
				calcu=1;countmini--;
				stringfun[i].xbar=0;
			}
	if (countmini==1)
		commanmini(1,2,count,1,290,260);
	if (countmini==2)
		commanmini(1,2,count,1,260,260);
	if (countmini==3)
		commanmini(1,2,count,1,250,260);
	if (countmini==4)
		commanmini(1,2,count,1,230,260);
	if (countmini==5)
		commanmini(1,2,count,1,210,260);
	if (countmini==6)
		commanmini(1,2,count,1,190,260);
	if (countmini==7)
		commanmini(1,2,count,0,170,260);
	outtextxy(160,300,"Minimization of Function is :");
	commanmini(1,2,count,0,260,340);
	ok();
	setcursorpos(getmaxx()/2,getmaxy()/2);
	cursoron();
	int Flag=0,io=0;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button)&&(!Flag))
		{
		Flag=1;
			if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
				press1(275,415,365,440);
		}
		if((Flag)&&(!button))
		{
			Flag=0;
			press2(275,415,365,440);
			if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
			{
				cursoroff();
				io=1;//sound();
			}
		}
	}
}

/*	Function of Two variables	*/

int two(void)
{
	int col[2]={258,468},row[2]={189,239},button;
	int backfun=1,count1=0;
	while(backfun)
	{
		functionget.x=0;functionget.xbar=0;functionget.y=0;functionget.ybar=0;
		int io=0,cho1=0,cho2=0,cho3=0,cho4=0;
		setfillstyle(SOLID_FILL,19);
		bar(20,100,615,450);
		setcolor(15);
		setfillstyle(SOLID_FILL,6);
		bar(110,85,530,108);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(110, 82, "   Boolean Exprasion of Two Variables");

		setfillstyle(SOLID_FILL,1);
		bar(120,155,520,290);
		setcolor(0);
		line(120,155,520,155);
		line(120,155,120,290);
		setcolor(15);
		line(120,290,520,290);
		line(520,155,520,290);
		line(320,155,320,290);
		setcolor(0);
		line(110,145,530,145);
		line(110,145,110,300);
		setcolor(15);
		line(110,300,530,300);
		line(530,145,530,300);

		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(150, 175, "x");
		outtextxy(360, 175, "x");
		outtextxy(360, 165, "-");
		setfillstyle(SOLID_FILL,15);
		bar(col[0],row[0],col[0]+22,row[0]+18);
		bar(col[1],row[0],col[1]+22,row[0]+18);

		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(150, 225, "y");
		outtextxy(360, 225, "y");
		outtextxy(360, 215, "-");
		setfillstyle(SOLID_FILL,15);
		bar(col[0],row[1],col[0]+22,row[1]+18);
		bar(col[1],row[1],col[1]+22,row[1]+18);
		for (int i=0;i<2;i++)
		{
			setcolor(15);
			line(col[0],row[i]+18,col[0]+22,row[i]+18);
			line(col[0]+22,row[i],col[0]+22,row[i]+18);
			setcolor(0);
			line(col[0],row[i],col[0]+22,row[i]);
			line(col[0],row[i],col[0],row[i]+18);
			setcolor(15);
			line(col[1],row[i]+18,col[1]+22,row[i]+18);
			line(col[1]+22,row[i],col[1]+22,row[i]+18);
			setcolor(0);
			line(col[1],row[i],col[1]+22,row[i]);
			line(col[1],row[i],col[1],row[i]+18);
		}
		ok();
		setcursorpos(getmaxx()/2,getmaxy()/2);
		cursoron();
		int Flag=0;
		while (io != 1)
		{
			button=getcursorpos(&x,&y);
			if (button)
			{
				Flag=1;
				if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
					press1(275,415,365,440);
			}
			if((Flag)&&(!button))
			{
				Flag=0;
				switch (check2(x,y))
				{
					case 0:
						cursoroff();
						good(266,203,cho1);
						setcursorpos(x,y);
						cursoron();
						cho1=!cho1;
						functionget.x=cho1;
					break;
					case 1:
						cursoroff();
						good(475,203,cho2);
						setcursorpos(x,y);
						cursoron();
						cho2=!cho2;
						functionget.xbar=cho2;
					break;
					case 2:
						cursoroff();
						good(266,253,cho3);
						setcursorpos(x,y);
						cursoron();
						cho3=!cho3;
						functionget.y=cho3;
					break;
					case 3:
						cursoroff();
						good(475,253,cho4);
						setcursorpos(x,y);
						cursoron();
						cho4=!cho4;
						functionget.ybar=cho4;
					break;
				}/*	End of Switch	*/
				press2(275,415,365,440);
				if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
				{
					cursoroff();
					io=1;//sound();
				}

			}/*	End of If Condition	*/
		}/*	End of While Loop	*/
		stringfun[count1].x=functionget.x;
		stringfun[count1].xbar=functionget.xbar;
		stringfun[count1].y=functionget.y;
		stringfun[count1].ybar=functionget.ybar;
		if (functionget.xbar==1||functionget.x==1||functionget.ybar==1||functionget.y==1)
			count1++;
		cursoroff();
		backfun=nextboolean(count1,1,200,200);
		if (count1==7)
		{
			backfun=0;
			endbool(count1,0,180,240);
		}
	}
	return(count1);
}

int check2(int x,int y)
{
	int col[2]={258,468},row[2]={189,239};
	if (x >= col[0] && x <= col[0]+22 && y >= row[0] && y <= row[0]+18)
		return(0);
	if (x >= col[1] && x <= col[1]+22 && y >= row[0] && y <= row[0]+18)
		return(1);
	if (x >= col[0] && x <= col[0]+22 && y >= row[1] && y <= row[1]+18)
		return(2);
	if (x >= col[1] && x <= col[1]+22 && y >= row[1] && y <= row[1]+18)
		return(3);
	return(-1);
}

void minimizationtwo(void)
{
	int calculate,i,calcu=0,calcu1=0;
	if (count1==1)
		commanmini(2,6,count1,1,290,160);
	if (count1==2)
		commanmini(2,6,count1,1,260,160);
	if (count1==3)
		commanmini(2,6,count1,1,230,160);
	if (count1==4)
		commanmini(2,6,count1,1,210,160);
	if (count1==5)
		commanmini(2,6,count1,1,180,160);
	if (count1==6)
		commanmini(2,6,count1,1,160,160);
	if (count1==7)
		commanmini(2,6,count1,1,130,160);
	outtextxy(160,130,"Your Boolean Function is :");
	for (i=0;i<count1;i++)
	{
		if ((stringfun[i].x==1&&stringfun[i].xbar==1)||(stringfun[i].y==1&&stringfun[i].ybar==1))
		{
			calcu=1;calcu1++;
			for (calculate=i;calculate<count1;calculate++)
			{
				stringfun[calculate].x=stringfun[calculate+1].x;
				stringfun[calculate].xbar=stringfun[calculate+1].xbar;
				stringfun[calculate].y=stringfun[calculate+1].y;
				stringfun[calculate].ybar=stringfun[calculate+1].ybar;
			}
			i--;
		}
	}
	count1=count1-calcu1;
	if (calcu==1)
	{
		if (count1==1)
			commanmini(2,6,count1,1,290,190);
		if (count1==2)
			commanmini(2,6,count1,1,260,190);
		if (count1==3)
			commanmini(2,6,count1,1,230,190);
		if (count1==4)
			commanmini(2,6,count1,1,210,190);
		if (count1==5)
			commanmini(2,6,count1,1,180,190);
		if (count1==6)
			commanmini(2,6,count1,1,160,190);
		if (count1==7)
			commanmini(2,6,count1,1,130,190);
	}
	calcu=0;calcu1=0;
	int iocontrol=0,conter=1;calcu1=0;
	for (i=0;i<count1;i++)
	{
		for (int j=i+1;j<count1;j++)
		{
			if (stringfun[i].x==stringfun[j].x)
			   if (stringfun[i].xbar==stringfun[j].xbar)
			      if (stringfun[i].y==stringfun[j].y)
				 if (stringfun[i].ybar==stringfun[j].ybar)
				 {
					calcu1++;calcu=1;
					for (conter=j;conter<count1;conter++)
					{
						stringfun[conter].x=stringfun[conter+1].x;
						stringfun[conter].xbar=stringfun[conter+1].xbar;
						stringfun[conter].y=stringfun[conter+1].y;
						stringfun[conter].ybar=stringfun[conter+1].ybar;
					}
				 }
		}//End of J Loop
	}// End of I Loop
	count1=count1-calcu1;
	if (calcu==1)
	{
		if (count1==1)
			commanmini(2,6,count1,1,290,220);
		if (count1==2)
			commanmini(2,6,count1,1,260,220);
		if (count1==3)
			commanmini(2,6,count1,1,230,220);
		if (count1==4)
			commanmini(2,6,count1,1,210,220);
		if (count1==5)
			commanmini(2,6,count1,1,180,220);
		if (count1==6)
			commanmini(2,6,count1,1,160,220);
		if (count1==7)
			commanmini(2,6,count1,1,130,220);
	}
	calcu1=0;conter=0;
	int an1=-1,an2=-1,an11=-1,an12=-1,an21=-1,an22=-1,counter=0;
	for (i=0;i<count1;i++)
		for (j=i+1;j<count1;j++)
			if (i!=an1&&j!=an1&&i!=an2&&j!=an2)
				if (stringfun[i].x==1&&stringfun[j].x==1)
				{
					result[calcu1].x=1;


/*	int rowin=250,anotherj[5]={-1,-1,-1,-1,-1};
	int ant=0;
	for (i=0;i<count1;i++)
	{
		conter=1;
		for (int j=i+1;j<count1;j++)
		{
		  //Check the x
		  for (int b=0;b<=i;b++)
			  if (j!=anotherj[ant]&&i!=anotherj[ant])
			  {
				if (stringfun[i].x==1&&stringfun[j].x==1)
				{
					b=i;
					result[calcu1].x=1;
					if (stringfun[i].xbar==1&&stringfun[j].xbar==1)
						result[calcu1].xbar=1;
					else
						result[calcu1].xbar=0;
					if (stringfun[i].y==1&&stringfun[j].y==1)
						result[calcu1].y=1;
					else
						result[calcu1].y=0;
					if (stringfun[i].ybar==1&&stringfun[j].ybar==1)
						result[calcu1].ybar=1;
					else
						result[calcu1].ybar=0;
					anotherj[i]=j;
					j=count1;conter=0;
					calcu1++;ant++;
				}
			  }
		  //Check the xbar
		  for (b=0;b<=i;b++)
			  if (j!=anotherj[ant]&&i!=anotherj[ant])
			  {
				if ((conter)&&(stringfun[i].xbar==stringfun[j].xbar==1))
				{
					result[calcu1].xbar=1;
					if (stringfun[i].x==stringfun[j].x==1)
						result[calcu1].x=1;
					else
						result[calcu1].x=0;
					if (stringfun[i].y==stringfun[j].y==1)
						result[calcu1].y=1;
					else
						result[calcu1].y=0;
					if (stringfun[i].ybar==stringfun[j].ybar==1)
						result[calcu1].ybar=1;
					else
						result[calcu1].ybar=0;
					anotherj[i]=j;
					j=count1;i=count1;conter=0;
					calcu1++;ant++;
				   }
			  }
		  //Check the y
		  for (b=0;b<=i;b++)
			  if (j!=anotherj[ant]&&i!=anotherj[ant])
			  {
				if ((conter)&&(stringfun[i].y==stringfun[j].y==1))
				{
					result[calcu1].y=1;
					if (stringfun[i].x==stringfun[j].x==1)
						result[calcu1].x=1;
					else
						result[calcu1].x=0;
					if (stringfun[i].xbar==stringfun[j].xbar==1)
						result[calcu1].xbar=1;
					else
						result[calcu1].xbar=0;
					if (stringfun[i].ybar==stringfun[j].ybar==1)
						result[calcu1].ybar=1;
					else
						result[calcu1].ybar=0;
					anotherj[i]=j;
					j=count1;i=count1;conter=0;
					calcu1++;ant++;
				}
			  }
		  //Check the ybar
		  for (b=0;b<=i;b++)
			  if (j!=anotherj[ant]&&i!=anotherj[ant])
			  {
				if ((conter)&&(stringfun[i].ybar==stringfun[j].ybar==1))
				{
					result[calcu1].ybar=1;
					if (stringfun[i].x==stringfun[j].x==1)
						result[calcu1].x=1;
					else
						result[calcu1].x=0;
					if (stringfun[i].y==stringfun[j].y==1)
						result[calcu1].y=1;
					else
						result[calcu1].y=0;
					if (stringfun[i].xbar==stringfun[j].xbar==1)
						result[calcu1].xbar=1;
					else
						result[calcu1].xbar=0;
					anotherj[i]=j;
					j=count1;i=count1;conter=0;
					calcu1++;ant++;
				}
			  }
			}//End of J Loop
	}// End of I Loop*/
	for (i=0;i<calcu1;i++)
	{
		stringfun[i].x=result[i].x;
		stringfun[i].y=result[i].y;
		stringfun[i].xbar=result[i].xbar;
		stringfun[i].ybar=result[i].ybar;
	}
	count1=calcu1-1;
	if (count1==1)
		commanmini(2,6,count1,1,290,rowin);
	if (count1==2)
		commanmini(2,6,count1,1,260,rowin);
	if (count1==3)
		commanmini(2,6,count1,1,230,rowin);
	if (count1==4)
		commanmini(2,6,count1,1,210,rowin);
	if (count1==5)
		commanmini(2,6,count1,1,180,rowin);
	if (count1==6)
		commanmini(2,6,count1,1,160,rowin);
	if (count1==7)
		commanmini(2,6,count1,1,130,rowin);
	rowin+=30;
	outtextxy(160,300,"Minimization of Function is :");
	commanmini(2,6,count1,1,260,340);
	ok();
	setcursorpos(getmaxx()/2,getmaxy()/2);
	cursoron();
	int Flag=0,io=0;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button)&&(!Flag))
		{
			Flag=1;
			if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
				press1(275,415,365,440);
		}
		if((Flag)&&(!button))
		{
			Flag=0;
			press2(275,415,365,440);
			if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
			{
				cursoroff();
				io=1;//sound();
			}
		}
	}
}

/*	Function of Three variables	*/

int three(void)
{
	int col[2]={258,468},row[3]={189,239,289},button;
	int backfun=1,count2=0;
	while(backfun)
	{
		functionget.x=0;functionget.xbar=0;functionget.y=0;functionget.ybar=0;functionget.z=0;functionget.zbar=0;
		int io=0,cho1=0,cho2=0,cho3=0,cho4=0,cho5=0,cho6=0;
		setfillstyle(SOLID_FILL,19);
		bar(20,100,615,450);
		setcolor(15);
		setfillstyle(SOLID_FILL,6);
		bar(110,85,530,108);
		settextstyle(1, HORIZ_DIR, 2);
		outtextxy(110, 82, "  Boolean Exprasion of Three Variables");

		setfillstyle(SOLID_FILL,1);
		bar(120,155,520,330);
		setcolor(0);
		line(120,155,520,155);
		line(120,155,120,330);
		setcolor(15);
		line(120,330,520,330);
		line(520,155,520,330);
		line(320,155,320,330);
		setcolor(0);
		line(110,145,530,145);
		line(110,145,110,340);
		setcolor(15);
		line(110,340,530,340);
		line(530,145,530,340);

		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(150, 175, "x");
		outtextxy(360, 175, "x");
		outtextxy(360, 165, "-");
		setfillstyle(SOLID_FILL,15);
		bar(col[0],row[0],col[0]+22,row[0]+18);
		bar(col[1],row[0],col[1]+22,row[0]+18);

		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(150, 225, "y");
		outtextxy(360, 225, "y");
		outtextxy(360, 215, "-");
		setfillstyle(SOLID_FILL,15);
		bar(col[0],row[1],col[0]+22,row[1]+18);
		bar(col[1],row[1],col[1]+22,row[1]+18);

		settextstyle(1, HORIZ_DIR, 4);
		outtextxy(150, 275, "z");
		outtextxy(363, 275, "z");
		outtextxy(360, 265, "-");
		setfillstyle(SOLID_FILL,15);
		bar(col[0],row[2],col[0]+22,row[2]+18);
		bar(col[1],row[2],col[1]+22,row[2]+18);
		for (int i=0;i<3;i++)
		{
			setcolor(15);
			line(col[0],row[i]+18,col[0]+22,row[i]+18);
			line(col[0]+22,row[i],col[0]+22,row[i]+18);
			setcolor(0);
			line(col[0],row[i],col[0]+22,row[i]);
			line(col[0],row[i],col[0],row[i]+18);
			setcolor(15);
			line(col[1],row[i]+18,col[1]+22,row[i]+18);
			line(col[1]+22,row[i],col[1]+22,row[i]+18);
			setcolor(0);
			line(col[1],row[i],col[1]+22,row[i]);
			line(col[1],row[i],col[1],row[i]+18);
		}
		ok();
		setcursorpos(getmaxx()/2,getmaxy()/2);
		cursoron();
		int Flag=0;
		while (io != 1)
		{
			button=getcursorpos(&x,&y);
			if (button)
			{
				Flag=1;
				if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
					press1(275,415,365,440);
			}
			if((Flag)&&(!button))
			{
				Flag=0;
				switch (check3(x,y))
				{
					case 0:
						cursoroff();
						good(266,203,cho1);
						setcursorpos(x,y);
						cursoron();
						cho1=!cho1;
						functionget.x=cho1;
					break;
					case 1:
						cursoroff();
						good(475,203,cho2);
						setcursorpos(x,y);
						cursoron();
						cho2=!cho2;
						functionget.xbar=cho2;
					break;
					case 2:
						cursoroff();
						good(266,253,cho3);
						setcursorpos(x,y);
						cursoron();
						cho3=!cho3;
						functionget.y=cho3;
					break;
					case 3:
						cursoroff();
						good(475,253,cho4);
						setcursorpos(x,y);
						cursoron();
						cho4=!cho4;
						functionget.ybar=cho4;
					break;
					case 4:
						cursoroff();
						good(266,303,cho5);
						setcursorpos(x,y);
						cursoron();
						cho5=!cho5;
						functionget.z=cho5;
					break;
					case 5:
						cursoroff();
						good(475,303,cho6);
						setcursorpos(x,y);
						cursoron();
						cho6=!cho6;
						functionget.zbar=cho6;
					break;
				}	/*	End of Switch	*/
				press2(275,415,365,440);
				if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
				{
					cursoroff();
					io=1;//sound();
				}

			}/*	End of If Condition	*/
		}/*	End of While Loop	*/
		stringfun[count2].x=functionget.x;
		stringfun[count2].xbar=functionget.xbar;
		stringfun[count2].y=functionget.y;
		stringfun[count2].ybar=functionget.ybar;
		stringfun[count2].z=functionget.z;
		stringfun[count2].zbar=functionget.zbar;
		if (functionget.xbar==1||functionget.x==1||functionget.ybar==1||functionget.y==1||functionget.zbar==1||functionget.z==1)
			count2++;
		setcolor(15);
		cursoroff();
		backfun=nextboolean(count2,2,200,200);
		if (count2==7)
		{
			backfun=0;
			endbool(count2,0,180,240);
		}
	}
	return(count2);
}

int check3(int x,int y)
{
	int col[2]={258,468},row[3]={189,239,289};
	if (x >= col[0] && x <= col[0]+22 && y >= row[0] && y <= row[0]+18)
		return(0);
	if (x >= col[1] && x <= col[1]+22 && y >= row[0] && y <= row[0]+18)
		return(1);
	if (x >= col[0] && x <= col[0]+22 && y >= row[1] && y <= row[1]+18)
		return(2);
	if (x >= col[1] && x <= col[1]+22 && y >= row[1] && y <= row[1]+18)
		return(3);
	if (x >= col[0] && x <= col[0]+22 && y >= row[2] && y <= row[2]+18)
		return(4);
	if (x >= col[1] && x <= col[1]+22 && y >= row[2] && y <= row[2]+18)
		return(5);
	return(-1);
}

void minimizationthree(void)
{
	int calculate,i,calcu=0,calcu1=0;
	if (count2==1)
		commanmini(2,6,count2,2,290,160);
	if (count2==2)
		commanmini(2,6,count2,2,260,160);
	if (count2==3)
		commanmini(2,6,count2,2,230,160);
	if (count2==4)
		commanmini(2,6,count2,2,210,160);
	if (count2==5)
		commanmini(2,6,count2,2,170,160);
	if (count2==6)
		commanmini(2,6,count2,2,140,160);
	if (count2==7)
		commanmini(2,6,count2,2,100,160);
	outtextxy(160,130,"Your Boolean Function is :");
	for (i=0;i<count2;i++)
	{
		if ((stringfun[i].x==1&&stringfun[i].xbar==1)||(stringfun[i].y==1&&stringfun[i].ybar==1)||(stringfun[i].z==1&&stringfun[i].zbar==1))
		{
			calcu=1;calcu1++;
			for (calculate=i;calculate<count2;calculate++)
			{
				stringfun[calculate].x=stringfun[calculate+1].x;
				stringfun[calculate].xbar=stringfun[calculate+1].xbar;
				stringfun[calculate].y=stringfun[calculate+1].y;
				stringfun[calculate].ybar=stringfun[calculate+1].ybar;
				stringfun[calculate].z=stringfun[calculate+1].z;
				stringfun[calculate].zbar=stringfun[calculate+1].zbar;
			}
			i--;
		}
	}
	count2=count2-calcu1;
	if (calcu==1)
	{
		if (count2==1)
			commanmini(2,6,count2,2,290,190);
		if (count2==2)
			commanmini(2,6,count2,2,260,190);
		if (count2==3)
			commanmini(2,6,count2,2,230,190);
		if (count2==4)
			commanmini(2,6,count2,2,210,190);
		if (count2==5)
			commanmini(2,6,count2,2,170,190);
		if (count2==6)
			commanmini(2,6,count2,2,140,190);
		if (count2==7)
			commanmini(2,6,count2,2,100,190);
	}
	calcu=0;calcu1=0;
	int iocontrol=0,conter=1;calcu1=0;
	for (i=0;i<count2;i++)
	{
		for (int j=i+1;j<count2;j++)
		{
			if (stringfun[i].x==stringfun[j].x)
			   if (stringfun[i].xbar==stringfun[j].xbar)
			      if (stringfun[i].y==stringfun[j].y)
				 if (stringfun[i].ybar==stringfun[j].ybar)
				     if (stringfun[i].z==stringfun[j].z)
					 if (stringfun[i].zbar==stringfun[j].zbar)
					 {
						calcu1++;calcu=1;
						for (conter=j;conter<count2;conter++)
						{
							stringfun[conter].x=stringfun[conter+1].x;
							stringfun[conter].xbar=stringfun[conter+1].xbar;
							stringfun[conter].y=stringfun[conter+1].y;
							stringfun[conter].ybar=stringfun[conter+1].ybar;
							stringfun[conter].z=stringfun[conter+1].z;
							stringfun[conter].zbar=stringfun[conter+1].zbar;
						}
						j--;
					 }
		}//End of J Loop
	}// End of I Loop
	count2=count2-calcu1;
	printf("%d",count1);
	if (calcu==1)
	{
		if (count2==1)
			commanmini(2,6,count2,2,290,220);
		if (count2==2)
			commanmini(2,6,count2,2,260,220);
		if (count2==3)
			commanmini(2,6,count2,2,230,220);
		if (count2==4)
			commanmini(2,6,count2,2,210,220);
		if (count2==5)
			commanmini(2,6,count2,2,170,220);
		if (count2==6)
			commanmini(2,6,count2,2,140,220);
		if (count2==7)
			commanmini(2,6,count2,2,100,220);
	}


/*	while (iocontrol < count2)
	{
		for (i=0;i<count2;i++)
		{
			for (int j=1;j<count2;j++)
			{
				//Check the x
				if (stringfun[i].x==stringfun[j].x==1)
				{
					result[calcu1].x=1;
					if (stringfun[i].xbar==stringfun[j].xbar==1)
						result[calcu1].xbar=1;
					else
						result[calcu1].xbar=0;
					if (stringfun[i].y==stringfun[j].y==1)
						result[calcu1].y=1;
					else
						result[calcu1].y=0;
					if (stringfun[i].ybar==stringfun[j].ybar==1)
						result[calcu1].ybar=1;
					else
						result[calcu1].ybar=0;
					calcu1++;j=count2;i=count2;conter=0;
				}
				//Check the xbar
				if ((conter)&&(stringfun[i].xbar==stringfun[j].xbar==1))
				{
					result[calcu1].xbar=1;
					if (stringfun[i].x==stringfun[j].x==1)
						result[calcu1].x=1;
					else
						result[calcu1].x=0;
					if (stringfun[i].y==stringfun[j].y==1)
						result[calcu1].y=1;
					else
						result[calcu1].y=0;
					if (stringfun[i].ybar==stringfun[j].ybar==1)
						result[calcu1].ybar=1;
					else
						result[calcu1].ybar=0;
					calcu1++;j=count2;i=count2;conter=0;
				}
				//Check the y
				if ((conter)&&(stringfun[i].y==stringfun[j].y==1))
				{
					result[calcu1].y=1;
					if (stringfun[i].x==stringfun[j].x==1)
						result[calcu1].x=1;
					else
						result[calcu1].x=0;
					if (stringfun[i].xbar==stringfun[j].xbar==1)
						result[calcu1].xbar=1;
					else
						result[calcu1].xbar=0;
					if (stringfun[i].ybar==stringfun[j].ybar==1)
						result[calcu1].ybar=1;
					else
						result[calcu1].ybar=0;
					calcu1++;j=count2;i=count2;conter=0;
				}
				//Check the ybar
				if ((conter)&&(stringfun[i].ybar==stringfun[j].ybar==1))
				{
					result[calcu1].ybar=1;
					if (stringfun[i].x==stringfun[j].x==1)
						result[calcu1].x=1;
					else
						result[calcu1].x=0;
					if (stringfun[i].y==stringfun[j].y==1)
						result[calcu1].y=1;
					else
						result[calcu1].y=0;
					if (stringfun[i].xbar==stringfun[j].xbar==1)
						result[calcu1].xbar=1;
					else
						result[calcu1].xbar=0;
					calcu1++;j=count2;i=count2;conter=0;
				}
			}//End of J Loop
		}// End of I Loop
		iocontrol++;
	}//End of While Loop
*/

	outtextxy(160,300,"Minimization of Function is :");
	commanmini(2,6,count2,1,260,340);
	ok();
	setcursorpos(getmaxx()/2,getmaxy()/2);
	cursoron();
	int Flag=0,io=0;
	while (io != 1)
	{
		button=getcursorpos(&x,&y);
		if ((button)&&(!Flag))
		{
			Flag=1;
			if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
				press1(275,415,365,440);
		}
		if((Flag)&&(!button))
		{
			Flag=0;
			press2(275,415,365,440);
			if (x >= 275 && x <= 365 && y >= 415 && y <= 440)
			{
				cursoroff();
				io=1;//sound();
			}
		}
	}
}

void empty(void)
{
	setfillstyle(SOLID_FILL,19);
	bar(20,100,615,450);
}

void ok(void)
{
	comman(275,415,365,440,7);
	settextstyle(1,0,3);
	outtextxy(305,412,"OK");
	outtextxy(305,413,"OK");
}

int check(int x,int y)
{
	for (int i = 0;i < 3;i++)
	if (x >= col[i] && x <= col[i]+40 && y >= row[0] && y <= row[1])
		return(i);
	return(-1);
}

/*	Function of Good	*/

void good(int x,int y,int check)
{
	if(!check)
		setcolor(BLACK);
	else
		setcolor(WHITE);

	line(x-5,y-3,x,y+2);
	line(x-5,y-4,x,y+1);
	line(x-5,y-5,x,y);
	line(x+1,y+2,x+12,y-9);
	line(x+1,y+1,x+12,y-10);
	line(x+1,y,x+12,y-11);
}

int nextboolean(int xa,int xb,int col,int row)
{
	setfillstyle(SOLID_FILL,7);
	bar(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+100);
	setfillstyle(SOLID_FILL,3);
	bar(getmaxx()/2-248,getmaxy()/2-123,getmaxx()/2+248,150);
	setcolor(15);
	line(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2-125);
	line(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2-250,getmaxy()/2+100);
	setcolor(0);
	line(getmaxx()/2-250,getmaxy()/2+100,getmaxx()/2+250,getmaxy()/2+100);
	line(getmaxx()/2+250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+100);
	setcolor(1);
	settextstyle(7,0,4);
	outtextxy(110,110,"Information");
	comman(150,285,250,315,7);
	comman(380,285,480,315,7);
	settextstyle(2,0,5);
	for (int i =0;i<=xa;i++)
	{
		if (i!=0)
		{
			if (xb==0)
			{
				if ((!stringfun[i].x)&&(!stringfun[i].xbar))
				{}//Dummy
				else
				{
					outtextxy(col,row,"+");
					col+=10;
				}
			}
			if (xb==1)
			{
				if (!stringfun[i].x&&!stringfun[i].xbar&&!stringfun[i].	y&&!stringfun[i].ybar)
				{}//Dummy
				else
				{
					outtextxy(col,row,"+");
					col+=10;
				}
			}
			if (xb==2)
			{
				if (!stringfun[i].x&&!stringfun[i].xbar&&!stringfun[i].	y&&!stringfun[i].ybar&&!stringfun[i].z&&!stringfun[i].zbar)
				{}//Dummy
				else
				{
					outtextxy(col,row,"+");
					col+=10;
				}
			}
		}
		if (stringfun[i].x==1)
		{
			outtextxy(col,row,"X");
			col+=10;
		}
		if (stringfun[i].xbar==1)
		{
			outtextxy(col,row,"X");
			outtextxy(col,row-6,"-");
			col+=10;
		}
		if (stringfun[i].y==1)
		{
			outtextxy(col,row,"Y");
			col+=10;
		}
		if (stringfun[i].ybar==1)
		{
			outtextxy(col,row,"Y");
			outtextxy(col,row-6,"-");
			col+=10;
		}
		if (stringfun[i].z==1)
		{
			outtextxy(col,row,"Z");
			col+=10;
		}
		if (stringfun[i].zbar==1)
		{
			outtextxy(col,row,"Z");
			outtextxy(col,row-7,"-");
			col+=10;
		}
	}
/*	settextstyle(2,0,5);
	outtextxy(180,285,"");*/
	settextstyle(1,0,3);
	outtextxy(180,285,"Yes");
	outtextxy(420,285,"No");
	setcolor(15);
	cursoron();
	int iolba=0,flag=0,again,again1;
	while (!iolba)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 150 && x <= 250 && y >= 285 && y <= 315)
			{
				press1(150,285,250,315);
				again=1;
			}
			if (x >= 380 && x <= 480 && y >= 285 && y <= 315)
			{
				press1(380,285,480,315);
				again=0;
			}
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			if (again)
				press2(150,285,250,315);
			else
				press2(380,285,480,315);
			delay(100);
			if (x >= 150 && x <= 250 && y >= 285 && y <= 315)
			{
//				sound();
				again1=1;
				iolba=1;
				cursoroff();
			}
			if (x >= 380 && x <= 480 && y >= 285 && y <= 315)
			{
//				sound();
				again1=0;
				cursoroff();
				iolba=1;
			}
		}
	}
	return(again1);

}

void endbool(int count,int par,int col,int row)
{
	setfillstyle(SOLID_FILL,7);
	bar(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+100);
	setfillstyle(SOLID_FILL,3);
	bar(getmaxx()/2-248,getmaxy()/2-123,getmaxx()/2+248,150);
	setcolor(15);
	line(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2-125);
	line(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2-250,getmaxy()/2+100);
	setcolor(0);
	line(getmaxx()/2-250,getmaxy()/2+100,getmaxx()/2+250,getmaxy()/2+100);
	line(getmaxx()/2+250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+100);
	setcolor(1);
	settextstyle(7,0,4);
	outtextxy(110,110,"Information");
	settextstyle(1,0,4);
	comman(250,285,350,315,7);
	outtextxy(280,280,"Ok");
	settextstyle(2,0,5);
	outtextxy(180,180,"You are continue only Seven times.");
	outtextxy(100,210,"Your Final Boolean Function is :");
	commanmini(2,5,count,par,col,row);
	setcursorpos(getmaxx()/2,getmaxy()/2);
	cursoron();
	int iolba=0,flag=0;
	while (!iolba)
	{
		button=getcursorpos(&x,&y);
		if ((button==1)&&(!flag))
		{
			flag=1;
			if (x >= 250 && x <= 350 && y >= 285 && y <= 315)
				press1(250,285,350,315);
		}
		if ((button==0)&&(flag))
		{
			flag=0;
			press2(250,285,350,315);
			if (x >= 250 && x <= 350 && y >= 285 && y <= 315)
			{
//				sound();
				iolba=1;
				cursoroff();
			}
		}
	}
}

void commanmini(int font,int size,int xa,int xb,int col,int row)
{
	settextstyle(font,0,size);
	for (int i =0;i<=xa;i++)
	{
		if (i!=0)
		{
			if (xb==0)
			{
				if ((!stringfun[i].x)&&(!stringfun[i].xbar))
				{}//Dummy
				else
				{
					outtextxy(col,row," + ");
					col+=30;
				}
			}
			if (xb==1)
			{
				if (!stringfun[i].x&&!stringfun[i].xbar&&!stringfun[i].	y&&!stringfun[i].ybar)
				{}//Dummy
				else
				{
					outtextxy(col,row," + ");
					col+=30;
				}
			}
			if (xb==2)
			{
				if (!stringfun[i].x&&!stringfun[i].xbar&&!stringfun[i].	y&&!stringfun[i].ybar&&!stringfun[i].z&&!stringfun[i].zbar)
				{}//Dummy
				else
				{
					outtextxy(col,row," + ");
					col+=30;
				}
			}
		}
		if (stringfun[i].x==1)
		{
			outtextxy(col,row,"X");
			col+=15;
		}
		if (stringfun[i].xbar==1)
		{
			outtextxy(col,row,"X");
			if (font==1)
				outtextxy(col,row-11,"-");
			else
				outtextxy(col,row-8,"-");
			col+=15;
		}
		if (stringfun[i].y==1)
		{
			outtextxy(col,row,"Y");
			col+=15;
		}
		if (stringfun[i].ybar==1)
		{
			outtextxy(col,row,"Y");
			outtextxy(col,row-8,"-");
			col+=15;
		}
		if (stringfun[i].z==1)
		{
			outtextxy(col,row,"Z");
			col+=15;
		}
		if (stringfun[i].zbar==1)
		{
			outtextxy(col,row,"Z");
			outtextxy(col,row-8,"-");
			col+=15;
		}
	}
}

void minidesign(void)
{
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 65,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
	setcolor(0);
	outtextxy(42,12,"Minimization of Boolean Functions");
	outtextxy(43,13,"Minimization of Boolean Functions");
	setcolor(14);
	outtextxy(41,10,"Minimization of Boolean Functions");
	outtextxy(40,10,"Minimization of Boolean Functions");
	setcolor(15);
	setfillstyle(SOLID_FILL,6);
	bar(200,85,420,108);
	settextstyle(1, HORIZ_DIR, 2);
	outtextxy(280, 82, "Result");
	setfillstyle(SOLID_FILL,1);
	bar(80,125,560,390);
	setcolor(0);
	line(80,125,560,125);
	line(80,125,80,390);
	setcolor(15);
	line(80,390,560,390);
	line(560,125,560,390);
	setcolor(0);
	line(70,115,570,115);
	line(70,115,70,400);
	setcolor(15);
	line(70,400,570,400);
	line(570,115,570,400);
}

