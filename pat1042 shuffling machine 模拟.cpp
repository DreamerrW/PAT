#include<cstdio>
int main()
{
	int start[55];
	int end[55];
	int scan[55];
	int n;  //洗牌次数
	scanf("%d",&n);
	for(int i=1;i<55;i++){
		scanf("%d",&scan[i]);
		end[i]=i;                //1到54赋值 
	} 
	while(n--){
		for(int i=1;i<55;i++)
			start[i]=end[i];
		for(int j=1;j<55;j++)
			end[scan[j]]=start[j];
	}
	char c[6]={"SHCDJ"};
	for(int i=1;i<55;i++){
		end[i]=end[i]-1;
		printf("%c%d",c[end[i]/13],end[i]%13+1);
		if(i!=54) printf(" ");
	}
	return 0;
 } 
