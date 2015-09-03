#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	double ans[1024*128] = {0};
	unsigned long long a;
	int y = 0;
	while (scanf("%llu", &a) != EOF)
		ans[y++] = sqrt(a);
	for (; --y >= 0; )
		printf("%.4lf\n", ans[y]);
	return 0;
}
