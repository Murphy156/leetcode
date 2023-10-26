# 哈希表
## 哈希表可以解决的问题
    一般哈希表都是用来快速判断一个元素是否出现集合里
## 哈希函数
        把学生的姓名直接映射为哈希表上的索引，然后就可以通过查询索引下标快速知道这位同学是否在这所学校里。
        通过hashcode把名字转化为数值，一般hashcode是通过特定编码方式，可以将其他数据格式转化为不同的数值，
    这样就把学生名字映射为哈希表上的索引数字
        如果hashCode得到的数值大于哈希表的大小，为了保证映射出来的索引数值都落在哈希表，我们会再次对数值
    做一个取模操作。
        如果学生的数量大于哈希表的大小，就会出现哈希碰撞。

## 哈希碰撞
    一般的哈希碰撞有两种解决方法，拉链法和线性探测法
### 拉链法
    发生冲突的元素存储在链表中，这样，就可以通过索引找到两个冲突的元素
### 线性探测法
    使用线性探测法，一定要保证tablesize大于datasize，我们需要依靠哈希表中的空位来解决碰撞问题
    