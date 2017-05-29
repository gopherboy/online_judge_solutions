#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, count = 2;
	cin>>n;
	for(int i = 1; i <= n; i++) {
		string query;
		cin>>query;
		if(query.length() >= 4 && query.substr(query.length() - 4, 4) == "+one")
			count += 2;
		else
			count++;
	}
	if(count == 13)
		count++;
	cout<<count * 100;
}
