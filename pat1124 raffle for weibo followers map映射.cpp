#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string,int> mp;
vector<string> ans;
int main()
{
	int m,n,s;
	scanf("%d %d %d",&m,&n,&s);
	string t;
	for(int i=0;i<m;i++){
		cin>>t;
		ans.push_back(t);
	}
	int flag=0;
	for(int i=s-1;i<m;i+=n){
		if(mp.find(ans[i])==mp.end()){   //之前没有 
			cout<<ans[i]<<endl;
			flag=1; 
			mp[ans[i]]=1;
		}
		else{
			while(mp.find(ans[i])!=mp.end()) i++;
			cout<<ans[i]<<endl;	
			flag=1; 
			mp[ans[i]]=1;
		}
	}
	if(flag==0) printf("Keep going...");
	return 0; 
}
