#include<cstdio>
int arr[1000];
int count;
int main()
{
	scanf("%d",&count);
	scanf("%d",&arr[0]);
	int maxval;
	int maxpoint;
	for(int q = 1;q< count;q++)
		scanf("%d",&arr[q]);
	maxval = arr[0]+arr[1]+arr[2];
	maxpoint = 2;
	for(int a =2;a<count -1;a++)
	{
		if(arr[a-1]+arr[a]+arr[a+1]> maxval)
		{
			maxval = arr[a-1]+arr[a]+arr[a+1];
			maxpoint = a+1;
		}
	}
	printf("%d %d",maxval,maxpoint);
	return 0;
}
