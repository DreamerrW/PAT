#include<cstdio>
using namespace std;
int k[200002];
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
	} 
	k[n + 1] = 0x7fffffff;  
	scanf("%d",&m);
	int midpos=(n+m+1)/2,i=1;
	int temp;
	int count=0;
	for(int j=1;j<=m;j++){
		scanf("%d",&temp);
		while(k[i]<temp){
			count++;
			if(count==midpos) printf("%d",k[i]);
			i++;
		}
		count++;
		if(count==midpos) printf("%d",temp);
		
	}
	while(i<=n){
		count++;
		if(count==midpos) printf("%d",k[i]);
		i++;
	}
	return 0;
	
 } 
