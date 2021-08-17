#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int main()
{
	int n,m;
	cin>>n>>m;
	//结点编号1~N
	vector<int> e[1010];
	int in[1010];  //每个结点的入度
	fill(in,in+1010,0); 
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		e[a].push_back(b); //有向边 
		in[b]++; //入度加一 
	}
	int k;
	cin>>k;
	int temp;
	for(int i=0;i<k;i++){  //k个判断队列 
		int judge=1;
		vector<int> tin(in,in+n+1);  //用in数组来初始化tin 
		for(int j=0;j<n;j++){
			cin>>temp;
			if(judge==1){
				if(tin[temp]!=0){
					ans.push_back(i); //不是拓扑排序
					judge=0; 
				}	
				else{
					for(int k=0;k<e[temp].size();k++)
						tin[e[temp][k]]--;   //删除边 
				}
			}
		} 
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	} 
	return 0;
 } 
