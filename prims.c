#include<stdio.h>

void main(){
    int i,j,a,b,u,v,source,n,ne=1,min_cost=0,min,cost[10][10],visited[10];
    printf("Enter the number of node\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;

    printf("Enter the source node\n");
    scanf("%d", &source);

    visited[source]=1;

    while(ne<n){
        min=999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(min>cost[i][j]){
                    if(visited[i]==0)
                        continue;
                    else{
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }

        if(visited[u]==0 || visited[v]==0){
            printf("edge-%d(%d->%d)=%d\n",ne++,a,b, min);
            min_cost=min_cost+min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Cost of Minimum cost spanning tree is %d \n", min_cost);
}