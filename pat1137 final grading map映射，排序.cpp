#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
	string id;
	int Gp,Gm,Gf,G;
};
map<string,int> gp;
map<string,int> gm;
map<string,int> gf;
bool cmp(node a,node b){
	if(a.G!=b.G) return a.G>b.G;
	else return a.id<b.id;
}
int main()
{
	int p,m,n;   //p是学生数目，m是中期成绩，n是final成绩
	vector<node> ans;
	scanf("%d %d %d",&p,&m,&n);
	int tgrade;
	string name;
	for(int i=0;i<p;i++){ //在线成绩 
		cin>>name>>tgrade;
		gp[name]=tgrade;
	}
	for(int i=0;i<m;i++){  //期中成绩 
		cin>>name>>tgrade;
		gm[name]=tgrade;
	}
	for(int i=0;i<n;i++){
		cin>>name>>tgrade;
		gf[name]=tgrade;
	} 
	for(auto it=gp.begin();it!=gp.end();it++){
		if(it->second>=200){  //改名学生的在线成绩大于200 
			if(gf.find(it->first)!=gf.end()){ //有期末成绩 如果没有期末成绩 就算期中100 总成绩也到不了60的 
				node temp;
				temp.id=it->first;
				temp.Gp=it->second;
				temp.Gf=gf[it->first]; 
				if(gm.find(it->first)!=gm.end())
					temp.Gm=gm[it->first];
				else 
					temp.Gm=-1;
				if(temp.Gm<temp.Gf) temp.G=temp.Gf;
				else temp.G=round(temp.Gm*0.4+temp.Gf*0.6);
				ans.push_back(temp);
			}
		} 
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		if(ans[i].G>=60) 
			printf("%s %d %d %d %d\n",ans[i].id.c_str(),ans[i].Gp,ans[i].Gm,ans[i].Gf,ans[i].G);
		else break;
	}
	return 0;
 } 
