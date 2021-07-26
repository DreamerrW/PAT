#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	double store;   //存货量  千吨 
	double sell;    //总售价  十亿 
	double price;   //单价    
}; 
bool cmp(node a,node b){
	return a.price>b.price;
}
int main()
{
	int n;  //n是月饼的总数，D是市场需求
	double D;
	scanf("%d %lf",&n,&D);
	vector<node> mooncake(n);
	for(int i=0;i<n;i++)
		scanf("%lf",&mooncake[i].store);  //存储 
	for(int i=0;i<n;i++){
		scanf("%lf",&mooncake[i].sell);   //售价 
		mooncake[i].price=mooncake[i].sell/mooncake[i].store;  //计算单价
	} 
	sort(mooncake.begin(),mooncake.end(),cmp); 
	
	double ans=0;
	 
	for(int i=0;i<n;i++){
		if(mooncake[i].store<=D){  //如果
			D-=mooncake[i].store;
			ans+=mooncake[i].sell;  //若是能全部卖出，就直接加上总售价 
		}
		else{
			ans+=mooncake[i].price*D;
			break;
		} 
	}
	printf("%.2f\n",ans);
	return 0;
 } 
