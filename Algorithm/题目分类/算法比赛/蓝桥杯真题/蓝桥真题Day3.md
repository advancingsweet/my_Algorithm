# 2023.3.22（距离蓝桥杯还有17天）

## 1.[P1555 - [蓝桥杯2021初赛\] 空间 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1555)

 ### （1.知识点

> **一个32位二进制整数 = 4B, 1KB = 1024B, 1MB = 1024KB**
>
> **所以 256MB = 256 * 1024 * 1024 / 4  个32位二进制整数** 

```C++
#include<iostream>
using namespace std;
int main()
{
	cout<<256 * 1024 * 1024 / 4 <<endl;
    return 0;
}
```

*********

## 2.[P2031 - [蓝桥杯2022初赛\] 九进制转十进制 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=2031)

### （1.知识点

> **进制数转换模板： 数n 由进制radix1 转换成 radix2**
>
> **转换思路：将radix1进制数数先转化成 10进制，然后再由十进制转换成radix2进制数。**

```C++
#include<iostream>
#include<cstring>


using namespace std;


int change(string &s,int radix1,int radix2)   //  s 由 radix1 进制转化成 radix2
{
	int ans = 0;

	for(int i = 0; i < s.size();i ++)
		{
		char t = s[i];
		if(t >= '0' && t <= '9') ans = ans * radix1 + t - '0';
		else ans = ans * radix1 + t - 'A' + 10;
	}

	int cnt = 0;
		int arr[1000];

	while(ans){
			arr[cnt++] = ans % radix2;
		ans /= radix2;
	}

	for(int i = 0;i < cnt;i ++)
			ans = ans * 10 + arr[i];

	return ans;
	}

int main()
{
	long long n;
	int radix1,radix2;

	cin>>n>>radix1>>radix2;

	string s = to_string(n);  // 将数字转化成字符串  to_string;

	int ans =  change(s,radix1,radix2);

	cout<<ans<<endl;

	return 0;
	}
```

*************

## 3.[P2041 - [蓝桥杯2022初赛\] 排列字母 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=2041)

> **解题思路：**
>
> 1. 将字符串中的字符逐一转化成 int，当做数组的坐标，此元素进行 ++ 操作即可。根据要求从前向后输出或者从后向前输出。

```C++
#include<iostream>
#include<cstring>

using namespace std;

char num[100];

int main()
{
	char ch[] = "WHERETHEREISAWILLTHEREISAWAY";
	
	for(int i = 0;i < strlen(ch);i ++)
		num[(int)ch[i]] ++;
	
	for(int i = 0;i < 100;i ++)
		if(num[i])
			while(num[i]--)
				cout<<(char)i;
	return 0;	
}
```

*****

## 4.[P1453 - [蓝桥杯2019初赛\]数列求值 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1453)

### (1.知识点(前缀和)

> **对于连乘、连加求取某一个值的后n位时，一定一定是每运算一次就 取 1eN 的模 ！！！！因为后n位的运算与n位前的数没有关系，数值准确。且不会出现爆内存的风险！！！**

**错误典例（long long 的内存都被刷爆了）：**

```C++
#include<iostream>

using namespace std;

int main(){
	
	long long ans = 0;
	
	long long a = 1,b = 1, c = 1;
	
	for(long long i = 1;i <= 20190321;i ++){   //
		
		ans = a + b + c;
		
		a = b, b = c, c = ans;
		
		if(i >= 20190300) cout<<ans<<endl;
	}
	
	string s = to_string(ans);
	
	for(int i = s.size() - 4;i < s.size();i ++)
	{
		cout<<s[i];
	}
	
	return 0;
	
}
```

```C++
//输出结果：
-744818352952221759
-2615661058505395521
3701892596100495905
341413184642878625
1427644722237979009
5470950502981353539
7240008409862211173
-4308140438628007895
8402818474215556817
-7112057628259791521
-3017379592672242599
-1726618746716477303
6590688106061040193
1846689766672320291
6710759126016883181
-3298607074959307951
5258841817729895521
8670993868787470751
-7815515462151493295
6114320224365872977
6969798631001850433
5268603393216230115
0115
```

```C++
#include<iostream>

using namespace std;

int main(){
	
	long long ans = 0;
	
	long long a = 1,b = 1, c = 1;
	
	for(long long i = 1;i <= 20190321;i ++){   //
		
		ans = (a + b + c)%10000;
		
		a = b, b = c, c = ans;
		
	}
	cout<<ans<<endl;
	
	return 0;
}
```

