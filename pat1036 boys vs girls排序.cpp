#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{    //�������Ա�ѧ�ţ��ɼ� 
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
	int n;  //n��ѧ��
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
	sort(Fstudent.begin(),Fstudent.end(),cmp1);   //Ů���ɼ��Ӹߵ��� 
	sort(Mstudent.begin(),Mstudent.end(),cmp2);   //�����ɼ��ӵ͵��� 
	if(Fnumber!=0)     //�����Ů���ɼ� 
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
