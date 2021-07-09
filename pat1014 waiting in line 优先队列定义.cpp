#include<cstdio>
#include<vector>
#include<queue>
#define maxTime 540
using namespace std;
// 每个窗口设置一个结构体来描述“窗口编号”和“服务完当前顾客的时间点”，再将这个结构体加入优先队列
// 这样就能保证每次取出的一定是最早服务完的那个窗口
struct customerinfo{
	int id;          //客户编号 从0到k-1 
	int window;      //窗口id 
	int time;        //完成服务所需要的时间 
	int finish;      //顾客的完成时间 
};
struct windowinfo{
	int id;          //窗口id 
	int alltime;     //窗口服务过的顾客的总完成时间 
};

struct cmp{
 	bool operator() (windowinfo a,windowinfo b){
 		if(a.alltime!=b.alltime) return a.alltime>b.alltime;  //优先将next小的放在队首，
 		else return a.id>b.id;       //若是完成时间相等，则用户会优先选择窗口id小的那一个             
	 } 
};

int main()
{
	int  n,m,k,q;                                //窗口数，黄线内人数，用户数目，用户查询数目
	scanf("%d %d %d %d",&n,&m,&k,&q);
	
	struct customerinfo customer[k];             //定义k个customer的信息 
	struct windowinfo windows[n];				 //窗口信息数组 
	
	queue<customerinfo> Q1[n];                   //n个窗口前n条队列 
	priority_queue<windowinfo,vector<windowinfo>,cmp> Q2;        //定义窗口优先队列，每次取出完成服务的窗口 
  
  	for(int i=0;i<(n*m>k?k:n*m);i++)         //将黄线内的用户排好 
	{
		scanf("%d",&customer[i].time);
		customer[i].id=i;
		customer[i].window=i%n;          
		Q1[i%n].push(customer[i]);           //将黄线内的用户加入每一个窗口的队列 
	}
	
	for(int i=0;i<(n<k?n:k);i++)             //先将每个窗口排在第一位的完成时间设定好 
	{
	 	windows[i].alltime=Q1[i].front().time; //每个窗口的首个完成信息和第一个人的需要时间相等 
		windows[i].id=i;					 //窗口id 
		Q2.push(windows[i]);                 //将n个窗口进入窗口优先队列 
	} 
	
	// m*n<k 即有人在线外等待的时候进入for循环
    for(int i=m*n;i<k;i++){
        scanf("%d",&customer[i].time);
        customer[i].id=i;
    }
    
	int wait=m*n;
	while(!Q2.empty())  //empty函数检测Q2是否非空 
	{
		struct windowinfo temp=Q2.top();                 //取出第一个完成服务的窗口
		Q2.pop();                                        //完成服务后，出队
		struct customerinfo done=Q1[temp.id].front();    // 取已经完成的那个顾客
		customer[done.id].finish=temp.alltime;           // 更新已完成顾客的完成时间
		Q1[temp.id].pop();                               //n条队列中完成用户那一队出队
		 
		if(!Q1[temp.id].empty())                         //若当前窗口的这条队非空 
		{
			temp.alltime+=Q1[temp.id].front().time;
			Q2.push(temp);                                 //取出的窗口更新信息后再入队 
		}
		if(wait<k){                                        // 如果有人等，则加入刚才那个窗口
            customer[wait].window=temp.id;
            Q1[temp.id].push(customer[wait]);
            wait++;
        }
		
	}
	int queries;
	for(int i=0;i<q;i++){
        scanf("%d",&queries);
        if(customer[queries-1].finish-customer[queries-1].time>=maxTime) printf("Sorry\n");
        else printf("%02d:%02d\n",customer[queries-1].finish/60+8,customer[queries-1].finish%60);
    }
		 
} 
