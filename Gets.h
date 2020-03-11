void Flush(void);
void binaryadition(void);
void binarysubtraction(void);
void binarymultiplication(void);
char *binaryget(int col,int row,int binrow);
char *binaryget1(int col,int row,int binrow);
void bincheck(char binnumber[],int*);
void equalnumber(char binnumber1[],char binnumber2[]);

void octaladition(void);
void octalsubtraction(void);
void octalmultiplication(void);
char *octalget(int col,int row,int binrow);
void octalcheck(char binnumber[],int*);
void addnumber(char binnumber1[],char binnumber2[]);

void hexaadition(void);
void hexasubtraction(void);
void hexamultiplication(void);
char *hexaget(int col,int row,int binrow);
void hexacheck(char binnumber[],int*);

void bcdadition(void);
void bcdsubtraction(void);
void bcdmultiplication(void);
char *bcdget(int col,int row,int binrow);
char *bcdget1(int col,int row,int binrow);
void bcdcheck(char binnumber[],int*);


int numberlength[2],temp,tempint1,tempint2,tempint3,carry=0;
long int tempint4,tempint5,tempint6;
char binnumber[2][16],result[20];
char tempnumber[16],resulttemp[20];
char tempchar,tempstr1[4],tempstr2[4];
int  btod=1,first=1;
int button;

