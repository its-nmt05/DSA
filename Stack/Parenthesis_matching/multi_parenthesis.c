#include <stdio.h>
#include <stdlib.h>

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }

    return 0;
}

struct stack
{
    char *arr;
    int top;
};

int isEmpty(struct stack *s)
{
    return s->top == -1;
}

struct stack *push(struct stack *s, char val)
{
    s->arr[++s->top] = val;
    return s;
}

char pop(struct stack **s)
{
    if (isEmpty(*s))
    {
        return '\0';
    }
    else
    {
        char c = (*s)->arr[(*s)->top--];
        return c;
    }
}

int parenthesesMatch(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->arr = (char *)malloc(sizeof(char) * 80);
    s->top = -1;
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            popped_ch = pop(&s);
            if(!match(popped_ch, exp[i])) {
                return 0;
            }
        }
    }

    if (isEmpty(s))
    {
        return 1;
    }
}

int main()
{
    char *exp = (char *)malloc(sizeof(char) * 80);
    printf("Enter an expression: ");
    scanf("%s", exp);

    if (parenthesesMatch(exp))
    {
        printf("Parentheses is matching.");
    }
    else
    {
        printf("Parentheses is not matching.");
    }

    return 0;
}