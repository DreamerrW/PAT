#include<cstdio>
#include<cmath>
using namespace std;

bool isprime(int n)    //�ж�һ�����Ƿ�Ϊ���� 
{
	if(n<=1)  return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		return false;
	}
	return true;
 } 
int change(int n,int radix)    //��������radix������������ת��Ϊ10���ƣ� 
{
	int ans=0;				
	while(n)
	{
		ans=ans*radix+n%radix;
		n=n/radix;
	}
	return ans;
}
int main()
{
 	int n;
 	int radix;
 	int num;
 	while(1)
 	{	
 		scanf("%d",&n);
 		if(n<0) break;
 		scanf("%d",&radix);
		num=change(n,radix);
		if(isprime(n)&&isprime(num))
		printf("Yes\n");
		else 
		printf("No\n");  
	 }
	 return 0;
 }
