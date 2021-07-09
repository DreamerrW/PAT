#include<set>
#include<iostream>
#include<string> 
//#include<map>
#include<unordered_map>
using namespace std;
unordered_map<string,set<int>> title, author, key, pub, year;   //���������ַ�����Ӧid��ӳ��  
//����������map<string,vector<int> Ҳ���ԣ�����Ҫ��sort������id����   
void find(unordered_map<string,set<int>> m,string str)
{
	if(m.find(str)!=m.end()){
		for(auto it=m[str].begin();it!=m[str].end();it++)  //setֻ���õ��������� 
		printf("%07d\n",*it);
	}
	else cout<<"Not Found\n";
}
int main()
{
	int n;   //�����Ŀ
	int m;   //��ѯ���� 
	int id;
	string ttitle, tauthor, tkey, tpub, tyear;    //�������� 
	scanf("%d",&n);
	for(int i=0;i<n;i++){     //������������Ϣ 
		scanf("%d",&id);
		getchar();            //�������ջ��з� 
		getline(cin,ttitle);
		title[ttitle].insert(id);
		getline(cin,tauthor);
		author[tauthor].insert(id);
		while(cin>>tkey){
			key[tkey].insert(id);
			char c=getchar();
			if(c=='\n') break;
		}
		getline(cin,tpub);
		pub[tpub].insert(id);
		getline(cin,tyear);
		year[tyear].insert(id); 
	}
	scanf("%d",&m);
	int num;
	for(int i=0;i<m;i++){
		scanf("%d: ",&num);
		string temp;
		getline(cin,temp);
		cout<<num<<": "<<temp<<"\n";
		if(num==1) find(title,temp);
		else if(num==2) find(author,temp);
		else if(num==3) find(key,temp);
		else if(num==4) find(pub,temp);
		else if(num==5) find(year,temp);
	}
	return 0;
}
