工厂模式 （Factory Patten）在使用时创建对象。when use then new
建设者模式 （Builder）     已经有对象（Object) 在builder中使用。after new then use。

简单工厂   Factory（int type） type==1 ==>Create A， type=2 ==> Create B;  A B is inheritance from Base;
普通工厂   FactoryA ==>create A, FactoryB ==> Create B;  A B is inheritance from Base;
抽象工厂   Factory1 ==>create A1,B1, Factory2 ==> Create A2,B2;  A1,A2  inheritance from BaseA;  B1,B2  inheritance from BaseB;

适配器模式 Adapter 作用：将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。

桥接模式 Bridge   Product->setProperty(T a); Product->setProperty(T b);
装饰  Decorator   Property p; A->set(p); B->set(p);

代理模式  用一个跟对象一样的物体来取代实际对象。 Proxy is a structural design pattern that provides an object that acts as a substitute for a real service object used by a client. 
A proxy receives client requests, does some work (access control, caching, etc.) and then passes the request to a service object.
             A {};  Proxy: public A(){ A* realA;};
             main(){ Proxy A( new A());}

命令模式（command）命令模式的有点：1.能够容易地设计一个命令队列；2.在需要的情况下，可以比较容易地将命令记入日志。
                                3.可以容易的实现对请求的撤销和重做。4.由于加进新的具体命令类不影响其他的类，因此增加新的具体命令类很容易。

命令模式： 将所有的command放一起
观察者模式： 将所有对象放一起
策略模式： 将对象分类

Command：主要思想是将命令封装为一个类，这样可以解耦命令请求者与命令执行者。一般说与Command模式比较的是Chain of Responsibility，对于Command，设计者知道有那些命令，应该将命令传给具体的Command子类，Chain of Responsibility不知道具体的命令处理类。
Observer：一般用来处理多个对象观察同一份数据，比如用柱子和用网格显示用一份数据，柱子更新数据马上通知网格更新，用Observer比较方便，各个观察者都不知道对方的存在。

C++实现智能指针
 

一般来说，智能指针的实现需要以下步骤：

1.一个模板指针T* ptr，指向实际的对象。

2.一个引用次数(必须new出来的，不然会多个shared_ptr里面会有不同的引用次数而导致多次delete)。

3.重载operator*和operator->，使得能像指针一样使用shared_ptr。

4.重载copy constructor，使其引用次数加一。

5.重载operator=，如果原来的shared_ptr已经有对象，则让其引用次数减一并判断引用是否为零(是否调用delete)。

　然后将新的对象引用次数加一。

6.重载析构函数，使引用次数减一并判断引用是否为零(是否调用delete)。