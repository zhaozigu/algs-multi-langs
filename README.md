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
  - [二叉搜索树（AVL) ](src/bitree/bistree.h) | C 语言实现

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

| 题目                                                                                                                                           | 参考解法                                                                          | 备注                               |
| ---------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------- | ---------------------------------- |
| [LeetCode1 Two Sum](https://leetcode-cn.com/problems/two-sum/)                                                                                 | [C++](src/leetcode/leetcode1_two_sum.cc)                                          | Two Sum                            |
| [LeetCode7 Reverse Integer](https://leetcode-cn.com/problems/two-sum/)                                                                         | [C++](src/leetcode/leetcode7_reverse_integer.cc)                                  | 反转数字                           |
| [LeetCode9 Palindrome Number](https://leetcode-cn.com/problems/palindrome-number/)                                                             | [C++](src/leetcode/leetcode9_palindrome_number.cc)                                | 回文数                             |
| [LeetCode13 Roman to Integer](https://leetcode-cn.com/problems/roman-to-integer/)                                                              | [C++](src/leetcode/leetcode13_roman_to_integer.cc)                                | 映射关系                           |
| [LeetCode14 Longest Common Prefix](https://leetcode-cn.com/problems/longest-common-prefix/)                                                    | [C++](src/leetcode/leetcode14_longest_common_prefix.cc)                           | 最长公共前缀                       |
| [LeetCode20 Valid Parentheses](https://leetcode-cn.com/problems/valid-parentheses/)                                                            | [C++](src/leetcode/leetcode20_valid_parentheses.cc)                               | 栈的应用                           |
| [LeetCode24 Swap Nodes in Pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)                                                        | [C++](src/leetcode/leetcode24_swap_nodes_in_pairs.cc)                             | 链表结点交换                       |
| [LeetCode27 Remove Element](https://leetcode-cn.com/problems/remove-element/)                                                                  | [C++](src/leetcode/leetcode27_remove_element.cc)                                  | 简单的数组操作                     |
| [LeetCode28 Implement strStr()](https://leetcode-cn.com/problems/implement-strstr/)                                                            | [C++](src/leetcode/leetcode28_implement_strstr.cc)                                | 字符串匹配                         |
| [LeetCode35 Search Insert Position](https://leetcode-cn.com/problems/search-insert-position/)                                                  | [C++](src/leetcode/leetcode35_search_insert_position.cc)                          | 二分搜索                           |
| [LeetCode36 Valid Sudoku](https://leetcode-cn.com/problems/valid-sudoku/)                                                                      | [C++](src/leetcode/leetcode36_valid_sudoku.cc)                                    | 搜索                               |
| [LeetCode42 Power of Four](https://leetcode-cn.com/problems/power-of-four/)                                                                    | [C++](src/leetcode/leetcode42_power_of_four.cc)                                   | 简单数论                           |
| [LeetCode55 Jump Game](https://leetcode-cn.com/problems/jump-game/)                                                                            | [C++](src/leetcode/leetcode55_jump_game.cc)                                       | 贪心算法                           |
| [LeetCode58 Length of Last Word](https://leetcode-cn.com/problems/length-of-last-word/)                                                        | [C++](src/leetcode/leetcode58_length_of_last_word.cc)                             | 简单题                             |
| [LeetCode62 Unique Paths](https://leetcode-cn.com/problems/unique-paths/)                                                                      | [C++](src/leetcode/leetcode62_unique_paths.cc)                                    | 简单动态规划（斐波那契）           |
| [LeetCode66 Plue One](https://leetcode-cn.com/problems/plus-one/)                                                                              | [C++](src/leetcode/leetcode66_plus_one.cc)                                        | 数组加法                           |
| [LeetCode70 Climbing Stairs](https://leetcode-cn.com/problems/climbing-stairs/)                                                                | [C++](src/leetcode/leetcode70_climbing_stairs.cc)                                 | 斐波那契数列（最简单的 dp)         |
| [LeetCode83 Remove Duplicates from Sorted List](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)                          | [C++](src/leetcode/leetcode83_remove_duplicates_from_sorted_list.cc)              | 链表操作                           |
| [LeetCode88 Merge Sorted Array](https://leetcode-cn.com/problems/merge-sorted-array/)                                                          | [C++](src/leetcode/leetcode88_merge_sorted_array.cc)                              | 有序数组合并                       |
| [LeetCode96 Unique Binary Search Trees](https://leetcode-cn.com/problems/unique-binary-search-trees/)                                          | [C++](src/leetcode/leetcode96_unique_binary_search_trees.cc)                      | **动态规划**（卡塔兰数）           |
| [LeetCode100 Same Tree](https://leetcode-cn.com/problems/same-tree/)                                                                           | [C++](src/leetcode/leetcode100_same_tree.cc)                                      | 基本二叉树性质；递归               |
| [LeetCode104 Maximum Depth of Binary Tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)                                     | [C++](src/leetcode/leetcode104_maximum_depth_of_binary_tree.cc)                   | 基本二叉树性质；递归               |
| [LeetCode111 Minimum Depth of Binary Tree](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)                                     | [C++](src/leetcode/leetcode111_minimum_depth_of_binary_tree.cc)                   | 基本二叉树性质；递归               |
| [LeetCode112 Path Sum](https://leetcode-cn.com/problems/path-sum/)                                                                             | [C++](src/leetcode/leetcode112_path_sum.cc)                                       | 简单递归                           |
| [LeetCode119 Pascal's Triangle II](https://leetcode-cn.com/problems/pascals-triangle-ii/)                                                      | [C++](src/leetcode/leetcode119_pascal_triangle_ii.cc)                             | 杨辉三角                           |
| [LeetCode121 Best Time to Buy and Sell Stock](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock)                                | [C++](src/leetcode/leetcode121_best_time_to_buy_and_sell_stock.cc)                | 最大最小值（或者 dp、单调栈也行 ） |
| [LeetCode122 Best Time to Buy and Sell Stock II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii)                          | [C++](src/leetcode/leetcode122_best_time_to_buy_and_sell_stock_ii.cc)             | 简单的贪心算法                     |
| [LeetCode134 Gas Station](https://leetcode-cn.com/problems/gas-station/)                                                                       | [C++](src/leetcode/leetcode134_gas_station.cc)                                    | Ad Hoc 类问题                      |
| [LeetCode136 Single Number](https://leetcode-cn.com/problems/single-number/)                                                                   | [C++](src/leetcode/leetcode136_single_number.cc)                                  | 异或运算 `^` 的高级应用            |
| [LeetCode137 Single Number II](https://leetcode-cn.com/problems/single-number-ii/)                                                             | [C++](src/leetcode/leetcode137_single_number_ii.cc)                               | 异或运算 `^` 的高级应用-II         |
| [LeetCode169 Majority Element](https://leetcode-cn.com/problems/majority-element/)                                                             | [C++](src/leetcode/leetcode169_majority_element.cc)                               | 众数；摩尔投票法                   |
| [LeetCode162 Find Peak Element](https://leetcode-cn.com/problems/find-peak-element/)                                                           | [C++](src/leetcode/leetcode162_find_peak_element.cc)                              | 二分查找                           |
| [LeetCode171 Excel Sheet Column Number](https://leetcode-cn.com/problems/excel-sheet-column-number/)                                           | [C++](src/leetcode/leetcode171_excel_sheet_column_number.cc)                      | 二十六进制转十进制                 |
| [LeetCode172 Factorial Trailing Zeroes](https://leetcode-cn.com/problems/excel-sheet-column-number/)                                           | [C++](src/leetcode/leetcode172_factorial_trailing_zeroes.cc)                      | 简单数论                           |
| [LeetCode189 Rotate Array](https://leetcode-cn.com/problems/rotate-array/)                                                                     | [C++](src/leetcode/leetcode189_rotate_array.cc)                                   | 翻转数组                           |
| [LeetCode190 Reverse Bits](https://leetcode-cn.com/problems/reverse-bits/)                                                                     | [C++](src/leetcode/leetcode190_reverse_bits.cc)                                   | 位运算与二进制                     |
| [LeetCode191 Number of 1 Bits](https://leetcode-cn.com/problems/number-of-1-bits/)                                                             | [C++](src/leetcode/leetcode191_numbers_of_1_bits.cc)                              | 位运算                             |
| [LeetCode199 Binary Tree Right Side View](https://leetcode-cn.com/problems/binary-tree-right-side-view/)                                       | [C++](src/leetcode/leetcode199_binary_tree_right_side_view.cc)                    | 广度优先搜索                       |
| [LeetCode202 Happy Number](https://leetcode-cn.com/problems/happy-number/)                                                                     | [C++](src/leetcode/leetcode206_reverse_linked_list.cc)                            | 简单数论（快乐数）                 |
| [LeetCode204 Count Primes](https://leetcode-cn.com/problems/count-primes/)                                                                     | [C++](src/leetcode/leetcode204_count_primes.cc)                                   | 简单数论（素数）                   |
| [LeetCode206 Reverse Linked List](https://leetcode-cn.com/problems/reverse-linked-list/)                                                       | [C++](src/leetcode/leetcode206_reverse_linked_list.cc)                            | **反转单链表**（面试题）           |
| [LeetCode217 Contains Duplicate](https://leetcode-cn.com/problems/contains-duplicate/)                                                         | [C++](src/leetcode/leetcode217_contains_duplicate.cc)                             | 简单题，集合判定                   |
| [LeetCode219 Contains Duplicate II](https://leetcode-cn.com/problems/contains-duplicate-ii/)                                                   | [C++](src/leetcode/leetcode219_contains_duplicate_ii.cc)                          | 简单题，集合判定（滑动窗口）       |
| [LeetCode223 Rectangle Area](https://leetcode-cn.com/problems/rectangle-area/)                                                                 | [C++](src/leetcode/leetcode223_rectangle_area.cc)                                 | 简单的几何题（交集）               |
| [LeetCode225 Implement Stack using Queues](https://leetcode-cn.com/problems/implement-stack-using-queues/)                                     | [C++](src/leetcode/leetcode225_implement_stack_using_queues.cc)                   | 栈与队列                           |
| [LeetCode226 Invert Binary Tree](https://leetcode-cn.com/problems/Invert-Binary-Tree/)                                                         | [C++](src/leetcode/leetcode226_invert_binary_tree.cc)                             | 二叉树结构；递归；                 |
| [LeetCode231 Power of Two](https://leetcode-cn.com/problems/power-of-two/)                                                                     | [C++](src/leetcode/leetcode231_power_of_two.cc)                                   | 简单的指数运算                     |
| [LeetCode235 Lowest Common Ancestor of a Binary Search Tree](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) | [C++](src/leetcode/leetcode235_lowest_common_ancestor_of_a_binary_search_tree.cc) | 二叉搜索树公共结点                 |
| [LeetCode237 Delete Node in a Linked List](https://leetcode-cn.com/problems/delete-node-in-a-linked-List/)                                     | [C++](src/leetcode/leetcode237_delete_node_in_a_linked_list.cc)                   | 简单链表基础题                     |
| [LeetCode238 Product of Array Except Self](https://leetcode-cn.com/problems/product-of-array-except-self/)                                     | [C++](src/leetcode/leetcode238_product_of_array_except_self.cc)                   | 简单的分治思想                     |
| [LeetCode242 Valid Anagram](https://leetcode-cn.com/problems/valid-anagram/)                                                                   | [C++](src/leetcode/leetcode242_valid_anagram.cc)                                  | 计数比较                           |
| [LeetCode263 Ugly Number](https://leetcode-cn.com/problems/ugly-number)                                                                        | [C++](src/leetcode/leetcode263_ugly_number.cc)                                    | 简单数论（丑数）                   |
| [LeetCode268 Missing Number](https://leetcode-cn.com/problems/missing-number/)                                                                 | [C++](src/leetcode/leetcode268_missing_number.cc)                                 | 异或运算 `^` 的高级应用            |
| [LeetCode278 First Bad Version](https://leetcode-cn.com/problems/first-bad-version/)                                                           | [C++](src/leetcode/leetcode278_first_bad_version.cc)                              | 二分查找                           |
| [LeetCode279 Prefect Squares](https://leetcode-cn.com/problems/perfect-squares/)                                                               | [C++](src/leetcode/leetcode279_perfect_squares.cc)                                | 动态规划 / 四平方定理（数论）      |
| [LeetCode292 Nim Game](https://leetcode-cn.com/problems/nim-game/)                                                                             | [C++](src/leetcode/leetcode292_nim_game.cc)                                       | 简单规律题；Nim 博弈               |
| [LeetCode326 Power of Three](https://leetcode-cn.com/problems/power-of-three/)                                                                 | [C++](src/leetcode/leetcode326_power_of_three.cc)                                 | 简单的指数运算                     |
| [LeetCode338 Counting Bits](https://leetcode-cn.com/problems/counting-bits/)                                                                   | [C++](src/leetcode/leetcode338_counting_bits.cc)                                  | 类似 dp 的位运算递推思路           |
| [LeetCode343 Integer Break](https://leetcode-cn.com/problems/integer-break/)                                                                   | [C++](src/leetcode/leetcode343_integer_break.cc)                                  | 乘方比乘法大，所以拆成 3 次方      |
| [LeetCode344 Reverse String](https://leetcode-cn.com/problems/reverse-string/)                                                                 | [C++](src/leetcode/leetcode344_reverse_string.cc)                                 | 简单交换字符                       |
| [LeetCode717 1-bit and 2-bit Characters](https://leetcode-cn.com/problems/1-bit-and-2-bit-characters/)                                         | [C++](src/leetcode/leetcode717_1-bit_and_2-bit_characters)                        | 简单题                             |

#### 面试题解法

| 简述                         | 参考解法                                         | 备注         |
| ---------------------------- | ------------------------------------------------ | ------------ |
| 设计一个有 `getMin` 功能的栈 | [C++](src/others/interview/stack_get_min.cc)     | 双栈设计     |
| 判断一个数是否是回文数       | [C++](src/others/interview/palindrome_number.cc) | 首尾取位比较 |

#### Online Judge

Online Judge 的代码为了便于测试，会使用类 `Solve` 统一包装解法，并用一个头文件独立出来。这样 I/O 代码，解法，测试均可以单独作为目标。当然，牺牲少量的效率和内存是无法避免的。

> 如果需要在对应 OJ 平台运行，把对应 `.hpp` 的文件内容拷贝到对应的执行文件中（`binary` 目标）。

| 题目                                                                                                                                                   | 参考解法                               | 备注                             |
| ------------------------------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------- | -------------------------------- |
| [POJ1003 Hangover](http://poj.org/problem?id=1003)                                                                                                     | [POJ1003](src/onlinejudge/poj1003.hpp) | 二分查找；递推                   |
| [POJ1004 Financial Management](http://poj.org/problem?id=1004) 或 [ZOJ1048](https://zoj.pintia.cn/problem-sets/91827364500/problems/91827364547)       | [POJ1004](src/onlinejudge/poj1004.hpp) | 简单题，求平均数                 |
| [POJ1005 I Think I Need a Houseboat](http://poj.org/problem?id=1005) 或 [ZOJ1049](https://zoj.pintia.cn/problem-sets/91827364500/problems/91827364548) | [POJ1005](src/onlinejudge/poj1005.hpp) | 简单题，简单计算                 |
| [POJ1007 DNA Sorting](http://poj.org/problem?id=1007)                                                                                                  | [POJ1007](src/onlinejudge/poj1007.hpp) | 简单题，逆序数（TODO: 多种解法） |
| [POJ1012 Joseph](http://poj.org/problem?id=1012)                                                                                                       | [POJ1012](src/onlinejudge/poj1012.hpp) | 简单题，约瑟夫环                 |
| [POJ1207 The 3n+1 problem](http://poj.org/problem?id=1207)                                                                                             | [POJ1207](src/onlinejudge/poj1207.hpp) | 简单题，循环                     |
| [POJ1258 Agri-Net](http://poj.org/problem?id=1258)                                                                                                     | [POJ1258](src/onlinejudge/poj1258.hpp) | 图论，Prim                       |
| [POJ1338 Ugly Numbers](http://poj.org/problem?id=1338)                                                                                                 | [POJ1338](src/onlinejudge/poj1338.hpp) | 枚举；队列                       |
| [POJ1363 Rails](http://poj.org/problem?id=1363)                                                                                                        | [POJ1363](src/onlinejudge/poj1363.hpp) | 栈                               |
