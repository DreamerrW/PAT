#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
//入栈的顺序是前序遍历，出栈的顺序是中序遍历  求后续遍历序列 
//这题它没说数字不重复，所以要注意可能重复 
using namespace std;
vector<int> pre,in,post,value;
void postorder(int preL,int preR,int inL,int inR){
	if(preL>preR) return;
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==pre[preL])
			break;                 //找到根在中序序列中的位置 
	int numleft=k-inL;       //左子树的结点个数 
	postorder(preL+1,preL+numleft,inL,k-1);
	postorder(preL+numleft+1,preR,k+1,inR);	
	post.push_back(pre[preL]);
}
int main()
{	
	int n;
	cin>>n;
	char str[5];
	stack<int> s;
	int i=0;     //入栈元素的序号  value用来存值 
	while(scanf("%s",str)!=EOF){
		if(str[1]=='u'){              //push
			int num;
			scanf("%d",&num);
			value.push_back(num);    //num是值 
			pre.push_back(i);        //push顺序是前序遍历 
			s.push(i);
			i++; 
		}else{                       //pop操作 
			in.push_back(s.top());   //中序序列 
			s.pop();     
		}
	}
	postorder(0,n-1,0,n-1);
	printf("%d",value[post[0]]);
	for(int j=1;j<n;j++)
		printf(" %d",value[post[j]]);
	return 0;
} 
	
