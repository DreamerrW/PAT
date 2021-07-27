#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int first;
	int n,k;   //n是总结点个数，k是逆置间隔
	cin>>first>>n>>k;
	int temp,data[100005],next[100005],list[100005],result[100005];
	
	int sum=0;   //有效结点个数 
	
	for(int i=0;i<n;i++){
		cin>>temp;
		cin>>data[temp]>>next[temp];
	}
	while(first!=-1){
		list[sum]=first;
		first=next[first];
		sum++;
	}
	for(int i=0;i<sum;i++)  result[i]=list[i];
	
	int cnt=sum/k;   //要逆置的次数 
	for(int i=0;i<cnt;i++){
		for(int j=0;j<k;j++){
			result[i*k+j]=list[i*k+k-1-j];
		}
	}
	for(int i=0;i<sum-1;i++)
		printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);
	printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
	return 0;
}
