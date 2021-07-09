#include<cstdio>
#include<queue>
#include<algorithm> 
using namespace std;
//����sort������ע��sort����ֻ�ܶ����飬vector��string�������� 
struct custominfo{
	int arrive;  //����ʱ�� 
	int time;  //����ʱ�� 
}temp;

bool cmp1(custominfo a,custominfo b){    //������ʱ������ 
	return a.arrive<b.arrive;
};
bool cmp2(int a,int b)
{
	return a<b;
} 
int main()
{
	int n,k;  
	scanf("%d%d",&n,&k);                //n���û���k������ 
	int hh,mm,ss,time;
	vector<custominfo> custom;          //����n���û�����Ϣ 
	vector<int> window(k,28800);        //k�����ڳ�ʼʱ��Ϊ8�� 
	  
	for(int i=0;i<n;i++)                //��������������custom���������� 
	{
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&time);
		temp.arrive=hh*60*60+mm*60+ss;      //��ʱ��ת��Ϊs 
		temp.time=time*60;
		if(temp.arrive>=61200)  continue;     //������ʱ���Ѿ�����17�� 
		custom.push_back(temp);
	}
	sort(custom.begin(),custom.end(),cmp1);  //���յ���ʱ������
	double result=0.0;
	
	for(int i=0;i<custom.size();i++)
	{
		sort(window.begin(),window.end(),cmp2);  //ѡ�����ʱ�������Ǹ����� 
		if(window[0]<=custom[i].arrive)         //���˿������ˣ����õȴ� 
		{
			window[0]=custom[i].arrive+custom[i].time;
		}
		else {
			result+=window[0]-custom[i].arrive;
			window[0]+=custom[i].time;
		}
	}  
	if(custom.size()==0)
	printf("0.0");
	else 
	printf("%.1f",result/60/custom.size());
	return 0;
}
