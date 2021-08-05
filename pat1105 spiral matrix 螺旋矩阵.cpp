#include<cstdio>
#include<cmath>
#include<algorithm> 
#include<vector>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int N;
	int m,n; //   mxn=M
	scanf("%d",&N);
	vector<int> a(N);
	for(int i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=sqrt(N);i++){
		if(N%i==0){
			n=i;	
		}
	}
	m=N/n;     //得到矩阵的边长
	sort(a.begin(),a.end(),cmp);
	int b[m][n];
	int level=m/2+m%2;
	int t=0;
	for(int i=0;i<level;i++){
		for(int j=i;j<n-i&&t<N;j++)
			b[i][j]=a[t++];
		for(int j=i+1;j<m-1-i&&t<N;j++)
			b[j][n-1-i]=a[t++];
		for(int j=n-1-i;j>=i&&t<N;j--)
			b[m-1-i][j]=a[t++];
		for(int j=m-2-i;j>i&&t<N;j--)
			b[j][i]=a[t++];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",b[i][j]);
			if(j!=n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
 } 
