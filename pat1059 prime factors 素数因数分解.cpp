#include<cstdio>
#include<cmath>
using namespace std;  
//建立一个素数表 
int prime[100000]={0};
bool isprime(int n){
	if(n<=1) return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0) return false;
	return true;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld=",n); 
	if(n==1) printf("1");   //若为1，则输出1 
	
	int k=2;
	while(n!=1){           //一直除到n为1为止，找到所有的因数 
		if(isprime(k)){    //如果这个数是素数 
			while(n%k==0){
				n=n/k;
				prime[k]++;
			}
		}
		k++;
	}
	int flag=0;   //flag为1后开始输出*
	for(int i=0;i<k;i++){  //i<k即可，不用遍历整个数组 
		if(prime[i]!=0){
			if(prime[i]>1){
				if(flag==0) printf("%d^%d",i,prime[i]);
				else printf("*%d^%d",i,prime[i]);
			}
			else{
				if(flag==0) printf("%d",i);
				else printf("*%d",i);
			}
			flag=1;
		}
	}
	return 0;
 } 
