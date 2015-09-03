#include<cstdio>
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if((a*b-1)%2)
		printf("[:=[first]");
	else 
		printf("[second]=:]");
	return 0;
}
