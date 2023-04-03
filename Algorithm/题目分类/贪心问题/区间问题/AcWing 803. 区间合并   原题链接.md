# AcWing 803. 区间合并   [原题链接](https://www.acwing.com/problem/content/805/)

> **区别于 AcWing 905. 区间选点   [原题链接](https://www.acwing.com/problem/content/907/)**
>
> **区间合并：学生选课，课程时间可重复，求他最长能上课的时间最长是多少。（每节课尽量早的开始，按左端点排序）**（区间相并）
> **区间取点：学生选课，课程时间不能重复，求他最多能上多少节课。              （每节课尽量早的结束，按右端点排序）**  （区间相交）

```C++
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
struct range
{
    int l,r;
    bool operator<(const range & p)const 
    {
        if(l != p.l) return l < p.l;
        return r < p.r;
    }
}ranges[N];
int main()
{
    cin >> n;
    for(int i = 0;i < n;i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        ranges[i] = {x,y};
    }
    sort(ranges,ranges + n);
    int st = ranges[0].r,ans = 1;  // 通俗理解： 最早开始的时间
    for(int i = 1;i < n;i ++)
        if(st >= ranges[i].l)    // 区间重叠
            st = max(st,ranges[i].r);    // 区间重叠，进行合并，选择右端点的最大值。  通俗理解：连续区间内，最晚结束的时间
        else {
            ans ++;
            st = ranges[i].r;   // 中间断开，重复上过程！
        }
    cout << ans<<endl;
    return 0;
}
```

