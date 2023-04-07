# [P3056 [USACO12NOV\]Clumsy Cows S](https://www.luogu.com.cn/problem/P3056)

> **1.思路：**
>
> **对于字符串，从左向右遍历，如果遇到左括弧，left ++ 。当遇到右括弧时，分两种情况判断：**
>
> - **情况一：在此之前有左括弧，那么可以与之匹配， left --。**
> - **情况二：在此之前没有左括弧，那么将其改成左括弧， left ++，change ++；**
>
> **最后：**
>
> ```C++
> int ans = change + (left)/2;    // left 一定为偶数，所以不需要可以讲所以样例一同考虑，而不需要单独考虑样例四。
> ```
>
> 
>
> **2.样例分析：**
>
> <img src="C:\Users\Hongwei Tang\AppData\Roaming\Typora\typora-user-images\image-20230325173148642.png" alt="image-20230325173148642" style="zoom: 50%;" />
>
> **3.题目总结：**
>
> **此题耗时很久，并且写代码时都没有彻底理解题意。同时，也对样例的可能没有想透彻。**

## AC(16 / 16)

```C++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 1000000;
char s[N];

int main()
{
	cin >> s;
	
	int left = 0,ans = 0,change = 0;
	
	for(int i = 0;i < strlen(s);i ++){	
			if(s[i] == '('){
				left ++;  // 待匹配得左括号
			}
			if(s[i] == ')'){
				if(left) left --;  // 与前面已有的左括号相匹配
				else  change ++,left ++;   //  左边多的无法匹配的 右括号
			}
	}
	ans = change + left/2;
	
	cout << ans <<endl;
	
	return 0;
	
}
```



## 第一次：AC(2 / 16)

> **没有理解题意（英文没有看懂），理解成了添加多少个括号可将其全部匹对**

```c++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 1000000;
char s[N];

int main()
{
	cin >> s;
	int left = 0,right = 0;
	int change = 0;
	char l = '(',r = ')';
	for(int i = 0;i < strlen(s);i ++){	
			if(s[i] == l){
				left ++;
			}
			if(s[i] == r){
				if(left) left --;
				else  change ++;
			}
	}
	cout<< (left + change) <<endl;    
	return 0;
	
}
```



##  第二次：AC（12 / 16)

> 还是没理解题意！

```C++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 1000000;
char s[N];

int main()
{
	cin >> s;
	
	int left = 0,right = 0;
	int change = 0;
	char l = '(',r = ')';
	for(int i = 0;i < strlen(s);i ++){	
			if(s[i] == l){
				left ++;
			}
			if(s[i] == r){
				if(left) left --;
				else  change ++;
			}
	}
	
	if(left && change) cout<<left + change<<endl;   // 此种情况仅仅是
	else cout<< (left + change)/2 <<endl;
	
	return 0;
}
```

## 第三次：AC(13 / 16)

```c++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 1000000;
char s[N];

int main()
{
	cin >> s;
	
	int left = 0,right = 0,ans = 0;
	char l = '(',r = ')';
	for(int i = 0;i < strlen(s);i ++){	
			if(s[i] == l){
				left ++;
			}
			if(s[i] == r){
				if(left) left --;
				else  right ++;
			}
	}
	
	if(left && right ) {
        if(left != right){
            int x = min(left,right);
            int y = max(left,right);
            ans = x + (y-x)/2;
        }
        else ans = left + right;
   }
	else ans = (left + right)/2 ;            // left && right == 0;
	cout << ans <<endl;
	return 0;
}
```

## 第四次：AC(14 / 16)

```C++
#include<iostream>
#include<cstring>

using namespace std;

const int N = 1000000;
char s[N];

int main()
{
	cin >> s;
	
	int left = 0,right = 0,ans = 0;
	int change = 0;
	char l = '(',r = ')';
	for(int i = 0;i < strlen(s);i ++){	
			if(s[i] == l){
				left ++;  // 待匹配得左括号
			}
			if(s[i] == r){
				if(left) left --;  // 与前面已有的左括号相匹配
				else  right ++;   //  左边多的无法匹配的 右括号
			}
	}
	if(right % 2){
		int Min = min(right,left);
		ans = Min/2 + 2 + right/2;
	}
	else ans = (right + left)/2;
	cout << ans <<endl;
	
	return 0;
}
```

答案：

```C++
#include<cstdio>
#include<cstring>//便于使用strlen();
using namespace std;
const int maxn=100010;
char str[maxn];
int ans,ls,num;//ans即answer,ls即str字符串的长度,num就是个假栈顶,说明现在已经有num个括号未匹配成功
int main(){
	scanf("%s",&str);
	ls=strlen(str);//记录str的长度，不要问我为什么不用STL
	for(int i=0;i<ls;i++){
		if(str[i]=='(')  num++;//等待匹配右括号
		else if(str[i]==')'&&num==0){//num==0即为现在str[i]之前所有括号都能匹配，凭空出现个右括号,ans自加,并将该括号转为左括号等待匹配
			ans++;num++;
		}else num--;//匹配成功后要减少一个待匹配的数量
	}
	ans+=num/2;//还有num个左括号没有匹配,便将其中的一半转为右括号
    
	if(num%2!=0)  ans++;//如果num是单数,则有一个括号必须进行一次删除修改
    //值得一提的是，楼上的dalao用的ans+=(num+1)/2;和此思路一致，也更加巧妙，我太弱所以没想到
	printf("%d",ans);
	return 0;
}
```

