// 最短路算法 Bellmax-Ford算法的优化 Spfa算法，可以处理负边权
auto spfa=[&](int s)
{
    vector<int> vis(n+1),cnt(n+1),dp(n+1,1e9);  // dp求从点s到任一点的最短路
    queue<int> q;
    q.push(s);
    dp[s]=0;
    int u,v,w;  // (u,v) 为有向边, w 为这条边的权值
    while(!q.empty())
    {
        u=q.front();    q.pop();
        vis[u]=0;
        for(auto [v,w]:a[u])
            if(dp[u]+w<dp[v])
            {
                dp[v]=dp[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n)
                    return 1;   // 有负环
                if(!vis[v])
                    vis[v]=1,q.push(v);
            }
    }
    return 0;   // 无负环
};