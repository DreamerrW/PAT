#include<iostream>
using namespace std;
bool isprime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int hash[10010]={0};
	int n,size;
	cin>>size>>n;
	while(!isprime(size)) size++;  //�ҵ���С��size
	int temp;
	int flag;
	for(int i=0;i<n;i++){   //n��Ҫ��������� 
		flag=0;
		cin>>temp;
		int index;
		if(i!=0) cout<<" ";
		for(int k=0;k<size;k++){
			index=(temp+k*k)%size;
			if(hash[index]==0){
				hash[index]=1;
				cout<<index;
				flag=1;        //�ҵ��� 
				break;
			}
		}
		if(!flag) printf("-"); //û���ҵ������ "-" 
	} 
	return 0;
 } 
