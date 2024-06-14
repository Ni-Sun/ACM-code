int find(int q)
{
    int l=0,r=n+1,mid;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(a[mid]<=q)
            l=mid;
        else
            r=mid;
    }
    return l;
}