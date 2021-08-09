#include<cstdio>
#include<vector>
#define inf 9999999
//Ҫ������·����һ��������̣�һ��ʱ����̣������Ļ���Ҫ����dijkstra�㷨�� 
using namespace std;
int dis[510];
int time[510];
int e[510][510]; //�Ծ���Ϊ�� 
int weight[510]; //��ĳ��������·������ʱ�� 
int w[510][510]; //��ʱ��Ϊ�� 
int nodenum[510]; //��ĳ�����������Ľ����Ŀ 
vector<int> dispath,timepath;
int dispre[510];
int timepre[510];
bool vis[510]={false};
int n,m;  //n����� m���� 
int start,final; //�����յ�
void dijkstra1(int s){   //����̾����·�� 
	weight[s]=0;  //��㵽����ʱ��Ϊ0 
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
void dijkstra2(int s){ //�����ʱ���·��
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
				if(time[u]+w[u][v]<time[v]){  //���Ż� 
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
		if(flag!=1){  //������ǵ���� 
			e[b][a]=len;
			w[b][a]=t;
		}
	}
	scanf("%d %d",&start,&final); 
	dijkstra1(start);  //�����·�� 
	dfs1(final);
	
	fill(vis,vis+510,false); 
	dijkstra2(start);  //������ٶȵ�·�� 
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
