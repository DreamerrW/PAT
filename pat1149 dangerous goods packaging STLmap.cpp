#include<iostream>
#include<vector>
#include<map> 
using namespace std;
int main()
{
	int n; //n�Բ����ݵĻ���
	int m; //m���嵥 
	cin>>n>>m;
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	} 
	while(m--){
		int k;
		int flag=0;
		cin>>k;
		int a[100000]={0};
		vector<int> temp(k);
		for(int i=0;i<k;i++){
			cin>>temp[i];	
			a[temp[i]]=1; 
		}
		for(int i=0;i<k;i++){	
			if(flag) break;
			for(int l=0;l<mp[temp[i]].size();l++){
				if(a[mp[temp[i]][l]]==1){     //�г�ͻ 
					flag=1;
					break;
				}
			}
		}
		if(flag) cout<<"No\n";
		else cout<<"Yes\n";
	}
 } 
