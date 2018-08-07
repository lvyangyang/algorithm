#include<iostream>
using namespace std;
template<class T>
void subset(T list[],int selected[],int index,int end_index)
{   int i;
    if(index==end_index){
        cout<<"{";
            for(i=0;i<end_index;i++)
            {   if(selected[i]==1)
                    cout<<list[i];
            }
            cout<<"}";
            cout<<endl;
    return;
    }
    

    selected[index]=0;
    subset(list,selected,index+1,end_index);
    selected[index]=1;
    subset(list,selected,index+1,end_index);
}

int main()
{
    char list[5]={'a','b','c','d','e'};
    int selected[5];

    subset(list,selected,0,5);
    return 0;
}