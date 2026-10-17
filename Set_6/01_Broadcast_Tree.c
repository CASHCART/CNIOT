/* EXTRACTED AND CORRECTED: actual Q6, photo13(11),(12), page8 + continuation.
   Heading says distance vector, but ALL visible source is broadcastTree BFS.
   Full original queue/visited/main code preserved. Only node/root bounds added.
   It prints a broadcast tree, NOT a distance matrix or distance-vector tables.
   Photo13(13)'s final-distance output does not belong to the visible source.
   A true distance-vector implementation is NOT recoverable from these pages. */
#include <stdio.h>
#define MAX_NODES 10
void broadcastTree(int graph[MAX_NODES][MAX_NODES],int numNodes,int root){
    int visited[MAX_NODES]={0};
    int queue[MAX_NODES];
    int front=0,rear=0;
    visited[root]=1;
    queue[rear++]=root;
    printf("Adjacent nodes of root node:%d\n",root+1);
    for(int i=0;i<numNodes;i++){
        if(graph[root][i]!=0){ printf("%d",i+1); }
    }
    printf("\n\nBroadcast Tree:\n");
    while(front<rear){
        int current=queue[front++];
        for(int i=0;i<numNodes;i++){
            if(graph[current][i]!=0 && visited[i]==0){
                visited[i]=1;
                queue[rear++]=i;
                printf("%d -> %d\n",current+1,i+1);
            }
        }
    }
}
int main(){
    int numNodes;
    int root;
    printf("Enter no. of nodes:");
    scanf("%d",&numNodes);
    if(numNodes<1 || numNodes>MAX_NODES) return 1;
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<numNodes;i++){
        for(int j=0;j<numNodes;j++) scanf("%d",&graph[i][j]);
    }
    printf("Enter root node:");
    scanf("%d",&root);
    if(root<1 || root>numNodes) return 1;
    broadcastTree(graph,numNodes,root-1);
    return 0;
}
