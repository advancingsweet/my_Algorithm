# [AcWing 467. 海港](https://www.acwing.com/problem/content/description/469/)

> **我的思路：**
>
> - **第 i 艘船的时间为 t[i],人数为 k[i]. 第 i 艘船 第 j 个人的国籍为 g[i][j];**
> - **在24小时之内，国籍为x 的人数为 nation[x],乘客国籍总共有 ans 种**
>
> **不足：虽然个人的思路正确，但是（ 第 i 艘船 第 j 个人的国籍为 g[i][j]）数组明显会爆内存空间。**
>
> **大佬思想（滑动窗口+桶排序）**
>
> - **题目提示保证输入的 t[i] 是递增的，因此可以使用滑动窗口的思想，将到港的乘客按照时间顺序依次入队。在入队之前，将队首所有已经超过86400秒的乘客出队。**
>
> - **在入队和出队的同时，统计不同国籍的乘客人数。可以使用桶排序的思想，以国籍作为键、以乘客数量为值保存到数组中：**
>
>   > **每次出队，将该国籍的人数减少一个。如果该国籍的人数为0，则总国籍数量减少一个**
>   > **每次入队，将该国籍的人数增加一个。如果增加之前，该国籍的人数为0，则总国籍数量增加一个**
>
> ```C++
> const int N = 300010;
> int q[N][2];  // q[i][0]保存时刻，q[i][1]保存国籍
> ```

## 1AC(8 / 20) [Wrong Answer](https://www.acwing.com/problem/content/submission/code_detail/23672656/)

```C++
#include<iostream>
#include<vector>

using namespace std;

const int N = 100010;

long long t[N],nation[N];
int g[10000][10000];
int k[N],p[N];

int n,head = 1,rear = 0;
int Max = -1,ans,read;

int main()
{
    cin >> n;
    
    for(int i = 1;i <= n;i ++){   // 第i艘船
        
        ans = 0;
        
        scanf("%lld%d",&t[i],&k[i]);  // 第i艘船的停靠时间t[i],乘客数量
        
        for(int j = 1;j <= k[i];j ++){
            scanf("%d",&read);// g(i,j)  第i艘船上第j个人的国籍g(i,j);
            g[i][read] += 1;
            Max = max(Max,read);  // 国籍号码的最大值
        } 

        p[++rear] = i;  // 来一个加一个
        
        for(int j = 1;j <= Max;j ++) {
            nation[j] += g[i][j];
            if(nation[j]) ans ++;
        }
        
        while(head <= rear && t[i] - 86400 >= t[p[head]]){
            int tt = p[head];
            for(int j = 1;j <= k[tt];j ++) {   // 抛出
                int nat = g[tt][j];       // 第p[head] 艘船上国籍为j的人数 g[tt][j];
                if(nat) nation[j] -- ;
                if(!nation[j]) ans --;
            }
            head ++;  // 抛出
        } 
        
        cout << ans <<endl;
    }
    
    return 0;
}
```

## 2.AC(14 / 20) [Memory Limit Exceeded](https://www.acwing.com/problem/content/submission/code_detail/23673615/)

```C++
#include<iostream>
#include<vector>

using namespace std;

const int N = 100010;

long long t[N],nation[N];
int g[10000][30000];   // 
int k[N],p[N];

int n,head = 1,rear = 0;
int Max = -1,ans,read;

int main()
{
    cin >> n;
    
    for(int i = 1;i <= n;i ++){   // 第i艘船
        
        ans = 0;
        
        scanf("%lld%d",&t[i],&k[i]);  // 第i艘船的停靠时间t[i],乘客数量
       
        for(int j = 1;j <= k[i];j ++){
            scanf("%d",&read);// g(i,j)  第i艘船上第j个人的国籍g(i,j);
            g[i][j] = read;
            Max = max(Max,read);  // 国籍号码的最大值
        } 
        p[++rear] = i;  // 来一个加一个
        
        for(int j = 1;j <= Max;j ++) 
            nation[g[i][j]] ++;  // 统计国籍为g[i][j] 的人数
        
        
        for(int j = 1;j <= Max;j ++)
            if(nation[j]) {
                ans ++;
               // printf("到第 %d 艘船为止船上国籍为 %d 的人数为%lld\n",i,j,nation[j]);
            }
        
        while(head <= rear && t[i] - 86400 >= t[p[head]]){
            int tt = p[head];
            for(int j = 1;j <= k[tt];j ++) {   // 第j个人
                int nat = g[tt][j];       // 第p[head] 艘船上国籍为的人数 g[tt][j];
                 nation[nat] -- ;  // 减去这艘船上国籍为nat 总人数
                if(!nation[nat]) ans --;
            }
            head ++;  // 抛出
        } 
        
       cout << ans <<endl;
    }
    
    return 0;
}
```

## AC(100%)

> **可惜不是自己写的，但是大佬的代码是真的强！**

```c++
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;

const int N = 300010;
int q[N][2]; //循环队列，q[i][0]保存时刻，q[i][1]保存国籍
LL cnt[N]; //每个国籍的人数

int main()
{
    int n;
    scanf("%d", &n);
    int hh = 0, tt = 0; //循环队列，tt指向队尾元素的下一个位置
    int ans = 0;
    while(n --)
    {
        int t, k;
        scanf("%d%d", &t, &k);

        //注意，这里是>= 86400，不包含第24小时这个时刻
        while(hh != tt && t - q[hh][0] >= 86400) 
        {
            int nation = q[hh][1];
            cnt[nation] --;
            if(cnt[nation] == 0) ans --;
            hh ++;
        }

        for(int i = 1; i <= k; i ++)  // i 为人数
        {
            int x;
            scanf("%d", &x);     // x为国籍

            if(cnt[x] == 0) ans ++;   
            cnt[x] ++;   // 国籍为 x 的总人数 cnt[x] + 1;

            q[tt][0] = t, q[tt][1] = x;  //  第i艘船的 总时间为： q[i][0], 总人数为 
            
            printf("q[%d][1] = %d\n",tt,q[tt][1]);
            
            tt ++;
            if(tt == N) tt = 0;
        }

        cout << ans << endl;
    }

    return 0;
}
```

