#include <stdio.h>
int i,j,m,n,p[10],w[10],v[10][10];

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

void knapsack(){
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0)
                v[i][j]=0;
            else if(w[i]>j)
                v[i][j]=v[i-1][j];
            else   
                v[i][j]=max(v[i-1][j], v[i-1][j-w[i]]+p[i]);
        }
    }
    printf("The optimal solution is %d\n", v[n][m]);
    printf("The Knapsack table is as follows \n");
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

void element(){
    int x[n];
    for(i=1;i<=n;i++)
        x[i] = 0;
    
    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(v[i][j]!=v[i-1][j]){
            printf("i=%d\n", i);
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }
    for(i=1;i<=n;i++)
        printf("%d\t", x[i]);
    printf("\n");
}

void main(){
    printf("Enter the capacity of knapsack\t");
    scanf("%d", &m);
    printf("\nEnter the number of elements\t");
    scanf("%d", &n);
    printf("\nEnter the weights of the elements \t");
    for(i=1;i<=n;i++)
        scanf("%d", &w[i]);
    printf("\nEnter the profits of the elements \t");
    for(i=1;i<=n;i++)
        scanf("%d", &p[i]);
    knapsack();
    printf("\n");
    element();
}