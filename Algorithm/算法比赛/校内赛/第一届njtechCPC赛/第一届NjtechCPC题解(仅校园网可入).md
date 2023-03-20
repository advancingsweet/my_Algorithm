# 第一届NjtechCPC(仅校园网可入)

[比赛详情 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/contest/64142356f98cbb3dc66d0539)

[第一届NjtechCPC题解 - 哔哩哔哩 (bilibili.com)](https://www.bilibili.com/read/cv22503861)

![比赛结果](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230320000347832.png)

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

# 四、洋洋的决斗

[题目详情 - 洋洋的决斗 - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/27?tid=64142356f98cbb3dc66d0539)

![image-20230319232149112](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230319232149112.png)

## 输出

最终扮演那个角色会赢，Allice/Bob

## 输入数据 1

```input1
14 5
7 13 1 6 14 2 16 17 18 19 34 36 20 23
```

## 输出数据 1

```output1
Alice
```

## 输入数据 2

```input2
14 5
14 20 12 6 0 16 8 11 9 17 13 3 5 19
```

## 输出数据 2

```output2
Bob
```

## 1.赛后代码

```C++
/*
	思路：两个人往集合s中填数，n轮后。
		不在s中的最小自然数如果为奇数， Alice胜
					    如果为偶数，Bob胜
			所以如果Alice 想赢，那么Alice就应该尽量去把不在集合s中得偶数填完,才能确保不在s中的最小自然数如果为奇数，从而让自己赢。
			 而如果Bob想赢，那么Bob就应该尽量去把不在集合s中得奇数填完,才能确保不在s中的最小自然数如果为偶数，从而让自己赢。
	
	1.跟谁先插入数没有关系吗？  没有关系。
	
	原因： A,B两人都是分别从最小的偶数、奇数开始填，所以两者填的数字互不干涉。且需要填的位置明确且也互不干涉。==> 谁先填谁后填所得到的最终结果一样。
	
	而如果不限制填充次数，直到填到数组满足某一条件为止，那么就得考虑先后问题了
	
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 200010;

int n,m;
bool vis[N];

int main()
{
	cin>>m>>n;
	
	for(int i = 1;i <= m;i ++) 
		{
			int x;
			scanf("%d",&x);
			vis[x] = 1;
		}
	
	int minOdd = 1,minEven = 0;  // 遍历奇数、偶数
	
	while(vis[minOdd]){  // 遍历奇数
		minO += 2;
	}
	
	while(vis[minEven]){ // 遍历偶数
		minEven += 2;
	}
	
	for(int i = 1;i <= n;i ++){
		
		vis[minOdd] = true;
		minOdd += 2;
		
		while(vis[minOdd]){
			minOdd += 2;
		}
		
		vis[minEven] = true;
		while(vis[minEven]){
			minEven += 2;
		}		
	}
	
	if(minOdd > minEven) printf("Bob\n");
	else printf("Alice\n");
	
	
	return 0;
}
```

*******************

# 五、NO ONE WIN! (动规，好难！)

[题目详情 - NO ONE WIN！ - NjtechOnlineJudge](https://acm.online.njtech.edu.cn/p/25?tid=64142356f98cbb3dc66d0539)

## 结题思路（师父）：

> dp[i][j] 表示有i个人的时候，血量上限是j的时候有多少种没有人赢的方案数字
>
> 在开始第一轮攻击的时候，设这一轮中共有n个人，初始血量上限是x。那么第一轮下来，没人都需要扣掉n-1滴血量(每个人都是同时发起攻击，攻击顺序没有先后）。并且会死若干人，假设死亡人数为k，那么k = 0 - n 之间的数字。
>
> 假设把第二轮看成是一个从头开始的游戏，那么可以推测出dp[n][x]一定会和dp[n-k][x-(n-1)]存在某种递推关系。
>
> 在第一轮攻击结束后，接着把其结束状态当做是新的一场游戏，那么人数就是n-k个，血量上限是x-(n-1).问题思考又与上面重合。
>
> 接着我们对于每一轮攻击，去枚举死亡人数，死了哪几个，死的人初始血量是多少。得到递推公式：
>
> dp[i][j] = sigma k=0 to i (dp[i-k][j-(i-1)]*C(k,n)*power(i-1,k))；

![image-20230320201809997](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230320201809997.png)

## 代码1（解释在哔哩哔哩链接中）

```C++
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll E = 998244353;

const int N = 510;

ll n,x;
ll dp[N][N];
ll combinator[N][N];
ll qpower[N][N];


int main()
{
	ll ans;
	
	scanf("%lld%lld",&n,&x);
	
	for(ll i = 1;i <= 500; i ++{
		for(ll j = 0; j <= i;j ++){
			if(j == 0 || j == i){
				combinator[i][j] = 1;
				continue;
			}
			combinator[i][j] = (combinator[i-1][j-1] + combinator[i-1][j])%E;
		}
	)
	
	for(ll i = 0;i <= 500;i ++){
		for(ll j = 0;j <= 500;j ++){
			if(j == 0){
				qpower[i][j] = 1;
				continue;
			}
			qpower[i][j] = (qpower[i][j-1]%E);
		}
	}
	
	ans = qpower[x][n];
	
	for(ll i = 1;i <= x; i++) dp[1][i] = 1;
	
	for(ll i =1;i <= n;i ++){
		for(ll j = 1;j <= x;j ++){
			for(ll k = i-1;k + j <= x && k + 1 <= n;k ++){
				if(k == 0) continue;
				dp[k+1][j+k]=(dp[k+1][j+k] + ((dp[i][j] * combinator[k+1][i]) % E * qpower[k][k+1-i])) % E; 
			}
		}
	}
	
	for(ll i=1;i<=x;i++)
        ans=(ans+E-dp[n][i])%E;

    printf("%lld\n",ans);

    return 0; 
}
```

## 代码2（师父的代码）

### [【算法竞赛】杨辉三角 | 杨辉三角与组合数的关系 | 杨辉三角的算法应用 | c++代码实现公式获取杨辉三角位置的值_MuShan-bit的博客-CSDN博客](https://blog.csdn.net/MuShan_bit/article/details/122833631)

```C++
#include <bits/stdc++.h>
#define ll long long   
using namespace std;
const int MOD=998244353;
ll C[505][505],dp[505][505],power[505][505]; // C表示组合数   power(i,j) 表示i的j次方
int main(){
    for(int i=0;i<=500;i++) C[i][0]=1,power[i][0]=1,dp[0][i]=1,dp[i][0]=1;
    				                        //dp[0][i] = 1 表示人数为0
    for(int i=1;i<=500;i++)
        for(int j=1;j<=i;j++){
             C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;  // 利用杨辉三角求组合数。因为下方需要遍历，所以直接将所以组合数求出并存放于数组中
    }											// 需要用到的次数很多，所以直接一次计算出并将其存储最为合理。
    for(int i=1;i<=500;i++)       
        for(int j=1;j<=500;j++) power[i][j]=(power[i][j-1]*i)%MOD;
    								          // 利用数组存放i的j-1次方。一次全部计算并存储起来之后再调用比用一次计算一次快很多！！！
    int n,x;
    scanf("%d%d",&n,&x);
    
    for(int i=2;i<=n;i++){     // 人数
        for(int j=1;j<=x;j++){ //  血量
            if(j<=i-1){   // 一轮i人参加，一轮下来每人扣i-1滴血，扣除的血量>血的上限值，那么直接全部死光
                dp[i][j]=power[j][i];  // 死亡人数仅有一种选择， 血量值的选择： 0~j，i个人， 那么就是 j的i次方
                continue;
            }
            for(int k=0;k<=i;k++){        
                dp[i][j]+=dp[i-k][j-(i-1)]*C[i][k]%MOD*power[i-1][k]%MOD; // 注意分开取余，不然很容易直接爆内存
                dp[i][j]%=MOD;  // 取余！！！ 遇到数据大的题目，一定一定要记得操作一次取一次余
            }
        }
    }
    printf("%lld",dp[n][x]);
    return 0;
}

```



## 代码3（我写的代码）

```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 510;

int dp[N][N];  // dp[i][j]  总人数为i人，最高血量值为j
int n,x;
long long INF = 998244353;
long long ans = 0;

long long Sum(int k)
{
	long long x,y;
	for(int i = n - k + 1;i <= n;i ++) {
		x = ( i * x)%INF;
	}
	for(int i = 1;i <= k; i++){
		k = (i * k)%INF;
	}
	return x/y;
}

long long power(int a,int x)
{
	long long res = 1;
	for(int i = 1; i <= x; i ++){
		res = (res * a)%INF;
	}
	
	return ans;
}

int main()
{
	cin>>n>>x;
	
	for(int i = 1;i <= n; i ++) dp[i][1] = 1;  // 血量	
	for(int i = 1;i <= x; i ++) dp[1][i] = 1;
	
	for(int i = 1;i <= n;i ++){  // i表示人数
		for(int j = 1;j <= x;j ++){ // j 代表最高血量
			for(int k = 0;k <= i;k ++ ){ // k表示死亡人数
			  ans = ans + dp[i - k][j - (i-1)] * Sum(k) * power(i-1,k);
		}
		dp[i][j] = ans%INF;
      }
	}
	
	cout<<dp[n][x]<<endl;
	
	return 0;
}
```

```C++
	#include<iostream>
	#include<cstring>
	#include<algorithm>
	#include<cstdio>
	
	using namespace std;
	
	const int N = 505;
	
	long long INF = 998244353;
	long long C[N][N],power[N][N],dp[N][N];
	int n,x;
	
	int main()
	{
		for(int i = 0;i <= 500; i ++) 
			C[i][0] = 1,power[i][0] = 1,dp[i][0] = 1,dp[0][i] = 1;
			//C[i][0] = 1,power[0][i] = 1,dp[0][i] = 1,dp[i][0] = 1;
		
		for(int i = 1;i <= 500;i ++){
			for(int j = 1;j <= i;j ++){
				//C[i][j] = C[i-1][j] + C[i-1][j-1];
				C[i][j] = (C[i-1][j] + C[i-1][j-1]) % INF;
			}
		}
	
	//	for(int i = 1; i <= N;i ++)
	//		for(int j = 1;j <= N;j ++)
	//			power[i][j] = ( power[i][j-1] * i ) % INF;
		for(int i = 1;i <= 500;i ++)
			for(int j = 1;j <= 500;j ++)
				//power[i][j] = (power[i][i-1] * i) % INF;
				power[i][j] = power[i][j-1] * i % INF;
		
		cin >> n >> x;
		
		for(int i = 2;i <= n;i ++){  // 人数一定得从第二个人开始，一个人的情况均为0（全局变量自动赋值）
			for(int j = 1;j <= x;j ++){
			if(j <= i - 1){ // 最高血量少于 i-1滴血. i人全死
				dp[i][j] = power[j][i]; // j的i次方
				continue;
			}
			for(int k = 0;k <= i; k ++){
				   dp[i][j] += dp[i-k][j - (i-1)] * C[i][k] % INF * power[i-1][k] % INF;
			       dp[i][j] %= INF;
			}
		}
	}
			cout<<dp[n][x]<<endl;		
				
		return 0;
	}

```

