#include<iostream>
using namespace std;

template<class T>
struct node
{
    T Data;
    struct node *pNext;
};

template<class T>
class SinglyLinearLinkedList
{   
    public:
    int iCount;
    struct node<T>* pHead;

    SinglyLinearLinkedList();
    int countNode();
    void display();
    void insertFirst(T);
    void insertLast(T);
    void insertAtPos(T, int);
    T deleteFirst();
    T deleteLast();
    T deleteAtPos(int);
};

template<class T>
SinglyLinearLinkedList<T>::SinglyLinearLinkedList()
{
    pHead = NULL;
    iCount  = 0;
}

template<class T>
int SinglyLinearLinkedList<T>::countNode()
{
    return iCount;
}

template<class T>
void SinglyLinearLinkedList<T>::display()
{
    if(pHead == NULL)
    {
        cout<<"Linked List is empty !!"<<endl;
        return;
    }

    struct node<T> *pTemp = NULL;
    pTemp = pHead;

    while(pTemp != NULL)
    {
        cout<<"|"<<pTemp->Data<<"|->";
        pTemp = pTemp->pNext;
    }
    cout<<"NULL"<<endl;
}

template<class T>
void SinglyLinearLinkedList<T>::insertFirst(T Value)
{
    struct node<T> *pNewNode = NULL;
    pNewNode = new struct node<T>;

    pNewNode->Data = Value;
    pNewNode->pNext = pHead;
    pHead = pNewNode;

    iCount++;
}

template<class T>
void SinglyLinearLinkedList<T>::insertLast(T Value)
{
    struct node<T> *pNewNode = NULL;
    struct node<T> *pTemp = NULL;
    pNewNode = new struct node<T>;

    pNewNode->Data = Value;
    pNewNode->pNext = NULL;

    if(pHead == NULL)
    {
        pHead = pNewNode;
    }
    else
    {
        pTemp = pHead;

        while(pTemp->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        pTemp->pNext = pNewNode;
    }

    iCount++;
}

template<class T>
void SinglyLinearLinkedList<T>::insertAtPos(T Value, int iPos)
{
    int i = 0, iSize = 0;
    iSize = countNode();
    struct node<T> *pNewNode = NULL;
    struct node<T> *pTemp = NULL;

    if(iPos < 1 || iPos > iSize + 1)
    {
        return;
    }

    if(iPos == 1)
    {
        insertFirst(Value);
    }
    else if(iPos == iSize + 1)
    {
        insertLast(Value);
    }
    else
    {   
        pTemp = pHead;
        pNewNode = new struct node<T>;
        pNewNode->Data = Value;

        for(i = 1; i < iPos-1; i++)
        {
            pTemp = pTemp->pNext;
        }

        pNewNode->pNext = pTemp->pNext;
        pTemp->pNext = pNewNode;

        iCount++;
    }
}

template<class T>
T SinglyLinearLinkedList<T>::deleteFirst()
{
    struct node<T> *pTemp = NULL;
    T DelData;

    if(pHead == NULL)
    {
        return -1;
    }

    pTemp = pHead;
    pHead = pHead->pNext;
    pTemp->pNext = NULL;
    DelData = pTemp->Data;
    delete pTemp;
    pTemp = NULL;

    iCount--;
    return DelData;
}

template<class T>
T SinglyLinearLinkedList<T>::deleteLast()
{
    T DelData;
    struct node<T> *pTemp = NULL;

    if(pHead == NULL)
    {
        return -1;
    }

    if(pHead->pNext == NULL)
    {
        DelData = pHead->Data;
        delete pHead;
        pHead = NULL;
    }
    else
    {
        pTemp = pHead;

        while(pTemp->pNext->pNext != NULL)
        {
            pTemp= pTemp->pNext;
        }
        DelData = pTemp->pNext->Data;
        delete pTemp->pNext;
        pTemp->pNext = NULL;
    }

    iCount--;
    return DelData;
}

template<class T>
T SinglyLinearLinkedList<T>::deleteAtPos(int iPos)
{
    int i = 0, iSize = 0;
    T DelData;
    iSize = countNode();
    struct node<T> *pTemp = NULL;
    struct node<T> *pTempDel = NULL;

    if(iPos < 1 || iPos > iSize)
    {
        return -1;
    }

    if(iPos == 1)
    {
        deleteFirst();
    }
    else if(iPos == iSize)
    {
        deleteLast();
    }
    else
    {   
        pTemp = pHead;

        for(i = 1; i < iPos - 1; i++)
        {
            pTemp = pTemp->pNext;
        }
        pTempDel = pTemp->pNext;
        DelData = pTempDel->Data;
        pTemp->pNext = pTemp->pNext->pNext;
        delete pTempDel;
        pTempDel = NULL;

        iCount--;
        return DelData;
    }
}