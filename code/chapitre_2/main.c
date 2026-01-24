#include <stdio.h>

/* Déclaration des quatre variables globales  */
int a, b, c, delta;

/*La fonction assembleur */
extern void delta_func();

void tester(int vA, int vB, int vC) {
    a = vA;
    b = vB;
    c = vC;
    
    delta_func(); // La fonction assembleur modifie la variable 'delta'
    
    printf("Test avec a=%d, b=%d, c=%d\n", a, b, c);
    printf("Resultat delta = %d\n", delta);
    printf("----------------------------\n");
}

int main() {
    printf("=== CALCUL ===\n\n");
    
    tester(1, 5, 4);  // Cas positif (9)
    tester(1, 2, 1);  // Cas nul (0)
    tester(2, 4, 8);  // Cas négatif (-48)
    
    return 0;
}