#include<stdio.h>
#include<string.h>

typedef struct{
	char ID[16];
	char arrive[9];
	char leave[9];
}Student;

Student user[20];

int main()
{
	int m;
	scanf("%d",&m);
	int  max=0;
	int  min=0;
	for(int i=0;i<m;i++)
	{
		scanf("%s",user[i].ID);
		scanf("%s",user[i].arrive);
		scanf("%s",user[i].leave);
	}
	for(int i=0;i<m;i++)
	{
		if(strcmp(user[i].arrive,user[min].arrive)<0)
		min=i;
		if(strcmp(user[i].leave,user[max].leave)>0)
		max=i;
	}
	printf("%s ",user[min].ID);
	printf("%s",user[max].ID);
	return 0;	
} 
