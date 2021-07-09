#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>
//�������������Ȱ������������ٰ���ʱ����Ⱥ�˳�����У�����������ʱ��
//ǰ������������ͬ��ǰ���״̬Ϊon-line����һ����״̬Ϊoff-line�ľ��Ǻϸ�����
using namespace std;
struct node{
	string name;
	int month,day,hour,minute;
	int time;
	int ifonline; 
};
int rate[25]={0};                 //24Сʱ����
double billfromzero(node call,int rate[])
{
	double total=rate[24]*60*call.day+rate[call.hour]*call.minute;
	for(int i=0;i<call.hour;i++)
	{
		total+=rate[i]*60;
	}
	return total/100.0;          //1��Ԫ����100���� 
 } 
bool cmp(node a,node b)
{
	if(a.name!=b.name) return a.name<b.name;    //���ȱȽ����������������Ƚ�ʱ�� 
	else return a.time<b.time;
}
int main()
{  
	int n;                   
	for(int i=0;i<24;i++)
	{
		scanf("%d",&rate[i]);  
		rate[24]+=rate[i];
	}
	scanf("%d",&n);           //n��ͨ����¼ 
	vector<node> data(n);
	for(int i=0;i<n;i++)
	{
    	cin>>data[i].name;
    	scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
    	string temp;
    	cin>>temp;
    	data[i].ifonline=(temp=="on-line")?1:0;   	
		data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;   //ͨ�绰ʱ��ļ���    	
	}
	sort(data.begin(),data.end(),cmp);   //������������ 
	map<string, vector<node> > custom;    //�������ֵ��û���map 
	for(int i=1;i<n;i++)
	{
		if(data[i].name==data[i-1].name&&data[i-1].ifonline==1&&data[i].ifonline==0)   //��ǰ�û�������ǰһ����ͬ����һ�� 
		{
			custom[data[i-1].name].push_back(data[i-1]);   //�û���һ��ͨ����¼�洢�ڶ����map�еı䳤������ 
			custom[data[i].name].push_back(data[i]); 
		}
	}
	for(auto it=custom.begin();it!=custom.end();it++)
	{
		vector<node> temp = it->second;
		cout<<it->first<<" ";
		printf("%02d\n",temp[0].month);    //��ӡ�·ݣ����� 
		double total=0.0;
		for(int i=0;i<temp.size();i+=2)    //custom���������һ��һ�Դ洢�� 
		{
			double t=billfromzero(temp[i+1],rate)-billfromzero(temp[i],rate);                       //һͰ�绰���˵� 
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",temp[i].day,temp[i].hour,temp[i].minute,temp[i+1].day,temp[i+1].hour,temp[i+1].minute,temp[i+1].time-temp[i].time,t);
			total+=t;
		}
		printf("Total amount: $%.2lf\n",total);
			
	} 
	
	return 0;
 } 
