#include<stdio.h>

void bfs(int source,int a[20][20], int visited[], int n){
    int q[20], front=0, rear=-1, u, i;
    visited[source]=1;
    q[++rear] = source;
    while(front<=rear){
        u = q[front++];
        for(i=1; i<=n; i++){
            if(visited[i]==0 && a[u][i]==1){
                visited[i]=1;
                q[++rear]=i;
            }
        }
        printf("%d\t", u);
    }
}

void main(){
    int i, j, a[20][20], n, source, visited[20];
    printf("Enter the number of vertices \n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);

    for(i=1; i<=n; i++)
        visited[i]=0;
    printf("Enter the source\n");
    scanf("%d", &source);
    visited[source]=1;

    bfs(source, a, visited, n);
}