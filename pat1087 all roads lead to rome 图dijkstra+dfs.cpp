#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define maxv 205
#define INF 1000000
using namespace std;
//输出  cnt条路，最少的cost，最多的happy，最多的avghappy  最少cost的路径本身 
int N,K;  //N个城市，K条路
int dis[maxv];
int e[maxv][maxv];
bool vis[maxv]={false};
int v[maxv];             //储存happy权值 
map<string,int> mp;
map<int,string> mp1;
vector<int> pre[maxv]; //前驱数组
vector<int> path,temppath;


int happy=0;
double avghappy=0;   
int cntpath=0;   

void dfs(int u){
	//边界 
	if(u==0){
		temppath.push_back(u);
		int value=0;
		for(int i=0;i<temppath.size();i++){
			int id=temppath[i];
		    value+=v[id];
		}
		double tempavg=1.0*value/(temppath.size()-1);
		if(value>happy){         //取最多happy的那一个 
			happy=value;
			avghappy=tempavg;
			path=temppath; 
		}else if(happy==value&&tempavg>avghappy){
			avghappy=tempavg;
			path=temppath;
		}
		cntpath++;            //总路径增加 
		temppath.pop_back();
		return ;
	}
	temppath.push_back(u);
	for(int i=0;i<pre[u].size();i++)
		dfs(pre[u][i]);
	temppath.pop_back(); 
}
void dijkstra(int s){
	dis[s]=0; //起点和起点的距离为0 
	for(int i=0;i<N;i++){
		int u=-1,min=INF;
		for(int j=0;j<N;j++){
			if(vis[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<N;v++){
			if(vis[v]==false&&e[u][v]!=INF){
				if(dis[u]+e[u][v]<dis[v]){
					dis[v]=dis[u]+e[u][v];
					pre[v].clear();
					pre[v].push_back(u);    //令v的前驱为u 
				}
				else if(dis[u]+e[u][v]==dis[v])
					pre[v].push_back(u);
			}
		}
	}
}
int main()
{
	fill(e[0],e[0]+maxv*maxv,INF);
	fill(dis,dis+maxv,INF);
	cin>>N>>K;  
	string s;
	cin>>s;      //输入起点城市 
	mp[s]=0;     //起点对应 0号城市 
	mp1[0]=s;    //0号城市对应起点
	 
	for(int i=1;i<N;i++){
		cin>>s>>v[i];
		mp[s]=i;         //给城市找一个对应的编号
		mp1[i]=s; 
	}
	
	for(int i=0;i<K;i++){   //初始化边权 
		string temp1,temp2;
		int d;
		cin>>temp1>>temp2>>d;
		e[mp[temp1]][mp[temp2]]=e[mp[temp2]][mp[temp1]]=d;
	} 
	
	dijkstra(0);
	int rom=mp["ROM"];
	dfs(rom);
	printf("%d %d %d %d\n",cntpath,dis[rom],happy,(int)avghappy); 
	for(int i=path.size()-1;i>=1;i--){
		printf("%s->",mp1[path[i]].c_str());
	}
	printf("ROM");
	return 0;
	
}
