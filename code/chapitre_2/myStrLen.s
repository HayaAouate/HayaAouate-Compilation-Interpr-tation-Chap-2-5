.text
        .globl myStrLen

myStrLen:
        pushl   %ebp            # Mise en place du cadre de pile
        movl    %esp, %ebp
        
        movl    8(%ebp), %edx   # Récupère l'adresse de la chaîne (1er argument)
        xorl    %eax, %eax      # Met le compteur (eax) à 0

boucle:
        cmpb    $0, (%edx)      # Compare l'octet pointé par edx avec 0 (fin de chaîne)
        je      fin             # Si c'est 0, on a fini
        
        incl    %eax            # Incrémente le compteur de longueur
        incl    %edx            # Passe au caractère suivant
        jmp     boucle          # Recommence

fin:
        popl    %ebp            # Restaure la pile
        ret                     # Renvoie le résultat (qui est dans eax)

