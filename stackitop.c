#include<stdio.h>
#include<ctype.h>
char stack[100],infix[100],postfix[50];
int top=-1;
void push(char elem)
{
    stack[++top]=elem;
}
void pop()
{
    top-=1;
}
void display(int size)
{
    for(int i=0;i<=size;i++)
    printf("%c",postfix[i]);
}
int pr(char ch)
{
    if(ch == '^') 
    return 3;
    else if(ch =='/'||ch=='%'||ch=='*') 
    return 2;
    else if(ch=='+'||ch=='-')
    return 1;
    else
    return 0;
}
int itopfix()
{
    int i=0,j=0;
    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))
        postfix[j++]=infix[i];
        else if(infix[i] == '(')
        push(infix[i]);
        else if(infix[i] ==')')
        {
        while(infix[i] != '(')
        {
        postfix[j++]=stack[top];
        pop();
        }
        pop();
        }
        else
        {
            if(top==-1)
            push(infix[i]);
            else
            {
                while(pr(stack[top]) >= pr(infix[i]))
                {
                postfix[j++]=stack[top];
                pop();
                }
                push(infix[i]);
            }
        }
      i++;
    }
    for(i=top;i>=0;i--)
    {
        postfix[j++]=stack[top];
        pop();
    }
return j;
}
int main()
{
    printf("Enter the infix Expression\n");
    gets(infix);
    int size=itopfix();
    display(size);
    return 0;
}