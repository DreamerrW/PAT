#include<iostream>
#include<cctype>
using namespace std;
string a[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"}; //低位 
string b[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"}; //高位 
int main()
{
	string s;
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,s);
		if(isdigit(s[0])){   //是地球数字 
			int num=stoi(s);
			if(num/13) printf("%s",b[num/13].c_str());
			if(num%13&&num/13) printf(" ");  
			if(num%13||num==0) printf("%s",a[num%13].c_str());
            printf("\n");
		}
		else{         //是火星字符 
			if(s=="tret"){
				printf("0\n");
				continue;
			}
			int t1=0,t2=0;
			string s1=s.substr(0,3);
			string s2;
			if(s.length()>4)     //如果还有第二个字符 
				s2=s.substr(4,3);
			if(s2.length()!=0){  //如果有两个字符 
				for(int j=1;j<13;j++){
					if(s1==b[j]) t1=j;
					if(s2==a[j]) t2=j;
				}
			}
			else{			    //如果只有一个 
				for(int j=1;j<13;j++){
					if(s1==a[j]) t2=j;
					if(s1==b[j]) t1=j;		
				}
 			}
			printf("%d\n",t1*13+t2);
		} 
	}
	return 0;
 } 
