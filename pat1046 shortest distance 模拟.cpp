#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int n;              //n¸ö³ö¿Ú
	scanf("%d",&n);
	vector<int> dis(n+1);
	int sum=0; 
	int temp;
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		sum+=temp;
		dis[i]=sum;
	}
	int m;
	scanf("%d",&m);
	int u,v;
	while(m--){
		scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);
		temp=dis[v-1]-dis[u-1];
		printf("%d\n",min(temp,sum-temp));
	} 
	return 0;
} 
