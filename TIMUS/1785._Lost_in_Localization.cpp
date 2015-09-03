#include<stdio.h>
using namespace std;
int main(){
	int a;
	scanf("%d",&a);
	if(a >= 1 && a <= 4)
		printf("%s","few");
	else if(a >= 5 && a <= 9)
		printf("%s","several");
	else if(a >= 10 && a <= 19)
		printf("%s","pack");
	else if(a >= 20 && a <= 49)
		printf("%s","lots");
	else if(a >= 50 && a <= 99)
		printf("%s","horde");
	else if(a >= 100 && a <= 249)
		printf("%s","throng");
	else if(a >= 250 && a <= 499)
		printf("%s","swarm");
	else if(a >= 500 && a <= 999)
		printf("%s","zounds");
	else if(a >= 1000)
		printf("%s","legion");

	return 0;
}
