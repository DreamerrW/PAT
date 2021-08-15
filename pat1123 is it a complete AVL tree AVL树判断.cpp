#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int id;
	int data;
	int height;  //�����߶�
	node *lchild,*rchild;
};
int iscomplete=1;
int n; //����� 
int getheight(node *root){
	if(root==NULL) return 0;  //�����߶�Ϊ0
	else return root->height; 
}
void updateheight(node* root){     //���½��ĸ߶� 
	root->height=max(getheight(root->lchild),getheight(root->rchild))+1;  //�������߶����������߶����ֵ+1 
} 
int getBF(node *root){
	return getheight(root->lchild)-getheight(root->rchild);
}
void L(node* &root){   //���� 
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateheight(root);
    updateheight(temp);
    root=temp;
}
void R(node* &root){  //���� 
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateheight(root);
	updateheight(temp);
	root=temp; 
}
void insert(node* &root,int v){
	if(root==NULL){  //new node
		root=new node;
		root->height=1;
		root->lchild=root->rchild=NULL;
		root->data=v;
		return ;
	}
	if(v<root->data){  //���������� 
		insert(root->lchild,v);
		updateheight(root);  //��������
		if(getBF(root)==2){
			if(getBF(root->lchild)==1){       //LL
				R(root);
			}
			else if(getBF(root->lchild)==-1){ //LR
				L(root->lchild);
				R(root);
			}
		}
	}
	else{
		insert(root->rchild,v);
		updateheight(root);  //��������
		if(getBF(root)==-2){
			if(getBF(root->rchild)==-1){ //RR
				L(root);
			}
			else if(getBF(root->rchild)==1){ //RL
				R(root->rchild);
				L(root); 
			}
		}
	} 
}
void levelorder(node *root){
	int num=0;
	int id=0;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *now=q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		now->id=id++;
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
}
int main()
{
	scanf("%d",&n);
	node *root=NULL;
	int t;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		insert(root,t);
	}
	levelorder(root);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *now=q.front();
		q.pop();
		if(now->lchild!=NULL) {
			if(now->lchild->id!=now->id*2+1){
				iscomplete=0;
				break;
			}
			else q.push(now->lchild);	
		}
		if(now->rchild!=NULL){
			if(now->rchild->id!=now->id*2+2){
				iscomplete=0;
				break;
			} 
			else q.push(now->rchild);
		}
	} 
	if(iscomplete==1) printf("\nYES");
	else printf("\nNO");
	return 0;
 } 
