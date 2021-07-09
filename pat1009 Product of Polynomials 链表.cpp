#include<stdio.h>
#include<stdlib.h>

//������ʵ��1Ԫ����ʽ����� 
typedef struct PNode{
	float coef;	  //ϵ�� 
	int expn;     //ָ��
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


void attach(int e,float c,PNode **prear)         //β�庯����ʵ��һ���ڵ�������Ա���� 
{
	PNode *s;                                 //�½�һ���ڵ�s 
	s=(Polynomial)malloc(sizeof(PNode));
	s->coef=c;
	s->expn=e;
	s->next=NULL;
	(*prear)->next=s;
	*prear=s;
}

Polynomial readpoly()
{         						 //������������һ�����򴢴�Ķ���ʽ 
	Polynomial p;
	PNode *rear;
	p=(Polynomial)malloc(sizeof(PNode));  //���Ƚ���һ����ͷ�ڵ�ĵ����� 
	p->next=NULL;
	rear=p;                                      //βָ����ָ��ͷָ��p 
	
	float c;
	int e;	                                 //ϵ����ָ�� 
	int n;										 //����ʽ���� 
	scanf("%d",&n);					
	for(int i=0;i<n;i++)
	{
		scanf("%d %f",&e,&c);
		attach(e,c,&rear);

	}
	return p;
}

Polynomial mult(Polynomial p1,Polynomial p2)            //����ʽ�˷����� 
{
	if(!(p1->next)||!(p2->next))  return NULL;  //��ֻ��ͷ�ڵ㣬������ʽΪ�� 
	Polynomial temp1,temp2;                     //����ʽp1��p2�ĸ��� 
	Polynomial p,rear;   //�������ʽ 
	Polynomial t;                      
	float c;
	int e;
	temp1=p1->next;
	temp2=p2->next;
	p=(Polynomial)malloc(sizeof(PNode)); 
	p->next=NULL;
	rear=p;
	
	while(temp2)	//����p1�ĵ�һ�����p2��������õ���ʼ�������ʽ 
	{
		attach(temp1->expn+temp2->expn,temp1->coef*temp2->coef,&rear);
		temp2=temp2->next;  
	}
	temp1=temp1->next;
	while(temp1)
	{
		temp2=p2->next;	//ָ�����ʽ2�ĵ�һ�� 
		rear=p;	
		while(temp2)
		{
			e=temp1->expn+temp2->expn;
			c=temp1->coef*temp2->coef;
			while(rear->next&&rear->next->expn>e)
			{
				rear=rear->next;
			}
			if(rear->next&&rear->next->expn==e)  //��ָ����ȣ�����ϵ���ϲ����Ƿ�����ɾ�������� 
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
			else    //���еĶ���ʽ��û�����ָ������ֱ�Ӳ��� 
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
