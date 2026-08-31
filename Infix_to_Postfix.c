#include <stdio.h>
#include <ctype.h>

#define MAX 100

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    char stack[MAX];
    int top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

     
        if (isdigit((unsigned char)ch))
        {
            postfix[j++] = ch;
        }

        else if (ch == '(')
        {
            stack[++top] = ch;
        }


        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }

            if (top == -1)
            {
                printf("Error: Parentheses are not balanced.\n");
                postfix[0] = '\0';
                return;
            }

            top--;  
        }


        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }

        else
        {
            printf("Error: Invalid character.\n");
            postfix[0] = '\0';
            return;
        }

        i++;
    }

    while (top != -1)
    {
        if (stack[top] == '(')
        {
            printf("Error: Parentheses are not balanced.\n");
            postfix[0] = '\0';
            return;
        }

        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0')
        printf("Postfix expression: %s\n", postfix);

    return 0;
}