// 字符串哈希+最长回文串
// 自然溢出
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
int n;
const ull P=131;
vector<ull> h1,h2,p;

ull geth(int l, int r, int f)   // 1<=l<=r<=n
{
    if(f==1) return (h1[r]-h1[l-1]*p[r-l+1]);
    else     return (h2[r]-h2[l-1]*p[r-l+1]);
}

bool OK(int m)
{
    int i;
    for(i=1;i+m-1<=n;i++)
        if(geth(i,i+m-1,1)==geth(n-i-m+2,n-i+1,2))
            return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string str;
    getline(cin,str);
    n=str.length();
    str=' '+str;
    int i,j;
    h1.resize(n+1),h2.resize(n+1),p.resize(n+1);
    p[0]=1;
    for(i=1;i<=n;i++)
    {
        h1[i]=h1[i-1]*P+ull(str[i]);        // 下标范围 [1,n]
        h2[i]=h2[i-1]*P+ull(str[n-i+1]);
        p[i]=p[i-1]*P;
    }

    int l=0,r=n+1,mid;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(OK(mid+1))       l=mid+1;
        else if(OK(mid))    l=mid;
        else                r=mid;
    }
    cout<<l;
}





/*------------------------------------------------------------------------------------*/
// 双哈希
// 题目链接 https://oj.swjtu.edu.cn/p/SWJTU0061
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define endl '\n'
ll mod[]={ll(1e9)+7,ll(1e9)+9};     // 类型转换
const ll P=131;
const ll N=3e6+10;
vector<ll> h[2],p[2];

pll geth(int l, int r)
{
    ll res[2];
    for(int i=0;i<2;i++)
    {
        res[i]=((h[i][r]-h[i][l-1]*p[i][r-l+1])%mod[i]+mod[i])%mod[i];
        // res[i]=(h[i][r]-h[i][l-1]*p[i][r-l+1]%mod[i]+mod[i])%mod[i];     // another version
    }
    return make_pair(res[0],res[1]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    string a,b;
    cin>>n>>a>>m;
    a=' '+a;
    int i,j,k;
    for(i=0;i<2;i++)
    {
        h[i].resize(N);
        p[i].resize(N);
    }
    p[0][0]=p[1][0]=1;
    for(i=1;i<=N;i++)
        for(j=0;j<2;j++)
        {
            p[j][i]=(p[j][i-1]*P)%mod[j];
        }
    pll ans={0,0};      // [1,n]
    auto &[x,y]=ans;
    for(i=1;i<=n;i++)
    {
        x=(x*P+a[i])%mod[0];
        y=(y*P+a[i])%mod[1];
    }

    while(m--)
    {
        int f=0;
        string str;
        cin>>str;
        b=' '+str+str;
        for(i=1;i<b.size();i++)
        {
            for(j=0;j<2;j++)
            {
                h[j][i]=(h[j][i-1]*P+b[i])%mod[j];
            }
        }
        for(i=1;i+n-1<b.size();i++)
            if(geth(i,i+n-1)==ans)
            {
                f=1;
                break;
            }
        if(f)
        {
            cout<<"YES\n";
            continue;
        }
        reverse(str.begin(),str.end());
        b=' '+str+str;
        for(i=1;i<b.size();i++)
        {
            for(j=0;j<2;j++)
            {
                h[j][i]=(h[j][i-1]*P+b[i])%mod[j];
            }
        }
        for(i=1;i+n-1<b.size();i++)
            if(geth(i,i+n-1)==ans)
            {
                f=1;
                break;
            }
        cout<<(f ? "YES" : "NO")<<endl;
    }
}





/*------------------------------------------------------------------------------------*/
// 大模数哈希
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t lll;
#define endl '\n'
const lll P=131;
const lll mod=lll(1e18)+9;  // 类型转换
const lll N=2e5+10;
vector<lll> p,h;

lll geth(int l, int r)	// 1<=l<=r<str.length()
{
	return ((h[r]-h[l-1]*p[r-l+1])%mod+mod)%mod;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	p.resize(N), h.resize(N);
	int i,j;
	p[0]=1;
	for(i=1;i<N;i++)
		p[i]=p[i-1]*P%mod;
	string str;
	cin>>str;
	lll t=0;
	for(int i=0;i<str.length();i++)
		h[i]=(h[i-1]*P+str[i])%mod;
}