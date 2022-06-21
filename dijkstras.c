#include<stdio.h>

void dijkstras();

int i,j,n,source,visited[10],d[10],cost[10][10],u,w,min;
void main(){
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    printf("Enter the cost adjacency matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    printf("Enter the source node \n");
    scanf("%d",&source);

    dijkstras();

    for(i=1;i<=n;i++){
        if(i!=source)
            printf("shortest path from %d to %d is %d\n", source, i, d[i]);
    }
        
}

void dijkstras(){
    for(i=0;i<=n;i++){
        visited[i]=0;
        d[i]=cost[source][i];
    }

    visited[source]=1;
    d[source]=0;

    for(j=2;j<=n;j++){
        min=999;
        for(i=1;i<=n;i++){
            if(!visited[i]){
                if(min>d[i]){
                    min=d[i];
                    u=i;
                }
            }
        }

        visited[u]=1;
        for(w=1;w<=n;w++){
            if(cost[u][w]!=999 && !visited[w]){
                if(d[w]>(cost[u][w]+d[u]))
                    d[w]=cost[u][w]+d[u];
            }
        }
    }

    // for(i=1;i<=n;i++){
    //         printf("shortest path %d i=%d\n", d[i], i);
    // }
}