#include<stdio.h>
#include <time.h>
int n;
clock_t start, end;
double tt;

void main(){
    int i,j,min, temp;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    srand(time(0));
    for(i=0;i<n;i++){
        arr[i]=rand();
    }
    printf("Unsorted array is\n");
    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    start=clock();
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    end=clock();
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
    tt=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n time taken=%lf\n", tt);
}