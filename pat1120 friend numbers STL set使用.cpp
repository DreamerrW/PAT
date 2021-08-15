#include<iostream>
#include<set>
using namespace std;
int getfriend(int x){
	int sum=0;
	while(x!=0){
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int main(){
	set<int> s;
	int n;
	int temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		s.insert(getfriend(temp));
	}
	printf("%d\n",s.size());
	for(auto it=s.begin();it!=s.end();it++){
		if(it!=s.begin()) printf(" ");
		printf("%d",*it);
	}
	return 0;
} 
