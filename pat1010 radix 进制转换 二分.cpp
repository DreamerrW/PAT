#include<stdio.h>
#include<string.h>
#include<math.h>

long long int str_num(char s[],long long int radix)  //将确定进制的数转换为10进制数字,查找的最大进制为num+1 
{
	long long int num=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		num=num*radix+s[i]-'0';
		else if(s[i]>='a'&&s[i]<='z')
		num=num*radix+(s[i]-'a'+10);	
	} 	
	return num;
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else 
	return b;
}
int findminradix(char s[])   //找到最小的进制即为n2中权值最大的数+1 
{
	int minradix=2;  //最小的是二进制 
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		minradix=max(minradix,s[i]-'0'+1);
		else if(s[i]>='a'&&s[i]<='z')
		minradix=max(minradix,s[i]-'a'+11); 
	}
	return minradix;
}

void match(char s1[],char s2[],long long int radix)
{

	long long  left,right,mid;
	long long  num2;
	long long  num1=str_num(s1,radix);
	left=findminradix(s2);
	right=num1+1;
	while(left<right)
	{
		mid=(left+right)/2;
		num2=str_num(s2,mid);
		if(num1==num2)
		{
			printf("%lld",mid);
			return;
		}
		else if(num1<num2||num2<0) right=mid-1;
		else left=mid+1;
	}
	if(num1==str_num(s2,left)) printf("%lld",left);
	else printf("Impossible");
		
}
int main()
{
	char s1[11];
	char s2[11];
	long long int radix;
	int tag;
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%d",&tag);
	scanf("%lld",&radix);
	if(tag==1) match(s1,s2,radix);
	else if(tag==2) match(s2,s1,radix);

	return 0;
 } 
