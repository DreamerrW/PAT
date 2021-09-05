#include<iostream>
#include<vector>
using namespace std;
struct node{
	int id;
	int pre;
}a[10001];
vector<int> b[1000];
int main()
{
	int n;
	cin>>n;
	getchar();
	string s;
	for(int i=0;i<n;i++){
		getline(cin,s);
		int d=0;
		int index;
		for(int j=0;j<s.length();j++){
			if(s[j]==' ')
				d++;       //记录距离 
		}
		index=stoi(s);      //编号 
		a[index].id=index;
		b[d].push_back(index);  //这个深度的编号 
		
		if(d!=0){
			int v=d-1;
			int end=b[v].size()-1;
			a[index].pre=b[v][end];
		}
	}
	int k;
	cin>>k;
	while(k--){
		int q;
		cin>>q;
		if(a[q].id==0&&q!=0){
			printf("Error: %04d is not found.\n",q);
			continue;
		}
		vector<int> ans;
		while(q!=0){
			ans.push_back(q);
			q=a[q].pre;
		}
		printf("0000");
		for(int i=ans.size()-1;i>=0;i--)
			printf("->%04d",ans[i]);
		printf("\n");
	}
	return 0;
}
