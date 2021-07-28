#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct info{
	int GE; //初始成绩 
	int GI; //面试成绩 
	int final;
	int rank;
	int id;
	vector<int> pref;  //志愿学校 
}; 
vector<info> stu; 
bool cmp1(info a,info b){
	if(a.final!=b.final) return a.final>b.final;
	else return a.GE>b.GE;
}
bool cmp2(info a,info b){
	return a.id<b.id;
}
int main()
{ 
	int n;               //总的申请人 0~n-1 编号 
	int m;              //学院数目   0~m-1
	int quota[101];       //每个学院的招生人数 
	int cnt[101]={0};    //每个学院已经招到的人数 
	int k;              //志愿数目   
	scanf("%d %d %d",&n,&m,&k);
	stu.resize(n);
	vector<info> ans[m];    //每个学院找到的学生id 
	for(int i=0;i<m;i++)  //每个学院的招生人数 
		scanf("%d",&quota[i]);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&stu[i].GE,&stu[i].GI);  //GE GI 
		stu[i].final=stu[i].GE+stu[i].GI;  //综合成绩 
		stu[i].id=i;                          //学生的id 
		stu[i].pref.resize(k);
		for(int j=0;j<k;j++) //志愿
			scanf("%d",&stu[i].pref[j]);  
	}
	sort(stu.begin(),stu.end(),cmp1);
	stu[0].rank=1;
	for(int i=1;i<n;i++){    //rank 排序 
		if(stu[i].final==stu[i-1].final&&stu[i].GE==stu[i-1].GE)
			stu[i].rank=stu[i-1].rank;
		else stu[i].rank=i+1;
	}
	
	for(int i=0;i<n;i++){      //录取环节 
		for(int j=0;j<k;j++){   //k个志愿 
			if(cnt[stu[i].pref[j]]<quota[stu[i].pref[j]]){  //如果录取人数没有超过 
				cnt[stu[i].pref[j]]++;
				ans[stu[i].pref[j]].push_back(stu[i]);break;
			}
			else if(cnt[stu[i].pref[j]]>=quota[stu[i].pref[j]]){  //如果录取人数超过了，考虑新的人的成绩和前面的是不是一样 
				int a=ans[stu[i].pref[j]].size()-1;
				if(stu[i].rank==ans[stu[i].pref[j]][a].rank){
					cnt[stu[i].pref[j]]++;
					ans[stu[i].pref[j]].push_back(stu[i]);break;
				}	
			}
		}
	}
	for(int i=0;i<m;i++){
		sort(ans[i].begin(),ans[i].end(),cmp2);   //录取的学生要按id号排序 
		for(int j=0;j<ans[i].size();j++){
			if(j!=0) printf(" "); 
			printf("%d",ans[i][j].id);
		}
		printf("\n");
	}
	return 0;
}  
