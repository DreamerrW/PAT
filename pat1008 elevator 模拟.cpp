#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int pastfloor=0;
	int nowfloor;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&nowfloor);
		if(nowfloor>pastfloor)
		{
			ans=ans+(nowfloor-pastfloor)*6+5;
		}
		else 
		{
			ans=ans+(pastfloor-nowfloor)*4+5;
		}
		pastfloor=nowfloor;
	}
	printf("%d",ans);
	return 0;
	
 } 
