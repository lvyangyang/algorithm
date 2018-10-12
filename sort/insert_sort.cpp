#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
void insert(const int& start,const int& end,const int& list_length,T *list)
{
    if(start>=end||end>list_length-1)
    return;
    T temp=list[end];
    int iter=end;
    while(iter>start)
    {
        list[iter]=list[iter-1];
        iter--;
    }
    
    list[start]=temp;
}

template<class T>
void insert_sort(const int& list_length,T *list)
{
    int iter=0;
    while(iter<list_length)
    {
        int iter_sub=0;
        while(iter_sub<iter)
        {
            if(list[iter]<=list[iter_sub])
            break;
            iter_sub++;
        }
        insert(iter_sub,iter,list_length,list);
        iter++;
    }
}

int main()
{   
    int list_length=25;
    int* list=new int[list_length];
    int iter=0;
    for(iter=0;iter<list_length;iter++)
    list[iter]=rand();
    insert_sort(list_length,list);
    for(iter=0;iter<list_length;iter++)
    cout<<list[iter]<<endl;
    return 1;
   
}
