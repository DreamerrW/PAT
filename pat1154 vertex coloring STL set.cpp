#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n,m; //n是顶点数，m是边数 
int main()
{
	cin>>n>>m;
	vector<int> v[n];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	} 
	int k;
	cin>>k; 
	while(k--){
		set<int> colors;
		vector<int> color(n);
		int flag=0;
		for(int i=0;i<n;i++){
			cin>>color[i];
			colors.insert(color[i]);
		}
		for(int i=0;i<n;i++){
			if(flag) break;
			for(int j=0;j<v[i].size();j++){
				if(color[i]==color[v[i][j]]){
					flag=1; 
					break;
				}		
			}
		}
		if(flag) printf("No\n");
		else printf("%d-coloring\n",colors.size());
	}
	return 0;
 } 
