#include<stdio.h>
int main()
{
	int a,b,c = 0,d;
	scanf("%d %d",&a,&d);
	b = d;
	while(b > 0)
	{
		int r;
		scanf("%d",&r);
		if(r+c<=a)
			c = 0;
		else
			c  = r + c -a;
		if(c < 0)
			c = 0;	
		b--;
	}
	printf("%d",c);
	return 0;
}
