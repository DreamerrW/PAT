#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int data;
	int height;  //�����߶�
	node *lchild,*rchild;
};

int getHeight(node *root){
	if(root==NULL) return 0;       //�����߶�Ϊ0; 
	else return root->height;
} 
void updateHeight(node* root){     //���½��ĸ߶� 
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;  //�������߶����������߶����ֵ+1 
} 
int getBalanceFactor(node *root){   //��ý���ƽ������ 
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void L(node* &root){   //���� 
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void R(node* &root){  //���� 
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp; 
}
void insert(node* &root,int temp){ //�����뺯������������AVL���� 
	if(root==NULL){
		root=new node;
		root->height=1;
		root->lchild=root->rchild=NULL;
		root->data=temp;
		return; 
	}
	if(temp<root->data){
		insert(root->lchild,temp);
		updateHeight(root);  //��������
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1)    //LL��
				R(root);
			else if(getBalanceFactor(root->lchild)==-1){ //LR�� 
				L(root->lchild);
				R(root); 
			}
		} 
	}
	else {
		insert(root->rchild,temp);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1)    //RR��
				L(root);
			else if(getBalanceFactor(root->rchild)==1){ //RL�� 
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
	for(int i=0;i<n;i++){  //����n���� 
		scanf("%d",&temp);
		insert(root,temp);
	}
	printf("%d",root->data); 
	return 0;
}
