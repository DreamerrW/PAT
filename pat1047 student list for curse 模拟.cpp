#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k;  //学生数和课程数 
vector<vector<string>> curse;
bool cmp(string a,string b){
	return a<b;
}
int main()
{
	scanf("%d %d",&n,&k);
	curse.resize(k+1);
	char s[4];
	int c;
	int temp;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		scanf("%d",&c);
		while(c--){
			scanf("%d",&temp);
			curse[temp].push_back(s);
		}
	}
	for(int i=1;i<=k;i++){
		sort(curse[i].begin(),curse[i].end(),cmp);
		printf("%d %d\n",i,curse[i].size());
		for(int j=0;j<curse[i].size();j++){
			printf("%s\n",curse[i][j].c_str());  //不能用cout会超时 
		}
	}
	return 0;
	
 } 
