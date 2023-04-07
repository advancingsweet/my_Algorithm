# 第十三届蓝桥杯省赛C++组真题

## 1.AcWing 4402. 刷题统计   [原题链接](https://www.acwing.com/problem/content/4405/)

> 题目总结：
>
> 1. 一开始就挺无语的，又是没有看数据范围，数据庞大，居然只用：int 开
> 2. 对于100%的评测用例，数据范围都是 $10^18$,居然还想着用遍历的方式去做，计算机直接被干到爆

y总代码：

```C++
#include<iostream>
#include<cstring>

using namespace std;
long long a,b,n,ans,i;

int main()
{
	cin >> a >> b >> n;
	long long num = 5 * a + 2 * b;
	 i = n / num;
	 ans = i * 7;
	 n %= num;
	
	long long d[] = { a,a,a,a,a,b,b};
	for(i = 0;n > 0;i ++){
	    n -= d[i];
	    ans ++;
	}
	
	cout << ans << endl;
	return 0;
}
```



### 我的代码

```C++
#include<iostream>
using namespace std;

long long a,b,n,ans,s,i;

int main()
{
	cin >> a >> b >> n;
	long long num = 5 * a + 2 * b;
	 i = n / num;
	 s  = i * num;
	 ans = i * 7;
	for( i = 1;i <= 7;i ++){
		if(s >= n) break;
		if(i >= 6){
			ans ++;
			s += b;
			if(i == 7) i = 1;
		}
		else{
			s += a;
			ans ++;
		} 
	}
	cout << ans << endl;
	return 0;
}
```

*********

![image-20230329150112721](C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230329150112721.png)