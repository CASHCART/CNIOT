/* EXTRACTED AND CORRECTED: actual Q4 code, photos13(6),(7), page5 + continuation.
   The record calls this Dijkstra, but it compares manually entered paths.
   This file deliberately preserves that original algorithm and statement order.
   Corrections: int main; dimension6 for indexes1..5; read costs into a (not path);
   validate path count. Diagonal costs must be0; each entered route must start1,
   reach5 and have5 slots (pad unused slots AFTER5 with0). Sample cost is6, not4.
   This is NOT a claim that the original code implements true Dijkstra. */
#include <stdio.h>
int main(){
    int path[6][6],i,j,min,a[6][6],p,st=1,ed=5,
        stp,edp,t[6],index;
    printf("Enter cost matrix:\n");
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++) scanf("%d",&a[i][j]);
    printf("Enter no. of paths:\n");
    scanf("%d",&p);
    if(p<1 || p>5) return 1;
    printf("Enter possible paths:\n");
    for(i=1;i<=p;i++)
        for(j=1;j<=5;j++) scanf("%d",&path[i][j]);
    for(i=1;i<=p;i++){
        t[i]=0;
        stp=st;
        for(j=1;j<=5;j++){
            edp=path[i][j];
            t[i]=t[i]+a[stp][edp];
            if(edp==ed) break;
            else stp=edp;
        }
    }
    min=t[st];
    index=st;
    for(i=1;i<=p;i++){
        if(min>t[i]){
            min=t[i];
            index=i;
        }
    }
    printf("Minimum cost:%d",min);
    printf("\nMinimum cost path:");
    for(i=1;i<=5;i++){
        printf("->%d",path[index][i]);
        if(path[index][i]==ed) break;
    }
    return 0;
}
