# Dijkstra算法理解：

1. **Dijkstra算法是基于顶点进行操作，且仅适合求一个顶点到其他任意顶点的最短距离，且其中权值不能有负数。**

   > > **最短路径Dijkstra算法和最小生成树Prim算法的相同点与不同点：**
   > >
   > > - 两个算法中每一个点都会遍历到，且每个点都只便利一次，所以会有标记访问数组vis[ ]。而标记访问数组是用来判读顶点是否被访问，将被访问过的顶点分到集合U中，未被访问的顶点在集合V-U中。
   > > - **Prim算法只求从源点出发到达所有顶点的最短路径，然后将到所以顶点的最短路径输出**
   > > - **而Dijkstra算法不仅记录了从源点出发到达所有顶点的最短路径，同时还记录了到每个顶点的最短距离（此为Dijkstra算法与Prim算法唯一的区别！）。但是Dijkstra仅是根据需求，输出源点到某个顶点的最短距离和最短路径**

   

2. 算法三部曲：

   - 1.updata（第一个值先于循环处理）  
   - 2.scan （寻找已有路径中最短路径）  
   - 3.add（将到未添加顶点的最短路径添加（添加的是顶点））

3. 对于ts[vNum] 数组（the shortest length) : 

   - 访问都是按照顶点之间的连接路径进行访问，所以所有访问的顶点都是在同一支路上。
   - ts[vNum]数值：表示的是从最初的顶点到某一点的距离，所以该距离有两种：
     - 1.从最初的顶点直接到达该顶点	
     - 2.从最初的顶点经过多个顶点到底该顶点。



```C++
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>

#define vNum 100
#define INF 0x3f3f3f3f

using namespace std;

int ts[vNum] = {0};     //记录从一顶点到其余顶点的最短距离

typedef struct Dijkstra{
    int edge[vNum][vNum];   //邻接矩阵
    int v;                  //顶点
    int vis[vNum];       // 标记访问数组
    vector<int>path;    //动态数组记录最短路径
}G;

void InitGraph(G& g)
{
    fstream fs("input.txt",ios::in);
    fs>>g.v;
    for(int i=0;i<g.v;i++)
    {
        g.vis[i]=0;
        for(int j=0;j<g.v;j++)
        {
            g.edge[i][j] = INF;
        }
    }
    int v1,v2,w;
    while(fs>>v1>>v2>>w,v1!=-1){
        g.edge[v1][v2] = w;
        g.edge[v2][v1] = w;
    }
    fs.close();
}

int Min(int *p,G g)  			//三部曲之二，scan最小值，并返回其下标
{
    int temp = INF,j;
    for(int i=0;i<g.v;i++){
        if(g.vis[i])  continue;		//一定要注意，访问过的顶点已被“添加”，所以不能再次添加，
        if(p[i]<temp) {
            temp = p[i];
            j = i;
        }
    }
    return j;
}

void Dijkstra(G &g,int st)    
{
    int count=1;				//第一个顶点在循环之外进行处理
        int i;
        g.vis[st]=1;     //若未被访问，则此刻被访问
        for(i=0;i<g.v;i++)
        {
            ts[i] = g.edge[st][i]; 
        }
        g.path.push_back(st);
    while(count!=g.v){
        count++;
        int miN = Min(ts,g);
        g.vis[miN] = 1;				
        g.path.push_back(miN);      //三部曲之三，.add
        int  sh = ts[miN];
        
         for(int i=0;i<g.v;i++)
         {
            if(ts[i]>g.edge[miN][i]+sh) 
                ts[i] = g.edge[miN][i]+sh;		//三部曲之一： updata
         }   
    }
    ts[st] = 0;
}

void Display(G g)
{
for(int i=0;i<g.v;i++)
    {
        for(int j=0;j<g.v;j++)
        {
            cout<<setw(14)<<g.edge[i][j];
        }
        cout<<endl;    
    }
    cout<<"最短距离 : "<<endl;
    for(int i=0;i<g.v;i++)
    {
        cout<<"["<<i<<"]"<<" : "<<ts[i]<<endl;
    }
    vector<int>::iterator it;   //迭代器
    cout<<endl<<"路径为 : "<<endl;
    for( it = g.path.begin();it < g.path.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    G g;
    InitGraph(g);
    Dijkstra(g,6);
    Display(g);
}

/*
#input.txt:
7
1 2 49
2 3 23
1 3 12
1 4 7
4 3 62
1 0 23
0 5 21
3 5 16
0 6 5
6 3 11
6 1 18
5 4 33
-1 -1 -1

#result:
最短距离 : 
[0] : 5
[1] : 18
[2] : 34
[3] : 11
[4] : 25
[5] : 26
[6] : 0

路径为 : 
6 0 3 1 4 5 2 

*/
```

