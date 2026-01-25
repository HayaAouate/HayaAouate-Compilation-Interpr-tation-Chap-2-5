#include <stdio.h>

// Déclaration de la fonction externe (écrite dans ton fichier .s)
extern int heron(int a, int b, int c);

int main() {
    printf("--- Test de la fonction Heron (ASM) ---\n\n");

    // Exemple 1 : Le classique triangle rectangle 3-4-5
    // Aire = 6, donc Aire^2 = 36
    int res1 = heron(3, 4, 5);
    printf("Triangle (3, 4, 5)   => Aire au carre : %d\n", res1);

    // Exemple 2 : Triangle rectangle 5-12-13
    // Aire = (5 * 12) / 2 = 30, donc Aire^2 = 900
    int res2 = heron(5, 12, 13);
    printf("Triangle (5, 12, 13)  => Aire au carre : %d\n", res2);

    // Exemple 3 : Triangle rectangle 7-24-25
    // Aire = (7 * 24) / 2 = 84, donc Aire^2 = 7056
    int res3 = heron(7, 24, 25);
    printf("Triangle (7, 24, 25)  => Aire au carre : %d\n", res3);

    return 0;
}