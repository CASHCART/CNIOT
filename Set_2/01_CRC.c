/* RECONSTRUCTED: experiment 2 is indexed, but its code page is absent.
   Educational modulo-2 polynomial division, not a named CRC standard. */
#include <stdio.h>
#include <string.h>

void divide(char t[], char g[]) {
    int i, j, n = strlen(t), k = strlen(g);

    for (i = 0; i <= n - k; i++)
        if (t[i] == '1')
            for (j = 0; j < k; j++)
                t[i+j] = (t[i+j] == g[j]) ? '0' : '1';
}

int main() {
    char d[100], g[20], t[120], r[120], c[120];
    int i, n, k, e = 0;

    printf("Enter data bits: ");
    scanf("%99s", d);
    printf("Enter generator bits: ");
    scanf("%19s", g);

    n = strlen(d);
    k = strlen(g);

    strcpy(t, d);
    for (i = 0; i < k-1; i++) t[n+i] = '0';
    t[n+k-1] = '\0';

    divide(t, g);
    strcpy(c, d);
    strcpy(c+n, t+n);

    printf("CRC remainder: %s\n", t+n);
    printf("Transmitted codeword: %s\n", c);

    printf("Enter received codeword: ");
    scanf("%119s", r);

    strcpy(t, r);
    divide(t, g);

    printf("Receiver remainder: %s\n", t+strlen(r)-(k-1));

    for (i = strlen(r)-(k-1); i < (int)strlen(r); i++)
        if (t[i] == '1') e = 1;

    printf("%s\n", e ? "Error detected." : "No error detected.");

    return 0;
}