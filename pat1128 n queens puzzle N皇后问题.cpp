#include<cstdio>
#include<cmath>
using namespace std;
int p[1001];
int main()
{
	int k;
	scanf("%d",&k);
	int n;
	while(k--){
		scanf("%d",&n);
		int flag=0;
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
			for(int j=0;j<i;j++){  //����֮ǰ�Ļʺ� 
				if(p[j]==p[i]||abs(p[j]-p[i])==abs(j-i)){   //�鿴ǰ���Ƿ��лʺ�͵�ǰ�Ļʺ���һ���Խ����ϻ���һ���� 
					flag=1;
					break;
				}
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
 } 
