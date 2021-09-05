#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> e[501];
int main()
{
	int n,r,k;
	cin>>n>>r>>k; //n是区域，r是相邻区域，k是动物种类 
	//区域从1 ~n
	for(int i=0;i<r;i++){
		int t1,t2;
		cin>>t1>>t2;
		e[t1].push_back(t2); //表示相邻 
		e[t2].push_back(t1);

	} 
	int m;
	cin>>m;  //m种方案 
	while(m--){
		vector<int> a(n+1);
		set<int> b;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b.insert(a[i]);
		}
		if(b.size()!=k){
			if(b.size()<k)
				printf("Error: Too few species.\n");
			else 
				printf("Error: Too many species.\n");
			continue; 
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<e[i].size();j++){
				if(a[i]==a[e[i][j]])
					flag=1;
			}
		}
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
