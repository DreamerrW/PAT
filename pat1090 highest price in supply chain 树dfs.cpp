#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int root;       //根节点 
double P,r;      //本金和利率 
vector<int> v[10010];
double ans=0; 
int cnt=0;
void dfs(int s,int depth){
	if(v[s].size()==0){    //递归边界 
		double tempans=P*pow(1+r*0.01,depth);
			if(tempans>ans){
				ans=tempans;
				cnt=1;	
			}
			else if(tempans==ans) cnt++;
		return;
	}
	for(int i=0;i<v[s].size();i++){
		dfs(v[s][i],depth+1);
	}

}
int main()
{
	int N;
	cin>>N>>P>>r;
	int temp;
	for(int i=0;i<N;i++){
		cin>>temp;
		if(temp==-1)
			root=i;
		else 
			v[temp].push_back(i);    //i结点的供应商是temp 
	}
	dfs(root,0);
	printf("%.2f %d",ans,cnt); 
	return 0;
} 
