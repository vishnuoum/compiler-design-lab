#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

regex_t regex;

void parse(char[]);
void token(char[], int, int);
int keyword(char[]);
int delimiter(char[]);
int paranthesis(char[]);
int operator(char[]);
int literal(char[]);

void main(){
    char statement[100];
    regcomp(&regex,"[:word:]",0);
    printf("Lexeme\tToken\n\n\n");
    FILE *fptr;
    fptr = fopen("files/input.c", "r");
    while (fgets(statement, 100, fptr) != NULL){
        if (statement[0] == '#'){
            continue;
        }
        parse(statement);
    }
}

void parse(char statement[]){
    int bp = 0, fp = 0;
    for (fp = 0; fp < strlen(statement); fp++){
        char ch = statement[fp];
        if (ch == ' ' || ch == '\n' || ch == '\0'){
            token(statement, bp, fp);
            bp = fp + 1;
        }
    }
}

void token(char statement[], int start, int end){
    char token[100];
    int index;
    for (index = 0; start < end; start++, index++){
        token[index] = statement[start];
    }
    token[index] = '\0';
    if (token[0] == ' ' || token[0] == '\0'){
        return;
    }
    // printf("%s\n",token);
    if (keyword(token) == TRUE){
        printf("%s\tKeyword\n", token);
    }
    else if (delimiter(token) == TRUE){
        printf("%s\tDelimiter\n", token);
    }
    else if (paranthesis(token) == TRUE){
        printf("%s\tParanthesis\n", token);
    }
    else if (operator(token) == TRUE){
        printf("%s\tOperator\n", token);
    }
    else if (literal(token) == TRUE){
        printf("%s\tLiteral\n", token);
    }
    else if((token[0]=='_'||isalpha(token[0]))&&!(regexec(&regex, token, 0, NULL, 0))){
        printf("%s\tIdentifier\n", token);
    }
    else{
        printf("%s\tNot recognized\n",token);
    }
}

int keyword(char tokenWord[]){
    char keywords[][50] = {"main","auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "char", "return", "union", "continue", "for", "void", "do", "if", "static", "while", "default", "const", "float"};
    for (int i = 0; i < 23; i++){
        if (!strcmp(keywords[i], tokenWord)){
            return TRUE;
        }
    }
    return FALSE;
}

int delimiter(char tokenWord[]){
    if (!strcmp(";", tokenWord) || !strcmp(",", tokenWord)){
        return TRUE;
    }
    return FALSE;
}

int paranthesis(char tokenWord[])
{
    char paranth[][5]={"(",")","{","}","[","]"};
    for (int i = 0; i < 6; i++){
        if (!strcmp(paranth[i], tokenWord)){
            return TRUE;
        }
    }
    return FALSE;
}

int operator(char tokenWord[]){
    char operators[][10] = {"+", "-", "*", "/", "++", "--", "=", "==", "<", ">", "<=", ">=", "!=", "!", "&", "|", "&&", "||"};
    for (int i = 0; i < 18; i++){
        if (!strcmp(operators[i], tokenWord)){
            return TRUE;
        }
    }
    return FALSE;
}

int literal(char tokenWord[]){
    char ch = tokenWord[0];
    char literals[] = {'\'', '\"', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 12; i++){
        if (ch == literals[i])
        {
            return TRUE;
        }
    }
    return FALSE;
}
