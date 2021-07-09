#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;
const int maxn=30;
int pre[maxn],in[maxn],post[maxn];
int n; //结点个数 

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* create(int postL,int postR,int inL,int inR)
{
	if(postL>postR)  return NULL;
	node* root =new node;
	root->data=post[postR];  //根结点的值为后续遍历中最后面的值
	int k;
	for(k=inL;k<=inR;k++)
	{
		if(in[k]==post[postR])  //在中序遍历中找到了根结点
		break; 
	 } 
	 int numleft=k-inL;
	 root->lchild=create(postL,postL+numleft-1,inL,k-1);
	 root->rchild=create(postL+numleft,postR-1,k+1,inR);
	 return root; 
}
void bfs(node* root){
	int num=0;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
}
int main()
{
	scanf("%d",&n);   //输入结点个数
	for(int i=0;i<n;i++)
	scanf("%d",&post[i]);
	for(int i=0;i<n;i++)
	scanf("%d",&in[i]);
	node* root =create(0,n-1,0,n-1);
	bfs(root);
	return 0;
} 
