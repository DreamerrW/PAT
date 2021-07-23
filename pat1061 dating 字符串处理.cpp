#include<iostream>
#include<cctype>
using namespace std;
string week[8]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char ans[2];  //ans[0]是代表星期几  ans[1]代表小时数 
	int cnt=0;
	for(int i=0;i<a.length()&&i<b.length();i++){
		if(cnt==0){  //cnt为0，找第一个相等的 
			if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G')
				ans[cnt++]=a[i];
		} 
		else{  //cnt为1，找第二个 
			if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='N'||isdigit(a[i])))
				ans[cnt++]=a[i];
		}
		if(cnt==2) break;
	}
	
	int hours=isdigit(ans[1])?(ans[1]-'0'):(ans[1]-'A'+10);
	int minute=0;   //秒数 
	for(int i=0;i<c.length()&&i<d.length();i++){
		if(c[i]==d[i]&&isalpha(c[i])){  //此处只要是字母就行 
			minute=i;
			break;
		}
	}
	printf("%s %02d:%02d",week[ans[0]-'A'].c_str(),hours,minute);
	return 0; 
 } 
