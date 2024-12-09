## Content
- 通用代码规范
- UE5的C++代码规范
- UE5中的标识符
## 通用代码规范
什么是代码规范？
- 一系列编写的指导方针
- 覆盖缩进、注释、命名、空格使用、换行等等方面
- 由团队/组织/公司制定
举例：谷歌的代码规范文档 Google C++ Style Guide

### UE代码规范
[Epic的虚幻引擎 C++ 代码规范 | 虚幻引擎 5.5 文档 | Epic Developer Community | Epic Developer Community](https://dev.epicgames.com/documentation/zh-cn/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine)
考虑：
- 80%的时间需要维护
- 不一定是你自己在进行维护（同事、新加入的同事）
- 开源
- 交叉编译兼容
为什么需要代码规范？
- 维护
- 降低阅读成本
- 降低复杂度
- 减少内耗
例子：
- 宏
命名
- 避免过度缩写
- 大驼峰
- bool需要加一个b
#### UE的命名规范（Uobject）
- 模板类的前缀是`T`。
- `UObject`类的派生类前缀是`U`。
- `AActor`类的派生类前缀是`A`。
- `SWidget`类的派生类前缀是`S`。
- 抽象接口类前缀是`I`。
- 枚举类型前缀是`E`。
- 布尔类型变量的变量名必须加上前缀`b`（例如：`bPendingDestruction`或者`bHasFadedIn`）。
- 绝大多数其它的类，类型名前会有前缀`F`，一些子系统可能会使用其它字母。
- 类型别名(`typedef`)也应当使用恰当的前缀：如果是一个结构体`struct`)则应使用前缀`F`。如果是一个`UObject`的派生类则应使用前缀`U`，以此类推。
#### 数据类型
内存优化的时候，可以使得size更小一点。
比如int就有多种类型。int8比int32这些更小
特殊写法：
```
uint8 xx:1;
```
虽然使用的int，但是只用一个bit。只能再类成员的时候使用。

#### 尽可能使用UE自带的数据类型
- 基础类：uint64/int16等
- 字符串类：使用UE定义的FString/FText/FName/TCHAR等
- 容器类：应避免使用stl，使用UE定义的TArray/TMap等
例子-FString：不要觉得编译可以通过就用一些C++自带的数据类型。

#### If-else对齐
注意if-else的大括号。不然有可能不会按照预期不会执行。【递进错误】

#### 命名空间
- UnrealHeaderTool仅支持全局命名空间的类型
- 不要在全局命名空间使用using 声明
- 一些宏在命名空间内可能会失效，可以尝试UE 前缀的版本

#### C++11
- 不要使用NULL宏，使用nullptr来表示空指针
- Lambda函数须明确指出返回类型
- 不要使用auto，除了:Lambda函数、迭代器声明，模板中类型推导

## UE5中的标识符
[[UFSH2024]UE5(标识符, meta=(详解, 史上最全)) | 大钊 Epic Games 虚幻社区经理_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1152LYrECW/?spm_id_from=333.337.search-card.all.click&vd_source=1d56ec2e56c55a5e2ca5345d267e169c)
[UnrealSpecifiers/Doc/zh/Main.md at main · fjz13/UnrealSpecifiers](https://github.com/fjz13/UnrealSpecifiers/blob/main/Doc/zh/Main.md)
格式：
>标头（标识符，meta=（key, key="value"))
【大钊的b站分享】

流程：
先写c++，generator会生成，Uproperty如果写了一些不正确的会编译报错。
### UPROPERTY
可以加一点定义，可以在蓝图上显示？

可以设定属性，还有下滑框。meta用法。隐藏（针对编辑器用法）

一级，二级（使用或`|`）建立多级列表

其他显示相关：
- 【DisPlay Name】
- 【DisPlay Priority】显示优先级，人为定义
- 【Advanced Display】隐藏低频修改的属性
- 【Clamp Min/Max】限制数值范围

蓝图，调整可读性
- 【BlueprintReadWrite】
- 【BlueprintReadOnly】
传播：
- 【BlueprintCallable】
### UFUNCTION
Meta函数默认值

### UCLASS
注意事项：
- 注意generated.h 否则会报错。
- 还有GENERATED_BODY
- 模板类的概念。所以初始化里面不需要写很多东西。
- 只在运行时用的东西不要在构造函数初始化。

跨模块访问，加模块名字？
- 全大写+API
### USTRUCT
用于结构体的宏。
### UENUM
用于枚举类的宏。
都建议使用enum class。
也可以用原生enum class，但是容易出现问题（例如，命名重复）