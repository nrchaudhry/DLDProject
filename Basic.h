/*	Function of Sound	*/

void sound(void)

{
	int i,c=500;
	   while (c!=700)
	   {
		sound(c);
		c+=10;
		delay(5);
		nosound();
	   }
}
/*	Functoin of Command	*/

void comman(int x,int y,int x1,int y1,int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x1, y1);
	setcolor(15);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(0);
	line(x+1,y1,x1,y1);
	line(x1,y+1,x1,y1);
}

void comman1(int x,int y,int x1,int y1,int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x1, y1);
	setcolor(0);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(15);
	line(x,y1,x1,y1);
	line(x1,y,x1,y1);
}

void comman2(int x,int y,int x1,int y1,int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x1, y1);
}

void comman3(int x,int y,int x1,int y1,int color)
{
	setfillstyle(SOLID_FILL, color);
	bar(x, y, x1, y1);
	setcolor(0);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(0);
	line(x,y1,x1,y1);
	line(x1,y,x1,y1);
}

void press(int x,int y,int x1,int y1)
{
	setcolor(0);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(15);
	line(x,y1,x1,y1);
	line(x1,y,x1,y1);
	delay(300);
	setcolor(15);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(0);
	line(x,y1,x1,y1);
	line(x1,y,x1,y1);
}

void press1(int x,int y,int x1,int y1)
{
	setcolor(0);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(15);
	line(x,y1,x1,y1);
	line(x1,y,x1,y1);
}

void press2(int x,int y,int x1,int y1)
{
	setcolor(15);
	line(x,y,x1,y);
	line(x,y,x,y1);
	setcolor(0);
	line(x+1,y1,x1,y1);
	line(x1,y+1,x1,y1);
}

void desion2(void)
{
	int c,r;

	setcolor(15);
	setfillstyle(SOLID_FILL,7);
	bar(getmaxx()/2-210,getmaxy()/2-100,getmaxx()/2+210,getmaxy()/2+75);
	setfillstyle(SOLID_FILL,3);
	bar(getmaxx()/2-210,getmaxy()/2-98,getmaxx()/2+210,180);
	setcolor(15);
	line(getmaxx()/2-210,getmaxy()/2-100,getmaxx()/2+210,getmaxy()/2-100);
	line(getmaxx()/2-210,getmaxy()/2-100,getmaxx()/2-210,getmaxy()/2+75);
	setcolor(0);
	line(getmaxx()/2-210,getmaxy()/2+75,getmaxx()/2+210,getmaxy()/2+75);
	line(getmaxx()/2+210,getmaxy()/2-100,getmaxx()/2+210,getmaxy()/2+75);


	setfillstyle(SOLID_FILL,14);
	bar(145,214,205,260);
	setcolor(0);
	line(145,260,205,260);
	line(144,260,175,214);
	line(175,214,206,260);
	setcolor(7);
	c=143;r=174;
	for (int i=0;i<30;i++)
	{
		line(c,260,r,214);
		c--;r--;
	}
	c=176;r=207;
	for (i=0;i<30;i++)
	{
		line(r,260,c,214);
		c++;r++;
	}
	setcolor(0);
	settextstyle(1,0,4);
	outtextxy(173,222,"!");

}

void Flush(void)
{
	_AH=0x0c;
	geninterrupt(0x21);
 }
