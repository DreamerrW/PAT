#include<cstdio>
#include<vector>
#include <algorithm> 
//�������dfs��dijkstra�㷨  
using namespace std;
const int INF = 9999999;
int dis[510],e[510][510],weight[510];  //�������飬��Ȩ���ڵ�Ȩֵ 
bool visited[510]={false};             //��¼�Ƿ���� 
vector<int> pre[510];                  //��¼ǰ�� 
vector<int> path,temppath;   
int minNeed=INF,minBack=INF; 
int cmax,n,sp,m;                      //cmax������г���n���ܹ��ĳ�վ��sp��������Ķ��㣬m��·
void dfs(int v)
{
	//temppath.push_back(v);
	if(v==0){
		int need=0,back=0;
		for(int i=temppath.size()-1;i>=0;i--){
			int id=temppath[i];
			if(weight[id]-cmax/2>0){           //����ǰ��������г���������һ�룬����Ҫ����� 
				back+=weight[id]-cmax/2;
			}
			else {
				if(back>cmax/2-weight[id]){    //����Ȼ���������ܴ��صĿ��Բ�����ȱ 
					back-=(cmax/2-weight[id]); 
				}
				else {                           //��������������Ҫ����� 
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
    dfs(pre[v][i]);           //���v��ǰ���ڵ�pre[v][i]���ݹ� 	  
    temppath.pop_back();     //����������ǰ���ڵ㣬����ǰ���vɾ�� 
}
void dijkstra(int s)
{
	dis[s]=0;                 //�������Լ��ľ���Ϊ0 
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
					dis[v]=dis[u]+e[u][v];       //�Ż�dis[v] 
					pre[v].clear();
					pre[v].push_back(u);         //ǰ������ 
				}
				else if(dis[u]+e[u][v]==dis[v])  //���ҵ���ȵ�·��
					pre[v].push_back((u));       //ǰ������ 
			}
		}
	}
}

int main()
{
	fill(e[0],e[0]+510*510,INF);          //��ʼ����Ȩ 
	fill(dis,dis+510,INF);                //��ʼ���������� 
	scanf("%d %d %d %d",&cmax,&n,&sp,&m); //cmax������г���n���ܹ��ĳ�վ��sp��������Ķ��㣬m��·
	for(int i=1;i<=n;i++)
		scanf("%d",&weight[i]);           //ÿ���������ڵ����г���  
	weight[0]=cmax/2;
	int temp1,temp2;      
	for(int i=0;i<m;i++){                //�����Ȩ 
		scanf("%d %d",&temp1,&temp2);
		scanf("%d",&e[temp1][temp2]);
		e[temp2][temp1]=e[temp1][temp2];
	} 
	dijkstra(0);                         //��dijkstra�㷨��dfs 
	dfs(sp); 
	printf("%d 0",minNeed);
	for(int i=path.size()-1;i>=0;i--)    //���ڵݹ�ԭ��·��������ģ�path.size()-1��0��㣬 
		printf("->%d",path[i]); 
	printf(" %d",minBack);
	return 0;
} 
