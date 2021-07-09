#include<stdio.h>
#include<stdlib.h>

//用链表实现1元多项式的相加 
typedef struct PNode{
	float coef;	  //系数 
	int expn;     //指数
	struct PNode *next; 
}PNode,*Polynomial;

void attach(int e,float c,PNode **rear)
{
	PNode *s;
	s=(PNode *)malloc(sizeof(PNode));
	s->next=NULL;
	s->coef=c;
	s->expn=e;
	(*rear)->next=s;
	*rear=s;
}

Polynomial readpoly()
{
	int n,e;
	float c;
	Polynomial p;
	PNode *rear;
	p=(Polynomial)malloc(sizeof(PNode));
	p->next=NULL;
	rear=p;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %f",&e,&c);
		attach(e,c,&rear);
	}
	return p;
}

Polynomial add(Polynomial p1,Polynomial p2)
{
	float sum;
	Polynomial temp1,temp2;
	Polynomial p3;        //p3为结果多项式 ，不用再申请空间 
	PNode *r;             //用于删除节点 
	temp1=p1->next;
	temp2=p2->next;
	p3=p1;
	
	while(temp1&&temp2)
	{
		if(temp1->expn==temp2->expn)
		{
			sum=temp1->coef+temp2->coef;
			if(sum!=0)
			{
				temp1->coef=sum;
				p3->next=temp1;
				p3=temp1;
				temp1=temp1->next; 
				r= temp2;
				temp2=temp2->next;
				free(r);
			}
			else
			{
				r=temp1;temp1=temp1->next;free(r);
				r=temp2;temp2=temp2->next;free(r);
			}
		}
		else if(temp1->expn>temp2->expn)
		{
			p3->next=temp1;
			p3=temp1;
			temp1=temp1->next;
		}
		else
		{
			p3->next=temp2;
			p3=temp2;
			temp2=temp2->next;
		}
	}
	p3->next=temp1?temp1:temp2;
	free(p2);
	return p1;
}

int getlength(Polynomial p)
{
	int n=0;
	while(p->next!=NULL)
	{
		p=p->next;
		n++;
	}
	return n;
}

void print(PNode* p)
{
	if(!p->next) 
	{
	printf("0"); return;
	}
	int n;
	n=getlength(p);
	printf("%d ",n);
	p=p->next;
	for(int i=0;i<n;i++)
	{
		printf("%d %.1f",p->expn,p->coef);
		if(i!=n-1)
		printf(" ");
		p=p->next;
	}
	return ;
}

int main()
{
	Polynomial p1,p2,pd;
	p1=readpoly();
	p2=readpoly();
	pd=add(p1,p2);
	print(p1);
	return 0;
 } 
