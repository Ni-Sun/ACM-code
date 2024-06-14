ll quick_power(ll base, ll power)
{
    ll res = 1;
    while(power)
    {
        if(power&1)
            res = (res*base) % mod;
        power >>= 1;
        base = (base*base) % mod;
    }
    return res;
}