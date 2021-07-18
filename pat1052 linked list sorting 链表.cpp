#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int address;
	int key;
	int next;
};
vector<node> list(100000);
vector<node> L;
bool cmp(node a,node b){
	return a.key<b.key;
}
int main()
{
	int n;         //n个结点 
	int head;      //头结点的地址 
	int ans;     //ans个结点 
	scanf("%d %d",&n,&head);  
	 
	int addr,key,next;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&addr,&key,&next);
		list[addr]={addr,key,next};
	}
	for(int i=head;i!=-1;i=list[i].next){
		L.push_back(list[i]);
	}
	ans=L.size();
	if(ans==0)
		printf("0 -1");
	else{
		sort(L.begin(),L.end(),cmp);
		head=L.front().address;   
		for(int i=0;i<ans;i++){
			if(i==ans-1)
			L[i].next=-1;
			else 
			L[i].next=L[i+1].address;
		}
		printf("%d %05d\n",ans,head);
		for(int i=0;i<ans;i++){
			if(i==ans-1)  
			printf("%05d %d %d\n",L[i].address,L[i].key,L[i].next);
			else 
			printf("%05d %d %05d\n",L[i].address,L[i].key,L[i].next);
		}
	}
	return 0;
} 
