#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int idnumber=1;
map<string,int> stringtoint;     //由于输入的是字符串而不是序号，所以要把它转换成序号，初始序号为1 
map<int,string> inttostring;
map<string,int> ans;

int k;                           //阈值，团体总共打电话超过这个阈值就被判定为 
int e[2002][2002],weight[2002];  //最多会有两千个人 
bool vis[2002]={false};          //顶点初始访问情况均为false 

int members=0;				  //记录团体成员 
int totalweight=0;            //团体总共打电话的时间 
int head;                     //黑帮的老大 

void dfs(int index)
{
	members++;            //每dfs一次，就让成员增加 
	vis[index]=true;
	if(weight[index]>weight[head]) head=index;
	
	for(int i=1;i<idnumber;i++)
	{
		if(e[index][i]!=0){	
			totalweight+=e[index][i];
			e[index][i]=e[i][index]=0;    //由于是只要边权不等于0就要相加，所以在加玩一次后要置零 
			if(vis[i]==false)
				dfs(i);		
		}
	}
}

int change(string temp){
	if(stringtoint.find(temp)==stringtoint.end()){     //加入当前成员找不到 
		stringtoint[temp]=idnumber;
		inttostring[idnumber]=temp;
		idnumber++;	
	}	
	return stringtoint[temp];
}

int main()
{
	fill(e[0],e[0]+2002*2002,0);   //初始边都为0 
	int n;
	scanf("%d %d",&n,&k);
	string temp1,temp2;
	int c1,c2;
	int w;
	for(int i=0;i<n;i++){  //n条通话记录
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
