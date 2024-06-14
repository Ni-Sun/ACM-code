// kruskal
vector<int> fa(n+1),sz(n+1,1);
iota(fa.begin(),fa.end(),0);
auto find=[&](auto find, int x)
{
    if(x==fa[x])    return x;
    return (fa[x]=find(find,fa[x]));
};
for(auto [u,v,w]:a)
{
    u=find(find,u),v=find(find,v);
    if(sz[u]>sz[v]) swap(u,v);
    if(u!=v)
    {
        fa[u]=v;
        sz[v]+=sz[u];
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
}