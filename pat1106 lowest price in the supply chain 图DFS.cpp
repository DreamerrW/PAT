#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int N;
double P,r;
vector<int> v[100010];
double minprice=99999999;
int cnt;
void dfs(int root,int depth){
	if(v[root].size()==0){  //到达了边界 
		double temp=P*pow(1+r*0.01,depth);
		if(temp<minprice){
			minprice=temp;
			cnt=1;
		} 
		else if(temp==minprice)
			cnt++;
		return ;
	}
	for(int i=0;i<v[root].size();i++){
		dfs(v[root][i],depth+1);
	}
} 
int main()
{
	scanf("%d",&N);
	scanf("%lf %lf",&P,&r);
	int k;
	for(int i=0;i<N;i++){
		scanf("%d",&k);
		int temp;
		if(k==0) continue;
		for(int j=0;j<k;j++){
			scanf("%d",&temp);
			v[i].push_back(temp);
		}
	}
	dfs(0,0);  //0是根节点
	printf("%.4f %d",minprice,cnt);
	return 0;
 } 
