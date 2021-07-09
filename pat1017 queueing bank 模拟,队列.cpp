#include<cstdio>
#include<queue>
#include<algorithm> 
using namespace std;
//善用sort函数，注意sort函数只能对数组，vector，string进行排序 
struct custominfo{
	int arrive;  //到达时间 
	int time;  //服务时长 
}temp;

bool cmp1(custominfo a,custominfo b){    //按到达时间排序 
	return a.arrive<b.arrive;
};
bool cmp2(int a,int b)
{
	return a<b;
} 
int main()
{
	int n,k;  
	scanf("%d%d",&n,&k);                //n个用户，k个窗口 
	int hh,mm,ss,time;
	vector<custominfo> custom;          //定义n个用户的信息 
	vector<int> window(k,28800);        //k个窗口初始时间为8点 
	  
	for(int i=0;i<n;i++)                //将所有满足条件custom放入数组中 
	{
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&time);
		temp.arrive=hh*60*60+mm*60+ss;      //将时间转换为s 
		temp.time=time*60;
		if(temp.arrive>=61200)  continue;     //若到达时间已经大于17点 
		custom.push_back(temp);
	}
	sort(custom.begin(),custom.end(),cmp1);  //按照到达时间排序
	double result=0.0;
	
	for(int i=0;i<custom.size();i++)
	{
		sort(window.begin(),window.end(),cmp2);  //选出完成时间最快的那个窗口 
		if(window[0]<=custom[i].arrive)         //若顾客来晚了，则不用等待 
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
