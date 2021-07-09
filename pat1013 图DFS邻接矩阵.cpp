#include<cstdio>
#include<cstring>
#define maxv 1002

int G[maxv][maxv]={0};  //邻接矩阵
int visited[maxv];
int occupied;         //被攻占的城市 
int n;                //n个城市 
void dfs(int index)
{
	visited[index]=1;
	for(int i=1;i<=n;i++)
	{
		if(G[index][i]==1)
		{
			if(!visited[i])
			dfs(i);
		}
	}
}

int main()
{
	int m,k;                             //n个城市，m条路，k个需要关心的城市 
	int temp1,temp2;
	scanf("%d %d %d",&n,&m,&k);            //m条公路
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&temp1,&temp2);
		G[temp1][temp2]=1;
		G[temp2][temp1]=1;
	}
	while(k--)
	{
		memset(visited,0,sizeof(visited));
		int cnt=0;
		scanf("%d",&occupied);
		visited[occupied]=1;               //已经攻占的城市设置为已访问 
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
			dfs(i);
			cnt++;
			}
		
		}
		printf("%d\n",cnt-1);           //新增公路为联通分量个数减一
	}
	return 0;		 
 } 
