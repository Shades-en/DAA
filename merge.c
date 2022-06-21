#include <stdio.h>
#include <time.h>
 
int n;
clock_t end, start;
double tt;


void combine(int arr[], int low, int high, int mid){
    int temp[high+1];
    int i,k,j;
    i=k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else    
            temp[k++]=arr[j++];
    }

    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=high)
        temp[k++]=arr[j++];

    for(i=low; i<=high; i++)
        arr[i]=temp[i];
}
void mergeSort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        combine(arr, low, high, mid);
    }
}

void main(){
    int i;
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
    mergeSort(arr, 0, n-1);
    end=clock();
    printf("\nAfter sorting\n");
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
    tt=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n time taken=%lf\n", tt);
}