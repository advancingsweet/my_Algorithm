#  [AcWing 1113. 红与黑](https://www.acwing.com/problem/content/1115/)

## y总代码（dfs）

> **总结：**
>
> **1.第22行代码绝了！！！**
>
> ```C++
>   cnt += dfs(a,b);  // !!!!! 简直绝了！！！！ 
> ```
>
> **对比“我的代码（dfs）”，最初因为全局变量在处理一次之后没有及时更新，导致无法报错！**
>
> **此种书写方式真的绝了！！！！！！**

```C++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;
const int N = 30;

int h,w;
char g[N][N];
int dx[] = {0,-1,0,1},dy[] = {1,0,-1,0};

int dfs(int x,int y)
{
    int cnt = 1;
    g[x][y] = '#';
    for(int i = 0;i < 4; i++){
        int a = x + dx[i],b = y + dy[i];
        if(a >= w || a < 0 || b >= h || b <0) continue;
        if(g[a][b] == '#') continue;
        g[a][b] = '#';
        cnt += dfs(a,b);  // !!!!! 简直绝了！！！！ 
    }
    return cnt;
}

int main()
{
    while(cin >> w >> h,w){
        swap(w,h);
        int x,y;
        for(int i = 0;i < w;i ++){
            cin >> g[i];
            for(int j = 0;j < h;j ++)
                if(g[i][j] == '@') x = i,y = j;
        } 
        
        cout << dfs(x,y) << endl;
    }
    return 0;
}
```

## 我的代码（dfs)

> **自我总结：**
>
> **1.此题输入是连续输入，所以对于一些全局变量，需要及时初始化！**
>
> **2.dfs根本不需要保存，所以根本就不需要使用queue + pair，导致写的代码复杂而繁琐** 

```C++
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>

#define x first
#define y second

using namespace std;
typedef pair<int,int>PII;

const int N = 30;

int h,w;
char g[N][N];
int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
int ans = 1;

int dfs(PII start)
{
    queue<PII>p;
    p.push(start);
    while(p.size())
    {
        PII tep = p.front();
        p.pop();
        for(int i = 0;i < 4;i ++){
            int x = tep.x + dx[i],y = tep.y + dy[i];
            if(x >= h || x < 0 || y < 0 || y >= w) continue; // 数组越界
            if(g[x][y] == '#' || g[x][y] == '@') continue;  // 红砖，不能踩
            ans ++ ;
            g[x][y] = '#';// 已经被访问过
            dfs({x,y});
        }
    }   
    return ans;
}

int main()
{
    while(cin >> w >> h,w){
        PII start;
        ans = 1;   // 注意每次都得初始化一次！！！
        for(int i = 0;i < h;i ++ ) {
            cin >> g[i];
            for(int j = 0;j < w;j ++)
                if(g[i][j] == '@') start = {i,j};
        }
        int cnt = dfs(start);
        cout << cnt << endl;
    }
    return 0;
}
```

## 我的代码（bfs)

> **总结：**
>
> **1.对于坐标类问题，需要使用queue<pair(int,int)>q  存储坐标（x,y)**
>
> **2.对于图论问题，仅需要queue<int>保存顶点就可**
>
> **区别dfs：**
>
> **dfs对于上述两种问题，均是找到一个可遍历的位置（x1,y1)就直接进行遍历， 而不是等到与(x,y)相邻的位置均遍历了再遍历下一层，所以dfs无需利用queue进行保存**

```C++
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>

#define x first
#define y second

using namespace std;
typedef pair<int,int>PII;

const int N = 30;

int h,w;
char g[N][N];
int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};

int dfs(PII start)
{
    queue<PII>p;
    p.push(start);
    int cnt = 1;
    while(p.size())
    {
        PII tep = p.front();
        p.pop();
        for(int i = 0;i < 4;i ++){
            int x = tep.x + dx[i],y = tep.y + dy[i];
            if(x >= h || x < 0 || y < 0 || y >= w) continue; // 数组越界
            if(g[x][y] == '#' || g[x][y] == '@') continue;  // 红砖，不能踩
            cnt ++ ;
            g[x][y] = '#';// 已经被访问过
            p.push({x,y});  // bfs必须将每个节点保存起来，所以必须要用到queue + pair
        }
    }   
    return cnt;
}

int main()
{
    while(cin >> w >> h,w){
        PII start;
        for(int i = 0;i < h;i ++ ) {
            cin >> g[i];
            for(int j = 0;j < w;j ++)
                if(g[i][j] == '@') start = {i,j};
        }
        int cnt = dfs(start);
        cout << cnt << endl;
    }
    return 0;
}
```

