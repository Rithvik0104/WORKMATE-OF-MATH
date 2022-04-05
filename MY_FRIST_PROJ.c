#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stck[SIZE];
int top = -1;

typedef struct node

{
    int data;
    char ster;
    struct node *next;
} node;

node *enter(node *v, int numb)
{
    if (numb == 2)
    {
        printf("\nEnter a operator which you need to perform\nOptions + - * / ^:");
    }
    else if (numb == 1)
    {
        printf("\nEnter the second number:");
    }

    char input[20];
    scanf("%s", &input);
    node *tmp = malloc(100);

    if (atoi(input) != 0)
    {
        tmp->data = atoi(input);
        tmp->next = NULL;
    }
    else
    {
        tmp->ster = (char)input[0];
        node *nodeNode = enter(tmp, numb - 1);
        tmp->next = nodeNode;
    }
}

void calculator()
{
    node *head = malloc(100);
    char input[20];
    printf("\nEnter the first number:");
    scanf("%s", &input);
    head->data = atoi(input);
    node *nextNode = enter(head, 2);
    head->next = nextNode;

    int first = head->data;
    int second = head->next->next->data;
    char op = head->next->ster;
    
    if (op == '+')
    {
        printf("\nThe result for the given numbers for ADDITION");
        printf("\n%i + %i = %i", first, second, first + second);
    }
    else if (op == '-')
    {
        printf("\nThe result for the given numbers for SUBTRACTION");
        printf("\n%i - %i = %i", first, second, first - second);
    }
    else if (op == '*')
    {
        printf("\nThe result for the given numbers for MULTIPLICATION");
        printf("\n%i * %i = %i", first, second, first * second);
    }
    else if (op == '/')
    {
        float a=first;
        float b=second;
        printf("\nThe result for the given numbers for DIVISION");
        printf("\n %i / %i = %.2f", first, second, a / b);
    }

    else if (op == '^')
    {
        printf("\nThe result for the given numbers for POWER");
        printf("\n  %i ^ %i = %i", first, second, first ^ second);
    }

    else
    {
        printf("\nPlease enter the correct operator or number");
    }
}

void multi()
{
    int i;
    int k;
    printf("\nEnter the table which you need:");
    scanf("%d", &k);
    for (i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", k, i, k * i);
    }
}

void push(char item)
{
    if (top >= SIZE - 1)
    {
        printf("\n the Stack is Overflow..");
    }
    else
    {
        top = top + 1;
        stck[top] = item;
    }
}

char pop()
{
    char item;
    if (top < 0)
    {
        printf("the stack is  under flow: invalid infix expression you entered ");
        getchar();
        exit(1);
    }
    else
    {
        item = stck[top];
        top = top - 1;
        return (item);
    }
}

int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char symbol)
{
    if (symbol == '^')
    {
        return (3);
    }
    else if (symbol == '*' || symbol == '/')
    {
        return (2);
    }
    else if (symbol == '+' || symbol == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
    int i, j;
    char item;
    char x;

    push('(');
    strcat(infix_exp, ")");

    i = 0;
    j = 0;
    item = infix_exp[i];

    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix_exp[j] = item;
            j++;
        }
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
            push(x);

            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix_exp[j] = x;
                j++;
                x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
            getchar();
            exit(1);
        }
        i++;

        item = infix_exp[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");
        getchar();
        exit(1);
    }

    postfix_exp[j] = '\0';
}

long decimalnumtoBinarynum(int decnum)
{
    long binarynum = 0;
    int rem, temp = 1;

    while (decnum != 0)
    {
        rem = decnum % 2;
        decnum = decnum / 2;
        binarynum = binarynum + rem * temp;
        temp = temp * 10;
    }
    return binarynum;
}

void infix()
{

    char infix[SIZE], postfix[SIZE];
    printf("\nEnter the Infix expression:");
    scanf("%s", &infix);

    InfixToPostfix(infix, postfix);
    printf("\nThe expected Postfix Expression is:");
    puts(postfix);
}

void dectobin()
{
    int decnum;
    printf("\nEnter a Decimal Number to convert:");
    scanf("%d", &decnum);
    printf("\nEquivalent Binary Number is: %ld", decimalnumtoBinarynum(decnum));
}

