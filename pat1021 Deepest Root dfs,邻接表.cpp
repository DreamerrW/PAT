#include<cstdio>
#include<vector>
#include<algorithm>  
using namespace std;
//考察dfs的运用 
vector<vector<int>> v;   //这样的写法一维是变长的  
bool visit[10010]={false};
int maxdepth=0; 
void dfs(int n,int depth)
{
	if(depth>maxdepth) maxdepth=depth;
	visit[n]=true;
	for(int i=0;i<v[n].size();i++)
	{
		if(!visit[v[n][i]])
		dfs(v[n][i],depth+1);
	}
}
int main() 
{
	int n;
	int m=0;                     //最大的深度 
	scanf("%d",&n);
	v.resize(n+1);
	vector<int> deep(n+1);     //储存每个结点的深度数组 
	int temp1,temp2,cnt=0;
	for(int i=0;i<n-1;i++){    //建立邻接表 
		scanf("%d %d",&temp1,&temp2);
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	} 
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i,0);
			cnt++;
		}
	}
	if(cnt>1){
		printf("Error: %d components",cnt);
		return 0; 
	}
	for(int i=1;i<=n;i++){      //dfs n次，把每次的最大深度记录来 
		maxdepth=0;
		fill(visit+1,visit+n+1,false);
		dfs(i,1);
		deep[i]=maxdepth; 
		if(maxdepth>m) m=maxdepth;
	}
	for(int i=1;i<=n;i++)
	{
		if(deep[i]==m)
		printf("%d\n",i);
	}
	return 0;  
}
