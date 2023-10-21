#include<stdio.h>
#include<conio.h>
#define  MAXSTK 5
typedef struct 
{
	int top;
	int item[MAXSTK];
}stacks;
int IsEmpty(stacks*);
int IsFull(stacks*);
void Push(stacks*,int);
int Pop(stacks*);
int Peep(stacks*);
void Display(stacks*);
int main()
{
	stacks s;
	int x,ch,ele;
	s.top = -1;
	do
	{
		printf("\n1-PUSH");
		printf("\n2-POP");
		printf("\n3-DISPLAY");
		printf("\n4-PEEP");
		printf("\n5-OUIT");
		printf("\nEnter your choice:-");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("\nEnter the elements to insert : ");
					scanf("%d",&x);
					Push(&s,x);
					break;
			case 2: ele = Pop(&s);
					if(ele==-1)
						printf("\nThe stacks is empty!");
					else
						printf("\nThe poped element is %d",ele);
					break;
			case 3: Display(&s);
					break;
			case 4: Peep(&s);
					break;
			case 5: break;
			default: printf("\nWrong choice : Try again");
		}
	}while(ch!=5);
	return 0;
}
int IsEmpty(stacks* sp)
{
	if(sp->top==-1)
		return 1;
	else
		return 0;
}
int IsFull(stacks* sp)
{
	if(sp->top==MAXSTK-1)
		return 1;
	else
		return 0;
}
void Push(stacks* sp,int x)
{
	if(IsFull(sp))
	{
		printf("\nStack is overflow");
	}
	else
	{
		sp->top++;
		sp->item[sp->top] = x;
	}
}
int Pop(stacks* sp)
{
	int x;
	if(IsEmpty(sp))
	{
		printf("\nStack is underflow");
		return -1;
	}
	else
	{
		x = sp->item[sp->top];
		sp->top--;
		return x;
	}
}
int Peep(stacks* sp)
{
	int x;
	if(IsEmpty(sp))
	{
		printf("\nStack is underflow");
		return -1;
	}
	else
	{
		printf("%d",sp->item[sp->top]);
	}
}
void Display(stacks* sp)
{
	int i;
	for(i=sp->top;i>=0;i--)
	{
		printf("%d\t",sp->item[i]);
	}
}
