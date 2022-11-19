## Prim算法心得：

1. Prim三部曲：

  - updata                           代码第36行，第一个updata (因为第一个元素是手动选定)
  - scan                              代码第65行，scan
  - add                               代码第66行，add

2. d[i]仅仅表示从集合U到集合V-U的最短距离

3. 该算法采用贪心算法，利用局部最优求全局最优解，所以当在求局部最优遇到”套娃“的情况等情况时，请重新回想一下全局求解的思路。因为贪心算法是基于全局求解思路进行求解！！！（解决此问题时，自己被局部问题困扰了很久，没有及时回想到全局求解的思路，浪费了大量不必要的时间去琢磨带有“套娃”味道的各种奇怪问题）

4. Prim算法中顶点仅只能被访问一次，所以需要标记访问数组vis[ ],

5. 一定要记得初始自定义数据结构中的各数据（本人第一次写此代码在这上面吃了不少亏）

6. **Prim算法是基于顶点进行操作，且每一个顶点只能访问一次（即每个顶点就能有一个度），所以无需考虑生成的最小生成树中存在环的情况。 （此为kruskal算法最大的区别！）kruskal算法是基于边进行考虑，所以每个顶点被访问的次数至少为一次，因此需要考虑其生成的最小生成树是否存在环的情况**

7. Prim算法与Dijkstra算法的区别：![[my_Algorithm/Dijkstra（first）.cpp at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Dijkstra/Dijkstra（first）.cpp)]()

  

```C++
#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>
#include<iomanip>
#include<algorithm>

#define INF 0x3f3f3f3f
#define vNum 20
#define st 4

using namespace std;

typedef struct Graph
{
    int edge[vNum][vNum];
    int v;
    int vis[vNum];						   //标记访问数组，区分顶点是在U集合中还是在V-U集合当中
    int d[vNum];   							//d[i]仅仅表示从集合U到集合V-U的最短距离
}G;
void InitGraph(G &g)
{
    fstream fs("test_input.txt",ios::in);
    fs>>g.v;
    memset(g.edge,0x3f,sizeof(g.edge));
    memset(g.d,0x3f,sizeof(g.d));
    memset(g.vis,0,sizeof(g.vis));
    int v1,v2,w;
    while(fs>>v1>>v2>>w,v1!=-1)
    {
        g.edge[v1][v2] = w;
        g.edge[v2][v1] = w;         //无向图
    }
    for(int i=1;i<=g.v;i++)
     {
        g.d[i] = g.edge[st][i];         //对数组d进行初始化（图构建成之后的初始化）  updata
     }  
    fs.close();
}

int Min(G g)
{
    int temp = INF,j=-1;
    for(int i =1;i<=g.v;i++)
    {
        if(temp>g.d[i]) 
        {   
            temp = g.d[i];
            j = i;
        }
    }
    return j;
}

queue<int>q1;
void Prim(G &g,int s)
{
    cout<<"Prim算法:"<<endl;
    g.vis[s] = 1;
    q1.push(s);
    g.d[s] = INF;                 
    int cnt = g.v -1;
    while(cnt--)
    {
        int miN = Min(g);           //scan
        q1.push(miN);               //add
        for(int i=1;i<=g.v;i++)     //updata
        {
            //if(g.edge[miN][i]<g.d[i]&&!g.vis[i])  //被访问的顶点都被收录到了集合U中：用g.vis[] = 1 表示； 同时，更新时得找新加入的顶点与V-U集合相连接的点;
         // g.d[i]仅仅表示从集合U到集合V-U中顶点i的距离; g.edge[miN][i]<g.d[i] 解决 V-U 结合中有一个点到U集合有多条路径，并选取最短的一条路径进行保存          
           if(!g.vis[i]&&g.edge[miN][i]!=INF)
           {
                g.d[i] = g.edge[miN][i];
            }
        }
        g.vis[miN] = 1;
        g.d[miN] = INF;
    }
}

void show(G g)
{
    for(int i =1;i<=g.v;i++)
    {
        for(int j=1;j<=g.v;j++)
        {
            cout<<setw(15)<<g.edge[i][j];
        }
        cout<<endl;
    }
}

void Display(G g)
{
    cout<<"最小生成树为 : "<<endl;
    while(!q1.empty())
    {
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
}

int main()
{
    G g;
    InitGraph(g);
    Prim(g,st);
    Display(g);
}

/*
#input.txt:
6
1 2 6
1 3 3
2 4 1 
2 6 5
4 3 6 
4 6 5  
5 3 6 
5 6 2
-1 -1 -1

#result:

Prim算法:
最小生成树为 : 
4 2 6 5 1 3 

*/
```

