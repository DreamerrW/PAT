#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> e[201];
int e1[201][201];
int n,m;
bool vis[201];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int t1,t2;
		cin>>t1>>t2;
		e[t1].push_back(t2);
		e[t2].push_back(t1);
		e1[t1][t2]=e1[t2][t1]=1;
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		fill(vis,vis+201,false);
		int l;
		cin>>l;
		vector<int> a(l);
		for(int j=0;j<l;j++){
			cin>>a[j];	
			vis[a[j]]=true;
		}
		bool flag=true;
		for(int j=0;j<l;j++){
			for(int k=j+1;k<l;k++){
				if(e1[a[j]][a[k]]==0) flag=false;  //如果有需要帮助 
			}
		}
		if(flag==false){
			printf("Area %d needs help.\n",i);
			continue;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			bool flag1=true;
			if(vis[j]==false){  //没又出现过的人 
				for(int k=0;k<l;k++){
					if(e1[j][a[k]]==0) {
						flag1=false;
						break;	
					}
				}
				if(flag1){
					ans=j;
					break; 
				}
			}
		}
		if(ans!=0)
			printf("Area %d may invite more people, such as %d.\n",i,ans);
		else 
			printf("Area %d is OK.\n",i);
	} 
}
