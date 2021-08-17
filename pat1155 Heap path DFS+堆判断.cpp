#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v;
vector<int> t;
void dfs(int i){
	if(i>=n) return;
	if(2*i+1>n){ //已经是叶子结点 
		v.push_back(t[i]);
		for(int j=0;j<v.size();j++)
			printf("%d%s",v[j],j!=v.size()-1?" ":"\n");
		v.pop_back();
		return ;
	}
	v.push_back(t[i]);
	dfs(2*i+2);
	dfs(2*i+1);
	v.pop_back();
}
int main()
{
	cin>>n;
	t.resize(n);
	for(int i=0;i<n;i++)
		cin>>t[i];
	dfs(0);
	int ismin=1,ismax=1;
	for(int i=0;2*i+1<n;i++){
		if(2*i+2<n){
			if(t[i]<t[2*i+1]||t[i]<t[2*i+2]) ismax=0;
			if(t[i]>t[2*i+1]||t[i]>t[2*i+2]) ismin=0; 
		}
		else {
			if(t[i]<t[2*i+1]) ismax=0;
			if(t[i]>t[2*i+1]) ismin=0;
		}
	}
	if(ismin==1) 
		printf("Min Heap");
	else 
		printf("%s",ismax==1?"Max Heap":"Not Heap");
	return 0;
}
