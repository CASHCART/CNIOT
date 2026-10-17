/* SET1 - THREE COMPLETE RECORD PROGRAMS
   Select ONE program at compilation; no main() or record body is rewritten.
   CN_PROGRAM=1: CHARACTER COUNT (default)
   CN_PROGRAM=2: CHARACTER STUFFING
   CN_PROGRAM=3: BIT STUFFING
   Example from this folder (binary kept outside the study folder):
   gcc -std=c99 -DCN_PROGRAM=2 01_Count_CharStuff_BitStuff.c -o /tmp/character_stuffing
   /tmp/character_stuffing
   For the exam, copy only the selected full program, without selector directives.
*/
#ifndef CN_PROGRAM
#define CN_PROGRAM 1
#endif

#if CN_PROGRAM == 1
/* ================= PROGRAM 1: CHARACTER COUNT ================= */
/* Extracted and corrected: exp1 p1. Only scanf width and strlen cast fixed.
   Original printf format is retained (no separator between count/data). */
#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    printf("Enter a string:");
    scanf("%99s",str);
    printf("%d%s",(int)strlen(str)+1,str);
    return 0;
}

#elif CN_PROGRAM == 2
/* ================= PROGRAM 2: CHARACTER STUFFING ================= */
/* Extracted and corrected: exp1 p3. Declared str used consistently.
   Apparent literal-E payload-copy typo repaired to str[i] (required by FhiF sample).
   scanf bounded; capacity201 allows99 escaped characters + flags + terminator. */
#include <stdio.h>
#include <string.h>
int main(){
    char str[100],stuff[201];
    int i,j=0;
    printf("Enter the data:");
    scanf("%99s",str);
    stuff[j++]='F';
    for(i=0;i<(int)strlen(str);i++){
        if(str[i]=='F'||str[i]=='E'){
            stuff[j++]='E';
        }
        stuff[j++]=str[i];
    }
    stuff[j++]='F';
    stuff[j]='\0';
    printf("Stuffed Data:%s\n",stuff);
    return 0;
}

#elif CN_PROGRAM == 3
/* ================= PROGRAM 3: BIT STUFFING ================= */
/* Extracted and corrected: exp1 p2. Only scanf width bounded; enter binary data. */
#include <stdio.h>
int main(){
    char data[100],stuff[200];
    int i,j=0,cnt=0;
    printf("Enter the bit stream:");
    scanf("%99s",data);
    for(i=0;data[i]!='\0';i++){
        stuff[j++]=data[i];
        if(data[i]=='1'){
            cnt++;
            if(cnt==5){
                stuff[j++]='0';
                cnt=0;
            }
        }else{
            cnt=0;
        }
    }
    stuff[j]='\0';
    printf("Stuffed bit stream:%s\n",stuff);
    return 0;
}

#else
#error "CN_PROGRAM must be1,2 or3"
#endif
