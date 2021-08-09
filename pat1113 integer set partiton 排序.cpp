#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n); //10¸öÊý
	vector<int> a(n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	int s1=0,s2=0;
	for(int i=0;i<n;i++){
		if(i<n/2) s1+=a[i];
		else s2+=a[i];
	} 
	if(n%2==0) printf("0 ");
	else printf("1 ");
	printf("%d",s2-s1);
	return 0;
 } 
