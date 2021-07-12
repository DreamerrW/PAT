#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int idnumber=1;
map<string,int> stringtoint;     //������������ַ�����������ţ�����Ҫ����ת������ţ���ʼ���Ϊ1 
map<int,string> inttostring;
map<string,int> ans;

int k;                           //��ֵ�������ܹ���绰���������ֵ�ͱ��ж�Ϊ 
int e[2002][2002],weight[2002];  //��������ǧ���� 
bool vis[2002]={false};          //�����ʼ���������Ϊfalse 

int members=0;				  //��¼�����Ա 
int totalweight=0;            //�����ܹ���绰��ʱ�� 
int head;                     //�ڰ���ϴ� 

void dfs(int index)
{
	members++;            //ÿdfsһ�Σ����ó�Ա���� 
	vis[index]=true;
	if(weight[index]>weight[head]) head=index;
	
	for(int i=1;i<idnumber;i++)
	{
		if(e[index][i]!=0){	
			totalweight+=e[index][i];
			e[index][i]=e[i][index]=0;    //������ֻҪ��Ȩ������0��Ҫ��ӣ������ڼ���һ�κ�Ҫ���� 
			if(vis[i]==false)
				dfs(i);		
		}
	}
}

int change(string temp){
	if(stringtoint.find(temp)==stringtoint.end()){     //���뵱ǰ��Ա�Ҳ��� 
		stringtoint[temp]=idnumber;
		inttostring[idnumber]=temp;
		idnumber++;	
	}	
	return stringtoint[temp];
}

int main()
{
	fill(e[0],e[0]+2002*2002,0);   //��ʼ�߶�Ϊ0 
	int n;
	scanf("%d %d",&n,&k);
	string temp1,temp2;
	int c1,c2;
	int w;
	for(int i=0;i<n;i++){  //n��ͨ����¼
		cin>>temp1>>temp2;
		c1=change(temp1);
		c2=change(temp2);
		scanf("%d",&w);
		e[c2][c1]+=w;
		e[c1][c2]+=w;
		weight[c1]+=w;
		weight[c2]+=w;
	}
	
	for(int i=1;i<idnumber;i++){
		if(vis[i]==false){
			head=i;
			dfs(i);
		}
		if(members>2&&totalweight>k)
		ans[inttostring[head]]=members;
		
		members=0; 
		totalweight=0;
	} 
	
	printf("%d\n",ans.size());
	for(auto it=ans.begin();it!=ans.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
	
} 
