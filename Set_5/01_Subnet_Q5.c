/* Extracted and corrected: EXACT Q5, photo13(9), page6; sample photo13(10), page7.
   Record heading: subnet of hosts / obtain a broadcast tree.
   Actual program prints root neighbours only. No IPv4 subnet-mask calculation.
   Corrections: prototype semicolon and 1-based array/root bounds.
   Original adj(), variables, OR condition, tab output and sequence retained. */
#include <stdio.h>
void adj(int k,int n,int a[10][10]);
int main(){
    int a[10][10],n,root;
    int i,j;
    printf("Enter no. of nodes:");
    scanf("%d",&n);
    if(n<1 || n>9) return 1;
    printf("Enter adj. matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d->%d:",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter root node:");
    scanf("%d",&root);
    if(root<1 || root>n) return 1;
    adj(root,n,a);
    return 0;
}
void adj(int k,int n,int a[10][10]){
    int j;
    printf("Adj. nodes of root node %d:\n",k);
    for(j=1;j<=n;j++){
        if(a[k][j]==1||a[j][k]==1){ printf("%d\t",j); }
    }
    printf("\n");
}
