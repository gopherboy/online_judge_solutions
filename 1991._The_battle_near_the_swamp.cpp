#include <iostream>
using namespace std;

int main() {
	int unused = 0, survived = 0;
	int n, k;
	cin>>n>>k;
	for(int i = 1; i <= n; i++) {
		int inp;
		cin>>inp;
		if(inp > k)
			unused += inp - k;
		if(inp < k)
			survived += k  - inp;
	}
	cout<<unused<<' '<<survived;
}
