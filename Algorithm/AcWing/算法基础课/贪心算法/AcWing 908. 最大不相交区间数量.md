# [AcWing 908. 最大不相交区间数量](https://www.acwing.com/problem/content/910/)

> **解题思路：**
>
> 1. **[AcWing 905. 区间选点](https://www.acwing.com/activity/content/problem/content/1111/)  （两道题一样一样的）**
>
> ![image-20230323000145308](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230323000145308.png)
>
> -  就等同于：尽可能的将各区间合成一个区间（条件是：组合的各个区间必须都有公共部分，且每个区间只能组合一次）。合并后，所有的区间都不是重合的区间，所以此时   所取点数 == 的区间数。
>
> - 选最少的点就是相当于把尽可能把相交的区间串一个，点的数量就是最终单独区间的数量！！
>
> 2. **此题的题意进行转换就等同如下：**
>
> - 类似在学校上课不能选上课时间重复的时间段。若有重复时间段，则可等价理解为“上的是同一堂课” （此题等价多个区间视为“同一区间”）。但是又得注意：
>
> - 为什么用右端点进行排序：因为越早结束课程，就越能保证剩下的时间充足，也就越能多选一些课程。（区间也是！）
>
>   ![image-20230323003531939](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230323003531939.png)

```C++
#include<iostream>
#include<algorithm>

using namespace std;

const int N  = 100010;

struct range
{
    int left,right;
    
    bool operator<(const range & r){
        return right < r.right;
    }
}ranges[N];

int n,ans;

int main()
{
    cin >> n;
    
    for(int i = 0;i < n;i ++){
        int x,y;
        scanf("%d%d",&x,&y);
        ranges[i] = {x,y};
    }
    
    sort(ranges,ranges + n);
    
    int st = -2e9;
    
    for(int i = 0;i < n;i ++)
        if(st < ranges[i].left){
            ans ++;
            st = ranges[i].right;
        }
        
    cout<<ans<<endl;
    
    return 0;
}
```

