#include <iostream>
using namespace std;

int const MAX = 3;
int queue_array[MAX];
int rightt = -1;
int leftt = -1;
//front (or left) and rear (or right)

void insert_right()
{
    int item;
    if ((leftt == 0 && rightt == MAX - 1) || (leftt == rightt + 1))
        cout << "Queue Overflow \n";
    else
    {
        //empty queue
        if (leftt == -1)
        {
            leftt = 0;
            rightt = 0;
        }
        else
        {
            if (rightt == MAX - 1)/*rightt is at last position of queue */
                rightt = 0;
            else
                rightt = rightt + 1;
        }

        cout << "Inset the element in queue : ";
        cin >> item;
        queue_array[rightt] = item;
    }
}

void insert_left()
{
    int item;
    if ((leftt == 0 && rightt == MAX - 1) || (leftt == rightt + 1))
        cout << "Queue Overflow \n";
    else
    {
        //empty queue
        if (leftt == -1)
        {
            leftt = 0;
            rightt = 0;
        }
        else
        {
            if (leftt == 0)
                leftt = MAX - 1;
            else
                leftt = leftt - 1;
        }

        printf("Inset the element in queue : ");
        cin >> item;
        queue_array[leftt] = item;
    }
}

void delete_left()
{
    if (leftt == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        cout << "Element deleted from queue is: " << queue_array[leftt] << "\n";
        if (leftt == rightt) /* queue has only one element */
        {
            leftt = -1;
            rightt = -1;
        }
        else
            if (leftt == MAX - 1)
                leftt = 0;
            else
                leftt = leftt + 1;
    }
}

void delete_right()
{
    if (leftt == -1)
    {
        cout << "Queue Underflow \n";
        return;
    }
    else
    {
        cout << "Element deleted from queue is: " << queue_array[rightt] << "\n";
        if (leftt == rightt) /* queue has only one element */
        {
            leftt = -1;
            rightt = -1;
        }
        else
            if (rightt == 0)
                rightt = MAX - 1;
            else
                rightt = rightt - 1;
    }
}

void display()
{
    int i;
    if (leftt == -1)
        cout << "Queue is empty \n";
    else
    {
        cout << "Queue is : \n";
        for (i = leftt; i != rightt; i = (i + 1) % MAX)
            cout << queue_array[i] << " ";

        cout << queue_array[i] << endl;
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout << "1.Insert element to queue right\n";
        cout << "2.Insert element to queue left\n";
        cout << "3.Delete element from queue right\n";
        cout << "4.Delete element from queue left\n";
        cout << "5.Display all elements of queue \n";
        cout << "6.Quit \n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert_right();
            break;
        case 2:
            insert_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            delete_left();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            cout << "Wrong choice \n";
        }
    }
}