#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();   //吸收cin的结束符 
	string ans;

	for(int i=0;i<n;i++){
		string t;
		getline(cin,t);
		reverse(t.begin(),t.end());
		if(i==0){  //第一个字符串 
			ans=t;
			continue; 
		}
		else{
			for(int j=0;j<min(ans.length(),t.length());j++){
				if(ans[j]!=t[j]){
					ans=ans.substr(0,j);
					break;
				}
			}
		}
	}
	reverse(ans.begin(),ans.end());  //逆序输出 
	if(ans.length()!=0)
		cout<<ans;
	else 
		cout<<"nai";
	return 0; 
 } 
