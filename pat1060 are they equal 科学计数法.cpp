#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);  //��Ч��λ��
	char a[10000],b[10000];
	char ans1[10000],ans2[10000]; 
	scanf("%s%s",a,b);
	int p,q;        //p��¼aС����λ�ã�q��¼bС����λ��
	p=strlen(a);
	q=strlen(b);    //����û��С���㣬������ĩβ 
	for(int i=0;i<strlen(a);i++){  //��¼С����λ�� 
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
	
	int firsta=0,firstb=0;  //a��b�ĵ�һ����Ч����λ�� 
	while(a[firsta]=='0'||a[firsta]=='.') firsta++;
	while(b[firstb]=='0'||b[firstb]=='.') firstb++;
	
	int e1,e2;                 //a��b��ָ������ 
	if(p>=firsta) e1=p-firsta; //˵����һ�����������
	else e1=p-firsta+1;
	if(q>=firstb) e2=q-firstb;
	else e2=q-firstb+1;
	
	if(firsta==strlen(a)) e1=0;
	if(firstb==strlen(b)) e2=0;
	
	int cnt1=0,cnt2=0;       //�������Ч������Ŀ 
	while(cnt1<n){
		if(a[firsta]!='.'&&firsta<strlen(a))
			ans1[cnt1++]=a[firsta];
		else if(firsta>=strlen(a)) 
			ans1[cnt1++]='0'; //��0
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
