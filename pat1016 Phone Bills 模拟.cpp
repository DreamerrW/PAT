#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>
//将给出的数据先按照姓名排序，再按照时间的先后顺序排列，这样遍历的时候，
//前后两个名字相同且前面的状态为on-line后面一个的状态为off-line的就是合格数据
using namespace std;
struct node{
	string name;
	int month,day,hour,minute;
	int time;
	int ifonline; 
};
int rate[25]={0};                 //24小时话费
double billfromzero(node call,int rate[])
{
	double total=rate[24]*60*call.day+rate[call.hour]*call.minute;
	for(int i=0;i<call.hour;i++)
	{
		total+=rate[i]*60;
	}
	return total/100.0;          //1美元等于100美分 
 } 
bool cmp(node a,node b)
{
	if(a.name!=b.name) return a.name<b.name;    //优先比较姓名，姓名相等则比较时间 
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
	scanf("%d",&n);           //n条通话记录 
	vector<node> data(n);
	for(int i=0;i<n;i++)
	{
    	cin>>data[i].name;
    	scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
    	string temp;
    	cin>>temp;
    	data[i].ifonline=(temp=="on-line")?1:0;   	
		data[i].time=data[i].day*24*60+data[i].hour*60+data[i].minute;   //通电话时间的计算    	
	}
	sort(data.begin(),data.end(),cmp);   //按照姓名排序 
	map<string, vector<node> > custom;    //建立名字到用户的map 
	for(int i=1;i<n;i++)
	{
		if(data[i].name==data[i-1].name&&data[i-1].ifonline==1&&data[i].ifonline==0)   //当前用户名字与前一个相同且是一对 
		{
			custom[data[i-1].name].push_back(data[i-1]);   //用户的一对通话记录存储在定义的map中的变长数组中 
			custom[data[i].name].push_back(data[i]); 
		}
	}
	for(auto it=custom.begin();it!=custom.end();it++)
	{
		vector<node> temp = it->second;
		cout<<it->first<<" ";
		printf("%02d\n",temp[0].month);    //打印月份，换行 
		double total=0.0;
		for(int i=0;i<temp.size();i+=2)    //custom里的数据是一对一对存储的 
		{
			double t=billfromzero(temp[i+1],rate)-billfromzero(temp[i],rate);                       //一桶电话的账单 
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",temp[i].day,temp[i].hour,temp[i].minute,temp[i+1].day,temp[i+1].hour,temp[i+1].minute,temp[i+1].time-temp[i].time,t);
			total+=t;
		}
		printf("Total amount: $%.2lf\n",total);
			
	} 
	
	return 0;
 } 
