### **注意在pop的时候判断非空**

```
cpp
priority_queue<pii> pq;
while(!pq.empty() && cnt>pq.top().first)
            pq.pop();
```

### priority_queue-比较函数

```
cpp
typedef pair<int,int> pii;
struct cmp	// 仿函数
{
    bool operator() (const pii &a, const pii &b)	// 相当于重载 '<' 运算符
    {
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
};
priority_queue<pii,vector<pii>,cmp> pq;	// 优先队列用仿函数
```

### 数字+字符混合输入

如果输入  192.168.88.0/24  , 可以用scanf输入

```
cpp
int a,b,c,d,e;
scanf("%d.%d.%d.%d/%d",&a,&b,&c,&d,&e);
```


### 数组下标越界

运行程序没有报错但是没输出, 可能是下标越界. 下标越界可能是***数组开小了***导致的.
