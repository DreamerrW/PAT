#include<iostream>
#include<vector>
using namespace std;
string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string c[9]={""," Shi"," Bai"," Qian"," Wan"," Shi"," Bai"," Qian"," Yi"};
int main()
{
	string s;
	cin>>s; 
	if(s[0]=='-'){ 	   //�����������
		cout<<"Fu ";
		s.erase(0,1);  //ȥ��һ��ʼ�ĸ��� 
	}
	if(s[0]=='0'){
		cout<<"ling";
		return 0;
	}
	int len=s.length();
	int pre=0;
	for(int i=0;i<s.length();i++){   
		int n=s[i]-'0';                       //תΪ���� 
		if(n!=0){
			if(pre!=0) cout<<" ling";        //���ǰ����0 �Ͳ����0 
			if(i>0) cout<<" ";              //���ǵ�һ�����ֵĻ�������ո� 
			cout<<num[n]<<c[len-1-i];
			pre=0;                           //ÿ����һ����Ϊ0��������pre=0 
		}
		else {
			if((len-i-1)%4==0&&pre!=3) cout<<c[len-1-i];   //��wanλ��0�ĵ�λwan Ҫ��� 
			pre++;   
		}
	}
	return 0;
 } 
