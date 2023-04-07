# [AcWing 1101. 献给阿尔吉侬的花束](https://www.acwing.com/problem/content/1103/)

> **题目总结：**
>
> **1.对于迷宫类最优解问题优先考虑bfs，层次遍历，每一层的step都是1**
>
> ```C++
> dist[a][b] = dist[t.x][t.y] + 1;     // 第34行代码，核心代码！
> ```
>
> **2.对于dfs，适用于迷宫是否能走通，但所经过的路程并非最优解**
>
> **3.对于pair + queue 的使用**
>
> **4.不要思想局限，迷宫等同于图，只是每一个点均有多个临界点罢了**
>
> **5.走迷宫常用偏移量**

## y总代码

```C++
#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>

#define x first
#define y second

using namespace std;
typedef pair<int,int>PII;
const int N = 210;

int n,m,t;
char g[N][N];
int dist[N][N];
int dx[] = {0,1,0,-1},dy[] = {-1,0,1,0};

int find(PII start,PII end)
{
    queue<PII>p;
    memset(dist,-1,sizeof(dist));
    p.push(start);
    dist[start.x][start.y] = 0;  // 初始化
  
    while(p.size()){
        PII t = p.front();
        p.pop();
        for(int i = 0;i < 4;i ++){
            int a = t.x + dx[i],b = t.y + dy[i];
            if(a < 0 || b < 0 || a >= n || b >= m) continue; // 数组下标越界
            if(dist[a][b] != -1) continue; // 被访问过
            if(g[a][b] == '#') continue; // 撞墙
            dist[a][b] = dist[t.x][t.y] + 1;     // 核心代码！！！
            if(end == make_pair(a,b)) return dist[a][b];
            p.push({a,b});
        }
    }
    return -1;
}

int main()
{
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        PII start,end;
        for(int i = 0;i < n; i++){
            scanf("%s",g[i]);
            for(int j = 0;j < m;j ++){
                if(g[i][j] == 'S') start = make_pair(i,j);
                if(g[i][j] == 'E') end = make_pair(i,j);
            }
        }
        int distance = find(start,end);
        if(distance == -1) cout <<"oop!" << endl;
        else cout << distance << endl;
    }
    return 0;
}
```



## 我的代码

> **看完y总的代码的总结：**
>
> **1.个人思路类似于dfs，但是根本就就有想明白。**
>
> **2.同时，思考到了自己的思路并非最优解，有点类似递归的味道。（发现走不通，那就返回）**
>
> **3.无法确定是否能走通！完全是无脑的增大循环次数（肯定有问题，而且还不敢增大，怕TLE)**
>
> **总结：啥也不会，没有思路，做少了，胡思乱想**

```C++
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace  std;

const int N = 210;

char g[N][N];

int r,s,n,res;
int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

bool eat(int x,int y)
{
    int step = 0;
    for(int i = 0;i <= s * r; i++){
        x += dx[step],y += dy[step];
        if(x < 0 || y < 0 || x >= r || y >= s || g[x][y] == '#')
        {
            x -= dx[step],y -= dy[step];
            step = (step + 1) % 4;
            res --;
        }
        res ++;
        if(g[x][y] == 'E') return true;
    }
    return false;
}

int main()
{
    cin >> n;
    while(n -- ){
        cin >> r >> s;
        int x,y;
        for(int i = 0 ;i < r ;i ++){
            scanf("%s",&g[i]);
            for(int j = 0; j < s;j ++)
                if(g[i][j] == 'S'){
                    x = i,y = j;
                    break;
               }
        }
        res = 0;
        if(eat(x,y)) cout << res << endl;
        else cout << "oop!" << endl;
    }
    return 0;
}
```

