#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000];
int main()
{
	int n;
	scanf("%d",&n);
	int maxtemp=-1;
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a[temp]++;  //������ô�๫���������� 
		if(temp>maxtemp) maxtemp=temp;
	}
	int max;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if((n-sum)>=i) max=i;
	} 
	printf("%d",max);
 } 
