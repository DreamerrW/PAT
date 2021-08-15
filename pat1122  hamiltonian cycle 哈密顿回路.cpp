#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define inf 9999999
using namespace std;
//结点编号1~N
int n,m;  
int e[210][210];
int main()
{
	fill(e[0],e[0]+210*210,inf);
	scanf("%d %d",&n,&m);
	int t1,t2;
	int k;  //k个查询队列 
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		e[t1][t2]=e[t2][t1]=1; 
	}
	scanf("%d",&k); 
	int n1;
	while(k--){
		scanf("%d",&n1);  //n1个结点 
		vector<int> v(n1);
		set<int> s;
		int flag1=1,flag2=1;  //flag1判断是否是环，是否经过每个结点且不重复  flag2判断是否走通 
		for(int i=0;i<n1;i++){
			scanf("%d",&v[i]);
			s.insert(v[i]);
		}
		if(s.size()!=n1-1||(n1-1)!=n||v[0]!=v[n1-1]) flag1=0;
		for(int i=0;i<n1-1;i++){
			if(e[v[i]][v[i+1]]!=1) flag2=0;  //路走不通 
		}
		if(flag1&&flag2) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}
