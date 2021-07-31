#include<iostream>
#include<cmath>
using namespace std;
int sign[4]={1,1,1,1};
long long gcd(long long a, long long b) {
 return b == 0 ? a : gcd(b, a % b);
}
long long gbs(int a,int b){    //��С������ 
	return a*b/gcd(a,b);   
}
void print(long long a,long b){
	if(a==0){
		printf("0");
		return;
	}
	if(a<0){               //
		if(a/b!=0){
			printf("(%lld",a/b);
			if(abs(a)%b)
				printf(" %lld/%lld)",abs(a)%b,b);
			else printf(")");
		}
		else printf("(%lld/%lld)",a,b);
	}
	else{           //a>=0
		if(a/b){ 
			printf("%lld",a/b);
			if(a%b)
				printf(" %lld/%lld",a%b,b);
		}
		else printf("%lld/%lld",a,b);
	}
	return;
}
void add(long long a,long long b,long long c,long long d){
	long long gcdvalue;
	gcdvalue=gcd(a,b);
		a/=gcdvalue;
		b/=gcdvalue;	
	gcdvalue=gcd(c,d);
		c/=gcdvalue;
		d/=gcdvalue;

	long long suma,sumb;   //�͵ķ��ӷ�ĸ 
	suma=a*d*sign[0]+b*c*sign[2];
	sumb=gbs(b,d);
	print(a*sign[0],b);  //�����ŵ���� 
	printf(" + ");
	print(c*sign[2],d);
	printf(" = "); 
	print(suma,sumb);
	return;
} 
void sub(long long a,long long b,long long c,long long d){
	long long gcdvalue;
		gcdvalue=gcd(a,b);
		a/=gcdvalue;
		b/=gcdvalue;	
		gcdvalue=gcd(c,d);
		c/=gcdvalue;
		d/=gcdvalue;

	long long suma,sumb;   //�͵ķ��ӷ�ĸ 
	suma=a*d*sign[0]-b*c*sign[2];
	sumb=gbs(b,d);
	print(a*sign[0],b);  //�����ŵ���� 
	printf(" - ");
	print(c*sign[2],d);
	printf(" = "); 
	print(suma,sumb);
	return;
}
void pro(long long a,long long b,long long c,long long d){
	long long gcdvalue;
		gcdvalue=gcd(a,b);
		a/=gcdvalue;
		b/=gcdvalue;	
		gcdvalue=gcd(c,d);
		c/=gcdvalue;
		d/=gcdvalue;
	long long proa,prob;
	proa=a*c;
	prob=b*d;
	gcdvalue=gcd(proa,prob);
	proa/=gcdvalue;
	prob/=gcdvalue;
	proa*=sign[0]*sign[2]; //���� 
	print(a*sign[0],b);
	printf(" * ");
	print(c*sign[2],d);
	printf(" = ");
	print(proa,prob);
	return;
}
void chufa(long long a,long long b,long long c,long long d){
	long long gcdvalue;
	gcdvalue=gcd(a,b);
		a/=gcdvalue;
		b/=gcdvalue;	
	gcdvalue=gcd(c,d);
		c/=gcdvalue;
		d/=gcdvalue;
	long long chua,chub;
	chua=a*d;
	chub=b*c;
	gcdvalue=gcd(chua,chub);
	chua/=gcdvalue;
	chub/=gcdvalue;
	
	chua*=sign[0]*sign[2];
	print(a*sign[0],b);
	printf(" / ");
	print(c*sign[2],d);
	printf(" = ");
	if(chub==0){
		printf("Inf");
		return;
	}
	print(chua,chub);
	return;
}
int main()
{
	long long  a,b,c,d;
	scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
	if(a<0){   
		a=-a;
		sign[0]=-1;  
	}
	if(c<0){
		c=-c;
		sign[2]=-1;
	}
	//�ӷ�
	add(a,b,c,d);
	printf("\n");
	//����
	sub(a,b,c,d);
	printf("\n");
	//�˷� 
	pro(a,b,c,d);
	printf("\n");
	//���� 
	chufa(a,b,c,d);
	return 0;
 } 
