//   TO INITIALIZE MOUSE AND CHECK THE ISTALLATION OF DRIVER
int mouseinit()
{

	int mstatus;
	asm	{
			mov ax, 0
			int 33h
			mov mstatus,ax
		}
		 return (mstatus);
}
//   TO SET MOUSE POSITION ON SCREEN
void setcursorpos(int x,int y)
{
	asm	{
			mov ax, 4
			mov cx, x
			mov dx, y
			int  33h
		}
}
//  TO SHOW THE MOUSE POINTER
void cursoron()
{
	asm {
			mov ax,1
			int 33h
		}
}
//  TO HIDE THE MOUSE POINTER
void cursoroff()
{
	mouseinit();
}
int but,xpixel,ypixel;
//  GET THE VALUES OF CURRENT POSITION OF MOUSE
//   AND BUTTON STATUS
int getcursorpos(int *x,int *y)
{

	asm {
			mov ax,3
			int 33h
			mov xpixel,cx
			mov ypixel,dx
			mov but,bx
		}
		 *x=xpixel;
		 *y=ypixel;
		 return(but);
}
int x,y;