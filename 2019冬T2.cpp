#include<iostream>
using namespace std;
int main()
{
	int data[100001],next[100001],list[100001],list1[100001];
	int first,n,k;
	cin>>first>>n>>k;
	for(int i=0;i<n;i++){
		int t1,t2;
		cin>>t1;
		cin>>data[t1];
		cin>>next[t1];
	}
	int num=0;
	while(first!=-1){
		list[num++]=first;
		first=next[first];
	}
	//总共有num个数
	int a=num%k;
	int j=0;
	for(j=0;j<a;j++){
		list1[j]=list[num-a+j];   //后面的m个数 
	}
	
	for(int i=num-1-a;i>=0;i-=k){
		for(int l=1;l<=k;l++){
			list1[j++]=list[i-k+l];
		}
	}
	
	for(int i=0;i<num;i++){
		if(i==0)
		    printf("%05d %d",list1[i],data[list1[i]]);
		else
			printf(" %05d\n%05d %d",list1[i],list1[i],data[list1[i]]);
		if(i==num-1)
			printf(" -1");
	}
	return 0;
}
