#include <iostream>
using namespace std;


class stack {
private:
    int top;
    int maxSize;
    int* stackArr;

public:

    stack(int maxSize) {
        top = -1;
        stackArr = new int[maxSize];
    }
    ~stack() {
        delete[]stackArr;
    }

    void push()
    {
        if (top == maxSize - 1) {
            maxSize++;
            int* nw = new int[maxSize];
            //cout << "stack is full";
            for (int i = 0; i < maxSize - 1; i++) {
                nw[i] = stackArr[i];
            }

            delete[]stackArr;
            stackArr = nw;
            nw = NULL;
            int item;
            cout << "enter the value to be inserted: ";
            cin >> item;
            stackArr[++top] = item;
        }
        else {
            int item;
            cout << "enter the value to be inserted: ";
            cin >> item;
            stackArr[++top] = item;
        }

    }

    void pop()
    {
        if (top == -1)
            cout << "stack is empty";
        else
            cout << "value poped is: " << stackArr[top--];
    }

    void traverse()
    {
        if (top == -1)
            cout << "stack is empty";
        else {
            cout << "elements in stack are \n";
            for (int i = top; i >= 0; --i)
                cout << stackArr[i] << endl;
        }

    }
};
int main() {
    int choice;
    char ch;
    stack st(1);
    do {
        cout << "\n1. PUSH";
        cout << "\n2. POP";
        cout << "\n3. TRAVERSE";
        cout << "\nEnter Your Choice = ";
        cin >> choice;

        switch (choice)
        {
        case 1://Calling push() function by class object
            st.push();
            break;
        case 2://calling pop() function
            st.pop();
            break;
        case 3:
            st.traverse();
            break;
        default:
            cout << "you entered wrong choice";
        }

        cout << "\n\nPress (Y/y) To Continue = ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}