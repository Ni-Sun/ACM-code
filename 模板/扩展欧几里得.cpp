/* 
    可以放到计算几何中算线段AB上有多少整点, 毕竟x,y取整数
    在两整点 A(x1,y1) 和 B(x2,y2) 的线段（含端点）中经过整点的个数为 gcd(∣x1−x2∣,∣y1−y2∣)+1
*/


// ax+by = gcd(a,b)
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll x1,y1,d;
    d = exgcd(b, a%b, x1, y1);
    x = y1, y = x1 - a/b*y1;
    return d;
}

x = (x%mod + mod) % mod;	// 保证0 < x < mod

// 求 a 在模 mod 下的逆元, ax = 1(%mod)
exgcd(a,mod,x,y);
x = (x%mod + mod) % mod;
