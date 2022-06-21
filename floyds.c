#include <stdio.h>
int matrix[10][10];
int i, j, k, order;

int min(int a, int b){
    if(a>b)
        return b;
    return a;
}

void warshall(int matrix[10][10]){
    for(k=0; k<order; k++){
        for(i=0; i<order; i++){
            for(j=0; j<order; j++){
                matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
            }
        }
    }
}

void main(){
    printf("Enter the num of rows \n");
    scanf("%d", &order);
    printf("Enter the adjacency matrix \n");
    for(i=0; i<order; i++){
        for(j=0; j<order; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    warshall(matrix);
    for(i=0; i<order; i++){
        for(j=0; j<order; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}