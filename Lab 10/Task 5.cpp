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
    {
        cout << "NULL" << endl;
        return;
    }

    cout << head->data << " -> ";
    display(head->next);
}


Node* insertBeginning(Node* head, int value)
{
    Node* temp = new Node();
    temp->data = value;
    temp->next = head;

    return temp;
}


Node* insertEnd(Node* head, int value)
{
    
    if (head == NULL)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;
        return temp;
    }

    
    head->next = insertEnd(head->next, value);

    return head;
}


Node* insertPosition(Node* head, int value, int pos)
{
    
    if (pos == 1)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->next = head;
        return temp;
    }

    
    if (head == NULL)
        return head;

    
    head->next = insertPosition(head->next, value, pos - 1);

    return head;
}


Node* deleteValue(Node* head, int value)
{
    if (head == NULL)
        return NULL;

    
    if (head->data == value)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }


    head->next = deleteValue(head->next, value);

    return head;
}


Node* deletePosition(Node* head, int pos)
{
    if (head == NULL)
        return NULL;

    
    if (pos == 1)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }

    
    head->next = deletePosition(head->next, pos - 1);

    return head;
}


int search(Node* head, int value, int pos = 1)
{
   
    if (head == NULL)
        return -1;

   
    if (head->data == value)
        return pos;

    
    return search(head->next, value, pos + 1);
}

int main()
{
    Node* head = NULL;

    
    head = insertBeginning(head, 10);
    cout << "After Insert Beginning: ";
    display(head);

    
    head = insertEnd(head, 20);
    cout << "After Insert End: ";
    display(head);

    
    head = insertPosition(head, 15, 2);
    cout << "After Insert Position: ";
    display(head);

    
    head = deleteValue(head, 20);
    cout << "After Delete Value: ";
    display(head);

    
    head = deletePosition(head, 1);
    cout << "After Delete Position: ";
    display(head);

    
    int result = search(head, 15);

    if (result == -1)
        cout << "Value not found";
    else
        cout << "Value found at position: " << result;

    return 0;
}