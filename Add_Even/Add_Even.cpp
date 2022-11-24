/*

Write a program which accepts input from user in Linked List and return addition of Even numbers.

Input Linked List : |11|->|20|->|32|->|41|->|59|
Output : 52
 
*/

#include<iostream>
#include"LinkedList.h"      //custom header file (Linked List)

using namespace std;

class Solution
{
    private:

    LinkedList *p;

    public:

    Solution();
    void accept(int);
    int addEven();

};

Solution::Solution()
{
    p = new LinkedList();
}

void Solution::accept(int iSize)     //accepts input from user
{
    int i = 0, data = 0;

    cout<<"Enter the data : "<<endl;

    for(i = 1; i <= iSize; i++)
    {
        cin>>data;
        p->insertLast(data);
    }
}

int Solution::addEven()     //to add even numbers from linked list (Logic)
{
    PNODE temp = NULL;
    int iSum = 0;

    temp = p->Head;

    while(temp != NULL)
    {   
        if(temp->data % 2 == 0)
        {
            iSum += temp->data;
        }
        temp = temp->next;
    }

    return iSum;
}

int main()                  //starting point of a program
{
    int iLength = 0;
    int iRet = 0;

    cout<<"Enter the number of elements : "<<endl;
    cin>>iLength;

    Solution obj;
    
    obj.accept(iLength);
    iRet = obj.addEven();

    cout<<"Addition of Even numbers is : "<<iRet<<endl;

    return 0;
}
