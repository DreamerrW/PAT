#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

struct student{
	int id;
	int english;
	int math;
	int c;
	int average;
	int aa,cc,ee,mm;
}temp; 

int w=1;
int rank;

bool cmp(struct student a,struct student b)
{
    if(w==1)return a.average>b.average;   //w=1对平均分排序 
    else if(w==2)return a.c>b.c;		  //w=2对c语言排序 
    else if(w==3)return a.math>b.math;    //w=3对数学排序 
    else return a.english>b.english;      //w=4对英语排序 
}

void print(student a)
{
    char ch='A';
    int b=a.aa;
    if(b>a.cc)b=a.cc,ch='C';
    if(b>a.mm)b=a.mm,ch='M';
    if(b>a.ee)b=a.ee,ch='E';
    printf("%d %c\n",b,ch);
    // cout<<b<<" "<<ch<<endl;
}

int main()
{
	map<int,student> students;    //定义一个map映射，将学号和学生联系起来  即student[id] 
	vector<student> finalrank;    //定义一个可变学生资料数组 
	int n,m;                      //n个学生，m个待查询 
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&temp.id,&temp.c,&temp.math,&temp.english);
		temp.average=(temp.math+temp.c+temp.english);
		students[temp.id]=temp;
		finalrank.push_back(temp);
	}
	
	sort(finalrank.begin(),finalrank.end(),cmp);   
	for(int i=0;i<n;i++)     //对平均分进行排序 
	{
		if(i>0&&finalrank[i].average==finalrank[i-1].average) 
		students[finalrank[i].id].aa=students[finalrank[i-1].id].aa;
		else students[finalrank[i].id].aa=i+1;
	}
	w=2;
	sort(finalrank.begin(),finalrank.end(),cmp);
	for(int i=0;i<n;i++)     //对c语言进行排序 
	{
		if(i>0&&finalrank[i].c==finalrank[i-1].c) 	
		students[finalrank[i].id].cc=students[finalrank[i-1].id].cc;
		else students[finalrank[i].id].cc=i+1;
	}
	w=3;
	sort(finalrank.begin(),finalrank.end(),cmp);
	for(int i=0;i<n;i++)     //对数学进行排序 
	{
		if(i>0&&finalrank[i].math==finalrank[i-1].math)	
		students[finalrank[i].id].mm=students[finalrank[i-1].id].mm;
		else students[finalrank[i].id].mm=i+1;
	}
	w=4;
	sort(finalrank.begin(),finalrank.end(),cmp);
	for(int i=0;i<n;i++)   //对英语进行排序 
	{
		if(i>0&&finalrank[i].english==finalrank[i-1].english) 	
		students[finalrank[i].id].ee=students[finalrank[i-1].id].ee;
		else students[finalrank[i].id].ee=i+1;
	}

	 for(int i=0;i<m;i++)
    {
        int id;
        scanf("%d",&id);
        if(students.find(id)==students.end()) 
		printf("N/A\n");
        else
		print(students[id]);
    }
    return 0; 
} 
