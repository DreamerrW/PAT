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
		if(isalpha(s2[i]))            //�������ĸ,ȫ��ת�ɴ�д 
			s2[i]=toupper(s2[i]);          
		ans[s2[i]]=1;
	}
	for(int i=0;i<s1.length();i++){ 
		if(isalpha(s1[i]))           
			s1[i]=toupper(s1[i]);
		if(ans.find(s1[i])==ans.end()){ //û�ҵ� 
			if(ans1.find(s1[i])==ans1.end()){  //�������֮ǰû�б���⵽�� 
				cout<<s1[i];
				ans1.insert(s1[i]);
			}	
		}	
	}
	return 0;
 } 
