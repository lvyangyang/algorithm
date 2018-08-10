template<class T>
class HashTable{
    public:
    HashTable(int divisor=11);
    ~HashTable(){delete[] ht;delete[] empty;}
    bool Search(const int& k,T& t);
    HashTable<T>& Insert(const T& t);
    HashTable<T>& Delete(const T& t);
    private:
    bool *empty;
    T *ht;
    int divisor;
};

template<class T>
HashTable<T>::HashTable(int divisor)
{
    this->divisor=divisor;
    empty=new bool[divisor];
    ht=new T[divisor];
    for(int i=0;i<divisor;i++)
    empty[i]=true;
};





template<class T>
bool HashTable<T>::Search(const int& k,T& t)
{
    int i=k%divisor;
    int p=i;
    while(true)
    {      
        if(empty[p])
        return false;
        else
            {
               if(ht[p]%diviser==i)
                    {
                        t=ht[p];
                        return true;
                    } 
            }
        p++;
        if(p%divisor==i)
        return false;
    }
}

template<class T>
HashTable<T>& HashTable<T>::Insert(const T& t)
{
    int i=t%divisor;
    int p=i;
    while(true)
    {      
        if(empty[p])
        break;
        p++;
        if(p%divisor==i)
        throw "hash table full";
    }
    ht[p]=t;
    empty[p]=false;
    return *this;
}

template<class T>
HashTable<T>& HashTable<T>::Delete(const T& t)
{
    int i=t%divisor;
    int p=i;
    while(true)
    {      
        if(empty[p])
        return *this;
        else
            {
               if(ht[p]==t)
                    {
                        break;
                    } 
            }
        p++;
        if(p%divisor==i)
        return false;
    }

    empty[p]=true;

    int adjust_p=p;
    while(true)
    {
       if(empty[(adjust_p+1)%divisor]) 
       break;
       else
            {
               if(ht[(adjust_p+1)%divisor]%diviser<=adjust_p)
                    {
                        ht[adjust_p]=ht[(adjust_p+1)%divisor];
                        empty[adjust_p]=false;
                        empty[(adjust_p+1)%divisor]=true;
                    }
                else break; 
            }
       adjust_p++;
    }
}



