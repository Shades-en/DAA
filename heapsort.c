#include<stdio.h>
#include<time.h>

void heapify(int h[],int n){
    int i, j, k, n1, v, heap;
    n1 = n;
    for(i=n1/2;i>=1;i--){
        k=i;
        v=h[k];
        heap=0;
        while(!heap && 2*k<=n){
            j=2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j=j+1;
            if(v>=h[j])
                heap=1;
            else{
                h[k]=h[j];
                k=j;
            }
            h[k]=v;
        }
    }
}


void main(){
    int n, i, size, t;
    clock_t start, end;
    double total_time;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int h[n];
    srand(time(0));
    for(i=1;i<=n;i++)
        h[i] = rand();
    printf("Elements Before Sorting \n");
    for(i=1;i<=n;i++)
        printf("%d\t", h[i]);
    printf("\n");
    heapify(h, n);
    printf("Elements after heapify\n");
    for(i=1;i<=n;i++)
        printf("%d\t", h[i]);
    printf("\n");
    start = clock();
    for(i=n;i>=1;i--){
        t=h[1];
        h[1] = h[i];
        h[i] = t;
        size = i-1;
        heapify(h, size);
    }
    end = clock();
    printf("Elements after sorting \n");
    for(i=1;i<=n;i++)
        printf("%d\t", h[i]);
    printf("\n");
    total_time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Total time taken is %e", total_time);
}