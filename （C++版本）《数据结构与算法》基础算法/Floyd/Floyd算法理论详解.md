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

# 困惑点：



![[my_Algorithm/问题.jpg at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/问题.jpg)]()

![[my_Algorithm/问题解答.jpg at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/问题解答.jpg)](https://github.com/advancingsweet/my_Algorithm/blob/main/%EF%BC%88C%2B%2B%E7%89%88%E6%9C%AC%EF%BC%89%E3%80%8A%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E3%80%8B%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/Image/%E9%97%AE%E9%A2%98.jpg)

# 推理过程：

![[my_Algorithm/图一.png at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/图一.png)](https://github.com/advancingsweet/my_Algorithm/blob/main/%EF%BC%88C%2B%2B%E7%89%88%E6%9C%AC%EF%BC%89%E3%80%8A%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E3%80%8B%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/Image/%E9%97%AE%E9%A2%98%E8%A7%A3%E7%AD%94.jpg)

![[my_Algorithm/图二.png at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/图二.png)](https://github.com/advancingsweet/my_Algorithm/blob/main/%EF%BC%88C%2B%2B%E7%89%88%E6%9C%AC%EF%BC%89%E3%80%8A%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E3%80%8B%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/Image/%E5%9B%BE%E4%B8%80.png)

![[my_Algorithm/图二.png at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/图二.png)](https://github.com/advancingsweet/my_Algorithm/blob/main/%EF%BC%88C%2B%2B%E7%89%88%E6%9C%AC%EF%BC%89%E3%80%8A%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E3%80%8B%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/Image/%E5%9B%BE%E4%BA%8C.png)

![[my_Algorithm/图二.png at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/图二.png)](https://github.com/advancingsweet/my_Algorithm/blob/main/%EF%BC%88C%2B%2B%E7%89%88%E6%9C%AC%EF%BC%89%E3%80%8A%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E3%80%8B%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/Image/%E5%9B%BE%E4%BA%8C.png)

![[my_Algorithm/推理图一.jpg at main · advancingsweet/my_Algorithm (github.com)](https://github.com/advancingsweet/my_Algorithm/blob/main/（C%2B%2B版本）《数据结构与算法》基础算法/Image/推理图一.jpg)](https://github.com/advancingsweet/my_Algorithm/blob/main/%EF%BC%88C%2B%2B%E7%89%88%E6%9C%AC%EF%BC%89%E3%80%8A%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95%E3%80%8B%E5%9F%BA%E7%A1%80%E7%AE%97%E6%B3%95/Image/%E6%8E%A8%E7%90%86%E5%9B%BE%E4%B8%80.jpg)

# Floyd思路：



```C++
int path[vNum][vNum];   //记录路径   表示含义： vNum1 -> path[vNum][vNum] -> vNum2    path值代表两个顶点之间的中间点，即：vNum1 通过path[vNum][vNum]与 vNum2直接相连接
int d[vNum][vNum];      //存放最短距离 表示含义：从vNum1 -> vNum2 的最短距离   
```

此数组保存的值，可以看作一条直线连接了 vNum1-vNum2 两个顶点，即两个顶点直接已经形成了一条直达路径，所以当vNum1与vNum2之间如果有多个顶点时，可以认为利用跳点，将各个顶点之间一一建立直接联系（新建立路径的权值是跳点到与其相连的两个顶点的权值之和），当跳点遍历完成之后，任意俩俩顶点全部都直接相连接，整个图已经变成了完全图，所以此时的d数组中存放的值是任意两点之间的最短距离。

