#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	int Np,Ng;
	int score[1000],rank[1000];
	scanf("%d %d",&Np,&Ng);
	for(int i=0;i<Np;i++)
		scanf("%d",&score[i]);
	vector<int> order;
	int temp;
	for(int i=0;i<Np;i++){
		scanf("%d",&temp);
		order.push_back(temp);
	}
	
	for(int num=Np;num>1;){
		vector<int> next;
		for(int i=0;i<num;i+=Ng){
			//本组范围i~i+Ng-1 或i~num-1 
			int jinji=i;
			for(int j=i;j<i+Ng&&j<num;j++){
				if(score[order[j]]>score[order[jinji]])
					jinji=j;
			}
			next.push_back(order[jinji]);
			for(int j=i;j<i+Ng&&j<num;j++){
				if(j!=jinji)
				rank[order[j]]=num/Ng+(num%Ng?1:0)+1;   //组数+1 
			}			
		}
		order=next;
		num=order.size();
	} 
	rank[order[0]]=1;
	for(int i=0;i<Np;i++){
		printf("%d",rank[i]);
		if(i!=Np-1) printf(" "); 
	}
	return 0; 
}
