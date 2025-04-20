#include <iostream>
using namespace std;
//Structure is created as node
struct node
{
    int data;
    node* next;//A next to the next node
}*top;

void push()
{
    node* temp = new node();

    temp->next = NULL;

    cout << "\nInput the new value to be pushed on the stack:";
    cin >> temp->data;

    if (top == NULL)
        top = temp;
    else {
        temp->next = top;
        top = temp;
    }
}

//Following function will implement the pop operation
void pop()
{
    if (top == NULL)
        cout << "stack is empty\n";
    else {
        cout << "poped item has value " << top->data;
        top = top->next;
    }
}
//This is to display the entire element in the stack
void display()
{
    if (top == NULL)
        cout << "\nStack is empty\n";
    else {
        cout << "\nStack elements:\n";
        node* temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }/*End of while */
    }
}

int main() {

    char opt;
    int choice;
    do
    {
        cout << "\n1.PUSH\n";
        cout << "2.POP\n";
        cout << "3.DISPLAY\n";
        cout << "4.EXIT\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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