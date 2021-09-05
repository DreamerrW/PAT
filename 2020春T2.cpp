#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
using namespace std;
vector<int> ans;
bool vis[100100]; //数字是否用过了 
vector<int> have;
bool dif[100100];
int a[11][1001];
int kick[11];  //是否出局 
int main(){
	int n,m;
	int s1,s2;
	cin>>s1>>s2;  //开始的两个数字 
	vis[s1]=vis[s2]=true; 
	dif[abs(s1-s2)]=true;
	have.push_back(s1);
	have.push_back(s2);
	cin>>n>>m;  //n个人。m个回合
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<m;i++){  //m回合 
		for(int j=0;j<n;j++){
			if(dif[a[j][i]]==true&&vis[a[j][i]]==false&&kick[j]==0){  //没被淘汰 且它的数字没被用过且是前面数字的差 
				vis[a[j][i]]=true;
				for(auto it:have){
					dif[abs(it-a[j][i])]=true;
				}
				have.push_back(a[j][i]);
			}
			else{
				if(kick[j]==0){
					kick[j]=1;
					printf("Round #%d: %d is out.\n",i+1,j+1);	
				}
			}
		}
	}
	int flag=1;
	for(int i=0;i<n;i++){
		if(kick[i]==0){ //没被淘汰
			ans.push_back(i+1);
			flag=0; 
		} 
	}
	if(flag==0){
		printf("Winner(s):");
		for(auto i:ans)
			printf(" %d",i);
	}
	else printf("No winner.");
}
