#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> in;
vector<int> level;
struct node{
	int data;
	node *l,*r;
};
node *create(int inL,int inR){
	if(inL>inR) return NULL; 
	node *root=new node;
	int k;
	int min=99999;
	for(int i=inL;i<=inR;i++){
		if(in[i]<min){
			k=i;
			min=in[i];
		} 
	}
	root->data=min;
	root->l=create(inL,k-1);
	root->r=create(k+1,inR);
	return root;
}
int main()
{
	int n;
	cin>>n;
	in.resize(n);
	node *root=NULL;
	for(int i=0;i<n;i++)
		cin>>in[i];
	root=create(0,n-1);
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *top=q.front();
		q.pop();
		level.push_back(top->data);
		if(top->l!=NULL) q.push(top->l);
		if(top->r!=NULL) q.push(top->r);
	} 
	for(int i=0;i<level.size();i++){
		if(i!=0) printf(" ");
		printf("%d",level[i]);
	}
	return 0;
}
