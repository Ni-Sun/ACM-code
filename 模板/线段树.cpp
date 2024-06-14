// 线段树 version1
#define lc p<<1     // 左子节点
#define rc p<<1|1   // 右子节点
const ll N = 1e5+1;
vector<ll> w;

struct node
{
    ll l,r,sum,add;     // 区间，区间和，懒标记
}tr[4*N];

void pushup(ll p)
{
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(ll p)
{
    if(tr[p].add)
    {
        tr[lc].sum += tr[p].add*(tr[lc].r-tr[lc].l+1);
        tr[rc].sum += tr[p].add*(tr[rc].r-tr[rc].l+1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void build(ll p, ll x, ll y)
{
    tr[p] = {x,y,w[x],0};
    if(x==y)    return;
    ll mid = (tr[p].l+tr[p].r)/2;
    build(lc,x,mid);
    build(rc,mid+1,y);
    pushup(p);
}

void update(ll p, ll x, ll y, ll k)
{
    if(x<=tr[p].l && tr[p].r<=y)
    {
        tr[p].add += k;
        tr[p].sum += k*(tr[p].r-tr[p].l+1);
        return;
    }
    ll mid = (tr[p].l+tr[p].r)/2;
    pushdown(p);
    if(x<=mid)  update(lc,x,y,k);
    if(y>mid)   update(rc,x,y,k);
    pushup(p);
}

ll query(ll p, ll x, ll y)
{
    if(x<=tr[p].l && tr[p].r<=y)
        return tr[p].sum;
    ll res = 0;
    pushdown(p);
    ll mid = (tr[p].l+tr[p].r)/2;
    if(x<=mid)  res += query(lc,x,y);
    if(y>mid)   res += query(rc,x,y);
    return res;
}















// 线段树 version2
template<class info,class opt>
struct segtree{
    #define ls (u<<1)
    #define rs (u<<1|1)

    int n;
    vector<info> io;

    void pushup(int u){
        io[u]=io[ls]+io[rs];
    }

    segtree(int _n):n(_n),io(4*n+1){}

    segtree(int _n,vector<info> init):
    n(_n),io(4*n+1){
        function<void(int,int,int)> built;
        built=[&](int u,int l,int r){
            if(l==r){
                io[u]=init[l];
                return;
            }
            int m=(l+r)>>1;
            built(ls,l,m);
            built(rs,m+1,r);
            pushup(u);
        };
        built(1,1,n);
    }

    void change(int u,int l,int r,int x,opt k){
        if(l==r){
            io[u]*=k;
            return;
        }

        int m=(l+r)>>1;
        if(x<=m) change(ls,l,m,x,k);
        else change(rs,m+1,r,x,k);
        pushup(u);
    }

    info query(int u,int l,int r,int x,int y){
        if(x<=l&&y>=r) return io[u];
        int m=(l+r)>>1;
        if(y<=m) return query(ls,l,m,x,y);
        else if(x>m) return query(rs,m+1,r,x,y);
        else return query(ls,l,m,x,y)+query(rs,m+1,r,x,y);
    }

    void cg(int x,opt k){
        change(1,1,n,x,k);
    }

    info qy(int x,int y){
        return query(1,1,n,x,y);
    }

    #undef ls
    #undef rs
};

struct opt{
    int k;
};

struct info{
    int m1,m2=0,n1=1,n2=0;
    // 合并
    info operator+(const info &p){
        info res;
        if(m1 > p.m1)
        {
            res.m1 = m1, res.n1 = n1;
            if(m2 > p.m1)
                res.m2 = m2, res.n2 = n2;
            else if(m2 == p.m1)
                res.m2 = m2, res.n2 = n2+p.n1;
            else
                res.m2 = p.m1, res.n2 = p.n1;
        }
        else if(m1 == p.m1)
        {
            res.m1 = m1, res.n1 = n1+p.n1;
            if(m2 > p.m2)
                res.m2 = m2, res.n2 = n2;
            else if(m2 == p.m2)
                res.m2 = m2, res.n2 = n2+p.n2;
            else
                res.m2 = p.m2, res.n2 = p.n2;
        }
        else // m1 < p.m1
        {
            res.m1 = p.m1, res.n1 = p.n1;
            if(m1 > p.m2)
                res.m2 = m1, res.n2 = n1;
            else if(m1 == p.m2)
                res.m2 = m1, res.n2 = n1+p.n2;
            else
                res.m2 = p.m2, res.n2 = p.n2;
        }
        return res;
    }

    // 更改
    void operator*=(const opt &p){
        m1=p.k;
    }
};
