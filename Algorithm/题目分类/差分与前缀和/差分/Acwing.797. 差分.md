# [Acwing.797. 差分](https://www.acwing.com/problem/content/799/)

> **[一、二维前缀和 && 一、二维差分](https://blog.csdn.net/m0_74215326/article/details/129620912?spm=1001.2014.3001.5502) **
>
> 完全不需要自己写题解了

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
        b[l] += c;
        b[r+1] -= c;
    }
    
    for(int i = 1;i <= n;i ++){
        a[i] = b[i] + a[i-1];
        printf("%d ",a[i]);
    }
    
    return 0;
}
```

