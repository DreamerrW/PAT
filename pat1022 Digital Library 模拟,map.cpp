#include<set>
#include<iostream>
#include<string> 
//#include<map>
#include<unordered_map>
using namespace std;
unordered_map<string,set<int>> title, author, key, pub, year;   //建立各个字符串对应id的映射  
//若是这里用map<string,vector<int> 也可以，但是要用sort函数对id排序   
void find(unordered_map<string,set<int>> m,string str)
{
	if(m.find(str)!=m.end()){
		for(auto it=m[str].begin();it!=m[str].end();it++)  //set只能用迭代器访问 
		printf("%07d\n",*it);
	}
	else cout<<"Not Found\n";
}
int main()
{
	int n;   //书的数目
	int m;   //查询次数 
	int id;
	string ttitle, tauthor, tkey, tpub, tyear;    //辅助变量 
	scanf("%d",&n);
	for(int i=0;i<n;i++){     //输入各个书的信息 
		scanf("%d",&id);
		getchar();            //用于吸收换行符 
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
