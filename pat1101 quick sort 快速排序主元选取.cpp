#include<iostream>
#include<vector>
#include<algorithm>
//���������У�һ�λ��ֺ����Ԫ�ر���ԪС���ұ�Ԫ�ر���ԪҪ��
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
		if(a[i]==b[i]&&b[i]>max){ //����ǰ����Ԫ��λ�ò��� 
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
	printf("\n");      //û����ԪҪ�������
	return 0;
} 
