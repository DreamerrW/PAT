#include<iostream>
#include<string> 
using namespace std;
int main()
{
	string s;
	cin>>s;
	//输入格式 ： -1.23E+12 
	int i=0;
	while(s[i]!='E') i++;
	string t=s.substr(1,i-1);  //t为E前面的部分 
	i++;                       //此时为指数符号位
	string num=s.substr(i+1,s.length()-i);  //指数部分字符串 
	int e=stoi(num);                        //转成指数 
	
	if(s[0]=='-')  cout<<s[0]; //若为负数 先输出符号位，若为正数就不用 

	if(s[i]=='-'){            //若指数为负数这种情况往前输出e-1个0即可 
		cout<<"0.";
		for(int j=0;j<e-1;j++) cout<<'0';  //输出e-1个0
		for(int j=0;j<t.length();j++) 
			if(t[j]!='.') cout<<t[j]; 
	}
	else{                    //指数为正数，较为复杂 
		int j;  
		for(j=0;j<t.length()&&t[j]!='.';j++) cout<<t[j];  //先把小数点前的部分输出了	
		j++;                      //j此时指向小数点后面的数 
		for(int k=0;k<e;k++){     //指数个0，若有数字就输出数字，若无就补0 
			if(j<t.length()){
				cout<<t[j];
				j++;
			}
			else cout<<'0';
		}
		//如+1.234E+2 = 123.4 在乘以指数后小数点还在此时string t还没输出完 
		if(j<t.length())  {
			cout<<'.';             //输出小数点 
			while(j<t.length()){   //输出剩下的数字 
				cout<<t[j];
				j++;
			}
		}
	} 
	return 0;
 } 
