#include<iostream> 
#include<vector>
#include<cmath>
#define maxv 100010
using namespace std;
vector<int> e[maxv];
double amount[maxv]={0};
int n;
double p,r;  //价格和利率 
double ans=0;
void dfs(int s,int depth){
	if(e[s].size()==0){           //到达了根结点 
		ans+=amount[s]*p*pow(1+r*0.01,depth);
		return; 
	}
	for(int i=0;i<e[s].size();i++)
		dfs(e[s][i],depth+1);
}
int main()
{
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int k,temp;
		scanf("%d",&k);
		if(k==0){
			scanf("%lf",&amount[i]);   //若是零售商 则输入商品数量 
		}
		for(int j=0;j<k;j++){     //若不是0，则输入下级 
			scanf("%d",&temp);
			e[i].push_back(temp);
		}
	}   
	dfs(0,0);                   //从根节点开始，初始高度为0 
	printf("%.1f",ans);
	return 0;
}
