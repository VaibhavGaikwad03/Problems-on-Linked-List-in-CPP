/*

Write a program which accepts input from the user in linked list and display multiplication of each digit 

Input linked list : |11|->|20|->|32|->|41|
Output : 1  0  6  4

*/

#include<iostream>
#include"LinkedList.h"              //userdefined header file
using namespace std;

class Solution
{
    private:
        LinkedList *p;
    
    public:
        Solution();
        void accept(int);
        void multiplicationOfDigits();

};

Solution::Solution()
{
    p = new LinkedList();               //creating an object of linked list
}

void Solution::accept(int iSize)        //accepts data into the linked list
{
    int i = 0, data = 0;
    cout<<"Enter the data : "<<endl;

    for(i  = 1; i <= iSize; i++)
    {
        cin>>data;
        p->insertLast(data);
    }
}

void Solution::multiplicationOfDigits()     //to perform multiplication of digits
{
    PNODE temp = NULL;                      //creating temporary pointer for travelling the linked list
    int iDigit = 0, iMult = 1;
    temp = p->Head;

    cout<<"Multiplication of digits : "<<endl;
    while(temp != NULL)                     
    {
        iMult = 1;
        while(temp->data != 0)              
        {
            iDigit = temp->data % 10;          //logic
            iMult *= iDigit;
            temp->data = temp->data / 10;
        }
        cout<<iMult<<"  ";
        temp = temp->next;
    }
}

int main()                              //entry point funtion
{
    int iLength = 0, iRet = 0;
    Solution obj;


    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    obj.accept(iLength);
    obj.multiplicationOfDigits();

    return 0;
}