STL Usage 
=============================================
* [function&bind](callback) using fuciton and bind to connect objects. std function or functionor. class function, using std::bind, global function or static function, useing its address.
* [throw&catch](throwcatch) How to set default terminate function and how to use noexcept keyword.
* [type_cast](cast) There are 4 cast functions: dynamic_cast, static_cast, const_cast,reinterpret_cast
* [lambda](lambda) notice use the defference between value & refrence.  

多态性(polymorphism)

new features in C++ 11 and later
* 1, auto decltype
* 2, lvalue rvalue
* 3, initializer_list
* 4, lambda functor
* 5，template
* 6 thread
* 7 shared_ptr weak_ptr  unique_ptr
* 8 for loop
* 9 using base::base  
* 10 nullptr --> 0
* 11 final & override
* 12 default
* 13 delete 
* 14 constexpr
* 15 enum class

static_assert    regex

Underscore _ Brace {} parentheses（）  angle brackects<>
comma , semicolon ;  colon : double colon ::

 optimization optimize

1、栈区（stack）— 由编译器自动分配释放 ，存放函数参数值，局部变量值等。其操作方式类似于数据结构中栈。
2、堆区（heap） — 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。注意它与数据结构中堆是两回事，分配方式倒是类似于链表，呵呵。

Incremental development


map, set, multimap, and multiset
上述四种容器采用红黑树实现，红黑树是平衡二叉树的一种。不同操作的时间复杂度近似为:
插入: O(logN)
查看: O(logN)
删除: O(logN)

hash_map, hash_set, hash_multimap, and hash_multiset
上述四种容器采用哈希表实现，不同操作的时间复杂度为：
插入:O(1)，最坏情况O(N)。
查看:O(1)，最坏情况O(N)。
删除:O(1)，最坏情况O(N)。
记住，如果你采用合适的哈希函数，你可能永远不会看到最坏情况。但是记住这一点是有必要的。


A pointer which has not been initialized to anything (not even NULL) is known as wild pointer.
int *p;  /* wild pointer */
A pointer pointing to a memory location that has been deleted (or freed) is called dangling pointer.
int *p = new int(10);
delete p; //p is a dangling pointer;

The Build Pipeline: Preprocess, Compile, assemble, and Link

  - bitset
  - bloom filter


  std::chrono
  std::dynamic_pointer_cast
  std::numeric_limits
  std::runtime_error
  std::logic_error
  std::atomic_load_explicit
  shared_from_this
  std::shuffle
1. 序列式容器: array, vector, deque, list, forward_list --- 数组 或者 指针实现
2. 关联容器: set, map, multiset, multimap --- 二叉树 红黑树 O(logn)
3. 无顺序容器: unordered_map, unordered_set, unordered_multimap, unordered_multiset

补充拓展:
4. stack
5. queue
6. priority_queue
7. string
8. bitset: (0或1)
  deque（双端队列）是一个动态数组，可以向两端发展，因此不论在尾部或头部安插元素都十分迅速。 在中间部分安插元素则比较费时，因为必须移动其它元素。 = double queue
enable_shared_from_this，shared_from_this()
  4.9 unordered_map（c++11）
优点：效率很高，查找删除是常数算法

缺点：空间上用的多，无序，适合一千万以下数据。


emplace()构造生成的时候是以move的方式，来放到位置上去的

b.emplace(std::pair<const int, std::string>(10, std::string("aga"));

推荐用emplace来代替insert

map的[]形式，必须有默认构造函数(不推荐)


 std::call_once(g_flag,CreateInstance); //如果两个线程同时到这里，其中一个线程要
                                                   //等另外一个执行结束
 34         return m_instance;         


 覆盖与隐藏：

覆盖指的是派生类的虚拟函数覆盖了基类的同名且参数相同的函数！这种覆盖，要满足两个条件
　(a)有virtual关键字，在基类中函数声明的时候加上就可以了
　(b)基类CB中的函数和派生类CD中的函数要一模一样，什么叫一模一样，函数名，参数，返回类型三个条件。

隐藏指的是：子类无法调用到基类中某个的函数

满足任一条件即可。

1,同名同参无virtual
2,同名不同参不管有无virtual


map-- count() to find how many keys
      find() to find if value in map

std::count --> get num of item in container

 std::priority_queue<int,vector<int>, greater<int> > que; //--> elements from greater to less


 Depth First Traversals: 
(a) Inorder (Left, Root, Right) : 4 2 5 1 3 
(b) Preorder (Root, Left, Right) : 1 2 4 5 3 
(c) Postorder (Left, Right, Root) : 4 5 2 3 1
Breadth-First or Level Order Traversal: 1 2 3 4 5 


运算符	描述	实例
&	
按位与操作，按二进制位进行"与"运算。运算规则：

0&0=0;   
0&1=0;    
1&0=0;     
1&1=1;	(A & B) 将得到 12，即为 0000 1100
|	
按位或运算符，按二进制位进行"或"运算。运算规则：

0|0=0;   
0|1=1;   
1|0=1;    
1|1=1;	(A | B) 将得到 61，即为 0011 1101
^	
异或运算符，按二进制位进行"异或"运算。运算规则：

0^0=0;   
0^1=1;   
1^0=1;  
1^1=0;	(A ^ B) 将得到 49，即为 0011 0001
~	
取反运算符，按二进制位进行"取反"运算。运算规则：

~1=-2;   
~0=-1;	(~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式。
<<	二进制左移运算符。将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）。	A << 2 将得到 240，即为 1111 0000
>>	二进制右移运算符。将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。	A >> 2 将得到 15，即为 0000 1111


queue FIFO 
stack FILO