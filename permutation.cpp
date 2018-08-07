#include<iostream>
#include<stdio.h> 
template<class T>
void swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<class T>
void Perm(T list[],int k,int m)
{   int i;
    if(k==m){
        for(i=0;i<=k;i++){
            std::cout<<list[i];            
        }
        std::cout<<std::endl;
        }
    else{
        for(i=k;i<=m;i++)
        {
            swap(list[k],list[i]);
            Perm(list,k+1,m);
            swap(list[k],list[i]);
        }

    }
    
}



int main()
{
    int list[]={1,2,3,4,5};
    Perm(list,0,4);
    return 0;
}