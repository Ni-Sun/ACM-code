#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef unsigned long long ull;
#define endl '\n'

#define lc p<<1     // 左子节点
#define rc p<<1|1   // 右子节点
const ll N = 1e6+1;
ll n,m;
string str;
vector<ull> pre;
const ull P=131;

struct node
{
	ll l,r;
    ull h1,h2;
}tr[4*N];

void pushup(ll p)
{
	int len1=tr[lc].r-tr[lc].l+1;
	int len2=tr[rc].r-tr[rc].l+1;
    tr[p].h1=tr[lc].h1*pre[len2]+tr[rc].h1;
	tr[p].h2=tr[rc].h2*pre[len1]+tr[lc].h2;
}

void build(ll p, ll x, ll y)
{
    tr[p] = {x,y,ull(str[x]),ull(str[x])};
    if(x==y)    return;
    ll mid = (tr[p].l+tr[p].r)/2;
    build(lc,x,mid);
    build(rc,mid+1,y);
    pushup(p);
}

void update(ll p, ll x, ull k)
{
	if(x==tr[p].l && x==tr[p].r)
	{
		tr[p].h1=tr[p].h2=k;
		return;
	}
	ll mid=tr[p].l+tr[p].r>>1;
	if(x<=mid)	update(lc,x,k);
	else		update(rc,x,k);
	pushup(p);
}


vector<ull> query(int p, int x, int y)
{
	if(x<=tr[p].l && tr[p].r<=y)
		return {tr[p].h1,tr[p].h2,tr[p].r-tr[p].l+1};
	int mid=tr[p].l+tr[p].r>>1;
	if(x>mid)	return query(rc,x,y);
	if(y<=mid)	return query(lc,x,y);
	auto w1=query(lc,x,y);
	auto w2=query(rc,x,y);
	vector<ull> res(3);
	res[0]=w1[0]*pre[w2[2]]+w2[0];
	res[1]=w2[1]*pre[w1[2]]+w1[1];
	res[2]=w1[2]+w2[2];
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>str;
	str=' '+str;
	n++;
	pre.resize(n+1);
	build(1,1,n);
	int i;
	pre[0]=1;
	for(i=1;i<=n;i++)
		pre[i]=pre[i-1]*P;
	while(m--)
	{
		int opt,x,l,r;
		char k;
		cin>>opt;
		if(opt==1)
		{
			cin>>x>>k;
			// cout<<x<<' '<<k<<endl;
			update(1,x,ull(k));
		}
		else
		{
			cin>>l>>r;
			auto x=query(1,l,r);
			cout<<(x[0]==x[1] ? "Yes" : "No")<<endl;
		}
	}
}