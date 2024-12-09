## Content
- UE中的UI实现
- UMG功能简介
- 控件蓝图的制作和使用
- 作业

## UE中的UI实现
什么是UI：用户界面（User Interface）的缩写。
游戏中的UI：更注重
- 沉浸感
- 视觉冲击力
- 动态，交互
- 风格一致

### SlateUI
Slate：底层框架，高效，功能复杂，大量C++代码。【了解】
不切实际，平时不太拿来使用。
### UMG
UMG（Unreal motion Graphics）虚幻引擎可视化工具。通过可视化的蓝图系统，让开发者不需要C++代码。简单的UI编辑，
Slate对于UMG进行易用化封装。进行交互处理。

## UMG功能简介
目录：
- 画布:整个U的可视化呈现，所见即所得
- 控制板/库:可添加到UI中的组件列表
- 层级视图:用于展示当前正在编辑的UI中的组成元素和层级关系
- 细节面板:用于调整UI元素的属性(如位置信息，材质，颜色等等)
- 绑定控件:显示当前绑定到C++变量的蓝图控件或动画
- 动画轨道:用于编辑控件动画
### UMG编辑器-设计器
创建方法：内容浏览器，创建，用户界面，控件蓝图。
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207163417.png)

#### 画布
画布：整个UI的可视化呈现。
所见即所得。拖入控件即可见。【类似于Unity中的Canvas？】
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207163718.png)

#### 控制板/库【左上角】
可以看到可以用哪些元素
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207163816.png)

#### 层级视图【左下角】
显示元素之间的关系（树状关系）
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207163918.png)
#### 细节面板【右侧】
用于调整UI元素的属性（如位置信息，材质，颜色等）
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207164052.png)

#### 绑定控件
在层级面板所在位置的另一个页标签。 
显示当前绑定到C++变量给你的蓝图控件或动画
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207164403.png)

#### 动画轨道【左下角打开】
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207164255.png)
用于编辑控件动画，如渐入渐出。【类似于PR的用法，k帧】
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207164305.png)

### UMG编辑器-图表
图表：蓝图，可视化编程。
在设计器界面的右上角找到Graph按钮，点击即可切换。
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207164502.png)
切换后：
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207164601.png)
逻辑驱动UI


## 控件蓝图的制作和使用

### UMG制作要点
- 元素展现 :通过图片，文字等内容，直观的展现U需要表述的信息
图片，简单的文字等（
- 交互体验: 使用按钮，滑动条，输入框等交互元素获取玩家输入以达成交互功能
PRogressBar
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207165546.png)
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207165613.png)

- 布局调整及适配: 通过合理的布局以美化U整体效果
HorizontalBox，VerticalBox，ScrollingBox？
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207165700.png)
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207165707.png)

- 动画效果: 动画效果的实现对于可以进一步提升U的美术效果功能实现:以代码驱动Ul的整体运行
#### 控件设置为变量
需要先勾选is variable，才能在图表中编辑（如果原本没有显示的话）
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207170100.png)
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207170103.png)
之后可以拉出来，设置一些属性。
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207170218.png)

#### 如何绑定事件？
在某个UI的细节面板的右下角，可以看到哪些是可以绑定的。
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207170422.png)
点击加号后新增
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207170443.png)
#### Preconstruct
用于判断是否是设计者视图，还是运行时？
没有真正运行的时候，有些变量取不到？

一个例子：判断是否在设计者视图，如果在的话，设置为黄色。
要点：
- isDesignTime拉出Branch部件
- Branch部件的T、F使用ctrl拖动改变。
- 设置颜色的模块：SetColorandOpacity
- 设置具体颜色：Make State Color
- 需要编译之后才有区别。

![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207171829.png)

Construct相比与PreConstruct要更安全。在PreContruct后面。

更应该使用的：OnInitialize：只会触发一次。
默认没有，需要添加。
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207172055.png)
### C++操控控件
创建C++类，AllClasses-Userwidget类
点击屏幕中间上方的Class Settings按钮，然后在左下角细节面板中会有设置父 类（Parent Class）的属性，设置为刚刚创建的C++ Class。
【类设置】
![image.png](https://gitee.com/dontt/picgo-img-bed/raw/master/img/20241207173932.png)

例子：
以TextBlock_Title控件为例 在IDE中声明变量指针： 注意：由于不建议引用其他头文件，因此可以采用前置声明的方式来抑制报红。

启动Livecoding进行热编译。

#### HUD类展示UI
创建一个继承自HUD类的蓝图，使用Create Widget节点，选择 创建HUD_UI。然后通过Add to Viewport节点添加到视窗进行显示。
ZOrder：深度顺序，决定谁优先显示。

### 高级要点
#### Slot
Slot设置中，可以改变控件在父控件中的布局状态、位置、大小等内容。
Slot，Horizontal，Vertical Box

#### 刷新函数绑定
需要频繁变更的内容，可以采用binding的方式控制其变化。

## 作业
1. 实现登录界面（输入用户名密码，密码加密显示，有确认按钮，有个界面就行） 
2. 实现加载界面（要有动画表达正在加载） 
3. 实现射击游戏操作面板（要有血条，子弹数，击中玩家会发生变化的准星）