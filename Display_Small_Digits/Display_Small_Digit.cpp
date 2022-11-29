/*

Write a program which accepts input from the user in Linked List and display small digits

Input : |11|->|250|->|532|->|415|
Output : 1  0  2  1

*/

#include<iostream>
#include"LinkedList.h"                          //user defined header file
using namespace std;

class Solution 
{
    private:

    LinkedList *p;

    public:
    
    Solution();
    ~Solution();
    void accept(int);
    void displaySmallDigits();
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

    for(i = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

void Solution::displaySmallDigits()             //to display small digits
{
    int iDigit = 0, iMin = 0;
    PNODE temp = NULL;
    temp = p->Head;

    cout<<"Small digits are : "<<endl;

    while(temp != NULL)
    {
        iMin = 10;

        while(temp->data != 0)
        {
            iDigit = temp->data % 10;           
            if(iDigit < iMin)                   //logic
            {
                iMin = iDigit;
            }
            temp->data = temp->data / 10;
        }

        cout<<iMin<<"  ";
        temp = temp->next;
    }
}

int main()                                      //entry point function
{

    Solution obj;
    int iLength = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);
    obj.displaySmallDigits();

    return 0;
}