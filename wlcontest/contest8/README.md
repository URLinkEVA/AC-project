# "蔚来杯"2022牛客暑期多校训练营8

https://ac.nowcoder.com/acm/contest/33193

## A Puzzle: X-Sums Sudoku
- 可以证明当边长为 2的幂次时贪心可以得到字典序最小数独
- 每个位置的值可以通过异或运算得到
- 容易计算异或值的前缀和, 复杂度 O(n + m)

## B Puzzle: Patrick's Parabox
- 可以只记录所有 box 和 player 相邻的状态进行 01BFS
- 用圆方树判断 player 是否能绕过 box 到达某个位置
- 复杂度 O(nm log nm)

## C Puzzle: Hearthstone
- 考虑维护 add 和 test x序列, 初始时有 test 1 到 test n
- add: 在末尾添加 add
- test x y 操作: 将 test x 移动到末尾. 如果 y = 1，移除序列中原来 test x后的第一个 add, 若不存在则是 bug
- 序列合法当且仅当任意前缀 test 数量大于或等于 add
- 一定不存在的: 最后一个 add 后 test 的数量
- 一定存在的: 最后一个 test 数量大于 add 的前缀中 add 的数量
- 用线段树即可维护，复杂度 O(q log q)

## D Poker Game: Decision
- 博弈状态不超过 6!
- 需要比较牌型的次数不超过 (6 3), 记忆化即可通过

## E Poker Game: Construction
- Alice 必能胜
- Bob 不能胜的情况有: AA 对不成顺 AXo; XY 对 XYo; XX 对 XX
- 不能平的情况有:
- XX 对除 XX 外的牌;
- XY 对 ZZ;
- XY 对 ZW(X>Y,Z>W) 且 Y<X<W<Z;
- XY 对 ZW(X>Y,Z>W) 且 W<Y<X<Z;
- XY 对 ZW(X>Y,Z>W) 且 W<Z<Y<X;

## F Longest Common Subsequence
- 如果两个序列中有相同数字，那么后面的数字一定全一样
- 对每个数字找到出现的最早位置
- 复杂度 O(n + m)

## G Lexicographic Comparison
- 维护 p形成的环
- 只需要比较环长不整除 x − y 的环中涉及的最小下标
- 平衡树维护所有环
- 方法一: 维护所有环长的对应最小下标, 只有 √q种环长
- 方法二: 维护区间最小公倍数
- 复杂度 O(q√q) 或 O(wqlog q) (w = 64)

## H Expression Evaluation
- 将当前正在读的数储存为 32 位 01 序列
- 每处理一维复杂度是 O(w) (w = 32)

## I Equivalence in Connectivity
- 图的连通性可以用并查集 Hash 表示
- 使用可撤销并查集和离线删除的技巧
- 树结构可以使用 DFS 序变成序列结构
- 复杂度 O(N log2 N)(N = n + m + q)

## J Symmetry: Tree
- 唯一重心的树, 重心一定在对称轴上
- 成对的同构子树可以放在对称轴两侧, 否则要沿着对称轴放
- 需要考虑双重心的子树, 如果两侧同构, 也可以构造答案
- 复杂度 O(nlog n)

## K Symmetry: Convex
- 考虑角 PiP1P2, 特判对称轴是它的平分线或者是 P1Pi的中垂线的情况
- 否则它一定对称到 Cn的角. 由于角一直变大，因此只需要检查 O(n)次
- 复杂度 O(nlog n)

## L Symmetry: Closure
- 满足正切值是有理数以及和 π的比值是有理数的角只有 45度角的倍数
- 存在不是 45度倍数的角, 共点会在圆周上稠密, 不共点会在平面上稠密
- 当存在不共点的线且互为 45度倍数角, 点会按周期在平面上排布
- 作旋转平移变化使得 l1到 x轴
- 如果都是垂直或水平, 按两维分别计算，如果有多条需要计算 gcd
- 否则需要考虑 45度的 gcd 和垂直水平的 gcd 的关系
- 复杂度 O(n + q)
