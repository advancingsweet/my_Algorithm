# AcWing 3729. 改变数组元素   [原题链接](https://www.acwing.com/problem/content/3732/)

> **此题总结**
>
> **由于各种概念没弄懂，错误非常多！逻辑错误！思考不全面**
>
> 1.  **如错误示例二： 第15行，仅考虑了当前处理长度大于等于数组长度，b[1] += 1; 但压根没考虑到此时数据读取还没有结束。即 b[1] += 1 会继续影响b[ i + 1] 及之后的数据！！！**
> 2. **又如错误示例一： 用差分数组读取元素！！！（正错误输出已列出，自行分析！）**

## **1. 错误示例一！！！**

```C++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 200010;
int b[N],n,m;

int main()
{
    cin >> n;
    while(n -- ){
        cin >> m;
        memset(b,0,sizeof b);
        for(int i = 1;i <= m; i++){  
             	scanf("%d",&b[i]);   // 不能用差分数组直接读取！！！！！！！！！！！！！
            if(i <= b[i]) b[1] += 1,b[i + 1] -= 1;   // 防止数组越界
            else b[i - b[i] + 1] += 1, b[i + 1] -= 1;
        }
        for(int i = 1;i <= m;i ++){
            b[i] += b[i-1];
            printf("%d ",!!b[i]);
        }
        cout << endl;
    }
    return 0;
}
```

### 输入

```
1
6
0 3 0 0 1 3
```

### 输出（不用差分数组读取，正确！）

```
b[1] = 1 b[2] = 0 b[3] = -1 b[4] = 1 b[5] = 1 b[6] = -1 
a[1] = 1 a[2] = 1 a[3] = 0 a[4] = 1 a[5] = 1 a[6] = 1  
```

### 输出（用差分数组读取，错误！）

```
b[1] = 1 b[2] = 3 b[3] = 0 b[4] = 0 b[5] = 1 b[6] = 3 
a[1] = 1 a[2] = 1 a[3] = 1 a[4] = 1 a[5] = 1 a[6] = 1 
```

*****************

## 2.错误实例二！！！

```C++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 20010;
int n,m，b[N];
int main()
{
    cin >> m; 
    while(m -- ){ 
        cin >> n; 
        memset(b,0,sizeof b;
        for(int i = 1;i <= n;i ++){
            int x;
            scanf("%d",&x);
            if(i <= x) b[1] += 1;      // 错误！！！ 虽然此时的 x >= i,但是读取还未结束，正确代码： if(i <= x) b[1] += 1, b[i+1] -=1; 
            else b[i - x + 1] += 1,b[i + 1] -=1;
        }
        for(int i = 1;i <= n; i++){
             b[i] += b[i-1];
             printf("%d ",!!b[i]);
        }
        cout<<endl; 
    }
    return 0;
}
```

*******

## 3.最终代码

```C++
#include<iostream>
#include<cstring>
using namespace std;
const int N = 200010;
int b[N],n,m;

int main()
{
    cin >> n;
    while(n -- ){
        cin >> m;
        memset(b,0,sizeof b);
        for(int i = 1;i <= m; i++){
            int x;
            scanf("%d",&x); 
            if(i <= x) b[1] += 1,b[i + 1] -= 1;    // 防止数组越界！
            else b[i - x + 1] += 1, b[i + 1] -= 1; 
        }
        for(int i = 1;i <= m;i ++){
            b[i] += b[i-1];
            printf("%d ",!!b[i]);
        }
        cout << endl;
    }
    return 0;
}
```

