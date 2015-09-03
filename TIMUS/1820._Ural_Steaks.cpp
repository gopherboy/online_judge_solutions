#include<stdio.h>
#include<math.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%d",n <= k? 2 : (2*n + k - 1) / k);
	return 0;
}
