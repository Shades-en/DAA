#include <stdio.h>

void main(){
    int i,j,a,b,u,v,n,ne=1,min_cost=0,min,cost[10][10],parent[10];

    printf("Enter the number of node\n");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &cost[i][j]);
        }
    }
    for(i=1;i<=n;i++)
        parent[i]=0;

    while(ne<n){
        min=999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(min>cost[i][j]){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        while(parent[v]){
            v=parent[v];
        }
        while(parent[u]){
            u=parent[u];
        }
        
        if(u!=v){
            printf("edge-%d(%d->%d)=%d\n",ne++,a,b, min);
            min_cost+=min;
            parent[v]=u;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("Cost of min spanning tree is %d\n",min_cost);
}