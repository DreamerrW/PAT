#include<iostream>
#include<vector>
#include<algorithm> 
#include<map>
using namespace std;
vector<int> ans;
bool vis[100100]; //�����Ƿ��ù��� 
vector<int> have;
bool dif[100100];
int a[11][1001];
int kick[11];  //�Ƿ���� 
int main(){
	int n,m;
	int s1,s2;
	cin>>s1>>s2;  //��ʼ���������� 
	vis[s1]=vis[s2]=true; 
	dif[abs(s1-s2)]=true;
	have.push_back(s1);
	have.push_back(s2);
	cin>>n>>m;  //n���ˡ�m���غ�
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<m;i++){  //m�غ� 
		for(int j=0;j<n;j++){
			if(dif[a[j][i]]==true&&vis[a[j][i]]==false&&kick[j]==0){  //û����̭ ����������û���ù�����ǰ�����ֵĲ� 
				vis[a[j][i]]=true;
				for(auto it:have){
					dif[abs(it-a[j][i])]=true;
				}
				have.push_back(a[j][i]);
			}
			else{
				if(kick[j]==0){
					kick[j]=1;
					printf("Round #%d: %d is out.\n",i+1,j+1);	
				}
			}
		}
	}
	int flag=1;
	for(int i=0;i<n;i++){
		if(kick[i]==0){ //û����̭
			ans.push_back(i+1);
			flag=0; 
		} 
	}
	if(flag==0){
		printf("Winner(s):");
		for(auto i:ans)
			printf(" %d",i);
	}
	else printf("No winner.");
}
