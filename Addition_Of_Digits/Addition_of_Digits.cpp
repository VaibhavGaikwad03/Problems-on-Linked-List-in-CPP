/*
Write a program which accepts input from the user in linked list and display addition of each elements
 
Input Linked List : |110|->|230|->|20|->|240|->|640|
Output : 2  5  2  6  10

*/

#include<iostream>
#include"LinkedList.h"              //custom (userdefined) header file
using namespace std;

class Solution
{
    private:
        LinkedList *p;

    public:

        Solution();
        void accept(int);
        void additionOfDigits();
        
};

Solution::Solution()
{
    p = new LinkedList();               //creating the object of linked list
}

void Solution::accept(int iSize)        //accepts input from the user in linked list 
{   
    int i = 0, data = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>data;
        p->insertLast(data);
    }
}

void Solution::additionOfDigits()       //display additon of digits of each element
{
    int iDigit = 0, iSum = 0;

    PNODE temp = NULL;
    temp = p->Head;

    cout<<"Addition of Digits is : "<<endl;
    while(temp != NULL)                 //to travel the linked list 
    {
        iSum = 0;
        while(temp->data != 0)
        {
            iDigit = temp->data % 10;
            iSum += iDigit;
            temp->data = temp->data / 10;
        }
        temp = temp->next;

        cout<<iSum<<"  ";
    }
    delete []p;                         //deleting the object of linked list 
}

int main()      //starting point of the program
{
    int iLength = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    Solution obj;

    obj.accept(iLength);
    obj.additionOfDigits();

    return 0;
}
