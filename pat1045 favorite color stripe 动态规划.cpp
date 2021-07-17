#include <iostream>
#include <vector>
//动态规划 
using namespace std;
int color[201],a[10001],dp[10001];
int main()
{
	int n; //n种颜色库
	int m; //m个喜欢的颜色 
	int l; 
	int temp;
	int maxn=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&temp);
		color[temp]=i;     //喜欢的颜色的优先级，i从1到m,数字越低优先级越高  
	}
	int num=1;
	scanf("%d",&l);
	for(int i=0;i<l;i++){
		scanf("%d",&temp);
		if(color[temp]!=0) a[num++]=temp;   //在输入过程中剔除掉不喜欢的元素 
	}
	for(int i=1;i<num;i++){                //遍历剩下的喜欢的元素序列 
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(color[a[i]]>=color[a[j]])  //与自己前面的颜色比较，遇到比自己优先级低的，就进行比较 
				dp[i]=max(dp[i],dp[j]+1);
		}
		maxn=max(dp[i],maxn);
	} 
	printf("%d",maxn);
	return 0;
}
