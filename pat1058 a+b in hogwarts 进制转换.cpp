#include<cstdio>
using namespace std;
struct node{
	int galleon;
	int sickle;
	int knut;
};
int main(){
	node a,b,c;
	scanf("%d.%d.%d",&a.galleon,&a.sickle,&a.knut);	
	scanf("%d.%d.%d",&b.galleon,&b.sickle,&b.knut);
		
	int flag=0;
	c.knut=a.knut+b.knut;  //©ке╛ль
	if(c.knut>=29){
		c.knut-=29;
		flag=1;
	} 
	c.sickle=a.sickle+b.sickle+flag;
	flag=0;
	if(c.sickle>=17){
		c.sickle-=17;
		flag=1;
	}
	c.galleon=a.galleon+b.galleon+flag;
	
	printf("%d.%d.%d",c.galleon,c.sickle,c.knut);
	return 0;
} 
