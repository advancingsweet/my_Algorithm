# 差分（一维与二维）

## 1.[Acwing.797. 差分](https://www.acwing.com/problem/content/799/)

> 1. **[一、二维前缀和 && 一、二维差分](https://blog.csdn.net/m0_74215326/article/details/129620912?spm=1001.2014.3001.5502) **
>
> 2. ```C++
>      while(m--){
>            scanf("%d%d%d",&l,&r,&c);
>            b[l] += c;  // 思想解释：21行滑动数组！！！
>            b[r+1]new = b[r+1]old -  c;
>          // 由21行可知滑动数组会一直将 +c 从l开始向前推，但增加区间仅在[l,r]。 a[r+1] = b[r+1] + a[r]; 滑动数组一直将状态滑到 a[r]， 
>          // a[i]new = a[i]old + c;   a[i+1] = b[i+1]new + a[i]new = b[i+1] + a[i] + c; 所有为使a[i+1]不受影响，只能 b[r+1]new = b[r+1]old - c;
>        }
>    ```
>
>    <img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230328205224060.png" alt="image-20230328205224060" style="zoom: 80%;" />
>
> 

```C++
#include<iostream>
using namespace std;
const int N = 100010;

int n,m,l,r,c;
int a[N],b[N];

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        scanf("%d",&a[i]);
        b[i] = a[i] - a[i-1];
    }
    while(m--){
        scanf("%d%d%d",&l,&r,&c);
        b[l] += c;  // 思想解释：21行滑动数组！！！
        b[r+1] -= c; // 由21行可知滑动数组会一直将 +c 从l开始向前推，但增加区间仅在[l,r]。 a[r+1] = b[r+1] + a[r]; 
    }
    for(int i = 1;i <= n;i ++){
        a[i] = b[i] + a[i-1];   // 滑动数组，当b[l] += c 时，可通过滑动数组一直将 +c 往前推，也就每一个元素均 + c。
        printf("%d ",a[i]);
    }
    return 0;
}
```

***************

## AcWing 798. 差分矩阵   [原题链接](https://www.acwing.com/problem/content/800/)

> 1. **[y总视频讲解](https://www.acwing.com/video/244/)**
>
> 2. **[二维差分(差分矩阵)](https://blog.csdn.net/m0_57487901/article/details/124859474)**
>
> 3. **二维差分数组的定义**
>
>    ```C++
>    long long res = 0;
>    for(int i = 1;i <= n;i ++)
>        for(int j = 1;j <= m;j ++)
>            res += b[i][j];
>    // x循环所得res == a[i][j];
>    ```



### 法一：插入法初始化差分数组

> <img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230328203731106.png" alt="image-20230328203731106" style="zoom:50%;" />

```C++
#include<iostream>
using namespace std;

const int N = 1010;

int a[N][N],b[N][N];
int q,n,m;

void insert(int x1,int y1,int x2,int y2,int c){   // 差分最核心操作！
    b[x1][y1] += c;
    b[x2 + 1][y1] -= c;   // 注意区别前缀和！
    b[x1][y2 + 1] -= c;
    b[x2+1][y2+1] += c;
}

int main()
{
    cin >> n >> m >>q;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++){
            scanf("%d",&a[i][j]);
            insert(i,j,i,j,a[i][j]);   // 初始化差分数组b    
        }
      
    int x1,y1,x2,y2,c;
   while(q -- ){
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1,y1,x2,y2,c);  // 对差分数组进行操作
    }  
    
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            b[i][j] = b[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];   // 此为前缀和！
            printf("%d ",b[i][j]);
        }
       puts("");
    }
    
    return 0;
}

```

## 法二：二维公式法求差分数组

> **[前缀和与差分 图文并茂 超详细整理](https://blog.csdn.net/weixin_45629285/article/details/111146240)**
>
> <img src="D:\Download\BaiDuWangPan\差分与前缀和-5.jpg" alt="差分与前缀和-5" style="zoom: 50%;" />
>
> **注意区分！！！**
>
> ```C++
> b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];  // 公式法求差分数组
> 
>  b[i][j] = b[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];  // 前缀和 ！！！    b[i][j] = a[i][j]
> ```
>
> 

```C++
#include<iostream>

using namespace std;

const int N = 1010;

int n,m,q;
int a[N][N],b[N][N];

void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
    b[x2 + 1][y2 + 1] += c; 
}

int main()
{
    cin >> n >> m >> q;
    
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= m;j ++)
        {
            scanf("%d",&a[i][j]);
            b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];  // 区别前缀和！！！
        }
    while(q -- ){
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1,y1,x2,y2,c);
    }
    
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            b[i][j] = b[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];  // 前缀和 ！！！   b[i][j] = a[i][j]
            printf("%d ",b[i][j]);
        }
        cout<<endl;
    }
    return 0;
}
```

