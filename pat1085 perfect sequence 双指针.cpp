#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	long long p;
	scanf("%d %lld",&n,&p);
	vector<int> ans(n);
	for(int i=0;i<n;i++)
		cin>>ans[i];
	sort(ans.begin(),ans.end());    //按升序排序 

	int maxsize=0;              //初始时长度为0 
	int tempmaxsize;         
	for(int i=0;i<n;i++){
		int min=i;
		int max=i+maxsize;
		for(int j=max;j<n;j++){
			if(ans[max]<=ans[min]*p){
				max++;
				tempmaxsize=max-min;
			}
			else break;
		}
		if(tempmaxsize>maxsize)
			maxsize=tempmaxsize;	
	}
	cout<<maxsize;
	return 0;
 } 
