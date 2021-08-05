#include<cstdio>
#include<map>
#include<algorithm> 
using namespace std;

map<int,int> mp;
int main()
{
	int data[100010],next[100010],result[100010],list[100010],list1[100010],list2[100010];
	int first;
	int n;
	scanf("%d %d",&first,&n);
	for(int i=0;i<n;i++){
		int addr;
		scanf("%d",&addr);
		scanf("%d %d",&data[addr],&next[addr]);
	}
	int sum=0;
	while(first!=-1){
		list[sum]=first;
		first=next[first];
		sum++;
	}
	int cnt1=0;
	int cnt2=0;
	for(int i=0;i<sum;i++){
		if(mp.find(abs(data[list[i]]))==mp.end()){ //没有过这个值 
			mp[abs(data[list[i]])]=1;	
			list1[cnt1]=list[i];
			cnt1++;
		}
		else{
			list2[cnt2]=list[i];
			cnt2++;
		}
	}
	for(int i=0;i<cnt1;i++){
		if(i==0)
			printf("%05d %d ",list1[i],data[list1[i]]);
		else printf("%05d\n%05d %d ",list1[i],list1[i],data[list1[i]]);
		if(i==cnt1-1)
			printf("-1");
	}
	printf("\n");
	for(int i=0;i<cnt2;i++){
		if(i==0)
			printf("%05d %d ",list2[i],data[list2[i]]);
		else printf("%05d\n%05d %d ",list2[i],list2[i],data[list2[i]]);
		if(i==cnt2-1) printf("-1");
	}
	return 0;
 } 
