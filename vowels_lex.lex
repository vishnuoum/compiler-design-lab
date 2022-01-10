%{
    #include<stdio.h>
    int v=0,c=0;
%}

%%

[aeiouAEIOU] {
    v++;
}

[a-zA-Z] {
    c++;
}

"\n" {
    printf("vowels=%d,consonants=%d\n",v,c);
    v=0;c=0;
}

%%

void main(){

    yylex();

}
