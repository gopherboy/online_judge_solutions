#include <stdio.h>
int first[100000]={0};
int second[100000]={0};
int count;
int dp(int cle,int c)
{
	int max = 0;
	for(int q = c+1;q<count;q++)
	{
		if(first[q]<=cle)
			continue;
		int m = dp(second[q],q);
		if(m>max)
			max = m;
	}
	return max+1*(cle!= -1);
}
int main()
{
	scanf("%d",&count);
	for(int aq = 0;aq<count;aq++)
		scanf("%d %d",&first[aq],&second[aq]);
	for(int a = 0;a<count;a++)
		for(int b =0;b<count-1;b++)
		{
			if(first[b]>first[b+1])
			{
				first[b] += first[b+1];
				first[b+1] = first[b]-first[b+1];
				first[b] -= first[b+1];
				second[b] += second[b+1];
				second[b+1] = second[b]-second[b+1];
				second[b] -= second[b+1];
				
			}
		}
	printf("%d",dp(-1,-1));
	return 0;
}
