# AcWing 905. 区间选点

## 1.[AcWing 905. 区间选点](https://www.acwing.com/problem/content/907/)

> **[AcWing 908. 最大不相交区间数量.md (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/Algorithm/AcWing/算法基础课/贪心算法/AcWing 908. 最大不相交区间数量.md)**  **（一定一定看此篇总结！！！）**
>
> **思路：**
>
> 1.利用结构体存储区间
>
> 2.对右端点从小到大进行排序，区间只会如图所示（最特殊的也就是右端点重合）
>
> <img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230322205806937.png" alt="image-20230322205806937" style="zoom:25%;" />
>
> 由图逐步分析可知，边一条一条遍历，没有遗漏。且经过对右端点的排序，不存在某一段区间（小），同时与两段区间（大区间，且右端点不相同）完全重合（被包裹了）。
>
> **3.一定一定要注意顺序！！！ 结构体变量定义的顺序！！ 数据读取的顺序！！！数据存入结构体的顺序！！！**

```C++
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

int n;
long long l,r;

struct line
{
    long long left,right;  // 赋值顺序 先左后右！！千万千万不能出错！！！
    
    bool operator<(const line & l)const
    {
        return right < l.right;  // 按照右端点进行排序
    }
    
}lines[N];

int main()
{
    cin >> n;
    
    for(int i = 0;i < n;i ++){   // sort 是从下标0开始排序，所以存储时应该从下标0开始
        
        scanf("%lld%lld",&l,&r);  // 一定一定要注意顺序！！
        
        lines[i] = { l, r};  // 赋值顺序一定一定得按照结构体定义顺序进行赋值！！！
    }
    
    sort(lines,lines + n);
    
    int res = 0;
    long long st = - 2e9;
    
    for(int i = 0;i < n;i ++){
        //重合部分不需要理会，有一个点就足够了，如果不重合则进入if中。
        if(st < lines[i].left){   // st 代表一段区间的最右端。一段区间的最右端小于另一端区间的最左端，则两个区间不重合。那么所需的点必须加一。
            res ++;
            st = lines[i].right;  //
        }
    }
    cout<<res<<endl;
    
    return 0;
}
```

## 2.[AcWing 905. 区间选点(惊奇的发现左右都可)](https://www.acwing.com/solution/content/10615/)

> **此题解中：**
>
> ```C++
> struct Range
> {
>     int  left,right;
>     bool operator <(const Range &W)const
>     {
>         return left <W.left;  // 按照左端点进行排序
>     }
> }range[N];
> 
> int res=0,st=-2e9;
>     for(int i=0;i<n;i++){
>         if(st < range[i].left)   // 判断条件没变！！！！
>         {
>             res++;
>             st = range[i].right;
>         }
>         else  st = min(st,range[i].right);   // 从重复的边中选取最小值
>         // 因为是按照左端点进行排序，且判断条件没变，所以需要额外考虑
>     }
> ```
>
> **解释：**
>
> 因为你左端点排序的话，一个大区间会存在多个小区间那么要想点数竟可能少，那么就选择小区间的右端点作为覆盖点，小区间可以覆盖大区间，但是不能覆盖大区间内另一个没有重复区域的小区间，所以要维护最右端点值。举个例子[3,6],[3,4],[5,6]，不取min第二次得到最右端是6，和[5,6]比较满足，res=1,就错了，相当于一个大区间内部可能有多个不相同的小区间，它们并不重复，也需要一个点
>
> <img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230322212547132.png" alt="image-20230322212547132" style="zoom: 67%;" />
>
> 