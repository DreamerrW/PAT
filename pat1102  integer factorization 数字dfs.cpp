#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int n,k,p;
int maxfacsum=-1;
vector<int> v,ans;
vector<int> tempans;
void dfs(int index,int tempsum,int tempk,int facsum){
	if(tempk==k){
		if(tempsum==n&&facsum>maxfacsum){
			ans=tempans;
			maxfacsum=facsum;
		}
		return;
	}
	while(index>=1){
		if(tempsum+v[index]<=n){
			tempans[tempk]=index;
			dfs(index,tempsum+v[index],tempk+1,facsum+index);
		}
		//if(index==1) return;
		index--;
	}
}
int main()
{
	scanf("%d %d %d",&n,&k,&p);
	int temp=0,index=1;
	while(temp<=n){
		v.push_back(temp);
		temp=pow(index,p);
		index++;
	}//建立幂数组
	tempans.resize(k);
	dfs(v.size()-1,0,0,0);
	if(maxfacsum==-1) {
		printf("Impossible");
		return 0;		
	}
	printf("%d = ",n);
	for(int i=0;i<ans.size();i++){
		if(i!=0) printf(" + ");
		printf("%d^%d",ans[i],p); 
	}
	return 0;
 } 
