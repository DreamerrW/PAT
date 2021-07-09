#include<stdio.h>

int main()
{
	float a[3][3];       
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		scanf("%f",&a[i][j]);
	}	
	int f[3]={0};
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]>a[i][f[i]])
			f[i]=j;
		}
	}
	
	for(int i=0;i<3;i++)
	{
		switch(f[i])
		{
			case 0: printf("W ");break;
			case 1: printf("T ");break;
			case 2: printf("L ");break; 
		}
	}
	printf("%.2f",(a[0][f[0]]*a[1][f[1]]*a[2][f[2]]*0.65-1)*2);
	return 0;
} 
