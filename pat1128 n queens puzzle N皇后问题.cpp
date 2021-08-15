#include<cstdio>
#include<cmath>
using namespace std;
int p[1001];
int main()
{
	int k;
	scanf("%d",&k);
	int n;
	while(k--){
		scanf("%d",&n);
		int flag=0;
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
			for(int j=0;j<i;j++){  //遍历之前的皇后 
				if(p[j]==p[i]||abs(p[j]-p[i])==abs(j-i)){   //查看前面是否有皇后和当前的皇后在一个对角线上或者一行上 
					flag=1;
					break;
				}
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
 } 
