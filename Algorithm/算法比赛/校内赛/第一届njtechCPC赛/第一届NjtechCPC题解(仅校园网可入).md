# 第一届NjtechCPC题解(仅校园网可入)

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

## 1.赛后代码

```

```

## 2.提交的代码

```C++
/*
	比赛过程中仅仅想：过滤掉重复认识的同伴： 类似 2-3 与 3-2 组合。每一组仅计算一次。
	实际思想：相互认识的一个群体
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