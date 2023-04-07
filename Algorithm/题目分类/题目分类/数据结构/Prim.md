# 搜索与图论的模板

## 区别Prim算法和Dijkstra算法

[prim与dijkstra的区别](https://www.acwing.com/solution/content/131270/)

一、d[vNum] 的含义：

​	1.prim算法中，d[vNum]表示顶点到已选顶点集合的距离   (点到集合的距离)   （迭代n次，因为需要将n个顶点均加入集合中）

​		在最小生成树中，权重是正是负都可以

​	2.Dijkstra算法中，d[vNum]表示顶点到源点的距离 		（点到点的距离） （迭代n-1次，一开始就已经选择了一个点作为源点）

二、prim算法和dijkstra算法都是差不多都是基于 bfs 思路

三、prim 与 dijkstra 思路区别
dijkstra：把所有点到 源点 距离dis设成∞ ，每次找到dis最小的点 确定下来(加入到路径中)，并用该点距离更新所有点到源点距离 **dis[i]=min(dis[i],w+a[t][i])**;
即：用源点扩展，每次确定距离最近的点，直到终点！！

prim：  把所有点到 集合 的距离dis设成∞ ，每次找到dis最小的点 确定下来(加入到集合中)，并用该点距离更新所有点到集合距离 **dis[i]=min(dis[i],a[t][i])**;
即：随意找一个起点，每次确定到集合最近的点，直到所有点都确定完！！

由上面的思路区别，不难看出唯一区别就是，dijkstra 更新的是到源点的距离，prim更新的是集合到集合的距离。

## [858. Prim算法求最小生成树](https://www.acwing.com/problem/content/860/)

```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

bool vis[N];
int g[N][N];
int d[N];       // 存储其他点到当前最小生成树的距离
int n,m;

int Prim()
{
    memset(d,INF,sizeof d);  // 初始化各顶点到集合的距离
    
    int res = 0;
    d[1] = 0;  // 从那个顶点开始，那个顶点到集合的距离就为0！
    
    for(int i = 0; i < n;i ++)  // 遍历各个顶点到集合的最短距离
    {
        int t = 0;  
        
        for(int j = 1;j <= n;j ++)  //遍历各个顶点到集合的最短距离
            if(!vis[j] && d[t] > d[j])    //scan     第一次： d[0] == INF > d[1] == 0;
                t = j;     // t 为d[N]数组中的最小值的下标
        
        if(d[t] == INF) return INF;  // 说明当前图是不连通的
        vis[t] = true;  //add 
        res += d[t];
       
       for(int j = 1;j <= n;j ++)   // update
            d[j] = min(d[j],g[t][j]);    // min(d[i],g[t][i])中，d[i] 表示t还未加入集合时，集合到未加入点的距离
                                        // g[t][i] 表示t加入集合后，集合从点t到未加入点的距离
                                        // d[i] 为旧距离，g[t][i] 为新距离 但均是集合到为加入集合的点的距离
                                        // 之所以不用考虑自环，是因为考虑vis[t] 已经发生更改，一个点只能访问一次
    }
    return res;
}

int main()
{
    
    memset(g,0x3f,sizeof g);  // 带权图初始化为 INF
    
    scanf("%d%d",&n,&m);
    
    while(m -- )
    {
        int a,b,c;
        
        scanf("%d%d%d",&a,&b,&c);   // 存在重边，但是权值可能不同,且求最小生成树，所以应该取其最小值
        
        g[a][b] = g[b][a] = min(g[a][b],c); 
    }
    
    int res = Prim();
    
    if(res == INF) cout<<"impossible"<<endl;
    else cout<<res<<endl;
    
    return 0;
}
```

**对于代码第30行（if(d[t] == INF) return INF;）的解释:**

样例：

10 20
5 3 -8
9 6 -1
1 3 -1
8 7 -6
5 4 6
7 7 -4
4 5 2
10 7 -4
2 1 9
7 10 10
4 5 6
8 7 -7
4 2 -3
9 6 6
5 1 0
7 6 5
5 4 -3
10 8 3
5 3 2
7 8 -7

此为一个非连通图：

<img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230202110652942.png" alt="image-20230202110652942" style="zoom: 33%;" />

1. 当从顶点1开始，一直按规则遍历到顶点2时。在2之后的所有d[V]均为INF,即没有没有连通，对于非连通图，需要借此进行特判！！！！
2. 若在代码第29行加上 cout<<t<<" ";     输出结果：1 3 5 4 2 0      （t == 0 代表 没有满足第27行 if(!vis[j] && d[t] > d[j]) 条件的 j ）