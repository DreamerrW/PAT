#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
double cmax,d,avg;  //最大油量，距离，每升油能走多久，n个加油站

struct node{
	double price;
	double dis;
}; 

vector<node> station;

bool cmp1(node a,node b){
	return a.dis<b.dis;
}

int main()
{
	scanf("%lf %lf %lf %d",&cmax,&d,&avg,&n);
	
	node temp;
	for(int i=0;i<n;i++){
		scanf("%lf %lf",&temp.price,&temp.dis);
		station.push_back(temp);
	}
	//增加一个距离为d,油价为0的加油站；
	temp.dis=d;
	temp.price=0;
	station.push_back(temp);
	
	sort(station.begin(),station.end(),cmp1);  //将加油站按照距离从小到大排序
	
	if(station[0].dis!=0){                   //若起点不为0，则直接退出即可 
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	
	double max1=cmax*avg;           //加满油一次所能走的最大的路 
	double nowgas=0.0;              //当前所剩下的油量 
	double nowdis=0.0;              //当前走过的距离 
	
	int i=0;                       //起点为i=0 
	double totalprice=0;           //总价格初始为0 
	while(nowdis<d){                   //当走过的距离达到目的地时，循环退出 
		int u=-1;
		int j=i+1;                 //从下一个加油站开始找 
		int minj=-1;              //找一个价格相对低的加油站 
		double min=10000;  
		int flag=0;
		while(station[j].dis<=station[i].dis+max1){      //在当前油站所能达到的最大距离中，找到价格最便宜的油站 
			flag=1;
			if(station[j].price<min){                    //minj是在没找到比当前价格低的加油站时的下策之选 
				minj=j;
				min=station[j].price;
			}
			if(station[j].price<station[i].price){      //只要找到一个比当前价格低的加油站，就起飞，退出循环 
				u=j;
				break;
			} 
			j++;
		} 
		
		if(u==-1){       //假如没找到，就加满油，然后开到minj这个加油站 
			if(flag==0) {           //flag=0,说明下一个加油站怎么开都开不到了 
				printf("The maximum travel distance = %.2f",nowdis+max1);
				return 0; 
			} 
			totalprice+=(cmax-nowgas)*station[i].price;           //价格相加 
			nowgas=cmax-(station[minj].dis-station[i].dis)/avg;
			nowdis=station[minj].dis; 
			i=minj;     //开到minj这个加油站 
		}
		else{           //假如找到了,就加到能开到这个加油站的油 
			totalprice+=(station[u].dis-station[i].dis-nowgas*avg)/avg*station[i].price;   //价格相加 
			nowgas=0; 
			nowdis=station[u].dis;
			i=u;        //以该加油站为起点 
		} 	
	}
	printf("%.2f",totalprice); 
	return 0;
}
