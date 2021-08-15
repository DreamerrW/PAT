#include<cstdio>
#include<vector>
#include<map>
using namespace std;
vector<vector<int>> e;
int main()
{
	int n,m; //结点编号0~n-1
	int t1,t2;
	scanf("%d %d",&n,&m);
	e.resize(n);
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	} 
	int k;
	scanf("%d",&k);
	while(k--){
		int flag=0;
		int n1,t;
		map<int,int> mp;
		scanf("%d",&n1);
		for(int i=0;i<n1;i++){
			scanf("%d",&t);
			mp[t]=1;
		}
		for(int i=0;i<n;i++){
			if(mp.find(i)==mp.end()){ //如果没找到 
				for(int j=0;j<e[i].size();j++){
					if(mp.find(e[i][j])==mp.end()){
						flag=1;
						break;
					}
				} 
			}
			if(flag==1) break;
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
