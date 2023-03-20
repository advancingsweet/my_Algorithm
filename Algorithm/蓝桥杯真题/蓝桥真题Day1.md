# 2023.3.20（距离蓝桥杯还有19天）

## 1.[P1508 - [蓝桥杯2020初赛\] 门牌制作 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1508)

```C++
/*
  也真是服了，居然一开始想的是手算？
  
  手算算不出来，居然枚举每一个位数，然后 int x = a * 1000 + b * 100 + c * 10 + d;  真的服了啊
*/
#include<iostream>

using namespace std;

int judge(int x)
{
    int cnt = 0;
    while(x){
        int re = x % 10;
        if(re == 2) cnt ++;
        x /= 10;
    }
    return cnt;
}
int main()
{
	int ans = 0;
    
    for(int i = 1;i <= 2020; i ++)  
        ans += judge(i);
   cout<<ans<<endl;

}
```

**************

## 2.[P1509 - [蓝桥杯2020初赛\] 既约分数 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1509)

[欧几里得演算法(辗转相除法)_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV19r4y127fu/?spm_id_from=333.788.recommend_more_video.0&vd_source=235a1e7b912d1c10826a324e11418122)

<img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230320153317180.png" alt="image-20230320153317180" style="zoom: 50%;" />

```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int GCB(int x,int y){  // 辗转相除法求最大公约数
	while(x%y){
		int z = x % y;
		x = y;
		y =  z;    // GCB(A,B) = GCB(B,R) = R. 若是B % R = 0; 则R为最大公约数
	}
	return y;	
}

int  ans；

int main()
{

	for(int i = 1;i <= 2020;i ++)
		for(int j = 1;j <= 2020;j ++)
			 if(GCB(i,j) == 1) ans ++;
	
	cout<<ans<<endl;
	return 0;
}
```

*****************

## 3.[P1510 - [蓝桥杯2020初赛\] 蛇形填数 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1510)

```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5100;

int dp[N][N];
int x = 1,y = 1;
int cnt;

int main()
{
	dp[x][y] = ++cnt;
	
	while(cnt <= 250000){
		// 向右偏移
		dp[x][++y] = ++ cnt; 
		
        // 向左下方偏移
		while(y > 1){     // 一定得是 y > 1; 如若y >= 1; 那么当y == 1时，会遍历到 dp[++x][0]   
			dp[++x][--y] = ++ cnt;  
		}
        
		// 向下偏移
		dp[++x][y] = ++ cnt ;
		
        // 向右上偏移
		while(x > 1){     // 一定得是 x > 1; 若是 x >= 1; 那么当x == 1时，会遍历到 dp[0][--y];  
			dp[--x][++y] = ++ cnt;
		}
	}
	cout<<dp[20][20]<<endl;
	return 0;
}
```

### 补充

### [AcWing 756. 蛇形矩阵 ](https://www.acwing.com/problem/content/description/758/)

```C++
/*
	我的代码  未ac
*/

#include<iostream>
using namespace std;

const int N = 110;

long long  dp[N][N];
int n,m;
long long ans = 1;
int x = 0,y = 0;

int main()
{
    cin >> n >> m;
    
    for(int i = 0;i <= n;i ++) dp[i][m] = -1;
    for(int i = 0;i <= m;i ++) dp[n][i] = -1;   // 将最外层用值包起来
    
    dp[0][0] = 1;
    
    while(ans <= n * m){
        //向右移动
       
        while(!dp[x][++y] && y < m){
            dp[x][y] = ++ ans;
        }
        if(dp[x][y]) y --;
        
        
        // 向下移动
        
        while(!dp[++x][y] && x < n){
            dp[x][y] = ++ ans;
        }
        if(dp[x][y]) x --;
        
        // 向左偏移
        
        while(!dp[x][--y] && y >= 0){
            dp[x][y] = ++ ans;
        }
        while( y == -1 || dp[x][y]) {
            cout<<y<<endl;
            y ++;  // 退回
        }
        // 向上偏移
        
        while(!dp[--x][y] && x >= 0){
            dp[x][y] = ++ ans;
        }
        while(x == -1 || dp[x][y])  ++ x; // 退回
        
    }
    
    cout<<endl;
    
    for(int i = 0;i <= n;i ++){
        for(int j = 0;j <= m;j ++){
            printf("%d  ",dp[i][j]);
        }
        puts("");
    }
    
    return 0;
}

```

***********

## 4.[P1511 - [蓝桥杯2020初赛\] 七段码 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1511)

### 考点：并查集、bfs、dfs、连通图、递归（类似开关问题)

![image-20230320193038520](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230320193038520.png)

```C++
/*
	思路：将各边看作点，然后各边相邻 <==> 各点相连接
	
	利用递归遍历所有种选择，对于每一个钟选择，利用并查集： 两点均被访问 且 两点之间相互联通加入一个集合（注意有可能是各集合的根节点相连）。
	
	最后通过遍历p[N]数组，查找 既被访问过的顶点以及用该顶点作为根节点的个数。 如果只有一个，那么表示只有一个连通子图，满足题意，如果有>= 2.那么不满足要求。
	
*/

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 10;

int g[N][N];
bool vis[N];
int p[N];
int ans,s;

int a[] = {1,2,1,6,6,5,6,7,2,7,2,3,7,5,7,3,5,4,4,3};
int cnt =sizeof(a)/sizeof(int);

int find(int x)
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void dfs(int u)
{
	if(u == 8){
		for(int i = 1;i <= 7;i ++) 	p[i] = i;
		for(int i = 1;i <= 7;i ++){
			for(int j = 1;j <= 7;j ++){
				if(g[i][j] && vis[i] && vis[j]) 
					u = p[find(i)] = p[find(j)] = min(find(i),find(j));
			}
		}
		int cnt = 0;
		for(int i = 1;i <= 7;i ++)
			if(vis[i] && p[i] == i)
				cnt ++;
		
		if(1 == cnt) ans ++;
		return;
	}	
			vis[u] = true;
			dfs(u+1);
			vis[u] = false;
			dfs(u+1);
}

int main()
{
	for(int i = 0,j = 1; i < cnt;){
		g[a[i]][a[j]] = g[a[j]][a[i]] = 1;
		i += 2,j += 2;
	}
	
	dfs(1);
	
	cout<<ans<<endl;
	
	return 0;
}
```

