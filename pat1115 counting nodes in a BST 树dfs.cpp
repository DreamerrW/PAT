#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int data;
	node* lchild,*rchild;
};
int maxdepth=-1;
vector<int> num(1000);
void insert(node* &root,int x){
	if(root==NULL){
		root=new node;
		root->data=x;
		root->lchild=root->rchild=NULL;
		return;
	}
	if(x<=root->data)
		insert(root->lchild,x);
	else 
		insert(root->rchild,x);
} 
void dfs(node *root,int depth){
	num[depth]++;
	if(root->lchild!=NULL) dfs(root->lchild,depth+1);
	if(root->rchild!=NULL) dfs(root->rchild,depth+1); 
	maxdepth=max(maxdepth,depth);
}
int main()
{
	int n;
	scanf("%d",&n);
	node* root=NULL;
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		insert(root,temp);  //½¨Á¢¶þ²æÊ÷ 
	}
	dfs(root,1);
	printf("%d + %d = %d",num[maxdepth],num[maxdepth-1],num[maxdepth-1]+num[maxdepth]);
	return 0;
}
