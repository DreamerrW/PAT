#include<cstdio>
#include<algorithm>
using namespace std;
bool isprime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int a[10000];
bool checked[10000]={false};
int main()
{
	fill(a,a+10000,-1);
	int temp;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		a[temp]=i;
	}
	//²éÑ¯
	int k;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&temp);
		if(a[temp]==-1){
			printf("%04d: Are you kidding?\n",temp);
			continue;
		}
		if(checked[temp]==true){
			printf("%04d: Checked\n",temp);
			continue;
		}
		if(a[temp]==1){
			printf("%04d: Mystery Award\n",temp);
			checked[temp]=true;
		}
		else if(isprime(a[temp])){
			printf("%04d: Minion\n",temp);
			checked[temp]=true;
		}
		else{
			printf("%04d: Chocolate\n",temp);
			checked[temp]=true;
		}
	}
	return 0; 
 } 
