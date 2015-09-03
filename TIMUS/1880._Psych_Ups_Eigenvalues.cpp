#include<stdio.h>
int first[4000],second[4000],third[4000];
int a,b,c;
bool s(int a)
{
	bool q = false;
	for(int w = 0;w<b;w++)
		if(a == second[w])
		{
			q = true;
			second[w] = -1;
		}
	return q;
}
bool t(int a)
{
	bool q = false;
	for(int w = 0;w<c;w++)
		if(a == third[w])
		{
			q = true;
			third[w] = -1;
		}
	return q;
}
bool rec(int a)
{
	return (s(a)+t(a)==2);
}
int main()
{
	scanf("%d ",&a);
	for(int q = 0;q< a;q++)
	{
		int w;
		scanf("%d",&w);
		first[q] = w;
	}
	scanf("%d ",&b);
	for(int q = 0;q< b;q++)
	{
		int w;
		scanf("%d",&w);
		second[q] = w;
	}
	scanf("%d ",&c);
	for(int q = 0;q< c;q++)
	{
		int w;
		scanf("%d",&w);
		third[q] = w;
	}
	int res = 0;
	for(int q = 0;q<a;q++)
	{
		res += rec(first[q]);
		first[q] = -1;
	}
	printf("%d",res);
	return 0;
}
