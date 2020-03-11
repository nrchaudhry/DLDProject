
void and(int x,int y);
void or(int x,int y);
void not(int x,int y);
void nand(int x,int y);
void nor(int x,int y);
void xor(int x,int y);
void xnor(int x,int y);

void and(int x,int y)
{
	ellipse(x, y, 0, 90,13, 17);
	ellipse(x, y, 270, 360,13, 17);
	line(x-30, y-17, x-1, y-17);
	line(x-30, y+17, x-1, y+17);
	line(x-30, y-17, x-30, y+17);
}

void or(int x,int y)
{
	ellipse(x, y, 0, 55,120, 30);
	ellipse(x, y, 305, 360,120, 30);
	ellipse(x+71, y, 0, 90,6, 23);
	ellipse(x+71, y, 270, 360,6, 23);
}

void not(int x,int y)
{
	line(x, y, x, y+25);
	line(x, y, x+30, y+12);
	line(x, y+25, x+30, y+12);
	circle(x+34, y+12, 4);
}

void nand(int x,int y)
{
	and(x,y);
	circle(x+19, y, 5);
}
void nor(int x,int y)
{
	or(x,y);
	circle(x+126, y, 5);
}

void xor(int x,int y)
{
	or(x,y);
	ellipse(x+61, y, 0, 90,6, 23);
	ellipse(x+61, y, 270, 360,6, 23);
}

void xnor(int x,int y)
{
	xor(x,y);
	circle(x+126, y, 5);
}

void or1(int x,int y)
{
	ellipse(x, y, 180, 360,25, 50);
	ellipse(x, y, 180, 360,25, 10);
}

void xor1(int x,int y)
{
	or1(x,y);
	ellipse(x,y-10,180,360,25,10);
}

void and1(int x,int y)
{
	ellipse(x, y, 180, 360,20, 17);
	line(x-20, y-25, x-20, y);
	line(x+20, y-25, x+20, y);
	line(x-20, y-25, x+20, y-25);
}
