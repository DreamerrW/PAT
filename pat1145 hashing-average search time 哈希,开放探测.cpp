#include<iostream>
#include<algorithm>
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
	int hash[10010];
	fill(hash,hash+10010,0);
	int msize,n,m;
	cin>>msize>>n>>m;
	int tm=m;
	while(isprime(msize)==false) msize++;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		int flag=0;
		for(int j=0;j<msize;j++){
			int index=(temp+j*j)%msize;
			if(hash[index]==0){ //�ҵ�һ���ܲ����λ�� 
				hash[index]=temp;
				flag=1;
				break;
			}
		}
		if(!flag) printf("%d cannot be inserted.\n",temp); 
	}
	int cnt=0;
	while(tm--){
		cin>>temp;
		for(int i=0;i<=msize;i++){
			cnt++; //���Ҵ�����һ 
			int index=(temp+i*i)%msize;
			if(hash[index]==temp||hash[index]==0) //���ҳɹ� 
				break; 
		}
	}
    printf("%.1f\n", (double)cnt/m);
}
