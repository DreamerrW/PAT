#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std; 
struct node{
	int id;
	int rank;
	int passnum=0;
	int total=0;
	vector<int> score;  //ÿ����ĳɼ�
	bool ispass=false;  //�Ƿ���һ��ͨ���˱����� 
}; 
bool cmp(node a,node b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.passnum!=b.passnum) return a.passnum>b.passnum;
	else return a.id<b.id;
}
int main()
{
	int n,k;  //�û���Ŀ����������Ŀ   
	//ѧ��id 00001~n  ������� 1~k 
	int m;  //�ύ��
	scanf("%d %d %d",&n,&k,&m);
	vector<node> student(n+1);
	vector<int> p(k+1);
	for(int i=1;i<=k;i++)
		scanf("%d",&p[i]);  //ÿһ�ſε����� 
	
	for(int i=1;i<=n;i++)
		student[i].score.resize(k+1,-2); //ÿ�ſεĳ�ʼ�ɼ���Ϊ-2 ��ʾû���ύ�� 
		
	int tempid,numid,score;  //ѧ�ţ�����ţ��ɼ� 
	for(int i=0;i<m;i++){  //m����¼ 
		scanf("%d %d %d",&tempid,&numid,&score);
		student[tempid].id=tempid;
		student[tempid].score[numid]=max(student[tempid].score[numid],score);
		if(score!=-1) student[tempid].ispass=true;  //�����ύͨ���ˣ������ 
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(student[i].score[j]!=-1&&student[i].score[j]!=-2) 
				student[i].total+=student[i].score[j];
			if(student[i].score[j]==p[j])   //������
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
		if(student[i].ispass==true){               //ûͨ������������û�ύ���ľͲ����� 
			printf("%d %05d %d",student[i].rank,student[i].id,student[i].total);
			for(int j=1;j<=k;j++){
				if(student[i].score[j]!=-1&&student[i].score[j]!=-2)
					printf(" %d",student[i].score[j]);
				else if(student[i].score[j]==-2)    //����û���ύ������ "-" 
					printf(" -");
				else 	
					printf(" 0");
			} 
			printf("\n");
		}
	}
	return 0;
 } 
