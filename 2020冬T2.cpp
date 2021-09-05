#include<iostream>
using namespace std;
int main()
{
	string s,p;  //找到s中最短的字串 包含p 
	cin>>s>>p;
	string temp;
	string ans;
	int now;
	for(int i=0;i<s.length();i++){
		now=0;
		temp.clear();
		if(s[i]==p[now]){
			for(int j=i;j<s.length();j++){
			if(s[j]==p[now]){
				temp+=s[j];
				if(now==p.size()-1){
					if(ans.size()==0||temp.size()<ans.size())
						ans=temp;
					continue;
				}
				now++;
			}
			else
				temp+=s[j];	
			}
		}
	}
	cout<<ans;
	return 0;
}
