# 一维vector
## 创建一维vector：
```c++
vector<int> nums;//不指定长度
vector<int> nums(n); // 指定长度为n 
```
## 添加元素
```c++
nums.push_back(1);//直接从数组末端添加
nums[i] = 1;//直接赋值给第i个位置
```

## 删除元素
```c++
nums.resize(nums.size-i); //直接将数组长度减小，某种方式上删掉了后面i个
nums.pop_back();//删掉最后一个元素
```

## 数组遍历
```c++
for(int i = 0; i < nums.size(); i++){
    cout<<nums[i]<<endl;
}
```
## 其他 
获得长度：nums.size() 

排序(O(nlogn))：sort(nums.begin(),nums.end()); 

翻转：reverse(nums.begin(), nums.end()); 

合并两个vector：合并nums1和nums2，并将合并后的数组赋值给nums

```c++
vector<int> nums1(m),nums2(n);
vector<int> nums;
nums.resize(m+n);
merge(nums1.begin(), nums1.end(),nums2.begin(),nums2.end(),nums);
```

# 二维vector
## 创建m*n的二维vector: 直接定义
```c++
vector<vector <int> > nums(m ,vector<int>(n));    //m*n的二维vector
```

> 定义了一个vector容器，元素类型为vector<int>，初始化为包含m个vector<int>对象，每个对象都是一个新创立的vector<int>对象的拷贝，而这个新创立的vector<int>对象被初始化为包含n个0。

> vector<int>(n)表示构造一个无名且含n个0的vector<int>对象。

## 动态创建m*n的二维vector 
### 方法一：
```c++
vector<vector <int> > nums;
nums.resize(m);
for(int i=0;i<m;i++) nums[i].resize(n);
```

### 方法二：
```c++
vector<vector <int> > nums;
```
> nums.resize(m,vector<int>(n));

## 初始化二维数组
```c++
vector<vector <int> > nums(m ,vector<int>(n,0));    //m*n的二维vector，所有元素为0
```

获得二维数组的行数：nums.size(); 

获得二维数组的列数：nums[0].size()

## 数组遍历
```c++
int m = nums.size(),n = nums[0].size();
for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
        cout<<nums[i][j]<<endl;
    }
}
```

> 用vector定义二维数组还阔以酱紫 ——vector<node> v[maxn]; //备注：node 是结构体; maxn 是v数组里元素的个数
