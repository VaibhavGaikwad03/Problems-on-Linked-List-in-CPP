/*

Write a program which accepts input from user in linked list and display palindrome numbers.

Input Linked List : |11|->|28|->|17|->|414|->|6|->|89|
Output : 11     6      414

*/

#include<iostream>
#include"LinkedList.h"                      //user defined header file
using namespace std;

class Solution
{
    private:
        LinkedList *p;

    public:
        Solution();
        void accept(int);
        void displayPalindrome();
};

Solution::Solution()
{
    p = new LinkedList();                   //creating object of linked list
}

void Solution::accept(int iSize)            //accepts data from user the in linked list 
{
    int i = 0, iData = 0;
    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

void Solution::displayPalindrome()         //to display pallindrome numbers
{
    int iRev = 0, iTemp = 0, iDigit = 0;
    PNODE temp = p->Head;

    cout<<"Palindrome numbers are : "<<endl;
    while(temp != NULL)
    {
        iRev = 0;
        iTemp = temp->data;

        while(temp->data != 0)
        {
            iDigit = temp->data % 10;
            iRev = (iRev * 10) + iDigit;            //logic
            temp->data = temp->data / 10;
        }

        if(iTemp == iRev)
        {
            cout<<iRev<<"  ";
        }
        temp = temp->next;
    }
}

int main()                              //entry point function
{
    Solution obj;
    int iLength = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);
    obj.displayPalindrome();
}