#include<iostream>
#include<cctype>
using namespace std;
string week[8]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char ans[2];  //ans[0]�Ǵ������ڼ�  ans[1]����Сʱ�� 
	int cnt=0;
	for(int i=0;i<a.length()&&i<b.length();i++){
		if(cnt==0){  //cntΪ0���ҵ�һ����ȵ� 
			if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
				ans[cnt++]=a[i];
		} 
		else{  //cntΪ1���ҵڶ��� 
			if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='N'||isdigit(a[i])))
				ans[cnt++]=a[i];
		}
		if(cnt==2) break;
	}
	
	int hours=isdigit(ans[1])?(ans[1]-'0'):(ans[1]-'A'+10);
	int minute=0;   //���� 
	for(int i=0;i<c.length()&&i<d.length();i++){
		if(c[i]==d[i]&&isalpha(c[i])){  //�˴�ֻҪ����ĸ���� 
			minute=i;
			break;
		}
	}
	printf("%s %02d:%02d",week[ans[0]-'A'].c_str(),hours,minute);
	return 0; 
 } 
