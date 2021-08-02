#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int id;
	vector<int> child;
	
};
vector<node> ans;
int N,M;
int deep[101];  
void bfs(int s){
	queue<node> q;
	q.push(ans[s]);
	while(!q.empty()){
		node top=q.front();
		q.pop();
		for(int i=0;i<top.child.size();i++){
			deep[top.child[i]]=deep[top.id]+1;
			q.push(ans[top.child[i]]);
		}
	} 
}
int main()
{
	scanf("%d %d",&N,&M); 
	ans.resize(N+1); 
	for(int i=1;i<=N;i++)
		ans[i].id=i; 
	for(int i=0;i<M;i++){        //M个有孩子的结点 
		int t1,k,t2;
		scanf("%d %d",&t1,&k);   //t1结点有k个孩子  
		for(int j=0;j<k;j++){
			scanf("%d",&t2);
			ans[t1].child.push_back(t2);   //孩子结点进入 
		}
	}
	deep[1]=1; //根节点高度为1 
	bfs(1);
	int bottom=0;  //最深的高度 
	for(int i=1;i<=N;i++){
		if(deep[i]>bottom)
			bottom=deep[i];
	}
	int num,maxnum=0;
	int maxlayer;
	for(int i=1;i<=bottom;i++){  //高度为1到max 
		num=0;
		for(int j=1;j<=N;j++){
			if(deep[j]==i)
				 num++;
		}
		if(num>maxnum){
			maxnum=num;
			maxlayer=i;
		}	
	}
	printf("%d %d",maxnum,maxlayer);
	return 0;
}
