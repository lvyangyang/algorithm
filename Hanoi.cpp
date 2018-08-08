#include<iostream>
using namespace std;
template<class T>
class Stack{
public:
Stack(int MaxStackSize=10);
~Stack(){delete[] stack;}
bool IsEmpty() const {return top==-1;}
bool IsFull() const {return top==MaxTop;}
T Top() const;
void Output(ostream& out) const;
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
void Stack<T>::Output(ostream& out) const
{
    for(int i=0;i<=top;i++)
    out<<stack[i];
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

void hanoi_tower(int n,Stack<int> &x,Stack<int> &y,Stack<int> &z)
{   if(n>0){
        hanoi_tower(n-1,x,z,y);
        int base;
        x.Delete(base);
        y.Add(base);
        hanoi_tower(n-1,z,y,x);

    }
    
}

int main()
{
    Stack<int> x(5);
    Stack<int> y(5);
    Stack<int> z(5);

   
    for(int i=1;i<=5;i++)
        x.Add(6-i);
    x.Output(cout);
    cout<<endl;

    hanoi_tower(5,x,y,z);

    cout<<"x:";
    x.Output(cout);
    cout<<"y:";
    y.Output(cout);
    cout<<"z:";
    z.Output(cout);
    return 0;


}