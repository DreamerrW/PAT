#include<cstdio>
using namespace std;
int coin[501];               //Ӳ��������500  
int main()
{
	int n,m;  				 //n���ܹ���Ӳ����Ŀ��m��Ҫ����Ǯ 
	scanf("%d %d",&n,&m);
	int temp;   
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		coin[temp]++;          //��¼ÿ�����ֳ��ֵĴ��� 
	}

	for(int i=0;i<501;i++){
		if(coin[i]){
			coin[i]--;
			if(m>i&&coin[m-i]!=0){
				printf("%d %d",i,m-i);
				return 0;
			}
			coin[i]++;
		} 
	}
	printf("No Solution");
	return 0;
 } 
