[AcWing 849. Dijkstra求最短路 I](https://www.acwing.com/activity/content/code/add/918/)

## 感悟：

1. 有重边，则在求最短路径时，应该取其最小值

   ```C++
    for(int i=1;i<=g.e;i++)     //记录边的条数
       {
           scanf("%d%d%d",&v1,&v2,&w);
           g.edges[v1][v2] = min(w, g.edges[v1][v2]);   //记录重边的最小值
       }
   ```

2. 无法到底顶点n

   ```C++
   memset(g.d,0x3f,sizeof(g.d));
   
   if(g.d[g.v]!=INF    //若无法到达 顶点n，则g.d[n]的数据不会更新，认为初始值INF
           cout<<g.d[g.v];
       else cout<<-1;
   ```

3. 对于Dijkstra算法

   - 任何一个顶点都只访问一次（任何步骤中都只访问一次）



```C++
#include<iostream>
#include<cstring>

#define INF 0x3f3f3f3f
#define N 503
#define M 100003
#define st 1

using namespace std;

typedef struct Graph
{
    int edges[N][N];
    int vis[N];
    int d[N];
    int v;  //顶点个数
    int e;  //边的条数
}G;

void InitGraph(G &g)
{
    memset(g.edges,0x3f,sizeof(g.edges));
    memset(g.vis,0,sizeof(g.vis));
    memset(g.d,0x3f,sizeof(g.d));
    cin>>g.v>>g.e;
    int v1,v2,w;
    for(int i=1;i<=g.e;i++)     //记录边的条数
    {
        scanf("%d%d%d",&v1,&v2,&w);
        g.edges[v1][v2] = min(w, g.edges[v1][v2]);   //记录重边的最小值
    }
}

int find(G g)
{
    int temp = INF,j=0;
    for(int i=1;i<=g.v;i++)
    {
        if(temp>g.d[i]&&!g.vis[i])   //i要未被访问过
        {
            temp = g.d[i];
            j = i;
        }
    }
    return j;
}

void Dijkstra(G &g)
{
    for(int i=1;i<=g.v;i++)
    {
        g.d[i] = g.edges[st][i];   //updata
    }
    g.vis[st] = 1;  //
    int count = 1,j = -1;
    while(count!=g.v)
    {
        int ve = find(g);  //scan
        if(!ve) return;
        g.vis[ve] = 1; //add
        count++;
        for(int i=1;i<=g.v;i++)
        {
           if(!g.vis[i]) // 被访问过的顶点最小值已经确认，无需再访问
                  g.d[i] = min(g.d[i],g.d[ve]+g.edges[ve][i]);  //updata
        }
    }
}

int main()
{
    G g;
    InitGraph(g);
    Dijkstra(g);
    if(g.d[g.v]!=INF    //若无法到达 顶点n，则g.d[n]的数据不会更新，认为初始值INF
        cout<<g.d[g.v];
    else cout<<-1;
    
}
```



