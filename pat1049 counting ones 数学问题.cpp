#include<cstdio>
using namespace std;
int main() 
{
	int n,low=0,high=0,now=1; 
	int p=1;   //数量级 
	int ans=0; //结果 
 	scanf("%d",&n);
 	int m=n;  //副本 
 	while(n) {
 		now=n%10;       //当前位 
 		high=m/(p*10);  //计算高位 
		low=m%p;       //计算低位 
		if(now<1)  ans+=high*p;  //小于1，高位*数量级
		else if(now==1) ans+=high*p+low+1;
		else ans+=(high+1)*p;
		
		p*=10;
		n/=10;
 	}
 	printf("%d", ans);
 	return 0;
}
