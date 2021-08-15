#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int data;
	node *lchild,*rchild;
};
void insert(node* &root,int v){
	if(root==NULL){
		root=new node;
		root->data=v;
		root->lchild=root->rchild=NULL;
		return ;
	}
	if(abs(v)<abs(root->data)) insert(root->lchild,v);
	else insert(root->rchild,v);
}
bool judge1(node *root){
	if(root==NULL) return true;
	if(root->data<0){  //是红结点 
		if(root->lchild!=NULL&&root->lchild->data<0) return false; //若红节点的子节点有红色 
		if(root->rchild!=NULL&&root->rchild->data<0) return false; 
	}
	return judge1(root->lchild)&&judge1(root->rchild);
}
int getnum(node *root){
	if(root==NULL) return 0;
	int l=getnum(root->lchild);
	int r=getnum(root->rchild);
	return root->data>0?max(l,r)+1:max(l,r); 
}
bool judge2(node *root){
	if(root==NULL) return true;
	int l=getnum(root->lchild);
	int r=getnum(root->rchild);
	if(l!=r) return false;
	return judge2(root->lchild)&&judge2(root->rchild);
}

int main()
{
	int k;
	cin>>k;
	int n;
	while(k--){
		cin>>n;
		int t;
		node *root=NULL;
		for(int i=0;i<n;i++){
			cin>>t;
			insert(root,t);	
		}
		if(root->data<0||judge1(root)==false||judge2(root)==false)
			printf("No\n");
		else printf("Yes\n");
	}
	return 0;
 } 
