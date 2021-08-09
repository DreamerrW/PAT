#include<iostream>
#include<vector>
using namespace std;
struct node{
	int id;
	int l,r;
};
vector<node> v(21);
int a[21];
int maxn=-1,ans;
void dfs(int root,int index){
	if(index>maxn){
		maxn=index;
		ans=root;
	}
	if(v[root].l!=-1) dfs(v[root].l,index*2);
	if(v[root].r!=-1) dfs(v[root].r,index*2+1);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		v[i].id=i;
		string s1,s2;
		cin>>s1>>s2;
		if(s1=="-") v[i].l=-1;
		else{
			v[i].l=stoi(s1);
			a[stoi(s1)]=1;	
		}
		if(s2=="-") v[i].r=-1;
		else {
			v[i].r=stoi(s2); 
			a[stoi(s2)]=1;	
		}
	}
	int root;
	for(int i=0;i<n;i++){
		if(a[i]!=1){
			root=i;
			break;
		}
	}
	dfs(root,1);
	if(maxn==n)
		printf("YES %d",ans);
	else 
		printf("NO %d",root);
	return 0;
}
