# 算法与数据结构实现

> Algorithms + Data Structures = Programs --Niklaus Wirth

项目主要整理收集常用的数据结构和算法的实现，常见的面试问题的解法，还有 LeetCode、OJ 题目的（参考）解法。代码会以**可读性为首要目标**，其次简洁易懂，第三才考虑效率（当然这是理想）。

主要是 C 系算法（C、C++、Java）还有 Python 的设计与实现，基本上遵循统一的接口。由于多语言，加上并不是什么大型项目，涉及的依赖也很少，Bazel 非常适合用来作为这个多语言项目的构建工具。**不使用 Bazel 完全没问题，因为项目内容都是分散的，彼此之间没有什么联系，只是 Bazel 可以提供一个统一的使用方式。**

算法是最适合使用 TDD 进行设计和开发的。因此在 [alpha](src/alpha) 目录中提供使用单元测试的方法，可以作为参考。C++ 使用的是 [googletest](https://github.com/google/googletest) 进行单元测试；Java 当然是 JUnit5；Python 直接使用内置的标准库模块 `unittest`。

除了测试，文档也是非常有必要的。目前尝试使用 Doxygen 作为一个通用的文档生成工具（主要针对 C/C++）。例如，在 [二叉树](src/bitree) 中有 Doxyfile 文件[TreeDoxyfile](src/bitree/TreeDoxyfile)。可以使用 `Doxygen TreeDoxyfile` 生成文档。

## 使用方式

### 项目结构

google 一直推崇所谓的单体哲学，因此项目也贴合这个理念，头文件、测试文件、代码文件都放到了一起。文件构建时可见性是由 `Build` 文件进行控制的。

项目使用 Bazel 构建，使用之前需要先安装 Bazel（[官方安装教程](https://docs.bazel.build/versions/3.7.0/install.html)）。

```
.
├── algs4_data       ## 《算法》测试数据
├── src
│   ├── alpha        ## 模板与基本测试
│   ├── bitree       ## 二叉树
│   ├── leetcode     ## Leetcode 题解
│   ├── list         ## 链表
│   ├── onlinejudge  ## 各平台 OJ 题解
│   ├── others       ## 其它，e.g. 面试题
│   └── sort         ## 排序
└── third_party
```

#### 《算法》环境

《算法》一书封装了一个 Java 库，并且提供测试数据，配套非常完善。现在使用 Bazel 可以更便捷的运行和修改书中的示例。

使用书中的 Java 库进行开发的示例见：[AlgsDrawExample](src/alpha/AlgsDrawExample.java)，源自于书中表 1.1.20 的示例。

[algs4_data](algs4_data/) 文件夹包含了书中提供的测试数据，使用 Bazel 运行程序时，有严格的可见性限制。书中 _1.1.10 二分查找_ 一节中示例如下：

```
java_binary(
  name = "BinarySearch",
  srcs = [
    "BinarySearch.java"
  ],
  deps = [
    "//third_party:algs4"
  ],
  data = [
    "//algs4_data:tinyW.txt",
    "//algs4_data:tinyT.txt",
  ]
)
```

在项目顶层使用 Bazel 运行该程序：

```
bazel run src/alpha:BinarySearch ./algs4_data/tinyW.txt < ./algs4_data/tinyT.txt
```

### 构建 & 运行

（示例）最常见的命令大概是下面这些：

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
  - [二叉树结构](src/bitree/bitree.h)
  - [二叉树遍历](src/bitree/traverse.h)

### 算法

各类基础算法的实现。

- 快速排序
  - [快速排序(C)](src/sort/qksort.c)
  - [函数式写法(Python)](src/sort/qsort_functional.py) | 三行极简
- 最大公约数
  - [欧几里得算法](src/math/gcd.cc) | 一行代码

### 解法

收集、整理 Online Judge、各类面试题的解决方案。

#### Leetcode

LeetCode 上的题目都是测试友好型的，提供的代码框架已经分离了 IO。因此解法和测试用例可以放到一起。

| 题目                                                                                                       | 参考解法                                                        | 备注                 |
| ---------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------- | -------------------- |
| [LeetCode100 Same Tree](https://leetcode-cn.com/problems/same-tree/)                                       | [C++](src/leetcode/leetcode100_same_tree.cc)                    | 基本二叉树性质；递归 |
| [LeetCode104 Maximum Depth of Binary Tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) | [C++](src/leetcode/leetcode104_maximum_depth_of_binary_tree.cc) | 基本二叉树性质；递归 |
| [LeetCode111 Minimum Depth of Binary Tree](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/) | [C++](src/leetcode/leetcode111_minimum_depth_of_binary_tree.cc) | 基本二叉树性质；递归 |
| [LeetCode169 Majority Element](https://leetcode-cn.com/problems/majority-element/)                         | [C++](src/leetcode/leetcode169_majority_element.cc)             | 众数；摩尔投票法；   |
| [LeetCode226 Invert Binary Tree](https://leetcode-cn.com/problems/Invert-Binary-Tree/)                     | [C++](src/leetcode/leetcode226_invert_binary_tree.cc)           | 二叉树结构；递归；   |
| [LeetCode237 Delete Node in a Linked List](https://leetcode-cn.com/problems/delete-node-in-a-linked-List/) | [C++](src/leetcode/leetcode237_delete_node_in_a_linked_list.cc) | 简单链表基础题       |
| [LeetCode292 Nim Game](https://leetcode-cn.com/problems/nim-game/)                                         | [C++](src/leetcode/leetcode292_nim_game.cc)                     | 简单规律题；Nim 博弈 |

#### 面试题解法

| 简述                         | 参考解法                                         | 备注         |
| ---------------------------- | ------------------------------------------------ | ------------ |
| 设计一个有 `getMin` 功能的栈 | [C++](src/others/interview/stack_get_min.cc)     | 双栈设计     |
| 判断一个数是否是回文数       | [C++](src/others/interview/palindrome_number.cc) | 首尾取位比较 |

#### Online Judge

Online Judge 的代码为了便于测试，会使用类 `Solve` 统一包装解法，并用一个头文件独立出来。这样 I/O 代码，解法，测试均可以单独作为目标。当然，牺牲少量的效率和内存是无法避免的。

> 如果需要在对应 OJ 平台运行，把对应 `.hpp` 的文件内容拷贝到对应的执行文件中（`binary` 目标）。

| 题目                                                           | 参考解法                               | 备注                             |
| -------------------------------------------------------------- | -------------------------------------- | -------------------------------- |
| [POJ1004 Financial Management](http://poj.org/problem?id=1004) | [POJ1004](src/onlinejudge/poj1004.hpp) | 简单题，求平均数                 |
| [POJ1007 DNA Sorting](http://poj.org/problem?id=1007)          | [POJ1007](src/onlinejudge/poj1007.hpp) | 简单题，逆序数（TODO: 多种解法） |
| [POJ1012 Joseph](http://poj.org/problem?id=1012)               | [POJ1012](src/onlinejudge/poj1012.hpp) | 简单题，约瑟夫环                 |
| [POJ1207 The 3n+1 problem](http://poj.org/problem?id=1207)     | [POJ1207](src/onlinejudge/poj1207.hpp) | 简单题，循环                     |
| [POJ1258 Agri-Net](http://poj.org/problem?id=1258)             | [POJ1258](src/onlinejudge/poj1258.hpp) | 图论，Prim                       |
| [POJ1338 Ugly Numbers](http://poj.org/problem?id=1338)         | [POJ1338](src/onlinejudge/poj1338.hpp) | 枚举；队列；                     |
| [POJ1363 Rails](http://poj.org/problem?id=1363)                | [POJ1363](src/onlinejudge/poj1363.hpp) | 栈                               |
