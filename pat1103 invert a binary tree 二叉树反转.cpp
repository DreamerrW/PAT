#include<cstdio>
#include<cctype>
#include<queue>
using namespace std;
//����������ҽ����û�г��ֵĽ�� 
struct node{
	int l,r;
	int id;
	int level;
}a[11]; 
int b[11]={0};  
int first=1;
void inorder(int root){
	if(a[root].l!=-1) inorder(a[root].l); 
	if(first==1) first=0;
	else printf(" ");
	printf("%d",a[root].id);
	if(a[root].r!=-1) inorder(a[root].r); 
}
int main()
{
	int n; //������
	scanf("%d",&n);
	// 0 ~n-1 ���
	for(int i=0;i<n;i++){
		char tl,tr;
		a[i].id=i;
		getchar();  //���ջ��з�= 
		scanf("%c %c",&tr,&tl);
		if(tr!='-'){
			a[i].r=tr-'0';
			b[a[i].r]=1;	
		}
		else a[i].r=-1;
		if(tl!='-'){
			a[i].l=tl-'0';
			b[a[i].l]=1;	
		}
		else a[i].l=-1;
	}
	int root=0;
	for(int i=0;i<n;i++)
		if(b[i]==0) root=i;
	//������� 
	queue<node> q;
	q.push(a[root]);
	int flag=1;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		if(flag==1) flag=0;
		else printf(" ");
		printf("%d",top.id);
		if(top.l!=-1) q.push(a[top.l]);
		if(top.r!=-1) q.push(a[top.r]);
	}
	printf("\n");
	inorder(root); //������� 
	return 0;
 } 
