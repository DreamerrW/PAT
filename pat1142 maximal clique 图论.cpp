#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int e[201][201];
bool vis[201];
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		e[t1][t2]=e[t2][t1]=1;
	}
	int k;
	scanf("%d",&k);
	int flag;
	while(k--){
		flag=0;
		fill(vis,vis+201,false);
		int n1;
		scanf("%d",&n1);
		vector<int> v(n1);
		for(int i=0;i<n1;i++){
			scanf("%d",&v[i]);
			vis[v[i]]=true;
		}
		for(int i=0;i<n1;i++){  //先判断是不是Cilque 
			for(int j=i+1;j<n1;j++){
				if(e[v[i]][v[j]]==0){
					printf("Not a Clique\n");
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) continue;
		for(int i=1;i<=n;i++){ //1到n号结点
			if(vis[i]==false){
				for(int j=0;j<n1;j++){
					if(e[v[j]][i]==0) break;
					if(j==n1-1){
						printf("Not Maximal\n");
						flag=1;
						break;
					}
				}
			} 
			if(flag) break; 
		}
		if(flag) continue;
		printf("Yes\n");
	}
	return 0;
}
