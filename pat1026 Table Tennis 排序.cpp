#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
//ÿ��ȡ��������һ�����ӣ�����vip���ӣ������û��ǲ���vip�û������ǣ���ֱ��ʹ�ã������ǣ������¸�vip�û��������ܲ��ܵȵ� 
//������vip���ӣ������ǲ���vip�û� �����ǣ������������������vip���ܲ���Ϊ�����������ǣ���ֱ�ӷ���
//Ҫע�⵱��ֹһ�����ӿ���ʱ��Ҫȡ��������С����һ�� 
//round���� �������뺯�� 
using namespace std;
struct playerinfo{
	int hh,mm,ss;  //ʱ�� 
	int arrive;   //����ʱ������ 
	int p;     //�û�ʹ�����ӵ�ʱ��   
	int vip;  //�Ƿ���vip 
	int serving; //��ʼʹ�õ�ʱ�� 
};
struct tableinfo{ 
	int num;    //�д��������� 
	int end=8*3600;
	int vip;
}; 
vector<playerinfo> players;
vector<tableinfo> tables;
bool cmp1(playerinfo a,playerinfo b){
	return a.arrive<b.arrive;        //������ʱ������ 
}
bool cmp2(playerinfo a,playerinfo b){
	return a.serving<b.serving;
}
void serving(int i,int minj){               //�������������������һ���û����� 
	if(players[i].arrive>=tables[minj].end)     //���絽���Ǹ��˵�ʱ�Ѿ������ӿ����� 
		players[i].serving=players[i].arrive;
	else 
		players[i].serving=tables[minj].end;
	tables[minj].end=players[i].serving+players[i].p;  	
	tables[minj].num++;		
}
int findnextvip(int vipid){
	vipid++;
    while(vipid < players.size() && players[vipid].vip == 0) vipid++;
    return vipid;
}
int main()
{
	int k,m,n;
	scanf("%d",&n);   //n���û�   
	playerinfo tempinfo;    //�������� 
	for(int i=0;i<n;i++) {
		scanf("%d:%d:%d %d %d",&tempinfo.hh,&tempinfo.mm,&tempinfo.ss,&tempinfo.p,&tempinfo.vip);
		tempinfo.arrive=tempinfo.hh*3600+tempinfo.mm*60+tempinfo.ss;   //����ʱ��ת��������
		tempinfo.serving = 21 * 3600; 
		if(tempinfo.p>=120)   tempinfo.p=7200;    
		else tempinfo.p=tempinfo.p*60;               //ת�������� 
		if(tempinfo.arrive>=21*3600)  continue;     //����21���ŵ����� 
		players.push_back(tempinfo);               //�������� 
	}
	scanf("%d %d",&k,&m);     //k������ 
	int viptable;
	tables.resize(k+1);
	for(int i=0;i<m;i++){    //m��vip���� 
		scanf("%d",&viptable);
		tables[viptable].vip=1;
	}
	sort(players.begin(),players.end(),cmp1);   //�Ȱ��յ���ʱ��������� 
	int i=0,vipid=-1;
    vipid=findnextvip(vipid);
	while(i<players.size()){
		int minend=9999999,minj=-1,firstfree=-1;    //���������������Ӧ������ 
		for(int j=1;j<tables.size();j++){
			if(tables[j].end<minend){
				minend=tables[j].end;
				minj=j;
			}
		}
		for(int j=1;j<tables.size();j++){         //�ҵ���ǰ������������С����һ�� 
			if(players[i].arrive>tables[j].end){
			firstfree=j;
			break;
			}
		}
		if(firstfree!=-1)      //�������ҵĵ������û�����ʱ��������������������ˣ����������������ˣ���������űȵ�ǰ����ҪС 
		minj=firstfree;
		if(tables[minj].end >= 21*3600) break;  //�������ӵ��������ʱ�䶼����21���� 
		if(players[i].vip == 1 && i < vipid) {
 		i++;
 		continue;
		}
		if(tables[minj].vip==1){                           //��������vip����            
			if(players[i].vip==1){                        //����ǰ�û�Ҳ��vip 
				serving(i,minj);                         //����ǰ�û����� 
				if(vipid==i)  vipid=findnextvip(vipid);
				i++;
			}	
			else{                                       //����ǰ�û�����vip 
				if(vipid<players.size()&&players[vipid].arrive<=tables[minj].end){   //��һ��vip�û��ĵ���ʱ��С�ڵ�ǰ�����Ľ���ʱ�� 
				 	serving(vipid, minj);              //����Ϊδ����vip�û�����
					vipid=findnextvip(vipid);
				}
				else{
					serving(i,minj); 
					i++;
				}	
			}
		}
		else{             //����������vip���� 
			if(players[i].vip==0){   //���û�����vip
				serving(i,minj);
				i++; 
			}
			else{                     //���û���vip,����Ҫ����
				int minvipend=999999,minvip=-1; 
				for(int j=1;j<tables.size();j++){      //ɸѡ��������������vip���� 
					if(tables[j].end<minvipend&&tables[j].vip==1){
						minvipend=tables[j].end;
						minvip=j;
					}
				}
				if(minvip!=-1&&players[i].arrive>=tables[minvip].end){  //��������������vip����������vip�û� 
					serving(i,minvip);
					if(vipid == i) vipid=findnextvip(vipid);
					i++;
				} 
				else{                                                   //�����ܣ�������ͨ���Ӱ� 
					serving(i,minj);
					if(vipid == i) vipid=findnextvip(vipid);
					i++;
				}	
			}
		}
	} 
	sort(players.begin(), players.end(), cmp2);
	
	for(int i=0;i<players.size()&&players[i].serving<21*3600;i++) {
 	printf("%02d:%02d:%02d ", players[i].arrive/3600, players[i].arrive %
	3600/60, players[i].arrive%60);
 	printf("%02d:%02d:%02d ", players[i].serving/3600,players[i].serving%
	3600/60, players[i].serving % 60);
 	printf("%.0f\n",round((players[i].serving-players[i].arrive)/60.0));
 	}
 	for(int i = 1; i <= k; i++) {
 		if(i!= 1) printf(" ");
 		printf("%d", tables[i].num);
 	}
 return 0;
}
