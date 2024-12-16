#include <iostream>
using namespace std;

struct node
{
    bool data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;
class dll
{
public:
    node *head;
    node *tail;
    dll();
    ~dll();
    void create();
    void display();
    void ones(dll &o1);
    void insertat(node *newnode);
    void twos(dll &t);
    void add(dll &obj1, dll &obj2);
};

dll::dll()
{
    head = NULL;
    tail = NULL;
}

dll::~dll()
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        node *todel = temp;
        temp = temp->next;
        delete todel;
    }
    cout << "\nDone";
}

void dll::create()
{
    node *newnode;
    int bn;
    cout << "\nenter the number of bits :";
    cin >> bn;
    for (int i = 0; i < bn; i++)
    {
        newnode = new node;
        cout << "enter the data for " << i + 1 << " bit :";
        cin >> newnode->data;
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    cout << "\n";
}

void dll::ones(dll &o1)
{
    node *newnode;
    node *temp;
    temp = tail;
    while (temp != NULL)
    {
        newnode = new node;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (temp->data == 0)
        {
            newnode->data = 1;
        }
        else if (temp->data == 1)
        {
            newnode->data = 0;
        }
        o1.insertat(newnode);
        temp = temp->prev;
    }
    cout << "\n";
}

void dll::insertat(node *newnode)
{
    if (tail == NULL)
    {
        tail = newnode;
        head = tail;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void dll::twos(dll &t)
{
    node *newnode;
    bool c = 0;
    bool s = 0;
    node *temp = tail;
    while (temp != NULL)
    {
        newnode = new node;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (temp == tail)
        {
            if (temp->data == 0)
            {
                s = 1;
                c = 0;
            }
            else if (temp->data == 1)
            {
                s = 0;
                c = 1;
            }
        }
        else
        {
            if (c == 0)
            {
                if (temp->data == 0)
                {
                    s = 0;
                    c = 0;
                }
                else if (temp->data == 1)
                {
                    s = 1;
                    c = 0;
                }
            }
            else if (c == 1)
            {
                if (temp->data == 0)
                {
                    s = 1;
                    c = 0;
                }
                else if (temp->data == 1)
                {
                    s = 0;
                    c = 1;
                }
            }
        }
        newnode->data = s;
        t.insertat(newnode);
        temp = temp->prev;
    }
}

void dll::add(dll &obj1, dll &obj2)
{
    node *newnode;
    node *temp1 = obj1.tail;
    node *temp2 = obj2.tail;
    bool s = 0;
    bool c = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        newnode = new node;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (c == 0)
        {
            if (temp1->data == 0 && temp2->data == 0)
            {
                s = 0;
                c = 0;
            }
            else if (temp1->data == 1 && temp2->data == 1)
            {
                s = 0;
                c = 1;
            }
            else
            {
                s = 1;
                c = 0;
            }
        }
        else if (c == 1)
        {
            if (temp1->data == 0 && temp2->data == 0)
            {
                s = 1;
                c = 0;
            }
            else if (temp1->data == 1 && temp2->data == 1)
            {
                s = 1;
                c = 1;
            }
            else
            {
                s = 0;
                c = 1;
            }
        }
        newnode->data = s;
        insertat(newnode);
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    while (temp1 != NULL)
    {
        newnode = new node;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (c == 0)
        {
            if (temp1->data == 0)
            {
                s = 0;
                c = 0;
            }
            else if (temp1->data == 1)
            {
                s = 1;
                c = 0;
            }
        }
        else if (c == 1)
        {
            if (temp1->data == 0)
            {
                s = 1;
                c = 0;
            }
            else if (temp1->data == 1)
            {
                s = 0;
                c = 1;
            }
        }
        newnode->data = s;
        insertat(newnode);
        temp1 = temp1->prev;
    }
    while (temp2 != NULL)
    {
        newnode = new node;
        newnode->next = NULL;
        newnode->prev = NULL;
        if (c == 0)
        {
            if (temp2->data == 0)
            {
                s = 0;
                c = 0;
            }
            else if (temp2->data == 1)
            {
                s = 1;
                c = 0;
            }
        }
        else if (c == 1)
        {
            if (temp2->data == 0)
            {
                s = 1;
                c = 0;
            }
            else if (temp2->data == 1)
            {
                s = 0;
                c = 1;
            }
        }
        newnode->data = s;
        insertat(newnode);
        temp2 = temp2->prev;
    }
    if (c == 1)
    {
        newnode = new node;
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = 1;
        insertat(newnode);
    }
}

void dll::display()
{
    node *temp;
    if (head == NULL)
    {
        cout << "\nDoubly linked list not created";
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << "\n";
}
int main()
{
    dll obj1;
    dll obj2;
    dll o1;
    dll o2;
    dll t1;
    dll t2;
    dll obj3;
    int ch;
    while (true)
    {
        cout << "\n1-Creating the doubly linked list";
        cout << "\n2-Ones compliment of doubly linked list";
        cout << "\n3-Two's compliment of doubly linked list";
        cout << "\n4-Addition of Two linked list";
        cout << "\n5-Exit";
        cout << "\nenter your choice :";
        cin >> ch;
        if (ch == 1)
        {
            cout << "\nCreatiing 1st dll ";
            obj1.create();
            cout << "\nCreating 2nd dll ";
            obj2.create();
            cout << "\nDisplaying 1st dll " << endl;
            obj1.display();
            cout << "\nDisplaying 2nd dll " << endl;
            obj2.display();
        }
        else if (ch == 2)
        {
            char choice;
            cout << "\n       a-1's compliment of 1st dll";
            cout << "\n       b-1's compliment of 2nd dll";
            cout << "\n       enter your choice :";
            cin >> choice;
            if (choice == 'a')
            {
                cout << "\nOne's compliment of 1st dll ";
                obj1.ones(o1);
                o1.display();
            }
            else if (choice == 'b')
            {
                cout << "\nOne's compliment of 2nd dll ";
                obj2.ones(o2);
                o2.display();
            }
        }
        else if (ch == 3)
        {
            char choice;
            cout << "\n       a-2's compliment of 1st dll";
            cout << "\n       b-2's compliment of 2nd dll";
            cout << "\n       enter your choice :";
            cin >> choice;
            if (choice == 'a')
            {
                cout << "\nTwo's compliment of 1st dll " << endl;
                o1.twos(t1);
                t1.display();
            }
            else if (choice == 'b')
            {
                cout << "\nTwo's compliment of 2nd dll " << endl;
                o2.twos(t2);
                t2.display();
            }
        }
        else if (ch == 4)
        {
            cout << "\nSum of bits of two dll" << endl;
            obj3.add(obj1, obj2);
            obj3.display();
        }
        else if (ch == 5)
        {
            cout << "\nEnd of the program!!";
            break;
        }
        else
        {
            cout << "\nInvalid choice";
        }
    }
}


// O/P :


// 1-Creating the doubly linked list
// 2-Ones compliment of doubly linked list
// 3-Two's compliment of doubly linked list
// 4-Addition of Two linked list
// 5-Exit
// enter your choice :1

// Creatiing 1st dll 
// enter the number of bits :4
// enter the data for 1 bit :1
// enter the data for 2 bit :0
// enter the data for 3 bit :0
// enter the data for 4 bit :1


// Creating 2nd dll 
// enter the number of bits :4
// enter the data for 1 bit :1
// enter the data for 2 bit :0
// enter the data for 3 bit :1
// enter the data for 4 bit :0


// Displaying 1st dll 
// 1 0 0 1 

// Displaying 2nd dll 
// 1 0 1 0 

// 1-Creating the doubly linked list
// 2-Ones compliment of doubly linked list
// 3-Two's compliment of doubly linked list
// 4-Addition of Two linked list
// 5-Exit
// enter your choice :2

//        a-1's compliment of 1st dll
//        b-1's compliment of 2nd dll
//        enter your choice :a

// One's compliment of 1st dll 
// 0 1 1 0 

// 1-Creating the doubly linked list
// 2-Ones compliment of doubly linked list
// 3-Two's compliment of doubly linked list
// 4-Addition of Two linked list
// 5-Exit
// enter your choice :3

//        a-2's compliment of 1st dll
//        b-2's compliment of 2nd dll
//        enter your choice :a

// Two's compliment of 1st dll 
// 0 1 1 1 

// 1-Creating the doubly linked list
// 2-Ones compliment of doubly linked list
// 3-Two's compliment of doubly linked list
// 4-Addition of Two linked list
// 5-Exit
// enter your choice :4

// Sum of bits of two dll
// 1 0 0 1 1 

// 1-Creating the doubly linked list
// 2-Ones compliment of doubly linked list
// 3-Two's compliment of doubly linked list
// 4-Addition of Two linked list
// 5-Exit
// enter your choice :5

// End of the program!!
// Done
// Done
// Done
// Done
// Done
// Done
// Done

// === Code Execution Successful ===