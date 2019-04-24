# TraningOfPAT
对练习后的PAT代码存储地方

[(^-^)PAT 真题网站传送门](https://www.patest.cn/practice)

## Content

### Basic Level(乙级)

- NULL

### Advanced Level(甲级)

- [1001 A+B Format](./code/1001.md) - Skr-Long
- [1002 A+B for Polynomials](./code/1002.md) - Skr-Long
- [1003 Emergency](./code/1003.md) - Skr-Long
- [1004 Counting Leaves](./code/1004.md) - Skr-Long
- [1005 Spell It Right](./code/1005.md) - Skr-Long
- [1006 Sign in and Sign out](./code/1006.md) -Skr-Long
- [1007 Maximum Subsequence Sum](./code/1007.md) -Skr-Long
- [1008 Elevator](./code/1008.md) - Skr-Long
- [1009 Product of Polynomials](./code/1009.md) - Skr-Long
- [1010 Radix](./code/1010.md) - Skr-Long
- [1011 Word Cup Betting](./code/1010.md) - Skr-Long
- [1012 The Best Rank](./code/1012.md) - Skr-Long
- [1013 Battle Over Cities](./code/1013.md) - Skr-Long
- [1014 Waiting in Line](./code/1014.md) - Skr-Long
- [1015 Reversible Primes](./code/1015.md) - Skr-Long
- [1016 Phone Bills](./code/1016.md) - Skr-Long
- [1017 Queuing at Bank](./code/1017.md) - Skr-Long
- [1018 Public Bike Management](./code/1018.md) - Skr-Long
- [1019 General Palindromic Number](./code/1019.md) - Skr-Long
- [1020 Tree Traversals](./code/1020.md) - Skr-Long
- [1020 Tree Traversals](./code2/PAT_A1020.md) -Mark
- [1021 Deepest Root](./code/1021.md) - Skr-Long
- [1022 Digital Library](./code/1022.md) - Skr-Long
- [1023 Have Fun with Numbers](./code/1023.md) - Skr-Long
- [1024 Palindromic Number](./code/1024.md) - Skr-Long
- [1025 PAT Ranking](./code/1025.md) - Skr-Long
- [1032 Sharing](./code2/PAT_A1032.md) -Mark
- [1034 Head of a Gang](./code2/PAT_A1034.md) -Mark
- [1043 Is it a Binary Search Tree](./code2/PAT_A1043.md) -Mark
- [1052 Linked List Sorting](./code2/PAT_A1052.md) -Mark
- [1053 Path of Equal Weight](./code2/PAT_A1053.md) -Mark

### Top Level(顶级)

- NULL

## Algorithm

### 图

- [1003 Emergency](./code/1003.md) - 最短路径生成 Dijkstra
- [1013 Battle Over Cities](./code/1013.md) - 图的连通性以及连通数量(图的遍历DFS算法)
- [1018 Pulic Bike Management](./code/1018.md) - 图的最短路劲计算, 包含节点权值以及边权的计算 Dijkstra + DFS
- [1021 Deepest Root](./code/1021.md) - 图的遍历以及连通块的计算, DFS算法或者BFS算法, 注意回溯或者避免无向图的回路搜索

### 树

- [1004 Counting Leaves](./code/1004.md) - 计算每层的叶子节点
- [1020 Tree Traverals](./code/1020.md) - 树的遍历, 后序以及中序还原树, 以及BFS层次遍历树, 树的链式存储

### map的使用

- [1006 Sign in and Sign out](./code/1006.md) - 对于map数据结构的运用, 主要利用key的排序,优先输出, 准确来说就是模拟
- [1002 A+B for Polynomials](./code/1002.md) - 使用map来进行多项式加法的计算
- [1009 Product of Polynomials](./code/1009.md) - 同理使用map, 通过排序key值, 还有更新value来模拟多项式乘法
- [1022 Digital Library](./code/1022.md) - 通过 map以及set来进行书籍信息与id的映射, 然后输出对应信息

### queue的使用

- [1014 Waiting in Line](./code/1014.md) - 通过使用queue来模拟

### 数学

- [1015 Reversible Primes](./code/1015.md) - 计算素数和进制转换, 以及相应进制的十进制转换
- [1023 Hava Fun with Numbers](./code/1023.md) - 大整数的运算, 使用struct模拟正数之间的运算, 存储更大的数字
- [1024 Palindromic Number](./code/1024.md) - 大整数的运算, 会编写大整数的加法, 以及大整数的反转

### 模拟

- [1005 Spell It Right](./code/1005.md) - 字符串操作, 模拟
- [1008 Elevator](./code/1008.md) - 直接模拟, 简单一遍过
- [1011 World Cup Betting](./code/1011.md) - 简单模拟, 使用了map存储数据
- [1017 Queuing at Bank](./code/1017.md) - 按照数据规则, 筛选适合条件的数据, 排序, 进行时间处理
- [1019 General Palindromic Number](./code/1019.md) - 进制转换以及判断回文数
- [1022 Digital Library](./code/1022.md) - 通过 map以及set来进行书籍信息与id的映射, 然后输出对应信息

### 排序

- [1012 The Best Rank](./code/1012.md) - 主要是快速排序以及查询
- [1016 Phone Bills](./code/1016.md) - 使用快排, 需要重写cmp, 直接使用字典序排序, 时间可使用字符串, 后面转换即可
- [1025 PAT Ranking](./code/1025.md) - 排序

### 动态规划

- [1007 Maximum Subsequence Sum](./code/1007.md) - 最大和子序列查找

### 二分法

- [1010 Radix](./code/1010.md) - 二分法查找进制, 需要找到比较函数, 上下界

