#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPrime(int n) {
    int i;
    int m = n / 2;

    for (i = 2; i <= m; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int findGCD(int n1, int n2) {
    int i, gcd;

    for(i = 1; i <= n1 && i <= n2; ++i) {
        if(n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }

    return gcd;
}

int powMod(int a, int b, int n) {
    long long x = 1, y = a;

    while (b > 0) {
        if (b % 2 == 1)
            x = (x * y) % n;
        y = (y * y) % n;
        b /= 2;
    }

    return x % n;
}

int main(int argc, char* argv[]) {
    int p, q;
    int n, phin;

    int data, cipher, decrypt;

    while (1) {
        printf("Entrer deux nombres premiers: ");
        scanf("%d %d", &p, &q);

        if (!(checkPrime(p) && checkPrime(q)))
            printf("Merci d'entrer uniquement des nombres premiers...\n");
        else if (!checkPrime(p))
            printf("Merci d'entrer uniquement des nombres premiers...\n");
        else if (!checkPrime(q))
            printf("Merci d'entrer uniquement des nombres premiers...\n");
        else
            break;
    }

    n = p * q;

    phin = (p - 1) * (q - 1);

    int e = 0;
    for (e = 5; e <= 100; e++) {
        if (findGCD(phin, e) == 1)
            break;
    }

    int d = 0;
    for (d = e + 1; d <= 100; d++) {
        if ( ((d * e) % phin) == 1)
            break;
    }

    printf("Valeur de e: %d\nValeur de d: %d\n", e, d);

    printf("Enter votre message numerique: ");
    scanf("%d", &data);

    cipher = powMod(data, e, n);
    printf("Le text chiffre est: %d\n", cipher);

    decrypt = powMod(cipher, d, n);
    printf("Le texte d'origine est: %d\n", decrypt);
    return 0;
}
