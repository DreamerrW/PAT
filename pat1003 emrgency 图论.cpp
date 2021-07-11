#include <stdio.h>
//#include<stdbool.h>

#define maxv 510          //顶点最大值 
#define INF 100000        //无穷大 

typedef struct{
//	int v[maxv];	    //顶点表 
int e[maxv][maxv];      //邻接矩阵 
int weight[maxv];      	//顶点权值,即每个城市救火队数目 
}Mgraph;
Mgraph G;                      //定义一个图 


int n,m,c1,c2;                 //输入，n个城市，m条路，c1起点，c2终点 

bool visited[maxv]={false};    //是否访问初始为否 
int distance[maxv];     	   //起点到任意一点最短距离 
int num[maxv]={0};
int w[maxv]={0}; 			   //起点到任意一点最短路径数目,和最大的救火队之和数目 

void dijkstra(int s)
{
	distance[s]=0;  		  //起点与自己的距离是0 
	w[s]=G.weight[s]; 		  //起点的救火队数目  
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
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通 
		if(u==-1) return; 
		visited[u]=true;		//标记u为已访问
		for(int v=0;v<n;v++)		//
		{
			if(visited[v]==false&&G.e[u][v]!=INF)       //如果v未访问&&u能到达v 
			{
				if(distance[u]+G.e[u][v]<distance[v])   //以u为中介点的时候能使dis[v]更小 
				{
					distance[v]=distance[u]+G.e[u][v];  //更新dis[v] 
					w[v]=w[u]+G.weight[v];				//更新w[v] 
					num[v]=num[u];						//继承num[v] 
				}
				else if(distance[u]+G.e[u][v]==distance[v]) //找到一条相等的路径 
				{
					num[v]=num[v]+num[u];              //原本v的路径条数加上以u为中介带来的路径条数 
					if(w[u]+G.weight[v]>w[v])		  //若以u为中介权值更大，则更新 
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
		scanf("%d",&G.weight[i]);   //读入各个城市权值，即救火队数目		
	}
	
	for(int i=0;i<n;i++)	{	//初始化distance数组		
		distance[i]=INF;
		for(int j=0;j<n;j++)	//初始化边权 
			G.e[i][j]=INF;
	}
	int u,v;                         
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);       //读入边权 
		scanf("%d",&G.e[u][v]);
		G.e[v][u]=G.e[u][v];       //无向图 
	}
	dijkstra(c1);
	printf("%d %d\n",num[c2],w[c2]);
	return 0; 
}


