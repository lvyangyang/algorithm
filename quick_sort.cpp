#include<iostream>
#include<cstdlib>
using namespace std;

template<class T>
int partition(T *A,int start,int end)
{
    int iter_s,iter_e;
    iter_s=start;
    iter_e=end;
    while(iter_s!=iter_e)
    {
        if(A[iter_s]>A[iter_s+1])
        {
            swap(A[iter_s],A[iter_s+1]);
            iter_s++;
        }
        else{
            if(A[iter_e]<=A[iter_s])
            swap(A[iter_e],A[iter_s+1]);

            iter_e--;
        }
    }
    return iter_s;

}

template<class T>
void quick_sort(T *A,int start,int end)
{
    if(start<end)
    {
        int mid=partition(A,start,end);
        quick_sort(A,start,mid);
        quick_sort(A,mid+1,end);
    }
}

int main()
{   
    int list_length=80;
    int* list=new int[list_length];
    int iter=0;
    srand(25);
    for(iter=0;iter<list_length;iter++)
    list[iter]=rand();
    swap(list[0],list[15]);
    cout<<list[0]<<endl;
    partition(list,0,list_length-1);
    
    quick_sort(list,0,list_length-1);
   

    for(iter=0;iter<list_length;iter++)
    cout<<list[iter]<<" ";
    return 1;

}