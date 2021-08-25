#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<int> v;
map<int,int> pos;
int main()
{
	int n,m;
	cin>>n>>m;
	v.resize(n+1);
	for(int i=1;i<=n;i++){  //插入的方法构建大顶堆 
		cin>>v[i];	
		int j=i;
		while(j>1){
			if(v[j]>v[j/2]){
				swap(v[j],v[j/2]);	
				j=j/2;
			}
        	else break;
		}
	}
	for(int i=1;i<=n;i++)
		pos[v[i]]=i;     //记录各个结点的位置 
	getchar();
	string ans,s;
	while(m--){
		getline(cin,s);
		int a,b;
		if(s.find("root")!=s.npos){
			sscanf(s.c_str(),"%d is the root",&a);
			if(pos.find(a)==pos.end()) {
				ans+="0"; continue;
			}
			if(pos[a]==1) ans+="1";
			else ans+="0";
		}
		else if(s.find("siblings")!=s.npos){
			sscanf(s.c_str(),"%d and %d are siblings",&a,&b);
			if(pos.find(a)==pos.end()||pos.find(b)==pos.end()){
				ans+="0"; continue;
			}
		    if(pos[a]/2==pos[b]/2) ans+="1";
			else ans+="0";
		}
		else if(s.find("parent")!=s.npos){
			sscanf(s.c_str(),"%d is the parent of %d",&a,&b);
			if(pos.find(a)==pos.end()||pos.find(b)==pos.end()){
				ans+="0"; continue;
			}
			if(pos[b]/2==pos[a]) ans+="1";
			else ans+="0";
		}
		else if(s.find("left")!=s.npos){
			sscanf(s.c_str(),"%d is the left child of %d",&a,&b);
			if(pos.find(a)==pos.end()||pos.find(b)==pos.end()){
				ans+="0"; continue;
			}
			if(pos[a]==pos[b]*2) ans+="1";
			else ans+="0";
		}
		else if(s.find("right")!=s.npos){
			sscanf(s.c_str(),"%d is the right child of %d",&a,&b);
			if(pos.find(a)==pos.end()||pos.find(b)==pos.end()){
				ans+="0"; continue;
			}
			if(pos[a]==pos[b]*2+1) ans+="1";
			else ans+="0";
		}
	}
	printf("%s",ans.c_str());
	return 0;
}
