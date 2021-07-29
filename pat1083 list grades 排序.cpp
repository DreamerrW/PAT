#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	char name[11];
	char id[11];
	int grade;
};
bool cmp(node a,node b){
	return a.grade>b.grade;
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<node> stu(n); 
	for(int i=0;i<n;i++)
		scanf("%s %s %d",stu[i].name,stu[i].id,&stu[i].grade);
	int low,high;
	scanf("%d %d",&low,&high);
	
	sort(stu.begin(),stu.end(),cmp);
	int cnt=0;
	for(int i=0;i<stu.size();i++){
		if(stu[i].grade<=high&&stu[i].grade>=low){
			printf("%s %s\n",stu[i].name,stu[i].id);
			cnt=1;
		}
	}
	if(cnt==0) printf("NONE");
	return 0;
 } 
