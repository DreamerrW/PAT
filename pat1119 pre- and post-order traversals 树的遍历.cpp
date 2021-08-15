#include<cstdio>
#include<vector>
using namespace std;
vector<int> in,pre,post;
bool unique=true;
void inorder(int preL,int preR,int postL,int postR){
	if(preL==preR){
		in.push_back(pre[preL]);
		return;
	}
	if(pre[preL]==post[postR]){  //
		int i;
		for(i=preL+1;i<=preR;i++)
			if(pre[i]==post[postR-1]) break;
		if(i-preL>1) //˵���������Һ��� �����ӵĽڵ�������1 
			inorder(preL+1,i-1,postL,postL+(i-preL-1)-1); //���� 
		else 
			unique=false;
		in.push_back(post[postR]); //�� 
		inorder(i,preR,postL+(i-1-preL),postR-1);  //�Һ��� 
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	pre.resize(n);
	post.resize(n);
	//ǰ��	
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]); 
	//���� 
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	inorder(0,n-1,0,n-1);
	if(unique==true) printf("Yes\n");
	else printf("No\n");
	for(int i=0;i<in.size();i++){
		if(i!=0) printf(" ");
		printf("%d",in[i]);
	}
	printf("\n");
	return 0;
 } 
