#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string s;
	string s1;
	getline(cin,s);
	int len=s.size();
	int nowmax=0;
	int max=0;
	int p=0;        //枢轴量 

	while(p<len){     //枢轴从0到len-1   考虑以p为对称奇数个 
		nowmax=0;
		int i=0;
		while(p-i>=0&&p+i<=len-1){
			if(s[p-i]==s[p+i])
				nowmax+=(i==0?1:2);
			else break;
			i++;
		}
		if(nowmax>max)
			max=nowmax;
		p++;
	}
	p=0;
	while(p<len){   //考虑偶数个的情况 
		nowmax=0;
		int i=0;
		if(s[p]==s[p+1]){
			while(p-i>=0&&p+1+i<len){
				if(s[p-i]==s[p+1+i])
					nowmax+=2;
				else break;
				i++;
			} 
		}
		if(nowmax>max)
			max=nowmax;
		p++;
	} 
	printf("%d",max); 
 } 
