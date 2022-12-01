/*

Write a program which accepts input from the user in linked list and return maximum number.

Input : |110|->|230|->|320|->|240|
Output : 320

*/
 
#include<iostream>
#include"LinkedList.h"                  //user defined header file
using namespace std;

class Solution
{
    private:
    
    LinkedList *p;

    public:

    Solution();
    ~Solution();
    void accept(int);
    int findMax();
};

Solution::Solution()                            //to allocating the resources
{
    p = new LinkedList();
}

Solution::~Solution()                           //to deallocating the resources
{
    delete []p;
    p = NULL;
}

void Solution::accept(int iSize)                //to accept input from the user
{
    int i = 0, iData = 0;

    cout<<"Enter the data : "<<endl;
    for(i  = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

int Solution::findMax()                         //to find the maximum number
{
    int iMax = p->Head->data;
    PNODE pTemp = NULL;
    pTemp = p->Head;

    while(pTemp != NULL)
    {
        if(iMax < pTemp->data)                  //logic
        {
            iMax = pTemp->data;
        }
        pTemp = pTemp->next;
    }
    return iMax;
}

int main()                                      //entry point function
{
    Solution obj;
    int iLength = 0, iRet = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);
    iRet = obj.findMax();

    cout<<"Maximum number from linked list is : "<<iRet<<endl;

    return 0;
}
