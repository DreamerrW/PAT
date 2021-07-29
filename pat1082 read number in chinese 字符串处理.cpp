#include<iostream>
#include<vector>
using namespace std;
string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string c[9]={""," Shi"," Bai"," Qian"," Wan"," Shi"," Bai"," Qian"," Yi"};
int main()
{
	string s;
	cin>>s; 
	if(s[0]=='-'){ 	   //两种特殊情况
		cout<<"Fu ";
		s.erase(0,1);  //去掉一开始的负号 
	}
	if(s[0]=='0'){
		cout<<"ling";
		return 0;
	}
	int len=s.length();
	int pre=0;
	for(int i=0;i<s.length();i++){   
		int n=s[i]-'0';                       //转为数字 
		if(n!=0){
			if(pre!=0) cout<<" ling";        //如果前面有0 就补输出0 
			if(i>0) cout<<" ";              //不是第一个数字的话就输出空格 
			cout<<num[n]<<c[len-1-i];
			pre=0;                           //每遇到一个不为0的数，将pre=0 
		}
		else {
			if((len-i-1)%4==0&&pre!=3) cout<<c[len-1-i];   //在wan位的0的单位wan 要输出 
			pre++;   
		}
	}
	return 0;
 } 
