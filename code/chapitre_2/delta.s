.text
        .globl delta_func

delta_func:
        pushl   %ebx            # SAUVEGARDE ebx (obligatoire en 32 bits)

        # Calcul de b^2
        movl    b, %eax
        imull   b, %eax         # %eax = b*b

        # Calcul de 4ac
        movl    a, %ebx
        imull   c, %ebx         # %ebx = a*c
        imull   $4, %ebx        # %ebx = 4ac

        # Soustraction
        subl    %ebx, %eax      # %eax = b^2 - 4ac

        # Stockage
        movl    %eax, delta

        popl    %ebx            # RESTAURE ebx avant de quitter
        ret