#include<iostream>
#include<vector> 
#include<cmath> 
#define INF 9999999
using namespace std;
int n,m; //n个房子  m个加油站
int k;   //k条路
int ds; //ds是加油站的最大覆盖距离   
int e[1011][1011];
int dis[1011];
bool vis[1011]={false};
double average=INF;  //平均的距离 
double mindis=-INF;      //最短的距离 
int gas=-1;       //gas number
void dijkstra(int s){
	dis[s]=0;   //起点与自己的距离为0
	for(int i=1;i<=n+m;i++){
		int u=-1,min=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) return; //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通  
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&e[u][v]!=INF){  //如果v未被攻占&&u能到达v 
				if(dis[u]+e[u][v]<dis[v]){   //如果通过u能优化距离 
					dis[v]=dis[u]+e[u][v];	
				}
			}
		} 
	} 
}
int main()
{	 
	fill(e[0],e[0]+1011*1011,INF);
//	fill(dis,dis+1011,INF);
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){  //k条路 
		string t1,t2;
		int a,b;           //a,b为输入的结点编号 
		int d;             //顶点间的距离绝对是整数 
		cin>>t1>>t2>>d;
		if(t1[0]=='G') {
			t1.erase(0,1);  //删除首个元素 
			a=n+stoi(t1);   //加油站结点在 N+stoi(t1)处  
		}
		else a=stoi(t1);    //房子结点编号为 1~N 
		if(t2[0]=='G'){
			t2.erase(0,1);
			b=n+stoi(t2); 
		}
		else b=stoi(t2);
		e[a][b]=e[b][a]=d;  //边权赋值 	 
	}
	
	for(int i=n+1;i<=n+m;i++){  //进行  m次dijktra算法，每次得到加油站到各个顶点距离的最小值 
		fill(dis,dis+1011,INF);
		fill(vis,vis+1011,false);
		dijkstra(i);          //从G1号加油站开始使用dijkstra算法 
		double tempmin=INF;
		double tempaverage=0;
		int flag=0; 
		for(int j=1;j<=n;j++){  //到所有房子的最短距离和平均距离的计算 
			 if(dis[j]<=ds){
			 	if(dis[j]<tempmin) 
			 		tempmin=dis[j];
			 	tempaverage+=dis[j];
			 }
			 else{             //若有大于ds的距离,说明这个加油站不行 
			 	flag=1;
			 	break; 
			 }
		}
		if(flag==0){ //这个加油站可以建造 
			if(tempmin>mindis) { //最段距离要尽可能的远,若最小距离相等则输出平均距离段的那一个 
				mindis=tempmin; 
				average=tempaverage; 
				gas=i-n;   //gas为第i号加油站 
			}
			else if(tempmin==mindis&&tempaverage<average){
				mindis=tempmin; 
				average=tempaverage; 
				gas=i-n;   //gas为第i号加油站 
			}	
		}
	}
	if(gas!=-1){   //找到了 
		printf("G%d\n",gas);
		printf("%.1f %.1f",mindis,average/n);
	} 
	else
		printf("No Solution");
	return 0; 
}
