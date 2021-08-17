#include<iostream>
#include<vector>
#include<algorithm>
#define inf 99999
using namespace std;
int e[210][210];
int mintotal=inf;
int minpath;
int main()
{
	fill(e[0],e[0]+210*210,inf);
	int n; //城市数目 1~n
	int m; // 边数
	int k,n1;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t1,t2;
		int dis;
		cin>>t1>>t2>>dis;
		e[t1][t2]=e[t2][t1]=dis;		
	}
	cin>>k;
	for(int j=1;j<=k;j++){
		cin>>n1;
		int total=0;
		vector<int> v(n1);
		vector<int> hash(n1);
		int iscycle=1;
		for(int i=0;i<n1;i++){
			cin>>v[i];
			hash[v[i]]=1;
		}
		if(v[0]!=v[n1-1]) iscycle=0;
		for(int i=0;i<n1-1;i++){
			if(e[v[i]][v[i+1]]==inf)  //如果不是环 
				iscycle=0;
			total+=e[v[i]][v[i+1]];  //路径长度 
		} 
		for(int i=1;i<=n;i++){  //判断是否每个点都在 
			if(hash[i]==0){
				iscycle=0;
				break;
			}
		}	
		if(iscycle==0){  //不是一个cycle 
			if(total>=inf) //路径不存在 
				printf("Path %d: NA (Not a TS cycle)\n",j); 
			else 
				printf("Path %d: %d (Not a TS cycle)\n",j,total); 
		} 
		else{
		 	if(v.size()==n+1)  //是一个简单回路 
		 		printf("Path %d: %d (TS simple cycle)\n",j,total); 
		 	else 
			 	printf("Path %d: %d (TS cycle)\n",j,total); 
		}
		if(total<mintotal&&iscycle!=0){
			mintotal=total;	
			minpath=j;
		}
	}
	printf("Shortest Dist(%d) = %d",minpath,mintotal);
	return 0;
 } 
