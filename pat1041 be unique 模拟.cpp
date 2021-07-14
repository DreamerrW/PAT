#include<cstdio>
#include<unordered_map>
#include<vector>
using namespace std;
int main()
{
	unordered_map<int,int> mp;
	int n;
	scanf("%d",&n);
	int temp;
	vector<int> temp1;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		temp1.push_back(temp);
		auto it=mp.find(temp); 
		if(it==mp.end())   //ÈôÃ»ÕÒµ½ 
			mp[temp]=0;
		else 
			mp[temp]=1;
	}
	int flag=0;
	for(int i=0;i<temp1.size();i++){
		if(mp[temp1[i]]==0){
			printf("%d",temp1[i]);
			flag=1;
			break;
		}
	}
	if(flag==0)  printf("None");
	return 0;
 } 
