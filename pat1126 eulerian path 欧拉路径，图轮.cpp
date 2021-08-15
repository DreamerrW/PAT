#include<cstdio>
#include<vector>
using namespace std;
//所有的结点的度都是偶数 Eulerian
//如果有两个结点的度是奇数 semi eulerian
int n,m;  //n个结点，m条边 
vector<int> v[510];
bool vis[510];
void dfs(int u){
	vis[u]=true;
	for(int i=0;i<v[u].size();i++){
		if(vis[v[u][i]]==false)
			dfs(v[u][i]);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int t1,t2;
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		v[t1].push_back(t2);
		v[t2].push_back(t1);
	}
	int odd=0; //奇数结点
	int even=0; //偶数结点 
	 
	for(int i=1;i<=n;i++){
		if(i!=1) printf(" ");
		printf("%d",v[i].size()); //输出结点的度
		if(v[i].size()%2==0) even++;
		else odd++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			dfs(i);
			cnt++;      //记录联通分量个数 
		}
	}
	printf("\n");
	if(cnt==1){        //不是连通图 
		if(even==n) printf("Eulerian"); 
		else if(odd==2)printf("Semi-Eulerian");  
        else printf("Non-Eulerian"); 
	}
	else printf("Non-Eulerian"); 
	return 0;
}
