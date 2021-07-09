#include<iostream>
#include<algorithm>  //包含reserve函数 
#include<string> 
using namespace std;
string add(string s1,string s2){
	string ans;
	char c;
	int len=s1.length();
	int flag=0,temp;
	for(int i=len-1;i>=0;i--){
		temp=(s1[i]-'0')+(s2[i]-'0')+flag;
		if(temp>=10){
			temp-=10;
			flag=1;
		}
		else flag=0;
		c=temp+'0';
		ans=c+ans;
	}
	if(flag)  ans='1'+ans;
	return ans;
}
int main()
{
	string s;
	int k;           //所能允许反转相加的次数 
	int i;
	cin>>s>>k;
	for(i=0;i<=k;i++){
		string t=s;
		reverse(t.begin(),t.end());  //t为s的反转
		if(s==t||i==k)  break;
		else s=add(s,t);	 
	}
	cout<<s<<"\n"<<i;
	return 0;	
}
