/* RECONSTRUCTED: experiment 2 is indexed, but its code page is absent.
   Educational modulo-2 polynomial division, not a named CRC standard. */
#include <stdio.h>
#include <string.h>
int binary(const char s[]) {
    int i;
    for (i = 0; s[i]; i++)
        if (s[i] != '0' && s[i] != '1') return 0;
    return i > 0;
}
void divide(char temp[], const char key[]) {
    int i, j, n = (int)strlen(temp), k = (int)strlen(key);
    for (i = 0; i <= n - k; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < k; j++)
                temp[i+j] = (temp[i+j] == key[j]) ? '0' : '1';
        }
    }
}
int main(void) {
    char data[100], key[32], temp[160], code[160], received[160];
    int i, n, k, error = 0;
    printf("Enter data bits: ");
    if (scanf("%99s", data) != 1) return 1;
    printf("Enter generator bits: ");
    if (scanf("%31s", key) != 1) return 1;
    n = (int)strlen(data);
    k = (int)strlen(key);
    if (!binary(data) || !binary(key) || k < 2 || key[0] != '1' || key[k-1] != '1') {
        printf("Use binary data and a generator of length >= 2 starting/ending with 1.\n");
        return 1;
    }
    strcpy(temp, data);
    for (i = 0; i < k-1; i++) temp[n+i] = '0';
    temp[n+k-1] = '\0';
    divide(temp, key);
    printf("CRC remainder: %s\n", temp+n);
    strcpy(code, data);
    strcat(code, temp+n);
    printf("Transmitted codeword: %s\n", code);
    printf("Enter received codeword: ");
    if (scanf("%159s", received) != 1) return 1;
    if (!binary(received) || (int)strlen(received) != n+k-1) {
        printf("Received word must have %d bits.\n", n+k-1);
        return 1;
    }
    strcpy(temp, received);
    divide(temp, key);
    printf("Receiver remainder: %s\n", temp+n);
    for (i = n; i < n+k-1; i++)
        if (temp[i] == '1') error = 1;
    printf("%s\n", error ? "Error detected." : "No error detected.");
    return 0;
}
