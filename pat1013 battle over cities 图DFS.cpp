#include<cstdio>
#include<vector>
#include<cstring> 
#define maxv 1003
using namespace std;
//该题即为求这副图的联通分量个数，cnt个连通分量需要cnt-1个路径连接
 
vector<int> G[maxv];  //vector实现邻接表 
int visited[maxv];    //判断该顶点是否访问过 
int occupied;         //被攻占的城市 

void dfs(int number)  //dfs函数 
{
	visited[number]=1;
	for(int i=0;i<G[number].size();i++)
	{
		if(!visited[G[number][i]])
		{
		//	visited[G[number][i]]=1;
			dfs(G[number][i]);
		}	
	}
}
 
int main()
{
	int n,m,k;
	int temp1,temp2;
	scanf("%d %d %d",&n,&m,&k);            //m条公路
	for(int i=0;i<m;i++)                   //m个由公路连接的城市 
	{
		scanf("%d %d",&temp1,&temp2);
		G[temp1].push_back(temp2);         //补全邻接表 
		G[temp2].push_back(temp1);
	} 
	while(k--)
	{
		memset(visited,0,sizeof(visited)); //设置vis数组全为0 
		int count=0;
		scanf("%d",&occupied);
		visited[occupied]=1;               //已经攻占的城市设置为已访问 
		for(int i=1;i<=n;i++)
		{
			if(!visited[i]){
			dfs(i);
			count++;		        	  //记录联通分量个数 
			}
		}
		printf("%d\n",count-1);           //新增公路为联通分量个数减一 
	}
	return 0;		 	
} 
