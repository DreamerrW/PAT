#include<stdio.h>
#define maxsize 103


typedef struct{
	int layer;
	int child[10];	
	int childs;
	//int parent;
}Tnode;

Tnode node[maxsize]={0};   	//	��ʼ��100����� 

int main()
{
	int n,m;
	int root,k;
	int son;    //���� 
	int temp;
	node[1].layer=1;

	scanf("%d %d",&n,&m);
	if(n==0) return 0;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&root);
		scanf("%d",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&son);
			node[root].child[j]=son;				//����ǰ�ڵ��Һ��� 
			//node[son].layer=node[root].layer+1;     //��ǰ�ڵ�ĺ��ӵĲ�����1 
			node[root].childs++;					//������Ŀ++ 
		}	
	}
	
	for(int i=1;i<maxsize;i++)  //��ÿһ���ڵ�ȷ�����Ĳ���
	{
		for(int j=0;j<maxsize;j++)
		{
			if(node[i].child[j]!=0)
			//k=node[i].child[j];
			{
				node[node[i].child[j]].layer=node[i].layer+1;
			}
		} 
	 } 



	int nowlayer=1;
	int maxlayer=1;
	int num[maxsize]={0};
	
	for(int i=0;i<maxsize;i++)
	{
		if(node[i].layer>maxlayer)
		maxlayer=node[i].layer;
	}
	
	for(int j=0;j<maxlayer;j++)
	{
		for(int i=0;i<maxsize;i++)
		{
			if(node[i].layer==nowlayer)
			{
				if(node[i].childs==0)
				num[nowlayer]++;
			} 
		}
		nowlayer++;
	}
	
	
	for(int i=1;i<=maxlayer;i++)
	{
		if(i==maxlayer)
		printf("%d",num[i]);
		else 
		printf("%d ",num[i]);
		
	}
	return 0;
	
} 
