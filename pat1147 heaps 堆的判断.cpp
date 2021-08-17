#include<iostream>
#include<vector>
using namespace std;
int t;
int m,n; 
vector<int> v(1001);
vector<int> post(1001);
void postorder(int i){
	if(i>=n) return ;
	postorder(2*i+1);
    postorder(2*i+2);
	post[t++]=v[i];
}
int main()
{

	cin>>m>>n;
	while(m--){
		t=0;
		for(int i=0;i<n;i++)
			cin>>v[i];
		int ismax=1,ismin=1;
		for(int i=0;2*i+1<n;i++){  //先判断是不是大根堆 
			if(i*2+2<n){  //如果有右孩子 
				if(v[i]<v[2*i+1]||v[i]<v[2*i+2]){
					ismax=0;
					break;
				}
			}
			else{
				if(v[i]<v[2*i+1]){
					ismax=0;
					break;	
				}
			}
		}
		for(int i=0;2*i+1<n;i++){
			if(2*i+2<n){  //如果有右孩子 
				if(v[i]>v[2*i+1]||v[i]>v[2*i+2]){
					ismin=0;
					break;
				}
			}
			else{
				if(v[i]>v[2*i+1]){
					ismin=0;
					break;	
				}
			}
		}
		if(ismax==0&&ismin==0) printf("Not Heap\n");
		if(ismax==0&&ismin==1) printf("Min Heap\n");
		if(ismax==1&&ismin==0) printf("Max Heap\n");
		postorder(0);
		for(int i=0;i<n;i++){
			if(i!=0) printf(" ");
			printf("%d",post[i]);
			if(i==n-1) printf("\n");
		}
	}
}
