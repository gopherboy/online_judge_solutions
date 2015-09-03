#include<stdio.h>
int main()
{
	short int a,b;
	scanf("%hd %hd",&a,&b);
	if((!(a%2))||(b%2))
		printf("yes");
	else
		printf("no");
	return 0;
}
