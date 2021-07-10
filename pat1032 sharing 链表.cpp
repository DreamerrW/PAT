#include<cstdio>
#include<map> 
using namespace std;
struct node{
	char data;
	int next;
	int flag;
}tempnode;

int main()
{
	map<int,node> mp;    //建立一个int到node的映射 
	int addr1,addr2;
	int m;
	scanf("%d %d %d",&addr1,&addr2,&m);
		
	int tempaddr;
	for(int i=0;i<m;i++){
		scanf("%d",&tempaddr);
		scanf(" %c %d",&tempnode.data,&tempnode.next);   //注意：scanf %c是会读入空格的，所以要加一个空格 
		tempnode.flag=0;
		mp[tempaddr]=tempnode;
	}
	
	while(addr1!=-1){
		mp[addr1].flag=1;
		addr1=mp[addr1].next;
	}
	while(addr2!=-1){
		if(mp[addr2].flag==1){
			printf("%05d",addr2);
			break;
		}
		addr2=mp[addr2].next;
	}
	if(addr2==-1)
	printf("-1");
	return 0;	
} 
