#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#define inf 9999999
using namespace std;
//�����1~N
int n,m;  
int e[210][210];
int main()
{
	fill(e[0],e[0]+210*210,inf);
	scanf("%d %d",&n,&m);
	int t1,t2;
	int k;  //k����ѯ���� 
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		e[t1][t2]=e[t2][t1]=1; 
	}
	scanf("%d",&k); 
	int n1;
	while(k--){
		scanf("%d",&n1);  //n1����� 
		vector<int> v(n1);
		set<int> s;
		int flag1=1,flag2=1;  //flag1�ж��Ƿ��ǻ����Ƿ񾭹�ÿ������Ҳ��ظ�  flag2�ж��Ƿ���ͨ 
		for(int i=0;i<n1;i++){
			scanf("%d",&v[i]);
			s.insert(v[i]);
		}
		if(s.size()!=n1-1||(n1-1)!=n||v[0]!=v[n1-1]) flag1=0;
		for(int i=0;i<n1-1;i++){
			if(e[v[i]][v[i+1]]!=1) flag2=0;  //·�߲�ͨ 
		}
		if(flag1&&flag2) printf("YES\n");
		else printf("NO\n");
	} 
	return 0;
}
