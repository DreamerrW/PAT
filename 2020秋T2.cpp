#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
	int n,m;
	cin>>n>>m;
	v.resize(n);
	int ans=0;
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++){
		if(v[i]<=m) ans++;
		else continue;
		int all=v[i];
		for(int j=i+1;j<n;j++){
			all+=v[j];
			if(all<=m) ans++;
			else break;
		}
	}
	cout<<ans;
}
