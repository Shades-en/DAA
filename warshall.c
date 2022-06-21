#include <stdio.h>
int matrix[10][10];
int i, j, k, row, column;

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

void warshall(int matrix[10][10]){
    for(k=0; k<row; k++){
        for(i=0; i<row; i++){
            for(j=0; j<column; j++){
                matrix[i][j] = max(matrix[i][j], (matrix[i][k] && matrix[k][j]));
            }
        }
    }
}

void main(){
    printf("Enter the num of rows \n");
    scanf("%d", &row);
    printf("Enter the num of column \n");
    scanf("%d", &column);
    printf("Enter the adjacency matrix \n");
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    warshall(matrix);
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}