#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	char level;
	string site;
	string date;
	string id;
	int score;
	string card;
};
struct info{
	int site;
	int time=0;
};
bool cmp(node a,node b){
	if(a.score!=b.score) return a.score>b.score;
	else return a.card<b.card;
}
bool cmp1(info a,info b){
	if(a.time!=b.time) return a.time>b.time;
	else return a.site<b.site;
}
vector<node> v;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		int score;
		cin>>s>>score;
		node now;
		now.card=s;
		now.level=s[0];
		now.site=s.substr(1,3);
		now.date=s.substr(4,6);
		now.id=s.substr(10,3);
		now.score=score;
		v.push_back(now);
	}
	for(int i=1;i<=m;i++){
		int type;
		string term;
		cin>>type>>term;
		printf("Case %d: %d %s\n",i,type,term.c_str());
		vector<node> ans;
		if(type==1){ //输出相同考试等级的成绩 
			for(int j=0;j<v.size();j++){
				if(v[j].level==term[0])
					ans.push_back(v[j]);
			}
			sort(ans.begin(),ans.end(),cmp);
			if(ans.size()==0) printf("NA\n");
			for(int j=0;j<ans.size();j++)
				printf("%s %d\n",ans[j].card.c_str(),ans[j].score);
		}
		else if(type==2){ //输出相同座位号的和成绩 
			int cnt=0,total=0;
			for(int j=0;j<v.size();j++){
				if(v[j].site==term){
					cnt++;
					total+=v[j].score;
				}
			}
			if(cnt==0) printf("NA\n");
			else printf("%d %d\n",cnt,total);
		}
		else if(type==3){ //输出相同考试年月日的成绩 
			vector<info> ans1(1001);
			int cnt=0;
			for(int j=0;j<v.size();j++){
				if(v[j].date==term){
					int num=stoi(v[j].site);
					ans1[num].site=num;
					ans1[num].time++;
					if(ans1[num].time==1) cnt++;
				}
			}
			sort(ans1.begin(),ans1.end(),cmp1);
			if(cnt==0) printf("NA\n");
			for(int j=0;j<cnt;j++)
				printf("%d %d\n",ans1[j].site,ans1[j].time);
		}
	}
	return 0;
}
