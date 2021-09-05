#include<iostream>
using namespace std;
bool isprime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	string s;
	cin>>s;
	bool flag=false;
	for(int i=0;i<s.size();i++){
		string t;
		t=s.substr(i);
		int temp;
		temp=stoi(t);
		cout<<t;
		if(isprime(temp))
			cout<<" Yes\n";
		else{
			cout<<" No\n";
			flag=true;
		}
	}
	if(flag==false) cout<<"All Prime!";
	return 0;
} 
