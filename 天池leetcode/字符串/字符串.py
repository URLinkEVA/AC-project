# 字符串比较
def strcmp(str1,str2):
    index1,index2 = 0, 0
    while index1 < len(str1) and index2 < len(str2):
        if ord(str1[index1]) == ord(str2[index2]):
            index1 += 1
            index2 += 1
        elif ord(str1[index1]) < ord(str2[index2]):
            return -1
        else:
            return 1
        
    if len(str1) < len(str2):
        return -1
    elif len(str1) > len(str2):
        return 1
    else:
        return 0

# 单模式串朴素匹配算法
def bruteForce(T: str, p: str) -> int:
    n, m = len(T), len(p)

    i, j = 0, 0       # i表示T当前位置，j表示P当前位置
        
    while i < n and j < m:   # i或j其中一个到达尾部时停止搜索
        if T[i] == p[j]:     # 如果相等，则进行下一个字符串的匹配
            i += 1
            j += 1
        else:
            i = i - (j - 1)  # 如果匹配失败则将i移动到上次匹配开始位置的下一个位置
            j = 0            # 匹配失败 j 回退到模式串开始位置

    if j == m:
        return i - j         # 匹配成功，返回匹配的开始位置
    else:
        return -1            # 匹配失败，返回-1   


# KMP算法
# 生成next数组
# next[j]表示下标j之前的模式串p中，最长相等前后缀的长度
def generateNext(p: str):
    m =len(p)
    next = [0 for _ in range(m)]   # 初始化数组元素全部为0

    left = 0      # left表示前缀串开始所在的下标位置
    for right in range(1, m):  # right表示后缀串开始所在的下标位置
        while left > 0 and p[left] != p[right]:   # 匹配不成功，left进行回退，left==0时停止回退
            left = next[left - 1]       # left进行回退操作
        if p[left] == p[right]:        # 匹配成功，找到相同的前后缀，先让left+=1，此时left为前缀长度
            left += 1      
        next[right] = left      # 记录前缀长度，跟新next[right]，结束本次循环，right+=1

    return next

# T为文本串，p为模式串
def KMP(T: str, p: str) -> int:
    n, m = len(T), len(p)

    next = generateNext(p)   # 生成next数组

    j = 0     
    for i in range(n):
        while j > 0 and T[i] != p[j]:  # 如果模式串前缀匹配不成功，将模式串进行回退，j==0时停止回退
            j = next[j - 1]
        if T[i] == p[j]:   # 当前模式串前缀匹配成功，令j+=1，继续匹配
            j += 1
        if j == m:         # 当前模式串完全匹配成功，返回匹配开始位置
            return i - j + 1 
    return -1     # 匹配失败，返回-1

    //43.00