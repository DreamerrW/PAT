#include<cstdio>
#include<vector>
#include<queue> 
#define maxv 1001
using namespace std;

vector<int> G[maxv];
bool vis[maxv];
int deep[maxv]; //每个结点的深度 

int n,l;
//用户按 1~n 编号   L级简介跟随者
int k;  
//k个待查询

void bfs(int v){
	int level=0;
	int ans=0;

	queue<int> q;
	q.push(v);     //顶点入队
	vis[v]=true;
	//顶点的深度为0 即筛选 深度为 1~l的结点即为结果 
	while(!q.empty()){                        //进行一次广度优先遍历 
		int top=q.front(); 
		if(deep[top]==l) break; 
		q.pop();                              //头结点出队 
		for(int i=0;i<G[top].size();i++){
			if(vis[G[top][i]]==false){
				q.push(G[top][i]);           //子结点入队 
				deep[G[top][i]]=deep[top]+1; //子结点深度加一 
				vis[G[top][i]]=true;   
				ans++;        
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		if(deep[i]>=1&&deep[i]<=l)
			ans++;
	}*/
	printf("%d\n",ans);
}
int main()
{
	scanf("%d %d",&n,&l);
	int num,temp;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp);
			G[temp].push_back(i);
		}
	}
	scanf("%d",&k);
	int v;
	while(k--){
		fill(deep,deep+maxv,0); //初始深度为0 
		fill(vis,vis+maxv,false);
		scanf("%d",&v);
		bfs(v);
	}
	return 0;
 } 
