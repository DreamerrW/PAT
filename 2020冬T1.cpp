#include<iostream>
using namespace std;
int ans[1000];
int fb[1000];
int fib(int n){
	if(n==0||n==1)
		return ans[n]=1;
	else 
		return ans[n]=ans[n-2]+ans[n-1]; 
}
int main()
{
	int n;
	scanf("%d",&n);
	int dis=0;
	int num=0;
	int a=0;
	ans[a]=fib(a);
	while(ans[a]<=n)
	{
		dis=n-ans[a];
		a++;
		ans[a]=fib(a);
	}
	if(ans[a]-n>=dis)
		a--;
	cout<<ans[a];
	return 0;
 } 
