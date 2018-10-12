#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
void merge(T *A,int p,int q,int r)
{   int iter_cout;
    int n1=q-p+1;
    int n2=r-q;
    if(n1<1||n2<1)
    return;
    T l1[n1];
    T l2[n2];
    int iter=0;
    while(iter+p<=q)
    {
        l1[iter]=A[iter+p];
        iter++;
    }
    iter=0;
    while(iter+q+1<=r)
    {
        l2[iter]=A[iter+q+1];
        iter++;
    }

    iter=0;
    int iter_1=0;
    int iter_2=0;
    while(iter+p<=r)
    {   
        if(iter_1>=n1)
        {
            A[iter+p]=l2[iter_2];
            iter++;
            iter_2++;
            continue;
        }
        if(iter_2>=n2)
        {
            A[iter+p]=l1[iter_1];
            iter++;
            iter_1++;
            continue;
        }

        if(l1[iter_1]<l2[iter_2])
        { 
          //  cout<<l1[iter_1]<<"<"<<l2[iter_2];
            A[iter+p]=l1[iter_1];
            iter_1++;
            iter++;
        }
        else{
         //   cout<<l1[iter_1]<<">"<<l2[iter_2];
            A[iter+p]=l2[iter_2];
            iter++;
            iter_2++;
        }
    
    }
}

template <class T>
void merge_sort(T *A, int start, int end)
{   
    if(start<end)
   {
    int iter;
    int mid=(end+start)/2;
    merge_sort(A,start,mid);

    merge_sort(A,mid+1,end);

    merge(A,start,mid,end);
    
   }
    
}

int main()
{
    int list_length=50;
    int* list=new int[list_length];
    int iter=0;

    for(iter=0;iter<list_length;iter++)
    list[iter]=rand();
    
    merge_sort(list,0,list_length-1);
    
   
 /*
   list[0]=1;
   list[1]=3;
   list[2]=5;
   list[3]=7;
   list[4]=9;
   list[5]=11;
   list[6]=2;
   list[7]=6;
   list[8]=8;
   merge(list,0,5,8);
  */
    for(iter=0;iter<list_length;iter++)
    cout<<list[iter]<<endl;
    return 1;

}