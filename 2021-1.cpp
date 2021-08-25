#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans,ans1;
int flags[100001];
int dif;  //公差 
int n,maxp;  
int maxprime,num=0;
int flag=0;
bool isprime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
void dfs(int index){
	ans.push_back(index); 
	if(ans.size()==n){  //有六个数
		ans1=ans; 
		flag=1;
		return ;
	}
	if(flags[index+dif]==1)  //也是素数
		dfs(index+dif); 
}
int main()
{
	cin>>n>>maxp;
	for(int i=1;i<=maxp;i++)         //建立素数表 
		if(isprime(i)){
			num++;          //记录有几个素数 
			maxprime=i;
			flags[i]=1;
		}
	if(num<=n||n==1){    
		printf("%d",maxprime);
		return 0;
	}
	for(dif=maxp/(n-1);dif>=1;dif--){
		for(int i=2;i+(n-1)*dif<=maxp;i++){
			ans.clear();
			if(flags[i]==1)
				dfs(i); 
		}
		if(flag) break;
	}
	if(ans1.size()==0){ //如果找不到 
		printf("%d",maxprime);
		return 0;
	}
	for(int i=0;i<n;i++){
		if(i!=0) printf(" ");
		printf("%d",ans1[i]);
	}
	return 0;
 } 
