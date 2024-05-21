#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
mt19937 mt(time(0));
uniform_int_distribution<int> dist1(3,20), dist2(3,20), dist3(3,20);    // 数据建议给小一点

int ran(int f)
{
    if(f==1)    return dist1(mt);
    if(f==2)    return dist2(mt);
    if(f==3)    return dist3(mt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<ran(1)<<endl;
}