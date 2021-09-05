#include<iostream>
#include<algorithm>
using namespace std;
int a[10010];
int milk[10010];
bool vis[10010];
int main()
{
	fill(milk,milk+10010,200);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(i){
			if(a[i]>a[i-1]) milk[i]=max(milk[i-1]+100,milk[i]);
			else if(a[i]==a[i-1]) milk[i]=milk[i-1];
		}
		int j=i-1;
		while(j>=0&&a[j]>=a[j+1]){
			if(a[j]>a[j+1]) milk[j]=max(milk[j+1]+100,milk[j]);
			else milk[j]=milk[j+1];
			j--;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=milk[i];
	cout<<ans;
 } 
