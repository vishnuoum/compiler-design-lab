#include<stdio.h>
#include<string.h>
#include <ctype.h>

int checkKey(char stmnt[]){
    int i;
    char list[][100]={"int","void","main","char","double"};
    for(i=0;i<5;i++){
        if(!strcmp(stmnt,list[i])){
            return 1;
        }
    }
    return 0;
}

int checkPar(char stmnt[]){
    int i;
    char list[][100]={"(",")","[","]","{","}"};
    for(i=0;i<6;i++){
        if(!strcmp(stmnt,list[i])){
            return 1;
        }
    }
    return 0;
}

int checkConstant(char stmnt[]){
    for(int i=0;i<strlen(stmnt);i++){
        if('0'<=stmnt[i] && stmnt[i]<='9')
            return 0;
    }
    return 1;
}

int checkOperator(char stmnt[]){
    int i;
    char list[][100]={"+","-","*","/","="};
    for(i=0;i<5;i++){
        if(!strcmp(stmnt,list[i])){
            return 1;
        }
    }
    return 0;
}

int checkDelim(char stmnt[]){
    int i;
    char list[][100]={";"};
    for(i=0;i<1;i++){
        if(!strcmp(stmnt,list[i])){
            return 1;
        }
    }
    return 0;
}


void parse(char stmnt[]){
    char word[50];
    int index=0;
    for(int i=0;i<strlen(stmnt);i++){
        if((stmnt[i]==' '|| stmnt[i]=='\n' || stmnt[i]=='\0' || stmnt[i]==EOF) && strlen(stmnt)!=0 ){
            if(checkKey(word)){
                printf("%s\t\tKeyword\n",word);
            }
            else if(checkPar(word)){
                printf("%s\t\tParanthesis\n",word);
            }
            else if(checkConstant(word)){
                printf("%s\t\tConstant\n",word);
            }
            else if(checkOperator(word)){
                printf("%s\t\tOperator\n",word);
            }
            else if(checkDelim(word)){
                printf("%s\t\tDelimiter\n",word);
            }
            else{
                printf("%s\t\tIdentifier\n",word);
            }
            word[0]='\0';
            index=0;
        }
        else{
            word[index]=stmnt[i];
            index++;
            word[index]='\0';
        }
    }
}

void main(){
    char stmnt[100];
    FILE *fptr;
//     add file.c in the working directory
    fptr=fopen("file.c","r");
    int i=0;
    printf("Lexeme\t\tToken\n");
    while(fgets(stmnt,100,fptr)!=NULL){
        if(stmnt[0]=='#'){
            printf("%s\t\tPreprocessor Directive\n",stmnt);
        }
        else{
            parse(stmnt);
        }
    }
}
