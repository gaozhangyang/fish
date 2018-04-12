# fish
a zixing ai project.
不用下载直接看代码。

## 代码说明
1. `FishHead.h`
约定的定义、结构
2. `PublicCode.cpp`
程序主体，详细的处理流程自己留着

## 错误列表
| **错误代码** | **定义名称** | **错误含义** |
|-------------|--------------|-------------|
|-1|`ERROR`|预留|
|-10|`FISH_READ_ERROR`|图像读取异常|
|-12|`FISH_ENHANCE_PARA_ERROR`|增强参数不存在|

## 更新记录

### 时间：20180411
增加`Structs.h`，`PublicCode.cpp`文件，初始化readme。
***
### 时间：20180412
 增加`stdafx.h`，修改`Structs.h`为`FishHead.h`，增加一些宏定义和函数，修改`PublicCode.cpp`中一点结构，`README.md`增加错误列表。