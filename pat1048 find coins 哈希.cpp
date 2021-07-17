#include<cstdio>
using namespace std;
int coin[501];               //硬币面额不超过500  
int main()
{
	int n,m;  				 //n是总共的硬币数目，m是要付的钱 
	scanf("%d %d",&n,&m);
	int temp;   
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		coin[temp]++;          //记录每个数字出现的次数 
	}

	for(int i=0;i<501;i++){
		if(coin[i]){
			coin[i]--;
			if(m>i&&coin[m-i]!=0){
				printf("%d %d",i,m-i);
				return 0;
			}
			coin[i]++;
		} 
	}
	printf("No Solution");
	return 0;
 } 
