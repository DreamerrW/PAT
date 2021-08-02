#include<iostream>
#include<cctype>
#include<map>
using namespace std;
map<char,int> ans1;
map<char,int> ans2;
int main()
{	
	int cnt=0;
	string s1,s2;
	cin>>s1;
	cin>>s2;
	for(int i=0;i<s1.size();i++){
		if(ans1.find(s1[i])==ans1.end())
		ans1[s1[i]]=1;
		else 
		ans1[s1[i]]++;
	}
	for(int i=0;i<s2.size();i++){
		if(ans1.find(s2[i])!=ans1.end()){
			if(ans1[s2[i]]!=0){
				ans1[s2[i]]--;
			}
			else cnt++;
		}
		else cnt++;
	}
	if(cnt!=0){
		printf("No %d",cnt);
	}
	else 
		printf("Yes %d",s1.size()-s2.size());
	return 0;
} 
