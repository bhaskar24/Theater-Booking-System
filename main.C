#include<conio.h>
#include<string.h>
#include<stdio.h>

#define theatre 5
#define g1 5
#define g2 9
#define tscreen 3

struct th_b_s
{
 int grp1[g1][g2];
 int grp2[g1][g2];

}th_b[7][tscreen];

struct bkng
{
 char t[40];
 char s1[50],s2[50],s3[50];
}th[5];

struct str
{
 char n11[50];
 char fn1[50];
 int row1,col1,gr1,thea1,scr1;
}st[90];

void entry(FILE *fp);      //function declaration
void create_b(FILE *fp,FILE *p,FILE *sr,FILE *rx);   //function declaration
void view(FILE *fp);
void seat_set(FILE *sr,int thea,int scr,int row,int col,int gr);
void i_seats(FILE *sr);
void p_s(FILE *sr,int thea,int scr);
void lp_s(FILE *sr,int thea,int scr);
void r_r(FILE *p,FILE *rx);
void view_s1(FILE *sr);

void v_ss(FILE *sr,FILE *p)
{
 int i;

 sr=fopen("sea.txt","rb+");
 if(sr==NULL)
 {
  sr=fopen("sea.txt","wb+");
  if(sr==NULL)
  {
   printf("Error in opening the file\n");
  }
 }
 rewind(p);
 p=fopen("v_recod.txt","rb+");
 if(p==NULL)
 {
  p=fopen("v_recod.txt","wb+");
  if(p==NULL)
  {
   printf("Error in opening the file\n");
  }
 }

  for(i=1;i<=1;i++)
  {
   fscanf(p,"%s %s %d %d %d %d %d",st[i].n11,st[i].fn1,&st[i].row1,&st[i].col1,&st[i].gr1,&st[i].thea1,&st[i].scr1);
   getch();
   seat_set(sr,st[i].thea1,st[i].scr1,st[i].row1,st[i].col1,st[i].gr1);
  }
  view_s1(sr);

  fclose(sr);
  fclose(p);
}
int main()       //main starts from here
{
 FILE *fp,*p,*sr,*rx;
 int s;
 int cha,x,i=3;

 rx=fopen("flag.txt","rb+");
 x=getw(rx);
 fprintf(rx,"%d",x);
 fclose(rx);

 printf("   --------------------------------------------------------------------------\n");
 printf("                   Welcome to the Theatre Book System     \n");
 printf("   --------------------------------------------------------------------------\n");
 printf("\n");

 //printf("Enter the password if you legal authority\n");
 //scanf("%d",&s);


 while(1)
 {
  printf("   --------------------------------------------------------------------------\n");
  printf("                   Welcome to the Theatre Book System     \n");
  printf("   --------------------------------------------------------------------------\n");
  printf("\n");

  printf("1.Enter new movie\n");
  printf("2.Create Booking of a Viewer\n");
  printf("3.View Movies according to theatre\n");
  printf("4.Exit\n");
  printf("6.Initialize all seats in all screen of all theatre to NULL.\n  But this function run once a day.So that next day we create new booking\n");
  printf("7.View recent ticket sold\n");
  printf("8.Total seats Vaccant and Book\n");
  printf("Enter your choice\n");
  scanf("%d",&cha);
  switch(cha)
  {
   case 1:entry(fp);
	  break;
   case 2:create_b(fp,p,sr,rx);
	  break;
   case 3:view(fp);
	  break;
   case 4://exit(0);
	  break;
   //case 5:view_s1(sr);
     //	  break;
   case 6:i_seats(sr);
	  break;
   case 7:r_r(p,rx);
	  break;
   case 8:v_ss(sr,p);
	  break;
   default :printf("Wrong choice\n");
  }
 }
}
     //getch();
     //return;


  // end of main

/*-----------------------Function Definations-------------------------------*/

