# [P3056 [USACO12NOV\]Clumsy Cows S](https://www.luogu.com.cn/problem/P3056)

## 第一次：AC(2 / 16)

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
	
	if(left && change) cout<<left + change<<endl;
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
//	if(left == right) ans = left + right;  // 相等
//	else   if(left && right ) {   // 不相等且均有值
//				int Min = min(left,right);
//				int Max = max(left,right);
//				ans = Min + (Max + Min)/2;
//		}
//	else ans = (left + right)/2 ;      // 既不相等 且 只有单边         // left && right == 0;
	
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

