#include<cstdio>
#include<set>
using namespace std;
double ans;
double Nc,Nt;  
int main()
{
	int n,m,k;      //n��set��ÿ��set��m�����֣�k��setҪ���жԱ�
	
	scanf("%d",&n); //s
	set<int> a[n];  //n��set 
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&temp);
			a[i].insert(temp);  //����set�� 
		}
	} 
	scanf("%d",&k); 
	int u,v;      //�ԱȵĶ� 
	while(k--){   //�Ա�k�� 
		Nc=Nt=0;
		scanf("%d %d",&u,&v);  //set[u]��set[v] 
		Nt=a[v-1].size();
		for(auto it=a[u-1].begin();it!=a[u-1].end();it++){
			if(a[v-1].find(*it)==a[v-1].end())  //û�ҵ�����Ϊ����ͬ���� 
				Nt++;
			else 
				Nc++; 
		}
		ans=Nc/Nt*100;
		printf("%.1f%%\n",ans);    //%%��ʾ���% 
	} 
	return 0;
 } 
