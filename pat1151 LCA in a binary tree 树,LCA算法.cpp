#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> pre;
vector<int> in; 
map<int,int> mp;
void lca(int inL,int inR,int preroot,int a,int b){
	if(inL>inR) return ; 
	int inroot=mp[pre[preroot]],ain=mp[a],bin=mp[b];  //ain是a在中序序列中的位置，bin是b在中序序列中的位置 
	if(ain<inroot&&bin<inroot) //lca在其左子树
		lca(inL,inroot-1,preroot+1,a,b);
	else if((ain<inroot&&bin>inroot)||(ain>inroot&&bin<inroot))
		printf("LCA of %d and %d is %d.\n",a,b,in[inroot]);
	else if(ain>inroot&&bin>inroot) //lca在其右子树
		lca(inroot+1,inR,preroot+1+(inroot-inL),a,b); 
	else if (ain==inroot)
 	printf("%d is an ancestor of %d.\n",a,b);
 	else if (bin==inroot)
 	printf("%d is an ancestor of %d.\n",b,a);
}
int main()
{
	int m,n; //m是待检测对数，n是结点数 
	cin>>m>>n;
	pre.resize(n+1);
	in.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>in[i];
		mp[in[i]]=i; //记录中序序列中该结点的位置 
	}
	for(int i=1;i<=n;i++)
		cin>>pre[i];
	while(m--){
		int a,b;
		cin>>a>>b;
		if(mp[a]==0&&mp[b]==0)
			printf("ERROR: %d and %d are not found.\n",a,b);
		else if(mp[a]==0||mp[b]==0)
			printf("ERROR: %d is not found.\n",mp[a]==0?a:b);
		else 
			lca(1,n,1,a,b);
	}
	return 0;
} 
