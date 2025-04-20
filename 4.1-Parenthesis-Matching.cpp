#include <iostream>
#include <cstring> // for strlen
using namespace std;

int top = -1;
const int maxSize = 1000;
char stack [maxSize];

void push(char element)
{
    if (top == maxSize - 1) {
        printf("stack is full \n");
        return;
    }

    stack[++top] = element;
}

char pop()
{
    if (top == -1) {
        printf("stack is empty \n");
        return 0;
    }

    return stack[top--];
}

void isBalanced(char expr[]) {

    int len = strlen(expr);
    for (int index = 0; index < len; index++) {

        if (expr[index] == '(') {
            push(expr[index]);
        }

        else if (expr[index] == ')') {
            if (top == -1) {
                cout << "Unbalanced Expression" << endl;
                return;
            }
            pop(); 
        }
    }

    if (top == -1)
    {
        cout << "Balanced Expression" << endl;
    }
    else {
        cout << "Unbalanced Expression" << endl;
    }
}

int main() {
    char expr[maxSize];
    cout << "Enter a parenthesis expression: ";
    cin >> expr;
    isBalanced(expr);

}