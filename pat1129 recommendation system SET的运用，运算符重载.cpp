#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int cnt;
};
bool cmp(node a,node b){
	if(a.cnt!=b.cnt) return a.cnt>b.cnt;
	else return a.id<b.id;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k); //n是查询队列 k是最大推荐数目
	//项目1~N 
	vector<node> a(n);
	vector<node> b(n);
//	set<int> ans;
	for(int i=0;i<n;i++){
		a[i].id=i+1;    //id从1~N 
		a[i].cnt=0;
	}
	int t;
	scanf("%d",&t);
	a[t-1].cnt++;  
	b=a;
	for(int i=0;i<n-1;i++){  //剩下n-1 次 
		scanf("%d",&t);
		b[t-1].cnt++;
		sort(a.begin(),a.end(),cmp);
		printf("%d:",t);
		for(int j=0;j<k;j++){
			if(a[j].cnt!=0)
				printf(" %d",a[j].id);
		}
		printf("\n");
		a=b;
	}
	return 0;
}