```C++
4659
```

***************

## 5.[P1452 - [蓝桥杯2019初赛\]平方和 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1452)

```C++
#include<iostream>

using namespace std;

bool vis[13];
long long ans;

void check(int u)
{
	int x = u;
	while(u){
		if(vis[u%10]) {
            ans += x * x;  // 注意坑点： 不能是 u * u; 只能是x * x;
            return ;
        }	
		u /= 10;	
	}
	return ;
}
int main(){
	
	vis[0] = 1;
	vis[1] = 1;
	vis[2] = 1;
	vis[9] = 1;
	
	for(int i = 1;i <= 2019;i ++)
		check(i);
	cout<<ans<<endl;
	
	return 0;
}
```

*****************

## 6.[P2032 - [蓝桥杯2022初赛\] 顺子日期 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=2032)

> 已经没法形容自己了，这题真的把自己蠢到了。

**********

## 7.[状态 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/status.php?user_id=awhiteboy)

```C++
442   // 4(四周) + 19 （20行剪19刀） + 20（20行） * 21（22列剪21刀）
    // 公式 : 4 + (m-1) + m * (n - 1) = m * n + 3;
```

******

## 8. [P2022 - [蓝桥杯2022初赛\] 灭鼠先锋 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=2022)

> 1. **代码来源：**
>
>  [2022年蓝桥杯省赛 C/C++ A组题解_蓝桥杯灭鼠先锋_傅志凌的博客-CSDN博客](https://blog.csdn.net/fzl194/article/details/124347039?ops_request_misc=%7B%22request%5Fid%22%3A%22167949693116800222835966%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=167949693116800222835966&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-2-124347039-null-null.142^v76^insert_down2,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=灭鼠先锋&spm=1018.2226.3001.4187)
>
> 2. **困惑点：**
>
>    - 如何判定必败态是小乔先下？
>    - 此题算法为：SG定理
>
>    即：对于公平类游戏，游戏选手都是在最优策略下进行游戏时，先手的开局就已经决定了此局游戏先手是胜还是负。即（游戏先手或游戏后手存在必胜策略，所以也就无需判断必败态是否是小乔下还是小蓝下）
>
>    **[SG定理证明（公平组合类游戏）](https://oi-wiki.org//math/game-theory/impartial-game/)**

```C++
#include<bits/stdc++.h>
using namespace std;
///判断是否仅存在一个空格
bool check(string s)  // 检查是否是必胜态
{
    int tot = 0;
    for(auto x : s)if(x == 'O')   
        tot++;
    return tot == 1;
}
map<string, bool>SG;  // 键值对

bool dfs(string s)  // 利用递归去模拟游戏过程
{
    // 判断是否存有s，如果有，那么直接返回键值对所对应的值，true/false;
    if(SG.count(s))  //  count() 返回指定元素出现的次数, (帮助评论区理解： 因为key值不会重复，所以只能是1 or 0)
        return SG[s];  
    
    if(check(s))   // 对于下一步落子的人来说是必败态 
        return SG[s] = false;
    
    ///模拟放1个棋子
    for(int i = 0; i < s.size(); i++)
		if(s[i] == 'O'){
	        string tmp = s;   
	        tmp[i] = 'X';    // 将 O 变为 X ： 落子
	        if(dfs(tmp) == false)  //可以到达必败态均为必胜态
	            return SG[s] = true;
	    }
    
    ///模拟放2个棋子
    for(int i = 0; i < s.size() - 1; i++)
        if(s[i] == 'O' && s[i + 1] == 'O' && i != 3){ // i != 3 防止第一行最后一个与第二行第一个两个不相邻的位置同时放入棋子
            string tmp = s;
            tmp[i] = tmp[i + 1] = 'X';
            if(dfs(tmp) == false)///可以到达必败态均为必胜态
             return SG[s] = true;
        }
    ///运行到此，说明只能转移到必胜态，此时为必败态
    return SG[s] = false;
}
int main()
{
    string s[] = {"XOOOOOOO", "XXOOOOOO", "OXOOOOOO", "OXXOOOOO"};
    for(int i = 0; i < 4; i++)
    {
        if(dfs(s[i]))cout<<"L";    //此时为必胜态，说明后手面临的局面必胜，输出L	
        else cout<<"V";
    }
    return 0;
}
```



