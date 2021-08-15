#include<iostream>
#include<algorithm> 
#include<cctype> 
#include<vector>
#include<map>
using namespace std;
struct node{
	string school;
	double tws=0;
	int ns=0; // 
	int rank=0;  //排名 
};
map<string,node> mp;
vector<node> ans;
bool cmp(node a,node b){
	if((int)a.tws!=(int)b.tws) return a.tws>b.tws;
	else if(a.ns!=b.ns) return a.ns<b.ns;
	else return a.school<b.school;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t1,t2; 
		double score;
		cin>>t1>>score>>t2;
		for(int j=0;j<t2.length();j++) //转为小写 
			t2[j]=tolower(t2[j]);
		if(t1[0]=='A'){
			mp[t2].school=t2;
			mp[t2].tws+=score;
			mp[t2].ns++;
		}
		else if(t1[0]=='B'){
			mp[t2].school=t2;
			mp[t2].tws+=score/1.5;
			mp[t2].ns++;
		}
		else if(t1[0]=='T'){
			mp[t2].school=t2;
			mp[t2].tws+=score*1.5;
			mp[t2].ns++;
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++){
		node now=it->second;
		ans.push_back(now);
	}
	sort(ans.begin(),ans.end(),cmp);
	ans[0].rank=1;
	printf("%d\n",ans.size());
	printf("%d %s %d %d\n",ans[0].rank,ans[0].school.c_str(),(int)ans[0].tws,ans[0].ns);
	for(int i=1;i<ans.size();i++){
		if((int)ans[i].tws==(int)ans[i-1].tws) 
			ans[i].rank=ans[i-1].rank;
		else ans[i].rank=i+1;
		printf("%d %s %d %d\n",ans[i].rank,ans[i].school.c_str(),(int)ans[i].tws,ans[i].ns);
	}
	return 0;
}
