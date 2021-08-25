#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int in;
	int out;
};
bool cmp(node a,node b){
	return a.out<b.out;
}
int main()
{
	int n;
	cin>>n;
	vector<node> v(n);
	for(int i=0;i<n;i++){
		int hh,mm,ss;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int hh1,mm1,ss1;
		scanf("%d:%d:%d",&hh1,&mm1,&ss1);
		v[i].in=hh*60*60+mm*60+ss;
		v[i].out=hh1*60*60+mm1*60+ss1;
	}
	sort(v.begin(),v.end(),cmp);
	int cnt=1;
	int num=0;
	for(int i=1;i<n;i++){
		if(v[i].in>=v[num].out){
			cnt++;
			num=i;
		}
	}
	printf("%d",cnt);
	return 0;
 } 
