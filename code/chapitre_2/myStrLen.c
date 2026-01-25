#include <stdio.h>

// Déclaration de la fonction assembleur
extern int myStrLen(char *s);

int main() {
    char *s1 = "Hello";      // Longueur 5
    char *s2 = "Assembleur"; // Longueur 10
    char *s3 = "";           // Longueur 0

    printf("=== TEST MYSTRLEN ===\n\n");
    
    printf("Chaine: '%s' -> Longueur: %d\n", s1, myStrLen(s1));
    printf("Chaine: '%s' -> Longueur: %d\n", s2, myStrLen(s2));
    printf("Chaine: '%s' -> Longueur: %d\n", s3, myStrLen(s3));

    return 0;
}