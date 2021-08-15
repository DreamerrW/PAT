#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> list;
vector<int> list1,list2,list3;
vector<int> ans;
int main()
{
	int data[100000],next[100000];
	int first;
	int n;
	int k;
	scanf("%d %d %d",&first,&n,&k);
	for(int i=0;i<n;i++){  //n¸ö½áµã 
		int taddr;
		scanf("%d",&taddr);
		scanf("%d %d",&data[taddr],&next[taddr]);
	}
	int sum=0;
	while(first!=-1){
		list.push_back(first);
		first=next[first];
	} 
	//printf("%d",list[0]);
	for(int i=0;i<list.size();i++){
		if(data[list[i]]<0)
			list1.push_back(list[i]);
		else if(data[list[i]]>=0&&data[list[i]]<=k)
			list2.push_back(list[i]);
		else 
			list3.push_back(list[i]);
	}
	ans.insert(ans.end(),list1.begin(),list1.end());
	ans.insert(ans.end(),list2.begin(),list2.end());
	ans.insert(ans.end(),list3.begin(),list3.end());
	for(int i=0;i<ans.size();i++){
		if(i==0)
			printf("%05d %d",ans[i],data[ans[i]]);
		else 
			printf(" %05d\n%05d %d",ans[i],ans[i],data[ans[i]]);
		if(i==ans.size()-1)	printf(" -1");
	}
	return 0;
 } 
