#include<cstdio>
#include<map>
using namespace std;
map<int,int> ans;
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);   //m*nÏñËØ
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&temp);
			ans[temp]++;
		}
	} 
	int max=0;
	int color=0;
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it->second>max){
			max=it->second;
			color=it->first;
		}
	}
	printf("%d",color);
	return 0;
} 
