#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n, sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		sum+=i;
	cout<<sum;
}