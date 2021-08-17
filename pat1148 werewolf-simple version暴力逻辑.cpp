#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int v[110];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=n;i++){      
		for(int j=i+1;j<=n;j++){  	//假定i和j是狼人  穷举法 
			vector<int> lie,a(n+1,1);
			a[i]=a[j]=-1;
			for(int k=1;k<=n;k++)
				if(v[k]*a[abs(v[k])]<0) lie.push_back(k);  //说的情况和实际情况不同 
			if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0){    //如果刚好有两个人说谎并且一个好人一个狼人 
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<"No Solution";
}
