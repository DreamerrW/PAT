#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std; 
struct node{
	int id;
	int rank;
	int passnum=0;
	int total=0;
	vector<int> score;  //每道题的成绩
	bool ispass=false;  //是否有一题通过了编译器 
}; 
bool cmp(node a,node b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.passnum!=b.passnum) return a.passnum>b.passnum;
	else return a.id<b.id;
}
int main()
{
	int n,k;  //用户数目，和问题数目   
	//学生id 00001~n  问题序号 1~k 
	int m;  //提交数
	scanf("%d %d %d",&n,&k,&m);
	vector<node> student(n+1);
	vector<int> p(k+1);
	for(int i=1;i<=k;i++)
		scanf("%d",&p[i]);  //每一门课的满分 
	
	for(int i=1;i<=n;i++)
		student[i].score.resize(k+1,-2); //每门课的初始成绩赋为-2 表示没有提交过 
		
	int tempid,numid,score;  //学号，问题号，成绩 
	for(int i=0;i<m;i++){  //m条记录 
		scanf("%d %d %d",&tempid,&numid,&score);
		student[tempid].id=tempid;
		student[tempid].score[numid]=max(student[tempid].score[numid],score);
		if(score!=-1) student[tempid].ispass=true;  //表明提交通过了，能输出 
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(student[i].score[j]!=-1&&student[i].score[j]!=-2) 
				student[i].total+=student[i].score[j];
			if(student[i].score[j]==p[j])   //满分了
				student[i].passnum++;    
		}
	} 
	sort(student.begin()+1,student.end(),cmp);
	for(int i=1;i<=n;i++){
		student[i].rank=i;
		if(student[i].total==student[i-1].total&&i!=1)
			student[i].rank=student[i-1].rank;
	}
	for(int i=1;i<=n;i++){
		if(student[i].ispass==true){               //没通过编译器或者没提交过的就不计入 
			printf("%d %05d %d",student[i].rank,student[i].id,student[i].total);
			for(int j=1;j<=k;j++){
				if(student[i].score[j]!=-1&&student[i].score[j]!=-2)
					printf(" %d",student[i].score[j]);
				else if(student[i].score[j]==-2)    //若是没有提交过就是 "-" 
					printf(" -");
				else 	
					printf(" 0");
			} 
			printf("\n");
		}
	}
	return 0;
 } 
