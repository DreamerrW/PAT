#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	int sum=v[0];
	for(int i=1;i<n;i++){
		sum=(sum+v[i])/2;
	}
	printf("%d",sum);
	return 0;
 } 