void basicstart(void)
{
	comman3(0,0,650,500,0);
	comman(0,10,630,470,7);
	comman2(2,12,628,68,3);
	comman3(15,70,615,455,0);
}
void basicend(void)
{
	int flag=0,chr=0;
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

/*	Functions of Binary Adition	*/

void binaryadition(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(350,150,489,170,15);
		comman1(350,200,489,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(90,3,"Binary Addition");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first Binary Number   :");
		outtextxy(90,200,"Enter the Second Binary Number :");
		if (first)
		{
			strcpy(binnumber[0],binaryget(355,153,150));
			bincheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(355,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],binaryget(355,203,200));
			bincheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	i=0;
	while (temp!=-1)
	{
		tempint1 = binnumber[0][temp]-48;
		tempint2 = binnumber[1][temp]-48;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{
			result[i]='0';
			carry=0;
		}
		if (tempint3==1)
		{
			result[i]='1';
			carry=0;
		}
		if (tempint3==2)
		{
			result[i]='0';
			carry=1;
		}
		if (tempint3==3)
		{
			result[i]='1';
			carry=1;
		}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	settextstyle(8,0,1);
	outtextxy(120,270,"Addition Result is ");
	outtextxy(310,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of Binary Subtraction		*/

void binarysubtraction(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(350,150,489,170,15);
		comman1(350,200,489,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(55,3,"Binary Subtraction");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first Binary Number   :");
		outtextxy(90,200,"Enter the Second Binary Number :");
		if (first)
		{
			strcpy(binnumber[0],binaryget(355,153,150));
			bincheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(355,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],binaryget(355,203,200));
			bincheck(binnumber[1],&btod);
		}
	}
	temp=strlen(binnumber[1])-1;
	while (temp!=-1)
	{
		if (binnumber[1][temp]=='1')
			binnumber[1][temp]='0';
		else
			binnumber[1][temp]='1';
		temp--;
	}
	for (int i=(strlen(binnumber[1])-1);i>=0;i--)
	{
		if ((carry)&&(binnumber[1][i]=='1'))
		{
			carry=1;binnumber[1][i]='1';
		}
		else
		if (((!carry)&&(binnumber[1][i]=='1'))||((carry)&&(binnumber[1][i]=='0')))
		{
			carry=0;binnumber[1][i]='1';
		}
		else
		if ((!carry)&&(binnumber[1][i]=='0'))
		{
			carry=0;binnumber[1][i]='0';
		}

	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	i=0;carry=0;
	while (temp!=-1)
	{
		tempint1 = binnumber[0][temp]-48;
		tempint2 = binnumber[1][temp]-48;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{
			result[i]='0';
			carry=0;
		}
		if (tempint3==1)
		{
			result[i]='1';
			carry=0;
		}
		if (tempint3==2)
		{
			result[i]='0';
			carry=1;
		}
		if (tempint3==3)
		{
			result[i]='1';
			carry=1;
		}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	settextstyle(8,0,1);
	outtextxy(120,270,"Subtractoin Result is ");
	outtextxy(340,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of Binary Multiplication		*/

void binarymultiplication(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,445,170,15);
		comman1(400,200,445,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(10,3,"Binary Multiplication");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first Binary Number   :");
		outtextxy(90,200,"Enter the Second Binary Number :");
		if (first)
		{
			strcpy(binnumber[0],binaryget1(405,153,150));
			bincheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(405,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],binaryget1(405,203,200));
			bincheck(binnumber[1],&btod);
		}
	}
	char tempnumber1[16],tempnumber2[16],tempnumber3[16],tempnumber4[16];
	equalnumber(binnumber[0],binnumber[1]);
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0];
	if (temp==1)
		if (binnumber[1][0]=='1')
			strcpy(result,binnumber[0]);
	if (temp==2)
	{
		if (binnumber[1][1]=='1')
			strcpy(tempnumber1,binnumber[0]);
		else
			strcpy(binnumber[0],"00");
		if (binnumber[1][0]=='1')
			strcpy(tempnumber2,binnumber[0]);
		else
			strcpy(tempnumber2,"00");
		tempnumber2[2]='0';
		tempnumber2[3]='\0';
		equalnumber(tempnumber1,tempnumber2);
		addnumber(tempnumber1,tempnumber2);
	}
	if (temp==3)
	{
		if (binnumber[1][2]=='1')
			strcpy(tempnumber1,binnumber[0]);
		else
			strcpy(tempnumber1,"000");
		if (binnumber[1][1]=='1')
			strcpy(tempnumber2,binnumber[0]);
		else
			strcpy(tempnumber2,"000");
		tempnumber2[3]='0';
		tempnumber2[4]='\0';
		equalnumber(tempnumber1,tempnumber2);
		addnumber(tempnumber1,tempnumber2);
		strcpy(tempnumber1,result);
		if (binnumber[1][0]=='1')
			strcpy(tempnumber2,binnumber[0]);
		else
			strcpy(tempnumber2,"000");
		tempnumber2[3]='0';tempnumber2[4]='0';tempnumber2[5]='\0';
		equalnumber(tempnumber1,tempnumber2);
		addnumber(tempnumber1,tempnumber2);
	}
	if (temp==4)
	{
		if (binnumber[1][3]=='1')
			strcpy(tempnumber1,binnumber[0]);
		else
			strcpy(tempnumber1,"0000");
		if (binnumber[1][2]=='1')
			strcpy(tempnumber2,binnumber[0]);
		else
			strcpy(tempnumber2,"0000");
		tempnumber2[4]='0';
		tempnumber2[5]='\0';
		equalnumber(tempnumber1,tempnumber2);
		addnumber(tempnumber1,tempnumber2);
		strcpy(tempnumber1,result);
		if (binnumber[1][1]=='1')
			strcpy(tempnumber2,binnumber[0]);
		else
			strcpy(tempnumber2,"0000");
		tempnumber2[4]='0';tempnumber2[5]='0';tempnumber2[6]='\0';
		equalnumber(tempnumber1,tempnumber2);
		addnumber(tempnumber1,tempnumber2);
		strcpy(tempnumber1,result);
		if (binnumber[1][0]=='1')
			strcpy(tempnumber2,binnumber[0]);
		else
			strcpy(tempnumber2,"0000");
		tempnumber2[4]='0';tempnumber2[5]='0';
		tempnumber2[6]='0';tempnumber2[7]='\0';
		equalnumber(tempnumber1,tempnumber2);
		addnumber(tempnumber1,tempnumber2);
	}
/*	if (binnumber[1][1]=='1')
	{
		tempnumber[0]='0';
		strcat(tempnumber2,binnumber[0]);
	}
	else
	{
		if (temp==1)
			strcpy(tempnumber2,"00");
		if (temp==2)
			strcpy(tempnumber2,"000");
		if (temp==3)
			strcpy(tempnumber2,"0000");
		if (temp==4)
			strcpy(tempnumber2,"00000");
	}
 outtextxy(100,250,tempnumber1);*/
	settextstyle(8,0,1);
	outtextxy(100,270,"Multiplication Result is ");
	outtextxy(350,270,result);
}

void equalnumber(char binnumber1[],char binnumber2[])
{
	char tempnumberof[20];int i;
	numberlength[0]=strlen(binnumber1);
	numberlength[1]=strlen(binnumber2);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumberof,binnumber1);
		i=0;
		while (temp!=0)
		{
			binnumber1[i]='0';
			i++;temp--;
		}
		binnumber1[i]='\0';
		strcat(binnumber1,tempnumberof);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumberof,binnumber2);
		i=0;
		while (temp!=0)
		{
			binnumber2[i]='0';
			i++;temp--;
		}
		binnumber2[i]='\0';
		strcat(binnumber2,tempnumberof);
	}
}

void addnumber(char binnumber1[],char binnumber2[])
{
	int i=0;
	carry=0;
	temp=strlen(binnumber1)-1;
	while (temp!=-1)
	{
		tempint1 = binnumber1[temp]-48;
		tempint2 = binnumber2[temp]-48;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{
			result[i]='0';
			carry=0;
		}
		if (tempint3==1)
		{
			result[i]='1';
			carry=0;
		}
		if (tempint3==2)
		{
			result[i]='0';
			carry=1;
		}
		if (tempint3==3)
		{
			result[i]='1';
			carry=1;
		}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
}

char *binaryget(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if ((i>=16)&&(ch!=8))
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
			cursor-=16;
		}
		comman1(350,binrow,489,binrow+20,15);
		cursor+=8;
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(350,binrow,489,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}

char *binaryget1(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
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
			cursor-=16;
		}
		comman1(400,binrow,445,binrow+20,15);
		cursor+=8;
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(400,binrow,445,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}

void bincheck(char binnumber[],int *btod  )
{
	for (int i=0;i<strlen(binnumber);i++)
		if ((binnumber[i] > '1')||(binnumber[i] < '0'))
		{
			*btod=1;
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
			int flag;
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
						i=strlen(binnumber);
						cursoroff();
					}
				}
			}
			Flush();
		}
}

