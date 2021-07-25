#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath> 
using namespace std;
//����������������������������Ǵ�С���������*** 
vector<int> v;
vector<int> level;


void levelorder(int start,int end,int index){
	if(start>end) return ;
	int n=end-start+1;          //�ڵ���
	int h=log(n+1)/log(2);      //log2(n+1)Ϊ�����߶�-1
	int leave=n-(pow(2,h)-1);   //���һ��Ľ����
	int root=start+(pow(2,h-1)-1)+min((int)pow(2,h-1),leave);  //�������Ľ����� 
	level[index]=v[root];       
	levelorder(start,root-1,2*index+1);  //�����±��0��ʼ��2*i+1Ϊ���㣬2*i+2Ϊ�Һ��� 
	levelorder(root+1,end,2*index+2); 
}

int main()
{
	int n;
	scanf("%d",&n);
	v.resize(n);
	level.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());   //�õ������������ 
	levelorder(0,n-1,0);
	printf("%d",level[0]);
	for(int i=1;i<n;i++)
		printf(" %d",level[i]);
	return 0;
 } 
