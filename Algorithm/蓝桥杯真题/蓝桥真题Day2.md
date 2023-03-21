# 2023.3.21（距离蓝桥杯还有18天）

## 1.[P1550 - [蓝桥杯2021初赛\] 卡片 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1550)

### 2.思路（总耗时：50min)

> 1.最初思路:
>                 0-9每种数字有2021次选择.使用之后就不能再使用.利用递归进行排序. 此方法根本无法实现：因为此方法无法体现拼凑数字的连续性。且递归条件也无法确定
>
>  2.第二次思路：
>
> ​	因为拼凑的数字要求是连续的，所以直接从0遍历到一个较大（根本不可能实现的的数）。然后再统计每一项所使用的数字。统计完之后再输出
>
> 3.第三次思路：
>
> - 题目要求从1开始遍历！！！
> - 数字是连续的，如果不连续应该立即输出（数字可能没有用尽）！！！而不是等循环结束再输出。如果等循环再输出，题目应该是如果将所以数字用尽那么能拼凑出多少数字。
>
> ```C++
> // 一旦拼凑不连续就立即输出：
> 3181
> 0 : 1093
> 1 : 0
> 2 : 82
> 3 : 901
> 4 : 1083
> 5 : 1083
> 6 : 1083
> 7 : 1083
> 8 : 1090
> 9 : 1093
>     
> // 一旦数字用尽就立即输出：
> 4701
> 0 : 0
> 1 : 0
> 2 : 0
> 3 : 0
> 4 : 0
> 5 : 0
> 6 : 0
> 7 : 0
> 8 : 0
> 9 : 0
> ```
>
> 

```C++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int num[10]，ans;

bool check(int i)
{
	if(!i && num[i]){
		 num[i]--;
		 cnt[i] ++;
	}
	while(i){  // 非0才能进入
		int x = i % 10;
		i /= 10;
		if(!num[x]) return false;
		num[x] --;
		cnt[x]++;
	}
	if(num[i] < 0) return false;
	return true;
}

int main()
{
	for(int i = 0;i <= 9; i ++) {
		num[i] = 2021;
	}
	
	for(int i = 1;i <= 1000000;i ++)
	{
		if(check(i)) {
			ans ++;
		}
		else {
			cout<<ans<<endl;
			return 0;
		}
	}
	return 0;
}
```

*****************

##  2.[P1551 - [蓝桥杯2021初赛\] 直线 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1551)

### [C语言（C++）中：详解floor函数、ceil函数和round函数_dangzhangjing97的博客-CSDN博客](https://blog.csdn.net/dangzhangjing97/article/details/81279862?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-81279862-blog-115407859.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-81279862-blog-115407859.pc_relevant_default&utm_relevant_index=1)

### (1.我的错误代码

> 我的思路：
>
> （斜率，截距） 确定唯一的一条直线
>
> 1.斜率不存在的直线数量 == 横坐标的个数
>
> 2.遍历dy，dx，（等同于遍历 k），然后再遍历（x,y), 将所有的（斜率，截距）组合存储起来。然后再将其组合按照斜率、截距的从小到大排序。最后去除相同的（斜率，截距）组合，从而得到的就是不重合的直线

```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>

using namespace std;

const int N = 1000000;

int ans = 20; // 斜率不存在的情况有20种
int cnt;

struct line
{
	double k;// 斜率
	double y; // 截距
	bool operator<(const line &l)const{
		if(k != l.k) return k < l.k;
		return y < l.k;
	}
}lines[N];

int main()
{
	for(double dx = 1;dx <= 19; dx ++)   // dx
		for(double dy = 0;dy <= 20; dy ++)  // dy
		{
			for(double x = 0;x <= 19;x ++) // 横坐标
				for(double y = 0;y <= 20;y ++){ // 纵坐标	
					lines[cnt++] = { dy * 1.0 / dx,y - x * dy * 1.0 / dx};
				}
		}
    
	sort(lines,lines + cnt);
	
	double k = lines[0].k,y = lines[0].y;
	for(int i = 1 ;i < cnt; i ++){
		if(lines[i].k == k && lines[i].y == y) continue;
		ans ++;
		k = lines[i].k, y = lines[i].y;	
	}
	
	cout<<ans<<endl;
	
	return 0;
}
```



********

## 3.[P1552 - [蓝桥杯2021初赛\] 货物摆放 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1552)

### （1.知识点

