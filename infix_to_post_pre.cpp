#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
class Stack
{
    int top;
    char s[11];
    public:
    Stack()
    {

        top=-1;
    }
    void push(char c)
    {
        if(top==9)
        {

            cout<<"Stack is Full";
        }
        else{
            s[++top]=c;
        }
    }
    char pop()
    {

        if(top==-1)
        {
            cout<<"Stack is Empty";
        }
        else{
            return s[top--];
        }
    }
    void infix_to_post(char infix[])
    {
        int index=0;
        char post[50]={'\0'};
        char symbol;
        char temp;
        int pos=0;
        int length=strlen(infix);
        while(index<length)
        {

            symbol=infix[index];
            switch(symbol)
            {

                case '(':push(symbol);
                       break;
                case ')':
                    temp=pop();
                    while(temp!='(')
                    {

                        post[pos]=temp;
                        pos++;
                        temp=pop();
                    }
                    break;
                    case '+':
                    case '-':
                    case '/':
                    case '*':
                    case '%':
                        while(preced(s[top])>=preced(symbol))
                        {
                            temp=pop();
                            post[pos]=temp;
                            pos++;
                        }
                        push(symbol);
                        break;
                        default:post[pos++]=symbol;
            }
            index++;
        }
        while(top>=0)
        {
            post[pos++]=pop();
        }
        puts(post);
    }


    void infix_to_pre(char infix[])
    {
        int index=0;
        int pos=0;
        char pre[50]={'\0'};
        char symbol;
        char temp;
        int length=strlen(infix);
        while(index<length)
        {

            symbol=infix[index];
            switch(symbol)
            {

                case ')':push(symbol);
                       break;
                case '(':
                    temp=pop();
                    while(temp!=')')
                    {

                        pre[pos++]=temp;
                        temp=pop();
                    }
                    break;
                    case '+':
                    case '-':
                    case '/':
                    case '*':
                    case '%':
                        while(preced(s[top])>=preced(symbol))
                        {
                            temp=pop();
                            pre[pos++]=temp;
                        }
                        push(symbol);
                        break;
                        default:pre[pos++]=symbol;
            }
            index++;
        }
        while(top>=0)
        {
            pre[pos++]=pop();
        }
        strrev(pre);
        puts(pre);
    }
    int preced(char ch)
 {if(ch=='/'||ch=='*'||ch=='%')
   return 5;
  else
   if(ch=='+'||ch=='-')
    return 4;
   else
    return 3;
 }


};
int main()
{
    char infix[50];
    Stack obj;
    cout<<"Enter Infix";
    gets(infix);
    cout<<"Enter 1 for postfix ,2 for prefix";
    int x;
    cin>>x;

    if(x==1)
        obj.infix_to_post(infix);
        else
        {
            strrev(infix);
            obj.infix_to_pre(infix);
        }
}

