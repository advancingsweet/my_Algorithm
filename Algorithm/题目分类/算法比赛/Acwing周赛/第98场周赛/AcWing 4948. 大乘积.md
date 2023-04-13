# AcWing 4948. 大乘积   [原题链接](https://www.acwing.com/problem/content/4951/)

> 解题思路：
>
> ![image-20230413131030859](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230413131030859.png)
>
> 可知，如果是直接开long long 型数据变量，会直接爆数据范围，所以得利用字符串存储数据然后进行处理。而不是直接相乘求结果。	

### 我的代码

```C++   
#include<iostream>
#include<cstring>

using namespace std;

string s,m = "1";
int n,ans;

int main()
{
    cin >> n;
    for(int i = 0;i < n;i ++){ 
        cin >> s;
        if(s[0] == '0') {
            cout << 0 << endl;
            return 0;
        }
        if(s[0] != '1'){
            m = s;
            continue;
        } 
        int cnt = 0;
        for(int i = 1,len = s.size();i < len;i ++)
           {
                if(s[i] != '0'){
                    m = s;
                    break;
                }
                cnt ++;
                if(i == len - 1) ans += cnt;
           }
    }
    
    cout << m;
    for(int i = 0;i < ans;i ++) cout << 0;
    
    return 0;
}
```

