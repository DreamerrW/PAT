#include<iostream>
#include<map>
#include<set>
using namespace std;
map<string,set<int>> ans;

int main()
{
	int n,k;   //ѧ��������γ�����
	scanf("%d %d",&n,&k);
	
	char name[4];
	int curseid,students;
	for(int i=0;i<k;i++){                   //k�ſγ���Ϣ¼�� 
		scanf("%d %d",&curseid,&students);  //�γ�id�͸ÿγ�ѧ������ 
		for(int j=0;j<students;j++){
			scanf("%s",name);
			ans[name].insert(curseid);      //������set����Ĭ���������Բ��ù���˳���� 
		} 
	}
	while(n>0){
		scanf("%s",name);
		printf("%s %d",name,ans[name].size());
		for(auto it=ans[name].begin();it!=ans[name].end();it++){
			printf(" %d",*it);
		}
		printf("\n");
		n--;
	}
	return 0;
 } 
