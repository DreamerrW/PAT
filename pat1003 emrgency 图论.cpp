#include <stdio.h>
//#include<stdbool.h>

#define maxv 510          //�������ֵ 
#define INF 100000  //����� 

typedef struct{
//	int v[maxv];	    //����� 
int e[maxv][maxv];      //�ڽӾ��� 
int weight[maxv];      	//����Ȩֵ,��ÿ�����оȻ����Ŀ 
}Mgraph;
Mgraph G;                      //����һ��ͼ 


int n,m,c1,c2;                 //���룬n�����У�m��·��c1��㣬c2�յ� 

bool visited[maxv]={false};    //�Ƿ���ʳ�ʼΪ�� 
int distance[maxv];     	   //��㵽����һ����̾��� 
int num[maxv]={0};
int w[maxv]={0}; 			   //��㵽����һ�����·����Ŀ,�����ľȻ��֮����Ŀ 

void dijkstra(int s)
{
	distance[s]=0;  		  //������Լ��ľ�����0 
	w[s]=G.weight[s]; 		  //���ľȻ����Ŀ  
	num[s]=1;     			   
	for(int i=0;i<n;i++)
	{
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++)
		{
			if(visited[j]==false&&distance[j]<MIN)
			{
				u=j;
				MIN=distance[j];
			}
		}
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ 
		if(u==-1) return; 
		visited[u]=true;		//���uΪ�ѷ���
		for(int v=0;v<n;v++)		//
		{
			if(visited[v]==false&&G.e[u][v]!=INF)       //���vδ����&&u�ܵ���v 
			{
				if(distance[u]+G.e[u][v]<distance[v])   //��uΪ�н���ʱ����ʹdis[v]��С 
				{
					distance[v]=distance[u]+G.e[u][v];  //����dis[v] 
					w[v]=w[u]+G.weight[v];				//����w[v] 
					num[v]=num[u];						//�̳�num[v] 
				}
				else if(distance[u]+G.e[u][v]==distance[v]) //�ҵ�һ����ȵ�·�� 
				{
					num[v]=num[v]+num[u];              //ԭ��v��·������������uΪ�н������·������ 
					if(w[u]+G.weight[v]>w[v])		  //����uΪ�н�Ȩֵ��������� 
						w[v]=w[u]+G.weight[v];
				}
			}
		} 
	}
}

int main()
{
	scanf("%d %d %d %d",&n,&m,&c1,&c2);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&G.weight[i]);   //�����������Ȩֵ�����Ȼ����Ŀ		
	}
	
	for(int i=0;i<n;i++)	{	//��ʼ��distance����		
		distance[i]=INF;
		for(int j=0;j<n;j++)	//��ʼ����Ȩ 
			G.e[i][j]=INF;
	}
	int u,v;                         
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);       //�����Ȩ 
		scanf("%d",&G.e[u][v]);
		G.e[v][u]=G.e[u][v];       //����ͼ 
	}
	dijkstra(c1);
	printf("%d %d\n",num[c2],w[c2]);
	return 0; 
}


