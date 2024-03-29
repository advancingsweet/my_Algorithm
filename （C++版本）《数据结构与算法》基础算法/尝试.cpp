```C++
# /*

fstream　　// 文件流
ifstream　 // 输入文件流
ofstream　 // 输出文件流
只用fstream 就对了
*/

#include<iostream>
#include<queue>
#include<fstream>   //打开文件一定要记得关闭文件
#include<iomanip>


#define vNum 10

using namespace std;

typedef struct UND{

    int edge[vNum][vNum];
    int v;
    int vis[vNum];
    int path[vNum];

}G;

void InitGraph(G& g)
{
    int v1,v2;
    fstream f("input.txt",ios_base::in);    //ios::in：文件以输入方式打开（文件数据输入到内存）
    f>>g.v;
    for(int i=0;i<g.v;i++)
    {
        g.vis[i] = 0;   //未被访问
        g.path[i] = -1; //路径
        for(int j=0;j<g.v;j++)
            g.edge[i][j] = 0;
    }

    while(f>>v1>>v2,v1!=-1)
    {
        g.edge[v1][v2] = 1;
        g.edge[v2][v1] = 1;   //初始图
    }
    f.close();
    return ;

}

int count =0;

void bfs(G &g,queue<int>&q)
{
    

    int st = q.front();
        q.pop();
    if(g.vis[st]) bfs(g,q);  //此举是为了防止同层次的顶点相互连接,同时，将重复存放在队列的顶点（除了第一次出现的之外）全部排除
    g.path[count++] = st;
    //cout<<st<<" ";
    g.vis[st] = 1;
    for(int i=0;i<g.v;i++)
    {
        if(!g.edge[st][i]||g.vis[i])  continue; //防止同层次的顶点，后序顶点再一次访问前序顶点
        q.push(i);              
    }
    if(q.empty())  return;
    bfs(g,q);

}

void write(G g)
{
    fstream fs("output.txt",ios::out);  //ios::out：文件以输出方式打开（内存数据输出到文件）
    for(int i=0;i<g.v;i++)
    {
        for(int j=0;j<g.v;j++)
        {
            fs<<setw(3)<<g.edge[i][j];
        }
        fs<<endl;    //文件跳行，不是cout<<endl;
    }
    fs<<"BSF访问顺序为: "<<endl;
    for(int i=0;i<g.v;i++)
        fs<<g.path[i]<<" ";
    fs<<endl;
    fs.close();
    return ;
}

int main()
{
    queue<int>q;
    q.push(3);
    G g;
    InitGraph(g);
    bfs(g,q);
    write(g);
}
```

