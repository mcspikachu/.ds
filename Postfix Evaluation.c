#include <stdio.h>
#include <ctype.h>
int stack[100];
int top = -1;
void push(int);
int pop();
void EvalPostfix(char[]);
int main()
{

    int i;
    char postfix[100];
    printf(" \nEnter postfix expression:");
    scanf("%s",postfix);
    EvalPostfix(postfix);
    return 0;
}
void push(int val)
{

    if (top >= 99) {
        printf("Stack overflow");
        return;
    }
    else {
        top++;
        stack[top] = val;
    }
}
int pop()
{
    int val;
    if (top < 0) {
        printf("stack underflow");
    }
    else {
        val = stack[top];
        top--;
        return val;
    }
}


void EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int a,b;


    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {

            push(ch-'0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            a = pop();
            b = pop();

            switch (ch)
            {
            case '*':
                val = b * a;
                break;

            case '/':
                val = b / a;
                break;

            case '+':
                val = b + a;
                break;

            case '-':
                val = b - a;
                break;
                case '%':
                	val=b%a;
                	break;
            }


            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

