#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	for(int i=0;i<k;i++){             //�ж�k�� 
		bool flag=false;
		stack<int> s;
		vector<int> v(n+1);                
		for(int j=1;j<=n;j++)         //������ջ���� 
			scanf("%d",&v[j]);
		int now=1;
		for(int j=1;j<=n;j++){
			s.push(j);                //���ְ�˳����ջ1��2��3��....n 
			if(s.size()>m) break;     //ջ���������ܴ���m 
			while(!s.empty()&&s.top()==v[now]){    //����˳���ջʱ 
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
