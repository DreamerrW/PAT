#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	string name; //姓名 
	int height; //身高 
};
vector<node> v(10010);
bool cmp(node a,node b){
	if(a.height!=b.height) return a.height>b.height;
	else return a.name<b.name;
}
int main()
{
	int n,k; //n个人，k行
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
		cin>>v[i].name>>v[i].height;
	int m=n/k;
	int m1=n-n/k*(k-1); //最后一行站的人
	sort(v.begin(),v.end(),cmp); 
	
	int t=0;
	for(int i=k;i>0;i--){   //从第k行开始搞
		vector<string> ans(max(m1,m));
		if(i==k){
			int first=m1/2;
			int t1=1,t2=1;
			for(int j=0;j<m1;j++){  //最后一行要输出m1个人 
				if(j==0) ans[first]=v[t++].name;
				else if(j%2==1){  //站在右边的 
					ans[first-t1]=v[t++].name;
					t1++;
				}
				else if(j%2==0){
					ans[first+t2]=v[t++].name;
					t2++;	
				}
			}
		}
		else{
			int first=m/2;
			int t1=1,t2=1;
			for(int j=0;j<m;j++){
				if(j==0) ans[first]=v[t++].name;
				else if(j%2==1){
					ans[first-t1]=v[t++].name;	
					t1++;
				}
				else if(j%2==0){
					ans[first+t2]=v[t++].name;
					t2++;	
				}
			}
		}
		int	len=(i==k?m1:m);
		for(int j=0;j<len;j++){
			if(j!=0) printf(" ");
				cout<<ans[j];
		}
		printf("\n");
	}
	return 0;
} 
