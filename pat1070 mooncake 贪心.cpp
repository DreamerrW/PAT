#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	double store;   //�����  ǧ�� 
	double sell;    //���ۼ�  ʮ�� 
	double price;   //����    
}; 
bool cmp(node a,node b){
	return a.price>b.price;
}
int main()
{
	int n;  //n���±���������D���г�����
	double D;
	scanf("%d %lf",&n,&D);
	vector<node> mooncake(n);
	for(int i=0;i<n;i++)
		scanf("%lf",&mooncake[i].store);  //�洢 
	for(int i=0;i<n;i++){
		scanf("%lf",&mooncake[i].sell);   //�ۼ� 
		mooncake[i].price=mooncake[i].sell/mooncake[i].store;  //���㵥��
	} 
	sort(mooncake.begin(),mooncake.end(),cmp); 
	
	double ans=0;
	 
	for(int i=0;i<n;i++){
		if(mooncake[i].store<=D){  //���
			D-=mooncake[i].store;
			ans+=mooncake[i].sell;  //������ȫ����������ֱ�Ӽ������ۼ� 
		}
		else{
			ans+=mooncake[i].price*D;
			break;
		} 
	}
	printf("%.2f\n",ans);
	return 0;
 } 
