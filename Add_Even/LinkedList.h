#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
 
class LinkedList
{
    int iCnt;

public:
    PNODE Head;

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
