#include<cstdio>
#include<algorithm>
using namespace std;
void downjust(int (&b)[110],int low,int high){  //����Ϊ�� 
	int i=0,j=2*i+1;
	while(j<=high){
		if(j+1<=high&&b[j]<b[j+1]) j=j+1;  //��ĸ���Ҫ�������ӽ�㽻�� 
		if(b[i]>=b[j]) break;
		swap(b[i],b[j]);  //���ǲ����㸸ĸ���ƣ��ͽ������ 
		i=j;j=2*i+1; 
	} 
} 
int main()
{
	int a[110],b[110];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	int i=0;
	while(b[i]<=b[i+1]&&i<n-1) i++;
	int j=i+1;
	while(a[j]==b[j]&&j<n) j++;
	if(j==n){
		printf("Insertion Sort\n");  //�������� 
		sort(b,b+i+2);
	}
	else{
		printf("Heap Sort\n");  //Ϊ������ 
		i=n-1;
		while(i>1&&b[i]>=b[0]) i--; //iָ���βԪ�� 
		swap(b[0],b[i]);      //��β�ͶѶ����� 
		downjust(b,0,i-1);    //���µ��� 
	}
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",b[i]);
	}
	return 0;
}
