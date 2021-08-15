#include<iostream>
using namespace std;
int main()
{
	int n;
	string s;
	string a,b;
	cin>>n;
	int z,t1,t2;
	while(n--){
		cin>>s;
		a=s.substr(0,s.size()/2);
		b=s.substr(s.size()/2,s.size()/2);
		z=stoi(s);
		t1=stoi(a);
		t2=stoi(b);
		if(t1==0||t2==0){
			printf("No\n");
			continue;
		} 
		if(z%(t1*t2)==0)
			printf("Yes");
		else printf("No");
		printf("\n");
	}
	return 0;
 } 
