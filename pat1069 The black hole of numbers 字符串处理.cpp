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
	s.insert(0,4-s.length(),'0');     //����������4λ��ʱ��ǰ�油0
	do{
		string a=s,b=s;
		sort(a.begin(),a.end(),cmp);
		sort(b.begin(),b.end());
		int ans=stoi(a)-stoi(b);      //stoi��������stringתΪ�ַ��� 
		s=to_string(ans);             //int��ת���ַ��� to_string ֻ�ܶ�stringʹ�� 
		s.insert(0,4-s.length(),'0');
		cout<<a<<" - "<<b<<" = "<<s<<endl;
	}while(s!="6174"&&s!="0000");
	return 0;
 } 
