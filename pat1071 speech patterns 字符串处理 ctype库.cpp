#include<iostream>
#include<map>
#include<cctype>
//isalnum ��������ʶ���Ƿ������֡���ĸ  isalpha����ʶ���Ƿ�����ĸ isdigit����ʶ���Ƿ������� tolower��������д��ΪСд 
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	map<string,int> ans;
	string t;
	for(int i=0;i<s.length();i++){
		if(isalnum(s[i])){
			s[i]=tolower(s[i]);
			t+=s[i];
		}
		if(!isalnum(s[i])||i==s.length()-1){
			if(t.length()!=0) ans[t]++;
			t="";  //t����Ϊ�� 
		}
	}
	int maxn=0;
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it->second>maxn) {
			t=it->first;
			maxn=it->second;
		}
	} 
	cout<<t<<" "<<maxn;
	return 0;
 } 
