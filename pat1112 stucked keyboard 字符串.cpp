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
	int k; //�ظ�k�ξ���Ϊ�ǻ�����
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
			if(cnt%k==0){  //���� 
                ans.insert(pre);
            }
			else good[pre]=true;
			cnt=1;
        }
		pre=s[i];
	}
	for(auto it=ans.begin();it!=ans.end();it++){
		if(good[*it]==false){  //����ǻ��� 
			ans1.insert(*it); 
		}
	}
	for(int i=0;i<s.length()-1;i++){     //���ձ���⵽��˳����� 
		if(ans1.find(s[i])!=ans1.end()&&printed[s[i]]==false){
			printf("%c",s[i]);
			printed[s[i]]=true;
		}
	}
	printf("\n"); 
	for(int i=0;i<s.length()-1;i++){
		printf("%c",s[i]);
		if(ans1.find(s[i])!=ans1.end())  //����ǻ����� 
			i=i+k-1;
	}
	return 0;
 } 
