# [P1791 - [NewOJ Week 1\] 前缀和的因子数 ](http://oj.ecustacm.cn/problem.php?id=1791)

> **总结：**
>
> **第一份代码仅能AC 90%，while嵌套循环函数超时。第二份代码AC，确定因子的for循环并未放入函数中。所以在不能明确循环次数的情况下，最后不要将内嵌套循环放入函数，因为调用函数也会需要时间！！！会增加TLE错误的出现概率**

## 第一份代码

```C++
#include<iostream>

using namespace std;

const int N = 5100000;

int n;
long long s[N];

long long judge(long long x)
{
	int cnt = 0;
	for(long long i = 1;i <= x / i;i ++)
		if(x % i == 0){
			cnt ++;
			if(i * i != x) cnt ++;	
			}
	return cnt;
}

int main()
{
	cin >> n;
	
	int i = 1,cnt = 1;
	
	while(1)
	{
		s[cnt] = s[cnt - 1] + i;
		if(judge(s[cnt]) > n){
			cout << s[cnt] <<endl;
			return 0;
		}
		i ++,cnt ++;
	}
	return 0;
}
```

## 第二份代码（优化）

```C++
#include<iostream>

using namespace std;

const int N = 5100000;

int n;
long long s[N],x;

int main()
{
	cin >> n;
	
	int i = 1,cnt = 1;
	
	while(1)
	{
		int ans = 0;
		
		 x = s[cnt] = s[cnt - 1] + i;
		
		for(long long i = 1;i <= x / i;i ++)
			if(x % i == 0){
				ans ++;
				if(i * i != x) ans ++;	
			}
		
		if(ans > n){
			cout << s[cnt] <<endl;
			return 0;
		}
		i ++,cnt ++;
	}
	return 0;
}
```

