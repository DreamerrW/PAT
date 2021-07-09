#include<stdio.h>
#include<stdlib.h>

//用链表实现1元多项式的相加 
typedef struct PNode{
	float coef;	  //系数 
	int expn;     //指数
	struct PNode *next; 
}PNode,*Polynomial;

void attach(int e,int c,PNode **rear) ;
Polynomial readpoly();
Polynomial mult(Polynomial p1,Polynomial p2);
int getlength(Polynomial p);
void print(PNode* p);

int main()
{
	Polynomial p1,p2,ps;
	p1=readpoly();
	p2=readpoly();
	ps=mult(p1,p2);
	print(ps);
	return 0; 
} 


void attach(int e,float c,PNode **prear)         //尾插函数，实现一个节点插在线性表最后 
{
	PNode *s;                                 //新建一个节点s 
	s=(Polynomial)malloc(sizeof(PNode));
	s->coef=c;
	s->expn=e;
	s->next=NULL;
	(*prear)->next=s;
	*prear=s;
}

Polynomial readpoly()
{         						 //根据输入生成一个降序储存的多项式 
	Polynomial p;
	PNode *rear;
	p=(Polynomial)malloc(sizeof(PNode));  //首先建立一个带头节点的单链表 
	p->next=NULL;
	rear=p;                                      //尾指针先指向头指针p 
	
	float c;
	int e;	                                 //系数和指数 
	int n;										 //多项式项数 
	scanf("%d",&n);					
	for(int i=0;i<n;i++)
	{
		scanf("%d %f",&e,&c);
		attach(e,c,&rear);

	}
	return p;
}

Polynomial mult(Polynomial p1,Polynomial p2)            //多项式乘法函数 
{
	if(!(p1->next)||!(p2->next))  return NULL;  //若只有头节点，即多项式为空 
	Polynomial temp1,temp2;                     //多项式p1和p2的副本 
	Polynomial p,rear;   //结果多项式 
	Polynomial t;                      
	float c;
	int e;
	temp1=p1->next;
	temp2=p2->next;
	p=(Polynomial)malloc(sizeof(PNode)); 
	p->next=NULL;
	rear=p;
	
	while(temp2)	//先用p1的第一项乘以p2的所有项得到初始结果多项式 
	{
		attach(temp1->expn+temp2->expn,temp1->coef*temp2->coef,&rear);
		temp2=temp2->next;  
	}
	temp1=temp1->next;
	while(temp1)
	{
		temp2=p2->next;	//指向多项式2的第一项 
		rear=p;	
		while(temp2)
		{
			e=temp1->expn+temp2->expn;
			c=temp1->coef*temp2->coef;
			while(rear->next&&rear->next->expn>e)
			{
				rear=rear->next;
			}
			if(rear->next&&rear->next->expn==e)  //若指数相等，则考虑系数合并后是否插入或删除的问题 
			{
				if(rear->next->coef+c)
				rear->next->coef+=c;
				else 
				{
					t=rear->next;
					rear->next=t->next;
					free(t);
				}
			}
			else    //现有的多项式中没有这个指数，则直接插入 
			{
				t=(Polynomial)malloc(sizeof(PNode));   
				t->coef=c; 
				t->expn=e;
				t->next=rear->next;
				rear->next=t;
				rear=rear->next; 
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;	
	}
	return p; 
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
	printf("0 0"); return;
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
