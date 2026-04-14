#include <iostream>
using namespace std;

class QueueUsingStacks {
private:
    int stack1[100], stack2[100];
    int top1, top2;
    int size;

public:
  
    QueueUsingStacks(int s) {
        size = s;
        top1 = -1;
        top2 = -1;
    }

    
    bool isFull() {
        return (top1 == size - 1);
    }

    
    bool isEmpty() {
        return (top1 == -1 && top2 == -1);
    }

    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        stack1[++top1] = value;
        cout << value << " inserted." << endl;
    }

    
    void transfer() {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (top2 == -1) {
            transfer();
        }

        return stack2[top2--];
    }

    
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        if (top2 == -1) {
            transfer();
        }

        return stack2[top2];
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        
        if (top2 == -1) {
            transfer();
        }

        cout << "Queue elements: ";
        for (int i = top2; i >= 0; i--) {
            cout << stack2[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    QueueUsingStacks q(size);

    int choice, value;

    for (int i = 0; i < 5 ; i++) {
        cout << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            cout << "Removed: " << q.dequeue() << endl;
            break;

        case 3:
            cout << "Front element: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}