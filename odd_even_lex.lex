%{
    #include<stdio.h>
%}

%%

^[0-9]*[13579]$ {
    printf("Odd");
}

^[0-9]*[02468]$ {
    printf("Even");
}

%%

void main(){

    yylex();

}
