/*
Write a program which accepts input from the user in linked list and display perfect numbers

Input : |11|->|6|->|17|->|28|
Output : 6   28

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
        void displayPerfect();
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

void Solution::displayPerfect()                 //to display perfect numbers
{
    int i = 0, iSum = 0;
    PNODE pTemp = NULL;
    pTemp = p->Head;

    cout<<"Perfect numbers are : "<<endl;
    while(pTemp != NULL)                        //to travel the linked list
    {
        iSum = 0;
        for(i = 1; i <= (pTemp->data / 2); i++)    //to get factors of a number
        {
            if(pTemp->data % i == 0)            
            {                                   
                iSum += i;
            }
        }

        if(iSum == pTemp->data)
        {
            cout<<iSum<<"  ";
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
    obj.displayPerfect();

    return 0;
}