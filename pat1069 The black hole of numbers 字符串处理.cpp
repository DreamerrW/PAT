#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main()
{
	string s;
	cin>>s;
	s.insert(0,4-s.length(),'0');     //用来给不足4位的时候前面补0
	do{
		string a=s,b=s;
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end());
		int ans=stoi(a)-stoi(b);      //stoi函数，将string转为字符串 
		s=to_string(ans);             //int型转成字符串 to_string 只能对string使用 
		s.insert(0,4-s.length(),'0');
		cout<<a<<" - "<<b<<" = "<<s<<endl;
	}while(s!="6174"&&s!="0000");
	return 0;
 } 
