#include<iostream>
#include<algorithm>
using namespace std;
bool judge(string s){
	int k=s.size()-1;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[k-i])
			return false;
	}
	return true;
}
string add(string s,string s1){
	int flag=0;
	string sum;
	int temp;
	char c;
	for(int i=s.size()-1;i>=0;i--){
		temp=s[i]-'0'+s1[i]-'0'+flag;
		if(temp>=10){
			temp-=10;
			flag=1;	
		}
		else
			flag=0;
		c=temp+'0';
		sum=c+sum;
	}
	if(flag) sum='1'+sum;
	return sum;
}
int main()
{
	string s;
	string s1;
	cin>>s;
	int flag=0;
	for(int i=0;i<10;i++){
		string sum;
		if(judge(s)==true){
			cout<<s<<" is a palindromic number.";
			flag=1;
			break;
		}
		s1=s;
		reverse(s1.begin(),s1.end()); 
		sum=add(s,s1);
		cout<<s<<" + "<<s1<<" = "<<sum<<endl;
		s=sum;
	}
	if(flag==0) printf("Not found in 10 iterations.");
	
}
