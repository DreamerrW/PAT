#include<iostream>
#include<cmath>
using namespace std;
// 630 
// 5*6*7
int main()	
{
	int n;
	scanf("%d",&n);
	int tempnum=1;
	int i,j;
	int len=0;
	int first=0; 
	for(i=2;i<=sqrt(n);i++){
		tempnum=n;
		for(j=i;j<=sqrt(n);j++){
			if(tempnum%j!=0) break;
			tempnum/=j;
		}
		if(j-i>len){
			len=j-i;
			first=i;
		}
	}
	if(first==0) printf("1\n%d",n); //first=0也就是没有因数 
	else {
		printf("%d\n",len);
		for(int i=0;i<len;i++){
			if(i!=0) printf("*");
			printf("%d",first+i);
		}
	}
	return 0;
}

