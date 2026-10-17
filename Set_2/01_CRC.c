/* RECONSTRUCTED: experiment 2 is indexed, but its code page is absent.
   Educational modulo-2 polynomial division, not a named CRC standard. */
#include <stdio.h>
#include <string.h>

int main() {
    char d[100], g[20], t[120], r[120];
    int i, j, n, k, e = 0;

    printf("Enter data bits: ");
    scanf("%s", d);
    printf("Enter generator bits: ");
    scanf("%s", g);

    n = strlen(d);
    k = strlen(g);

    strcpy(t, d);
    for (i = 0; i < k - 1; i++) t[n+i] = '0';
    t[n+k-1] = '\0';

    for (i = 0; i <= n-k; i++)
        if (t[i] == '1')
            for (j = 0; j < k; j++)
                t[i+j] = (t[i+j] == g[j]) ? '0' : '1';

    printf("CRC remainder: %s\n", t+n);

    strcpy(d+n, t+n);
    printf("Transmitted codeword: %s\n", d);

    printf("Enter received codeword: ");
    scanf("%s", r);
    strcpy(t, r);

    for (i = 0; i <= (int)strlen(r)-k; i++)
        if (t[i] == '1')
            for (j = 0; j < k; j++)
                t[i+j] = (t[i+j] == g[j]) ? '0' : '1';

    printf("Receiver remainder: %s\n", t+strlen(r)-k+1);

    for (i = strlen(r)-k+1; i < (int)strlen(r); i++)
        if (t[i] == '1') e = 1;

    printf("%s\n", e ? "Error detected." : "No error detected.");
    return 0;
}
