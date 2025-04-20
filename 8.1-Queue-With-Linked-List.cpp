#include <iostream>
using namespace std;
//Structure is created as a node
struct node
{
    int data;
    node* next;//A link to the next node
}*front, * rear;

void enqueue()
{
    node* temp = new node();

    temp->next = NULL;

    cout << "\nInput the new value to be added on the queue:";
    cin >> temp->data;

    if (rear == NULL || front == NULL)
        rear = front = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
}

//Following function will implement the pop operation
void dequeue()
{
    if (front == NULL)
        cout << "queue is empty\n";
    else {
        cout << "deleted item has value " << front->data;
        front = front->next;
    }
}
//This is to display the entire element in the stack
void display()
{
    if (front == NULL)
        cout << "\nQueue is empty\n";
    else {
        cout << "\nQueue elements:\n";
        node* temp = front;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main() {

    char opt;
    int choice;
    do
    {
        cout << "\n1.Enqueue\n";
        cout << "2.Dequeue\n";
        cout << "3.DISPLAY\n";
        cout << "4.EXIT\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            cout << "\nWrong choice\n";
        }

        cout << "\n\nDo you want to continue (Y/y) = ";
        cin >> opt;
    } while ((opt == 'Y') || (opt == 'y'));

    return 0;
}