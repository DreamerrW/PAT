#include<iostream>
#include<vector>
using namespace std;
struct node{
	int id;
	string data;
	int l,r;
};
vector<node> a;
int have[31];
string dfs(int root){
	if(a[root].l==-1&&a[root].r==-1) return a[root].data;
	if(a[root].l==-1&&a[root].r!=-1) return "("+a[root].data+dfs(a[root].r)+")";
	if(a[root].l!=-1&&a[root].r!=-1) return "("+dfs(a[root].l)+a[root].data+dfs(a[root].r)+")"; 
	 
}
int main()
{
	int n;
	scanf("%d",&n);
	a.resize(n+1);
	for(int i=1;i<=n;i++){
		a[i].id=i;
		cin>>a[i].data;
		cin>>a[i].l>>a[i].r;
		if(a[i].l!=-1) have[a[i].l]=1;
		if(a[i].r!=-1) have[a[i].r]=1;
	}
	int root;
	for(int i=1;i<=n;i++){  //找到根结点 
		if(have[i]!=1){
			root=i;
			break;
		}
	}
	string ans=dfs(root);
	if(ans[0]=='(') ans=ans.substr(1,ans.size()-2);
	cout<<ans;
	return 0;
}
