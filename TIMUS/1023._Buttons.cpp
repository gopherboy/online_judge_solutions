#include <iostream>
using namespace std;

//int findL(int k, int lTemp) {
//	if(lTemp >= k)
//		return 0;
//	if(k%(lTemp+1) == 0 && k/(lTemp+1) >= 2)
//		return lTemp;
//	return findL(k, lTemp + 1);
//}

int main() {
	int k;
	cin>> k;
	int l = 2;
	while(1) {
		if(l >=k){
			l = k-1;
			break;
		}
		if(k%(l+1) == 0 && k/(l+1) >= 2)
			break;
		l++;
	}
	cout<<l;
}