void quiz()
{
    int p, a[10], n = 0;
    printf("\n------QUIZ------");
    for (p = 1; p <= 10; p++)
    {
        n = 0;
        switch (p)
        {
        case 1:
            printf("\nwhat will be ans for for given expression of infix to postfix \n (A/(B-C+D))(E-F)*C \n 1.ABCD-+/F-*C \n 2.ABC-D/EF+-*C \n 3.ABC-D+/EF-*C ");
            printf("\nEnter answer for above quetsion:");
            scanf("%d", &n);
            if (n == 3)
            {
                printf("You have entered the correct answer Now you entered to second question.", p);
            }
            else
            {
                printf("You have entered the wrong answer Better Luck Next Time ", p - 1);
                p = 6;
            }
            break;
        case 2:
            printf("\n\nwhat will be binary value for 13\n 1.1101 \n 2.1111 \n 3.1001");
            printf("\nEnter answer for above quetsion:");
            scanf("%d", &n);
            if (n == 1)
            {
                printf("You have entered the correct answer Now your going to third question xD ", p);
            }

            else
            {
                printf("You have entered the wrong answer Better Luck Next Time ", p - 1);

                p = 6;
            }
            break;
        case 3:
            printf("\n\nwho invented the calculator \n1. Stev\n 2. Jack St. Clair Kilby \n 3. Margan");
            printf("\nEnter answer for above quetsion:");
            scanf("%d", &n);
            if (n == 2)
            {
                printf("You have entered the correct answer Now you have to ans next question\n", p);
            }
            else
            {
                printf("You have entered the wrong answer Better Luck Next Time", p - 1);
                p = 6;
            }
            break;
        case 4:
            printf("\n\nwho is called as father of mathematics \n 1. radha\n 2.Archimedes\n 3. gargee");
            printf("\nEnter answer for above quetsion:");
            scanf("%d", &n);
            if (n == 2)
            {
                printf("\nYou have entered the correct answer wow now its last question to attend", p);
            }
            else
            {
                printf("You have entered the wrong answer Better Luck Next Time ", p - 1);
                p = 6;
            }
            break;
        case 5:
            printf("\n\nwho is famous mathmatics in india \n 1. BRAHMAGUPTA.\n 2. ramanjan \n 3. acharya");
            printf("\nEnter answer for above quetsion:");
            scanf("%d", &n);
            if (n == 1)
            {
                printf("You have entered the correct answer wow you answered every thing correct keep it up", p);
            }
            else
            {
                printf("You have entered the wrong answerBetter Luck NextTime", p - 1);
                p = 6;
            }
            break;
        default:
            break;
        }
    }
}

long BinarynumtoDecimalnum(int binnum)
{
    long dec = 0;
    int i = 0, rem;
    while (binnum != 0)
    {
        rem = binnum % 10;
        binnum /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

void bintodec()
{
    int binnum;
    printf("\nEnter a Binary Number to convert:");
    scanf("%d", &binnum);
    printf("\nEquivalent Decimal Number is: %ld", BinarynumtoDecimalnum(binnum));
}

int postfixevaluation()
{
    char expr[30];
    char *p;
    int x1, x2, x3, n;
    printf("Enter the expression for postfix evaluation:");
    scanf("%s", expr);
    p = expr;
    while (*p != '\0')
    {
        if (isdigit(*p))
        {
            n = *p - 48;
            push(n);
        }
        else
        {
            x1 = pop();
            x2 = pop();
            switch (*p)
            {
            case '+':
            {
                x3 = x1 + x2;
                break;
            }
            case '-':
            {
                x3 = x2 - x1;
                break;
            }
            case '*':
            {
                x3 = x1 * x2;
                break;
            }
            case '/':
            {
                x3 = x2 / x1;
                break;
            }
            }
            push(x3);
        }
        p++;
    }
    printf("\nThe result of expression %s  =  %d", exp, pop());
    return 0;
}

void helpdesk()
{
    printf("\nAny queries regarding this Project");
    printf("\nYou can contact me through");
    printf("\n\nMobile number:8562916291");
    printf("\n\nOR");
    printf("\n\nEmail id:rithvikdadapuram2003@gmail.com");
    printf("\n\n\n----------------------THANK YOU----------------------");
}

int main()
{
    int ch, q;
    do
    {
        printf("\n----------WELCOME TO WORKMATE OF MATHS----------\n \n");
        printf("Options of this project");
        printf("\n1.CALCULATOR");
        printf("\n2.MULTIPLICATION TABLE");
        printf("\n3.INFIX TO POSTFIX");
        printf("\n4.DECIMAL TO BINARY CONVERSION");
        printf("\n5.QUIZ ON MATHS");
        printf("\n6.BINARY TO DECIMAL CONVERSION");
        printf("\n7.POSTFIX EVALUATION");
        printf("\n8.HELP DESK");
        // printf("\n8.HELP DESK");
        printf("\n\nENTER YOUR CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            calculator();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        case 2:
            multi();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        case 3:
            infix();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        case 4:
            dectobin();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        case 5:
            quiz();
            printf("\n need to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        case 6:
            bintodec();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        case 7:
            postfixevaluation();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;
        case 8:
            helpdesk();
            printf("\nneed to go back to menu please enter 0:");
            scanf("%d", &q);
            break;

        default:
            printf("\n you enter wrong operator check once and do");
            exit(0);
        }

    } while (q == 0);
    printf("\n\n --------------------------------THANK YOU FOR VISITING--------------------------------");
    return 0;
}
