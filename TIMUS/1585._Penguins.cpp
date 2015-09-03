#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int count;
	int e= 0,l=0,m=0;
	scanf("%d",&count);
	for(int q = 0;q<= count;q++)
	{
		string w;
		getline(cin,w);
		if(w[0] == 'E')
			e++;
		if(w[0] == 'L')
			l++;
		if(w[0] == 'M')
			m++;
	}
	if(e>l&&e>m)
		printf("Emperor Penguin");
	else if(l>e&&l>m)
		printf("Little Penguin");
	else
		printf("Macaroni Penguin");
	return 0;
}
