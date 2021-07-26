#include<iostream>
#include<map>
#include<cctype>
//isalnum 函数用来识别是否是数字、字母  isalpha用来识别是否是字母 isdigit用来识别是否是数字 tolower用来将大写变为小写 
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	map<string,int> ans;
	string t;
	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){
			s[i]=tolower(s[i]);
			t+=s[i];
		}
		if(!isalnum(s[i])||i==s.length()-1){
			if(t.length()!=0) ans[t]++;
			t="";  //t重新为空 
		}
	}
	int maxn=0;
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it->second>maxn) {
			t=it->first;
			maxn=it->second;
		}
	} 
	cout<<t<<" "<<maxn;
	return 0;
 } 
