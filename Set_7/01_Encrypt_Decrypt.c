/* Extracted and corrected: exp7 photo14 (no suffix). Only fgets failure guard.
   Fixed key3, character-code addition/subtraction and original format preserved. */
#include <stdio.h>
#include <string.h>
int main(){
    char text[100];
    int i,key=3;
    printf("Enter a message:");
    if(fgets(text,sizeof(text),stdin)==NULL) return 1;
    text[strcspn(text,"\n")]='\0';
    for(i=0;text[i]!='\0';i++) text[i]=text[i]+key;
    printf("Encrypted message:%s\n",text);
    for(i=0;text[i]!='\0';i++) text[i]=text[i]-key;
    printf("Decrypted message:%s\n",text);
    return 0;
}
