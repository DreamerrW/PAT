#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string s;
	cin>>s;
	//�����ʽ �� -1.23E+12 
	int i=0;
	while(s[i]!='E') i++;
	string t=s.substr(1,i-1);  //tΪEǰ��Ĳ��� 
	i++;                       //��ʱΪָ������λ
	string num=s.substr(i+1,s.length()-i);  //ָ�������ַ��� 
	int e=stoi(num);                        //ת��ָ�� 
	
	if(s[0]=='-')  cout<<s[0]; //��Ϊ���� ���������λ����Ϊ�����Ͳ��� 

	if(s[i]=='-'){            //��ָ��Ϊ�������������ǰ���e-1��0���� 
		cout<<"0.";
		for(int j=0;j<e-1;j++) cout<<'0';  //���e-1��0
		for(int j=0;j<t.length();j++) 
			if(t[j]!='.') cout<<t[j]; 
	}
	else{                    //ָ��Ϊ��������Ϊ���� 
		int j;  
		for(j=0;j<t.length()&&t[j]!='.';j++) cout<<t[j];  //�Ȱ�С����ǰ�Ĳ��������	
		j++;                      //j��ʱָ��С���������� 
		for(int k=0;k<e;k++){     //ָ����0���������־�������֣����޾Ͳ�0 
			if(j<t.length()){
				cout<<t[j];
				j++;
			}
			else cout<<'0';
		}
		//��+1.234E+2 = 123.4 �ڳ���ָ����С���㻹�ڴ�ʱstring t��û����� 
		if(j<t.length())  {
			cout<<'.';             //���С���� 
			while(j<t.length()){   //���ʣ�µ����� 
				cout<<t[j];
				j++;
			}
		}
	} 
	return 0;
 } 
