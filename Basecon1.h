       Convertatoh(long int Num,long int Base);
long int    Decimalatoh(char String[] , long int InitialBase);
long int    deciatoh(char fgh[],long int inti);
char *getnumber12(int col,int row,int binrow);
void enderror2atoh(void);

float rs12=0.0;
//static long int aatoh=0;int button;
long int initbaseatoh,conbaseatoh;
char *integralatoh="     " ,*fractionatoh="     " , *Matoh="                 ", *Natoh="                   ";
int dtobatoh=1;

void htod(void)
{
long int Dec;
char f[22],number[3][10];

  //     "header part"

	dtobatoh=1;
	while (dtobatoh)
	{
		dtobatoh=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(50,10,"Hexadecimal to Decimal");
		comman(65,100,575,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,150,"Enter the Hexa Number : ");
		strcpy(number[0],getnumber12(360,150,153));
		strcpy(f,number[0]);
		for (int i=0;i<strlen(number[0]);i++)
			if ((number[0][i] >='0'&&number[0][i] <= '9')||((number[0][i] >= 'A')&&(number[0][i] <= 'F'))||(number[0][i] >= 'a')&&(number[0][i] <= 'f'))
			{}//Dummy
			else
			{
				desion2();
				dtobatoh=1;
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(230,190,"Numbers use only 0 to 9");
				outtextxy(300,210," and A to F Digits");
				outtextxy(240,230,"You are Worng enter the Number");
				outtextxy(310,250,"Try Again");
				enderror2atoh();
			}
		strcpy(number[1],"16");
		initbaseatoh=atol(number[1]);
		strcpy(number[2],"10");
		conbaseatoh=atol(number[2]);
		Dec=Decimalatoh(f,initbaseatoh);
	}

      Convertatoh(Dec,conbaseatoh);
      if (a==1)
      {
	outtextxy(390,330,"");
      }
      else
      {
//	gotoxy(200,260);
	outtextxy(140,250,"Decimal Number is");
	outtextxy(210,250,Natoh);
	};
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	int flag,chr=0;
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

void htoa(void)
{
long int Dec;
char f[22],number[3][10];

  //     "header part"

	dtobatoh=1;
	while (dtobatoh)
	{
		dtobatoh=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(30,6,"Hexadecimal to Octal");
		comman(65,100,575,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,150,"Enter the Hexa Number : ");
		strcpy(number[0],getnumber12(360,150,153));
		strcpy(f,number[0]);
		for (int i=0;i<strlen(number[0]);i++)
			if ((number[0][i] >='0'&&number[0][i] <= '9')||((number[0][i] >= 'A')&&(number[0][i] <= 'F'))||(number[0][i] >= 'a')&&(number[0][i] <= 'f'))
			{}//Dummy
			else
			{
				desion2();
				dtobatoh=1;
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(230,190,"Numbers use only 0 to 9");
				outtextxy(300,210," and A to F Digits");
				outtextxy(240,230,"You are Worng enter the Number");
				outtextxy(310,250,"Try Again");
				enderror2atoh();
			}
		strcpy(number[1],"16");
		initbaseatoh=atol(number[1]);
		strcpy(number[2],"8");
		conbaseatoh=atol(number[2]);
		Dec=Decimalatoh(f,initbaseatoh);
	}

      Convertatoh(Dec,conbaseatoh);
      if (a==1)
      {
	outtextxy(390,330,"");
      }
      else
      {
//	gotoxy(200,260);
	outtextxy(170,250,"Octal Number is");
	outtextxy(210,250,Natoh);
	};
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	int flag,chr=0;
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

void atoh(void)
{
long int Dec;
char f[22],number[3][10];

  //     "header part"

	dtobatoh=1;
	while (dtobatoh)
	{
		dtobatoh=0;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(30,6,"Octal to Hexadecimal");
		comman(65,100,575,350,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,150,"Enter the Octal Number : ");
		strcpy(number[0],getnumber12(360,150,153));
		strcpy(f,number[0]);
		for (int i=0;i<strlen(number[0]);i++)
			if ((number[0][i] >='0')&&(number[0][i] <= '7'))
			{}//Dummy
			else
			{
				desion2();
				dtobatoh=1;
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(230,200,"Numbers use only 0 to 7 Digits");
				outtextxy(240,220,"You are Worng enter the Number");
				outtextxy(310,240,"Try Again");
				enderror2atoh();
			}
		strcpy(number[1],"8");
		initbaseatoh=atol(number[1]);
		strcpy(number[2],"16");
		conbaseatoh=atol(number[2]);
		Dec=Decimalatoh(f,initbaseatoh);
	}

      Convertatoh(Dec,conbaseatoh);
      if (a==1)
      {
	outtextxy(390,330,"");
      }
      else
      {
//	gotoxy(200,260);
	outtextxy(120,250,"HexaDecimal Number is");
	outtextxy(230,250,Natoh);
	};
	comman(270,410,370,440,7);
	settextstyle(1,0,4);
	setcolor(0);
	outtextxy(300,405,"Ok");
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	int flag,chr=0;
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

    //     "Function Convertion"

Convertatoh(long int Num, long int Base)
{
	long int Q=Num,R=0,Last=18,h,last=0;
	while(Q>=Base)
	{
		R=Num%Base ;
		Num=Num/Base ;
		if(Base>10&& R>9)
			Natoh[Last] ='A'+R-10;
		else
			Natoh[Last]=R+48;
		Q=Num;Last--;
	}
	Natoh[Last]=Q+48;
	float s=rs,r=0.0;
	double te,fr=0.0;
	if (a==1)
	{
		while(last<=15)
		{
		       r=rs*Base;          h=r;
		       fr=modf(r,&te);     rs=fr;
		       if (Base>10 && h>9)
				Matoh[last]=h+55;
		       else
				Matoh[last]=h+48;
			last++;
		}
	}
	Matoh[Last]=Q+48; return 0;
}

//       "Function"

long int  deciatoh(char fgh[],long int inti)
{
	  long int z=0,num=0,i=0;
	  while(i<strlen(fgh))
	  {
		if (fgh[i]==' ') break;
			if ((fgh[i]>96) && (fgh[i]<122))
				fgh[i]-=32;
				if (fgh[i]>64)
					z=fgh[i]-55;
				else
					z=fgh[i]-48;
/*			if (z>=initbase)
			{
				desion2();
				dtobatoh=1;
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(8,0,2);
				outtextxy(200,190,"This Number is greater");
				outtextxy(250,220,"then InitialBase");
				enderror2();
				i=strlen(fgh);
			}*/
	      num=num*inti+fgh[i];
	      if(fgh[i]>64)
		  num-=55;
	      else
		  num-=48;
		  i++;
	    } return(num);
    }

//            "Function Decimal"

long int Decimalatoh(char string[],long int InitialBase)
{
   long int numb=0,n=0,d=1,Num,sub1=0,s=0,sub2=0,z=0;
   float Divisor=1.0;
   while (string[s]!= 0)
     {
	   if (string[s]=='.') a=1;
	   if (a==0) {integralatoh[sub1]=string[s]; sub1++;     }
	    else   { fractionatoh[sub2]=string[s]; sub2++;    }
	    s++;
      }
      integralatoh[sub1]=fractionatoh[sub2]=0;
      if (a==0)
      {
	 numb=deciatoh(integralatoh,InitialBase);
	 return(numb);
      }
      else
      {
	numb=deciatoh(integralatoh,InitialBase);
	while (fractionatoh[d]!=0)
	{
	  if (fractionatoh[d]>64)
	      z=fractionatoh[d]-55;
	  else
	      z=fractionatoh[d]-48;
       if
       (z>=InitialBase)
       {
	  gotoxy(2,9);
	  printf("The Number at Position %d After decimal is Greater then InitialBase ",d);
	  getch();
	  textbackground(BLACK);
	  clrscr();
	  exit(0);
       }
       Divisor*=InitialBase;
       n=fractionatoh[d];
       if (n>96 && n<123)
	   n-=87;
       else
	   if(n>64 && n<91)
	       n-=55;
	   else
	       if(n>47&&n<58)
		  n-=48;
		 rs=rs+(1.0/Divisor)*n;
		 d++;
	       }    return(numb);
       }
}

char *getnumber12(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if((i>=8)&&(ch!=8))
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
			cursor-=28;
		}
		comman2(350,binrow,570,binrow+20,9);
		cursor+=14;
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman2(350,binrow,489,binrow+20,9);
	outtextxy(col, row, get);
	return(get);
}

void enderror2atoh(void)
{
	setcursorpos(getmaxx( )/2,getmaxy()/2);
	cursoron();
	settextstyle(1,0,4);
	outtextxy(getmaxx()/2-20,265,"Ok");
	int flag,i=0;
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
				i=1;
				cursoroff();
			}
		}
	}
	cursoroff();
}
