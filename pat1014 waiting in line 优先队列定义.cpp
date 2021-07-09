#include<cstdio>
#include<vector>
#include<queue>
#define maxTime 540
using namespace std;
// ÿ����������һ���ṹ�������������ڱ�š��͡������굱ǰ�˿͵�ʱ��㡱���ٽ�����ṹ��������ȶ���
// �������ܱ�֤ÿ��ȡ����һ���������������Ǹ�����
struct customerinfo{
	int id;          //�ͻ���� ��0��k-1 
	int window;      //����id 
	int time;        //��ɷ�������Ҫ��ʱ�� 
	int finish;      //�˿͵����ʱ�� 
};
struct windowinfo{
	int id;          //����id 
	int alltime;     //���ڷ�����Ĺ˿͵������ʱ�� 
};

struct cmp{
 	bool operator() (windowinfo a,windowinfo b){
 		if(a.alltime!=b.alltime) return a.alltime>b.alltime;  //���Ƚ�nextС�ķ��ڶ��ף�
 		else return a.id>b.id;       //�������ʱ����ȣ����û�������ѡ�񴰿�idС����һ��             
	 } 
};

int main()
{
	int  n,m,k,q;                                //���������������������û���Ŀ���û���ѯ��Ŀ
	scanf("%d %d %d %d",&n,&m,&k,&q);
	
	struct customerinfo customer[k];             //����k��customer����Ϣ 
	struct windowinfo windows[n];				 //������Ϣ���� 
	
	queue<customerinfo> Q1[n];                   //n������ǰn������ 
	priority_queue<windowinfo,vector<windowinfo>,cmp> Q2;        //���崰�����ȶ��У�ÿ��ȡ����ɷ���Ĵ��� 
  
  	for(int i=0;i<(n*m>k?k:n*m);i++)         //�������ڵ��û��ź� 
	{
		scanf("%d",&customer[i].time);
		customer[i].id=i;
		customer[i].window=i%n;          
		Q1[i%n].push(customer[i]);           //�������ڵ��û�����ÿһ�����ڵĶ��� 
	}
	
	for(int i=0;i<(n<k?n:k);i++)             //�Ƚ�ÿ���������ڵ�һλ�����ʱ���趨�� 
	{
	 	windows[i].alltime=Q1[i].front().time; //ÿ�����ڵ��׸������Ϣ�͵�һ���˵���Ҫʱ����� 
		windows[i].id=i;					 //����id 
		Q2.push(windows[i]);                 //��n�����ڽ��봰�����ȶ��� 
	} 
	
	// m*n<k ������������ȴ���ʱ�����forѭ��
    for(int i=m*n;i<k;i++){
        scanf("%d",&customer[i].time);
        customer[i].id=i;
    }
    
	int wait=m*n;
	while(!Q2.empty())  //empty�������Q2�Ƿ�ǿ� 
	{
		struct windowinfo temp=Q2.top();                 //ȡ����һ����ɷ���Ĵ���
		Q2.pop();                                        //��ɷ���󣬳���
		struct customerinfo done=Q1[temp.id].front();    // ȡ�Ѿ���ɵ��Ǹ��˿�
		customer[done.id].finish=temp.alltime;           // ��������ɹ˿͵����ʱ��
		Q1[temp.id].pop();                               //n������������û���һ�ӳ���
		 
		if(!Q1[temp.id].empty())                         //����ǰ���ڵ������ӷǿ� 
		{
			temp.alltime+=Q1[temp.id].front().time;
			Q2.push(temp);                                 //ȡ���Ĵ��ڸ�����Ϣ������� 
		}
		if(wait<k){                                        // ������˵ȣ������ղ��Ǹ�����
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
