#include<iostream>
#include<map>
#include<set>
using namespace std;
map<string,set<int>> ans;

int main()
{
	int n,k;   //学生总数与课程总数
	scanf("%d %d",&n,&k);
	
	char name[4];
	int curseid,students;
	for(int i=0;i<k;i++){                   //k门课程信息录入 
		scanf("%d %d",&curseid,&students);  //课程id和该课程学生人数 
		for(int j=0;j<students;j++){
			scanf("%s",name);
			ans[name].insert(curseid);      //由于是set，会默认排序，所以不用关心顺序了 
		} 
	}
	while(n>0){
		scanf("%s",name);
		printf("%s %d",name,ans[name].size());
		for(auto it=ans[name].begin();it!=ans[name].end();it++){
			printf(" %d",*it);
		}
		printf("\n");
		n--;
	}
	return 0;
 } 
