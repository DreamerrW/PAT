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
	map<int,node> mp;    //����һ��int��node��ӳ�� 
	int addr1,addr2;
	int m;
	scanf("%d %d %d",&addr1,&addr2,&m);
		
	int tempaddr;
	for(int i=0;i<m;i++){
		scanf("%d",&tempaddr);
		scanf(" %c %d",&tempnode.data,&tempnode.next);   //ע�⣺scanf %c�ǻ����ո�ģ�����Ҫ��һ���ո� 
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
