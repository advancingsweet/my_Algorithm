# 2023.3.22（距离蓝桥杯还有11天）

## 1.[P1555 - [蓝桥杯2021初赛\] 空间 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=1555)

 ### （1.知识点

> 一个32位二进制整数 = 4B, 1KB = 1024B, 1MB = 1024KB
>
> 所以 256MB = 256 * 1024 * 1024 / 4  个32位二进制整数 

```C++
#include<iostream>
using namespace std;
int main()
{
	cout<<256 * 1024 * 1024 / 4 <<endl;
    return 0;
}
```





## 2.[P2031 - [蓝桥杯2022初赛\] 九进制转十进制 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=2031)

### (1.知识点

> 1.[进制转换(C++)_c++进制转换_Luqwera的博客-CSDN博客](https://blog.csdn.net/qq_39876147/article/details/113834134?ops_request_misc=%7B%22request%5Fid%22%3A%22167942098516800192285316%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=167942098516800192285316&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-113834134-null-null.142^v75^insert_down2,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=进制转换c%2B%2B&spm=1018.2226.3001.4187)  (任意转换)

```C++
// 仅适用于 2 ~ 10 进制转换
#include<iostream>
#include<stack>

using namespace std;

int chang(int n,int a)  // n 为原数值，a为原本进制数。   
{
	stack<int>k;
	int ans = 0;
	while(n){
		k.push(n%10);
		n /= 10;
	}
	
	while(k.size() >= 1){
		ans = ans*a + k.top();
		k.pop();
	}
	return ans;
}

int main()
{
	int n,m,ans;
	
	cin >> n >> m;
	
	ans = chang(n,m);
	
	cout<<ans<<endl;
}
```



## 3.[P2041 - [蓝桥杯2022初赛\] 排列字母 - New Online Judge (ecustacm.cn)](http://oj.ecustacm.cn/problem.php?id=2041)

> 思路：
>
> 1.将字母强制转换成数字存储到数组中，然后遍历一次数组再按顺序输出即可。
>
> 进制数转换模板： 数n 由进制radix1 转换成 radix2
>
> ```C++
> #include<iostream>
> #include<cstring>
> 
> 
> using namespace std;
> 
> 
> int change(string &s,int radix1,int radix2)   //  s 由 radix1 进制转化成 radix2
> {
> 	int ans = 0;
> 	
> 	for(int i = 0; i < s.size();i ++)
> 	{
> 		char t = s[i];
> 		if(t >= '0' && t <= '9') ans = ans * radix1 + t - '0';
> 		else ans = ans * radix1 + t - 'A' + 10;
> 	}
> 	
> 	int cnt = 0;
> 	int arr[1000];
> 	
> 	while(ans){
> 		arr[cnt++] = ans % radix2;
> 		ans /= radix2;
> 	}
> 	
> 	for(int i = 0;i < cnt;i ++)
> 		ans = ans * 10 + arr[i];
> 	
> 	return ans;
> }
> 
> int main()
> {
> 	long long n;
> 	int radix1,radix2;
> 	
> 	cin>>n>>radix1>>radix2;
> 	
> 	string s = to_string(n);  // 将数字转化成字符串  to_string;
> 	
> 	int ans =  change(s,radix1,radix2);
> 	
> 	cout<<ans<<endl;
> 	
> 	return 0;
> }
> ```
>
> 

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

