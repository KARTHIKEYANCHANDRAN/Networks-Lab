
// Karthi is genius

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node *next;
int coeff,pow;
}*head1=NULL,*head2=NULL,*head3=NULL,*head=NULL;
void append(int ce,int p,int equ)
{
struct node *temp, *r;
  if(equ==1)
  {
   head=head1;
  }
  else if(equ==2)
  {
   head=head2;
  }
  else
  {
   head=head3;
  }
temp=(struct node *)malloc(sizeof(struct node));
temp->coeff=ce;
temp->pow=p;
r=head;
  if(head==NULL)
  {
  head=temp;
  head->next=head;
  }
  else
  {
   while(r->next!=NULL)
    {
     r=r->next;
    }
   temp->next=NULL;
   r->next=temp;
  }
}
void display(int equ)
{
struct node *q;
 if(equ==1)
 {
 head=head1;
 }
 else if(equ==2)
 {
 head=head2;
 }
 else
 {
 head=head3;
 }
q=head;
 while(q->next!=NULL)
 {
 printf("%d%d",q->coeff,q->pow);
 q=q->next;
 }
printf("%d%d",q->coeff,q->pow);
}

void addpoly()
{
int sum;
struct node *c1,*c2,*d;
c1=head1;
c2=head2;
 while(c1!=NULL&&c2!=NULL)
 {
  if(c1->pow==c2->pow)
  {
  sum=c1->coeff + c2->coeff;
  append(sum,c1->pow,3);
  c1=c1->next;
  c2=c2->next;
  }
  else if(c1->pow > c2->pow)
  {
  append(c1->coeff,c1->pow,3);
  c1=c1->next;
  }
  else
  {
  append(c2->coeff,c2->pow,3);
  c2=c2->next;
  }
 }
 if(c1==NULL)
 {
  while(c2!=NULL)
  {
  append(c2->coeff,c2->pow,3);
  c2=c2->next;
  }
 }
 if(c2==NULL)
  {
  while(c1!=NULL)
  {
  append(c1->coeff,c1->pow,3);
  c1=c1->next;
  }
  }
}
void subpoly()
{
int sum;
struct node *c1,*c2,*d;
c1=head1;
c2=head2;
while(c1!=NULL&&c2!=NULL)
{
 if(c1->pow==c2->pow)
 {
 sum=c1->coeff - c2->coeff;
 append(sum,c1->pow,3);
 c1=c1->next;
 c2=c2->next;
 }
 else if(c1->pow > c2->pow)
 {
 append(c1->coeff,c1->pow,3);
 c1=c1->next;
 }
 else
 {
 append(-(c2->coeff),c2->pow,3);
 c2=c2->next;
 }
}
if(c1==NULL)
{
 while(c2!=NULL)
 {
 append(-(c2->coeff),c2->pow,3);
 c2=c2->next;
 }
}
if(c2==NULL)
{
 while(c1!=NULL)
 {
 append(c1->coeff,c1->pow,3);
 c1=c1->next;
 }
}
}
void main()
{
int ch,pc,t=1,r=1,pcoeff,ppow;
clrscr();
printf("Polynomial Equation Solving\n");
 printf("Enter the polynomial equation 1\n");
 while(t)
 {
 printf("Press 1=Add term\n 2=Exit\n");
 scanf("%d",&pc);
 switch(pc)
 {
 case 1:
  {
  printf("Enter the coefficint :\n");
  printf("Enter the power :\n");
  scanf("%d%d",&pcoeff,&ppow);
  append(pcoeff,ppow,1);
  break;
  }
 case 2:
  {
   t=0;
   break;
  }
  }
  }
printf("Enter the polynomial equation 2\n");
 while(r)
 {
 printf("Press 1=Add term\n 2=Exit\n");
 scanf("%d",&pc);
 switch(pc)
 {
 case 1:
  {
  printf("Enter the coefficint :\n");
  printf("Enter the power :\n");
  scanf("%d%d",&pcoeff,&ppow);
  append(pcoeff,ppow,2);
  break;
  }
 case 2:
  {
   r=0;
   break;
  }
 }
 }
printf("Press 1=AddPOLY\n Press 2=SubPOLY\n");
while(1)
 {
 printf(" enter choice: ");
 scanf("%d",&ch);
 switch(ch)
  {
   case 1:
    {
     addpoly();
     break;
    }
   case 2:
    {
     subpoly();
     break;
    }
  case 3:
    {
    exit(0);
    break;
    }
  }
 getch();
 }
 }
