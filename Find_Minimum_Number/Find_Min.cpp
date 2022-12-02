/*

Write a program which accepts input from the user in linked list and return minimum number.

Input Linked List : |110|->|230|->|320|->|240|
Output : 110

*/

#include<iostream>
#include"LinkedList.h"                      //user defined header file (generic data structures(Linked Lis))
using namespace std;

template <class T>
class Solution
{
    private:

    SinglyLinearLinkedList<int> *p;

    public:
    
    Solution();
    ~Solution();
    void accept(int);
    T findMin();
};

template <class T>
Solution<T>::Solution()                      //to allocating the resources
{
    p = new SinglyLinearLinkedList<int>();
}

template <class T>
Solution<T>::~Solution()                    //to deallocate the resources 
{
    delete p;
    p = NULL;
}

template <class T>
void Solution<T>::accept(int iSize)         //to accept the input from user
{
    int i = 0, iData = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

template <class T>
T Solution<T>::findMin()                    //to find the minimum data
{
    T iMin = p->pHead->Data;
    struct node<T> *pTemp = NULL;
    pTemp = p->pHead;

    while(pTemp != NULL)
    {       
        if(iMin > pTemp->Data)              //logic
        {
            iMin = pTemp->Data;
        }
        pTemp = pTemp->pNext;
    }
    return iMin;
}

int main()                                   //entry point function
{   
    Solution<int> obj;
    int iLength = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);

    cout<<"Minimum number is : "<<obj.findMin();

    return 0;
}