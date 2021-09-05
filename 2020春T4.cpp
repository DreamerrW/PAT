#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<vector> 
using namespace std;
vector<vector<int>> runs(1000);
vector<int> a;
multiset<int> t;
multiset<int> temp;
int main()
{
	int n,m;
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)  //先把前m个数输入 
		t.insert(a[i]);
		
	int num=0;
	int now=0; 
	for(int i=m;i<n;i++){
		auto it=t.begin();
		runs[num].push_back(*it); 
		if(a[i]<*it) {
			now++;
			temp.insert(a[i]);
			t.erase(*it);
			if(now==m){
				t=temp;
				temp.clear();
				num++;
				now=0;	
			}	
		}
		else{
			t.erase(it);
			t.insert(a[i]);			
		}
	}
	for(auto it:t)
		runs[num].push_back(it);
	for(auto it1:temp)
		runs[num+1].push_back(it1);
	if(now!=0) num++;
	
	for(int i=0;i<=num;i++){
		for(int j=0;j<runs[i].size();j++){
			if(j!=0) printf(" ");
			printf("%d",runs[i][j]);
		}
		printf("\n");
	}
	return 0;
}
