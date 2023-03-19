# AcWing 897. 最长公共子序列

### 1.[AcWing 897. 最长公共子序列](https://www.acwing.com/activity/content/problem/content/1005/)

### 2.[超级无敌解释！！！图解无敌](https://programmercarl.com/1143.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF)

### 3.[y式dp分析法](https://www.acwing.com/solution/content/8111/)

<img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230319120324077.png" alt="image-20230319120324077" style="zoom:67%;" />

（箭头移动即代表状态转移、状态继承）

```C++
#include<iostream>  
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;
int a,b;
char s[N],t[N];
int dp[N][N];

int main()
{
    cin>>a>>b>>s+1>>t+1;
    // dp[i][j] 记录的是 s序列中前i个字符与t序列中前j个字符的最长公共子序列的长度。
    for(int i = 1;i <= a;i ++)  // s
        for(int j = 1;j <= b;j ++){  //t
            if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1; 
            // 此公式从左向右理解：s[i] == t[j]，那么就应该 看看 1~i-1 与 1~j-1 之中还有多少公共子序列
            // 从右往左理解： s[i-1] == t[j-1]. 那么 dp[i-1][j-1]（初始化为0） 应该将（i-1,j-1)这一对相同字符加入，然后dp（i,j) >= dp(i-1,j-1);
           
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);   // s[i] != t[j]
            /*
            f[i][j] 表示在第一个序列的前i个字母中出现并且在第二个序列的前j个字母中出现的最大值
            以第i个和第j个字母是否相同来划分
            如果相同 f[i][j] = f[i - 1][j - 1] + 1
            如果不相同 f[i][j] = max(f[i - 1][j], f[i][j - 1])
            因为如果不相同，那么此时f[i][j]的值肯定不会大于f[i - 1][j]和f[i][j - 1]的最大值
            那么一定会等于f[i - 1][j]和f[i][j - 1]的最大值
            */
        }
        cout<<dp[a][b]<<endl;
    
    return 0;
}
```

