# [\859. Kruskal算法求最小生成树](https://www.acwing.com/problem/content/description/861/)

```C++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int N = 200010,M = 100010,INF = 0x3f3f3f3f;

int p[M];
int n,m;

struct Edges
{
    int a,b,w;
    
    bool operator<(const Edges& e)const 
    {
        return w < e.w;
    }
}edges[N];

int find(int x)  // 返回x的祖宗节点
{
    if(p[x]!=x) p[x] = find(p[x]); // 用父亲节点 = 祖宗节点 ，然后返回祖宗节点
    return p[x];
     /*
    	效率比：
    	while(p[x] != x) x = p[x];
    	return p;
    	快！
    */
}

void kruskal()
{
    
    int cnt = 0, res = 0;
    
    sort(edges,edges + m);
    
    for(int i = 1;i < M; i ++) p[i] = i; // 为什么是M,而不是m?  因为m条边中,顶点序号至少是1 ~ m+1
    
    for(int i = 0;i < m;i ++)
    {
        int a = edges[i].a, b = edges[i].b;
        a = find(a), b = find(b);  // 求a,b的根节点
        if(a != b){
            p[a] = b;           //
            res += edges[i].w;
            cnt++;
        }
    }
    if(cnt != n-1) cout<<"impossible"<<endl;
    else cout<<res<<endl;
}

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i = 0;i < m; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i] = {a,b,c};
    }
    
    kruskal();
    
    return 0;
}
```

# 思路详解

1. 算法思想：

   > 此算法是基于边进行操作，所以每个顶点至少被访问一次，无需vis[ ]数组。也正因为此，所以其生成的最小生成树需要考虑内部是否存在环（一个点被多次访问）

2. 此算法基于边进行操作，所以数据类型定义成edges即可，再用自定义数据结构图（最好包含图的顶点个数以及边的条数）进行封装。

3. [超强的并查集解释！](https://blog.csdn.net/the_ZED/article/details/105126583)

   此算法是利用kruskal算法思想，但是并不完全适用，因为并查集中，pre[x] = y;是指定方向的，即适用于有向图的最小生成树求解。而对于无向图的最小生成树的求解，所以需要将其进行简做修改：

   > 1.先将各个顶点是为只有根节点的树，其根节点就是自身序号.而对于需要合并的顶点，合并之后，并不需要谁为谁前驱（有向图求解就需要），仅需要用将各自顶底的根节点值改成相同，
   >
   > 根节点值相同的就为同一集合的顶点。如果再添加新的边，若是两个顶点的根节点相同，则表示其在同一棵子树中，因此不能连接。
   > 2.也因为无法规定方向，所以kruskal算法无法直接输入最小生成树的顶底顺序。仅能输出形成最小生成树的边。