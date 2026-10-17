/* Extracted and corrected: exp3 p4 + continuation.
   Original output format retained, including concatenated frame values.
   Only 1-based array capacity and w/f bounds corrected. Ideal ACK simulation. */
#include <stdio.h>
int main(){
    int w,i,f,frames[51];
    printf("Enter window size:");
    scanf("%d",&w);
    if(w<1) return 1; /* Prevent modulo by zero. */
    printf("\nEnter no. of frames to transmit:");
    scanf("%d",&f);
    if(f<1 || f>50) return 1; /* 1-based frame array bounds. */
    printf("\nEnter %d frames:",f);
    for(i=1;i<=f;i++) scanf("%d",&frames[i]);
    printf("\nwith sliding window frames:\n\n");
    printf("After sending %d frames at each stage sender waits for acknowledgement sent\n",w);
    for(i=1;i<=f;i++){
        if(i%w==0){
            printf("%d\n",frames[i]);
            printf("Acknowledgement of above frames sent is received by sender\n\n");
        }else printf("%d",frames[i]);
    }
    if(f%w!=0)
        printf("\nAcknowledgement of above frames sent is received by sender\n");
    return 0;
}
