#include<cstdio>
#include<cmath>
using namespace std;  
//����һ�������� 
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
	if(n==1) printf("1");   //��Ϊ1�������1 
	
	int k=2;
	while(n!=1){           //һֱ����nΪ1Ϊֹ���ҵ����е����� 
		if(isprime(k)){    //�������������� 
			while(n%k==0){
				n=n/k;
				prime[k]++;
			}
		}
		k++;
	}
	int flag=0;   //flagΪ1��ʼ���*
	for(int i=0;i<k;i++){  //i<k���ɣ����ñ����������� 
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
