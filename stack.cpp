#include<iostream>
template<class T>
class Stack{
public:
Stack(int MaxStackSize=10);
~Stack(){delete[] stack;}
bool IsEmpty() const {return top==-1;}
bool IsFull() const {return top==MaxTop;}
T Top() const;
Stack<T>& Add(const T &x);
Stack<T>& Delete(T &x);
private:
int top;
int MaxTop;
T *stack;
};

template<class T>
Stack<T>::Stack(int MaxStackSize)
{
    MaxTop=MaxStackSize;
    stack=new T[MaxTop];
    top=-1;
}

template<class T>
T Stack<T>::Top() const
{
    if(top==-1)
    return NULL;
    T t=stack[top];
    return t;
}

template<class T>
Stack<T>& Stack<T>::Add(const T &x) 
{
   if(top==MaxTop)
   throw "stack overflow";
   stack[++top]=x;
   return *this;
}

template<class T>
Stack<T>& Stack<T>::Delete(T &x)
{
    if(top==-1)
    throw "empty stack";
    x=stack[top];
    top--;
    return *this;
}

int main()
{
    Stack<int> test_stack(20);
    test_stack.Add(15);
    test_stack.Add(16);
    int x;
    test_stack.Delete(x);
    return 0;
}