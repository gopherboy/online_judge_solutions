#include<cstdio>
#define INT long long
INT pb[46] = {0};
INT pnb[46] = {0};
INT isntBlue(int);
INT isBlue(int a)
{
	if(a<=1)
		return 1;
	if(pnb[a-1] == 0)
		pnb[a-1] = isntBlue(a-1);
	return pnb[a-1];
}
INT isntBlue(int a)
{
	if(a<=1)
		return 1;
	if(pnb[a-1] == 0)
		pnb[a-1] = isntBlue(a-1);
	if(pb[a-1] == 0)
		pb[a-1] = isBlue(a-1);
	return pb[a-1]+pnb[a-1];	
}
INT dp(int a)
{
	if(a>0)
		return 2*isBlue(a-1)+2*isntBlue(a-1);
	return 1;
}
int main()
{
	int aa;
	scanf("%d",&aa);
	if(aa != 1 && aa != 2)
		printf("%lld",dp(aa-1));
	else
		printf("2");
	return 0;
}
