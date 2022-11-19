## kruskal算法

1. 算法思想：

   > 此算法是基于边进行操作，所以每个顶点至少被访问一次，无需vis[ ]数组。也正因为此，所以其生成的最小生成树需要考虑内部是否存在环（一个点被多次访问）

2. 此算法基于边进行操作，所以数据类型定义成edges即可，再用自定义数据结构图（最好包含图的顶点个数以及边的条数）进行封装。

3. [](https://blog.csdn.net/the_ZED/article/details/105126583)：超强的并查集解释！

4. 此算法是利用kruskal算法思想，但是并不完全适用，因为并查集中，pre[x] = y;是指定方向的，即适用于有向图的最小生成树求解。而对于无向图的最小生成树的求解，所以需要将其进行简做修改：

   > 1.先将各个顶点是为只有根节点的树，其根节点就是自身序号.而对于需要合并的顶点，合并之后，并不需要谁为谁前驱（有向图求解就需要），仅需要用将各自顶底的根节点值改成相同，
   >
   > 根节点值相同的就为同一集合的顶点。如果再添加新的边，若是两个顶点的根节点相同，则表示其在同一棵子树中，因此不能连接。
   > 2.也因为无法规定方向，所以kruskal算法无法直接输入最小生成树的顶底顺序。仅能输出形成最小生成树的边。

```C++
#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>
#include<iomanip>
#include<algorithm>

#define vNum 20

using namespace std;

typedef struct Edge
{
    int v1,v2,w;
    Edge(int u1=0,int u2=0,int u=0):v1(u1),v2(u2),w(u){}
    bool operator<(Edge edge)const{
        return w<edge.w;
    }
}Edge;

typedef struct Gra
{
    Edge edge[vNum];
    int root[vNum];
    int e;				//图边的条数
    int v;				//图顶点个数
    Edge minTree[vNum];	 //记录形成最小生成树的边
}Gra;

int getroot(Gra g,int p)    //真的很妙
{
    while(p!=g.root[p])
        p = g.root[p];
    return p;
}

void InitEdges(Gra &g)
{
    fstream fs("test_input.txt",ios::in);
    int count =0;
    fs>>g.v;
    int v1,v2,w;
    while(fs>>v1>>v2>>w,v1!=-1)
    {
        g.edge[++count]={v1,v2,w};
    }
    g.e = count;
    for(int i =1;i<=g.v;i++)
    {
        g.root[i] = i;  //最初时，自己就是自己的根节点，同样，这也是getroot()函数判断顶点根节点的条件
    }
    fs.close();
}

void kruskal(Gra &g)   // 
{
    cout<<endl<<"kruskal算法 :"<<endl;
   sort(g.edge+1,g.edge+g.e+1);  //对<运算符进行重载  注意排序下标：sort(m,m+n) 为：[m,n)
   int count=0;
   for(int i=1;i<=g.e;i++)
    {   
         Edge temp = g.edge[i];
        if(g.root[temp.v1]!=g.root[temp.v2])        //即两个顶点不在同一棵树上
        {
           int num = g.root[temp.v1];
            g.minTree[++count] = temp;      //仅能将边和权值记录，无法按顺序输出
            for(int i=1;i<=g.v;i++)
            {     //不能是g.root[i]==g.root[temp.v1]  当i==temp.v1时，也满足条件，此时g.root[temp.v1]的值会发生改变，判断条件改变，结果就会改变
            		if(g.root[i]==num)  g.root[i]=g.root[temp.v2];     //将同一集合的顶点的节点标为相同值。
            }
        }             
    }
}

void showMinTree(Gra g)
{
    for(int i=1;i<g.v;i++)
    {
        cout<<g.minTree[i].v1<<" "<<g.minTree[i].v2<<" "<<g.minTree[i].w<<endl;
    }
}

int main()
{
   	Gra g1;
   InitEdges(g1);
    kruskal(g1);
   showMinTree(g1);
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
kruskal算法 :
2 4 1
5 6 2
1 3 3
2 6 5
1 2 6
*/
```



