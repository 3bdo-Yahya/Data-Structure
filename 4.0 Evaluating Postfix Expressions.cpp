#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

#define maxSize 1000

int top = -1;
void push(int* stack, int element)
{
    if (top == maxSize - 1) {
        printf("stack is full \n");
        return;
    }

    stack[++top] = element;
}

char pop(int* stack)
{
    if (top == -1) {
        printf("stack is empty \n");
        return 0;
    }

    return stack[top--];
}

float postfix_eval(char postfix[])
{
    int len = strlen(postfix);
    int* stack = new int[len];
    int temp, a, b;

    for (int postfixIndex = 0; postfixIndex < len; ++postfixIndex)
    {
        if (postfix[postfixIndex] <= '9' && postfix[postfixIndex] >= '0')
        {
            push(stack, postfix[postfixIndex] - 48);
        }
        else
        {
            //Pop the top most two operand for operation
            a = pop(stack);
            b = pop(stack);
            switch (postfix[postfixIndex])
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
                break;
            }

            push(stack, temp);
        }
    }

    return pop(stack);

    delete[]stack;

}
int main()
{

    char choice, postfix[maxSize];
    do
    {
        cout << "\n\nEnter the Postfix expression = ";
        cin >> postfix;//Inputting the postfix notation
        float x = postfix_eval(postfix);
        cout << "\n\nThe postfix evaluation is = " << x;
        cout << "\n\nDo you want to continue (Y/y) = ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

}