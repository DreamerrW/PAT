#include<cstdio>
#include<queue>
using namespace std;
//三维的广度优先搜索 
int M,L,N,T;  //M*Nsize  L片  T边界
struct node{
	int x,y,z;
}; 
int arr[1300][130][70];    // x y z 
bool vis[1300][130][70]={false};
int X[6]={0,0,0,0,1,-1};
int Y[6]={0,0,1,-1,0,0};
int Z[6]={1,-1,0,0,0,0};
int ans=0;
int bfs(int x,int y,int z){
	int cnt=0;
	node temp;
	temp.x=x,temp.y=y,temp.z=z;
	queue<node> q;
	q.push(temp);
	vis[x][y][z]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<6;i++){
			int tx=top.x+X[i];
			int ty=top.y+Y[i];
			int tz=top.z+Z[i];
			if(tx>=0&&tx<M&&ty>=0&&ty<N&&tz>=0&&tz<L&&!vis[tx][ty][tz]&&arr[tx][ty][tz]==1){
				temp.x=tx,temp.y=ty,temp.z=tz;
				vis[tx][ty][tz]=true;
				q.push(temp);
			}
		}
	}
	if(cnt>=T)
		return cnt;
	else 
		return 0;
}
int main()
{
	scanf("%d %d %d %d",&M,&N,&L,&T);
	for(int i=0;i<L;i++)    
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++){
				scanf("%d",&arr[j][k][i]);
			}
	for(int i=0;i<L;i++)    
		for(int j=0;j<M;j++)
			for(int k=0;k<N;k++){
				if(!vis[j][k][i]&&arr[j][k][i]==1) ans+=bfs(j,k,i);
			}
	printf("%d",ans);
	return 0;
 } 
