#include<stdio.h>
#include<string.h>

void main(){
    
    int i,j,k,l,flag;
    char input[100],rules[]="E+E",stack[100];
    printf("Enter the input string:");
    scanf("%s",input);
    printf("Stack\tInput\tAction\n");
    for(i=0;i<strlen(input);i++){
        if(('a'<=input[i] && input[i]<='z') || input[i]=='+'){
            printf("$%s\t%s$\tShift %c\n",stack,input,input[i]);
            stack[strlen(stack)]=input[i];
            input[i]=' ';
        }
        
        for(j=0;j<strlen(stack);j++){
            if('a'<=stack[j] && stack[j]<='z'){
                printf("$%s\t%s$\tReduce E->i\n",stack,input);
                stack[j]='E';
            }
        }
        
        for(j=0;j<strlen(stack);j++){
            flag=1;
            for(k=j;k<j+3;k++){
                if(stack[k]!=rules[k-j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                printf("$%s\t%s$\tReduce E->E+E\n",stack,input);
                for(k=j+1;k<j+3;k++){
                    stack[k]=stack[k+2];
                }
                stack[j]='E';
                break;
            }
        }
    }
    if(stack[0]=='E' && input[strlen(input)-1]==' ')
        printf("$%c\t%s$\tAccept\n",stack[0],input);
}
