# AcWing 4949. 末尾连续0   [原题链接](https://www.acwing.com/problem/content/4952/)

> **一、知识点：**
>
> **[算术基本定理“质数分解唯一性的证明”：古典方法与现代方法](https://blog.csdn.net/lijil168/article/details/68185549)**
>
> **二、题解思路：**
>
> **1.每个数的质因数分解是唯一的！**
>
> **number = k * power(10,n); n为末尾0的个数，power(10,n) = power(2,n)*power(5,n);**
>
> **所以把number质因数分解，假设能分解出2的p1次方，5的p2次方，那么总共能拼出 min(p1,p2)个 2 * 5；**
>
> ```C++
> min(p1,p2) == p2 // 对于一个阶乘来说能分解出的2肯定比5多
> ```
>
> **三、错误思路：**
>
>  **利用字符串将各个数的阶乘保存起来，对每一个数进行特判。此为典型的错误思想！因为15！就已经溢出，超过15的阶乘根本无法算出来，更别提将n >= 15的数的阶乘算出！**
>
> **四、理解重点！！！**
>
> **对于阶乘n！，为何可通过遍历（i = 1 ~ n)分别除5就可知阶乘中质因数5的个数？**
>
> > **1 * 5 = 5;**
> >
> > **2 * 5 = 10;**
> >
> > **·····**
> >
> > **n * 5 = 5n;**
> >
> > **可知： [ 5,10) 区间的阶乘，仅包含了一个质因数5。[ 10, 15）区间的阶乘，包含了两个质因数5 ·······**
> >
> > **坑点！**
> >
> > **n如果是5的倍数，那么也应该算入内！！！！ 所以才有while循环，而不仅仅是 cnt += s/5 !!!**
> >
> > ```C++
> >  while(s){
> >         cnt += s/5;  
> >         s /= 5;
> >  }
> > ```

### 一、y总代码

#### 时间复杂度：（二分）O（logn)

> **对于第10行代码(我的想法:很复杂,而且还是写错了!)**
>
> ```C++
> int f(int s)
> {
>     int cnt = 0;
>     if(s / 5) cnt ++;
>     s /= 5;
>     while(s){
>         cnt ++;     // 错误,应该判断s是否还能整除2!
>         s /= 5;
>     }
>     return cnt;
> }
> ```

```C++
#include<iostream>
using namespace std;
int n;
int f(int s)
{
    int cnt = 0;
    while(s){
        cnt += s/5;  // 绝了，跟dfs中求节点个数一样！ 对比我的代码真的绝了啊!!!!
        s /= 5;
    }
    return cnt;
}
int lower_bound(int n)
{
    int l = 0,r = 5e5 + 1;  // 二分的边界
    while(l + 1 != r){
        int mid = l + r >> 1;
        if(f(mid) >= n) r = mid;
        else l = mid;
    }
    return r;
}

int main()
{
    cin >> n;
    int a = lower_bound(n);
    int b = lower_bound(n + 1) - 1;
    cout << b - a + 1 << endl;
    for(int i = a;i <= b;i ++) cout << i << " ";
    return 0;
}
```

#### 时间复杂度 O(nlogn)

```C++
#include<iostream>
#include<vector>

using namespace std;

int f(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt += n/5;
        n /= 5;
    }
    return cnt;
}

vector<int>s;
int n;

int main()
{
    cin >> n;
    
    for(int i = 1;;i ++ )    // 直接给了死循环，结合下文的代码测试结果可理解这步骤的原因
    {
        int t = f(i);
        if(t > n) break;
        if(t == n) s.push_back(i);
    }
    cout << s.size()<< endl;
    for(int c:s) cout << c<<" ";
    return 0;
}
```



### 二、代码调试

> **总结：**
>
> **进一步验证了“质数分解唯一性”定理的正确性。**

```C++
#include<iostream>
#include<vector>

using namespace std;

int f(int n)
{
    int cnt = 0;
    while(n)
    {
        cnt += n/5;
        n /= 5;
    }
    return cnt;
}

int n;
int main()
{
    cin >> n;
    for(int i = 1;i < 20;i ++ )
    printf("i = %d,t = %d\n",i,f(i));
}
```

输出：

```
i = 1,t = 0
i = 2,t = 0
i = 3,t = 0
i = 4,t = 0
i = 5,t = 1
i = 6,t = 1
i = 7,t = 1
i = 8,t = 1
i = 9,t = 1
i = 10,t = 2
i = 11,t = 2
i = 12,t = 2
i = 13,t = 2
i = 14,t = 2
i = 15,t = 3
i = 16,t = 3
i = 17,t = 3
i = 18,t = 3
i = 19,t = 3
```

