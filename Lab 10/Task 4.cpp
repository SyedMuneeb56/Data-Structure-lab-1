#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;
};


void display(Node* head)
{
    
    if (head == NULL)
        return;

   
    cout << head->data << " ";

    
    display(head->next);
}

int main()
{
    
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();

   
    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    
    cout << "Linked List: ";
    display(n1);

    return 0;
}