
## 游戏引擎
### 常见的游戏引擎有哪些？

UE
- PBR渲染
- 蓝图+C++
- gameplay框架
- 开源

unity
- 不开源

CryEngine

### 什么是游戏引擎

#### 游戏引擎框架
游戏行为全部或部分由美术或者策划提供的数据控制。
- 通用性和偏向性
- 可扩展性
- 完善工具链
无论是什么开发都需要了解游戏引擎框架
推荐：《game engine architecture》
#### 游戏引擎渲染
- deferred renderer
- forward renderer
- mobile renderer
国内mobile较好：
- 芯片、带宽更差，所以需要分片渲染（tile）
- tile-based rendering
- tile based deferred rendering
需要注意的是，GPU内存的问题（手机上）片上内存（on-chip）
手机端GPU和CPU共享主内存。片上内存处理速度更快。主内存更慢
### 游戏引擎物理
Phyix
Haok
UE-Chaos等

## UE引擎
### ue引擎是什么样的
UE官方随着引擎发展也会发布游戏
对于FPS-TPS等类型的游戏支持较好

#### 如何学习UE
学习资料
- Unreal engine Youtube官方
- Unreal Engine bilibili官方
- zhihu官方
#### Launcher
源码版本和launcher版本不一样
对于硬件要求较高

#### UE 编辑器使用
Play in Editor：所见即所得。
建游戏：
- 蓝图
- C++
路径不要有中文，也不要test（关键字）会可能打不开
- uproject：项目
- target.cs：
- Build：会有dll相关设置
#### 编辑器布局
- 下面：
- 左边：
- 右边：

#### 编辑器使用
地图：new level（File里）
切换关卡等
更改地图加载方式：
- 流失加载
- 全部加载

可视化游戏世界
Viewpoint（更改编辑器视角）
- 有光照
- 无光照
- 等

导航
- QE+鼠标右键，调整相机视角
- F：focus
- 还可以更改相机速度

下拉：【小三角】
- Ctrl+数字，添加相机朝向（Bookmark）
- G：game view：隐藏线框

选取
- hierarchy的树可以方便选取
- 可以在show里面选取
- World outline里面也可以选取，使用+-号进行排除【类似于正则？】
- 片选（不同的视图，顶视图，透视图）

安放与对齐
- 移动选择（类似于unity）
- Grid control更改最小移动的角度等等
坐标系转换：
- 世界坐标系和局部坐标系
- 还有贴地
	- End
	- alt-end
	- shift-end

快速迭代
- 三个点下拉可以改变play的模式
- 模拟角色数量

Volumn和光源
- 空气墙
- 触发器（Trigger）
- 光源，点，面，天光等等

资产管理
- 路径
- filter等
- view option：浏览方式
Content browser
- 路径和windows的磁盘路径一一对应
- uasset文件
- 非UE资源不要放在这个路径
资源迁移
- Asset migrate
- 会迁移相互的引用关系
DDC：格式转化
资产命名规范：
#### Project项目结构
Config
Content
Source
.sln
.uproject

World: 包含关卡列表
Level：关卡
sub-level：类似于PUBG中的子区域（处理地图）
Actor：放入关卡的对象都是Actor，可以使用进程代码来创建及销毁

资产使用流程

工程设置
Map & Modes
Packaging
Platform
- 使用Android Studio来安装SDK和NDK

## Source Code
需要：
- github账号
- unreal账号
- 找到5.4版本

我们用源码的目的
- 了解启动部分的源码
- 感兴趣的模块

编译源码：
- 运行Setup.bat下载依赖文件
- 运行GenerateProjectFiles.bat生成工程文件（sln）
- 生成项目文件（右键uproject生成）
- 编译是通过UBT进行的：
	- 预处理头文件，语法，宏等，再转化为胶水代码
	- 调用普通的编译器

编译规则：
- 目标文件
	- build.cs定义的一些链接相关的
- 模块
	- Engine：gameplay相关的类
	- Core：
	- Runtime modules：有一些命名规则。基本功能，Core，Engine。渲染
	- Editor Modules
### 游戏框架
游戏状态（GameState）：全局的状态
兵卒（Pawn）：角色，生命体，
角色（Character）：子类，用作玩家角色
玩家控制器（PlayerController）：接受输入，控制。

#### BluePrint：脚本
可视化编程，引擎运行时会读取字节码，交由虚拟机解释后执行
BluePrint分类
蓝图和C++的通信
- 反射信息（Uproperty）
- EditCondition
相互调用
- C++调用蓝图
- 蓝图调用C++。加入不同的反射信息
记得加入控制帧的判断。

使用原则：
- 用于数值配置
- 用于简单的效果展示
- 用于简单逻辑：代码不超过屏幕

### LUA
slua，Unlua进行开发（脚本语言）

### C++添加向导
UE里面有自己的创建向导（有自己的反射信息和预制的templater）
#### 编码规范
- T
- A
- U
- F
- I
- E
- b
基本类型不建议使用原生C++的，用UE提供的（做了跨平台的处理）

UObject，UClass，用配置驱动引擎。

#### 调试 
很多调试的模式
- Debug
- debugGame：调试模块
- Development：启用配置所有功能
- Shipping：交付游戏
真机调试

## 引擎工具
UE-log可以看日志
- channel
- verbosity level
可视化日志
内置控制台
- 可以看性能
调试游戏相机
加参数（-game等）
- RenderDoc是单帧捕获和详细分析
Unreal insight：性能分析

## 作业
1.源码编译UE5,新建一个C++工程，进行简单场景编辑和工程设置
2.编译并构建安装包，确保能够用来将游戏工程安装到手机正常运行


