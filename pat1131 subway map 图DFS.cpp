#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n;
vector<int> e[10000];
vector<int> path,tpath;
int line[10000][10000];
bool vis[10000];
int s,end1;  //起点，终点

int mincnt,mintsfer;
int transfer(vector<int> a){
	int cnt=-1,preline=0;
	for(int i=1;i<a.size();i++){
		if(line[a[i]][a[i-1]]!=preline) cnt++;
		preline=line[a[i]][a[i-1]];
	}
	return cnt;
}
void dfs(int v,int depth){
	if(v==end1){
		tpath.push_back(v);
		if(depth<mincnt||(depth==mincnt&&transfer(tpath)<mintsfer)){
			mincnt=depth;
			mintsfer=transfer(tpath);
			path=tpath;
		}
		tpath.pop_back();
		return ;
	}
	tpath.push_back(v);
	vis[v]=true;
	for(int i=0;i<e[v].size();i++){
		if(vis[e[v][i]]==false)
			dfs(e[v][i],depth+1);
	}
	vis[v]=false;
	tpath.pop_back();
}
int main()
{
	cin>>n;
	int m;
	for(int i=1;i<=n;i++){  //建立图 
		int pre,t;
		cin>>m>>pre;
		for(int j=1;j<m;j++){
			cin>>t;
			e[pre].push_back(t);
			e[t].push_back(pre);
			line[pre][t]=line[t][pre]=i;  //两站之间是几号线 
			pre=t;
		}
	}
	int k;
	cin>>k;
	while(k--){
		cin>>s>>end1;
		mincnt=9999,mintsfer=9999;
		tpath.clear();
		fill(vis,vis+10000,false);
		dfs(s,0);
		printf("%d\n",mincnt);
		int preline=0,pretsfer=s;
		for(int j=1;j<path.size();j++){
			if(line[path[j]][path[j-1]]!=preline){
				if(preline!=0) printf("Take Line#%d from %04d to %04d.\n",preline,pretsfer,path[j-1]);
				preline=line[path[j]][path[j-1]];
				pretsfer=path[j-1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n",preline,pretsfer,end1);
	}
	return 0;
 } 
