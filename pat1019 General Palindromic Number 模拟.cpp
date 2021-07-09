#include<cstdio>

using namespace std;
int main()
{
	int n;
	int radix;
	scanf("%d %d",&n,&radix);
	int arr[40];
	int index=0;
	while(n!=0)
	{
		arr[index]=n%radix;
		index++;
		n=n/radix;
	}
	int i=0;
	index--;
	int k=index;
	while(i<k)
	{
		if(arr[i]!=arr[k])
		break;
		i++;
		k--;
	}
	if(i>=k)
	printf("Yes\n");
	else 
	printf("No\n");
	for(int j=index;j>=0;j--)
	{
		printf("%d",arr[j]);
		if(j!=0)  printf(" ");
	}
	if(index==-1)   //若输入0的情况 
	printf("0");
	return 0;
 } 
