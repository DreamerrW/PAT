#include<cstdio>
#include<vector>
#include<cstring> 
#define maxv 1003
using namespace std;
//���⼴Ϊ���⸱ͼ����ͨ����������cnt����ͨ������Ҫcnt-1��·������
 
vector<int> G[maxv];  //vectorʵ���ڽӱ� 
int visited[maxv];    //�жϸö����Ƿ���ʹ� 
int occupied;         //����ռ�ĳ��� 

void dfs(int number)  //dfs���� 
{
	visited[number]=1;
	for(int i=0;i<G[number].size();i++)
	{
		if(!visited[G[number][i]])
		{
		//	visited[G[number][i]]=1;
			dfs(G[number][i]);
		}	
	}
}
 
int main()
{
	int n,m,k;
	int temp1,temp2;
	scanf("%d %d %d",&n,&m,&k);            //m����·
	for(int i=0;i<m;i++)                   //m���ɹ�·���ӵĳ��� 
	{
		scanf("%d %d",&temp1,&temp2);
		G[temp1].push_back(temp2);         //��ȫ�ڽӱ� 
		G[temp2].push_back(temp1);
	} 
	while(k--)
	{
		memset(visited,0,sizeof(visited)); //����vis����ȫΪ0 
		int count=0;
		scanf("%d",&occupied);
		visited[occupied]=1;               //�Ѿ���ռ�ĳ�������Ϊ�ѷ��� 
		for(int i=1;i<=n;i++)
		{
			if(!visited[i]){
			dfs(i);
			count++;		        	  //��¼��ͨ�������� 
			}
		}
		printf("%d\n",count-1);           //������·Ϊ��ͨ����������һ 
	}
	return 0;		 	
} 
