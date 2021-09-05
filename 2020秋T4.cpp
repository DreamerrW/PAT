#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define maxn 1001
using namespace std;
int n,m,k;
int indegree[maxn],id[maxn];
int e[maxn][maxn];   //分数边 
int e1[maxn][maxn];  //优惠券边 
vector<int> Next[maxn];
int pre[maxn];
int wd[maxn];
int ws1[maxn];

int main()
{
	int cnt=0;
	fill(pre,pre+maxn,-1);
	cin>>n>>m;  //n是测试的总数 
	for(int i=0;i<m;i++){
		int t1,t2,s,d;
		cin>>t1>>t2>>s>>d;
		e[t1][t2]=s;   //需要达到的分数 
		e1[t1][t2]=d;  //优惠券面值 
		Next[t1].push_back(t2);  //t1到t2的边 
		indegree[t2]++;   //t2入度+1 
		id[t2]++;
	} 
	queue<int> q;
	for(int i=0;i<n;i++)
		if(indegree[i]==0) q.push(i);  //所有入度为0的结点
	while(!q.empty()){
		int u=q.front();
		cnt++;
		q.pop();
		for(int i=0;i<Next[u].size();i++){
			int v=Next[u][i];
			indegree[v]--;
			if(indegree[v]==0) q.push(v);
			if(pre[v]==-1||ws1[u]+e[u][v]<ws1[v]){
				ws1[v]=ws1[u]+e[u][v];
				wd[v]=wd[u]+e1[u][v];
				pre[v]=u;
			}
			else if(ws1[u]+e[u][v]==ws1[v]&&wd[u]+e1[u][v]>wd[v]){
				wd[v]=wd[u]+e1[u][v];
				pre[v]=u;
			}
		}
	} 
	bool flag=false;
	if(cnt!=n) flag=true;
	if(flag) printf("Impossible.\n");
	else printf("Okay.\n");
	cin>>k;
	while(k--){
		int t;
		cin>>t;
		if(id[t]==0) printf("You may take test %d directly.\n",t);
		else if(flag) printf("Error.\n");
		else {
			vector<int> path;
			while(t!=-1){
				path.push_back(t);
				t=pre[t];
			}
			for(int i=path.size()-1;i>=0;i--){
				if(i) printf("%d->",path[i]);
				else printf("%d\n",path[i]);
			}
		}
	}
	return 0;
}
