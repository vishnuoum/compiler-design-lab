#include<stdio.h>
#include<string.h>

void main(){
    char stack[100]="\0",input[100],var,substr[3]="E+E";
    int index=0,i,j,k,l,m,flag;
    printf("Production\nE->E+E\nE->id\n");
    printf("Enter the input string:");
    scanf("%s",input);
    printf("Stack\tString\tAction\n");
    for(i=0,j=0;i<strlen(input);i++){
        var=input[i];
        if(var >= 'a' && var <= 'z' || var=='+'){
            printf("%s\t%s\tShift %c\n",stack,input,var);
            stack[j]=var;
            stack[j+1]='\0';
            input[i]=' ';
        }
        if(stack[j] >= 'a' && stack[j] <= 'z'){
            printf("%s\t%s\tReduce E->id\n",stack,input);
            stack[j]='E';
        }
        for(k=0;k<strlen(stack);k++){
            index=0;
            flag=1;
            for(l=k;l<k+3 && strlen(stack)>=k+3;l++){
                if(substr[index]!=stack[l]){
                    flag=0;
                    break;
                }
                index++;
            }
            // substr[index]='\0';
            if(flag==1 && index!=0){
                printf("%s\t%s\tReduce E->E+E\n",stack,input);
                for(l=k+1,m=k+4;l<strlen(stack);l++,m++){
                    stack[l]=stack[m];
                }
                stack[k]='E';
                j=j-2;
            }
        }
        j++;
    }
    printf("%s\t%s\taccept",stack,input);
}
