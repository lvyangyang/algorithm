#include<iostream>
int fibonacci(int fb_index)
{
    if(fb_index==1)
    return 1;
    else if(fb_index==2)
    return 2;
    else
    return fibonacci(fb_index-1)+fibonacci(fb_index-2);
}

int main()
{
    std::cout<<fibonacci(5);
    return 0;
}