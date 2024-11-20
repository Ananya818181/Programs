#include<stdio.h>
int top=-1,n,i;
char text[20],stack[20];

void push(char data)
{
    top = top + 1;
    stack[top] = data;
}

char pop()
{
    char data = stack[top];
    top = top - 1;
    return data;
}

int isMatching(char data1 , char data2)
{
    if((data1=='(' && data2==')') ||
       (data1=='{' && data2=='}') ||
       (data1=='[' && data2==']'))
        return 1;
    else
        return 0;
}

int isBalanced(char* text)
{
    int i = 0;
    while(text[i] != '\0')
    {
        if(text[i] == '(' || text[i] == '{' || text[i] == '[')
            push(text[i]);
        else if(text[i] == ')' || text[i] == '}' || text[i] == ']')
        {
            if(top == -1) 
                return 0;
            else if(!isMatching(pop(), text[i]))
                return 0;
        }
        i++;
    }

    if(top == -1)
        return 1;
    else    
        return 0;
}

void main()
{
    printf("Enter the string: ");
    scanf("%s", text);
    if(isBalanced(text))
        printf("Balanced\n");
    else 
        printf("Not balanced\n");
}
