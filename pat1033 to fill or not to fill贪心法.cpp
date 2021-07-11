#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
double cmax,d,avg;  //������������룬ÿ�������߶�ã�n������վ

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
	//����һ������Ϊd,�ͼ�Ϊ0�ļ���վ��
	temp.dis=d;
	temp.price=0;
	station.push_back(temp);
	
	sort(station.begin(),station.end(),cmp1);  //������վ���վ����С��������
	
	if(station[0].dis!=0){                   //����㲻Ϊ0����ֱ���˳����� 
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	
	double max1=cmax*avg;           //������һ�������ߵ�����· 
	double nowgas=0.0;              //��ǰ��ʣ�µ����� 
	double nowdis=0.0;              //��ǰ�߹��ľ��� 
	
	int i=0;                       //���Ϊi=0 
	double totalprice=0;           //�ܼ۸��ʼΪ0 
	while(nowdis<d){                   //���߹��ľ���ﵽĿ�ĵ�ʱ��ѭ���˳� 
		int u=-1;
		int j=i+1;                 //����һ������վ��ʼ�� 
		int minj=-1;              //��һ���۸���Ե͵ļ���վ 
		double min=10000;  
		int flag=0;
		while(station[j].dis<=station[i].dis+max1){      //�ڵ�ǰ��վ���ܴﵽ���������У��ҵ��۸�����˵���վ 
			flag=1;
			if(station[j].price<min){                    //minj����û�ҵ��ȵ�ǰ�۸�͵ļ���վʱ���²�֮ѡ 
				minj=j;
				min=station[j].price;
			}
			if(station[j].price<station[i].price){      //ֻҪ�ҵ�һ���ȵ�ǰ�۸�͵ļ���վ������ɣ��˳�ѭ�� 
				u=j;
				break;
			} 
			j++;
		} 
		
		if(u==-1){       //����û�ҵ����ͼ����ͣ�Ȼ�󿪵�minj�������վ 
			if(flag==0) {           //flag=0,˵����һ������վ��ô������������ 
				printf("The maximum travel distance = %.2f",nowdis+max1);
				return 0; 
			} 
			totalprice+=(cmax-nowgas)*station[i].price;           //�۸���� 
			nowgas=cmax-(station[minj].dis-station[i].dis)/avg;
			nowdis=station[minj].dis; 
			i=minj;     //����minj�������վ 
		}
		else{           //�����ҵ���,�ͼӵ��ܿ����������վ���� 
			totalprice+=(station[u].dis-station[i].dis-nowgas*avg)/avg*station[i].price;   //�۸���� 
			nowgas=0; 
			nowdis=station[u].dis;
			i=u;        //�Ըü���վΪ��� 
		} 	
	}
	printf("%.2f",totalprice); 
	return 0;
}
