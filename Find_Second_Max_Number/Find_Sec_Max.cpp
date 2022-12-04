/*

Write a program which accepts input from the user in linked list and return second max number.

Input Linked List : |110|->|230|->|320|->|240|

Output : 240

*/

#include<iostream>
#include"LinkedList.h"                          //user defined header file

class Solution
{
    private:
    
    LinkedList *p;                              //linked list class

    public:

    Solution();
    ~Solution();
    void accept(int);
    int findSecMax();
};

Solution::Solution()                            //to allocating the resources
{
    p = new LinkedList;
}

Solution::~Solution()                           //to deallocating the resources
{
    delete p;
    p = NULL;
}

void Solution::accept(int iSize)                //to accept the data from the user (User interaction)
{
    int i = 0, iData = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

int Solution::findSecMax()                      //to find the second maximum number
{
    int iMax = p->Head->data, iSecMax = p->Head->data;
    PNODE pTemp = p->Head;

    while(pTemp != NULL)
    {
        if(iMax < pTemp->data)
        {
            iSecMax = iMax;
            iMax = pTemp->data;
        }
        else if(iMax > pTemp->data && iSecMax < pTemp->data)
        {
            iSecMax = pTemp-> data;
        }
        pTemp = pTemp->next;
    }
    return iSecMax;
}

int main()                                          //entry point function
{
    Solution obj;

    int iLength = 0, iRet = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);
    iRet = obj.findSecMax();

    cout<<"Second max number is : "<<iRet<<endl;

    return 0;
}