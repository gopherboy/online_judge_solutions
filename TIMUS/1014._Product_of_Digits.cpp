#include <cstdio>
int main()
{
	int a;
	int digits[10]={0};
	scanf("%d",&a);
	if(a==0)
	{
		printf("10");
		return 0;
	}
	if(a==1)
	{
		printf("1");
		return 0;
	}
	for(int r = 9;r>=2;r--)
	{
		while(a%r == 0 && a!=1)
		{
			//printf("%d\t\t%d\n",a,r);
			digits[r]++;
			a = a/r;
		}
	}
	if(a!=1)
	{
		printf("-1");
		return 0;
	}
	for(int p = 2;p<=9;p++)
	{
		for(int o = 0;o<digits[p];o++)
			printf("%d",p);
	}
	return 0;
}
