#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<char,int> ans;
set<char> ans1;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s2.length();i++){
		if(isalpha(s2[i]))            //如果是字母,全部转成大写 
			s2[i]=toupper(s2[i]);          
		ans[s2[i]]=1;
	}
	for(int i=0;i<s1.length();i++){ 
		if(isalpha(s1[i]))           
			s1[i]=toupper(s1[i]);
		if(ans.find(s1[i])==ans.end()){ //没找到 
			if(ans1.find(s1[i])==ans1.end()){  //这个坏键之前没有被检测到过 
				cout<<s1[i];
				ans1.insert(s1[i]);
			}	
		}	
	}
	return 0;
 } 
