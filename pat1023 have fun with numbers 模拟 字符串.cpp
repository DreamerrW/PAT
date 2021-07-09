#include<iostream>
#include<string>
using namespace std;
bool exist[10]={false};
bool newexist[10]={false};
string getdouble(string s)
{
	string s1;
	int flag=0;
	int temp;
	char c;
	for(int i=s.length()-1;i>=0;i--){
		temp=(s[i]-'0')*2+flag;
		if(temp>=10){
			flag=1;
			temp=temp-10;
		}
		else flag=0;
		c=temp+'0';
		s1=c+s1;
	}
	if(flag) s1='1'+s1;
	return s1;
}
int main()
{
	string num,newnum;
	cin>>num;
	newnum=getdouble(num);
	
	for(int i=0;i<num.length();i++){
		exist[num[i]-'0']=true;
	}
	for(int i=0;i<newnum.length();i++){
		newexist[newnum[i]-'0']=true;
	}
	int flag=0;
	for(int i=0;i<=9;i++){
		if(exist[i]!=newexist[i]){
		flag=1;
		break;
		}
	}
	if(flag==1) cout<<"No\n";
	else cout<<"Yes\n";
	cout<<newnum;
	return 0;
}
 
