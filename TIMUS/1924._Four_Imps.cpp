#include <cstdio>

int main() {
	int a;
	scanf("%d",&a);
	if(a%4 == 1 || a%4 == 2)
		printf("grimy");
	else
	printf("black");
	return 0;
}
