#include <stdio.h>
#include <stdlib.h>

// Définition des types de nœuds
#define NBRE 258

// Structure de l'arbre syntaxique
typedef struct node {
    int type;           // '+' , '-' , '*' , '/' , NBRE
    int val;            // Pour les nombres
    struct node *fg;    // Fils gauche
    struct node *fd;    // Fils droit
} Node;

// --- FONCTIONS DE GESTION DE L'ARBRE ---

Node* creer_noeud(int type, Node* g, Node* d, int valeur) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) exit(1);
    n->type = type;
    n->fg = g;
    n->fd = d;
    n->val = valeur;
    return n;
}

int priorite(Node* n) {
    if (n == NULL) return 100;
    if (n->type == NBRE) return 10;   // Les nombres sont prioritaires (atomes)
    if (n->type == '*' || n->type == '/') return 2;
    if (n->type == '+' || n->type == '-') return 1;
    return 0;
}



void afficher_intelligent(Node* n) {
    if (n == NULL) return;

    if (n->type == NBRE) {
        printf("%d", n->val);
        return;
    }

    // Gestion du fils GAUCHE
    // On met des parenthèses si le fils est moins prioritaire que l'opérateur actuel
    int p_g = (priorite(n->fg) < priorite(n));
    if (p_g) printf("(");
    afficher_intelligent(n->fg);
    if (p_g) printf(")");

    // Affichage de l'opérateur
    printf(" %c ", n->type);

    // Gestion du fils DROIT
    int p_d = (priorite(n->fd) < priorite(n));
    
    // Règle d'associativité pour éviter les erreurs sur '-' et '/'
    // Exemple : 1 - (2 - 3) doit garder ses parenthèses
    if (priorite(n->fd) == priorite(n) && (n->type == '-' || n->type == '/')) {
        p_d = 1;
    }

    if (p_d) printf("(");
    afficher_intelligent(n->fd);
    if (p_d) printf(")");
}


int main() {
    printf("Tests des exemples de l'exercice 5.2 :\n\n");

    // Exemple : (1 + (2 + 3)) -> 1 + 2 + 3
    Node* ex1 = creer_noeud('+', creer_noeud(NBRE, NULL, NULL, 1), 
                               creer_noeud('+', creer_noeud(NBRE, NULL, NULL, 2), 
                                              creer_noeud(NBRE, NULL, NULL, 3), 0), 0);
    printf("(1 + (2 + 3)) \t -> ");
    afficher_intelligent(ex1); printf("\n");

    // Exemple : 1 * (2 + 3) -> 1 * (2 + 3)
    Node* ex2 = creer_noeud('*', creer_noeud(NBRE, NULL, NULL, 1), 
                               creer_noeud('+', creer_noeud(NBRE, NULL, NULL, 2), 
                                              creer_noeud(NBRE, NULL, NULL, 3), 0), 0);
    printf("1 * (2 + 3) \t -> ");
    afficher_intelligent(ex2); printf("\n");

    // Exemple : 1 + (2 * 3) -> 1 + 2 * 3
    Node* ex3 = creer_noeud('+', creer_noeud(NBRE, NULL, NULL, 1), 
                               creer_noeud('*', creer_noeud(NBRE, NULL, NULL, 2), 
                                              creer_noeud(NBRE, NULL, NULL, 3), 0), 0);
    printf("1 + (2 * 3) \t -> ");
    afficher_intelligent(ex3); printf("\n");

    return 0;
}