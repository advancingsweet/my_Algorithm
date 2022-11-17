1. [https://blog.csdn.net/yuewenyao/article/details/81021319]:

   

2. 对于Floyd算法，

   ```c++
   typedef struct Graph{
       int edge[vNum][vNum];       //邻接矩阵
       int path[vNum][vNum];       //记录路径   表示含义： vNum1 -> path[vNum][vNum] -> vNum2    path值代表两个顶点之间的中间点
       int v;
       int d[vNum][vNum];         //存放最短距离 表示含义：从vNum1 -> vNum2 的最短距离         
   }G;
   ```

困惑点：

![]()	![问题](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\问题.jpg)

![](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\问题解答.jpg)

![]()

# 推理过程：

![](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\图一.png)

![](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\图二.png)

![](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\图三.png)



![](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\推理图二.jpg)

![](C:\Users\Hongwei Tang\Desktop\数据库大作业（第14周周末之前提交）\推理图一.jpg)





# Floyd思路：



```C++
int path[vNum][vNum];   //记录路径   表示含义： vNum1 -> path[vNum][vNum] -> vNum2    path值代表两个顶点之间的中间点，即：vNum1 通过path[vNum][vNum]与 vNum2直接相连接
int d[vNum][vNum];      //存放最短距离 表示含义：从vNum1 -> vNum2 的最短距离   
```

此数组保存的值，可以看作一条直线连接了 vNum1-vNum2 两个顶点，即两个顶点直接已经形成了一条直达路径，所以当vNum1与vNum2之间如果有多个顶点时，可以认为利用跳点，将各个顶点之间一一建立直接联系（新建立路径的权值是跳点到与其相连的两个顶点的权值之和），当跳点遍历完成之后，任意俩俩顶点全部都直接相连接，整个图已经变成了完全图，所以此时的d数组中存放的值是任意两点之间的最短距离。

