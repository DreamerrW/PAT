#include<stdio.h>
#define maxm 10001
//用动态规划来做 
int a[maxm];
int dp[maxm];
int start[maxm]; 

int main()    //模拟法解题 
{
	int k;
	int sum=0;
	int maxsum=0;
	int startpos=0,endpos=0;
	int tempstartpos=0;
	
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		if(sum<0)
		{
			sum=0;
			tempstartpos=i+1;
		}
		else if(sum>maxsum)
		{
			maxsum=sum;
			startpos=tempstartpos;
			endpos=i;
		}
	}
	if(maxsum<0)
	{
		maxsum=0;
		endpos=k-1;
	}
	printf("%d %d %d",maxsum,a[startpos],a[endpos]);
	return 0;

} 
/*int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int startpos=0,endpos=n-1,opt=a[0];
	// dp[i]=max(dp[i-1]+a[i],a[i]);
	int dp=a[0],tempstartpos=0,tempendpos=0;
	
	for(int i=1;i<n;i++){
		if(dp+a[i]>a[i]) {
			dp=dp+a[i];
			tempendpos=i;
		}
		else{
			dp=a[i];
			tempstartpos=i;tempendpos=i;
		}
		if(dp>opt){
			opt=dp;
			startpos=tempstartpos;endpos=tempendpos;
		}
	}
	if(opt<0){
		opt=0;startpos=0;endpos=n-1;
	}
	printf("%d %d %d",opt,a[startpos],a[endpos]); 
	return 0;
}*/

