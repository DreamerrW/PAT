#include<iostream>
#include<vector> 
#include<cmath> 
#define INF 9999999
using namespace std;
int n,m; //n������  m������վ
int k;   //k��·
int ds; //ds�Ǽ���վ����󸲸Ǿ���   
int e[1011][1011];
int dis[1011];
bool vis[1011]={false};
double average=INF;  //ƽ���ľ��� 
double mindis=-INF;      //��̵ľ��� 
int gas=-1;       //gas number
void dijkstra(int s){
	dis[s]=0;   //������Լ��ľ���Ϊ0
	for(int i=1;i<=n+m;i++){
		int u=-1,min=INF;
		for(int j=1;j<=n+m;j++){
			if(vis[j]==false&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		if(u==-1) return; //�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ  
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(vis[v]==false&&e[u][v]!=INF){  //���vδ����ռ&&u�ܵ���v 
				if(dis[u]+e[u][v]<dis[v]){   //���ͨ��u���Ż����� 
					dis[v]=dis[u]+e[u][v];	
				}
			}
		} 
	} 
}
int main()
{	 
	fill(e[0],e[0]+1011*1011,INF);
//	fill(dis,dis+1011,INF);
	scanf("%d %d %d %d",&n,&m,&k,&ds);
	for(int i=0;i<k;i++){  //k��· 
		string t1,t2;
		int a,b;           //a,bΪ����Ľ���� 
		int d;             //�����ľ������������ 
		cin>>t1>>t2>>d;
		if(t1[0]=='G') {
			t1.erase(0,1);  //ɾ���׸�Ԫ�� 
			a=n+stoi(t1);   //����վ����� N+stoi(t1)��  
		}
		else a=stoi(t1);    //���ӽ����Ϊ 1~N 
		if(t2[0]=='G'){
			t2.erase(0,1);
			b=n+stoi(t2); 
		}
		else b=stoi(t2);
		e[a][b]=e[b][a]=d;  //��Ȩ��ֵ 	 
	}
	
	for(int i=n+1;i<=n+m;i++){  //����  m��dijktra�㷨��ÿ�εõ�����վ����������������Сֵ 
		fill(dis,dis+1011,INF);
		fill(vis,vis+1011,false);
		dijkstra(i);          //��G1�ż���վ��ʼʹ��dijkstra�㷨 
		double tempmin=INF;
		double tempaverage=0;
		int flag=0; 
		for(int j=1;j<=n;j++){  //�����з��ӵ���̾����ƽ������ļ��� 
			 if(dis[j]<=ds){
			 	if(dis[j]<tempmin) 
			 		tempmin=dis[j];
			 	tempaverage+=dis[j];
			 }
			 else{             //���д���ds�ľ���,˵���������վ���� 
			 	flag=1;
			 	break; 
			 }
		}
		if(flag==0){ //�������վ���Խ��� 
			if(tempmin>mindis) { //��ξ���Ҫ�����ܵ�Զ,����С������������ƽ������ε���һ�� 
				mindis=tempmin; 
				average=tempaverage; 
				gas=i-n;   //gasΪ��i�ż���վ 
			}
			else if(tempmin==mindis&&tempaverage<average){
				mindis=tempmin; 
				average=tempaverage; 
				gas=i-n;   //gasΪ��i�ż���վ 
			}	
		}
	}
	if(gas!=-1){   //�ҵ��� 
		printf("G%d\n",gas);
		printf("%.1f %.1f",mindis,average/n);
	} 
	else
		printf("No Solution");
	return 0; 
}
