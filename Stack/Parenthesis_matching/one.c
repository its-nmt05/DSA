#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char *arr;
    int top;
};

int isEmpty(struct stack *s)
{
    return s->top == -1;
}

struct stack *push(struct stack *s)
{
    s->arr[++s->top] = '(';
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

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(s);
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            pop(&s);
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

    if(parenthesesMatch(exp)) {
        printf("Parentheses is matching.");
    } else {
        printf("Parentheses is not matching.");
    }

    return 0;
}