#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int table[126];
void shiftTable(char pattern[], int m){
    for(int i=0; i<126; i++){
        table[i] = m;
    }
    for(int j=0; j<m-1; j++)
        table[pattern[j]]=m-j-1;
}

void main(){
    int i,k;
    int flag=0;
    char pattern[100], string[100];
    printf("Enter the string\n");
    gets(string);
    printf("Enter the search string \n");
    gets(pattern);
    int m=strlen(pattern);
    int n=strlen(string);
    shiftTable(pattern, m);
    i=m-1;
    while(i<=n-1){
        k=0;
        while(k<=m-1 && pattern[m-1-k]==string[i-k])
            k++;
        if(k==m){
            printf("Pattern found at location %d\n", i-m+1);
            flag=1;
            break;
        }
        else
            i+=table[string[i]];
    }
    if(flag==0)
        printf("pattern not found\n");
}