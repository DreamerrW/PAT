#include<cstdio>
#include<vector>
#include<queue> 
#define maxv 1001
using namespace std;

vector<int> G[maxv];
bool vis[maxv];
int deep[maxv]; //ÿ��������� 

int n,l;
//�û��� 1~n ���   L����������
int k;  
//k������ѯ

void bfs(int v){
	int level=0;
	int ans=0;

	queue<int> q;
	q.push(v);     //�������
	vis[v]=true;
	//��������Ϊ0 ��ɸѡ ���Ϊ 1~l�Ľ�㼴Ϊ��� 
	while(!q.empty()){                        //����һ�ι�����ȱ��� 
		int top=q.front(); 
		if(deep[top]==l) break; 
		q.pop();                              //ͷ������ 
		for(int i=0;i<G[top].size();i++){
			if(vis[G[top][i]]==false){
				q.push(G[top][i]);           //�ӽ����� 
				deep[G[top][i]]=deep[top]+1; //�ӽ����ȼ�һ 
				vis[G[top][i]]=true;   
				ans++;        
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		if(deep[i]>=1&&deep[i]<=l)
			ans++;
	}*/
	printf("%d\n",ans);
}
int main()
{
	scanf("%d %d",&n,&l);
	int num,temp;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp);
			G[temp].push_back(i);
		}
	}
	scanf("%d",&k);
	int v;
	while(k--){
		fill(deep,deep+maxv,0); //��ʼ���Ϊ0 
		fill(vis,vis+maxv,false);
		scanf("%d",&v);
		bfs(v);
	}
	return 0;
 } 