/*	Functions of Octal Adition	*/

void octaladition(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,479,170,15);
		comman1(400,200,479,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(140,3,"Octal Addition");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first Octal Number   :");
		outtextxy(90,200,"Enter the Second Octal Number :");
		if (first)
		{
			strcpy(binnumber[0],octalget(415,153,150));
			octalcheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(415,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],octalget(415,203,200));
			octalcheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	i=0;
	while (temp!=-1)
	{
		tempint1 = binnumber[0][temp]-48;
		tempint2 = binnumber[1][temp]-48;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{result[i]='0';carry=0;}
		if (tempint3==1)
		{result[i]='1';carry=0;}
		if (tempint3==2)
		{result[i]='2';carry=0;}
		if (tempint3==3)
		{result[i]='3';carry=0;}
		if (tempint3==4)
		{result[i]='4';carry=0;}
		if (tempint3==5)
		{result[i]='5';carry=0;}
		if (tempint3==6)
		{result[i]='6';carry=0;}
		if (tempint3==7)
		{result[i]='7';carry=0;}
		if (tempint3==8)
		{result[i]='0';carry=1;}
		if (tempint3==9)
		{result[i]='1';carry=1;}
		if (tempint3==10)
		{result[i]='2';carry=1;}
		if (tempint3==11)
		{result[i]='3';carry=1;}
		if (tempint3==12)
		{result[i]='4';carry=1;}
		if (tempint3==13)
		{result[i]='5';carry=1;}
		if (tempint3==14)
		{result[i]='6';carry=1;}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	settextstyle(8,0,1);
	outtextxy(150,270,"Addition Result is ");
	outtextxy(350,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of Octal Subtraction		*/

void octalsubtraction(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,479,170,15);
		comman1(400,200,479,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(85,3,"Octal Subtraction");
		char getnumber[20];
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first Octal Number   :");
		outtextxy(90,200,"Enter the Second Octal Number :");
		if (first)
		{
			strcpy(binnumber[0],octalget(415,153,150));
			octalcheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(415,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],octalget(415,203,200));
			octalcheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0];
	tempint5=atol(binnumber[1]);
	if (temp==1)
		tempint6=7;
	if (temp==2)
		tempint6=77;
	if (temp==3)
		tempint6=777;
	if (temp==4)
		tempint6=7777;
	if (temp==5)
		tempint6=77777;
	if (temp==6)
		tempint6=777777;
	tempint6=tempint6-tempint5;
	tempint6++;
	ltoa(tempint6,binnumber[1],10);
	carry=0;tempstr1[1]='\0';temp=strlen(binnumber[1])-1;
	for (i=(strlen(binnumber[1])-1);i>=0;i--)
	{

		if (binnumber[1][temp]=='8')
		{
			binnumber[1][temp]='0';
			tempstr1[0]=binnumber[1][temp-1];
			tempint6=atol(tempstr1);
			tempint6++;
			itoa(tempint6,tempstr1,10);
			binnumber[1][temp-1]=tempstr1[0];
		}
		temp--;

	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	i=0;
	while (temp!=-1)
	{
		tempint4 = binnumber[0][temp]-48;
		tempint5 = binnumber[1][temp]-48;
		tempint6 = carry+tempint4+tempint5;
		if (tempint6==0)
		{result[i]='0';carry=0;}
		if (tempint6==1)
		{result[i]='1';carry=0;}
		if (tempint6==2)
		{result[i]='2';carry=0;}
		if (tempint6==3)
		{result[i]='3';carry=0;}
		if (tempint6==4)
		{result[i]='4';carry=0;}
		if (tempint6==5)
		{result[i]='5';carry=0;}
		if (tempint6==6)
		{result[i]='6';carry=0;}
		if (tempint6==7)
		{result[i]='7';carry=0;}
		if (tempint6==8)
		{result[i]='0';carry=1;}
		if (tempint6==9)
		{result[i]='1';carry=1;}
		if (tempint6==10)
		{result[i]='2';carry=1;}
		if (tempint6==11)
		{result[i]='3';carry=1;}
		if (tempint6==12)
		{result[i]='4';carry=1;}
		if (tempint6==13)
		{result[i]='5';carry=1;}
		if (tempint6==14)
		{result[i]='6';carry=1;}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
/*	tempint4=atoi(result);
	tempint4++;
	itoa(tempint4,result,10);*/
	settextstyle(8,0,1);
	outtextxy(130,270,"Substraction Result is ");
	outtextxy(380,270,result);


}


/*	Functions of Octal Multiplication	*/

void octalmultiplication(void)
{
	comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
	comman1(400,150,479,170,15);
	comman1(400,200,479,220,15);
	setcolor(0);
	settextstyle(7,0,6);
	outtextxy(50,3,"Octal Multiplication");
	char getnumber[20];
	settextstyle(2,0,5);
	outtextxy(90,150,"Enter the first Octal Number   :");
	outtextxy(90,200,"Enter the Second Octal Number :");

	octalget(415,153,150);
	octalget(415,203,200);
}

char *octalget(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if ((i>=6)&&(ch!=8))
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
			cursor-=16;
		}
		cursor+=8;
		comman1(400,binrow,479,binrow+20,15);
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(400,binrow,479,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}

void octalcheck(char binnumber[],int *btod)
{
	for (int i=0;i<strlen(binnumber);i++)
		if ((binnumber[i] > '7')||(binnumber[i] < '0'))
		{
			*btod=1;
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
			int flag;
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
						i=strlen(binnumber);
						cursoroff();
					}
				}
			}
			Flush();
		}
}

/*	Functions of Hexadecimal Adition	*/

void hexaadition(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,479,170,15);
		comman1(400,200,479,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(25,3,"HexaDecimal Adition");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first HexaDecimal Number   :");
		outtextxy(90,200,"Enter the Second HexaDecimal Number :");
		if (first)
		{
			strcpy(binnumber[0],hexaget(415,153,150));
			hexacheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(415,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],hexaget(415,203,200));
			hexacheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	i=0;
	char tempstr[2];
	tempstr[1]='\0';
	while (temp!=-1)
	{
		tempstr[0] = binnumber[0][temp];
		if ((tempstr[0] >='0')&&(tempstr[0] <='9'))
			tempint1 = atoi(tempstr);
		if ((tempstr[0] =='A')||(tempstr[0] =='a'))
			tempint1 = 10;
		if ((tempstr[0] =='B')||(tempstr[0] =='b'))
			tempint1 = 11;
		if ((tempstr[0] =='C')||(tempstr[0] =='c'))
			tempint1 = 12;
		if ((tempstr[0] =='D')||(tempstr[0] =='d'))
			tempint1 = 13;
		if ((tempstr[0] =='E')||(tempstr[0] =='e'))
			tempint1 = 14;
		if ((tempstr[0] =='F')||(tempstr[0] =='f'))
			tempint1 = 15;
		tempstr[0] = binnumber[1][temp];
		if ((tempstr[0] >='0')&&(tempstr[0] <='9'))
			tempint2 = atoi(tempstr);
		if ((tempstr[0] =='A')||(tempstr[0] =='a'))
			tempint2 = 10;
		if ((tempstr[0] =='B')||(tempstr[0] =='b'))
			tempint2 = 11;
		if ((tempstr[0] =='C')||(tempstr[0] =='c'))
			tempint2 = 12;
		if ((tempstr[0] =='D')||(tempstr[0] =='d'))
			tempint2 = 13;
		if ((tempstr[0] =='E')||(tempstr[0] =='e'))
			tempint2 = 14;
		if ((tempstr[0] =='F')||(tempstr[0] =='f'))
			tempint2 = 15;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{result[i]='0';carry=0;}
		if (tempint3==1)
		{result[i]='1';carry=0;}
		if (tempint3==2)
		{result[i]='2';carry=0;}
		if (tempint3==3)
		{result[i]='3';carry=0;}
		if (tempint3==4)
		{result[i]='4';carry=0;}
		if (tempint3==5)
		{result[i]='5';carry=0;}
		if (tempint3==6)
		{result[i]='6';carry=0;}
		if (tempint3==7)
		{result[i]='7';carry=0;}
		if (tempint3==8)
		{result[i]='8';carry=0;}
		if (tempint3==9)
		{result[i]='9';carry=0;}
		if (tempint3==10)
		{result[i]='A';carry=0;}
		if (tempint3==11)
		{result[i]='B';carry=0;}
		if (tempint3==12)
		{result[i]='C';carry=0;}
		if (tempint3==13)
		{result[i]='D';carry=0;}
		if (tempint3==14)
		{result[i]='E';carry=0;}
		if (tempint3==15)
		{result[i]='F';carry=0;}

		if (tempint3==16)
		{result[i]='0';carry=1;}
		if (tempint3==17)
		{result[i]='1';carry=1;}
		if (tempint3==18)
		{result[i]='2';carry=1;}
		if (tempint3==19)
		{result[i]='3';carry=1;}
		if (tempint3==20)
		{result[i]='4';carry=1;}
		if (tempint3==21)
		{result[i]='5';carry=1;}
		if (tempint3==22)
		{result[i]='6';carry=1;}
		if (tempint3==23)
		{result[i]='7';carry=1;}
		if (tempint3==24)
		{result[i]='8';carry=1;}
		if (tempint3==25)
		{result[i]='9';carry=1;}
		if (tempint3==26)
		{result[i]='A';carry=1;}
		if (tempint3==27)
		{result[i]='B';carry=1;}
		if (tempint3==28)
		{result[i]='C';carry=1;}
		if (tempint3==29)
		{result[i]='D';carry=1;}
		if (tempint3==30)
		{result[i]='E';carry=1;}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	settextstyle(8,0,1);
	outtextxy(150,270,"Addition Result is ");
	outtextxy(350,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of Hexadecimal Subtraction	*/

void hexasubtraction(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,479,170,15);
		comman1(400,200,479,220,15);
		setcolor(0);
		settextstyle(7,0,5);
		outtextxy(45,10,"HexaDecimal Subtraction");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first HexaDecimal Number   :");
		outtextxy(90,200,"Enter the Second HexaDecimal Number :");
		if (first)
		{
			strcpy(binnumber[0],hexaget(415,153,150));
			hexacheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(415,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],hexaget(415,203,200));
			hexacheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	strcpy(tempnumber,binnumber[1]);
	temp=numberlength[0]-1;
	for (i=0;i<numberlength[0];i++)
	{
		if ((tempnumber[temp]=='A')||(tempnumber[temp]=='a'))
			tempint1=10;
		if ((tempnumber[temp]=='B')||(tempnumber[temp]=='b'))
			tempint1=11;
		if ((tempnumber[temp]=='C')||(tempnumber[temp]=='c'))
			tempint1=12;
		if ((tempnumber[temp]=='D')||(tempnumber[temp]=='d'))
			tempint1=13;
		if ((tempnumber[temp]=='E')||(tempnumber[temp]=='e'))
			tempint1=14;
		if ((tempnumber[temp]=='F')||(tempnumber[temp]=='f'))
			tempint1=15;
		if ((tempnumber[temp]>='0')&&(tempnumber[temp]<='9'))
		{
			tempstr2[1]='\0';
			tempstr2[0]=tempnumber[temp];
			tempint1=atoi(tempstr2);
		}
		if (!carry)
		{
			tempint1=15-tempint1+1;
			if (tempint1==16)
			{
				tempint1=0;
				carry=0;
			}
			else
				carry=1;
		}
		else
			tempint1=15-tempint1;
		if (tempint1==15)
			binnumber[1][temp]='F';
		if (tempint1==14)
			binnumber[1][temp]='E';
		if (tempint1==13)
			binnumber[1][temp]='D';
		if (tempint1==12)
			binnumber[1][temp]='C';
		if (tempint1==11)
			binnumber[1][temp]='B';
		if (tempint1==10)
			binnumber[1][temp]='A';
		if ((tempint1>=0)&&(tempint1<=9))
		{
			itoa(tempint1,tempstr1,10);
			binnumber[1][temp]=tempstr1[0];
		}
		temp--;
	}
	i=0;
	char tempstr[2];
	tempstr[1]='\0';
	temp=numberlength[0]-1;
	carry=0;
	while (temp!=-1)
	{
		tempstr[0] = binnumber[0][temp];
		if ((tempstr[0] >='0')&&(tempstr[0] <='9'))
			tempint1 = atoi(tempstr);
		if ((tempstr[0] =='A')||(tempstr[0] =='a'))
			tempint1 = 10;
		if ((tempstr[0] =='B')||(tempstr[0] =='b'))
			tempint1 = 11;
		if ((tempstr[0] =='C')||(tempstr[0] =='c'))
			tempint1 = 12;
		if ((tempstr[0] =='D')||(tempstr[0] =='d'))
			tempint1 = 13;
		if ((tempstr[0] =='E')||(tempstr[0] =='e'))
			tempint1 = 14;
		if ((tempstr[0] =='F')||(tempstr[0] =='f'))
			tempint1 = 15;
		tempstr[0] = binnumber[1][temp];
		if ((tempstr[0] >='0')&&(tempstr[0] <='9'))
			tempint2 = atoi(tempstr);
		if ((tempstr[0] =='A')||(tempstr[0] =='a'))
			tempint2 = 10;
		if ((tempstr[0] =='B')||(tempstr[0] =='b'))
			tempint2 = 11;
		if ((tempstr[0] =='C')||(tempstr[0] =='c'))
			tempint2 = 12;
		if ((tempstr[0] =='D')||(tempstr[0] =='d'))
			tempint2 = 13;
		if ((tempstr[0] =='E')||(tempstr[0] =='e'))
			tempint2 = 14;
		if ((tempstr[0] =='F')||(tempstr[0] =='f'))
			tempint2 = 15;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{result[i]='0';carry=0;}
		if (tempint3==1)
		{result[i]='1';carry=0;}
		if (tempint3==2)
		{result[i]='2';carry=0;}
		if (tempint3==3)
		{result[i]='3';carry=0;}
		if (tempint3==4)
		{result[i]='4';carry=0;}
		if (tempint3==5)
		{result[i]='5';carry=0;}
		if (tempint3==6)
		{result[i]='6';carry=0;}
		if (tempint3==7)
		{result[i]='7';carry=0;}
		if (tempint3==8)
		{result[i]='8';carry=0;}
		if (tempint3==9)
		{result[i]='9';carry=0;}
		if (tempint3==10)
		{result[i]='A';carry=0;}
		if (tempint3==11)
		{result[i]='B';carry=0;}
		if (tempint3==12)
		{result[i]='C';carry=0;}
		if (tempint3==13)
		{result[i]='D';carry=0;}
		if (tempint3==14)
		{result[i]='E';carry=0;}
		if (tempint3==15)
		{result[i]='F';carry=0;}

		if (tempint3==16)
		{result[i]='0';carry=1;}
		if (tempint3==17)
		{result[i]='1';carry=1;}
		if (tempint3==18)
		{result[i]='2';carry=1;}
		if (tempint3==19)
		{result[i]='3';carry=1;}
		if (tempint3==20)
		{result[i]='4';carry=1;}
		if (tempint3==21)
		{result[i]='5';carry=1;}
		if (tempint3==22)
		{result[i]='6';carry=1;}
		if (tempint3==23)
		{result[i]='7';carry=1;}
		if (tempint3==24)
		{result[i]='8';carry=1;}
		if (tempint3==25)
		{result[i]='9';carry=1;}
		if (tempint3==26)
		{result[i]='A';carry=1;}
		if (tempint3==27)
		{result[i]='B';carry=1;}
		if (tempint3==28)
		{result[i]='C';carry=1;}
		if (tempint3==29)
		{result[i]='D';carry=1;}
		if (tempint3==30)
		{result[i]='E';carry=1;}
		i++;temp--;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	settextstyle(8,0,1);
	outtextxy(130,270,"Subtraction Result is ");
	outtextxy(355,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of Hexadecimal Multiplication	*/

void hexamultiplication(void)
{
	comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
	comman1(400,150,479,170,15);
	comman1(400,200,479,220,15);
	setcolor(0);
	settextstyle(7,0,5);
	outtextxy(15,10,"HexaDecimal Multiplication");
	char getnumber[20];
	settextstyle(2,0,5);
	outtextxy(90,150,"Enter the first HexaDecimal Number   :");
	outtextxy(90,200,"Enter the Second HexaDecimal Number :");

	octalget(415,153,150);
	octalget(415,203,200);
}

char *hexaget(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if ((i>=6)&&(ch!=8))
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
			cursor-=16;
		}
		cursor+=8;
		comman1(400,binrow,479,binrow+20,15);
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(400,binrow,479,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}

void hexacheck(char binnumber[],int *btod)
{
	for (int i=0;i<strlen(binnumber);i++)
		if ((binnumber[i] >='0'&&binnumber[i] <= '9')||((binnumber[i] >= 'A')&&(binnumber[i] <= 'F'))||(binnumber[i] >= 'a')&&(binnumber[i] <= 'f'))
		{}//Dummy
		else
		{
			*btod=1;
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
			int flag;
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
						i=strlen(binnumber);
						cursoroff();
					}
				}
			}
			Flush();
		}
}

/*	Functions of BCD Adition	*/

void bcdadition(void)
{
	int btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,479,170,15);
		comman1(400,200,479,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(150,3,"BCD Adition");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first BCD Number   :");
		outtextxy(90,200,"Enter the Second BCD Number :");
		if (first)
		{
			strcpy(binnumber[0],bcdget(415,153,150));
			bcdcheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(415,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],bcdget(415,203,200));
			bcdcheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	i=0;
	while (temp!=-1)
	{
		tempint1 = binnumber[0][temp]-48;
		tempint2 = binnumber[1][temp]-48;
		tempint3 = carry+tempint1+tempint2;
		if (tempint3==0)
		{
			result[i]='0';
			carry=0;
		}
		if (tempint3==1)
		{
			result[i]='1';
			carry=0;
		}
		if (tempint3==2)
		{
			result[i]='2';
			carry=0;
		}
		if (tempint3==3)
		{
			result[i]='3';
			carry=0;
		}
		if (tempint3==4)
		{
			result[i]='4';
			carry=0;
		}
		if (tempint3==5)
		{
			result[i]='5';
			carry=0;
		}
		if (tempint3==6)
		{
			result[i]='6';
			carry=0;
		}
		if (tempint3==7)
		{
			result[i]='7';
			carry=0;
		}
		if (tempint3==8)
		{
			result[i]='8';
			carry=0;
		}
		if (tempint3==9)
		{
			result[i]='9';
			carry=0;
		}
		if (tempint3==10)
		{
			result[i]='0';
			carry=1;
		}
		if (tempint3==11)
		{
			result[i]='1';
			carry=1;
		}
		if (tempint3==12)
		{
			result[i]='2';
			carry=1;
		}
		if (tempint3==13)
		{
			result[i]='3';
			carry=1;
		}
		if (tempint3==14)
		{
			result[i]='4';
			carry=1;
		}
		if (tempint3==15)
		{
			result[i]='5';
			carry=1;
		}
		if (tempint3==16)
		{
			result[i]='6';
			carry=1;
		}
		if (tempint3==17)
		{
			result[i]='7';
			carry=1;
		}
		if (tempint3==18)
		{
			result[i]='8';
			carry=1;
		}
		i++;temp--;
	}
	if (carry==1)
	{
		result[i]='1';
		i++;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	strcpy(resulttemp,result);
	result[0] = '\0';
	for (i=0;i<strlen(resulttemp);i++)
	{
		tempchar = resulttemp[i];
		if (tempchar == '0')
			strcat(result,"0000");
		if (tempchar == '1')
			strcat(result,"0001");
		if (tempchar == '2')
			strcat(result,"0010");
		if (tempchar == '3')
			strcat(result,"0011");
		if (tempchar == '4')
			strcat(result,"0100");
		if (tempchar == '5')
			strcat(result,"0101");
		if (tempchar == '6')
			strcat(result,"0110");
		if (tempchar == '7')
			strcat(result,"0111");
		if (tempchar == '8')
			strcat(result,"1000");
		if (tempchar == '9')
			strcat(result,"1001");
	}
	settextstyle(2,0,6);
	outtextxy(100,270,"Addition Result is ");
	outtextxy(290,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of BCD Subtraction	*/

void bcdsubtraction(void)
{
	int btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,479,170,15);
		comman1(400,200,479,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(100,3,"BCD Subtraction");
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first BCD Number   :");
		outtextxy(90,200,"Enter the Second BCD Number :");
		if (first)
		{
			strcpy(binnumber[0],bcdget(415,153,150));
			bcdcheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(415,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],bcdget(415,203,200));
			bcdcheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	temp=numberlength[0]-1;
	long int temp1;
	if (temp==0)
		temp1=9;
	if (temp==1)
		temp1=99;
	if (temp==2)
		temp1=999;
	if (temp==3)
		temp1=9999;
	if (temp==4)
		temp1=99999;
	if (temp==5)
		temp1=999999;
	tempint5=atol(binnumber[1]);
	tempint5=temp1-tempint5+1;
	ltoa(tempint5,binnumber[1],10);
	temp=numberlength[0]-1;
	i=0;
	while (temp!=-1)
	{
		tempint4 = binnumber[0][temp]-48;
		tempint5 = binnumber[1][temp]-48;
		tempint6 = carry+tempint4+tempint5;
		if (tempint6==0)
		{
			result[i]='0';
			carry=0;
		}
		if (tempint6==1)
		{
			result[i]='1';
			carry=0;
		}
		if (tempint6==2)
		{
			result[i]='2';
			carry=0;
		}
		if (tempint6==3)
		{
			result[i]='3';
			carry=0;
		}
		if (tempint6==4)
		{
			result[i]='4';
			carry=0;
		}
		if (tempint6==5)
		{
			result[i]='5';
			carry=0;
		}
		if (tempint6==6)
		{
			result[i]='6';
			carry=0;
		}
		if (tempint6==7)
		{
			result[i]='7';
			carry=0;
		}
		if (tempint6==8)
		{
			result[i]='8';
			carry=0;
		}
		if (tempint6==9)
		{
			result[i]='9';
			carry=0;
		}
		if (tempint6==10)
		{
			result[i]='0';
			carry=1;
		}
		if (tempint6==11)
		{
			result[i]='1';
			carry=1;
		}
		if (tempint6==12)
		{
			result[i]='2';
			carry=1;
		}
		if (tempint6==13)
		{
			result[i]='3';
			carry=1;
		}
		if (tempint6==14)
		{
			result[i]='4';
			carry=1;
		}
		if (tempint6==15)
		{
			result[i]='5';
			carry=1;
		}
		if (tempint6==16)
		{
			result[i]='6';
			carry=1;
		}
		if (tempint6==17)
		{
			result[i]='7';
			carry=1;
		}
		if (tempint6==18)
		{
			result[i]='8';
			carry=1;
		}
		i++;temp--;
	}
	result[i]='\0';
	strcpy(resulttemp,result);
	i=0;
	temp=strlen(result)-1;
	while (temp!=-1)
	{
		result[i]=resulttemp[temp];
		i++;temp--;
	}
	strcpy(resulttemp,result);
	result[0] = '\0';
	for (i=0;i<strlen(resulttemp);i++)
	{
		tempchar = resulttemp[i];
		if (tempchar == '0')
			strcat(result,"0000");
		if (tempchar == '1')
			strcat(result,"0001");
		if (tempchar == '2')
			strcat(result,"0010");
		if (tempchar == '3')
			strcat(result,"0011");
		if (tempchar == '4')
			strcat(result,"0100");
		if (tempchar == '5')
			strcat(result,"0101");
		if (tempchar == '6')
			strcat(result,"0110");
		if (tempchar == '7')
			strcat(result,"0111");
		if (tempchar == '8')
			strcat(result,"1000");
		if (tempchar == '9')
			strcat(result,"1001");
	}
	settextstyle(2,0,6);
	outtextxy(80,270,"Subtraction Result is ");
	outtextxy(295,270,result);
/*	if (strlen(result)==0);
		outtextxy(310,270,"0");*/
}

/*	Functions of BCD Multiplication		*/

void bcdmultiplication(void)
{
	btod=1,first=1;
	while(btod)
	{
		btod=0;
		comman(getmaxx()/2-250,getmaxy()/2-125,getmaxx()/2+250,getmaxy()/2+125,7);
		comman1(400,150,430,170,15);
		comman1(400,200,430,220,15);
		setcolor(0);
		settextstyle(7,0,6);
		outtextxy(60,3,"BCD Multiplication");
		char getnumber[20];
		settextstyle(2,0,5);
		outtextxy(90,150,"Enter the first BCD Number   :");
		outtextxy(90,200,"Enter the Second BCD Number :");
		if (first)
		{
			strcpy(binnumber[0],bcdget1(405,153,150));
			bcdcheck(binnumber[0],&btod);
			if (btod)
				first=1;
			else
				first=0;
		}
		outtextxy(405,153,binnumber[0]);
		if (!btod)
		{
			strcpy(binnumber[1],bcdget1(405,203,200));
			bcdcheck(binnumber[1],&btod);
		}
	}
	for (int i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	if (numberlength[0]<numberlength[1])
	{
		temp=numberlength[1]-numberlength[0];
		strcpy(tempnumber,binnumber[0]);
		i=0;
		while (temp!=0)
		{
			binnumber[0][i]='0';
			i++;temp--;
		}
		binnumber[0][i]='\0';
		strcat(binnumber[0],tempnumber);
	}
	if (numberlength[1]<numberlength[0])
	{
		temp=numberlength[0]-numberlength[1];
		strcpy(tempnumber,binnumber[1]);
		i=0;
		while (temp!=0)
		{
			binnumber[1][i]='0';
			i++;temp--;
		}
		binnumber[1][i]='\0';
		strcat(binnumber[1],tempnumber);
	}
	for (i=0;i<2;i++)
		numberlength[i]=strlen(binnumber[i]);
	tempint1=atoi(binnumber[0]);
	tempint2=atoi(binnumber[1]);
	tempint3=tempint1*tempint2;
	itoa(tempint3,resulttemp,10);
	result[0] = '\0';
	for (i=0;i<strlen(resulttemp);i++)
	{
		tempchar = resulttemp[i];
		if (tempchar == '0')
			strcat(result,"0000");
		if (tempchar == '1')
			strcat(result,"0001");
		if (tempchar == '2')
			strcat(result,"0010");
		if (tempchar == '3')
			strcat(result,"0011");
		if (tempchar == '4')
			strcat(result,"0100");
		if (tempchar == '5')
			strcat(result,"0101");
		if (tempchar == '6')
			strcat(result,"0110");
		if (tempchar == '7')
			strcat(result,"0111");
		if (tempchar == '8')
			strcat(result,"1000");
		if (tempchar == '9')
			strcat(result,"1001");
	}
	settextstyle(8,0,1);
	outtextxy(100,270,"Multiplication Result is ");
	outtextxy(350,270,result);
}

char *bcdget(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if ((i>=6)&&(ch!=8))
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
			cursor-=16;
		}
		cursor+=8;
		comman1(400,binrow,479,binrow+20,15);
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(400,binrow,479,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}

char *bcdget1(int col,int row,int binrow)
{
	char ch,get[16];
	int i=0,cursor=col;
	setcolor(0);
	get[0] = '\0';
	outtextxy(cursor,row+5,"-");
	while ((ch=getch()) != 13)
	{
		if ((i>=2)&&(ch!=8))
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
			cursor-=16;
		}
		cursor+=8;
		comman1(400,binrow,430,binrow+20,15);
		setcolor(0);
		outtextxy(cursor,row+5,"-");
		outtextxy(col, row, get);
		i++;
		}
	}
	comman1(400,binrow,430,binrow+20,15);
	setcolor(0);
	outtextxy(col, row, get);
	return(get);
}

void bcdcheck(char binnumber[],int *btod)
{
	for (int i=0;i<strlen(binnumber);i++)
		if ((binnumber[i] > '9')||(binnumber[i] < '0'))
		{
			*btod=1;
			desion2();
			settextstyle(8,0,4);
			outtextxy(123,135,"<ERROR>");
			settextstyle(2,0,5);
			outtextxy(220,200,"BCD Numbers use only 0 to 9 Digits");
			outtextxy(240,220,"You are Worng enter the Number");
			outtextxy(310,240,"Try Again");
			comman(getmaxx()/2-50,270,getmaxx()/2+50,300,3);
			setcolor(0);
			settextstyle(1,0,4);
			outtextxy(getmaxx()/2-20,265,"Ok");
			i = 0;
			setcursorpos(getmaxx( )/2,getmaxy()/2);
			cursoron();
			int flag;
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
						i=strlen(binnumber);
						cursoroff();
					}
				}
			}
			Flush();
		}

}

