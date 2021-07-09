#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.size();
	int n1,n2;
	int k;
	int maxk=1;
	for(n2=3;n2<=len;n2++){
		for(k=1;k<=n2;k++){
			if(k+n2+k-2==len){
				if(k>maxk)
				maxk=k;
			}
		}
	}
	n1=maxk;
	n2=len+2-2*n1;
	for(int i=0;i<len-1;i++)
	{
		if(i<n1-1) {
			printf("%c",s[i]);
			for(int j=0;j<n2-2;j++){
				printf(" ");
			}
			printf("%c\n",s[len-1-i]);
		}
		else if(i<n1+n2-1)  printf("%c",s[i]);
		else break;
	}
	return 0;
 } 
