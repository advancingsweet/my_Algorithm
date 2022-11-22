[AcWing 849. Dijkstra求最短路 I](https://www.acwing.com/activity/content/code/add/918/)

# 感悟：

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

4. 整体思想：

   ​       1.找到与起点s最近的且未确认[最短路径](https://so.csdn.net/so/search?q=最短路径&spm=1001.2101.3001.7020)的顶点(记为u)，访问并加入集合st(确定了最短路的集合)。

   ​       2.之后，令u为中介点，优化起点s与所有经过u可以到达的顶点v的最短距离。就如同Floyd算法，通过中介的将s和v直接连接成一条直线，而该条直线的权值就为其s到v的最短路径长，该长就保存在数组d中。思想与Floyd算法完全相同！



Dijkstra代码模板：

```c++
//朴素Dijkstra 邻接矩阵存储稠密图  
int g[N][N];//g[a][b]:a->b的权重 
int dist[N];//dist[i]:起点到i的距离 
bool st[N];//st[i]:i点是否已确定最短路 
 
void dijkstra(int u)//u为起点 
{
	memset(dist,0x3f,sizeof dist);//距离都初始化为很大的数 
	dist[u]=0;//u->u 距离为0 起点为0 
	
	for(int i=0;i<n;i++)//n个点 n次循环 
	{
		int t=-1;//t是距离最近的未确定最短路点的编号 
		for(int j=1;j<=n;j++)//遍历n个点 
			if(!st[j] && (t==-1 || dist[t]>dist[j]))//寻找最近的点 
				t=j;
		
		st[t]=true;//找到的点 确定了最短路 
		
		for(int j=1;j<=n;j++)//遍历n个点 用最新的点更新迭代所有出边  
			dist[j]=min(dist[j],dist[t]+g[t][j]);
 
	}
}
```

# 大佬代码（运用了模板）：

[代码出处](https://blog.csdn.net/PRML_MAN/article/details/114477814)

```C++
#include<iostream>
#include<cstring>
using namespace std;

const int N=510;

typedef struct Graph
{
    int edges[N][N],dist[N];
    bool vis[N];
    int n,m;
}G;

void InitG(G &g)
{
    scanf("%d%d",&g.n,&g.m);
    memset(g.edges,0x3f,sizeof(g.edges));
    while(g.m--)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g.edges[a][b]=min(g.edges[a][b],w);   //取重边的最小值
    }
}

void dijkstra(G &g,int u)
{
    memset(g.dist,0x3f,sizeof g.dist);
    g.dist[u]=0;
    for(int i=0;i<g.n;i++)
    {
        int t=-1;
        for(int j=1;j<=g.n;j++)
            if(!g.vis[j] && (t==-1 || g.dist[t]>g.dist[j]))
                t=j;

        g.vis[t]=true;
        
        for(int j=1;j<=g.n;j++)
            g.dist[j]=min(g.dist[j],g.dist[t]+g.edges[t][j]);
    }
}
 
int main()
{
    G g;
    dijkstra(g,1);
    if(g.dist[g.n]==0x3f3f3f3f) printf("-1\n");
    else printf("%d\n",g.dist[g.n]);
    return 0;
}
```

# 我的代码：

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
           if(!g.vis[i]) // 被访问过的顶点最小值已经确认，无需再访问；访问了也无妨，应为此已经时最小值，不会更改最小值的大小
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



