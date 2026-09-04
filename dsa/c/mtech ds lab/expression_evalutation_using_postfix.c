#include <stdio.h>

#define STACK_SIZE 100
#define POSTFIX_SIZE 1000

typedef enum
{
    false = 0,
    true = 1
} bool;

typedef struct
{
    int values[STACK_SIZE];
    int top;
    int size;
} stack;

static bool is_digit(char value)
{
    return value >= '0' && value <= '9';
}

static bool is_space(char value)
{
    return value == ' ' || value == '\t' || value == '\n';
}

static bool push(stack *st, int value)
{
    if (st->top == st->size - 1)
        return false;
    st->values[++st->top] = value;
    return true;
}

static bool pop(stack *st, int *value)
{
    if (st->top == -1)
        return false;
    *value = st->values[st->top--];
    return true;
}

static int peek(stack *st)
{
    if (st->top == -1)
        return 0;
    return st->values[st->top];
}

static int precedence(char operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/' || operator == '%')
        return 2;
    if (operator == '^')
        return 3;
    return 0;
}

static bool is_right_associative(char operator)
{
    return operator == '^';
}

bool infix_to_postfix(const char *expression, char *postfix, int postfix_size, stack *st)
{
    int output = 0;
    bool expect_operand = true;
    st->top = -1;

    for (int index = 0; expression[index]; index++)
    {
        char current = expression[index];

        if (is_space(current))
            continue;

        if (is_digit(current))
        {
            if (!expect_operand)
                return false;
            while (is_digit(expression[index]))
            {
                if (output + 1 >= postfix_size)
                    return false;
                postfix[output++] = expression[index++];
            }
            if (output + 1 >= postfix_size)
                return false;
            postfix[output++] = ' ';
            index--;
            expect_operand = false;
            continue;
        }

        if (current == '(')
        {
            if (!expect_operand || !push(st, current))
                return false;
            continue;
        }

        if (current == ')')
        {
            int operator;
            if (expect_operand)
                return false;
            while (st->top != -1 && peek(st) != '(')
            {
                pop(st, &operator);
                if (output + 2 >= postfix_size)
                    return false;
                postfix[output++] = (char)operator;
                postfix[output++] = ' ';
            }
            if (st->top == -1)
                return false;
            pop(st, &operator);
            continue;
        }

        if (precedence(current) == 0 || expect_operand)
            return false;

        while (st->top != -1 && peek(st) != '(' &&
               (precedence((char)peek(st)) > precedence(current) ||
                (precedence((char)peek(st)) == precedence(current) &&
                 !is_right_associative(current))))
        {
            int operator;
            pop(st, &operator);
            if (output + 2 >= postfix_size)
                return false;
            postfix[output++] = (char)operator;
            postfix[output++] = ' ';
        }

        if (!push(st, current))
            return false;
        expect_operand = true;
    }

    if (expect_operand)
        return false;

    while (st->top != -1)
    {
        int operator;
        pop(st, &operator);
        if (operator == '(' || output + 2 >= postfix_size)
            return false;
        postfix[output++] = (char)operator;
        postfix[output++] = ' ';
    }
    postfix[output] = '\0';
    return true;
}

static bool integer_power(int base, int exponent, int *result)
{
    if (exponent < 0)
        return false;
    *result = 1;
    while (exponent > 0)
    {
        if (exponent % 2)
            *result *= base;
        base *= base;
        exponent /= 2;
    }
    return true;
}

bool evaluate_postfix(const char *postfix, int *result, stack *st)
{
    st->top = -1;

    for (int index = 0; postfix[index]; index++)
    {
        if (is_space(postfix[index]))
            continue;

        if (is_digit(postfix[index]))
        {
            int value = 0;
            while (is_digit(postfix[index]))
                value = value * 10 + postfix[index++] - '0';
            index--;
            if (!push(st, value))
                return false;
            continue;
        }

        if (postfix[index] != '+' && postfix[index] != '-' && postfix[index] != '*' &&
            postfix[index] != '/' && postfix[index] != '%' && postfix[index] != '^')
            return false;

        int right;
        int left;
        int value;
        if (!pop(st, &right) || !pop(st, &left))
            return false;

        if (postfix[index] == '+')
            value = left + right;
        else if (postfix[index] == '-')
            value = left - right;
        else if (postfix[index] == '*')
            value = left * right;
        else if (postfix[index] == '/')
        {
            if (right == 0)
                return false;
            value = left / right;
        }
        else if (postfix[index] == '%')
        {
            if (right == 0)
                return false;
            value = left % right;
        }
        else if (!integer_power(left, right, &value))
            return false;

        if (!push(st, value))
            return false;
    }

    if (st->top != 0)
        return false;
    *result = peek(st);
    return true;
}

int main(void)
{
    stack st = {.top = -1, .size = STACK_SIZE};
    char postfix[POSTFIX_SIZE];
    int result;

    if (infix_to_postfix("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3", postfix,
                         POSTFIX_SIZE, &st) &&
        evaluate_postfix(postfix, &result, &st))
    {
        printf("%s\n%d\n", postfix, result);
    }
    return 0;
}
