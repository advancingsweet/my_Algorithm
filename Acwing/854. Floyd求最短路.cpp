[854. Floyd求最短路](https://www.acwing.com/problem/content/856/)

# 1.Floyd算法感悟

1. 因为有重边，且此题为取最小值，所以在输入的时候取最小值即可

   ```c++
    while(g.e--)  //以下不需要用到边数，可以直接用g.e--
       {
           cin>>a>>b>>w;
           g.d[a][b] = min(g.d[a][b],w);		//去重边，取最小值
       }
   ```

   

2. Floyd算法可以对负权有向无环图使用，但因为存在：

   ```c++
   g.d[i][j] = min(g.d[i][j],g.d[i][k]+g.d[k][j]);  //其中，可能 g.d[i][j] =INF, 而 g.d[i][k] 与 g.d[k][j] 两个任意一个为负数，另外一个为 INF,那么仍会进行松弛操作，所以在输出时，判断条件应为：
    if(g.d[a][b]>INF/2) cout<<"impossible"<<endl;  // INF/2 仍然是一个很大的数值，仍可表示a,b之间无法到达
    if(g.d[a][b]==INF) cout<<"impossible"<<endl;   //此判断条件无法输出 impossible;
   
   /*
   输入：
   5 10 10
   1 5 10
   3 4 9
   3 2 10
   3 3 7
   3 1 5
   4 5 7
   1 2 -5				负数
   5 1 6
   4 3 8
   5 5 6
   4 1
   1 4
   5 2
   3 2
   5 4
   4 5
   2 2
   3 5
   3 1
   1 1
   
   输出：
   13
   1061109562   					此并非 impossible, 而是输出了 INF + (-5)
   1
   0
   impossible
   7
   0
   15
   5
   0
   
   标准答案：
   13
   impossible
   1
   0
   impossible
   7
   0
   15
   5
   0
   
   */
   ```

   

# 2.我的最初代码：（还是错误的，没有考虑负数的情况）

```c++
	#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int n = 203;
const int m = 20003;

typedef struct edge
{
    int a;
    int b;
    edge(int v1=-1,int v2=-1):a(v1),b(v2){}
}node;

typedef struct Graph
{
    int edges[n][n];
    int v;
    int e;
    int k;
    queue<node>q;
    int d[n][n];
}G;

void InitG(G &g)
{
    memset(g.edges,0x3f,sizeof(g.edges));
    memset(g.d,0x3f,sizeof(g.d));
    
    cin>>g.v>>g.e>>g.k;
    int a,b,w,i;
    for(i=1;i<=g.e;i++)
    {
        
        cin>>a>>b>>w;
        g.edges[a][b] = w;
        g.d[a][b] = w;
    }
    for( i=0;i<g.k;i++)
       {
           cin>>a>>b;
           g.q.push(node(a,b));
       }
}

void Floyd(G &g)
{
    for(int k=1;k<=g.v;k++)
        for(int i=1;i<=g.v;i++)
            for(int j=1;j<=g.v;j++)
                {
                    if(i!=j)//&&g.edges[i][k]>=0&&g.edges[k][j]>=0)
                        g.d[i][j] = min(g.d[i][j],g.edges[i][k]+g.edges[k][j]);
                    else g.d[i][j] = 0;
                }
}
int main()
{
    
    G g;
    InitG(g);
    Floyd(g);
    while(g.q.size())
    {
        node temp = g.q.front();
        g.q.pop();
        if(g.d[temp.a][temp.b]==0x3f3f3f3f) cout<<"impossible"<<endl;
        else cout<<g.d[temp.a][temp.b]<<endl;
    }    
}
```

# 3.最终代码：

```c++
#include<iostream>
#include<cstring>

using namespace std;

const int n = 203,m = 20003,INF=1e9;

int a,b,w;   //定义全局变量，可通用
typedef struct Graph
{
    int v,e,k;
    int d[n][n];
}G;

void InitG(G &g)
{
    cin>>g.v>>g.e>>g.k;
    memset(g.d,0x3f,sizeof(g.d));
    while(g.e--)  //以下不需要用到边数，可以直接用g.e--
    {
        cin>>a>>b>>w;
        g.d[a][b] = min(g.d[a][b],w);		//去重边，取最小值
    }
}

void Floyd(G &g)
{
    for(int k=1;k<=g.v;k++)
        for(int i=1;i<=g.v;i++)
            for(int j=1;j<=g.v;j++)
                {
                    g.d[i][j] = min(g.d[i][j],g.d[i][k]+g.d[k][j]);  //一定一定要注意，此为min(g.d[i][j],g.d[i][k]+g.d[k][j])；利用跳点，将i-j相连接，权值为从i直接或间接到j的最小距离。
                    if(i==j) g.d[i][j] =0;
                }
}
int main()
{
    G g;
    InitG(g);
    Floyd(g);
    while(g.k--)
    {
        cin>>a>>b;
        if(g.d[a][b]>INF/2) cout<<"impossible"<<endl;   
        else cout<<g.d[a][b]<<endl;
    }    
}
```

