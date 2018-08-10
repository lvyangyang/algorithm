template<class T>
class BinaryTreeNode{
    T data;
    BinaryTreeNode<T> *leftnode;
    BinaryTreeNode<T> *rightnode;

};

template<class T>
void PreOrder(BinaryTreeNode<T> *t)
{
    if(t)
    {
        cout<<t->data;
        PreOrder(t->leftnode);
        PreOrder(t->rightnode);
    }

}

template<class T>
void InOrder(BinaryTreeNode<T> *t)
{
    if(t)
    {       
        PreOrder(t->leftnode);
        cout<<t->data;
        PreOrder(t->rightnode);
    }

}

template<class T>
void PostOrder(BinaryTreeNode<T> *t)
{
    if(t)
    {       
        PreOrder(t->leftnode);    
        PreOrder(t->rightnode);
        cout<<t->data;
    }
}

template<class T>
void CopyBinaryTree(BinaryTreeNode<T> *t,BinaryTreeNode<T> *copyed)
{    
    if(t)
    {  
        copyed=new BinaryTreeNode<T>;

        CopyBinaryTree(t->leftnode,copyed->leftnode);
        CopyBinaryTree(t->rightnode,copyed->leftnode);
       
        copyed->data=t->data;
        
    }
    
}