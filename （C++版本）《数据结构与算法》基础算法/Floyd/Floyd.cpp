```c++
#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

#define vNum 10
#define INF 0X3f3f3f3f

using namespace std;

typedef struct Graph{

    int edge[vNum][vNum];       //邻接矩阵
    int path[vNum][vNum];       //记录路径   表示含义： vNum1 -> path[vNum][vNum] -> vNum2  
    int v;
    int d[vNum][vNum];          //存放最短距离          
}G;

void InitGraph(G &g)
{
    fstream fs("input.txt",ios::in);
    fs>>g.v;
    memset(g.edge,0x3f,sizeof(g.edge));     //初始矩阵
    memset(g.d,0x3f,sizeof(g.d));
    for(int i=0;i<g.v;i++)
        for(int j=0;j<g.v;j++)
        {
            g.path[i][j] = -1;
        }
    int v1,v2,w;
    while(fs>>v1>>v2>>w,v1!=-1){
        g.edge[v1][v2] = w;
        g.edge[v2][v1] = w;
        g.d[v1][v2] = w;
        g.d[v2][v1] = w;
        g.path[v1][v2] = v1;    // 一定得对path数组进行初次处理
        g.path[v2][v1] = v2;
    }
    fs.close();
    return;

}
void Floyd(G &g)
{
        for(int k =0;k<g.v;k++)
            for(int i=0;i<g.v;i++)
                for(int j=0;j<g.v;j++)
                {
                    if(g.path[i][k]!=-1&&g.path[k][j]!=-1&&g.d[i][j] > g.d[i][k]+g.d[k][j])
                        {
                            g.d[i][j] = g.d[i][k]+g.d[k][j];
                            g.path[i][j] = k;
                        }
                }
}

void Path(G g,int v1,int v3)
{
    if(g.path[v1][v3]==-1)  return;
    if(g.path[v1][v3] == v1)
    {
        cout<<v1<<" ";
        return; }
    else{

        int k = g.path[v1][v3];
        Path(g,v1,k);
        Path(g,k,v3);
    }
}

void Search(G g,int v1,int v2)
{
    cout<<v1<<"到"<<v2<<"的最短距离为:"<<g.d[v1][v2]<<endl;
    cout<<v1<<"到"<<v2<<"的最路径离为:";
    Path(g,v1,v2);
    cout<<v2<<endl;
}

int main()
{
    G g;
    InitGraph(g);
    Floyd(g);
    int v1=2,v2=4;
    Search(g,v1,v2);
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

2到4的最短距离为:42
2到4的最路径离为:2 3 1 4

*/
```

