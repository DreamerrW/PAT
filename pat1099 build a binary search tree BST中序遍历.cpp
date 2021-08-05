#include<cstdio>
#include<algorithm>
#include<queue>
//�Ƚ���������������ö��н���bfs 
using namespace std;
int n;         //������ 
struct node{
	int data;
	int l,r; //���Һ���
	int level; 
}a[101];
int b[101];
int t=0;
void inorder(int root){
	if(root>=n) return;
	if(a[root].l!=-1) inorder(a[root].l);
	a[root].data=b[t++];
	if(a[root].r!=-1) inorder(a[root].r);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)	
		scanf("%d %d",&a[i].l,&a[i].r);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(b,b+n);
	inorder(0);
	queue<node> q;
	a[0].level=1;
	q.push(a[0]); //���ڵ����
	int flag=1;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		if(flag==1) flag=0;
		else printf(" "); //����ո� 
		printf("%d",top.data);
		if(top.l!=-1)
			q.push(a[top.l]);
		if(top.r!=-1)
			q.push(a[top.r]);
	}
	return 0; 
	
 } 
