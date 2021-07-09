#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct studentinfo{
	string id; 
	int score, finalrank, location, localrank;
};
bool cmp(studentinfo a,studentinfo b){   //成绩从高到低排序 
	if(a.score!=b.score) return a.score>b.score;
	else return a.id<b.id;
}
int main()
{ 
	int N;   //N个测试位置点 
	int k;   //每个测试点k个学生
	vector<studentinfo> final;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&k);
		vector<studentinfo> v(k);   //每个测试点k个学生 
		for(int j=0;j<k;j++){
			cin>>v[j].id;            //学生 
			scanf("%d",&v[j].score); //成绩录入 
			v[j].location=i;         //考场信息录入 
		}
		sort(v.begin(),v.end(),cmp);
		v[0].localrank=1;
		final.push_back(v[0]);
		for(int j=1;j<k;j++){       //考场排名录入 
			if(v[j].score==v[j-1].score)
			v[j].localrank=v[j-1].localrank;
			else v[j].localrank=j+1;
			final.push_back(v[j]);
		}		
	}
	sort(final.begin(),final.end(),cmp);  
	final[0].finalrank=1; 
	for(int j=1;j<final.size();j++){   //所有学生排名录入 
		if(final[j].score==final[j-1].score)
		final[j].finalrank=final[j-1].finalrank;
		else final[j].finalrank=j+1;
	}
	int num=final.size();
	printf("%d\n",num);
	for(int i=0;i<final.size();i++){
		cout<<final[i].id;
		printf(" %d %d %d\n",final[i].finalrank,final[i].location,final[i].localrank); 
	}
	return 0;	
 } 
