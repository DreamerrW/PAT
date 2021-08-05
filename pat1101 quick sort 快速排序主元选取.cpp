#include<iostream>
#include<vector>
#include<algorithm>
//快速排序中，一次划分后，左边元素比主元小，右边元素比主元要大
int ans[100010]; 
using namespace std;
int main(){
	int n,max=0,cnt=0;
	scanf("%d",&n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(a[i]==b[i]&&b[i]>max){ //排序前后，主元的位置不变 
			ans[cnt]=b[i];
			cnt++;
		}
		if(max<b[i])
			max=b[i];
 	}
 	printf("%d\n",cnt);
 	for(int i=0;i<cnt;i++){
 		if(i!=0) printf(" ");
		 printf("%d",ans[i]); 
	}
	printf("\n");      //没有主元要输出空行
	return 0;
} 
