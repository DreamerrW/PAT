#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int ans=0;
	int cntt=0,cntp=0;  //A前面的P和T个数
	for(int i=0;i<s.length();i++){
		if(s[i]=='T') cntt++;
	} 
	for(int i=0;i<s.length();i++){
		if(s[i]=='P') cntp++;
		if(s[i]=='T') cntt--;
		if(s[i]=='A') {
			ans+=(cntp*cntt%1000000007);
			ans%=1000000007;
		}
	}
	cout<<ans;
	return 0;
 } 
