#include<cstdio>
#include<vector>
using namespace std;
vector<int> pre,in;
vector<int> post;
void postorder(int preL,int preR,int inL,int inR){
	if(preL>preR) return ;
	int k;
	for(k=inL;k<=inR;k++){
		if(pre[preL]==in[k]) //找到根节点在中序数组中的位置  
		break;
	}
	int numleft=k-inL;
	postorder(preL+1,preL+numleft,inL,k-1);
	postorder(preL+numleft+1,preR,k+1,inR);
	post.push_back(pre[preL]);
}
int main()
{
	int n;
	scanf("%d",&n);
	pre.resize(n);
	in.resize(n); 
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	postorder(0,n-1,0,n-1);
	printf("%d",post[0]);
	return 0;
 } 
