/*
 
Write a program which accepts input from the user in linked list and display prime numbers

Input : |11|->|20|->|17|->|41|->|22|->|89|
Output : 11     17      41      89

*/

#include<iostream>
#include"LinkedList.h"                          //user defined header file
using namespace std;

class Solution
{
    private:
        LinkedList *p;                          //linked list class from "LinkedList.h" header file
    public:
        Solution();
        void accept(int);
        void displayPrime();
};

Solution::Solution()
{
    p = new LinkedList();                        //creating object of a linked list
}

void Solution::accept(int iSize)                //accepts data from the user in linked list
{
    int i = 0, iData = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>iData;
        p->insertLast(iData);
    }
}

void Solution::displayPrime()                 //to display prime numbers
{
    int i = 0;
    PNODE pTemp = NULL;
    pTemp = p->Head;

    cout<<"Prime numbers are : "<<endl;

    while(pTemp != NULL)
    {
        for(i = 2; i < pTemp->data; i++)
        {
            if(pTemp->data % i == 0)
            {
                break;
            }
        }

        if(i == pTemp->data)
        {
            cout<<pTemp->data<<"  ";
        }
        pTemp = pTemp->next;
    }
    
}

int main()                                              //entry point function
{
    Solution obj;
    int iLength = 0;
    cout<<"Enter the number of elements : "<<endl;         //accepting size of a linked list from user
    cin>>iLength;

    obj.accept(iLength);
    obj.displayPrime();

    return 0;
}
