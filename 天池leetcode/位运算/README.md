# 原码、反码和补码
二进制有三种不同的表示形式：原码、反码和补码，计笪机内部使用补码来表示。

原码：就是其二进制表示（注意，有一位符号位）
```
00 00 00 11 -> 3
10 00 00 11 -> -3
```

反码：正数的反码就是原码，负数的反码是符号位不变，其余位取反（对应正数按位取
```
00 00 00 11 -> 3
11 11 11 00 -> -3
```
补码：正数的补码就是原码,负数的补码是反码+1。
```
00 00 00 11 -> 3
11 11 11 01 -> -3
```
符号位：最高位为符号位,0表示正数,1表示负数。在位运算中符号位也参与运算。


# 课后习题
## 2的幂
```
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。
```
### 示例1
```
输入：n = 1
输出：true
解释：20 = 1
```
### 示例2
```
输入：n = 3
输出：false
```


## 只出现一次的数字 II
```
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
```
### 示例1
```
输入：nums = [2,2,3,2]
输出：3
```
### 示例2
```
输入：nums = [0,1,0,1,0,1,99]
输出：99
```

## 子集
> 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

> 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

### 示例1
```
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

### 示例2
```
输入：nums = [0]
输出：[[],[0]]
```
