#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	double temp;
	long double ans=0; 
	for(int i=1;i<=n;i++){
		scanf("%lf",&temp);
		ans+=temp*i*(n-i+1);	
	}
	printf("%.2lf",ans);
	return 0;		
} 
