#include<cstdio>
#include<vector>
#include<map>
#include<set>
using namespace std;
int main()
{
	map<int,int> mp;
	map<int,int> mp1;
	set<int> ans; 
	int n; //N对cp
	int m; //m个客人 
	scanf("%d",&n);
	int t1,t2;
	for(int i=0;i<n;i++){
		scanf("%d %d",&t1,&t2);
		mp[t1]=t2;
		mp[t2]=t1;
	}
	scanf("%d",&m);
	int t3;
	for(int i=0;i<m;i++){
		scanf("%d",&t3);
		mp1[t3]=1;
	}
	for(auto it=mp1.begin();it!=mp1.end();it++){
		int k=it->first;
		if(mp1.find(mp[k])==mp1.end()) ans.insert(k);
	}
	printf("%d\n",ans.size()); 
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it!=ans.begin()) printf(" ");
		printf("%05d",*it);
	}
	 return 0;
 } 
