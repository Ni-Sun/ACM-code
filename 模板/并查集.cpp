vector<int> fa,sz;
fa.resize(n+1),sz.resize(n+1,1);
iota(fa.begin(),fa.end(),0);

int find(int x) // 找根节点
{
    if(fa[x]==x)    return x;
    return fa[x]=find(fa[x]);
}

void unionset(int x, int y) // 合并并查集
{
    x=find(x),y=find(y);
    if(x==y)    return;
    if(sz[x]>sz[y]) swap(x,y);
    fa[x]=y;
    sz[y]+=sz[x];
}
