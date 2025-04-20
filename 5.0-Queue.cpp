#include <iostream>
using namespace std;

int const MAX = 100;
int front = -1, rear = -1;
int queue_array[MAX];

void enqueue()
{
    int item;
    if (rear == MAX - 1)
        cout << "Queue Overflow \n";
    else
    {
        if (front == -1)
            front = 0;
        printf("Insret the element in queue : ");
        cin >> item;
        queue_array[++rear] = item;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow \n";
        return;
    }
    else
    {
        cout << "Element deleted from queue is: " << queue_array[front++] << "\n";
    }
}

void display()
{
    if (front == -1 || rear < front)
        cout << "Queue is empty \n";
    else
    {
        cout << "Queue is : \n";
        for (int i = front; i <= rear; i++)
            cout << queue_array[i] << " ";
        cout << "\n";
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
            return 1;
        default:
            cout << "Wrong choice \n";
        }
    }
}
