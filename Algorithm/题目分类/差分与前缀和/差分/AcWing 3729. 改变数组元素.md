# [AcWing 3729. 改变数组元素](https://www.acwing.com/problem/content/3732/)

> **知识点：**
>
> **1.[memset的用法详解](https://blog.csdn.net/weixin_44162361/article/details/115790452?ops_request_misc=%7B%22request%5Fid%22%3A%22167979340316800226597156%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=167979340316800226597156&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-115790452-null-null.142^v76^insert_down2,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=memset函数&spm=1018.2226.3001.4187)**

## 1.(8 / 10) [Time Limit Exceeded](https://www.acwing.com/problem/content/submission/code_detail/23680194/)

> 直接爆搜，没有技巧，全是感情

```C++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 200010;

int T,n;
int a[N];
int v[N];
int head,rear,p;

int main()
{
    cin >> T;
    
    while(T--){
        
        memset(v,0,sizeof v);  // 全部初始化为0
        
        cin >> n;
        
        head = 1,rear = n,p = 1;
        
        for(int i = 1;i <= n;i ++) 
           {
               scanf("%d",&a[i]);
               
               if(i <= a[i]) memset(v,1,sizeof i);
               
               for(int j = i;j >= i - a[i] + 1;j --) v[j] = 1;
           }
        for(int i = 1;i <= n;i ++) printf("%d ",v[i]);
        
        puts("");
    }
    
    return 0;
}
```

