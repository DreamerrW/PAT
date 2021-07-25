#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath> 
using namespace std;
//二叉排序树的中序遍历序列满足是从小到大的序列*** 
vector<int> v;
vector<int> level;


void levelorder(int start,int end,int index){
	if(start>end) return ;
	int n=end-start+1;          //节点数
	int h=log(n+1)/log(2);      //log2(n+1)为此树高度-1
	int leave=n-(pow(2,h)-1);   //最后一层的结点数
	int root=start+(pow(2,h-1)-1)+min((int)pow(2,h-1),leave);  //左子树的结点个数 
	level[index]=v[root];       
	levelorder(start,root-1,2*index+1);  //由于下标从0开始，2*i+1为左结点，2*i+2为右孩子 
	levelorder(root+1,end,2*index+2); 
}

int main()
{
	int n;
	scanf("%d",&n);
	v.resize(n);
	level.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());   //得到中序遍历序列 
	levelorder(0,n-1,0);
	printf("%d",level[0]);
	for(int i=1;i<n;i++)
		printf(" %d",level[i]);
	return 0;
 } 
