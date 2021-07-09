#include<cstdio>
#include<vector>
#include<algorithm>  
using namespace std;
//����dfs������ 
vector<vector<int>> v;   //������д��һά�Ǳ䳤��  
bool visit[10010]={false};
int maxdepth=0; 
void dfs(int n,int depth)
{
	if(depth>maxdepth) maxdepth=depth;
	visit[n]=true;
	for(int i=0;i<v[n].size();i++)
	{
		if(!visit[v[n][i]])
		dfs(v[n][i],depth+1);
	}
}
int main() 
{
	int n;
	int m=0;                     //������� 
	scanf("%d",&n);
	v.resize(n+1);
	vector<int> deep(n+1);     //����ÿ������������� 
	int temp1,temp2,cnt=0;
	for(int i=0;i<n-1;i++){    //�����ڽӱ� 
		scanf("%d %d",&temp1,&temp2);
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	} 
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			dfs(i,0);
			cnt++;
		}
	}
	if(cnt>1){
		printf("Error: %d components",cnt);
		return 0; 
	}
	for(int i=1;i<=n;i++){      //dfs n�Σ���ÿ�ε������ȼ�¼�� 
		maxdepth=0;
		fill(visit+1,visit+n+1,false);
		dfs(i,1);
		deep[i]=maxdepth; 
		if(maxdepth>m) m=maxdepth;
	}
	for(int i=1;i<=n;i++)
	{
		if(deep[i]==m)
		printf("%d\n",i);
	}
	return 0;  
}
