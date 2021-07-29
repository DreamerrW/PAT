#include<cstdio>
#include<cstdlib>
using namespace std;
long long gcd(long long a,long long b){  //最大公约数 
	long long temp;
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
//12 20
//20 12
//12 8 
//8 4
//4 0
//  1/5 2/7
int main()
{
	long long n,a,b,integer;
	long long suma=0,sumb=1;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		long long  gcdvalue;
		scanf("%lld/%lld",&a,&b);
		suma=a*sumb+suma*b;
		sumb=b*sumb; 
		gcdvalue=gcd(suma,sumb);
		suma/=gcdvalue;
		sumb/=gcdvalue;
	}
	integer=suma/sumb;
	if(integer!=0)  printf("%lld",integer);
	if(suma%sumb){
		if(integer!=0) printf(" ");
		printf("%lld/%lld",suma%sumb,sumb);
	}
	if(suma==0) printf("0");
	return 0;
}
