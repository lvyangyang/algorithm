#include<iostream>
using namespace std;
template<class T>
class MaxHeap{
    public:
    MaxHeap(int MaxHeapSize=10);
    ~MaxHeap(){delete[] heap;}
    T Max(){if(CurrentSize==0) throw "out of bounds"; return heap[1];}
    MaxHeap<T>& Insert(const T& x);
    MaxHeap<T>& Delete(T& x);
    void Output();
    private:
    int max_of_three(int parent,int left,int right);
    int CurrentSize,MaxSize;
    T *heap;
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{
    MaxSize=MaxHeapSize;
    heap=new T[MaxSize+1];
    CurrentSize=0;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x)
{
    if(CurrentSize==MaxSize)
    throw "out of bounds";
    heap[++CurrentSize]=x;

    int present=CurrentSize;
    int parent=present/2;
    T temp;
    while(parent)
    {
        if(heap[present]>heap[parent])
        {
            temp=heap[parent];
            heap[parent]=heap[present];
            heap[present]=temp;

            present=parent;
            parent=parent/2;
        }
        else break;
    }
    return *this;
}

template<class T>
int MaxHeap<T>::max_of_three(int parent,int left,int right)
{
    if(parent>CurrentSize||left>CurrentSize||right>CurrentSize)
    throw "out of range";
    int temp=(heap[parent]>=heap[left]? parent:left);
    return heap[temp]>=heap[right]? temp:right;
}


template<class T>
MaxHeap<T>& MaxHeap<T>::Delete(T& x)
{
    x=heap[1];
    heap[1]=heap[CurrentSize];
    CurrentSize--;

    T temp;
    int max;
    int parent=1;
    while(parent<=CurrentSize/2)
    {
        if((2*parent+1)>CurrentSize)
        {
            max=max_of_three(parent,2*parent,2*parent+1);
            if(max!=parent)
            {
               temp=heap[parent];
               heap[parent]=heap[max];
               heap[max]=heap[parent];
            }
            else break;
            
        }
        else
        {
            if(heap[parent]<heap[2*parent])
            {
               temp=heap[parent];
               heap[parent]=heap[2*parent];
               heap[2*parent]=heap[parent];
            }
            else break;
        }

    }

}

template<class T>
void MaxHeap<T>::Output()
{
    for(int i=1;i<=CurrentSize;i++)
    {
        cout<<heap[i];
        cout<<" ";
    }
    cout<<endl;
}

int main()
{
    MaxHeap<int> heap_test(50);
    heap_test.Insert(15);
    heap_test.Insert(25);
    heap_test.Insert(5);
    heap_test.Insert(55);
    heap_test.Insert(6);
    heap_test.Insert(16);
    heap_test.Output();
    
    int x;
    heap_test.Delete(x);
    heap_test.Insert(66);
    heap_test.Output();
    heap_test.Insert(23);
    heap_test.Delete(x);
    heap_test.Output();
    

    return 0;
}

