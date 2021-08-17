#include<iostream>
using namespace std;
bool isprime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	string s;
	int len,k;
	cin>>len>>k;
	cin>>s;
	for(int i=0;i+k<=len;i++){
		string t=s.substr(i,k);
		int num=stoi(t);
		if(isprime(num)){
			cout<<t;
			return 0;
		}
	}
	printf("404");
 } 
