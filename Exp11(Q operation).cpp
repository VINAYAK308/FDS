


#include <iostream>
#define MAX 10
using namespace std;

struct queue {
    int data[MAX];
    int front, rear;
};

class Queue {
    struct queue q;

public:
    Queue() { q.front = q.rear = -1; }

    int isempty();
    int isfull();
    void enqueue(int);
    int delqueue();
    void display();
};

int Queue::isempty() {
    return (q.front == -1 && q.rear == -1); // Properly checks if the queue is empty
}

int Queue::isfull() {
    return (q.rear == MAX - 1); // Checks if the queue is full
}

void Queue::enqueue(int x) {
    if (isempty()) {
        // If the queue is initially empty, reset both pointers
        q.front = q.rear = 0;
    } else {
        q.rear++; // Increment the rear pointer for normal cases
    }
    q.data[q.rear] = x; // Insert the new element
}

int Queue::delqueue() {
    if (isempty()) {
        throw runtime_error("Queue Underflow"); // Throw an error for invalid dequeue
    }
    int x = q.data[q.front]; // Retrieve the element to be deleted
    if (q.front == q.rear) {
        // If deleting the last element, reset the queue
        q.front = q.rear = -1;
    } else {
        q.front++; // Move the front pointer forward
    }
    return x;
}

void Queue::display() {
    if (isempty()) {
        cout << "\nQueue is empty";
        return;
    }
    cout << "\nQueue contains: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

int main() {
    Queue obj;
    int ch, x;
    do {
        cout << "\n1. Insert job\n2. Delete job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
        case 1:
            if (!obj.isfull()) {
                cout << "\nEnter data: ";
                cin >> x;
                obj.enqueue(x);
            } else {
                cout << "Queue is full";
            }
            break;

        case 2:
            if (!obj.isempty()) {
                cout << "\nDeleted Element = " << obj.delqueue();
            } else {
                cout << "\nQueue is underflow";
            }
            cout << "\nRemaining jobs: ";
            obj.display();
            break;

        case 3:
            obj.display();
            break;

        case 4:
            cout << "\nExit";
            break;

        default:
            cout << "\nInvalid choice!";
        }
    } while (ch != 4);
    return 0;
}



// (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % cd "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FDS/" && g++ Exp11.c
// pp -o Exp11 && "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FDS/"Exp11

// 1. Insert job
// 2. Delete job
// 3. Display
// 4. Exit
// Enter your choice: 1

// Enter data: 20

// 1. Insert job
// 2. Delete job
// 3. Display
// 4. Exit
// Enter your choice: 1

// Enter data: 21

// 1. Insert job
// 2. Delete job
// 3. Display
// 4. Exit
// Enter your choice: 1 

// Enter data: 22

// 1. Insert job
// 2. Delete job
// 3. Display
// 4. Exit
// Enter your choice: 3

// Queue contains: 20 21 22 

// 1. Insert job
// 2. Delete job
// 3. Display
// 4. Exit
// Enter your choice: 2

// Deleted Element = 20
// Remaining jobs: 
// Queue contains: 21 22 

// 1. Insert job
// 2. Delete job
// 3. Display
// 4. Exit
// Enter your choice: 4

// Exit%                                                                                                                               
// (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % 