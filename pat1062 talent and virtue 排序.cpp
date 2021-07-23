#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int virtue_grade;
	int talent_grade;
	int total_grade;
};
vector<node> sage;  //ʥ��  tanlent>H virtue>H 
vector<node> nobleman; //����  tanlent<H virtue>H 
vector<node> fool;		//���� tanlent<H virtue<H 
vector<node> small;  //С�� tanlent>H virtue<H 
bool cmp1(node a,node b){  //�������ܳɼ�����virtue����id��˳�� 
	if(a.total_grade!=b.total_grade) return a.total_grade>b.total_grade;
	else if(a.virtue_grade!=b.virtue_grade) return a.virtue_grade>b.virtue_grade;
	else return a.id<b.id;
}
int main()
{
	int N,L,H;
	scanf("%d %d %d",&N,&L,&H);
	node temp;                  //����ʱ�Ļ���ṹ 
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&temp.id,&temp.virtue_grade,&temp.talent_grade);
		temp.total_grade=temp.virtue_grade+temp.talent_grade;
		if(temp.talent_grade<L||temp.virtue_grade<L)   //���ڵ�����
			continue; 
		if(temp.talent_grade>=H&&temp.virtue_grade>=H) //ʥ�� 
			sage.push_back(temp); 
		else if(temp.talent_grade<H&&temp.virtue_grade>=H) //���� 
			nobleman.push_back(temp);
		else if(temp.talent_grade<H&&temp.virtue_grade<H&&temp.virtue_grade>=temp.talent_grade)  //����
			fool.push_back(temp);
		else 
			small.push_back(temp);
	}
	sort(sage.begin(),sage.end(),cmp1);
	sort(nobleman.begin(),nobleman.end(),cmp1);
	sort(fool.begin(),fool.end(),cmp1);
	sort(small.begin(),small.end(),cmp1);
	int m=sage.size()+nobleman.size()+fool.size()+small.size();  //ȫ������������ 
	printf("%d\n",m);
	for(int i=0;i<sage.size();i++)
		printf("%d %d %d\n",sage[i].id,sage[i].virtue_grade,sage[i].talent_grade);
	for(int i=0;i<nobleman.size();i++)
		printf("%d %d %d\n",nobleman[i].id,nobleman[i].virtue_grade,nobleman[i].talent_grade);
	for(int i=0;i<fool.size();i++)
		printf("%d %d %d\n",fool[i].id,fool[i].virtue_grade,fool[i].talent_grade);
	for(int i=0;i<small.size();i++)
		printf("%d %d %d\n",small[i].id,small[i].virtue_grade,small[i].talent_grade);
	
	return 0; 
 } 
