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

