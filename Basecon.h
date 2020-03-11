       Convert(long int Num,long int Base);
long int    Decimal(char String[] , long int InitialBase);
long int    deci(char fgh[],long int inti);
char *getnumber(int col,int row,int binrow);
char *baseget(int col,int row,int binrow,int bincol);
void enderror2(void);

float rs=0.0;
static long int a=0;
long int Num,initbase,conbase;
char *integral="     " ,*fraction="     " , *M="                 ", *N="                   ";
int dtob,check;

void basecon(void)
{
long int Dec;
char f[22],number[3][10];

  //     "header part"

	dtob=1;
	while (dtob)
	{
		dtob=0;check=1;
		comman3(0,0,650,500,0);
		comman(0,10,630,470,7);
		comman2(2,12,628,68,3);
		comman3(15,70,615,455,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(40,10,"One Base to Another Base");
		comman(65,100,575,400,9);
		setcolor(15);
		settextstyle(1,0,2);
		outtextxy(85,110,"Enter  the Number : ");
		strcpy(number[0],getnumber(352,110,113));
		strcpy(f,number[0]);
		for (int i=0;i<strlen(number[0]);i++)
			if ((number[0][i] >='0'&&number[0][i] <= '9')||((number[0][i] >= 'A')&&(number[0][i] <= 'Z'))||(number[0][i] >= 'a')&&(number[0][i] <= 'z'))
			{}//Dummy
			else
			{
				check=0;
				desion2();
				dtob=1;
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(2,0,5);
				outtextxy(230,190,"Numbers use only 0 to 9");
				outtextxy(300,210," and A to Z Digits");
				outtextxy(240,230,"You are Worng enter the Number");
				outtextxy(310,250,"Try Again");
				enderror2();
			}
		if (check)
		{
			outtextxy(85,160,"Enter the Initial Base : ");
			strcpy(number[1],baseget(352,160,163,350));
			initbase=atol(number[1]);
			for (i=0;i<strlen(number[1]);i++)
				if ((number[1][i] > '9')||(number[1][i] < '0'))
				{
					check=0;
					desion2();
					dtob=1;
					settextstyle(8,0,4);
					outtextxy(123,135,"<ERROR>");
					settextstyle(2,0,5);
					outtextxy(280,200,"Base use only 0 to 9");
					outtextxy(240,220,"You are Worng enter the Base");
					outtextxy(310,240,"Try Again");
					enderror2();
				}
		 }
		if (check)
		{
			outtextxy(85,210,"Enter the Base to be Converted in : ");
			strcpy(number[2],baseget(470,210,213,470));
			conbase=atol(number[2]);
			for (i=0;i<strlen(number[2]);i++)
				if ((number[2][i] > '9')||(number[2][i] < '0'))
				{
					check=0;
					desion2();
					dtob=1;
					settextstyle(8,0,4);
					outtextxy(123,135,"<ERROR>");
					settextstyle(2,0,5);
					outtextxy(280,200,"Base use only 0 to 9");
					outtextxy(240,220,"You are Worng enter the Base");
					outtextxy(310,240,"Try Again");
					enderror2();
				}
		}
		if (((initbase>36) || (conbase>36))&&(check))
		{
			check=0;
			desion2();
			dtob=1;
			settextstyle(8,0,4);
			outtextxy(123,135,"<ERROR>");
			outtextxy(200,200,"Out of Bound base ");
			enderror2();
		}
		if (check)
			Dec=Decimal(f,initbase);
	}

      Convert(Dec,conbase);
      if (a==1)
      {
	outtextxy(390,330,"");
      }
      else
      {
	 outtextxy(120,300,"The Number after Conversion is :");
	 outtextxy(140,340,N);
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

Convert(long int Num, long int Base)
{
	long int Q=Num,R=0,Last=18,h,last=0;
	while(Q>=Base)
	{
		R=Num%Base ;
		Num=Num/Base ;
		if(Base>10&& R>9)
			N[Last] ='A'+R-10;
		else
			N[Last]=R+48;
		Q=Num;Last--;
	}
	N[Last]=Q+48;
	float r=0.0;
	double te,fr=0.0;
	if (a==1)
	{
		while(last<=15)
		{
		       r=rs*Base;          h=r;
		       fr=modf(r,&te);     rs=fr;
		       if (Base>10 && h>9)
				M[last]=h+55;
		       else
				M[last]=h+48;
			last++;
		}
	}
	M[Last]=Q+48; return 0;
}

//       "Function"

long int  deci(char fgh[],long int inti)
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
			if (z>=initbase)
			{
				desion2();
				dtob=1;
				settextstyle(8,0,4);
				outtextxy(123,135,"<ERROR>");
				settextstyle(8,0,2);
				outtextxy(200,190,"This Number is greater");
				outtextxy(250,220,"then InitialBase");
				enderror2();
				i=strlen(fgh);
			}
	      num=num*inti+fgh[i];
	      if(fgh[i]>64)
		  num-=55;
	      else
		  num-=48;
		  i++;
	    } return(num);
    }
/*long int  deci(char fgh[],long int inti)
{
	  long int z=0,num=0,i=0;
	  char temp[2];temp[1]='\0';
	  while(i<strlen(fgh))
	  {
		temp[0]=fgh[i];
		z=atoi(temp);i++;
		if (z>=initbase)
		{
			desion2();
			*dtob=1;
			settextstyle(8,0,4);
			outtextxy(123,135,"<ERROR>");
			settextstyle(8,0,2);
			outtextxy(200,190,"This Number is greater");
			outtextxy(250,220,"then InitialBase");
			enderror2();
			i=strlen(fgh);
	      gotoxy(2,9);
	      printf(" The Number at Position %d is greater then InitialBase ",i+1);
	      getch();
	      textbackground(BLACK);
	      clrscr();
	      exit(0);}
	      num=num*inti+fgh[i];
	      if(fgh[i]>64)
		  num-=55;
	      else
		  num-=48;
		  i++;
	    } //return(num);
    }
}                     */

//            "Function Decimal"

long int Decimal(char string[],long int InitialBase)
{
   long int numb=0,n=0,d=1,Num,sub1=0,s=0,sub2=0,z=0;
   float Divisor=1.0;
   while (string[s]!= 0)
     {
	   if (string[s]=='.') a=1;
	   if (a==0) {integral[sub1]=string[s]; sub1++;     }
	    else   { fraction[sub2]=string[s]; sub2++;    }
	    s++;
      }
      integral[sub1]=fraction[sub2]=0;
      if (a==0)
      {
	 numb=deci(integral,InitialBase);
	 return(numb);
      }
      else
      {
	numb=deci(integral,InitialBase);
	while (fraction[d]!=0)
	{
	  if (fraction[d]>64)
	      z=fraction[d]-55;
	  else
	      z=fraction[d]-48;
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
       n=fraction[d];
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

char *getnumber(int col,int row,int binrow)
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

char *baseget(int col,int row,int binrow,int bincol)
{
	char ch,get[16];
	int i=0,cursor=col;
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if((i>=2)&&(ch!=8))
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
		comman2(bincol,binrow,bincol+50,binrow+20,9);
		cursor+=13;
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman2(bincol,binrow,bincol+50,binrow+20,9);
	outtextxy(col, row, get);
	return(get);
}

void enderror2(void)
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
