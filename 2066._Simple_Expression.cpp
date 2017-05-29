#include <iostream>
#include <limits>
#define MAX std::numeric_limits<int>::max()
using namespace std;

int res = MAX;


void second(int a, int b) {
	if(a+b < res)
		res = a+b;
	if(a-b < res)
		res = a-b;
	if(b-a < res)
		res = b-a;
	if(b*a < res)
		res = b*a;
}


void first(int a, int b, int c) {
	second(a+b, c);
	second(a-b, c);
	second(a*b, c);
	second(b-a, c);
}

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	first(a,b,c);
	first(a,c,b);
	first(b,c,a);
	cout<<res;
}
