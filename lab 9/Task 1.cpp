#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node* head;

public:
    
    DoublyLinkedList() {
        head = nullptr;
    }

   
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    
    void insertAtStart(int value) {
        Node* newNode = new Node(value);

        
        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    
    void insertAtPosition(int value, int position) {
      
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

      
        if (position == 1) {
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        int count = 1;

        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }

        
        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        
        if (temp->next == nullptr) {
            temp->next = newNode;
            newNode->prev = temp;
        }
        else {
            newNode->next = temp->next;
            newNode->prev = temp;

            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    
    void deleteByValue(int value) {
        
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

     
        if (temp == nullptr) {
            cout << "Value not found!" << endl;
            return;
        }

        
        if (temp == head) {
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward Traversal: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    
    void displayReverse() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "Reverse Traversal: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};


int main() {
    DoublyLinkedList dll;

  
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);

    cout << "List after inserting at end:" << endl;
    dll.displayForward();

    
    dll.insertAtStart(5);

    cout << "List after inserting at start:" << endl;
    dll.displayForward();

   
    dll.insertAtPosition(15, 3);

    cout << "List after inserting 15 at position 3:" << endl;
    dll.displayForward();

    
    cout << "Displaying list in forward direction:" << endl;
    dll.displayForward();

    
    cout << "Displaying list in reverse direction:" << endl;
    dll.displayReverse();

    
    dll.deleteByValue(5);

    cout << "List after deleting 5 (first node):" << endl;
    dll.displayForward();

    dll.deleteByValue(30);

    cout << "List after deleting 30 (last node):" << endl;
    dll.displayForward();

    dll.deleteByValue(15);

    cout << "List after deleting 15:" << endl;
    dll.displayForward();

    
    cout << "Reverse traversal after deletions:" << endl;
    dll.displayReverse();

    return 0;
}