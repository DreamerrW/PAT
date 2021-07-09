#include<cstdio>
#include<algorithm>
#define maxv 510
using namespace std;
const int INF=999999;
int e[maxv][maxv];
int dis[maxv];
bool visited[maxv]={false};
int cost[maxv][maxv];
int c[maxv];
int pre[maxv];
int n,m,s,d; //nΪ��������m��·������sΪ��㣬dΪ�յ�
void dfs(int v){
	if(v==s){
		printf("%d ",v);
		return;
	}
	else {
		dfs(pre[v]);
		printf("%d ",v);
	}
	return ;
}
void dijkstra(int s){
	dis[s]=0;
	c[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(visited[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) return;
		visited[u]=true;
		for(int v=0;v<n;v++){
			if(visited[v]==false&&e[u][v]!=INF){
				if(dis[u]+e[u][v]<dis[v]){   //����uΪ�н�����Ż� 
					dis[v]=dis[u]+e[u][v];
					c[v]=c[u]+cost[u][v];      //����dis��c������Ϣ 
					pre[v]=u; 
				}
				else if(dis[u]+e[u][v]==dis[v]){  //�ҵ�һ����ȵ�·�� 
					if((c[u]+cost[u][v])<c[v]){  //�����Ѹ��٣������,����ʲô������ 
						c[v]=c[u]+cost[u][v];      //����dis��c������Ϣ
						pre[v]=u; 
					}
				}
			}
		}	
	}
}
int main()
{
	fill(e[0],e[0]+maxv*maxv,INF);
	fill(cost[0],cost[0]+maxv*maxv,INF);
	fill(c,c+maxv,INF);
	fill(dis,dis+maxv,INF);   //��ʼ�� 
	scanf("%d %d %d %d",&n,&m,&s,&d);
	int temp1,temp2;
	for(int i=0;i<m;i++){   //m��·������Ŀ 
		scanf("%d %d",&temp1,&temp2);
		scanf("%d",&e[temp1][temp2]);
		e[temp2][temp1]=e[temp1][temp2];
		scanf("%d",&cost[temp1][temp2]);
		cost[temp2][temp1]=cost[temp1][temp2];
	} 
	dijkstra(s);
	dfs(d);
	printf("%d %d",dis[d],c[d]);
	return 0; 
 } 
