#include<stdio.h>
#define maxsize 103


typedef struct{
	int layer;
	int child[10];	
	int childs;
	//int parent;
}Tnode;

Tnode node[maxsize]={0};   	//	初始化100个结点 

int main()
{
	int n,m;
	int root,k;
	int son;    //孩子 
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
			node[root].child[j]=son;				//给当前节点找孩子 
			//node[son].layer=node[root].layer+1;     //当前节点的孩子的层数加1 
			node[root].childs++;					//孩子数目++ 
		}	
	}
	
	for(int i=1;i<maxsize;i++)  //给每一个节点确定它的层数
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
