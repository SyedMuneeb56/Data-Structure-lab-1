#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};


void printForward(Node* head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    cout << head->data << " ";
    printForward(head->next);
}


void printReverse(Node* tail)
{
    if (tail == NULL)
    {
        cout << endl;
        return;
    }

    cout << tail->data << " ";
    printReverse(tail->prev);
}


Node* insertBeginning(Node* head, int value)
{
    Node* temp = new Node();
    temp->data = value;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;

    return temp;
}


Node* insertEnd(Node* head, int value)
{
    if (head == NULL)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }

    if (head->next == NULL)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;
        temp->prev = head;
        head->next = temp;
        return head;
    }

    insertEnd(head->next, value);

    return head;
}


Node* insertPosition(Node* head, int value, int pos)
{
    if (pos == 1)
        return insertBeginning(head, value);

    if (head == NULL)
        return head;

    if (pos == 2)
    {
        Node* temp = new Node();
        temp->data = value;

        temp->next = head->next;
        temp->prev = head;

        if (head->next != NULL)
            head->next->prev = temp;

        head->next = temp;

        return head;
    }

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

        if (temp != NULL)
            temp->prev = NULL;

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

        if (temp != NULL)
            temp->prev = NULL;

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


Node* getTail(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    return getTail(head->next);
}


bool palindrome(Node* left, Node* right)
{
    if (left == NULL || right == NULL)
        return true;

    if (left == right || left->prev == right)
        return true;

    if (left->data != right->data)
        return false;

    return palindrome(left->next, right->prev);
}

int main()
{
    Node* head = NULL;

    
    head = insertBeginning(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 10);

    cout << "Forward: ";
    printForward(head);

    
    Node* tail = getTail(head);

    cout << "Reverse: ";
    printReverse(tail);

   
    head = insertPosition(head, 15, 2);

    cout << "After Insert Position: ";
    printForward(head);

    head = deleteValue(head, 20);

    cout << "After Delete Value: ";
    printForward(head);

    
    int pos = search(head, 15);

    cout << "Position of 15: " << pos << endl;

    
    tail = getTail(head);

    if (palindrome(head, tail))
        cout << "Palindrome List";
    else
        cout << "Not Palindrome";

    return 0;
}