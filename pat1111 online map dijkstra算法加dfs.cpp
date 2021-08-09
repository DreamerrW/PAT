#include<cstdio>
#include<vector>
#define inf 9999999
//要求两条路径，一条距离最短，一条时间最短，这样的话就要两个dijkstra算法， 
using namespace std;
int dis[510];
int time[510];
int e[510][510]; //以距离为边 
int weight[510]; //到某个点的最短路径花的时间 
int w[510][510]; //以时间为边 
int nodenum[510]; //到某个点所经过的结点数目 
vector<int> dispath,timepath;
int dispre[510];
int timepre[510];
bool vis[510]={false};
int n,m;  //n个结点 m条边 
int start,final; //起点和终点
void dijkstra1(int s){   //找最短距离的路径 
	weight[s]=0;  //起点到起点的时间为0 
	dis[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&dis[j]<min){
					u=j;
					min=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&e[u][v]!=inf){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v]; 
					dispre[v]=u;
					weight[v]=w[u][v]+weight[u];
				}
				else if(dis[u]+e[u][v]==dis[v]){
					if(weight[v]>w[u][v]+weight[u]){
						weight[v]=w[u][v]+weight[u];
						dispre[v]=u;
					}
				} 
			} 
		}
	}
} 
void dijkstra2(int s){ //找最短时间的路径
	time[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&time[j]<min){
					u=j;
					min=time[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&w[u][v]!=inf){
				if(time[u]+w[u][v]<time[v]){  //能优化 
					time[v]=time[u]+w[u][v];
					timepre[v]=u;
					nodenum[v]=nodenum[u]+1;
				}
				else if(time[v]==time[u]+w[u][v]){
					if(nodenum[v]>nodenum[u]+1){
						timepre[v]=u;
						nodenum[v]=nodenum[u]+1;
					}
				}
			}
		}
	}	
}
void dfs1(int v){
	dispath.push_back(v);
	if(v==start) return;
	dfs1(dispre[v]);
}
void dfs2(int v){
	timepath.push_back(v);
	if(v==start) return;
	dfs2(timepre[v]);
}
int main()
{
	fill(e[0],e[0]+510*510,inf);
	fill(w[0],w[0]+510*510,inf);
	
	fill(dis,dis+510,inf);
	fill(time,time+510,inf);
	
	fill(weight,weight+510,inf);
	scanf("%d %d",&n,&m);
	int flag;
	for(int i=0;i<m;i++){
		int a,b,len,t;
		scanf("%d %d %d %d %d",&a,&b,&flag,&len,&t);
		e[a][b]=len;
		w[a][b]=t;
		if(flag!=1){  //如果不是单向边 
			e[b][a]=len;
			w[b][a]=t;
		}
	}
	scanf("%d %d",&start,&final); 
	dijkstra1(start);  //找最短路径 
	dfs1(final);
	
	fill(vis,vis+510,false); 
	dijkstra2(start);  //找最快速度的路径 
	dfs2(final); 
	
	printf("Distance = %d",dis[final]);
	if(dispath==timepath)
		printf("; Time = %d: ",time[final]);
	else{
		printf(": ");
		for(int i=dispath.size()-1;i>=0;i--){
			printf("%d",dispath[i]);
			if(i!=0) printf(" -> "); 
		}
		printf("\n");
		printf("Time = %d: ",time[final]);
	}
	for(int i=timepath.size()-1;i>=0;i--){
		printf("%d",timepath[i]);
		if(i!=0) printf(" -> ");
	}
	return 0;
}
