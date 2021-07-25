#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int data;
	int height;  //子树高度
	node *lchild,*rchild;
};

int getHeight(node *root){
	if(root==NULL) return 0;       //空树高度为0; 
	else return root->height;
} 
void updateHeight(node* root){     //更新结点的高度 
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;  //左子树高度与右子树高度最大值+1 
} 
int getBalanceFactor(node *root){   //获得结点的平衡因子 
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void L(node* &root){   //左旋 
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void R(node* &root){  //右旋 
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp; 
}
void insert(node* &root,int temp){ //结点插入函数，用来建立AVL函数 
	if(root==NULL){
		root=new node;
		root->height=1;
		root->lchild=root->rchild=NULL;
		root->data=temp;
		return; 
	}
	if(temp<root->data){
		insert(root->lchild,temp);
		updateHeight(root);  //更新树高
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1)    //LL型
				R(root);
			else if(getBalanceFactor(root->lchild)==-1){ //LR型 
				L(root->lchild);
				R(root); 
			}
		} 
	}
	else {
		insert(root->rchild,temp);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1)    //RR型
				L(root);
			else if(getBalanceFactor(root->rchild)==1){ //RL型 
				R(root->rchild);
				L(root); 
			}
		} 
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node *root=NULL;
	int temp;
	for(int i=0;i<n;i++){  //输入n个数 
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d",root->data); 
	return 0;
}
