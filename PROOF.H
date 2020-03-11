void commanproof(int col,int row,char name[]);
void endproof(void);
void xbar(int col,int row);
void ybar(int col,int row);
void xbar1(int col,int row);
void ybar1(int col,int row);
void negation(void)
{
	commanproof(100,6,"Involation Laws");
	setcolor(15);
	line(getmaxx()/2,75,getmaxx()/2,getmaxy()-75);
	line(15,getmaxy()-75,getmaxx()-15,getmaxy()-75);
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(280,150,"X = X");line(280,153,292,153);line(280,150,292,150);
	setcolor(0);
	settextstyle(2,0,6);
	outtextxy(250,190,"e.g     X = 1");
	outtextxy(240,230,"L.H.S    1 = 0");
	line(320,231,328,231);line(320,228,328,228);line(360,231,370,231);
	outtextxy(240,270,"     1 = X");
	outtextxy(250,330,"Hence Proved.");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void complementory(void)
{
	commanproof(50,6,"Complementory Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)      X +   = 1");xbar1(162,90);
	outtextxy(342,90,"b)      X .   = 0");xbar1(455,90);
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(72,140,"e.g  X = 1 then   = 0");xbar(225,140);
	outtextxy(42,180,"L.H.S     1 + 0 = 1");
	outtextxy(100,220,"L.H.S = R.H.S");
	// proof of b part.
	outtextxy(372,140,"e.g  X = 1 then   = 0");xbar(525,140);
	outtextxy(342,180,"L.H.S     1 . 0 = 0");
	outtextxy(400,220,"L.H.S = R.H.S");
	setcursorpos(x,y);
	cursoron();
	endproof();

}

void demorgan(void)
{
	commanproof(100,6,"De Morgan's Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)    X + Y  = ");line(95,90,160,90);
	xbar1(210,90);ybar1(260,90);outtextxy(240,90,".");
	outtextxy(342,90,"b)    X . Y  = ");line(400,90,450,90);
	xbar1(510,90);ybar1(570,90);outtextxy(540,90,"+");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(72,140,"e.g  X = 1 and Y = 0");
	outtextxy(42,180,"L.H.S    1 + 0 = 1 = 0");
	line(125,180,170,180);line(202,180,210,180);
	xbar(115,220);ybar(218,220);
	outtextxy(135,220,"= 0 and");outtextxy(238,220,"= 1");
	outtextxy(42,260,"R.H.S      0 . 1 = 0");
	outtextxy(100,300,"L.H.S = R.H.S");
	// proof of b part.
	outtextxy(372,140,"e.g  X = 1 and Y = 0");
	outtextxy(342,180,"L.H.S    1 . 0 = 0 = 1");
	line(425,180,467,180);line(499,180,507,180);
	xbar(415,220);ybar(518,220);
	outtextxy(435,220,"= 0 and");outtextxy(538,220,"= 1");
	outtextxy(342,260,"R.H.S      0 + 1 = 1");
	outtextxy(400,300,"L.H.S = R.H.S");
	setcursorpos(x,y);
	cursoron();
	endproof();

}

void associative(void)
{
	commanproof(100,6,"Associative Laws");
	setcolor(15);
	line(getmaxx()/2,75,getmaxx()/2,getmaxy()-75);
	line(15,getmaxy()-75,getmaxx()-15,getmaxy()-75);
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)    X + ( Y + Z ) =  ( X + Y ) + Z = X + Y + Z");
	outtextxy(42,220,"b)    X . ( Y . Z ) =  ( X . Y ) . Z = X . Y . Z");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(92,140,"In this case only open the Bracketes.");
	outtextxy(125,180,"X + Y + Z = X + Y + Z = X + Y + Z");
	// proof of b part.
	outtextxy(92,260,"In this case only open the Bracketes.");
	outtextxy(125,300,"X . Y . Z = X . Y . Z = X . Y . Z");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void absorption(void)
{
	commanproof(100,6,"Absorption Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)    X . ( X + Y ) = X");
	outtextxy(342,90,"b)   X + ( X . Y ) = X");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(92,140,"X . X + X . Y = X");
	outtextxy(92,180,"X + X . Y = X   (X.X=X)");
	outtextxy(102,220,"X ( 1 + Y ) = X");
	outtextxy(105,260,"X . 1 = X    (1+Y=1)");
	outtextxy(135,300,"X = X");
	// proof of b part.
	outtextxy(392,140,"X + X . Y = X");
	outtextxy(388,180,"X ( 1 + Y ) = X");
	outtextxy(398,220,"X . 1 = X    (1+Y=1)");
	outtextxy(415,260,"X = X");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void properties(void)
{
	commanproof(40,6,"Properties of 0 and 1");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)       X + 1 = 1");
	outtextxy(342,90,"b)       X . 0 = 0");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(62,140,"(X + 1) . 1 = 1    (X.1=X)");
	outtextxy(62,180,"(X + 1).(X + ) = 1  (X+ =1)");
	xbar(172,180);xbar(278,180);
	outtextxy(82,220,"X + 1 .  = 1");
	xbar(153,220);
	outtextxy(75,250,"X +   = 1        (1. = )");
	xbar(115,250);xbar(267,250);xbar(290,250);
	outtextxy(95,280,"1 = 1          (X+ =1)");
	xbar(273,280);
	// proof of b part.
	outtextxy(362,140,"X . 0 + 0 = 0     (X+0=X)");
	outtextxy(362,180,"X . 0 + X .  = 0   (X. =0)");
	xbar(468,180);xbar(567,180);
	outtextxy(382,220,"X ( 0 +   ) = 0");
	xbar(461,220);
	outtextxy(375,250,"X .   = 0        (0+ = )");
	xbar(415,250);xbar(567,250);xbar(588,250);
	outtextxy(405,280,"0 = 0         (X. =0)");
	xbar(570,280);
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void idempotent(void)
{
	commanproof(90,6,"Idempotent Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)       X + X = X");
	outtextxy(342,90,"b)       X . X = X");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(62,140,"(X + X) . 1 = X    (X.1=X)");
	outtextxy(62,180,"(X + X).(X + ) = X  (X+ =1)");
	xbar(172,180);xbar(278,180);
	outtextxy(82,220,"X + X .  = X");
	xbar(153,220);
	outtextxy(75,250,"X + 0 = X        (X. =0)");
	xbar(267,250);
	outtextxy(95,280,"X = X          (X+0=X)");
	// proof of b part.
	outtextxy(362,140,"X . X + 0 = X     (X+0=X)");
	outtextxy(362,180,"X . X + X .  = X   (X. =0)");
	xbar(468,180);xbar(567,180);
	outtextxy(382,220,"X ( X +   ) = X");
	xbar(461,220);
	outtextxy(375,250,"X . 1 = X        (X+ =1)");
	xbar(567,250);
	outtextxy(405,280,"X = X         (X.1=X)");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void distributive(void)
{
	commanproof(80,6,"Distributive Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(35,90,"a)   X+(Y.Z) = (X+Y).(X+Z)");
	outtextxy(342,90,"b)   X.(Y+Z) = X.Y + X.Z");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(62,140,"e.g     X=1, Y=2 and Z=3");
	outtextxy(40,170,"Put the values in this eq.");
	outtextxy(62,220,"1 + (2.3) = (1 + 2).(1 + 3)");
	outtextxy(112,250,"1 + 6 = 3 . 4");
	outtextxy(152,280,"7 = 7");
	// proof of b part.
	outtextxy(362,140,"e.g    X=1, Y=2 and Z=3");
	outtextxy(342,170,"Put the values in this eq.");
	outtextxy(360,220,"1 . (2 + 3) = 1 . 2 + 1 . 3");
	outtextxy(415,250,"1 . 5 = 2 + 3");
	outtextxy(450,280,"5 = 5");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void commutative(void)
{
	commanproof(62,6,"Commutative Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)     X + Y = Y + X");
	outtextxy(342,90,"b)     X . Y = Y . X");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(72,140,"e.g     X = 1 and Y = 2");
	outtextxy(40,170,"Put the values in this eq.");
	outtextxy(112,200,"1 + 2 = 2 + 1");
	outtextxy(152,250,"3 = 3");
	// proof of b part.
	outtextxy(372,140,"e.g     X = 1 and Y = 2");
	outtextxy(342,170,"Put the values in this eq.");
	outtextxy(412,200,"1 . 2 = 2 . 1");
	outtextxy(452,250,"2 = 2");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void identity(void)
{
	commanproof(132,6,"Identity Laws");
	setcolor(1);
	settextstyle(1,0,2);
	outtextxy(42,90,"a)        X + 0 = X");
	outtextxy(342,90,"b)        X . 1 = X");
	setcolor(0);
	settextstyle(2,0,6);
	// proof of a part.
	outtextxy(72,140,"X + X.  = X     ( 0=X.  )");
	xbar(130,140);
	xbar(290,140);
	outtextxy(72,180,"X (1 +  ) = X");
	xbar(135,180);
	outtextxy(72,220,"X . 1 = X       ( X+1=1 )");
	outtextxy(132,260,"X = X");
	// proof of b part.
	outtextxy(372,140,"X.( X +  ) = X   ( X+ =1 )");
	xbar(440,140);
	xbar(570,140);
	outtextxy(372,180,"X.X + X.  = X");
	xbar(445,180);
	outtextxy(362,220,"X + 0 = X  (X.X=X) (X. = 0)");
	xbar(568,220);
	outtextxy(432,260,"X = X");
	setcursorpos(x,y);
	cursoron();
	endproof();
}

void commanproof(int col,int row,char name[])
{
	comman3(0, 0, getmaxx(), getmaxy(), 11);
	comman(0, 0, getmaxx(), 75,9);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	setcolor(0);
	outtextxy(col,row,name);
	outtextxy(col+1,row+1,name);
	setcolor(14);
	outtextxy(col-1,row-2,name);
	outtextxy(col-2,row-2,name);
	comman3(15,76,getmaxx()-15,getmaxy()-15,15);

	line(getmaxx()/2,75,getmaxx()/2,getmaxy()-75);
	line(15,getmaxy()-75,getmaxx()-15,getmaxy()-75);
	comman(270,420,370,450,7);
	settextstyle(1,0,4);
	outtextxy(300,415,"Ok");
}

void endproof(void)
{
	int iop=0,flag=0;
	int button;
	while (iop != 1)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && x <= 370 && y >= 420 && y <= 450)
			{
				press1(270,420,370,450);
			}
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,420,370,450);
			delay(150);
			if (x >= 270 && x <= 370 && y >= 420 && y <= 450)
			{
				sound();
				iop=1;
				cursoroff();
			}
		}
	}
}

void xbar(int col,int row)
{
	outtextxy(col,row,"X");
	outtextxy(col,row-10,"-");
}

void ybar(int col,int row)
{
	outtextxy(col,row,"Y");
	outtextxy(col,row-10,"-");
}

void xbar1(int col,int row)
{
	outtextxy(col,row,"X");
	outtextxy(col+1,row-12,"-");
}

void ybar1(int col,int row)
{
	outtextxy(col,row,"Y");
	outtextxy(col+1,row-12,"-");
}
