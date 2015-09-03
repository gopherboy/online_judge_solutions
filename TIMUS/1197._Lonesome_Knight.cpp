#include<iostream>
using namespace std;
int res(int a,int b)
{
	int r = 0;
	if((a-2)<9&&(a-2)>0&&(b-1)<9&&(b-1)>0)
		r++;
	if((a-2)<9&&(a-2)>0&&(b+1)<9&&(b+1)>0)
		r++;
	if((a-1)<9&&(a-1)>0&&(b-2)<9&&(b-2)>0)
		r++;
	if((a-1)<9&&(a-1)>0&&(b+2)<9&&(b+2)>0)
		r++;
	if((a+2)<9&&(a+2)>0&&(b-1)<9&&(b-1)>0)
		r++;
	if((a+2)<9&&(a+2)>0&&(b+1)<9&&(b+1)>0)
		r++;
	if((a+1)<9&&(a+1)>0&&(b-2)<9&&(b-2)>0)
		r++;
	if((a+1)<9&&(a+1)>0&&(b+2)<9&&(b+2)>0)
		r++;
	return r;
}
int main()
{
	int a;
	cin>>a;
	while(a)
	{
		int z;
		char c;
		cin>>c>>z;
		cout<<res((int)c-'a'+1,z)<<endl;
		a--;
	}
	return 0;
}
