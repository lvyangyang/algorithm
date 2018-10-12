
#include<iostream>
#include<cstdlib>
using namespace std;
template <class T>
void bubble_sort(T *A,int p,int q)
{
    int i,j;
    for(i=p;i<=q;i++)
    {
        for(j=q;j>i;j--)
        {
            if(A[j]<A[j-1])
            {
                T temp=A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
            }
        }
    }
}
int main()
{
    int list_length=6;
    int* list=new int[list_length];
    int iter=0;

    for(iter=0;iter<list_length;iter++)
    list[iter]=rand();
    bubble_sort(list,0,list_length-1);
    for(iter=0;iter<list_length;iter++)
    cout<<list[iter]<<endl;
    return 1;

}