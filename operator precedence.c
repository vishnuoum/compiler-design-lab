#include<stdio.h>
#include<string.h>

void main(){
    char input[100][100],terminals[100];
    int n,i,j,flag,index=0;
    printf("Enter number of productions:");
    scanf("%d",&n);
    printf("Enter the productions:\n");
    for(i=0;i<n;i++){
        scanf("%s",input[i]);
    }

    for(i=0;i<n;i++){
        flag=-1;
        for(j=0;j<strlen(input[i]);j++){
            if(input[i][j]=='=' || (input[i][j]>='a' && input[i][j]<='z') || input[i][j]=='+' || input[i][j]=='-'
                                                                                || input[i][j]=='*' || input[i][j]=='/'){
                flag=0;
                if(input[i][j]!='='){
                    terminals[index]=input[i][j];
                    index++;
                }
            }
            
            else if(input[i][j]>='A' && input[i][j]<='Z' && flag!=-1){
                if(flag==0){
                    flag=1;
                }
                else if(flag==1){
                    printf("Not operator precedence grammar\n");
                    flag=2;
                    break;
                }
            }
        }
        if(flag==2){
            break;
        }
    }
    terminals[index]='$';
    printf("\t");
    for(i=0;i<index+1;i++){
        printf("%c\t",terminals[i]);
    }


    for(i=0;i<index+1;i++){
        printf("\n%c\t",terminals[i]);
        for(j=0;j<index+1;j++){
            if(terminals[i]>='a' && terminals[i]<='z' && terminals[j]>='a' && terminals[j]<='z'){
                printf(" \t");
            }
            else if(terminals[i]=='$'&&terminals[j]=='$'){
                printf("A\t");
            }
            else if(terminals[i]==terminals[j] || terminals[i]>terminals[j]){
                if(terminals[i]=='+'&&terminals[j]=='*'){
                    printf("<\t");
                    continue;
                }
                printf(">\t");
            }
            else if(terminals[i]<terminals[j]){
                if(terminals[i]=='*'&&terminals[j]=='+'){
                    printf(">\t");
                    continue;
                }
                printf("<\t");
            }
        }
    }
} 
