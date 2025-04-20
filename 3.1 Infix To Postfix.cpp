#include <iostream>
#include <cstring>

using namespace std;

int top = -1;
const int maxSize = 1000;

void push(char* stack, char element)
{
    if (top == maxSize - 1) {
        printf("stack is full \n");
        return;
    }

    stack[++top] = element;
}

char pop(char* stack)
{
    if (top == -1) {
        printf("stack is empty \n");
        return 0;
    }

    return stack[top--];
}

int prec(char symbol)
{
    switch (symbol) {

    case '(':
        return 1;
    case ')':
        return 2;
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
    case '%':
        return 4;
    case '^':
        return 5;
    default:
        return 0;
    }

}

void infix_postfix(char infix[])
{
    int len = strlen(infix);
    char* stack = new char[len];
    char* postfix = new char[len];

    int postfixIndex = 0, infixIndex = 0;
    char ch;

    infix[len++] = ')';
    push(stack, '(');

    for (; infixIndex < len; ++infixIndex)
    {
        switch (prec(infix[infixIndex]))
        {
            //Scanned char is '(' push to the stack
        case 1:
            push(stack, infix[infixIndex]);
            break;
            //Scanned char is ')' pop the operator(s) and add to the postfix expression
        case 2:
            ch = pop(stack);
            while (ch != '(')
            {
                postfix[postfixIndex++] = ch;
                ch = pop(stack);
            }
            break;
            //Scanned operator is +,â€“ then pop the higher or same
            //precedence operator to add postfix before pushing
            //the scanned operator to the stack
        case 3:
            ch = pop(stack);
            while (prec(ch) >= 3)
            {
                postfix[postfixIndex++] = ch;
                ch = pop(stack);
            }

            push(stack, ch);
            push(stack, infix[infixIndex]);
            break;
        case 4:
            ch = pop(stack);
            while (prec(ch) >= 4)
            {
                postfix[postfixIndex++] = ch;
                ch = pop(stack);
            }

            push(stack, ch);
            push(stack, infix[infixIndex]);
            break;
        case 5:
            ch = pop(stack);
            while (prec(ch) == 5)
            {
                postfix[postfixIndex++] = ch;
                ch = pop(stack);
            }

            push(stack, ch);
            push(stack, infix[infixIndex]);
            break;
            //Scanned char is a operand simply add to the postfix expression
        default:
            postfix[postfixIndex++] = infix[infixIndex];
            break;
        }
    }

    //Printing the postfix notation to the screen
    cout << "\nThe Postfix expression is = ";
    for (int i = 0; i < postfixIndex; i++)
        cout << postfix[i];

    delete[]stack;
    delete[]postfix;

}

int main()
{

    char choice, infix[maxSize];
    do
    {
        cout << "\n\nEnter the infix expression = ";
        cin >> infix;//Inputting the infix notation
        infix_postfix(infix);//Calling the infix to postfix function
        cout << "\n\nDo you want to continue (Y/y) = ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
