#include<iostream> 
#include<vector>
#include<cmath>
#define maxv 100010
using namespace std;
vector<int> e[maxv];
double amount[maxv]={0};
int n;
double p,r;  //�۸������ 
double ans=0;
void dfs(int s,int depth){
	if(e[s].size()==0){           //�����˸���� 
		ans+=amount[s]*p*pow(1+r*0.01,depth);
		return; 
	}
	for(int i=0;i<e[s].size();i++)
		dfs(e[s][i],depth+1);
}
int main()
{
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int k,temp;
		scanf("%d",&k);
		if(k==0){
			scanf("%lf",&amount[i]);   //���������� ��������Ʒ���� 
		}
		for(int j=0;j<k;j++){     //������0���������¼� 
			scanf("%d",&temp);
			e[i].push_back(temp);
		}
	}   
	dfs(0,0);                   //�Ӹ��ڵ㿪ʼ����ʼ�߶�Ϊ0 
	printf("%.1f",ans);
	return 0;
}
