#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
char stack [Max];
int top=-1;
char infix[100],prefix[100],infixrev[100];
void push(char val)
{
    if(top==Max-1){
        printf("stack full");
    }
    else{
        top++;
        stack[top]=val;
    }
}
char pop(){
    if(top==-1){
        printf("empty");
        return -1;
    }
    else{
        return stack[top--];;
    }
}

int priority(char op){
    if(op=='%') return 3;
    else if(op=='*' || op=='/') return 2;
    else if(op=='-' || op=='+') return 1;
    else return 0;
}
void reverse(char og[],char res[]){
    int len=strlen(og);
    for(int i=0;i<len;i++){
        res[i]=og[len-i-1];
        if(res[i]=='(') res[i]=')';
        else if(res[i]==')') res[i]='(';
    }
    res[len]='\0';
}
void itp(){
    int i=0,j=0;

    reverse(infix,infixrev);
    char x;
    while(infixrev[i]!='\0'){
        x=infixrev[i];
        if((x>='A'&&x<='Z') || (x>='a'&&x<='z') || (x>='0'&&x<='9')){
            prefix[j]=x;
            j++;
        }
        else if(x=='(') push(x);
        else if(x==')'){
            while(top!=-1 && stack[top]!='('){
                prefix[j++]=pop();
            }
            pop(); //'('
        }
        else{
            while(top!=-1 && priority(stack[top])>priority(x)){ //here no >=
                prefix[j++]=pop();
            }
            push(x);
        }
        i++;
    }
    while(top!=-1){
        prefix[j++]=pop();
    }
    prefix[j]='\0';
    
}

void main(){
    char temp[100];
    printf("enter infix exp");
    scanf("%s",infix);
    itp();
    reverse(prefix,temp);
    printf("prefix exp:%s",temp);
}
