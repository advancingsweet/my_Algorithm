# [3956. 截断数组](https://www.acwing.com/problem/content/3959/)

# [题解](https://www.acwing.com/solution/content/66585/)



```C++
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 100010;

long long  s[N],n,res;

int main()
{
    cin>>n;
    
    for(int i = 1;i <= n;i ++)
    {
        scanf("%lld",&s[i]);  // scanf("%d",&a[i]); 会报错！！ long long == long long int  得用lld
        s[i] += s[i-1];
    }
    
    if(s[n] % 3 == 0){
        
        long long  ave = s[n] / 3;
        
        for(int i = 1,cnt = 0;i <= n -2;i ++)  
        {
            if(s[i] == ave) cnt ++;   // 第一刀的位置 只要满足此条件都可
            if(s[n] - s[i+1] == ave) res += cnt;  // 第二刀的位置为i+1， 如果满足此条件，那么此位置可与所有第一道的位置进行组合。
        }
    }
    cout<<res<<endl;
    
    return 0;
}
```

# 整体思路

1. 将一个数组切两刀，分成的三部分数值和相等。所以一判断条件是所有数之和sum能够进行三等分

   