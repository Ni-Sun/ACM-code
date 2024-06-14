// 最近公共祖先
// version1
// 树链剖分
const int N=5e5+10;
int fa[N],dep[N],sz[N],top[N],son[N];
vector<vector<int>> a;

void dfs1(int u, int fat)
{
    fa[u]=fat,dep[u]=dep[fat]+1,sz[u]=1;
    for(auto v:a[u])
    {
        if(v==fat)
            continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[son[u]]<sz[v])
            son[u]=v;
    }
}

void dfs2(int u, int topp)
{
    top[u]=topp;
    if(!son[u])
        return;
    dfs2(son[u],topp);  //重儿子
    for(auto v:a[u])
    {
        if(v==son[u] || v==fa[u])
            continue;
        dfs2(v,v);
    }
}

int lca(int u, int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]])
            swap(u,v);
        u=fa[top[u]];
    }
    return (dep[u]<dep[v] ? u:v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,s;
    cin>>n>>m>>s;
    a.resize(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y),a[y].push_back(x);
    }
    dfs1(s,0);
    dfs2(s,s);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
            cout<<a<<'\n';
        else
            cout<<lca(a,b)<<'\n';
    }
}



// version 2
// 倍增
vector<int> dep;
vector<vector<int>> a,fa;

void dfs(int u, int father)
{
    int i;
    fa[u][0]=father, dep[u]=dep[father]+1;
    for(i=1;i<20;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto v:a[u])
        if(v!=father)
            dfs(v,u);
}

int lca(int u, int v)
{
    int i;
    if(dep[u]<dep[v])
        swap(u,v);
    for(i=19;i>=0;i--)
        if(dep[fa[u][i]]>=dep[v])
            u=fa[u][i];
    if(u==v)
        return u;
    for(i=19;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}

int main()
{
    fa.resize(n+1),dep.resize(n+1);
    a.resize(n+1);
    for(i=0;i<=n;i++)
        fa[i].resize(20);   // 这里大小取决于n，保证2^(fa[i].size-1)>n
}