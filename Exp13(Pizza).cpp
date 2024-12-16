#include<iostream>
#define MAX 5
using namespace std;

class PizzaParlour{
    private:
    int order[MAX];
    int front, rear;

    public:
    PizzaParlour(){
        front = -1;
        rear = -1;
    }
    bool isFull(){
        return (rear + 1) % MAX;
    }
    bool isEmpty(){
        return(front == -1);
    }

    void placeOrder(int orderID){
        if(isFull()){
            cout<<"Parlour is at full capacity, can't place any order"<<endl;
            return;
        }
        if(front == -1){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % MAX;
        }
        order[rear] = orderID;
        cout<<"Order "<<orderID<<" has been placed successfully!!!"<<endl;
    }

    void serveOrder(){
        if(isEmpty()){
            cout<<"No order is there!!!"<<endl;
            return;
        }
        cout<<"Serving Order "<<order[front]<<endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % MAX;
        }
    }

    void displayOrder(){
        if(isEmpty()){
            cout<<"No order to display"<<endl;
            return;
        }

        int i = front;
        cout<<"Current order in the display"<<endl;
        while(true){
            cout<<order[i]<<" ";
            if(i == rear) break;
            i = (i + 1) % MAX;
        }
        cout<<endl;
    }
};

int main(){
    PizzaParlour parlour;
    int choice, orderID;

    do{
        cout<<"___MENU___"<<endl;
        cout<<"1. Place order"<<endl;
        cout<<"2. Serve order"<<endl;
        cout<<"3. Display order"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter order ID: ";
            cin>>orderID;
            parlour.placeOrder(orderID);
            break;

            case 2:
            parlour.serveOrder();
            break;

            case 3:
            parlour.displayOrder();
            break;

            case 4:
            cout<<"Exiting..."<<endl;
            break;

            default:
            cout<<"Invalid Choice";
        }
    } while(choice != 4);

    return 0;
}




// (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % cd "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FDS/" && g++ Exp13.cp
// p -o Exp13 && "/Users/trushantramdasjadhav/Desktop/TicketingSystem/FDS/"Exp13
// ___MENU___
// 1. Place order
// 2. Serve order
// 3. Display order
// 4. Exit
// Enter your choice: 1
// Enter order ID: 123
// Order 123 has been placed successfully!!!
// ___MENU___
// 1. Place order
// 2. Serve order
// 3. Display order
// 4. Exit
// Enter your choice: 3
// Current order in the display
// 123 
// ___MENU___
// 1. Place order
// 2. Serve order
// 3. Display order
// 4. Exit
// Enter your choice: 2
// Serving Order 123
// ___MENU___
// 1. Place order
// 2. Serve order
// 3. Display order
// 4. Exit
// Enter your choice: 3
// No order to display
// ___MENU___
// 1. Place order
// 2. Serve order
// 3. Display order
// 4. Exit
// Enter your choice: 4
// Exiting...
// (base) trushantramdasjadhav@Trushants-MacBook-Air FDS % 