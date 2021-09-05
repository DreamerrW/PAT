#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
string a[26][7];
string ans[100010];
int main()
{
	for(int i=0;i<26;i++){
		for(int j=0;j<7;j++){
			cin>>a[i][j];
		}
	}
	string t;
	getchar();
	getline(cin,t);
	int num=0;   //出现的单词个数 
	int flag=0;
	for(int i=0;i<t.length();i++){
		if(t[i]>='A'&&t[i]<='Z'){  //如过是字母 
			for(int j=0;j<7;j++){
				if(flag)
					ans[j+num*7]+=' ';	
				ans[j+num*7]+=a[t[i]-'A'][j];
			}
			if(flag==0)
				flag=1;
		}
		else{
			if(i!=0){
				if(t[i-1]>='A'&&t[i-1]<='Z'){
					num++;
					flag=0;	
				}
			}
		}
	}
	int k=t.length()-1;
	if(t[k]>='A'&&t[k]<='Z') num++;
	for(int i=0;i<num*7;i++){
		if(i%7==0&&i!=0) cout<<endl;
		cout<<ans[i];
		if(i!=num*7-1) cout<<endl;
	}
	return 0;
 } 