> 判断是否是素数、求一个数的所有因式
>
> ![image-20230321164723214](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230321164723214.png)
>
> 1.暴力枚举
>
> ```C++
> long long x = 1234567890123456;  
> long long gcb[100000];
> int cnt = 0;
> for(long long  i = 2;i < x;i ++)
>      if(x % i == 0) gcb[cnt++] = i;
> ```
>
> 暴力枚举直接把计算机干爆。
>
> 2.试除法
>
> ```C++
> long long x = 1234567890123456;  
> long long gcb[100000];
> int cnt = 0;
> for(long long  i = 2;i < x / i;i ++)
>      if(x % i == 0){   // 已经证明i, x/i两个数均是x的因数
>          gcb[cnt++] = i;
>          if(i * i != x) gcb[cnt++] = x / i;  // 如果 i != x/i，那么也应该将 x/i存入。如果相等，由于每一个因数只存放一次，所以相等时不能进行存放
>      } 
> ```
>
> 细节总结
>
> - 循环变量的数据类型得用 long long 型
>
> - ```C++
>   for(long long  i = 2;i < x / i;i ++) 
>       // 如果是 i < sqrt(x), 那么循环一次调用一次函数，效率太低
>       // 如果是 i * i < x; 那么可能 前一轮i * i 未爆long long,但是下一轮 (i+1) * (i+1) 直接干爆 long long 存储内存
>   ```
>
> 3.[y总证明yyds！！！](https://www.acwing.com/video/291/)
>
> 4.[【算法拾遗】试除法 （数学推理法）](https://zhuanlan.zhihu.com/p/60745545)

### （2.题目解答

> 本题思路及总结：
>
> 1. 以后凡是碰到很大很大的数据，所有定义均用long long 类型。包括循环变量！！！
> 2. 此题主要思想是求数n的因数，同时寻找出三个因数，使得其乘积等于n。一定一定要注意，从样例中可以看出，因数可是重复使用。如果不能重复使用，那么可以开一个vis[cnt]数组。序号和存放因数的序号相对应，使 vis[cnt]直接初始化为false即可。

```C++
#include<iostream>

using namespace std;

typedef long long LL;

LL INF = 2021041820210418;
LL p[1000000];   //一定得要LL数据类型。 2021041820210418/2 为LL型等
int cnt;

int main()
{
	for(LL i = 1;i < INF / i;i ++)
		if(INF % i == 0){
			p[cnt++] = i;
			if(i * i != INF) p[cnt++] = INF / i;
		}
		
	int ans = 0;
	
	for(int i = 0;i < cnt;i ++)
		for(int j = 0;j < cnt;j ++)
			for(int k = 0;k < cnt;k ++)
				if(p[i] * p[j] * p[k] == INF) ans ++;
	
	cout << ans <<endl;
	
	return 0;
}
```

*************

## 4.[P1553 - [蓝桥杯2021初赛\] 路径 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1553)

### （1.知识点

>1.  最小公倍数 = n和m的乘积除以最大公约数;
>
>   ```C++
>   int gcb(int n,int m)
>   {
>       while(n % m){   // 余为0就代表整除
>           int z = n % m;
>           n = m;
>           m = z;
>       }
>       return m;
>   }
>   
>   int com(int n,int m)
>   {
>       return n * m / gcb(n,m);
>   }
>   ```
>
>   
>
>2. 求最大公约数——辗转相除法
>
>   ```C++
>   int gcb(int n,int m)
>   {
>       while(n % m){   // 余为0就代表整除
>           int z = n % m;
>           n = m;
>           m = z;
>       }
>       return m;
>   }
>   ```
>
>3.  [dijkstra算法详解](https://www.acwing.com/solution/content/5806/)

 ###  (2 解题

> - 一定一定记得带权图初始化为INF！！！！ 
>
> - 无权图初始化为0，代表两点之间不相连
>
> - 有向图无向图
>
>   ```C++
>   g[x][y] = g[y][x] = w;  // 无向图
>   
>   g[x][y] = w;  // 有向图
>   ```

```C++
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

const int N = 2022;

int g[N][N];
long long d[N];
int INF = 0x3f3f3f3f;
bool vis[N];

//****************************************

int gcb(int n,int m)
{
	while(n % m){
		int z = n % m;
		n = m;
		m = z;
	}
	return m;
}

int com(int n,int m)
{
	return n * m / gcb(n,m);
}

void dijkstra(int st)
{
	memset(d,0x3f,sizeof d);
	
	d[st] = 0;  
	
	for(int i = 1;i < 2022;i ++){
		
		int t = -1;  // 最短
		
		for(int j = 1;j < 2022;j ++)
			if(!vis[j] && ( t == -1 || d[j] < d[t])) t = j;
		
		vis[t] = 1;
		
		for(int k = 1;k < 2022;k ++)
			d[k] = min(d[k],d[t] + g[t][k]);  // d[k] 从st 到 k 的距离， d[t] + g[t][k]  从 st 到 t 再到 k 的距离。			
	}
}

//*****************************************

int main()
{
	memset(g,0x3f,sizeof g);
	
	for(int i = 1;i < N;i ++)   // 初始化
		for(int j = 1;j < N;j ++)
			if(abs(i-j) <= 21) 
				g[i][j] = g[j][i] = com(i,j);
			
			
	dijkstra(1);
			
	cout<<d[2021]<<endl;
	
	return 0;
}
```

