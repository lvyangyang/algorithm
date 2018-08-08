#include<iostream>
using namespace std;
template<class T>
class Queue{
    public:
    Queue(int MaxQueueSize=10);
    ~Queue(){delete[] queue;};
    bool IsEmpty(){return front==rear;}
    bool IsFull(){return ((rear+1)%MaxSize==front) ? 1:0;}
    T First() const;
    T Last() const;
    Queue<T>& Add(const T &x);
    Queue<T>& Delete(T& x);
    private:
    int front;
    int rear;
    int MaxSize;
    T *queue;
};

template<class T>
Queue<T>::Queue(int MaxQueueSize)
{
    MaxSize=MaxQueueSize+1;
    queue=new T[MaxSize];
    front=0;
    rear=0;    
}

template<class T>
T Queue<T>::First() const
{
    if(this.IsEmpty())
    throw "out of bounds";
    return queue[(front+1)%MaxSize];    
}

template<class T>
 T Queue<T>:: Last() const
 {  
     if(this->IsEmpty())
    throw "out of bounds";
     return queue[rear];
 }

template<class T>
Queue<T>& Queue<T>:: Add(const T &x)
{
    if(this->IsFull())
    throw "out of bounds";
    queue[(++rear)%MaxSize]=x;
    return *this;
}

template<class T>
Queue<T>& Queue<T>:: Delete(T &x)
{
    if(this->IsEmpty())
    throw "out of bounds";
    x=queue[(++front)%MaxSize];
    return *this;
}

int main()
{
    Queue<int> q(10);
    q.Add(5);
    q.Add(6);

    int x;
    q.Delete(x);
    cout<<x;
    q.Delete(x);
    cout<<x;

    return 0;
}