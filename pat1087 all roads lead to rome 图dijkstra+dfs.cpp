#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define maxv 205
#define INF 1000000
using namespace std;
//���  cnt��·�����ٵ�cost������happy������avghappy  ����cost��·������ 
int N,K;  //N�����У�K��·
int dis[maxv];
int e[maxv][maxv];
bool vis[maxv]={false};
int v[maxv];             //����happyȨֵ 
map<string,int> mp;
map<int,string> mp1;
vector<int> pre[maxv]; //ǰ������
vector<int> path,temppath;


int happy=0;
double avghappy=0;   
int cntpath=0;   

void dfs(int u){
	//�߽� 
	if(u==0){
		temppath.push_back(u);
		int value=0;
		for(int i=0;i<temppath.size();i++){
			int id=temppath[i];
		    value+=v[id];
		}
		double tempavg=1.0*value/(temppath.size()-1);
		if(value>happy){         //ȡ���happy����һ�� 
			happy=value;
			avghappy=tempavg;
			path=temppath; 
		}else if(happy==value&&tempavg>avghappy){
			avghappy=tempavg;
			path=temppath;
		}
		cntpath++;            //��·������ 
		temppath.pop_back();
		return ;
	}
	temppath.push_back(u);
	for(int i=0;i<pre[u].size();i++)
		dfs(pre[u][i]);
	temppath.pop_back(); 
}
void dijkstra(int s){
	dis[s]=0; //�������ľ���Ϊ0 
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
					pre[v].push_back(u);    //��v��ǰ��Ϊu 
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
	cin>>s;      //���������� 
	mp[s]=0;     //����Ӧ 0�ų��� 
	mp1[0]=s;    //0�ų��ж�Ӧ���
	 
	for(int i=1;i<N;i++){
		cin>>s>>v[i];
		mp[s]=i;         //��������һ����Ӧ�ı��
		mp1[i]=s; 
	}
	
	for(int i=0;i<K;i++){   //��ʼ����Ȩ 
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
