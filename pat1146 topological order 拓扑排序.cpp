#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
int main()
{
	int n,m;
	cin>>n>>m;
	//�����1~N
	vector<int> e[1010];
	int in[1010];  //ÿ���������
	fill(in,in+1010,0); 
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		e[a].push_back(b); //����� 
		in[b]++; //��ȼ�һ 
	}
	int k;
	cin>>k;
	int temp;
	for(int i=0;i<k;i++){  //k���ж϶��� 
		int judge=1;
		vector<int> tin(in,in+n+1);  //��in��������ʼ��tin 
		for(int j=0;j<n;j++){
			cin>>temp;
			if(judge==1){
				if(tin[temp]!=0){
					ans.push_back(i); //������������
					judge=0; 
				}	
				else{
					for(int k=0;k<e[temp].size();k++)
						tin[e[temp][k]]--;   //ɾ���� 
				}
			}
		} 
	}
	for(int i=0;i<ans.size();i++){
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	} 
	return 0;
 } 
