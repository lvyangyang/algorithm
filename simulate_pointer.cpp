template<class T>
class SimNode{
public:
T date;
int link;

};

template<class T>
class SimSpace{
public:
SimSpace(int MaxSpaceSize=100);
~SimSpace(){delete [] node;}
int Allocate();
void Deallocate(int &i);
private:
int NumberOfNodes,first1,first2;
SimNode<T> &node;
};

template<class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
    node=new SimNode<T> [MaxSpaceSize];
    NumberOfNodes=MaxSpaceSize;
    int index=0;
    while(index<NumberOfNodes)
    {
        index++;
        node[index].link=index+1;
    }
    node[NumberOfNodes].link=-1;
    first1=0;
    first2=-1;
}
template<class T>
int SimSpace<T>::Allocate()
{
    if(first2==-1)
    {
        if(first1==NumberOfNodes)
        throw "no memory";
        i=first1++;
    }
    
    i=first2;
    first2=node[first2].link;
    return i;

}

template<class T>
void SimSpace<T>::Deallocate(int& i)
{
    node[i].link=first2;
    first2=i;
    i=-1;
}