#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> in,pre;
vector<int> level;
struct node{
	int data;
	int layer;
	node *lchild,*rchild;
};
bool vis[21];
node *create(int preL,int preR,int inL,int inR){
	if(preL>preR) return NULL;
	node* root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL])
		break; 
	}
	int numleft=k-inL;
	root->lchild=create(preL+1,preL+numleft,inL,k-1);
	root->rchild=create(preL+numleft+1,preR,k+1,inR);
	return root;
}
int main()
{
	node* root=NULL;
	int n;
	cin>>n;
	in.resize(n);
	pre.resize(n);
	level.resize(n);
	
	for(int i=0;i<n;i++)
		cin>>in[i];
	for(int i=0;i<n;i++)
		cin>>pre[i];
		
	root=create(0,n-1,0,n-1);
	queue<node*> q;
	root->layer=1;
	q.push(root);
	int num=0;
	while(!q.empty()){
		node *top=q.front();
		q.pop();
		if(vis[top->layer]==false) {
			level[num++]=top->data;	
			vis[top->layer]=true;
		}
		if(top->lchild!=NULL) {
			top->lchild->layer=top->layer+1;
			q.push(top->lchild);	
		}
		if(top->rchild!=NULL){
			top->rchild->layer=top->layer+1;
		 	q.push(top->rchild); 
		}
	}
	
	for(int j=0;j<num;j++){
		if(j!=0) printf(" ");
		printf("%d",level[j]);
	}
	return 0;
 } 
