#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	set<int> ans;
	int t;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if(t>0) ans.insert(t);
	}
	if(ans.size()==0){
		printf("1");
		return 0;
	}
	int i=1;
    int flag=1;
	for(auto it=ans.begin();it!=ans.end();it++){
		if(*it!=i){
			printf("%d",i);
            flag=0;
			break;
		}
		i++;
	}
    if(flag) printf("%d",i);
	return 0;
 } 
