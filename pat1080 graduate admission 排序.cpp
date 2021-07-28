#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct info{
	int GE; //��ʼ�ɼ� 
	int GI; //���Գɼ� 
	int final;
	int rank;
	int id;
	vector<int> pref;  //־ԸѧУ 
}; 
vector<info> stu; 
bool cmp1(info a,info b){
	if(a.final!=b.final) return a.final>b.final;
	else return a.GE>b.GE;
}
bool cmp2(info a,info b){
	return a.id<b.id;
}
int main()
{ 
	int n;               //�ܵ������� 0~n-1 ��� 
	int m;              //ѧԺ��Ŀ   0~m-1
	int quota[101];       //ÿ��ѧԺ���������� 
	int cnt[101]={0};    //ÿ��ѧԺ�Ѿ��е������� 
	int k;              //־Ը��Ŀ   
	scanf("%d %d %d",&n,&m,&k);
	stu.resize(n);
	vector<info> ans[m];    //ÿ��ѧԺ�ҵ���ѧ��id 
	for(int i=0;i<m;i++)  //ÿ��ѧԺ���������� 
		scanf("%d",&quota[i]);
	
	for(int i=0;i<n;i++){
		scanf("%d %d",&stu[i].GE,&stu[i].GI);  //GE GI 
		stu[i].final=stu[i].GE+stu[i].GI;  //�ۺϳɼ� 
		stu[i].id=i;                          //ѧ����id 
		stu[i].pref.resize(k);
		for(int j=0;j<k;j++) //־Ը
			scanf("%d",&stu[i].pref[j]);  
	}
	sort(stu.begin(),stu.end(),cmp1);
	stu[0].rank=1;
	for(int i=1;i<n;i++){    //rank ���� 
		if(stu[i].final==stu[i-1].final&&stu[i].GE==stu[i-1].GE)
			stu[i].rank=stu[i-1].rank;
		else stu[i].rank=i+1;
	}
	
	for(int i=0;i<n;i++){      //¼ȡ���� 
		for(int j=0;j<k;j++){   //k��־Ը 
			if(cnt[stu[i].pref[j]]<quota[stu[i].pref[j]]){  //���¼ȡ����û�г��� 
				cnt[stu[i].pref[j]]++;
				ans[stu[i].pref[j]].push_back(stu[i]);break;
			}
			else if(cnt[stu[i].pref[j]]>=quota[stu[i].pref[j]]){  //���¼ȡ���������ˣ������µ��˵ĳɼ���ǰ����ǲ���һ�� 
				int a=ans[stu[i].pref[j]].size()-1;
				if(stu[i].rank==ans[stu[i].pref[j]][a].rank){
					cnt[stu[i].pref[j]]++;
					ans[stu[i].pref[j]].push_back(stu[i]);break;
				}	
			}
		}
	}
	for(int i=0;i<m;i++){
		sort(ans[i].begin(),ans[i].end(),cmp2);   //¼ȡ��ѧ��Ҫ��id������ 
		for(int j=0;j<ans[i].size();j++){
			if(j!=0) printf(" "); 
			printf("%d",ans[i][j].id);
		}
		printf("\n");
	}
	return 0;
}  
