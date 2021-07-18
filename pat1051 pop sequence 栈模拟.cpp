#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	for(int i=0;i<k;i++){             //判断k次 
		bool flag=false;
		stack<int> s;
		vector<int> v(n+1);                
		for(int j=1;j<=n;j++)         //给出出栈队列 
			scanf("%d",&v[j]);
		int now=1;
		for(int j=1;j<=n;j++){
			s.push(j);                //数字按顺序入栈1、2、3、....n 
			if(s.size()>m) break;     //栈的容量不能大于m 
			while(!s.empty()&&s.top()==v[now]){    //当能顺序出栈时 
				s.pop();
				now++;
			}
		}	
		if(now==n+1) flag=true; 
 		if(flag) printf("YES\n");
 		else printf("NO\n");
	}
	return 0;
}
