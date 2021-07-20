#include<iostream> 
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int book[201];
struct node{
	char name[10];
	int age;
	int money;
};
bool cmp(node a,node b){
	if(a.money!=b.money)
	return a.money>b.money;
	else if(a.age!=b.age)
	return a.age<b.age;
	else 
	return (strcmp(a.name,b.name)<0);
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector<node> v(n);
	vector<node> ans;
	for(int i=0;i<n;i++)
		scanf("%s %d %d",v[i].name,&v[i].age,&v[i].money);
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++){
		if(book[v[i].age]<100)    //每个年龄只取最富有的100个人防止超时 
		ans.push_back(v[i]);
		book[v[i].age]++;
	}
	int m,amin,amax;
	int count;
	for(int i=0;i<k;i++){
		scanf("%d %d %d",&m,&amin,&amax);
		printf("Case #%d:\n",i+1);
		count=0;
		for(int j=0;j<ans.size();j++){
			if(ans[j].age>=amin&&ans[j].age<=amax){   //若年龄在范围内就输出 
				count++;
				printf("%s %d %d\n",ans[j].name,ans[j].age,ans[j].money);		
			}
			if(count==m) break;
		}
		if(count==0)  printf("None\n");   //如果没有输出过人 
	}
	return 0;
}
