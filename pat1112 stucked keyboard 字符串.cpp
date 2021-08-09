#include<iostream>
#include<map> 
#include<set>
using namespace std;
bool good[256]={false};
bool printed[256]={false};
set<char> ans;
set<char> ans1;
int main()
{
	int k; //重复k次就认为是坏键盘
	scanf("%d\n",&k);
	string s;
	getline(cin,s);
	s=s+'#';
	char pre=s[0];
	int cnt=1;
	for(int i=1;i<s.length();i++){
		if(s[i]==pre){
			cnt++;
		}
		else {
			if(cnt%k==0){  //坏键 
                ans.insert(pre);
            }
			else good[pre]=true;
			cnt=1;
        }
		pre=s[i];
	}
	for(auto it=ans.begin();it!=ans.end();it++){
		if(good[*it]==false){  //如果是坏键 
			ans1.insert(*it); 
		}
	}
	for(int i=0;i<s.length()-1;i++){     //按照被检测到的顺序输出 
		if(ans1.find(s[i])!=ans1.end()&&printed[s[i]]==false){
			printf("%c",s[i]);
			printed[s[i]]=true;
		}
	}
	printf("\n"); 
	for(int i=0;i<s.length()-1;i++){
		printf("%c",s[i]);
		if(ans1.find(s[i])!=ans1.end())  //如果是坏键盘 
			i=i+k-1;
	}
	return 0;
 } 
