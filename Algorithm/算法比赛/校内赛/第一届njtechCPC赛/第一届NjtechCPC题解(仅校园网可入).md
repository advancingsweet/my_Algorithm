# 第一届NjtechCPC(仅校园网可入)

[比赛详情 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/contest/64142356f98cbb3dc66d0539)

[第一届NjtechCPC题解 - 哔哩哔哩 (bilibili.com)](https://www.bilibili.com/read/cv22503861)



**************

# 一、洋洋的小目标

### [题目详情 - 洋洋的目标 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/23?tid=64142356f98cbb3dc66d0539)

​	![image-20230319171634417](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230319171634417.png)

```C++
#include<iostream>

using namespace std;

int main()
{
	cout<<"洋洋的小目标"<<endl;
	
	return 0;
}
```

**************************

# 二、洋洋的基因锁

### [题目详情 - 洋洋的基因锁 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/24?tid=64142356f98cbb3dc66d0539)

![image-20230319173220249](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230319173220249.png)

#### 输入样例1

```imput1
BCA
cad
b
```

#### 输出样例1

```output1
3
```

#### 输入样例2

```inmput2
ABCD
abcd
a
```

#### 输出样例2

```output2
1
```

## 比赛后的代码

```C++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e7+10;
char s,s1[N],s2[N];

int main()
{
	cin>>s1+1>>s2+1>>s;
    
    int cnt = 0;
    
    for(int i = 1;i <= strlen(s1); i++){
        if((int)s - 32 == (int)s[1]){
            cnt ++;
            s = s2[i];
        }
        else break;   
        /*
        比赛时脑子一糊涂，直接return 0； 导致样例二怎么都数不出来。
        第一次修改：在else 之中加入 cout<<cnt<<endl; 又把循环外的cout<<cnt<<endl; 过了样例2，但是样例又过不了
        第二次修改：在循环外面又加入一个cout<<cnt<<endl;  
        
        总结：真的服了，打得乱七八糟的
        */
    }
    cout<<cnt<<endl;

	return 0;
}
```

## 比赛的过程中提交的代码

```C++
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e7+10;

char s1[N],s2[N];
char s;

int main()
{
	cin>>s1>>s2>>s;
	
	int cnt = 0;
	
	for(int i = 0;i < strlen(s1);i ++)
	{
		if((s-32) == s1[i]){
			cnt ++;
			s = s2[i];
		}
		else {
			cout<<cnt<<endl;  // 写得跟个shi一样
			return 0;
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
}
```



****************************

# 三、洋洋的舞会

[题目详情 - 洋洋的舞会 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/26?tid=64142356f98cbb3dc66d0539)

![image-20230319173102896](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230319173102896.png)

#### 输入样例1：

```none
1 0 2
```

#### 输出样例1：

```none
1
```

#### 输入样例2：

```none
2 1 2
1 2
```

#### 输出样例2：

```none
2
```

#### 输入样例3：

```none
3 2 2
1 2
2 3
```

#### 输出样例3：

```none
4
```

## 1.赛后代码（1）

```C++
/*
	并查集
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

// 利用并查集图论
using namespace std;

const int N = 1010;

int p[N];
int n,m,k;
int cnt[N];
long long ans = 1; //因为数很大，所以最好取long long 作为数据类型
int INF = 1000000007;

int find(int x)    // 路径压缩，查找跟节点
{
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void combine(int x,int y)
{
	// 似乎没有考虑根节点合并的情况
	//p[x] = p[y] = min(find(x),find(y)); 仅仅是合并x,y单独两个点，若x,y属于两个集合，那么这样连接就会出现错误
	p[find(x)] = p[find(y)] = min(find(x),find(y));  // 1.将x,y单独两个点合并。 2.将x,y两个集合进行合并。
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i = 0;i <= n;i ++) p[i] = i;
	
	for(int i = 1;i <= m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		combine(x,y);	
	}
	
	int val = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(p[i] == i){  // 发现根节点 
			for(int j = 1;j <= n;j ++){   
			//没有考虑根节点合并的情况	if(p[j] == i && i != j) cnt[i] ++;  统计每个连通分量的节点个数
			   if(find(j) == i && i != j) cnt[i] ++;
			}
			val += cnt[i];  // 将连通分量的生成最小生成树的边数相加
		}	
	}
	
	for(int i = 1;i <= val;i ++)
		{
			ans *= k;
			ans %= INF;    // 边乘边取余，防止爆内存
		}
	
	cout<<ans<<endl;
	
	return 0;
}
```

## 赛后代码（2）

```C++
/*
	dfs(深度优先搜索)  但仅过了7组数据，还有13组数据没过
	
	原因： ans 的数据范围开的是 int 。尽管是边乘变取余，但是也存在乘法已经爆了，无法取余的情况存在
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int vis[N]; 
int n,m,k;
int g[N][N];
// int ans = 1;  错误
long long ans = 1;
int cnt;
int INF = 1000000007;

void dfs(int u)
{
	vis[u] = 1;	
	for(int i = 1;i <= n; i++)
		if(!vis[i] && g[u][i]) dfs(i);
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i = 1;i <= m;i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x][y] = g[y][x] = 1;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(!vis[i]){
			cnt ++;
			dfs(i);
		}
	}
	for(int i = 1;i <= (n-cnt);i++){
		ans *= k;
		ans %= INF;
	}
	cout<<ans<<endl;
	
	return 0;
}
```



## 2.提交的代码

```C++
/*
	比赛过程中仅仅想：过滤掉重复认识的同伴： 类似 2-3 与 3-2 组合。每一组仅计算一次。 （错误）
					仅考虑了认识关系是否重合（边是否重合） 
					未考虑同伴与同伴的认识关系是否构成闭环（图存在环）  ： 1-2， 2-3，3-1。但是，当1，2都比3先到时，仅算1-2与（1，2）-3 两次
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1010;
int n,m,k;
int g[N][N];
int INF =1000000007;
int ans = 1;

int main()
{
	cin>>n>>m>>k;
	
	for(int i = 1;i <= m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(g[x][y]) continue;
		else {
			g[x][y] = g[y][x] = 1;  //x,y相互认识
			ans *= k;
	}
	}
	
	cout<<(ans%INF)<<endl;
	
	return 0;
}
```

****************

# 四、洋洋的决斗（不会）

[题目详情 - 洋洋的决斗 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/27?tid=64142356f98cbb3dc66d0539)

*******************

# 五、NO ONE WIN! (不会)

[题目详情 - NO ONE WIN！ - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/25?tid=64142356f98cbb3dc66d0539)