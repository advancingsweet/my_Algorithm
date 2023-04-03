# AcWing 895. 最长上升子序列

### [AcWing 895. 最长上升子序列](https://www.acwing.com/problem/content/897/)

## 一、题解思路

动态规划问题：状态传递 + 状态计算。

1. 在考虑状态传递的过程中，应该找出状态传递的条件。如此题：

- ```C++
  // 状态传递方程：
  if(f[i] > f[j]) dp[i] = max(dp[i],dp[j] + 1);    
  
  /*
  状态传递条件： if(f[i] > f[j])    (j < i)
  条件解释：
  	   1. f[i] > f[j]：那么dp[j]中的集合，f[j] 是其中的最大值，而f[i] >max(dp[j]的值)，所以dp[i] 可以继承dp[j],并且将加入期内。所以dp[i] > dp[j]. 满足单调递增且最长原则，并可将此状态继续往下传递。
         2. f[i] = f[j]: 最终dp[i] >= dp[j].  因为存在dp[i] == dp[j]，不满足最长原则，所以不进行状态转移。
         				序列：  1，2，7，f[j] = 20 ,23,9,13, f[i] = 20;   dp[j] = 4, dp[i] = 6; dp[i] > dp[j]
           			序列：  1，2，7，f[j] = 20 ,23, f[i] = 20;        dp[j] = 4, dp[i] = 4; dp[i] = dp[j]
         3. f[i] < f[j]: 最终dp[i]与dp[j]的大小无法比较. 无法确定是否满足单调递增也不确定是否满足最长原则， 所以不进行状态转移。
         				序列：  1，2，7，f[j] = 20 ,23,9,13, f[i] = 15;   dp[j] = 4, dp[i] = 5;  dp[i] > dp[j]
           			序列：  1，2，7，f[j] = 20 ,23, f[i] = 8;        dp[j] = 4, dp[i] = 4;   dp[i] = dp[j]
           			序列：	 1，2，7，f[j] = 20 ,23, f[i] = 6;        dp[j] = 4, dp[i] = 3;   dp[i] < dp[j]            
  */
  ```



## 二、代码 	

```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n;
int dp[N]; // 表示前i个数字所能组成的最大上升子序列
int f[N];

int main()
{
    cin>>n;
    
    for(int i = 1;i <= n; i++) cin>>f[i];
    
    for(int i = 1;i <= n;i ++)
    {
        dp[i] = 1;  // 至少包含自己
        
        for(int j = 1;j < i; j ++)
            if(f[i] > f[j]) dp[i] = max(dp[i],dp[j] + 1);  
           /* 
           注意：动态规划问题是找状态条件，
            else dp[i] = max(dp[i],dp[j]);  错误，因为一旦f[i] <= f[j] 那么dp[i] 无法继承 dp[j].
            */
    }
    
    int res = -1;
    
    for(int i = 1;i <= n; i++)
        res = max(res,dp[i]);
    
    cout<<res<<endl;
    
    return 0;
}
```

## 三、题解

### [原地址](https://www.acwing.com/solution/content/138995/)

![image-20230318233839107](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230318233839107.png)

## 四、路径输出(大佬代码)

```C++
#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N];
/*  f[i]是以a[i]结尾的上升子序列的集合, 属性是这些子序列中长度的最大值
    集合的划分
        背包问题都是以最后一个物品选多少个分类, 那么这里呢?
        f[i]表示的这些子序列最后一个数都是w[i], 能不能用w[i-1]来分类呢?
        第i-1个数无非这么几种
            不存在, 即w[i]是第一个数
            要么是a[1], 要么是a[2], 要么是a[3].....a[i-1]
        这些数都是不一定存在的, 因为是上升子序列, a[i]必须大于它们才可以
*/
int f[N];
// 保存转移路径
int g[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ )
        cin >> a[i];

    for (int i = 0; i < n; i ++ )
    {
        // 一个数也算一个子序列
        f[i] = 1;
        // 等于0表示只有一个数
        g[i] = 0;
        // 我们看i前面的那个数是数列中的第几个数, 它可以不存在(当i是第一个数), 也可以是数列第一个数....
        for (int j = 0; j < i; j ++ )
            // 如果倒数第二个数i-1是小于i的, 上身子序列长度+1, 而以倒数第二个数结尾的上升子序列长度为f[j]
            if (a[i] > a[j])
                // 求的是最长的子序列, 只有后面的长度大于前面长度才更新
                if (f[i] < f[j] + 1)
                {
                    // 状态变化
                    f[i] = f[j] + 1;
                    // j转移到i
                    g[i] = j;
                }
    }
    // 不要惯性思维, 因为集合表示的是以每一个数结尾的上升子序列, 所以还要求一遍最大值
    int res = 0;
    int k = 0;
    for (int i = 0; i < n; i ++ )
    {
        res = max(res, f[i]);
        // 记录最大值的下标
        if (f[k] < f[i])
            k = i;
    }
    // cout << res << endl;
    cout << f[k] << endl;

    // 长度是f[k]
    for (int i = 0, len = f[k]; i < len; i ++ )
    {
        printf("%d", a[k]);

        if (i <= f[k])
            printf(" <- ");

        k = g[k];
    }

    return 0;
}
```

## 五、路径输出（我的代码）

```c++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int dp[N],g[N],a[N];
int n;

int main()
{
    cin >> n;
    
    for(int i = 1;i <= n;i ++) cin>>a[i];
    
    for(int i = 1;i <= n;i ++){
        
        dp[i] = 1,g[i] = 0;      // dp[i] = 1 是指前i个数中，至少a[i] 本身就是一个序列，初始化为1； g[i] = 0表示只有自己本身。
        for(int j = 1;j < i; j ++){
            if(a[i] > a[j]){                // 注意注意！！！ 此并非 {  dp[i] = max(dp[i],dp[j] + 1);  g[i] = j;}
                if(dp[i] < dp[j] + 1){     // 只有更新的时候才更新状态，否则不能更新状态
                    dp[i] = dp[j] + 1;    
                    g[i] = j;
                }
            } 
        }
    }
    int res = 0; 
    int k = 1;
    
    for(int i = 1;i <= n;i ++) {
        res = max(res,dp[i]);
        if(dp[k] < dp[i]) k = i;   // 记录最长上升子序列的最大值的下标。
    }
    
    cout<<res<<endl; // 最长上升子序列的长度
   
    for(int i = 1,len = dp[k];i <= len;i ++){
        printf("%d ",a[k]); // k 仅仅是对应值的下标,而存储值的是a[k]
        k = g[k];
    }
    return 0;
}
```

![image-20230319004950696](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230319004950696.png)