#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);  //有效的位数
	char a[10000],b[10000];
	char ans1[10000],ans2[10000]; 
	scanf("%s%s",a,b);
	int p,q;        //p记录a小数点位置，q记录b小数点位置
	p=strlen(a);
	q=strlen(b);    //若是没有小数点，就是在末尾 
	for(int i=0;i<strlen(a);i++){  //记录小数点位置 
		if(a[i]=='.'){
			p=i;
			break;
		}
	} 
	for(int i=0;i<strlen(b);i++){
		if(b[i]=='.'){
			q=i;
			break;
		}
	} 
	
	int firsta=0,firstb=0;  //a、b的第一个有效数字位置 
	while(a[firsta]=='0'||a[firsta]=='.') firsta++;
	while(b[firstb]=='0'||b[firstb]=='.') firstb++;
	
	int e1,e2;                 //a和b的指数部分 
	if(p>=firsta) e1=p-firsta; //说明是一个大于零的数
	else e1=p-firsta+1;
	if(q>=firstb) e2=q-firstb;
	else e2=q-firstb+1;
	
	if(firsta==strlen(a)) e1=0;
	if(firstb==strlen(b)) e2=0;
	
	int cnt1=0,cnt2=0;       //输出的有效数字数目 
	while(cnt1<n){
		if(a[firsta]!='.'&&firsta<strlen(a))
			ans1[cnt1++]=a[firsta];
		else if(firsta>=strlen(a)) 
			ans1[cnt1++]='0'; //补0
		firsta++;
	}
	while(cnt2<n){
		if(b[firstb]!='.'&&firstb<strlen(b))
			ans2[cnt2++]=b[firstb];
		else if(firstb>=strlen(b)) 
			ans2[cnt2++]='0';
		firstb++;
	} 
	if(strcmp(ans1,ans2)==0&&e1==e2)
		printf("YES 0.%s*10^%d",ans1,e1);
	else 
		printf("NO 0.%s*10^%d 0.%s*10^%d",ans1,e1,ans2,e2);
	return 0;
 } 
