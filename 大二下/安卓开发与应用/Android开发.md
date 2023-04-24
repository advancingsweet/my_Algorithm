# 一、代码注释

```Java
package com.example.urien.secondapp;
 
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
 
public class MainActivity extends AppCompatActivity {
 
    //1.声明控件
    private Button bt_Lesson1;
    private Button bt_lesson2;
    private Button bt_lesson3;
    private Button bt_lesson4;
 
    @Override
    protected void onCreate(Bundle savedInstanceState) {//onCreate用来创建一个activity
        super.onCreate(savedInstanceState);
        //setContentView方法是在MainActiviy中显示activity_main中所定义的内容
        setContentView(R.layout.activity_main);
 
        //2.找到控件
        bt_Lesson1 = findViewById(R.id.bt_lesson1);     // 根据Id来查找布局文件中的组件
        bt_lesson2 = findViewById(R.id.bt_lesson2);
        bt_lesson3 = findViewById(R.id.bt_lesson3);
        bt_lesson4 = findViewById(R.id.bt_lesson4);
        //4.生成监听器对象
        setListener();
    }
 
    private void setListener(){
        OnClick onclick = new OnClick();
        bt_Lesson1.setOnClickListener(onclick);
        bt_lesson2.setOnClickListener(onclick);
        bt_lesson3.setOnClickListener(onclick);
        bt_lesson4.setOnClickListener(onclick);
    }
 
    //3.定义一个类，实现监听器接口
    private class OnClick implements View.OnClickListener{
        @Override
        public void onClick(View v) {   // 创建视图 v
            Intent intent = null;
            switch(v.getId()){//跳转相应avtivity实现方法
                case R.id.bt_lesson1:
                    intent = new Intent(MainActivity.this,Lesson1_Activity.class);
                    break;
                case R.id.bt_lesson2:
                    intent = new Intent(MainActivity.this,Lesson2_Activity.class);
                    break;
                case R.id.bt_lesson3:
                    intent = new Intent(MainActivity.this,Lesson3_Activity.class);
                    break;
                case R.id.bt_lesson4:
                    intent = new Intent(MainActivity.this,Lesson4_Activity.class);
                    break;
            }
            startActivity(intent);   //
            MainActivity.this.finish();
        }
    }
}
```

# 二、文字解释

## 基本框架注释

> main_layout.xml 文件
>
> ```java
> <Button android:id = "@+id/btn1"  // ID 名： btn1 (可以理解为该组件的别名)
>     	android:layout_width = "match_parent"     //  match_parent : 内容宽度又屏幕宽度决定，自适应
>         android:loyout_height = "wrap_content"    //  wrap_content : 限定宽度的情况下，自动调整高度将内容展示出来
>         android:text = "Button1"/>
> ```
>
> MainActivity.java 文件
>
> ```java
> package com.example.MainActivity;
> 
> public class MainActivity extends AppCompatActivity{  // 
>     @Override
>     protected void onCreate(Bundle savedInstanceState){
>         super.onCreate(savedinstanceState);  // super 调用父类
>         setContentView(R.layout.main_layout); //setContentView方法是先在MainActiviy中声明可显示main_layout中所定义的内容
>         Button btn1;  // 创建 Button对象  Button btn1 = (Button)findViewBlyd(R.id.btn1);   
>         btn1 = (Button)findViewBlyd(R.id.btn1);  // 使用findViewBlyd（）方法根据ID找到视图对象（View类型）， 所以得将其进行强制转换
>         // 这样就可以使用 btn1 对象操作Button的组件了
>     }  
> } 
> ```

### 1.[为什么启动Activity都是写的super.onCreate](https://blog.csdn.net/sjpz0124/article/details/45399493?ops_request_misc=%7B%22request%5Fid%22%3A%22168216441616800215085798%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=168216441616800215085798&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-4-45399493-null-null.142^v86^insert_down1,239^v2^insert_chatgpt&utm_term= super.onCreate(savedInstanceState)%3B&spm=1018.2226.3001.4187)

> 1.如果写在你自己定义的一个OnCreate(),在这个函数里写调用OnCreate的话，必然要写super.OnCreate()，否则会递归调用，
> 其他地方写的话，super是调用父类的,this是调用你覆盖的，不过一般没有人会去手动调用这玩意吧，因此一般是调用super.OnCreate().
>
> 2.首先我们可以看到， HelloWorldActivity 是继承自 Activity 的。 Activity 是 Android 系统提 供的一个活动基类， 我们项目中所有的活动都必须要继承它才能拥有活动的特性。 然后可以 看到 HelloWorldActivity 中有两个方法， onCreateOptionsMenu()这个方法是用于创建菜单的， 我们可以先无视它， 主要看下 onCreate()方法。 onCreate()方法是一个活动被创建时必定要执 行的方法， 其中只有两行代码， 并且没有 Hello world!的字样。那么图 1.15 中显示的 Hello world! 是在哪里定义的呢？ **其实 Android程序的设计讲究逻辑和视图分离， 因此是不推荐在活动中直接编写界面的， 更加通用的一种做法是， 在布局文件中编写界面， 然后在活动中引入进来。** 你可以看到， 在 onCreate()方法的第二行调用了 setContentView()方法，就是这个方法给当前的活动引入了一 个 hello_world_layout 布局，那 Hello world!一定就是在这里定义的了！

### 2.项目包名

> Package name, Android应用使用 “反向域名 + 项目名称” 的格式

### 3.使用AVD测试

> Available Virtual Device (可用虚拟设备)

### 4.组件ID的用处

> **1.id是组件的唯一标识，通过id可以在应用中获取到该组件findViewById(R.id.xxxx);**
> 如果需要在应用中对组件进行设置，比如文字显示信息，背景颜色等代码设置，则需要设置该组件的id，以便于在应用中找到该组件。如果在应用中不对该组件进行操作，则不需要设置id，也不建议设置id信息

### 5. .xml 文件与. java 文件的作用

> **Android程序的设计讲究逻辑和视图分离， 因此是不推荐在活动中直接编写界面的， 更加通用的一种做法是， 在布局文件中编写界面， 然后在活动中引入进来**
>
> **.xml文件**
>
> **用于编写界面布局（美观）**
>
> **.java文件**
>
> **用于编写活动内容，即在界面中进行何种操作（功能实现）**

