# 算法与数据结构实现

> Algorithms + Data Structures = Programs --Niklaus Wirth

项目主要整理收集常用的数据结构和算法的实现，常见的面试问题的解法，还有 LeetCode、OJ 题目的（参考）解法。代码会以**可读性为首要目标**，其次简洁易懂，第三才考虑效率（当然这是理想）。

主要是 C 系算法（C、C++、Java）还有 Python 的设计与实现，基本上遵循统一的接口。由于多语言，加上并不是什么大型项目，涉及的依赖也很少，Bazel 非常适合用来作为这个多语言项目的构建工具。**不使用 Bazel 完全没问题，因为项目内容都是分散的，彼此之间没有什么联系，只是 Bazel 可以提供一个统一的使用方式。**

算法是最适合使用 TDD 进行设计和开发的。因此在 [alpha](src/alpha) 目录中提供使用单元测试的方法，可以作为参考。C++ 使用的是 [googletest](https://github.com/google/googletest) 进行单元测试；Java 当然是 JUnit5；Python 直接使用内置的标准库模块 `unittest`。

除了测试，文档也是非常有必要的。目前尝试使用 Doxygen 作为一个通用的文档生成工具（主要针对 C/C++）。

## 使用方式

### 项目结构

google 一直推崇所谓的单体哲学，因此项目也贴合这个理念，头文件、测试文件、代码文件都放到了一起。文件构建时可见性是由 `Build` 文件进行控制的。

项目使用 Bazel 构建，使用之前需要先安装 Bazel（[官方安装教程](https://docs.bazel.build/versions/3.7.0/install.html)）。

### 构建 & 运行

最常见的命令大概是下面这些：

```
# 清理项目
bazel clean
# 构建
bazel build src/alpha:MyAddTests_Cpp
# 运行
bazel run src/alpha:MyAddTests_Cpp
# 测试
bazel test src/alpha:MyAddTests_Cpp
```

## 目录

### 数据结构

- [单链表](src/list/)
- [二叉树与二叉搜索树](src/bitree)

### 算法

TODO: 各类基础算法的实现。

### 解法

TODO: 收集、整理 Online Judge、各类面试题的解决方案。