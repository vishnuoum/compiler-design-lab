#include <stdio.h>
#include<string.h>

char firstList[100],rules[100][100];
int n,ind=0;

int check(char c){
    for(int i=0;i<strlen(firstList);i++){
        if(c==firstList[i]){
            return 1;
        }
    }
    return 0;
}

void first(char c){
    for(int i=0;i<n;i++){
        if(rules[i][0]==c){
            if(('a'<=rules[i][2] && rules[i][2]<='z')|| rules[i][2]=='+'){
                if(!check(rules[i][2])){
                    printf("%c\n",rules[i][2]);
                    firstList[ind++]=rules[i][2];
                }
            }
            else if('A'<=rules[i][2] && rules[i][2]<='Z'){
                first(rules[i][2]);
            }
        }
    }
}

void main()
{
    char c;
    printf("Enter number of rules:");
    scanf("%d",&n);
    printf("Enter the rules:\n");
    for(int i=0;i<n;i++){
        scanf("%s",rules[i]);
    }
    printf("Enter the Non Terminal to find first:");
    scanf(" %c",&c);
    printf("First of %c\n",c);
    first(c);

}
