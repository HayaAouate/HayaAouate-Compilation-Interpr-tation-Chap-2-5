#include <stdio.h>

// On déclare la fonction externe écrite en assembleur
extern long median3(long a, long b, long c);

int main() {
    printf("--- Exercice 2.2 : Test de la fonction Median3 ---\n");

    // Test 1 : Médiane au milieu
    printf("Test 1 (10, 20, 30) : Resultat = %ld\n", median3(10, 20, 30));

    // Test 2 : Médiane en première position
    printf("Test 2 (25, 10, 30) : Resultat = %ld\n", median3(25, 10, 30));

    // Test 3 : Médiane en dernière position
    printf("Test 3 (10, 40, 25) : Resultat = %ld\n", median3(10, 40, 25));

    return 0;
}