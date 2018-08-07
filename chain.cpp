#include<iostream>
using namespace std;
template<class T>
class ChainNode{
    public:
    T data;
    ChainNode<T> *link;
};

template<class T>
class Chain{
    public :
        Chain() {first = 0;}
        ~ Chain();
        bool IsEmpty() const {return first == 0;}
        int Length() const;
        bool Find(int k, T& x) const;
        int Search(const T& x) const;
        Chain<T>& Delete(int k, T& x);
        Chain<T>& Insert(int k, const T& x);
        Chain<T>& Reverse();
        void Output(ostream& out) const;
        private:
        ChainNode<T> *first; // 指向第一个节点的指针
};

template<class T>
Chain<T>::~Chain()
{   ChainNode<T> *next;
    ChainNode<T> *current=first;
    while(current)
    {
        next=current->link;
        delete first;
        current=next;
    }
}

template<class T>
int Chain<T>::Length() const
{
    int length=0;
    ChainNode<T> *current=first;
    while(current)
    {   length++;
        current=current->link;       
    }
    return length;
}

template<class T>
bool Chain<T>::Find(int k,T &x) const
{
    if(k<1) return false;
    int index=1;
    ChainNode<T> *current=first;
    while(index<k&&current)
    {
        index++;
        current=current->link;
    }
    if(current){x=current->data;return true;}
    return false;
}

template<class T>
int Chain<T>::Search(const T &x) const
{   int index=1;
    ChainNode<T> *current=first;
    while(current&&current->data!=x)
    {   index++;
        current=current->link;
    }
    if(current) return index;
    return 0;
}
template<class T>
void Chain<T>::Output(ostream& out) const
{
    ChainNode<T> *current=first;
    while(current)
    {
        out<<current->data<<" ";
        current=current->link;
    }
}

template<class T>
ostream & operator<<(ostream &out,Chain<T> &x)
{
    x.Output(out);
    return out;
}

template<class T>
Chain<T>& Chain<T>::Delete(int k,T& x)
{
    if(k<1||!first)
    throw "out of range";
    
    
    if(k==1)
    {
        x=first->data;
        delete first;
    }
    if(k>1)
    {   
        int index=1;
        ChainNode<T> *current=first;
        ChainNode<T> *prev_node;

        while(index<k&&current)
        {
            prev_node=current;
            current=current->link;
            index++;
        } 
        if(current)
        {
            prev_node->link=current->link;
            x=current->data;
            delete current;
        }
        else 
        throw "out of range";
    }
    
    return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k,const T&x)
{
    if(k<0) 
    {
       throw "out of range";
    } 
    if(k==0)
    {
        ChainNode<T> * new_node1=new ChainNode<T>;
        new_node1->data=x;
        new_node1->link=first;
        first=new_node1;
    }
    if(k>0)
    {
        int index=1;
        ChainNode<T> * current=first;
        while(index<k&&current)
        {   
            index++;
            current=current->link;
        }
        if(!current) throw "out of range";

        ChainNode<T> * new_node=new ChainNode<T>;
        new_node->data=x;
        new_node->link=current->link;
        current->link=new_node;  
    }
    

    return *this;
}

template<class T>
Chain<T>& Chain<T>::Reverse()
{
    ChainNode<T> *current_end=first;
    ChainNode<T> * temp_next,*next;

    temp_next=first->link;
    current_end=first;
    first->link=NULL;
    while(temp_next)
    {   next=temp_next; 
        temp_next=next->link;
        next->link=current_end;
        current_end=next;
    }
    first=current_end;

    return *this;
}

int main()
{
Chain<int> test_chain;
test_chain.Insert(0,2);
test_chain.Insert(1,3);
test_chain.Insert(2,4);
test_chain.Insert(3,5);
test_chain.Insert(4,6);
test_chain.Output(cout);
cout<<endl;
test_chain.Reverse();
test_chain.Output(cout);
return 0;
}