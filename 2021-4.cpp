#include<iostream>
#include<vector>
#include<algorithm>
#define inf 999999
using namespace std;
bool vis[201];
int dis[201][201];
vector<int> path; 
vector<int> ans;
int cnt=0;
int n,m;  //1~n
void dfs(int index){
	path.push_back(index);
	int u=-1,min=inf;
	vis[index]=true;
	for(int i=0;i<=n;i++){      //找到最近没访问过的结点 
		if(vis[i]==false&&dis[index][i]<min){
			u=i;
			min=dis[index][i];
		} 
	}
	if(u==-1) return ;
	cnt+=min;
	dfs(u);
}
int main()
{
	cin>>n>>m;
	fill(dis[0],dis[0]+201*201,inf);
	for(int i=0;i<=n;i++)  //自己与自己的距离为0     
		dis[i][i]=0; 
	for(int i=0;i<m;i++){
		int a,b,t;
		cin>>a>>b>>t;
		dis[a][b]=dis[b][a]=t;
	}
	//floyd 算法
	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(dis[i][k]!=inf&&dis[k][j]!=inf&&dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	} 
	dfs(0);
	int flag=0;
	for(int i=0;i<=n;i++){
		if(vis[i]==false){
			flag=1;
			ans.push_back(i);
		}
	}
	for(int i=0;i<path.size();i++){
		if(i!=0) printf(" ");
		printf("%d",path[i]);
	}
	printf("\n");
	if(flag==0)
		printf("%d",cnt);
	else{
		for(int i=0;i<ans.size();i++){
			if(i!=0) printf(" ");
			printf("%d",ans[i]);
		}
	}
	return 0;
 } 
