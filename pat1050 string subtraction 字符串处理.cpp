#include<iostream>
#include<map>
using namespace std;
map<char,int> mp;     //将出现过的字符记录下来 
string s1;
string s2;
int main()
{
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.size();i++){
		mp[s2[i]]=1;
	}
	string ans;
	for(int i=0;i<s1.size();i++){
		if(mp.find(s1[i])==mp.end()){
			ans+=s1[i];
		}
	}
	cout<<ans;
	return 0;
 } 
