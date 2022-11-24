#include<iostream>
using namespace std;

struct node 
{ 
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class LinkedList 
{
    public:
        PNODE Head;
        int iCnt;
    
        LinkedList();
        int countNode();
        void display();
        void insertFirst(int);
        void insertLast(int);
        void insertAtPos(int, int);
        void deleteFirst();
        void deleteLast();
        void deleteAtPos(int);

};

LinkedList::LinkedList()
{
    Head = NULL;
    iCnt = 0;
}

int LinkedList::countNode()
{
    return iCnt;
}

void LinkedList::display()
{
    PNODE temp = NULL;
    temp = Head;
    cout<<"Data from the Linked List : \n";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void LinkedList::insertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    iCnt++;
}

void LinkedList::insertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        PNODE temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCnt++;
}

void LinkedList::insertAtPos(int iNo, int iPos)
{
    int size = countNode();

    if((iPos < 1) || (iPos > size+1))
    {
        cout<<"Invalid Position !!\n";
        return;
    }

    if(iPos == 1)
    {
        insertFirst(iNo);
    }
    else if(iPos == size + 1)
    {
        insertLast(iNo);
    }
    else
    {
        PNODE newn = NULL;
        newn = new NODE;
        PNODE temp = NULL;
        temp = Head;

        newn->data = iNo;
        newn->next = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }   
        newn->next = temp->next;
        temp->next = newn;
        
        iCnt++;
    }
}

void LinkedList::deleteFirst()
{

    if(Head == NULL)
    {
        cout<<"Linked List is empty !!\n";
        return;
    }
    PNODE temp = NULL;
    temp = Head;

    Head = Head->next;
    delete temp;

    iCnt--;
}

void LinkedList::deleteLast()
{
    if(Head == NULL)
    {
        cout<<"Linked List is empty !!\n";
        return;
    }

    PNODE temp = NULL;
    temp = Head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    iCnt--;
}

void LinkedList::deleteAtPos(int iPos)
{
    int size = countNode();

    if((iPos < 1) || (iPos > size))
    {
        cout<<"Invalid Position !!\n";
        return;
    }
    
    if(iPos == 1)
    {
        deleteFirst();
    }
    else if(iPos == size)
    {
        deleteLast();
    }
    else
    {
        PNODE temp = NULL;
        PNODE tempdelete = NULL;
        temp = Head;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        iCnt--;
    }
}
