#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int frontIndex;
    int rearIndex;
    int maxSize;

public:
    myQueue(int size) {
        maxSize = size;
        arr = new T[maxSize];
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isEmpty() const {
        return (rearIndex < frontIndex);
    }

    bool isFull() const {
        return (rearIndex == maxSize - 1);
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        arr[++rearIndex] = value;
        cout << value << " inserted." << endl;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[frontIndex++];
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    myQueue<int> q(size);

    int choice, value;

    
    for (int i = 0; i < 5; i++) {
        cout << " Queue Menu " << endl ;
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
            q.enQueue(value);
            break;

        case 2:
            cout << "Removed: " << q.deQueue() << endl;
            break;

        case 3:
            cout << "Front element: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting." << endl;
            return 0;  

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}