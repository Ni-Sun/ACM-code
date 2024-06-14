// 树状数组
int n,m;
vector<ll> a;

ll lowbit(ll x)
{
    return x&-x;
}

// 单点修改
void change(ll x, ll k)
{
    while(x<=n)
    {
        a[x]+=k;
        x+=lowbit(x);
    }
}

// 查询区间[1,x]前缀和
ll query(ll x)
{
    ll res=0;
    while(x>0)
    {
        res+=a[x];
        x-=lowbit(x);
    }
    return res;
}

int main()
{
    cin>>n>>m;
    a.resize(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>t;
        change(i,t);
    }
    while(m--)
    {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1)
            change(x,y);
        else
            cout<<query(y)-query(x-1)<<endl;
    }
}