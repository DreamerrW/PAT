#include<cstdio>
#include<set>
using namespace std;
double ans;
double Nc,Nt;  
int main()
{
	int n,m,k;      //n个set，每个set有m个数字，k对set要进行对比
	
	scanf("%d",&n); //s
	set<int> a[n];  //n个set 
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&temp);
			a[i].insert(temp);  //插入set中 
		}
	} 
	scanf("%d",&k); 
	int u,v;      //对比的对 
	while(k--){   //对比k次 
		Nc=Nt=0;
		scanf("%d %d",&u,&v);  //set[u]和set[v] 
		Nt=a[v-1].size();
		for(auto it=a[u-1].begin();it!=a[u-1].end();it++){
			if(a[v-1].find(*it)==a[v-1].end())  //没找到，即为不相同的数 
				Nt++;
			else 
				Nc++; 
		}
		ans=Nc/Nt*100;
		printf("%.1f%%\n",ans);    //%%表示输出% 
	} 
	return 0;
 } 
