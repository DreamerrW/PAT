#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int maxn=110; 
int n,m,k; //n个反应物，m个产物，k个方程式
//是否使用过 
bool vis[maxn]={false};  //反应物
//产物，原料 
vector<int> pro;
bool react[maxn];
unordered_map<int, vector<vector<int>>> mp;
bool ok=false;
vector<int> tmp;
vector<int> ans;
void dfs(int index){
	if(ok) return ;
	if(index==m){
		ans=tmp;
		ok=true;
		return;
	}
	int x=pro[index];  //要生成的第 index号产物 
	for(int i=0;i<mp[x].size();i++){
		tmp.push_back(i);
		bool fla g=true;
		int j=0;
		for(;j<mp[x][i].size();j++){
			if(vis[mp[x][i][j]]==true) {
				flag=false;
				break;  
			}
			vis[mp[x][i][j]]=true;
		}
		if(!flag){
			for(int u=0;u<j;u++)
				vis[mp[x][i][u]]=false;
			tmp.pop_back();
			continue;
		}
		dfs(index+1);
		for(j=0;j<mp[x][i].size();j++)
            vis[mp[x][i][j]] = false;
        tmp.pop_back();
	}
} 
int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		react[x]=true;  //映射，表示x是反应物 
	}
	cin>>m;
	pro.resize(m);
	for(int i=0;i<m;i++){
		cin>>pro[i];
		if(react[pro[i]]==false) continue;
		vector<int> t={pro[i]};
		mp[pro[i]].push_back(t);
	}
	cin>>k;
	while(k--){
		vector<int> temp;
		string s;
		bool ok=true;
		while(1){
			cin>>s;
			if(s=="->") break;
			if(isdigit(s[0])){
				int t=stoi(s);
				if(react[t]==false) ok=false; //如果这个不是反应物
				temp.push_back(t); 
			}
		}
		int t;
		cin>>t;
		if(ok) mp[t].push_back(temp);
	}
	for(auto a:pro){
		sort(mp[a].begin(),mp[a].end());   //按字典序排序 
	}
	dfs(0);  //从第一个反应物开始 
	
	for(int i=0;i<m;i++){
		int t=ans[i];
		bool first=true;
		auto v=mp[pro[i]][t];
		for(auto a:v){
			if(first) first=false;
			else printf(" + ");
			printf("%02d",a);
		}
		printf(" -> %02d\n",pro[i]);
	}
	return 0;
 } 
