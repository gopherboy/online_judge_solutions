#include<iostream>
#include<vector>
using namespace std;
vector<int>first;
vector<int>g1;
vector<int>g2;
int totalCount;
int main()
{
	first.resize(20,0);
	g1.resize(20,0);
	g2.resize(20,0);
	cin>>totalCount;
	for(int a = 0;a<totalCount;a++)
	{
		int que;
		cin>>que;
		for(int b = 0;a<totalCount;a++)
		{
			if(first[b] == 0 || first[b+1]>que)
				first.push(que,b);
		}
	}
	for(int a = 0;a<totalCount;a++)
		cout<<first[a]<<endl;
	return 0;
}
