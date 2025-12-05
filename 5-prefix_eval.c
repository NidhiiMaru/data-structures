#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include <string.h>
#define MAX 5
float stack[MAX];
int top=-1;
char prefix[100];
void push(float val){
    if(top==MAX-1){
        printf("\n stack overflow");
    }
    else{
        top ++;
        stack[top]=val;
    }
}
float pop(){
    float val;
    if(top==-1){
        printf("\n stack empty");
        return -1;
    }
    else{
        val=stack[top];
        top--;
        return val;
    }
}
void prefixeval(char prefix[]){
    int i=0,len=strlen(prefix);
    char x;
    float op1,op2,res,p;
    for(i=len-1;i>=0;i--){
        x=prefix[i];
        if(isdigit(x)){
            p=x-'0';
            push(p);
        }
        else if(x=='*' || x=='/' || x=='+' || x=='-' || x=='%'){
            op2=pop();
            op1=pop();
            if(x=='+') res=op1+op2;
            else if(x=='-') res=op1-op2;
            else if(x=='*') res=op1*op2;
            else if(x=='/') res=op1/op2;
            else if(x=='%') res=(int)op1 % (int)op2;
            push(res);
        }
        
        else{
            printf("invalid char");
            exit(0);
        }
    }
    printf("ans is %f",stack[top]);
}
int main()
{
  printf("enter prefix expression: ");
  scanf("%s",prefix);
  prefixeval(prefix);
  return 0;
    }
