#include<cstdio>
#include<cstring>
#define maxv 1002

int G[maxv][maxv]={0};  //�ڽӾ���
int visited[maxv];
int occupied;         //����ռ�ĳ��� 
int n;                //n������ 
void dfs(int index)
{
	visited[index]=1;
	for(int i=1;i<=n;i++)
	{
		if(G[index][i]==1)
		{
			if(!visited[i])
			dfs(i);
		}
	}
}

int main()
{
	int m,k;                             //n�����У�m��·��k����Ҫ���ĵĳ��� 
	int temp1,temp2;
	scanf("%d %d %d",&n,&m,&k);            //m����·
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&temp1,&temp2);
		G[temp1][temp2]=1;
		G[temp2][temp1]=1;
	}
	while(k--)
	{
		memset(visited,0,sizeof(visited));
		int cnt=0;
		scanf("%d",&occupied);
		visited[occupied]=1;               //�Ѿ���ռ�ĳ�������Ϊ�ѷ��� 
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
			dfs(i);
			cnt++;
			}
		
		}
		printf("%d\n",cnt-1);           //������·Ϊ��ͨ����������һ
	}
	return 0;		 
 } 
