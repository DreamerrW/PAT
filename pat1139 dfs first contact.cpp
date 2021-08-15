#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define inf 99999
using namespace std;
struct node{
	int s1,s2;
};
int e[310][310]={0};
int sign[310];
bool vis[310];
int n,m;
map<string,int> mp;
map<int,string> mp1;
vector<int> tans;
vector<node> ans;
int a,b;
bool cmp(node a,node b){
	if(a.s1!=b.s1) return a.s1<b.s1;
	else return a.s2<b.s2;
}
void dfs(int v){
	if(v==b){  //dfs到达终点 
		tans.push_back(v);
		if(tans.size()==4){   //size为4 
			if(sign[tans[1]]==sign[a]&&sign[tans[2]]==sign[b]){
			node now;
			now.s1=abs(stoi(mp1[tans[1]]));
			now.s2=abs(stoi(mp1[tans[2]]));
			ans.push_back(now);
			}
		}
		tans.pop_back();
		return ;
	} 
	tans.push_back(v);
	vis[v]=true;
	for(int i=0;i<n;i++){
		if(vis[i]==false&&e[v][i]!=inf)
			dfs(i);
	}
	vis[v]=false;
	tans.pop_back();
}
int main()
{
	fill(e[0],e[0]+310*310,inf);
	int person=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(mp.find(t1)==mp.end()){   //没找到 
			mp[t1]=person;
			mp1[person]=t1;
			if(t1[0]=='-') sign[person]=1;
			person++;
		}
		if(mp.find(t2)==mp.end()){   //没找到 
			mp[t2]=person;
			mp1[person]=t2;	
			if(t2[0]=='-') sign[person]=1; //符号位 
			person++;
		}
		e[mp[t1]][mp[t2]]=1;
		e[mp[t2]][mp[t1]]=1;
	}
	int k;
	scanf("%d",&k);
	string A,B;
	while(k--){
		cin>>A>>B;
		ans.clear();
		tans.clear();
		fill(vis,vis+310,false);
		a=mp[A];
		b=mp[B];
		dfs(a);
		sort(ans.begin(),ans.end(),cmp);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%04d %04d\n",ans[i].s1,ans[i].s2);
	}
	return 0;
}
