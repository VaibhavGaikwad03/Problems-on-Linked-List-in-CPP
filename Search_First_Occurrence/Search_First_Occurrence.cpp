/*

Write a program which accept the linked list as an input from the user and accept another number and return first occurence of that number.

Input Linked List : |10|->|20|->|30|->|40|->|50|->|30|->|70|
Input : 30

Output : 3

*/
 
#include<iostream>
#include"LinkedList.h"                                              //user defined header file
using namespace std;

class Solution
{
    private:

    LinkedList *p;                                                  //linked list class

    public:

    Solution();
    ~Solution();
    void accept(int);
    int searchFirstOccurrence(int);
};

Solution::Solution()                                                //to allocating the resources
{
    p = new LinkedList();
}

Solution::~Solution()                                               //to deallocating the resources
{
    delete p;
    p = NULL;
}

void Solution::accept(int iSize)                                    //to accept the data from user
{
    int i = 0, iData = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

int Solution::searchFirstOccurrence(int iNo)                         //to search first occurrence
{   
    int iIndex = 0;
    PNODE pTemp = NULL;
    pTemp = p->Head;

    while(pTemp != NULL)
    {
        iIndex++;
        if(pTemp->data == iNo)
        {
            break;                                                  //logic
        }
        pTemp = pTemp->next;
    }

    if(pTemp != NULL)
    {
        return iIndex;
    }
    else
    {
        return -1;
    }
}

int main()                                                          //entry point function
{
    Solution obj;
    int iLength = 0, iNo = 0, iFirstOcc = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);

    cout<<"Enter the number to search first occurrence : "<<endl;
    cin>>iNo;

    iFirstOcc = obj.searchFirstOccurrence(iNo);

    if(iFirstOcc != -1)
    {
        cout<<iNo<<" Occurred at index : "<<iFirstOcc<<endl;
    }
    else
    {
        cout<<iNo<<" Not found !!"<<endl;
    }

    return 0;
}
