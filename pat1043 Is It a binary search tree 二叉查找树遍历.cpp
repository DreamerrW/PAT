#include<cstdio>
#include<vector>
using namespace std;
struct node{
	int data;               //������ 
	node *left,*right;      //ָ���� 
};
vector<int> origin,pre,preM,post,postM;
void insert(node * &root,int temp){
	if(root==NULL){
		root = new node;
		root->data=temp;
		root->left=root->right=NULL;
		return;
	}
	if(temp<root->data) insert(root->left,temp);  //����������
	else insert(root->right,temp);
	return; 
} 
void preorder(node *root){        //����������� 
	if(root==NULL) return;
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}
void preordermirror(node* root){ //����������������� 
	if(root==NULL) return;
	preM.push_back(root->data);
	preordermirror(root->right);
	preordermirror(root->left);
}
void postorder(node *root){     //������������ 
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	post.push_back(root->data);
}
void postordermirror(node *root){ //������������������ 
	if(root==NULL) return;
	postordermirror(root->right);
	postordermirror(root->left);
	postM.push_back(root->data);
}
int main()
{
	int n;
	scanf("%d",&n); //n�����
	int temp;
	node *root=NULL; //����� 
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		origin.push_back(temp);  //��¼��ʼ���У� 
		insert(root,temp);   //����BST 
	}
	preorder(root);
	preordermirror(root);
	postorder(root);
	postordermirror(root);
	if(origin==pre){         //������������о�������˳�� 
		printf("YES\n");
		for(int i=0;i<post.size();i++){
			printf("%d",post[i]);
			if(i!=post.size()-1)  printf(" ");
		}
	}
	else if(origin==preM){  //�������������������������˳�� 
		printf("YES\n"); 
		for(int i=0;i<postM.size();i++){
			printf("%d",postM[i]);
			if(i!=postM.size()-1)  printf(" ");
		}
	}
	else 
	printf("NO\n");
	return 0;
 } 
