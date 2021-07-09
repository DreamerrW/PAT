#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
//每次取出最快的那一张桌子，若是vip桌子，则考虑用户是不是vip用户，若是，则直接使用，若不是，则考虑下个vip用户来这里能不能等的到 
//若不是vip桌子，则考虑是不是vip用户 ，若是，则考虑最早结束的那张vip桌能不能为它服务，若不是，则直接服务
//要注意当不止一张桌子空闲时，要取出桌号最小的那一张 
//round函数 四舍五入函数 
using namespace std;
struct playerinfo{
	int hh,mm,ss;  //时间 
	int arrive;   //到达时间秒数 
	int p;     //用户使用桌子的时间   
	int vip;  //是否是vip 
	int serving; //开始使用的时间 
};
struct tableinfo{ 
	int num;    //招待过的人数 
	int end=8*3600;
	int vip;
}; 
vector<playerinfo> players;
vector<tableinfo> tables;
bool cmp1(playerinfo a,playerinfo b){
	return a.arrive<b.arrive;        //按到达时间排序 
}
bool cmp2(playerinfo a,playerinfo b){
	return a.serving<b.serving;
}
void serving(int i,int minj){               //最早结束的那桌来给下一个用户服务 
	if(players[i].arrive>=tables[minj].end)     //最早到的那个人到时已经有桌子空闲了 
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
	scanf("%d",&n);   //n对用户   
	playerinfo tempinfo;    //缓冲数据 
	for(int i=0;i<n;i++) {
		scanf("%d:%d:%d %d %d",&tempinfo.hh,&tempinfo.mm,&tempinfo.ss,&tempinfo.p,&tempinfo.vip);
		tempinfo.arrive=tempinfo.hh*3600+tempinfo.mm*60+tempinfo.ss;   //到达时间转换成秒数
		tempinfo.serving = 21 * 3600; 
		if(tempinfo.p>=120)   tempinfo.p=7200;    
		else tempinfo.p=tempinfo.p*60;               //转换成秒数 
		if(tempinfo.arrive>=21*3600)  continue;     //若在21点后才到，埋丢 
		players.push_back(tempinfo);               //存入数据 
	}
	scanf("%d %d",&k,&m);     //k张桌子 
	int viptable;
	tables.resize(k+1);
	for(int i=0;i<m;i++){    //m张vip桌子 
		scanf("%d",&viptable);
		tables[viptable].vip=1;
	}
	sort(players.begin(),players.end(),cmp1);   //先按照到达时间进行排序 
	int i=0,vipid=-1;
    vipid=findnextvip(vipid);
	while(i<players.size()){
		int minend=9999999,minj=-1,firstfree=-1;    //最早结束的那桌对应的桌号 
		for(int j=1;j<tables.size();j++){
			if(tables[j].end<minend){
				minend=tables[j].end;
				minj=j;
			}
		}
		for(int j=1;j<tables.size();j++){         //找到当前空闲且桌号最小的那一张 
			if(players[i].arrive>tables[j].end){
			firstfree=j;
			break;
			}
		}
		if(firstfree!=-1)      //假若能找的到，即用户来到时除了最早结束那桌结束了，还有其他桌结束了，且这桌序号比当前这桌要小 
		minj=firstfree;
		if(tables[minj].end >= 21*3600) break;  //所有桌子的最早结束时间都大于21点了 
		if(players[i].vip == 1 && i < vipid) {
 		i++;
 		continue;
		}
		if(tables[minj].vip==1){                           //若该桌是vip桌子            
			if(players[i].vip==1){                        //若当前用户也是vip 
				serving(i,minj);                         //给当前用户服务 
				if(vipid==i)  vipid=findnextvip(vipid);
				i++;
			}	
			else{                                       //若当前用户不是vip 
				if(vipid<players.size()&&players[vipid].arrive<=tables[minj].end){   //下一个vip用户的到达时间小于当前这桌的结束时间 
				 	serving(vipid, minj);              //这桌为未来的vip用户服务；
					vipid=findnextvip(vipid);
				}
				else{
					serving(i,minj); 
					i++;
				}	
			}
		}
		else{             //若该桌不是vip桌子 
			if(players[i].vip==0){   //若用户不是vip
				serving(i,minj);
				i++; 
			}
			else{                     //若用户是vip,则需要考虑
				int minvipend=999999,minvip=-1; 
				for(int j=1;j<tables.size();j++){      //筛选出最快结束的那张vip桌子 
					if(tables[j].end<minvipend&&tables[j].vip==1){
						minvipend=tables[j].end;
						minvip=j;
					}
				}
				if(minvip!=-1&&players[i].arrive>=tables[minvip].end){  //若最快结束的那张vip桌子能满足vip用户 
					serving(i,minvip);
					if(vipid == i) vipid=findnextvip(vipid);
					i++;
				} 
				else{                                                   //若不能，就用普通桌子吧 
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
