#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
//��ջ��˳����ǰ���������ջ��˳�����������  ������������� 
//������û˵���ֲ��ظ�������Ҫע������ظ� 
using namespace std;
vector<int> pre,in,post,value;
void postorder(int preL,int preR,int inL,int inR){
	if(preL>preR) return;
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==pre[preL])
			break;                 //�ҵ��������������е�λ�� 
	int numleft=k-inL;       //�������Ľ����� 
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
	int i=0;     //��ջԪ�ص����  value������ֵ 
	while(scanf("%s",str)!=EOF){
		if(str[1]=='u'){              //push
			int num;
			scanf("%d",&num);
			value.push_back(num);    //num��ֵ 
			pre.push_back(i);        //push˳����ǰ����� 
			s.push(i);
			i++; 
		}else{                       //pop���� 
			in.push_back(s.top());   //�������� 
			s.pop();     
		}
	}
	postorder(0,n-1,0,n-1);
	printf("%d",value[post[0]]);
	for(int j=1;j<n;j++)
		printf(" %d",value[post[j]]);
	return 0;
} 
	
