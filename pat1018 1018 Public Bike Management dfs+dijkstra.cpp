#include<cstdio>
#include<vector>
#include <algorithm> 
//该题采用dfs加dijkstra算法  
using namespace std;
const int INF = 9999999;
int dis[510],e[510][510],weight[510];  //距离数组，边权，节点权值 
bool visited[510]={false};             //记录是否访问 
vector<int> pre[510];                  //记录前驱 
vector<int> path,temppath;   
int minNeed=INF,minBack=INF; 
int cmax,n,sp,m;                      //cmax最多自行车，n是总共的车站，sp是有问题的顶点，m条路
void dfs(int v)
{
	//temppath.push_back(v);
	if(v==0){
		int need=0,back=0;
		for(int i=temppath.size()-1;i>=0;i--){
			int id=temppath[i];
			if(weight[id]-cmax/2>0){           //若当前顶点的自行车数量大于一半，则需要多带回 
				back+=weight[id]-cmax/2;
			}
			else {
				if(back>cmax/2-weight[id]){    //若不然，若已有能带回的可以补满空缺 
					back-=(cmax/2-weight[id]); 
				}
				else {                           //若补不满，则需要多带车 
					need+=cmax/2-weight[id]-back;
					back=0;
				}
			}
		}
		if(need<minNeed){
			minNeed=need;
			minBack=back;
			path=temppath;
		}else if(need==minNeed&&back<minBack){
			minBack=back;
			path=temppath;
		}
	//	temppath.pop_back();  
		return ;
	}
    temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++)
    dfs(pre[v][i]);           //结点v的前驱节点pre[v][i]，递归 	  
    temppath.pop_back();     //遍历完所有前驱节点，将当前结点v删除 
}
void dijkstra(int s)
{
	dis[s]=0;                 //顶点与自己的距离为0 
	for(int i=0;i<=n;i++){
		int u=-1,min=INF;
		for(int j=0;j<=n;j++){
			if(visited[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) return ;
		visited[u]=true;
		for(int v=0;v<=n;v++)
		{
			if(visited[v]==false&&e[u][v]!=INF){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v];       //优化dis[v] 
					pre[v].clear();
					pre[v].push_back(u);         //前驱读入 
				}
				else if(dis[u]+e[u][v]==dis[v])  //若找到相等的路径
					pre[v].push_back((u));       //前驱读入 
			}
		}
	}
}

int main()
{
	fill(e[0],e[0]+510*510,INF);          //初始化边权 
	fill(dis,dis+510,INF);                //初始化距离数组 
	scanf("%d %d %d %d",&cmax,&n,&sp,&m); //cmax最多自行车，n是总共的车站，sp是有问题的顶点，m条路
	for(int i=1;i<=n;i++)
		scanf("%d",&weight[i]);           //每个顶点现在的自行车量  
	weight[0]=cmax/2;
	int temp1,temp2;      
	for(int i=0;i<m;i++){                //读入边权 
		scanf("%d %d",&temp1,&temp2);
		scanf("%d",&e[temp1][temp2]);
		e[temp2][temp1]=e[temp1][temp2];
	} 
	dijkstra(0);                         //用dijkstra算法加dfs 
	dfs(sp); 
	printf("%d 0",minNeed);
	for(int i=path.size()-1;i>=0;i--)    //由于递归原因，路径是逆序的，path.size()-1是0结点， 
		printf("->%d",path[i]); 
	printf(" %d",minBack);
	return 0;
} 
