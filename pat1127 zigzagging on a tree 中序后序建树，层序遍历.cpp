#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int data;
	int level;
	node *lchild,*rchild;
};
vector<int> post,in,level;
int h[30]; 
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR)	return NULL;
	node *root=new node;
	root->data=post[postR];
	int i;
	for(i=inL;i<=inR;i++){
		if(in[i]==post[postR])
			break;
	}
	int numleft=i-inL;
	root->lchild=create(postL,postL+numleft-1,inL,i-1);
	root->rchild=create(postL+numleft,postR-1,i+1,inR);
	return root;
}
int main()
{
	node *root=NULL;
	int n;
	scanf("%d",&n);
	post.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	root=create(0,n-1,0,n-1);
	
	queue<node*> q;
	root->level=1;
	q.push(root);
	int maxlevel=-1;
	while(!q.empty()){
		node *top=q.front();
		q.pop();
		level.push_back(top->data);	 //层序遍历序列 
		
		h[top->level]++;             //记录这个高度的结点有多少个 
		if(top->level>maxlevel) maxlevel=top->level;
		
		if(top->lchild){
			top->lchild->level=top->level+1;
			q.push(top->lchild);
		}
		if(top->rchild){
			top->rchild->level=top->level+1;
			q.push(top->rchild);
		}	
	}

	int sum=0;
	for(int i=1;i<=maxlevel;i++){
		if(i%2==1){  //从右往左输入 
			for(int j=sum+h[i]-1;j>=sum;j--){
				if(j!=0) printf(" ");
				printf("%d",level[j]);
			}
			sum+=h[i];
		}
		else if(i%2==0){
			for(int j=sum;j<sum+h[i];j++){
				if(j!=0) printf(" ");
				printf("%d",level[j]);
			}
			sum+=h[i];
		}
	} 
	return 0;
}
