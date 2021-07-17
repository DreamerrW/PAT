#include<cstdio>
#include<vector>
using namespace std;
vector<int> sum;   //sum[i]��ʾ��1��i���������ֵĺ� 
vector<int> ans;   //������飬�ɶ���� 
int n,m;           //n������mΪ�� 

void find(int i,int &j,int &tempsum){   //�ҵ���i��ʼ��>=m���±��sum 
	int low=i,high=n;
	while(low<high){
		int mid=(low+high)/2;
		if(sum[mid]-sum[i-1]>=m)
			high=mid;
		else 
			low=mid+1;
	}
	j=high;
	tempsum=sum[j]-sum[i-1]; 
}
int main()
{
	scanf("%d %d",&n,&m);
	sum.resize(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int minans=sum[n];
	for(int i=1;i<=n;i++){
		int j,tempsum;
		find(i,j,tempsum);
		if(tempsum>minans) continue;
		if(tempsum>=m){
			if(tempsum<minans){
				ans.clear();      //�����ǰ�ĺ�С�����ҵ�����С��ֵ����֮ǰ�Ķ���� 
				minans=tempsum;
			}
			ans.push_back(i);    //i��j����𰸵�ջ 
			ans.push_back(j);
		}
	}
	for(int i=0;i<ans.size()-1;i+=2)
		printf("%d-%d\n",ans[i],ans[i+1]);
	return 0;
 } 
