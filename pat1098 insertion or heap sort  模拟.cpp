#include<cstdio>
#include<algorithm>
using namespace std;
void downjust(int (&b)[110],int low,int high){  //调整为堆 
	int i=0,j=2*i+1;
	while(j<=high){
		if(j+1<=high&&b[j]<b[j+1]) j=j+1;  //父母结点要和最大的子结点交换 
		if(b[i]>=b[j]) break;
		swap(b[i],b[j]);  //若是不满足父母优势，就交换结点 
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
		printf("Insertion Sort\n");  //插入排序 
		sort(b,b+i+2);
	}
	else{
		printf("Heap Sort\n");  //为堆排序 
		i=n-1;
		while(i>1&&b[i]>=b[0]) i--; //i指向堆尾元素 
		swap(b[0],b[i]);      //堆尾和堆顶交换 
		downjust(b,0,i-1);    //向下调整 
	}
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",b[i]);
	}
	return 0;
}
