#include<cstdio>
using namespace std;
int main() 
{
	int n,low=0,high=0,now=1; 
	int p=1;   //������ 
	int ans=0; //��� 
 	scanf("%d",&n);
 	int m=n;  //���� 
 	while(n) {
 		now=n%10;       //��ǰλ 
 		high=m/(p*10);  //�����λ 
		low=m%p;       //�����λ 
		if(now<1)  ans+=high*p;  //С��1����λ*������
		else if(now==1) ans+=high*p+low+1;
		else ans+=(high+1)*p;
		
		p*=10;
		n/=10;
 	}
 	printf("%d", ans);
 	return 0;
}
