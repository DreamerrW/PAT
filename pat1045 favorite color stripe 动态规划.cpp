#include <iostream>
#include <vector>
//��̬�滮 
using namespace std;
int color[201],a[10001],dp[10001];
int main()
{
	int n; //n����ɫ��
	int m; //m��ϲ������ɫ 
	int l; 
	int temp;
	int maxn=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&temp);
		color[temp]=i;     //ϲ������ɫ�����ȼ���i��1��m,����Խ�����ȼ�Խ��  
	}
	int num=1;
	scanf("%d",&l);
	for(int i=0;i<l;i++){
		scanf("%d",&temp);
		if(color[temp]!=0) a[num++]=temp;   //������������޳�����ϲ����Ԫ�� 
	}
	for(int i=1;i<num;i++){                //����ʣ�µ�ϲ����Ԫ������ 
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(color[a[i]]>=color[a[j]])  //���Լ�ǰ�����ɫ�Ƚϣ��������Լ����ȼ��͵ģ��ͽ��бȽ� 
				dp[i]=max(dp[i],dp[j]+1);
		}
		maxn=max(dp[i],maxn);
	} 
	printf("%d",maxn);
	return 0;
}
