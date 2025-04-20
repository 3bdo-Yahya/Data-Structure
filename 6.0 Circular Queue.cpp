#include <iostream>
using namespace std;
int const MAX = 3;


int queue_array[MAX];
int rear = -1;
int front = -1;


void enqueue()
{
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        cout << "Queue Overflow \n";
    else
    {
        //empty queue
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            if (rear == MAX - 1)/*rear is at last position of queue */
                rear = 0;
            else
                rear = rear + 1;
        }

        cout << "Inset the element in queue : ";
        cin >> item;
        queue_array[rear] = item;
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow \n";
        return;
    }
    else
    {
        cout << "Element deleted from queue is: " << queue_array[front] << endl;
        if (front == rear) /* queue has only one element */
        {
            front = -1;
            rear = -1;
        }
        else
            if (front == MAX - 1)
                front = 0;
            else
                front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue is : \n";
        for (i = front; i != rear; i = (i + 1) % MAX)
            cout << queue_array[i] << " ";

        cout << queue_array[i] << endl;
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout << "1.Insert element to queue \n";
        cout << "2.Delete element from queue \n";
        cout << "3.Display all elements of queue \n";
        cout << "4.Quit \n";
        cout << "Enter your choice : ";
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
            cout << "Wrong choice \n";
        }
    }
}

