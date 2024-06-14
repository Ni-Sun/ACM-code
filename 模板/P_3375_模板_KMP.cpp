#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string a,b;     // a是目标串, b是模式串
    cin>>a>>b;
    a=' '+a;
    b=' '+b;
    int n=b.length()-1;
    vector<int> ne(n+1);    // ne数组从ne[1]开始用,ne[0]没用
    int i,j,t;
    for(i=2,j=0;i<=n;i++)
    {
        while(j && b[i]!=b[j+1])
            j=ne[j];
        if(b[i]==b[j+1])
            j++;
        ne[i]=j;
    }

    for(i=1,j=0;i<a.length();i++)
    {
        while(j && a[i]!=b[j+1])
            j=ne[j];
        if(a[i]==b[j+1])
            j++;
        if(j==n)        // 匹配成功
            cout<<i-n+1<<endl;
    }

    for(i=1;i<=n;i++)
        cout<<ne[i]<<' ';
}