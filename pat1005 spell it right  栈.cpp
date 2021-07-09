#include<iostream>
#include<string>
using namespace std;
int main()
{
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six","seven", "eight", "nine"};
	string a;
	cin>>a;
	int sum=0;
	for(int i=0;i<a.size();i++)
		sum+=a[i]-'0';
	string s=to_string(sum);   //to_string函数，可以将数字转换成字符串
	for(int i=0;i<s.size();i++)
	{
		cout<<arr[s[i]-'0'];
		if(i!=s.size()-1) printf(" ");
	}
	return 0; 	
}
