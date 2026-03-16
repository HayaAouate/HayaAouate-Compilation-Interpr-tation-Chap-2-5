/* dc-elem.c
 * * Un analyseur syntaxique elementaire pour montrer l'analyseur lexical.
 * Avec la lecture ligne par ligne
 * * VERSION MODIFIEE POUR EXERCICE 4.3 (Ajout -, *, /, %)
 */

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <assert.h>
# include <setjmp.h>

# define Nombre 256 // renvoye par yylex pour signaler un nombre
# define MaxLigne 4096 // longueur maximum d'une ligne

int yylval; // valeur du mot lu (le cas echeant)

jmp_buf reprise; // pour reprendre apres erreur

char ligne[MaxLigne]; // la derniere ligne lue
int iligne = 0; // l' index du prochain caractere a traiter

/* erreur -- en cas d'erreur, reprise ou sortie */
void
erreur(char * message){
    fprintf ( stderr, "%s\n", message);
# if 1
    // ignorer la fin de la ligne
    ligne[ iligne ] = 0;
    longjmp(reprise, 1);
# else
    // arreter le programme
    exit (1) ;
# endif
}

/* yylex -- lire le mot suivant */
int
yylex(void){
    int c;

    // si la ligne courante est terminée, lire la suivante
    if ( ligne[ iligne ] == 0){
        iligne = 0;
        if ( fgets ( ligne, sizeof ligne, stdin) == 0)
            return 0;
    }

    while(ligne[iligne ] == ' ' ) // sauter les espaces
        iligne += 1;
    c = ligne[ iligne ++];

    if (c == '#') { // commentaire
        while(ligne[iligne ] != '\n' && ligne[iligne] != 0)
            iligne += 1;
        c = ligne[ iligne ++];
    }

    // MODIFICATION : ajout de -, *, / et % comme mots reconnus
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '\n' || c == 0) // un mot a lui tout seul
        return c;

    if ( isdigit (c) ) { // debut d'un nombre
# if 1
        // conversion par le programme
        yylval = c - '0';
        while(isdigit ( ligne[ iligne ]) )
            yylval = yylval * 10 + ligne[ iligne ++] - '0';
# endif
        return Nombre;
    }

    erreur("caractère invalide");
    return 0; // pour eviter un warning
}

/* yyparse -- l' analyseur syntaxique */
int
yyparse(void){
    int gauche, droit, operation, resultat ;
    int t;

    setjmp(reprise);

    for(;;) {
        // afficher le prompt
        printf ("? ");

        // premier mot : la fin ou le premier nombre
        t = yylex();
        if ( t == 0){
            printf ("Ciao\n");
            return 0;
        }
        if ( t != Nombre)
            erreur("erreur de syntaxe");
        gauche = yylval;

        // operateur
        t = yylex();
        // MODIFICATION : accepte désormais les autres opérateurs usuels
        if ( t != '+' && t != '-' && t != '*' && t != '/' && t != '%')
            erreur("erreur de syntaxe");
        operation = t;

        // deuxième nombre
        t = yylex();
        if ( t != Nombre)
            erreur("erreur de syntaxe");
        droit = yylval;

        // fin de ligne
        t = yylex(); 
        if ( t != '\n')
            erreur("erreur de syntaxe");

        // MODIFICATION : effectuer l' operation correspondante
        if ( operation == '+')
            resultat = gauche + droit;
        else if ( operation == '-')
            resultat = gauche - droit;
        else if ( operation == '*')
            resultat = gauche * droit;
        else if ( operation == '/') {
            if (droit == 0) erreur("division par zéro");
            resultat = gauche / droit;
        }
        else if ( operation == '%') {
            if (droit == 0) erreur("modulo par zéro");
            resultat = gauche % droit;
        }
        else
            assert (0) ;

        printf ("= %d\n", resultat);
    }
}

int
main(){
    return yyparse();
}