void r_r(FILE *p,FILE *rx)
{
 int x;

 rx=fopen("flag.txt","rb+");
 if(rx==NULL)
 {
  rx=fopen("flag.txt","wb+");
  if(rx==NULL)
  {
   printf("Error in opening the file\n");
  }
 }
 p=fopen("v_recod.txt","rb+");
 if(p==NULL)
 {
  p=fopen("v_recod.txt","wb+");
  if(p==NULL)
  {
   printf("Error in opening the file\n");
  }
 }

 fscanf(p,"%s %s %d %d %d %d %d \n",st[x].n11,st[x].fn1,&st[x].row1,&st[x].col1,&st[x].gr1,&st[x].thea1,&st[x].scr1);
 printf("%s in %s movie sold tickets from row %d & in column %d in group %d of theatre %d in screen %d\n",st[x].n11,st[x].fn1,st[x].row1,st[x].col1,st[x].gr1,st[x].thea1,st[x].scr1);

 fclose(p);
}
void i_seats(FILE *sr)
{
 int i,j,k,l;

 sr=fopen("sea.txt","rb+");
 if(sr==NULL)
 {
  sr=fopen("sea.txt","wb+");
  if(sr==NULL)
  {
   printf("Error in opening the file\n");
  }
 }
 for(i=1;i<=7;i++)
 {
  for(j=1;j<=3;j++)
  {
   for(k=1;k<=g1;k++)
   {
    for(l=1;l<=g2;l++)
    {
     th_b[i][j].grp1[k][l]=0;
     fprintf(sr,"%d",th_b[i][j].grp1[k][l]);
    }

   }

   for(k=1;k<=g1;k++)
   {
    for(l=1;l<=g2;l++)
    {
     th_b[i][j].grp2[k][l]=0;
     fprintf(sr,"%d",th_b[i][j].grp2[k][l]);
    }

   }
  }

 }
 printf("All seats are initialized\n");
 fclose(sr);
}

 void seat_set(FILE *sr,int thea,int scr,int row,int col,int gr)  // fill seats acc to viewer,complete
{
 int i,j,k,l;//,m=n+col;

 sr=fopen("sea.txt","rb+");
 if(sr==NULL)
 {
  sr=fopen("sea.txt","wb+");
  if(sr==NULL)
  {
   printf("Error in opening the file\n");
  }
 }
 for(i=1;i<=5;i++) //for start
 {
  for(j=1;j<=3;j++)
  {
   for(k=1;k<=5;k++)
   {
    for(l=1;l<=9;l++)
    {
     fscanf(sr,"%d",&th_b[i][j].grp1[k][l]);
      if(i==thea && j == scr)
       {
	if(k == row && l == col)
	{
	   if(gr==1)
	   {
	    th_b[i][j].grp1[row][col]=1;
	    fprintf(sr,"%d",th_b[i][j].grp1[k][l]);
	  }
	}
       }
    }
   }
  for(k=1;k<=5;k++)
   {
    for(l=1;l<=9;l++)
    {
     fscanf(sr," %d ",&th_b[i][j].grp2[k][l]);
     if(i==thea && j == scr)
     {
	if(i==thea && j == scr)
       {
	if(k == row && l == col)
	{
	  if(gr == 2)
	  {
	   th_b[i][j].grp2[k][l]=1;
	   fprintf(sr,"%d",th_b[i][j].grp2[k][l]);
	  }
	}
       }
     }

    }
   }
  }
 }
 fclose(sr);
}

 void entry(FILE *fp)
{
   int i;

 fp=fopen("tempb.txt","rb+");
 if(fp==NULL)
 {
  fp=fopen("tempb.txt","wb+");
  if(fp==NULL)
  {
   printf("Error in opening file\n");
  }
 }

   fseek(fp,0L,0);
  for(i=1;i<=5;i++)
 {
  fflush(stdin);
  printf("Enter %d theatre name\n",i);
  gets(th[i].t);
  fprintf(fp,"%s",th[i].t);
  fprintf(fp,"\n");

  printf("Enter movie in 1 Screen\n");
  gets(th[i].s1);
  fprintf(fp,"%s",th[i].s1);
  fprintf(fp,"\n");
  //printf("\n");

  printf("Enter movie in 2 Screen\n");
  gets(th[i].s2);
  //printf("\n");

  while((strcmp(th[i].s1,th[i].s2))==0)
  {
   printf("You enter same movie in same screen\n,So TRY AGAIN!\n");
   printf("Enter movie in 2 Screen\n");
   gets(th[i].s2);
   printf("\n");
  }
   fprintf(fp,"%s",th[i].s2);
   fprintf(fp,"\n");

   printf("Enter movie in 3 Screen\n");
   scanf("%s",th[i].s3);
   printf("\n");

  while((strcmp(th[i].s1,th[i].s3))==0)
  {
   printf("You enter same movie in same scree,So Try Again!\n");
   printf("Enter movie in 3 Screen\n");
   scanf("%s",th[i].s3);
   printf("\n");
  }

  while((strcmp(th[i].s2,th[i].s3))==0 )
  {
   printf("You enter same movie in same scree,So Try Again!\n");
   printf("Enter movie in 3 Screen\n");
   scanf("%s",th[i].s3);
   printf("\n");
  }

  fprintf(fp,"%s",th[i].s3);
  fprintf(fp,"\n");
 }

 fclose(fp);
}
void p_s(FILE *sr,int thea,int scr)
{
   int i,j,k,l;

 sr=fopen("sea.txt","rb+");
 if(sr==NULL)
 {
  sr=fopen("sea.txt","wb+");
  if(sr==NULL)
  {
   printf("Error in opening the file\n");
  }
 }
 for(i=1;i<=5;i++) //for start
 {
  for(j=1;j<=3;j++)
  {if(i==thea && j == scr){/*clrscr();*/}
   if(i==thea && j == scr){printf("Seats in screen %d of theatre %d\n",scr,thea);}
   for(k=1;k<=5;k++)
   {
    for(l=1;l<=9;l++)
    {
     fscanf(sr," %d ",&th_b[i][j].grp1[k][l]);
      if(i==thea && j == scr)
       {
	printf(" %d ",th_b[i][j].grp1[k][l]);
       }
    }
    if(i==thea && j == scr){printf("\n");}
   }
   if(i==thea && j == scr){printf("\n");}

   for(k=1;k<=5;k++)
   {
    for(l=1;l<=9;l++)
    {
     fscanf(sr," %d ",&th_b[i][j].grp2[k][l]);
     if(i==thea && j == scr)
       {
	printf(" %d ",th_b[i][j].grp2[k][l]);
       }
    }
    //fscanf(sr,"\n");
    if(i==thea && j == scr){printf("\n");}

   }if(i==thea && j == scr){getch();}

    if(i==thea && j == scr)printf("\n");
  }
 }
 fclose(sr);
}
void create_b(FILE *fp,FILE *p,FILE *sr,FILE *rx)
{
 int i,gr,j,c=0,a[5][3],b[5],x;
 int thea,scr,row,col,n,temp=0,flag;
 char name[50],fname[50];
 int aq=0;

 fflush(stdin);

 rx=fopen("flag.txt","rb+");
 if(rx==NULL)
 {
  rx=fopen("flag.txt","wb+");
  if(rx==NULL)
  {
   printf("Error in opening file\n");
   return;
  }
 }

 fp=fopen("tempb.txt","rb+");
 if(fp==NULL)
 {
  fp=fopen("tempb.txt","wb+");
  if(fp==NULL)
  {
   printf("Error in opening file\n");
   return ;
  }
 }

 p=fopen("v_recod.txt","ab+");
 if(p==NULL)
 {
  p=fopen("v_recod.txt","rb+");
  if(p==NULL)
  {
   printf("Error in opening file\n");
   return ;
  }
 }
 printf("Enter Viewer name\n");
 gets(name);

 printf("Enter the Film Name\n");
 gets(fname);

 for(i=1;i<=5;i++)
 {
  b[i]=0;
 }

 for(i=1;i<=5;i++)
 {
  for(j=1;j<=tscreen;j++)
  {
   a[i][j]=0;
  }
 }
    //rewind(fp);
   for(i=1;i<=5;i++)
   {
     fscanf(fp,"%s",&th[i].t);

     fscanf(fp,"%s",&th[i].s1);
    if((strcmp(fname,th[i].s1))==0)
     {
       c++;
       a[i][1]=c;
       b[i]=i;

       aq++;
     }
     fscanf(fp,"%s",&th[i].s2);
     if(( strcmp(fname,th[i].s2))==0)
       {
	 c++;
	 a[i][2]=c;
	 b[i]=i;
	 aq++;
       }
      fscanf(fp,"%s",&th[i].s3);
     if((strcmp(fname,th[i].s3))==0)
       {
	 c++;
	 a[i][3]=c;
	 b[i]=i;

	 aq++;
       }

   }

 if(aq==0)
 {
  fflush(stdin);
  printf("%s",fname);printf(" movie is not display in any of the theatre\n");
  return;
 }

  for(i=1;i<=5;i++)
  {
   if( b[i]==1 || b[i]==2 || b[i]==3|| b[i]==4|| b[i]==5)
   {
    temp=temp+1;
    aq=b[i];
   }

  }

  if(temp >1 && temp<= 5)
  {
    printf("Movie is currently playing in more than 1 theatre\n");
    printf("Please check movie scedule\n");
    printf("Enter viewer choice,which theatre viewer is prefer\n");
    scanf("%d",&thea);
  }
  else if(temp==1)
	{
	 thea=aq;
	}
	else
	{
	 printf("Error in booking in verifying theatre\n");
	 return;
	}


    if((strcmp(fname,th[thea].s1))==0)  //check
     {
      scr=1;
     }
    else if(( strcmp(fname,th[thea].s2))==0)
	  {
	    scr=2;
	  }
	  else if((strcmp(fname,th[thea].s3))==0)
		 {
		  scr=3;
		 }
		 else
		 {
		  printf("Error in booking in verifying screen\n");
		  return;
		 }


 printf("Ether the description of ticket 1 for silver(Rs 100) & 2 for gold(Rs 150)\n");
 scanf("%d",&gr);
 printf("Select seats of screen \n");
 lp_s(sr,thea,scr);

 printf("Enter viewer choice row\n");
 scanf("%d",&row);
 printf("Enter viewer choice colum\n");
 scanf("%d",&col);
 seat_set(sr,thea,scr,row,col,gr);

 printf("Is this is first record of viewer,1 for yes,2 for no\n");
 scanf("%d",&flag);
 if(flag==1)
 {
  x=0;
 }
 else
    {
     x=getw(rx);
     fscanf(rx,"%2d",&x);
     x=x;
    }
 if(x>90)
 {
  printf("No seats\n");
  return ;
 }
  //i=1;
  strcpy(st[x].n11,name);
  fputs(st[x].n11,p);
  fprintf(p,"\n");
  strcpy(st[x].fn1,fname);
  fputs(st[x].fn1,p);
  fprintf(p,"\n");

  st[x].row1=row;
  st[x].col1=col;
  st[x].gr1=gr;
  st[x].thea1=thea;
  st[x].scr1=scr;
  fprintf(p,"%d %d %d %d %d\n",st[x].row1,st[x].col1,st[x].gr1,st[x].thea1,st[x].scr1);

 x=x+01;
 fprintf(rx,"%2d",x);
 printf("Booking is created\n\n");

 fclose(fp);
 fclose(sr);
 fclose(p);
}
void view(FILE *fp)//show movies and theatre
{
 int i;

 fp=fopen("tempb.txt","rb+");
 if(fp==NULL)
 {
  fp=fopen("tempb.txt","wb+");
  if(fp==NULL)
  {
   printf("Error in opening file\n");
   return;
  }
 }


  for(i=1;i<=5;i++)
  {
   fscanf(fp,"%s",th[i].t);
   printf("Name of %d theatre:-",i);
   puts(th[i].t);

   printf("Name of movie in 1st Screen:-");
   fscanf(fp,"%s",th[i].s1);
   puts(th[i].s1);

   printf("Name of movie in 2nd Screen:-");
   fscanf(fp,"%s",th[i].s2);
   puts(th[i].s2);

   printf("Name of movie in 3rd Screen:-");
   fscanf(fp,"%s",th[i].s3);
   puts(th[i].s3);

   printf("\n");
   getch();
  }

 fclose(fp);
}
void lp_s(FILE *sr,int thea,int scr)
{
 int i,j,k,l,p;
//  clrscr();

   sr=fopen("sea.txt","rb+");
   if(sr==NULL)
   {
    sr=fopen("sea.txt","wb+");
    if(sr==NULL)
     {
      printf("Error in opening file\n)");
      return ;
     }
   }

  for(i=1;i<=5;i++)
  {
    for(j=1;j<=3;j++)
    {
     if(i== thea && j== scr){printf("Seats of screen %d of theatre %d \n",j,i);}
      if(i== thea && j== scr){printf("   ");}
     for(p=1;p<=9;p++)
     {
       if(i== thea && j== scr){printf("");}
       if(i== thea && j== scr){printf(" C%d ",p);}
     }
      if(i== thea && j== scr){printf("\n   ");}
     for(p=1;p<=9;p++)
     {
       if(i== thea && j== scr){printf("----");}
     }
      if(i== thea && j== scr){printf("\n");}
     for(k=1;k<=5;k++)
     {
       if(i== thea && j== scr){printf("R%d ",k);}
      for(l=1;l<=9;l++)
      {
	if(i== thea && j== scr){printf(" ");}
       fscanf(sr,"%d",&th_b[i][j].grp1[k][l]);
	if(i== thea && j== scr){printf("|%d|",th_b[i][j].grp1[k][l]);if(k==3 && l==9){printf("\tFor Silver(Price for each seat is 100)");}}
      }
       if(i== thea && j== scr){printf("\n");}
      printf("   ");
      for(p=1;p<=9;p++)
     {
       if(i== thea && j== scr){printf("----");}
     }
       if(i== thea && j== scr){printf("\n");}
     }
       if(i== thea && j== scr){printf("\n");}
     for(k=6;k<=10;k++)
     {
       if(k>=5 && k<10)
	{
	  if(i== thea && j== scr){printf("R%d ",k);}
	}
	else
	{
	  if(i== thea && j== scr){printf("R%d",k);}
	}
      for(l=1;l<=9;l++)
      {
	if(i== thea && j== scr){printf(" ");}
       fscanf(sr,"%d",&th_b[i][j].grp2[k][l]);
	if(i== thea && j== scr){printf("|%d|",th_b[i][j].grp2[k][l]);if(k==8 && l==9){printf("\tFor Gold(Price for each seat is 150)");}}
      }
       if(i== thea && j== scr){printf("\n");}
       if(i== thea && j== scr){printf("   ");}
      for(p=1;p<=9;p++)
     {
       if(i== thea && j== scr){printf("----");}
     }
       if(i== thea && j== scr){printf("\n");}
     }

     if(i== thea && j== scr)
     {getch();
     }
     //
    }
     printf("\n");
  }
  fclose(sr);
}
 void view_s1(FILE *sr)//function to view seats,complete
 {
  int i,j,k,l,p;
//  clrscr();

   sr=fopen("sea.txt","rb+");
   if(sr==NULL)
   {
    sr=fopen("sea.txt","wb+");
    if(sr==NULL)
     {
      printf("Error in opening file\n)");
      return ;
     }
   }

  for(i=1;i<=5;i++)
  {
    for(j=1;j<=3;j++)
    {
     printf("Seats of screen %d of theatre %d \n",j,i);
     printf("   ");
     for(p=1;p<=9;p++)
     {
      printf("");
      printf(" C%d ",p);
     }
     printf("\n   ");
     for(p=1;p<=9;p++)
     {
      printf("----");
     }
     printf("\n");
     for(k=1;k<=5;k++)
     {
      printf("R%d ",k);
      for(l=1;l<=9;l++)
      {
       printf(" ");
       fscanf(sr,"%d",&th_b[i][j].grp1[k][l]);
       printf("|%d|",th_b[i][j].grp1[k][l]);if(k==3 && l==9){printf("\tFor Silver(Price for each seat is 100)");}
      }
      printf("\n");
      printf("   ");
      for(p=1;p<=9;p++)
     {
      printf("----");
     }
      printf("\n");
     }
      printf("\n");
     for(k=6;k<=10;k++)
     {
       if(k>=5 && k<10)
	{
	 printf("R%d ",k);
	}
	else
	{
	 printf("R%d",k);
	}
      for(l=1;l<=9;l++)
      {
       printf(" ");
       fscanf(sr,"%d",&th_b[i][j].grp2[k][l]);
       printf("|%d|",th_b[i][j].grp2[k][l]);if(k==8 && l==9){printf("\tFor Gold(Price for each seat is 150)");}
      }
      printf("\n");
      printf("   ");
      for(p=1;p<=9;p++)
     {
      printf("----");
     }
      printf("\n");
     }

     getch();
 //    clrscr();

    }

  }
  fclose(sr);
 }
