

#include <iostream>
using namespace std;

#define SIZE 5

class dequeue {
    int a[SIZE];
    int front, rear, count;

public:
    dequeue();
    void add_at_beg(int);
    void add_at_end(int);
    void delete_fr_front();
    void delete_fr_rear();
    void display();
};

dequeue::dequeue() {
    front = -1;
    rear = -1;
    count = 0;
}

void dequeue::add_at_beg(int item) {
    if (count == SIZE) {
        cout << "\nInsertion is not possible, overflow!!!";
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else {
        front = (front - 1 + SIZE) % SIZE;
    }
    a[front] = item;
    count++;
}

void dequeue::add_at_end(int item) {
    if (count == SIZE) {
        cout << "\nInsertion is not possible, overflow!!!";
        return;
    }
    if (rear == -1) { // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    a[rear] = item;
    count++;
}

void dequeue::delete_fr_front() {
    if (count == 0) {
        cout << "\nDeletion is not possible: Dequeue is empty";
        return;
    }
    cout << "\nThe deleted element is " << a[front];
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    count--;
}

void dequeue::delete_fr_rear() {
    if (count == 0) {
        cout << "\nDeletion is not possible: Dequeue is empty";
        return;
    }
    cout << "\nThe deleted element is " << a[rear];
    if (front == rear) { // Only one element
        front = rear = -1;
    } else {
        rear = (rear - 1 + SIZE) % SIZE;
    }
    count--;
}

void dequeue::display() {
    if (count == 0) {
        cout << "\nDequeue is empty";
        return;
    }
    cout << "\nDequeue elements are: ";
    for (int i = 0; i < count; i++) {
        cout << a[(front + i) % SIZE] << " ";
    }
}

int main() {
    int c, item;
    dequeue d1;

    do {
        cout << "\n\n****DEQUEUE OPERATION****\n";
        cout << "\n1 - Insert at beginning";
        cout << "\n2 - Insert at end";
        cout << "\n3 - Display";
        cout << "\n4 - Deletion from front";
        cout << "\n5 - Deletion from rear";
        cout << "\n6 - Exit";
        cout << "\nEnter your choice <1-6>: ";
        cin >> c;

        switch (c) {
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.add_at_beg(item);
                break;
            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> item;
                d1.add_at_end(item);
                break;
            case 3:
                d1.display();
                break;
            case 4:
                d1.delete_fr_front();
                break;
            case 5:
                d1.delete_fr_rear();
                break;
            case 6:
                cout << "Exiting program.";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (c != 6);

    return 0;
}




// O/P

// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 1
// Enter the element to be inserted: 11


// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 1
// Enter the element to be inserted: 12


// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 1
// Enter the element to be inserted: 13


// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 1
// Enter the element to be inserted: 14


// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 2
// Enter the element to be inserted: 15


// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 3

// Dequeue elements are: 14 13 12 11 15 

// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 4

// The deleted element is 14

// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 3

// Dequeue elements are: 13 12 11 15 

// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 5

// The deleted element is 15

// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 3

// Dequeue elements are: 13 12 11 

// ****DEQUEUE OPERATION****

// 1 - Insert at beginning
// 2 - Insert at end
// 3 - Display
// 4 - Deletion from front
// 5 - Deletion from rear
// 6 - Exit
// Enter your choice <1-6>: 6
// Exiting program.%                                                                          
// (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % 
