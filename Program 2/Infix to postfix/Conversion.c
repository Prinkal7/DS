#include<stdio.h>
#include<ctype.h>

#define MAX 50

char stack[MAX];
int top = -1;

char push(char x){
    stack[++top] = x;
}

char pop(){
    return (stack[top--]);
}

int pr(char ele){
    if(ele == '^'){
        return (3);
    }
    else if(ele == '/' || ele =='*'){
        return 2;
    }
    else if(ele == '+' || ele=='-'){
        return 1;
    }else{
        return 0;
    }
}

void main()
{
    char infix[50], postfix[50], ch, elem;
    int i=0,k=0;
    printf("Enter Infix Expression : ");
    scanf("%s",infix);
    push('#');
    while( (ch = infix[i++]) != '\0')
    {
        if( ch == '(' ) push(ch);
        else
        if(isalnum(ch)) postfix[k++] = ch;
        else
        if( ch == ')')
        {
            while( stack[top] != '(')
                postfix[k++] = pop();
            elem=pop();
        }
        else
        {
            while( pr(stack[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while( stack[top] != '#')
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("\nPostfix Expression = %s\n",postfix);
}
