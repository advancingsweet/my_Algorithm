# 2023.3.21（距离蓝桥杯还有18天）

## 1.[P1550 - [蓝桥杯2021初赛\] 卡片 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1550)

## 2.思路（总耗时：50min)

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

