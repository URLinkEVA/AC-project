# 例题
AcWing 665. 倍数

AcWing 660. 零食

AcWing 659. 区间

AcWing 664. 三角形

AcWing 667. 游戏时间

AcWing 669. 加薪

AcWing 670. 动物

# 习题
AcWing 657. 选择练习

AcWing 671. DDD

AcWing 662. 点的坐标

AcWing 666. 三角形类型
```cpp
//三条边排序
if(a<b) swap(a,b);
if(a<c) swap(a,c);
if(b<c) swap(b,c);
```
AcWing 668. 游戏时间2
```cpp
//分钟比较
t1 = a*60 + b;
t2 = c*60 + d;
if(t2>t1) cout << "O JOGO DUROU " << (t2-t1)/60 << " HORA(S) E "<< (t2-t1)%60 <<" MINUTO(S)" << endl;
else cout << "O JOGO DUROU "<< (24*60+t2-t1)/60 <<" HORA(S) E "<< (24*60+t2-t1)%60 <<" MINUTO(S)" << endl;
```

AcWing 672. 税

AcWing 663. 简单排序

AcWing 658. 一元二次方程公式

AcWing 661. 平均数3
