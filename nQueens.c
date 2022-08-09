#include<stdio.h>

void nqueen(int);
int place(int[], int);
void printSolution(int[], int);

void main(){
    int n;
    printf("Enter the number of queens \n");
    scanf("%d", &n);
    nqueen(n);
}

void nqueen(int n){
    int x[10], k=1, count=0;
    x[k]=0;
    while(k!=0){
        x[k]+=1;
        while(x[k]<=n && !place(x, k))
            x[k]+=1;
        if(x[k]<=n){
            
            if(k==n){
                count++;
                printf("\nSolution %d\n", count);
                printSolution(x, k);
            }
            else
                x[++k]=0;
        }
        else    
            k--;
    } 
}

int place(int x[], int k){
    for(int i=1;i<k;i++)
        if(x[i]==x[k] || abs(x[i]-x[k])==abs(i-k)){
            return 0;
        }
    return 1;
}

void printSolution(int x[], int n){
    char c[10][10];
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            c[i][j]='X';
        }
    }

    for(i=1;i<=n;i++){
        c[i][x[i]]='Q';
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%c\t", c[i][j]);
        }
        printf("\n");
    }
}