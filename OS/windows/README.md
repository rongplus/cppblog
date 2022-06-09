STL Usage 
=============================================
* [function&bind](callback) using fuciton and bind to connect objects. std function or functionor. class function, using std::bind, global function or static function, useing its address.
* [throw&catch](throwcatch) How to set default terminate function and how to use noexcept keyword.
* [type_cast](cast) There are 4 cast functions: dynamic_cast, static_cast, const_cast,reinterpret_cast
* [lambda](lambda) notice use the defference between value & refrence.  



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
查看:O(logN)
删除:O(logN)

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