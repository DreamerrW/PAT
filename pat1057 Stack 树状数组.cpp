#include<iostream>
#include<stack>
#include<string>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int maxn=100010;
int c[maxn];   //树状数组 
stack<int> s;
void update(int x,int v){
	for(int i=x;i<maxn;i+=lowbit(i)){
		c[i]+=v;
	}
}
int getsum(int x){
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i))
		sum+=c[i];
	return sum;
}
void peekmedian(){
	int left=1,right=maxn,mid,k=(s.size()+1)/2;
	while(left<right){
		mid=(left+right)/2;
		if(getsum(mid)>=k) 
			right=mid;
		else left=mid+1;
	} 
	printf("%d\n",left);
}
int main()
{

	int n;
	scanf("%d",&n);   //n次操作 
	string str;
	int temp;
	while(n--){
		cin>>str;
		if(str[1]=='u'){         //push操作 
			scanf("%d",&temp);
			s.push(temp);
			update(temp,1);
		} 
		else if(str[1]=='o'){     //pop操作 
			if(!s.empty()){
				update(s.top(),-1);
				printf("%d\n",s.top());
				s.pop();
			}
			else printf("Invalid\n");
		}
		else{					 //选择中位数操作 
			if(!s.empty())
				peekmedian();
			else 
				printf("Invalid\n");
		}
	} 
	return 0;
 } 
