#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int cnt=0;
	scanf("%d",&n);
	int a[n];
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a[temp]=i;   //表明这个数字占着哪个位置 
	}
	for(int i=1;i<n;i++){
		if(i!=a[i]){
			while(a[0]!=0){
				swap(a[0],a[a[0]]);
				cnt++;
			}
			if(i!=a[i]){
				swap(a[0],a[i]);
			}
		}
	} 
	printf("%d",cnt);
	return 0;
}
