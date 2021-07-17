#include <iostream>
#include <future>
#include <thread>
#include <chrono>

#include <queue>
#include <stack>

// queue = FIFO
// stack = LIFO
template <typename T>
class Queue
{
public:
    Queue() 
    {
        
    }

    Queue(const Queue &que)
    {
        inStack = que.inStack;
    }
    T pop() 
    {
        if (outStack.empty() )
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        auto value = outStack.top();
        outStack.pop();
        return value;
    }
    void push(T value) {
        inStack.push(value);
    }

    bool empty()
    {
        return inStack.empty() && outStack.empty();
    }

private:
    std::stack<T> inStack;
    std::stack<T> outStack;

};
int main()
{

    Queue<int> testQueue;
    testQueue.push(4);
    testQueue.push(5);

    std::cout << testQueue.pop() << std::endl;


    const char* c1 = new char[5]("abcd");
    char const *c2 = new char[5]("abcd");
    char * const c3 = new char[5]("abcd");
    //c1[2] = 't';
    //c2[2] = 't';
    c3[2] = 't';
    c2 = c1;
    c1 = c2;
    //c3 = c2;
    return 0;
}

//const char* is a pointer to a constant character
//char* const is a constant pointer to a character
//const char* const is a constant pointer to a constant character

//before * => value stored is constant
//after * => pointer itself is constant