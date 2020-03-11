/*	Function of Binary to Decimal Conversion	*/
void simplebd(void);
void fractionbd(void);
void simplebo(void);
void simplebh(void);

void simpledb(void);
void simpledo(void);
void simpledh(void);

void simpleob(void);
void simpleod(void);
void simpleoh(void);

void simplehb(void);

void simplebcd(void);

void errordisplay1(void);
void errordisplay2(void);

char get[20];
int button;

void bd(void)
{
	int button;
	int flag=0,chr=0;
	int btod=1,point=0;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(80,3,"Binary to Decimal");
		comman(65,100,575,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Binary Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=10)&&(ch!=8))
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
		comman2(cursor,115,550,145,9);

		for (i=0;i<strlen(get);i++)
			if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Binary Numbers use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	for (int i=0;i<strlen(get);i++)
		if (get[i] == '.')
			point = 1;
	if (point)
		fractionbd();
	else
		simplebd();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simplebd(void)
{
	int btod1=strlen(get),colbd=120,rowbd=180;
	int decimal=0,deci1;
	char chbd[1],getbd;
	settextstyle(1,0,2);
	outtextxy(100,180,"=");
	for (int i=0;i<strlen(get);i++)
	{
		getbd = get[i];
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"2");
		colbd+=12;rowbd-=12;
		btod1--;itoa(btod1, chbd, 10);
		settextstyle(1,0,1);
		outtextxy(colbd,rowbd,chbd);
		colbd+=12;rowbd+=15;
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"*");
		colbd+=10;rowbd-=3;
		settextstyle(1,0,2);
		if (getbd=='1')
		{
			outtextxy(colbd,rowbd,"1");
			deci1=1;
		}
		else
		{
			outtextxy(colbd,rowbd,"0");
			deci1=0;
		}
		colbd+=14;
		if (i==5)
		{
			rowbd=220;colbd=120;
		}
		if (btod1)
			outtextxy(colbd,rowbd,"+");
		colbd+=18;
		decimal+=pow(2,btod1)*deci1;
	}
	itoa(decimal,get,10);
	settextstyle(1,0,2);
	outtextxy(170,300,"Decimal Number is ");
	outtextxy(380,300,get);
}

void fractionbd(void)
{
	int btod1,colbd=120,rowbd=180;
	int decimal=0,deci1,i=0;
	char chbd[1],getbd;
	settextstyle(1,0,2);
	outtextxy(100,180,"=");
	while (get[i] != '.')
		i++;
	btod1=i;
	i=0;
	while(get[i] != '.')
	{
		getbd = get[i];
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"2");
		colbd+=12;rowbd-=12;
		btod1--;itoa(btod1, chbd, 10);
		settextstyle(1,0,1);
		outtextxy(colbd,rowbd,chbd);
		colbd+=12;rowbd+=15;
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"*");
		colbd+=10;rowbd-=3;
		settextstyle(1,0,2);
		if (getbd=='1')
		{
			outtextxy(colbd,rowbd,"1");
			deci1=1;
		}
		else
		{
			outtextxy(colbd,rowbd,"0");
			deci1=0;
		}
		colbd+=14;
		if (i==5)
		{
			rowbd=220;colbd=120;
		}
		if (btod1)
			outtextxy(colbd,rowbd,"+");
		colbd+=18;
		decimal+=pow(2,btod1)*deci1;
		i++;
	}
	colbd-=15;
	outtextxy(colbd,rowbd,".");colbd+=10;
	int local=1;
	float decimal1=0;
	char getfar[10];
	for (i++;i<strlen(get);i++)
	{
		getbd = get[i];
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"2");
		colbd+=12;rowbd-=12;
		itoa(local,chbd,10);local++;
		settextstyle(1,0,1);
		outtextxy(colbd,rowbd,"-");colbd+=13;
		outtextxy(colbd,rowbd,chbd);
		colbd+=12;rowbd+=15;
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"*");
		colbd+=10;rowbd-=3;
		settextstyle(1,0,2);
		if (getbd=='1')
		{
			outtextxy(colbd,rowbd,"1");
			deci1=1;
		}
		else
		{
			outtextxy(colbd,rowbd,"0");
			deci1=0;
		}
		colbd+=14;
		if (i==5)
		{
			rowbd=220;colbd=120;
		}
		if (i!=strlen(get)-1)
			outtextxy(colbd,rowbd,"+");
		colbd+=18;
		decimal1+=pow(2,-local)*deci1;
	}
	itoa(decimal1,getfar,10);
	itoa(decimal,get,10);
	i=strlen(get);
	get[i]='.';i++;
	get[i]='\0';
	settextstyle(1,0,2);
	outtextxy(170,300,"Decimal Number is ");
	outtextxy(380,300,get);
	setcolor(0);
	outtextxy(100,400,getfar);
}

/*	Function of Binary to Octal Conversion		*/

