#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
//考察sort函数的应用 
using namespace std;
struct student{
	int id;
	string name;
	int grade;
};
vector<student> students; 
int flag;
bool cmp(student a,student b)
{
	if(flag==1){
		return a.id<b.id;
	}
	else if(flag==2){
		return a.name==b.name?a.id<b.id:a.name<b.name;
	}
	else if(flag==3)
	{
		return a.grade==b.grade?a.id<b.id:a.grade<b.grade;
	}
}
int main()
{
	int c;
	scanf("%d %d",&c,&flag);
	student temp;
	for(int i=0;i<c;i++){
		scanf("%d",&temp.id);
		cin>>temp.name;
		scanf("%d",&temp.grade);
		students.push_back(temp);
	}	
	sort(students.begin(),students.end(),cmp);
	for(int i=0;i<students.size();i++){
		printf("%06d ",students[i].id);
		cout<<students[i].name;
		printf(" %d\n",students[i].grade);
	}
	return 0;
	
 } 
