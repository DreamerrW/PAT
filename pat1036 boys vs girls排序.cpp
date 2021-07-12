#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{    //姓名，性别，学号，成绩 
	string name;
	char gender;
	string id;
	int grade;
};
vector<node> Fstudent;
vector<node> Mstudent;

bool cmp1(node a,node b){
	return a.grade>b.grade;
}
bool cmp2(node a,node b){
	return a.grade<b.grade;
}
int main()
{
	int n;  //n个学生
	scanf("%d",&n);
	node temp;
	for(int i=0;i<n;i++){
		cin>>temp.name>>temp.gender>>temp.id>>temp.grade;
		if(temp.gender=='F')
			Fstudent.push_back(temp);
		else 
			Mstudent.push_back(temp);
	}
	int Fnumber,Mnumber;
	Fnumber=Fstudent.size();
	Mnumber=Mstudent.size(); 
	sort(Fstudent.begin(),Fstudent.end(),cmp1);   //女生成绩从高到低 
	sort(Mstudent.begin(),Mstudent.end(),cmp2);   //男生成绩从低到高 
	if(Fnumber!=0)     //先输出女生成绩 
		cout<<Fstudent[0].name<<" "<<Fstudent[0].id<<endl;
	else 
		cout<<"Absent"<<endl;
	if(Mnumber!=0)
		cout<<Mstudent[0].name<<" "<<Mstudent[0].id<<endl;
	else 
		cout<<"Absent"<<endl;
	if(Fnumber==0||Mnumber==0)
		cout<<"NA"<<endl;
	else 
		cout<<Fstudent[0].grade-Mstudent[0].grade<<endl;
	return 0;
}
