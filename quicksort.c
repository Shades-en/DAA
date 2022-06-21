#include<stdio.h>
#include<time.h>

int num;
clock_t start, end;
double tt;
void quicksort(int arr[], int first, int last){
    int i, j, pivot, temp;
    if(first<last){
        i=pivot=first;
        j=last;
        while(i<j){
            while(arr[i]<=arr[pivot] && i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr, first, j-1);
        quicksort(arr, j+1, last);
    }
}

void main(){
    int i;
    printf("Enter the no. of elements\n");
    scanf("%d", &num);
    srand(time(0));
    int arr[num];
    for(i=0;i<num;i++){
        arr[i]=rand();
    }
    printf("unsorted array:\n");
    for(i=0;i<num;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    printf("Sorted array is\n");
    start=clock();
    quicksort(arr, 0, num-1);
    end=clock();
    for(i=0;i<num;i++)
        printf("%d\t", arr[i]);
    tt=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n time taken=%lf\n", tt);
}