void bo(void)
{
	int button;
	int flag=0,chr=0;
	int btod=1;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(110,3,"Binary to Octal");
		comman(25,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Binary Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=15)&&(ch!=8))
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
			cursor+=13;
			setcolor(15);
			comman2(380,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Binary Numbers use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simplebo();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simplebo(void)
{
	int temp1=0,no=strlen(get)-1,rowbo=170,colbo=575,rowbo1=200,temp=0,botemp=0,displayrow=230,displaycol=545;
	char chbo,chtemp[1],gettemp[10],gettemp1[10];
	for (int i=0;i<strlen(get);i++)
	{
		chbo=get[no];
		no--;
		if (chbo=='1')
		{
			if (temp==0)
				temp1+=1;
			if (temp==1)
				temp1+=2;
			if (temp==2)
				temp1+=4;
			outtextxy(colbo,rowbo,"1");
		}
		else
			outtextxy(colbo,rowbo,"0");
		if (temp==0)
			outtextxy(colbo,rowbo1,"1");
		if (temp==1)
			outtextxy(colbo,rowbo1,"2");
		if (temp==2)
		{
			outtextxy(colbo,rowbo1,"4");
			itoa(temp1,chtemp,10);
			temp1=0;
			outtextxy(displaycol,displayrow,chtemp);
			displaycol-=120;
			gettemp1[botemp]=chtemp[0];
			gettemp1[botemp+1]='\0';
			botemp++;
		}
		temp++;
		if ((i==2)||(i==5)||(i==8)||(i==11))
		{
			temp=0;
			colbo-=60;
		}
		else
			colbo-=30;
	}
	if ((strlen(get)==1)||(strlen(get)==4)||(strlen(get)==7)||(strlen(get)==10)||(strlen(get)==13))
	{
		for (i=0;i<2;i++)
		{
			itoa(temp1,chtemp,10);
			outtextxy(displaycol,displayrow,chtemp);
			gettemp1[botemp]=chtemp[0];
			gettemp1[botemp+1]='\0';
			outtextxy(colbo,rowbo,"0");
			if (temp==1)
				outtextxy(colbo,rowbo1,"2");
			if (temp==2)
				outtextxy(colbo,rowbo1,"4");
			temp++;
			colbo-=30;
		}
	}
	if ((strlen(get)==2)||(strlen(get)==5)||(strlen(get)==8)||(strlen(get)==11)||(strlen(get)==14))
	{
		itoa(temp1,chtemp,10);
		outtextxy(displaycol,displayrow,chtemp);
		gettemp1[botemp]=chtemp[0];
		gettemp1[botemp+1]='\0';
		outtextxy(colbo,rowbo1,"4");
		outtextxy(colbo,rowbo,"0");
		colbo-=30;
	}
	gettemp[strlen(gettemp1)]='\0';
	for (i=0;i<strlen(gettemp1);i++)
		gettemp[strlen(gettemp1)-i-1]=gettemp1[i];
	outtextxy(180,280,"Octal Number is");
	outtextxy(360,280,gettemp);
}

/*	Function of Binary to HexaDecimal Convertion	*/

void bh(void)
{
	int button;
	int flag=0,chr=0;
	int btod=1;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(60,10,"Binary to HexaDecimal");
		comman(35,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Binary Number : ");
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=16)&&(ch!=8))
				sound();
			else
			{
			get[i] = ch;
			get[i+1] = '\0';
			if (ch==8)
			{
				i--;
				get[i] = '\0';
				i--;
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(380,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Binary Numbers use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simplebh();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simplebh(void)
{
	int temp1=0,no=strlen(get)-1,rowbo=170,colbo=575,rowbo1=200,temp=0,botemp=0,displayrow=230,displaycol=535;
	char chbo,chtemp[2],gettemp[10],gettemp1[10];
	for (int i=0;i<strlen(get);i++)
	{
		chbo=get[no];
		no--;
		if (chbo=='1')
		{
			if (temp==0)
				temp1+=1;
			if (temp==1)
				temp1+=2;
			if (temp==2)
				temp1+=4;
			if (temp==3)
				temp1+=8;
			outtextxy(colbo,rowbo,"1");
		}
		else
			outtextxy(colbo,rowbo,"0");
		if (temp==0)
			outtextxy(colbo,rowbo1,"1");
		if (temp==1)
			outtextxy(colbo,rowbo1,"2");
		if (temp==2)
			outtextxy(colbo,rowbo1,"4");
		if (temp==3)
		{
			outtextxy(colbo,rowbo1,"8");
			if ((temp1>=0)&&(temp1<=9))
				itoa(temp1,chtemp,10);
			if (temp1==10)
				chtemp[0]='A';
			if (temp1==11)
				chtemp[0]='B';
			if (temp1==12)
				chtemp[0]='C';
			if (temp1==13)
				chtemp[0]='D';
			if (temp1==14)
				chtemp[0]='E';
			if (temp1==15)
				chtemp[0]='F';
			chtemp[1]='\0';
			outtextxy(displaycol,displayrow,chtemp);
			displaycol-=140;
			temp1=0;
			gettemp1[botemp]=chtemp[0];
			gettemp1[botemp+1]='\0';
			botemp++;
		}
		temp++;
		if ((i==3)||(i==7)||(i==11)||(i==15))
		{
			temp=0;
			colbo-=50;
		}
		else
			colbo-=30;
	}
	if ((strlen(get)==1)||(strlen(get)==5)||(strlen(get)==9)||(strlen(get)==13))
	{
		for (i=0;i<3;i++)
		{
			if ((temp1>=0)&&(temp1<=9))
				itoa(temp1,chtemp,10);
			if (temp1==10)
				chtemp[0]='A';
			if (temp1==11)
				chtemp[0]='B';
			if (temp1==12)
				chtemp[0]='C';
			if (temp1==13)
				chtemp[0]='D';
			if (temp1==14)
				chtemp[0]='E';
			if (temp1==15)
				chtemp[0]='F';
			chtemp[1]='\0';
			outtextxy(displaycol,displayrow,chtemp);
			gettemp1[botemp]=chtemp[0];
			gettemp1[botemp+1]='\0';
			outtextxy(colbo,rowbo,"0");
			if (temp==1)
				outtextxy(colbo,rowbo1,"2");
			if (temp==2)
				outtextxy(colbo,rowbo1,"4");
			if (temp==3)
				outtextxy(colbo,rowbo1,"8");
			temp++;
			colbo-=30;
		}
	}
	if ((strlen(get)==2)||(strlen(get)==6)||(strlen(get)==10)||(strlen(get)==14))
	{
		for (i=0;i<2;i++)
		{
			if ((temp1>=0)&&(temp1<=9))
				itoa(temp1,chtemp,10);
			if (temp1==10)
				chtemp[0]='A';
			if (temp1==11)
				chtemp[0]='B';
			if (temp1==12)
				chtemp[0]='C';
			if (temp1==13)
				chtemp[0]='D';
			if (temp1==14)
				chtemp[0]='E';
			if (temp1==15)
				chtemp[0]='F';
			chtemp[1]='\0';
			outtextxy(displaycol,displayrow,chtemp);
			gettemp1[botemp]=chtemp[0];
			gettemp1[botemp+1]='\0';
			outtextxy(colbo,rowbo,"0");
			if (temp==1)
				outtextxy(colbo,rowbo1,"2");
			if (temp==2)
				outtextxy(colbo,rowbo1,"4");
			if (temp==3)
				outtextxy(colbo,rowbo1,"8");
			temp++;
			colbo-=30;
		}
	}
	if ((strlen(get)==3)||(strlen(get)==7)||(strlen(get)==11)||(strlen(get)==15))
	{
			if ((temp1>=0)&&(temp1<=9))
				itoa(temp1,chtemp,10);
			if (temp1==10)
				chtemp[0]='A';
			if (temp1==11)
				chtemp[0]='B';
			if (temp1==12)
				chtemp[0]='C';
			if (temp1==13)
				chtemp[0]='D';
			if (temp1==14)
				chtemp[0]='E';
			if (temp1==15)
				chtemp[0]='F';
			chtemp[1]='\0';
		outtextxy(displaycol,displayrow,chtemp);
		gettemp1[botemp]=chtemp[0];
		gettemp1[botemp+1]='\0';
		outtextxy(colbo,rowbo1,"8");
		outtextxy(colbo,rowbo,"0");
		colbo-=30;
	}
	gettemp[strlen(gettemp1)]='\0';
	for (i=0;i<strlen(gettemp1);i++)
		gettemp[strlen(gettemp1)-i-1]=gettemp1[i];
	outtextxy(130,280,"HexaDecimal Number is");
	outtextxy(380,280,gettemp);
}

/*	Function of Decimal to Binary Conversion	*/

void db(void)
{
	int button;
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(80,3,"Decimal to Binary");
		comman(65,100,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,110,"Enter the Decimal Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,117,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=10)&&(ch!=8))
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
			comman2(380,105,550,145,9);
			outtextxy(cursor,117,"-");
			settextstyle(8,0,1);
			outtextxy(385, 110, get);
			i++;
			}
	}

		for (i=0;i<strlen(get);i++)
			if ((get[i] < '0')||(get[i] > '9'))
			{
				dtob=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Decimal Numbers use only 0 to 9 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simpledb();
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simpledb(void)
{
	int colbd=110,rowbd=170;
	int decimal,remainder;
	char chbd[1],gettemp[20],gettempdb[20];
	decimal=atoi(get);
	if (decimal<0)
		decimal=-decimal;
	settextstyle(1,0,2);
	outtextxy(100,140,"  N/2         Quotient       Remainder");
	outtextxy(90,150,"컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");
	int i=0;
	while (decimal>0)
	{
//		itoa(decimal,get,10);
		settextstyle(2,0,6);
		outtextxy(colbd,rowbd,get);
		if (strlen(get)==1)
			colbd+=4;
		if (strlen(get)==2)
			colbd+=16;
		if (strlen(get)==3)
			colbd+=20;
		if (strlen(get)==4)
			colbd+=30;
		if (strlen(get)==5)
			colbd+=40;
		if (strlen(get)==6)
			colbd+=50;
		if (strlen(get)==7)
			colbd+=60;
		if (strlen(get)==8)
			colbd+=70;
		if (strlen(get)==9)
			colbd+=80;
		if (strlen(get)==10)
			colbd+=90;
		outtextxy(colbd,rowbd," /2");

		colbd=460;
		remainder=decimal%2;
		if (remainder==1)
		{
			outtextxy(colbd,rowbd,"1");
			gettemp[i]='1';
		}
		else
		{
			outtextxy(colbd,rowbd,"0");
			gettemp[i]='0';
		}

		colbd=280;
		decimal=decimal/2;
		itoa(decimal,get,10);
		outtextxy(colbd,rowbd,get);
		if ((i==9)||(i==17))
		{
			setcolor(0);
			outtextxy(240,370,"Hit any Key!!!!!");
			getch();
			setcolor(15);
			comman2(105,170,550,400,9);
			rowbd=150;
		}
		i++;
		rowbd+=20;colbd=110;
	}
	gettemp[i]='\0';
	if (rowbd>300)
		rowbd+=10;
	else
		rowbd+=30;
	gettempdb[strlen(gettemp)]='\0';
	for (i=0;i<strlen(gettemp);i++)
		gettempdb[strlen(gettemp)-i-1]=gettemp[i];
	settextstyle(1,0,2);
	outtextxy(140,rowbd,"Binary Number is");
	outtextxy(330,rowbd,gettempdb);
}

/*	Function of Decimal to Octal Conversion		*/

void deoc(void)
{
	int button;
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(100,3,"Decimal to Octal");
		comman(65,100,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,110,"Enter the Decimal Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,117,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			 if ((i>=10)&&(ch!=8))
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
			comman2(380,105,550,145,9);
			outtextxy(cursor,117,"-");
			settextstyle(8,0,1);
			outtextxy(385, 110, get);
			i++;
			}
	}
	comman2(cursor,115,548,145,9);
	for (i=0;i<strlen(get);i++)
		if ((get[i] < '0')||(get[i] > '9'))
		{
			dtob=1;
			desion2();
			settextstyle(8,0,4);
			outtextxy(123,135,"<ERROR>");
			settextstyle(2,0,5);
			outtextxy(220,200,"Decimal Numbers use only 0 to 9 Digits");
			outtextxy(240,220,"You are Worng enter the Number");
			outtextxy(310,240,"Try Again");
			comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
			setcolor(0);
			settextstyle(1,0,4);
			outtextxy(getmaxx()/2-20,265,"Ok");
			i = 0;
			setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simpledo();
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simpledo(void)
{
	int colbd=110,rowbd=170;
	int decimal,remainder;
	char chbd[1],gettemp[20],gettempdo[20];
	decimal=atoi(get);
	if (decimal<0)
		decimal=-decimal;
	settextstyle(1,0,2);
	outtextxy(100,140,"  N/8         Quotient       Remainder");
	outtextxy(90,150,"컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");
	int i=0;
	while (decimal>0)
	{
//		itoa(decimal,get,10);
		settextstyle(2,0,6);
		outtextxy(colbd,rowbd,get);
		if (strlen(get)==1)
			colbd+=4;
		if (strlen(get)==2)
			colbd+=16;
		if (strlen(get)==3)
			colbd+=20;
		if (strlen(get)==4)
			colbd+=30;
		if (strlen(get)==5)
			colbd+=40;
		if (strlen(get)==6)
			colbd+=50;
		if (strlen(get)==7)
			colbd+=60;
		if (strlen(get)==8)
			colbd+=70;
		if (strlen(get)==9)
			colbd+=80;
		if (strlen(get)==10)
			colbd+=90;
		outtextxy(colbd,rowbd," /8");

		colbd=460;
		remainder=decimal%8;
		if (remainder==0)
		{
			outtextxy(colbd,rowbd,"0");
			gettemp[i]='0';
		}
		if (remainder==1)
		{
			outtextxy(colbd,rowbd,"1");
			gettemp[i]='1';
		}
		if (remainder==2)
		{
			outtextxy(colbd,rowbd,"2");
			gettemp[i]='2';
		}
		if (remainder==3)
		{
			outtextxy(colbd,rowbd,"3");
			gettemp[i]='3';
		}
		if (remainder==4)
		{
			outtextxy(colbd,rowbd,"4");
			gettemp[i]='4';
		}
		if (remainder==5)
		{
			outtextxy(colbd,rowbd,"5");
			gettemp[i]='5';
		}
		if (remainder==6)
		{
			outtextxy(colbd,rowbd,"6");
			gettemp[i]='6';
		}
		if (remainder==7)
		{
			outtextxy(colbd,rowbd,"7");
			gettemp[i]='7';
		}

		colbd=280;
		decimal=decimal/8;
		itoa(decimal,get,10);
		outtextxy(colbd,rowbd,get);
		if ((i==9)||(i==17))
		{
			setcolor(0);
			outtextxy(240,370,"Hit any Key!!!!!");
			getch();
			setcolor(15);
			comman2(105,170,550,400,9);
			rowbd=150;
		}
		i++;
		rowbd+=20;colbd=110;
	}
	gettemp[i]='\0';
	if (rowbd>300)
		rowbd+=10;
	else
		rowbd+=30;
	gettempdo[strlen(gettemp)]='\0';
	for (i=0;i<strlen(gettemp);i++)
		gettempdo[strlen(gettemp)-i-1]=gettemp[i];
	settextstyle(1,0,2);
	outtextxy(150,rowbd,"Octal Number is");
	outtextxy(330,rowbd,gettempdo);
}

/*	Function of Decimal to HexaDecimal Conversion		*/

void dh(void)
{
	int button;
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(60,10,"Decimal to HexaDecimal");
		comman(65,100,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,110,"Enter the Decimal Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,117,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=10)&&(ch!=8))
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
			comman2(380,105,550,145,9);
			outtextxy(cursor,117,"-");
			settextstyle(8,0,1);
			outtextxy(385, 110, get);
			i++;
			}
	}
	comman2(cursor,115,548,145,9);
	for (i=0;i<strlen(get);i++)
		if ((get[i] < '0')||(get[i] > '9'))
		{
			dtob=1;
			desion2();
			settextstyle(8,0,4);
			outtextxy(123,135,"<ERROR>");
			settextstyle(2,0,5);
			outtextxy(220,200,"Decimal Numbers use only 0 to 9 Digits");
			outtextxy(240,220,"You are Worng enter the Number");
			outtextxy(310,240,"Try Again");
			comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
			setcolor(0);
			settextstyle(1,0,4);
			outtextxy(getmaxx()/2-20,265,"Ok");
			i = 0;
			setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simpledh();
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simpledh(void)
{
	int colbd=110,rowbd=170;
	int decimal,remainder;
	char chbd[1],gettemp[20],gettempdo[20];
	decimal=atoi(get);
	if (decimal<0)
		decimal=-decimal;
	settextstyle(1,0,2);
	outtextxy(100,140,"  N/16         Quotient       Remainder");
	outtextxy(90,150,"컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴");
	int i=0;
	while (decimal>0)
	{
//		itoa(decimal,get,10);
		settextstyle(2,0,6);
		outtextxy(colbd,rowbd,get);
		if (strlen(get)==1)
			colbd+=4;
		if (strlen(get)==2)
			colbd+=16;
		if (strlen(get)==3)
			colbd+=20;
		if (strlen(get)==4)
			colbd+=30;
		if (strlen(get)==5)
			colbd+=40;
		if (strlen(get)==6)
			colbd+=50;
		if (strlen(get)==7)
			colbd+=60;
		if (strlen(get)==8)
			colbd+=70;
		if (strlen(get)==9)
			colbd+=80;
		if (strlen(get)==10)
			colbd+=90;
		outtextxy(colbd,rowbd," /16");

		colbd=460;
		remainder=decimal%16;
		if (remainder==0)
		{
			outtextxy(colbd,rowbd,"0");
			gettemp[i]='0';
		}
		if (remainder==1)
		{
			outtextxy(colbd,rowbd,"1");
			gettemp[i]='1';
		}
		if (remainder==2)
		{
			outtextxy(colbd,rowbd,"2");
			gettemp[i]='2';
		}
		if (remainder==3)
		{
			outtextxy(colbd,rowbd,"3");
			gettemp[i]='3';
		}
		if (remainder==4)
		{
			outtextxy(colbd,rowbd,"4");
			gettemp[i]='4';
		}
		if (remainder==5)
		{
			outtextxy(colbd,rowbd,"5");
			gettemp[i]='5';
		}
		if (remainder==6)
		{
			outtextxy(colbd,rowbd,"6");
			gettemp[i]='6';
		}
		if (remainder==7)
		{
			outtextxy(colbd,rowbd,"7");
			gettemp[i]='7';
		}
		if (remainder==8)
		{
			outtextxy(colbd,rowbd,"8");
			gettemp[i]='8';
		}
		if (remainder==9)
		{
			outtextxy(colbd,rowbd,"9");
			gettemp[i]='9';
		}
		if (remainder==10)
		{
			outtextxy(colbd,rowbd,"A");
			gettemp[i]='A';
		}
		if (remainder==11)
		{
			outtextxy(colbd,rowbd,"B");
			gettemp[i]='B';
		}
		if (remainder==12)
		{
			outtextxy(colbd,rowbd,"C");
			gettemp[i]='C';
		}
		if (remainder==13)
		{
			outtextxy(colbd,rowbd,"D");
			gettemp[i]='D';
		}
		if (remainder==14)
		{
			outtextxy(colbd,rowbd,"E");
			gettemp[i]='E';
		}
		if (remainder==15)
		{
			outtextxy(colbd,rowbd,"F");
			gettemp[i]='F';
		}

		colbd=280;
		decimal=decimal/16;
		itoa(decimal,get,10);
		outtextxy(colbd,rowbd,get);
		if ((i==9)||(i==17))
		{
			setcolor(0);
			outtextxy(240,370,"Hit any Key!!!!!");
			getch();
			setcolor(15);
			comman2(105,170,550,400,9);
			rowbd=150;
		}
		i++;
		rowbd+=20;colbd=110;
	}
	gettemp[i]='\0';
	if (rowbd>300)
		rowbd+=10;
	else
		rowbd+=30;
	gettempdo[strlen(gettemp)]='\0';
	for (i=0;i<strlen(gettemp);i++)
		gettempdo[strlen(gettemp)-i-1]=gettemp[i];
	settextstyle(1,0,2);
	outtextxy(100,rowbd,"HexaDecimal Number is");
	outtextxy(360,rowbd,gettempdo);
}

/*	Function of Octal to Binary Conversion		*/

void ob(void)
{
get[0]='\0';
	int flag=0,chr=0,button;
	int btod=1;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(110,3,"Octal to Binary");
		comman(25,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Octal Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		char ch;
		int i=0,cursor=365;
		outtextxy(cursor,127,"-");
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=5)&&(ch!=8))
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
			cursor+=13;
			setcolor(15);
			comman2(360,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(365, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
		if ((get[i] < '0')||(get[i] > '7'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Octal Numbers use only 0 to 7 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simpleob();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simpleob(void)
{
	int no,rowbo=170,colbo=70,rowbo1=200,colbo1=40,no1=0;
	char chbo[1],chtemp[1],gettemp[15];
	for (int i=0;i<strlen(get);i++)
	{
		chbo[0]=get[i];
		no = atoi(chbo);
		itoa(no,chtemp,10);
		outtextxy(colbo,rowbo,chtemp);
		colbo+=120;

		outtextxy(colbo1,rowbo1,"4");
		if ((no==4)||(no==5)||(no==6)||(no==7))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"2");
		no1++;
		if ((no==2)||(no==3)||(no==6)||(no==7))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"1");
		no1++;
		if ((no==1)||(no==3)||(no==5)||(no==7))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		no1++;
		colbo1+=60;
	}
	gettemp[no1]='\0';
	outtextxy(100,300,"Binary Number is");
	outtextxy(300,300,gettemp);
}

/*	Function of Octal to Decimal Conversion		*/

void od(void)
{
	int flag=0,chr=0;
	int btod=1,button;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(110,3,"Octal to Decimal");
		comman(25,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Octal Number : ");
/*	bingetint(get, 370,120);
	itoa(get1, get, 10);
	outtextxy(100,100,get);*/
		get[0]='\0';
		Flush();
		char ch;
		int i=0,cursor=365;
		outtextxy(cursor,127,"-");
		while ((ch=getch()) != 13)
		{
			if ((i>=5)&&(ch!=8))
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
			cursor+=13;
			setcolor(15);
			comman2(360,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(365, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
		if ((get[i] < '0')||(get[i] > '7'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Octal Numbers use only 0 to 7 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simpleod();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simpleod(void)
{
	int btod1=strlen(get),colbd=120,rowbd=180;
	int decimal=0,decimal1=0,deci1,col1=120;
	char chbd[1],getbd,getnum[10];
	settextstyle(1,0,2);
	outtextxy(100,180,"=");
	outtextxy(100,250,"=");
	for (int i=0;i<strlen(get);i++)
	{
		getbd = get[i];
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"8");
		colbd+=12;rowbd-=12;
		btod1--;itoa(btod1, chbd, 10);
		settextstyle(1,0,1);
		outtextxy(colbd,rowbd,chbd);
		colbd+=12;rowbd+=15;
		settextstyle(1,0,2);
		outtextxy(colbd,rowbd,"*");
		colbd+=10;rowbd-=3;
		settextstyle(1,0,2);
		if (getbd=='0')
		{
			outtextxy(colbd,rowbd,"0");
			deci1=0;
		}
		if (getbd=='1')
		{
			outtextxy(colbd,rowbd,"1");
			deci1=1;
		}
		if (getbd=='2')
		{
			outtextxy(colbd,rowbd,"2");
			deci1=2;
		}
		if (getbd=='3')
		{
			outtextxy(colbd,rowbd,"3");
			deci1=3;
		}
		if (getbd=='4')
		{
			outtextxy(colbd,rowbd,"4");
			deci1=4;
		}
		if (getbd=='5')
		{
			outtextxy(colbd,rowbd,"5");
			deci1=5;
		}
		if (getbd=='6')
		{
			outtextxy(colbd,rowbd,"6");
			deci1=6;
		}
		if (getbd=='7')
		{
			outtextxy(colbd,rowbd,"7");
			deci1=7;
		}
		colbd+=14;
		if (i==5)
		{
			rowbd=220;colbd=120;
		}
		if (btod1)
			outtextxy(colbd,rowbd,"+");
		colbd+=18;
		decimal1=pow(8,btod1)*deci1;
		itoa(decimal1,getnum,10);
		outtextxy(col1,250,getnum);
		col1+=70;
		if (btod1)
			outtextxy(col1,250,"+");
		col1+=20;
		decimal+=decimal1;
	}
	itoa(decimal,get,10);
	settextstyle(1,0,2);
	outtextxy(170,300,"Decimal Number is ");
	outtextxy(380,300,get);
}

/*	Function of HexaDecimal to Binary Convertion	*/

void hb(void)
{
	int button;
	int flag=0,chr=0;
	int btod=1;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(60,10,"HexaDecimal to Binary");
		comman(35,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Hexa Number : ");
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=4)&&(ch!=8))
				sound();
			else
			{
			get[i] = ch;
			get[i+1] = '\0';
			if (ch==8)
			{
				i--;
				get[i] = '\0';
				i--;
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(380,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] >='0'&&get[i] <= '9')||((get[i] >= 'A')&&(get[i] <= 'F'))||(get[i] >= 'a')&&(get[i] <= 'f'))
			{}//Dummy
			else
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(230,190,"HexaDecimal Numbers use only 0 to 9");
				outtextxy(300,210," and A to F Digits");
				outtextxy(240,230,"You are Worng enter the Number");
				outtextxy(310,250,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simplehb();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simplehb(void)
{
	int no,rowbo=170,colbo=85,rowbo1=200,colbo1=40,no1=0;
	char chbo[1],chtemp[1],gettemp[15];
	for (int i=0;i<strlen(get);i++)
	{
		chbo[0]=get[i];
		chbo[1]='\0';
		outtextxy(colbo,rowbo,chbo);

		colbo+=150;

		outtextxy(colbo1,rowbo1,"8");
		if ((get[i] >='8'&&get[i] <= '9')||((get[i] >= 'A')&&(get[i] <= 'F'))||(get[i] >= 'a')&&(get[i] <= 'f'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"4");
		no1++;
		if ((get[i] >='4'&&get[i] <= '7')||((get[i] >= 'C')&&(get[i] <= 'F'))||(get[i] >= 'c')&&(get[i] <= 'f'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"2");
		no1++;
		if ((get[i]=='2')||(get[i]=='3')||(get[i]=='6')||(get[i]=='7')||(get[i]=='A')||(get[i]=='a')||(get[i]=='B')||(get[i]=='b')||(get[i]=='E')||(get[i]=='e')||(get[i]=='F')||(get[i]=='f'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"1");
		no1++;
		if ((get[i]=='1')||(get[i]=='3')||(get[i]=='5')||(get[i]=='7')||(get[i]=='9')||(get[i]=='B')||(get[i]=='b')||(get[i]=='D')||(get[i]=='d')||(get[i]=='F')||(get[i]=='f'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		no1++;
		colbo1+=60;
	}
	gettemp[no1]='\0';
	outtextxy(100,300,"Binary Number is");
	outtextxy(300,300,gettemp);
}

/*	Function of Decimal to BCD convertion	*/

void dbcd(void)
{
	int button;
	int flag=0,chr=0;
	int btod=1;
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(140,10,"Decimal to BCD");
		comman(35,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Decimal Number : ");
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=5)&&(ch!=8))
				sound();
			else
			{
			get[i] = ch;
			get[i+1] = '\0';
			if (ch==8)
			{
				i--;
				get[i] = '\0';
				i--;
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(380,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] >='0'&&get[i] <= '9'))
			{}//Dummy
			else
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Decimal Numbers use only 0 to 9 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	simplebcd();
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void simplebcd(void)
{
	int no,rowbo=170,colbo=85,rowbo1=200,colbo1=40,no1=0;
	char chbo[1],chtemp[1],gettemp[15];
	for (int i=0;i<strlen(get);i++)
	{
		chbo[0]=get[i];
		chbo[1]='\0';
		outtextxy(colbo,rowbo,chbo);

		colbo+=150;

		outtextxy(colbo1,rowbo1,"8");
		if ((get[i] >='8'&&get[i] <= '9'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"4");
		no1++;
		if ((get[i] >='4'&&get[i] <= '7'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"2");
		no1++;
		if ((get[i]=='2')||(get[i]=='3')||(get[i]=='6')||(get[i]=='7'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		colbo1+=30;
		outtextxy(colbo1,rowbo1,"1");
		no1++;
		if ((get[i]=='1')||(get[i]=='3')||(get[i]=='5')||(get[i]=='7')||(get[i]=='9'))
		{
			outtextxy(colbo1,230,"1");
			gettemp[no1]='1';
		}
		else
		{
			outtextxy(colbo1,230,"0");
			gettemp[no1]='0';
		}
		no1++;
		colbo1+=60;
	}
	gettemp[no1]='\0';
	outtextxy(130,300,"BCD Number is");
	outtextxy(300,300,gettemp);
}

/*	Function of Decimal to Biquinary Convertion	*/

void dbiq(void)
{
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Decimal to Biquinary");
		comman(65,80,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,90,"Enter the Decimal Number : ");
		char ch;
		int i=0,cursor=385,a;
		outtextxy(cursor,97,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=8)&&(ch!=8))
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
				comman2(380,95,550,145,9);
				outtextxy(cursor,97,"-");
				settextstyle(8,0,1);
				outtextxy(385, 90, get);
				i++;
			}
		}

		for (i=0;i<strlen(get);i++)
			if ((get[i] < '0')||(get[i] > '9'))
			{
				dtob=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Decimal Numbers use only 0 to 9 Digits");
				outtextxy(220,220,"You are Worng enter the Number.");
				outtextxy(320,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
// Variable of Tempary Declartion
	int temp,rrow;
	char tempchar[2];

	setcolor(0);
	outtextxy(220,120,"Biquinary Code");
	rectangle(85,150,530,176);
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(90,153,"Decimal");
	outtextxy(190,153,"5    0");
	outtextxy(310,153,"4    3    2    1    0");
	temp=strlen(get);rrow=176;
	tempchar[1]='\0';
	for (int i=0;i<temp;i++)
	{
		setcolor(0);
		rectangle(85,rrow,530,rrow+26);
		setcolor(15);
		tempchar[0]=get[i];
		outtextxy(120,rrow+5,tempchar);
		if (tempchar[0]=='0')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    0    0    0    1");
		}
		if (tempchar[0]=='1')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    0    0    1    0");
		}
		if (tempchar[0]=='2')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    0    1    0    0");
		}
		if (tempchar[0]=='3')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    1    0    0    0");
		}
		if (tempchar[0]=='4')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"1    0    0    0    0");
		}
		if (tempchar[0]=='5')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    0    0    0    1");
		}
		if (tempchar[0]=='6')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    0    0    1    0");
		}
		if (tempchar[0]=='7')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    0    1    0    0");
		}
		if (tempchar[0]=='8')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    1    0    0    0");
		}
		if (tempchar[0]=='9')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"1    0    0    0    0");
		}
		rrow+=26;
	}
	setcolor(0);
	line(170,150,170,rrow);
	line(280,150,280,rrow);
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

/*	Function of Biquinary to Decimal Convertion	*/

void biqd(void)
{
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Biquinary to Decimal");
		comman(65,100,580,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,110,"Enter the Biquinary Number : ");
		int rcol=400;
		setcolor(0);
		for (int i=0;i<8;i++)
		{
			rectangle(rcol,115,rcol+22,135);
			rcol+=22;
		}
		char ch,tempchr[2];
		setcolor(15);
		outtextxy(450,112,"-");
		i=0;tempchr[1]='\0';rcol=405;
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			get[i] = ch;
			tempchr[0]=ch;
			get[i+1] = '\0';
			setcolor(15);
			settextstyle(8,0,1);
			outtextxy(rcol,110, tempchr);
			i++;
			if (i==2)
				rcol+=48;
			else
				rcol+=22;
		}
		int count=9;
		for (i=2;i<strlen(get);i++)
			if (get[i]=='1')
				if (count==9)
					count=1;
				else
					count++;
		if ((get[0] == '1')&&(get[1] == '1'))
		{
			dtob=1;
			errordisplay1();
		}
		else
			if (count > 1)
			{
				dtob=1;
				errordisplay1();
			}
			else
				if (strlen(get)<7)
				{
					dtob=1;
					errordisplay1();
				}
				else
				for (i=0;i<strlen(get);i++)
					if ((get[i] < '0')||(get[i] > '1'))
				{
					dtob=1;
					errordisplay1();
				}
	}
	settextstyle(8,0,4);
	setcolor(15);
	outtextxy(100,250,"Decimal Number is");
	if (!strcmp(get,"0100001"))
		outtextxy(460,250,"0");
	if (!strcmp(get,"0100010"))
		outtextxy(460,250,"1");
	if (!strcmp(get,"0100100"))
		outtextxy(460,250,"2");
	if (!strcmp(get,"0101000"))
		outtextxy(460,250,"3");
	if (!strcmp(get,"0110000"))
		outtextxy(460,250,"4");
	if (!strcmp(get,"1000001"))
		outtextxy(460,250,"5");
	if (!strcmp(get,"1000010"))
		outtextxy(460,250,"6");
	if (!strcmp(get,"1000100"))
		outtextxy(460,250,"7");
	if (!strcmp(get,"1001000"))
		outtextxy(460,250,"8");
	if (!strcmp(get,"1010000"))
		outtextxy(460,250,"9");

	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void errordisplay1(void)
{
	desion2();
	settextstyle(8,0,4);
	outtextxy(123,135,"<ERROR>");
	settextstyle(2,0,5);
	outtextxy(200,190,"Biquinary Code use only 0 and 1 Digits.");
	outtextxy(200,210,"The length of Biquinary Code is 7-Bit.");
	outtextxy(220,230,"You are one Bit ON in each part.");
	outtextxy(220,250,"You are Worng enter the Number.");
	comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
	setcolor(0);
	settextstyle(1,0,4);
	outtextxy(getmaxx()/2-20,265,"Ok");
	int i = 0,flag;
	setcursorpos(getmaxx( )/2,getmaxy()/2);
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

/*	Function of Decimal to Quibinary Convertion	*/

void dqui(void)
{
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Decimal to Quibinary");
		comman(65,80,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,90,"Enter the Decimal Number : ");
		char ch;
		int i=0,cursor=385,a;
		outtextxy(cursor,97,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i==8)&&(ch!=8))
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
				comman2(380,105,550,145,9);
				outtextxy(cursor,97,"-");
				settextstyle(8,0,1);
				outtextxy(385, 90, get);
				i++;
			}
		}

		for (i=0;i<strlen(get);i++)
			if ((get[i] < '0')||(get[i] > '9'))
			{
				dtob=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Decimal Numbers use only 0 to 9 Digits");
				outtextxy(220,220,"You are Worng enter the Number.");
				outtextxy(320,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
// Variable of Tempary Declartion
	int temp,rrow;
	char tempchar[2];

	setcolor(0);
	outtextxy(220,120,"Quibinary Code");
	rectangle(85,150,530,176);
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(90,153,"Decimal");
	outtextxy(190,153,"0    1");
	outtextxy(310,153,"0    2    4    6    8");
	temp=strlen(get);rrow=176;
	tempchar[1]='\0';
	for (int i=0;i<temp;i++)
	{
		setcolor(0);
		rectangle(85,rrow,530,rrow+26);
		setcolor(15);
		tempchar[0]=get[i];
		outtextxy(120,rrow+5,tempchar);
		if (tempchar[0]=='0')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"1    0    0    0    0");
		}
		if (tempchar[0]=='1')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"1    0    0    0    0");
		}
		if (tempchar[0]=='2')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    1    0    0    0");
		}
		if (tempchar[0]=='3')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    1    0    0    0");
		}
		if (tempchar[0]=='4')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    0    1    0    0");
		}
		if (tempchar[0]=='5')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    0    1    0    0");
		}
		if (tempchar[0]=='6')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    0    0    1    0");
		}
		if (tempchar[0]=='7')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    0    0    1    0");
		}
		if (tempchar[0]=='8')
		{
			outtextxy(190,rrow+5,"1    0");
			outtextxy(310,rrow+5,"0    0    0    0    1");
		}
		if (tempchar[0]=='9')
		{
			outtextxy(190,rrow+5,"0    1");
			outtextxy(310,rrow+5,"0    0    0    0    1");
		}
		rrow+=26;
	}
	setcolor(0);
	line(170,150,170,rrow);
	line(280,150,280,rrow);
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

/*	Function of Quibinary to Decimal Convertion	*/

void quid(void)
{
	int flag=0,chr=0;
	int dtob=1;
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Quibinary to Decimal");
		comman(65,100,580,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,150,"Enter the Quibinary Number : ");
		int rcol=400;
		setcolor(0);
		for (int i=0;i<8;i++)
		{
			rectangle(rcol,155,rcol+22,175);
			rcol+=22;
		}
		char ch,tempchr[2];
		setcolor(15);
		outtextxy(450,152,"-");
		i=0;tempchr[1]='\0';rcol=405;
		while ((i!=7)&&((ch=getch()) != 13))
		{
			get[i] = ch;
			tempchr[0]=ch;
			get[i+1] = '\0';
			setcolor(15);
			settextstyle(8,0,1);
			outtextxy(rcol,150, tempchr);
			i++;
			if (i==2)
				rcol+=48;
			else
				rcol+=22;
		}
		int count=9;
		for (i=2;i<strlen(get);i++)
			if (get[i]=='1')
				if (count==9)
					count=1;
				else
					count++;
		if ((get[0] == '1')&&(get[1] == '1'))
		{
			dtob=1;
			errordisplay2();
		}
		else
			if (count > 1)
			{
				dtob=1;
				errordisplay2();
			}
			else
				if (strlen(get)<7)
				{
					dtob=1;
					errordisplay2();
				}
				else
				for (i=0;i<strlen(get);i++)
					if ((get[i] < '0')||(get[i] > '1'))
				{
					dtob=1;
					errordisplay2();
				}
	}
	settextstyle(8,0,4);
	setcolor(15);
	outtextxy(100,250,"Decimal Number is");
	if (!strcmp(get,"1010000"))
		outtextxy(460,250,"0");
	if (!strcmp(get,"0110000"))
		outtextxy(460,250,"1");
	if (!strcmp(get,"1001000"))
		outtextxy(460,250,"2");
	if (!strcmp(get,"0101000"))
		outtextxy(460,250,"3");
	if (!strcmp(get,"1000100"))
		outtextxy(460,250,"4");
	if (!strcmp(get,"0100100"))
		outtextxy(460,250,"5");
	if (!strcmp(get,"1000010"))
		outtextxy(460,250,"6");
	if (!strcmp(get,"0100010"))
		outtextxy(460,250,"7");
	if (!strcmp(get,"1000001"))
		outtextxy(460,250,"8");
	if (!strcmp(get,"0100001"))
		outtextxy(460,250,"9");

	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void errordisplay2(void)
{
	desion2();
	settextstyle(8,0,4);
	outtextxy(123,135,"<ERROR>");
	settextstyle(2,0,5);
	outtextxy(200,190,"Quibinary Code use only 0 and 1 Digits.");
	outtextxy(200,210,"The length of Quibinary Code is 7-Bit.");
	outtextxy(220,230,"You are one Bit ON in each part.");
	outtextxy(220,250,"You are Worng enter the Number.");
	comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
	setcolor(0);
	settextstyle(1,0,4);
	outtextxy(getmaxx()/2-20,265,"Ok");
	int i = 0,flag;
	setcursorpos(getmaxx( )/2,getmaxy()/2);
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

/*	Function of Binary to Gray's Code Convertion	*/

void bgray(void)
{
	int flag=0,chr=0;
	int btod=1;
	char result[10];
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Binary to Gray's Code");
		comman(35,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Binary Number : ");
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=10)&&(ch!=8))
				sound();
			else
			{
			get[i] = ch;
			get[i+1] = '\0';
			if (ch==8)
			{
				i--;
				get[i] = '\0';
				i--;
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(380,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Binary Numbers use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	int tempint1,tempint2,tempint3;
	char temp[2];
	temp[1]='\0';
	result[0]=get[0];
	for (int i=0;i<strlen(get)-1;i++)
	{
		temp[0]=get[i];tempint1=atoi(temp);
		temp[0]=get[i+1];tempint2=atoi(temp);
		tempint3=tempint1+tempint2;
		if (tempint3==0)
			result[i+1]='0';
		if (tempint3==1)
			result[i+1]='1';
		if (tempint3==2)
			result[i+1]='0';
	}
	result[i+1]='\0';
	outtextxy(150,220,"Gray's Code is");
	outtextxy(310,220,result);

	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

/*	Function of Gray's Code to Binary convertion	*/

void grayb(void)
{
	int flag=0,chr=0;
	int btod=1;
	char result[10];
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Gray's Code to Binary");
		comman(35,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Gary's Code : ");
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,127,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=10)&&(ch!=8))
				sound();
			else
			{
			get[i] = ch;
			get[i+1] = '\0';
			if (ch==8)
			{
				i--;
				get[i] = '\0';
				i--;
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(380,115,598,145,9);
			outtextxy(cursor,127,"-");
			settextstyle(8,0,1);
			outtextxy(385, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Gray's Code use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	int tempint1,tempint2,tempint3;
	char temp[2];
	temp[1]='\0';
	result[0]=get[0];
	for (int i=0;i<strlen(get)-1;i++)
	{
		temp[0]=result[i];tempint1=atoi(temp);
		temp[0]=get[i+1];tempint2=atoi(temp);
		tempint3=tempint1+tempint2;
		if (tempint3==0)
			result[i+1]='0';
		if (tempint3==1)
			result[i+1]='1';
		if (tempint3==2)
			result[i+1]='0';
	}
	result[i+1]='\0';
	outtextxy(140,220,"Binary Number is");
	outtextxy(330,220,result);

	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void dex(void)
{
	int flag=0,chr=0;
	int dtob=1;
	char result[16];
	while (dtob)
	{
		dtob=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(40,3,"Decimal to Excess-3");
		comman(65,100,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,110,"Enter the Decimal Number : ");
		char ch;
		int i=0,cursor=385;
		outtextxy(cursor,117,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=4)&&(ch!=8))
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
			comman2(380,105,550,145,9);
			outtextxy(cursor,117,"-");
			settextstyle(8,0,1);
			outtextxy(385, 110, get);
			i++;
			}
	}

		for (i=0;i<strlen(get);i++)
			if ((get[i] < '0')||(get[i] > '9'))
			{
				dtob=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,210,"You are Worng enter the Number.");
				outtextxy(320,230,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	char temp[2];temp[1]='\0';
	int tempint;result[0]='\0';
	int rrow=150;
	outtextxy(90,150,"Decimal");
	outtextxy(190,150,"Decimal+1");
	outtextxy(340,150,"Excess-3 Code");
	setcolor(0);
	rectangle(85,150,530,176);
	for (int i=0;i<=strlen(get);i++)
	{
		rectangle(85,rrow,530,rrow+26);
		rrow+=26;
	}
	line(170,150,170,rrow);
	line(300,150,300,rrow);
	setcolor(15);
	rrow=176;
	for (i=0;i<strlen(get);i++)
	{
		temp[0]=get[i];
		tempint=atoi(temp);
		outtextxy(120,rrow,temp);
		outtextxy(210,rrow,temp);
		outtextxy(230,rrow,"+ 3");
		tempint+=3;
		if (tempint==3)
		{
			strcat(result,"0011");
			outtextxy(390,rrow,"0011");
		}
		if (tempint==4)
		{
			strcat(result,"0100");
			outtextxy(390,rrow,"0100");
		}
		if (tempint==5)
		{
			strcat(result,"0101");
			outtextxy(390,rrow,"0101");
		}
		if (tempint==6)
		{
			strcat(result,"0110");
			outtextxy(390,rrow,"0110");
		}
		if (tempint==7)
		{
			strcat(result,"0111");
			outtextxy(390,rrow,"0111");
		}
		if (tempint==8)
		{
			strcat(result,"1000");
			outtextxy(390,rrow,"1000");
		}
		if (tempint==9)
		{
			strcat(result,"1001");
			outtextxy(390,rrow,"1001");
		}
		if (tempint==10)
		{
			strcat(result,"1010");
			outtextxy(390,rrow,"1010");
		}
		if (tempint==11)
		{
			strcat(result,"1011");
			outtextxy(390,rrow,"1011");
		}
		if (tempint==12)
		{
			strcat(result,"1100");
			outtextxy(390,rrow,"1100");
		}
		rrow+=26;
	}
	outtextxy(150,320,"Excess-3 Code is");
	outtextxy(330,320,result);
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
				press1(270,410,370,440);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,410,370,440);
			delay(100);
			if (x >= 270 && y >= 410 && x <= 370 && y <= 440)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

void exd(void)
{
	int flag=0,chr=0;
	int btod=1;
	char result[10];
	while(btod)
	{
		btod=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(20,3,"Ex-3 Code to Decimal");
		comman(35,100,600,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,120,"Enter the Ex-3 Code : ");
		char ch;
		int i=0,cursor=345;
		outtextxy(cursor,127,"-");
		get[0]='\0';
		Flush();
		while ((ch=getch()) != 13)
		{
			if ((i>=16)&&(ch!=8))
				sound();
			else
			{
			get[i] = ch;
			get[i+1] = '\0';
			if (ch==8)
			{
				i--;
				get[i] = '\0';
				i--;
				cursor-=26;
			}
			setcolor(15);
			cursor+=13;
			comman2(340,115,598,145,9);
			outtextxy(cursor,127,"-");
 			settextstyle(8,0,1);
			outtextxy(345, 120, get);
			i++;
			}
		}
		comman2(cursor,115,598,145,9);
		for (i=0;i<strlen(get);i++)
			if ((get[i] > '1')||(get[i] < '0'))
			{
				btod=1;
				desion2();
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(220,200,"Binary Numbers use only 0 and 1 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
				setcolor(0);
				settextstyle(1,0,4);
				outtextxy(getmaxx()/2-20,265,"Ok");
				i = 0;
				setcursorpos(getmaxx( )/2,getmaxy()/2);
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
	int tempint,tempint1=strlen(get),tempint2;
	char temp[16],tempchr[4][5];
	tempint=strlen(get);
	if ((tempint==1)||(tempint==5)||(tempint==9)||(tempint==13))
	{
		strcpy(temp,"000");
		strcat(temp,get);
		strcpy(get,temp);
	}
	if ((tempint==2)||(tempint==6)||(tempint==10)||(tempint==14))
	{
		strcpy(temp,"00");
		strcat(temp,get);
		strcpy(get,temp);
	}
	if ((tempint==3)||(tempint==7)||(tempint==11)||(tempint==15))
	{
		strcpy(temp,"0");
		strcat(temp,get);
		strcpy(get,temp);
	}
	int rcol=230,check=0;
	outtextxy(80,176,"Excess-3 Code");
	outtextxy(100,202,"Decimal+3");
	outtextxy(110,228,"Decimal");
	setcolor(0);
	rectangle(75,176,230,255);
	if ((tempint1>=0)&&(tempint1<=4))
		tempint1=1;
	if ((tempint1>=4)&&(tempint1<=8))
		tempint1=2;
	if ((tempint1>=9)&&(tempint1<=12))
		tempint1=3;
	if ((tempint1>=13)&&(tempint1<=16))
		tempint1=4;
	tempint2=0;
	for (int j=0;j<tempint1;j++)
		for (int i=0;i<4;i++)
		{
			tempchr[j][i]=get[tempint2];
			tempint2++;
		}
	for (i=0;i<tempint1;i++)
		tempchr[i][4]='\0';
	for (i=0;i<tempint1;i++)
	{
		rectangle(rcol,176,rcol+90,255);
		outtextxy(rcol+20,176,tempchr[i]);
		if (!strcmp(tempchr[i],"0011"))
		{
			outtextxy(rcol+40,202,"3");
			outtextxy(rcol+40,228,"0");
			get[i]='0';
		}
		else
		if (!strcmp(tempchr[i],"0100"))
		{
			outtextxy(rcol+40,202,"4");
			outtextxy(rcol+40,228,"1");
			get[i]='1';
		}
		else
		if (!strcmp(tempchr[i],"0101"))
		{
			outtextxy(rcol+40,202,"5");
			outtextxy(rcol+40,228,"2");
			get[i]='2';
		}
		else
		if (!strcmp(tempchr[i],"0110"))
		{
			outtextxy(rcol+40,202,"6");
			outtextxy(rcol+40,228,"3");
			get[i]='3';
		}
		else
		if (!strcmp(tempchr[i],"0111"))
		{
			outtextxy(rcol+40,202,"7");
			outtextxy(rcol+40,228,"4");
			get[i]='4';
		}
		else
		if (!strcmp(tempchr[i],"1000"))
		{
			outtextxy(rcol+40,202,"8");
			outtextxy(rcol+40,228,"5");
			get[i]='5';
		}
		else
		if (!strcmp(tempchr[i],"1001"))
		{
			outtextxy(rcol+40,202,"9");
			outtextxy(rcol+40,228,"6");
			get[i]='6';
		}
		else
		if (!strcmp(tempchr[i],"1010"))
		{
			outtextxy(rcol+40,202,"10");
			outtextxy(rcol+40,228,"7");
			get[i]='7';
		}
		else
		if (!strcmp(tempchr[i],"1011"))
		{
			outtextxy(rcol+40,202,"11");
			outtextxy(rcol+40,228,"8");
			get[i]='8';
		}
		else
		if (!strcmp(tempchr[i],"1100"))
		{
			outtextxy(rcol+40,202,"12");
			outtextxy(rcol+40,228,"9");
			get[i]='9';
		}
		else
			check=1;
		get[i+1]='\0';
		rcol+=90;
	}
	line(75,204,rcol,204);
	line(75,230,rcol,230);
	setcolor(15);
	if (check)
		outtextxy(150,270,"This Code is not Excess-3 Code");
	else
	{
		outtextxy(150,270,"Decimal Number is");
		outtextxy(350,270,get);
	}
	comman(270,400,370,430,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,395,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	while (!chr)
	{
		button=getcursorpos(&x,&y);
		if (button)
		{
			flag=1;
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
				press1(270,400,370,430);
		}
		if ((!button)&&(flag))
		{
			flag=0;
			press2(270,400,370,430);
			delay(100);
			if (x >= 270 && y >= 400 && x <= 370 && y <= 430)
			{
				sound();
				chr=1;
				cursoroff();
			}
		}
	}

}

