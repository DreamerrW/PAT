#include<iostream>
#include<vector>
using namespace std;
struct node{
	string team;
	string password;
};
vector<node> ans;
vector<node> s;
int main()
{
	int n;
	int need=0;
	scanf("%d",&n);
	node temp1;
	for(int i=0;i<n;i++){
		cin>>temp1.team>>temp1.password;
		s.push_back(temp1);
	}
	int flag;
	for(int i=0;i<s.size();i++){
		flag=0;
		for(int j=0;j<s[i].password.size();j++){
			switch(s[i].password[j]){
				case'1': s[i].password[j]='@';flag=1;break;	
				case'0': s[i].password[j]='%';flag=1;break;
				case'l': s[i].password[j]='L';flag=1;break;
				case'O': s[i].password[j]='o';flag=1;break;
			}
		}
		if(flag==1){
			ans.push_back(s[i]);
		}	
	}
	need=ans.size();
	if(need!=0){
		printf("%d\n",need);
		for(int i=0;i<need;i++){
			cout<<ans[i].team<<" "<<ans[i].password<<endl;
		}
	}
	else if(n==1)
		printf("There is 1 accounts and no account is modified");
	else 
		printf("There are %d accounts and no account is modified",n);
	return 0;
 } 
