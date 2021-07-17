#include<cstdio>
#include<vector>
using namespace std;
vector<int> sum;   //sum[i]表示从1到i的所有数字的和 
vector<int> ans;   //结果数组，成对输出 
int n,m;           //n个数，m为和 

void find(int i,int &j,int &tempsum){   //找到从i开始数>=m的下表和sum 
	int low=i,high=n;
	while(low<high){
		int mid=(low+high)/2;
		if(sum[mid]-sum[i-1]>=m)
			high=mid;
		else 
			low=mid+1;
	}
	j=high;
	tempsum=sum[j]-sum[i-1]; 
}
int main()
{
	scanf("%d %d",&n,&m);
	sum.resize(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int minans=sum[n];
	for(int i=1;i<=n;i++){
		int j,tempsum;
		find(i,j,tempsum);
		if(tempsum>minans) continue;
		if(tempsum>=m){
			if(tempsum<minans){
				ans.clear();      //如果当前的和小于能找到的最小的值，则之前的都清除 
				minans=tempsum;
			}
			ans.push_back(i);    //i和j进入答案的栈 
			ans.push_back(j);
		}
	}
	for(int i=0;i<ans.size()-1;i+=2)
		printf("%d-%d\n",ans[i],ans[i+1]);
	return 0;
 } 
