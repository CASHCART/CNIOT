/* Extracted and corrected: record experiment8, Traffic shaping using leaky
   bucket algorithm. Source: Record Pics/photos14(1),(2), both code pages joined.
   Preserve bucket_size/output_rate/n/incoming/stored/sent/i and both loops.
   Genuine correction: first-page stored=sent is changed to stored-=sent;
   otherwise it contradicts both the continuation and recorded sample.
   Handwritten hyphens in identifiers normalized to underscores.
   Positive capacity/rate and nonnegative packet sizes are required.
   Compile: gcc -std=c99 01_Leaky_Bucket.c -o /tmp/leaky_bucket
*/
#include <stdio.h>
int main(){
    int bucket_size,output_rate,n;
    int incoming,stored=0,sent,i;
    printf("Enter bucket size:");
    if(scanf("%d",&bucket_size)!=1 || bucket_size<1) return 1;
    printf("Enter output rate:");
    if(scanf("%d",&output_rate)!=1 || output_rate<1) return 1;
    printf("Enter no. of packets:");
    if(scanf("%d",&n)!=1 || n<0) return 1;

    for(i=1;i<=n;i++){
        printf("Enter packet size %d:",i);
        if(scanf("%d",&incoming)!=1 || incoming<0) return 1;
        if(incoming>bucket_size-stored){
            printf("Packet overflow! Packets dropped\n");
        }else{
            stored+=incoming;
            printf("Packets in bucket:%d\n",stored);
        }
        sent=(stored<output_rate)?stored:output_rate;
        stored-=sent; /* Record first page incorrectly says stored=sent. */
        printf("Packets sent:%d\n",sent);
        printf("Packets remaining:%d\n",stored);
    }
    while(stored>0){
        sent=(stored<output_rate)?stored:output_rate;
        stored-=sent;
        printf("Packet sent:%d\n",sent);
        printf("Packet remaining:%d\n",stored);
    }
    return 0;
}
