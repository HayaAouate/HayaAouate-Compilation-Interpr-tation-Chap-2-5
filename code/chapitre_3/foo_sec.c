#include <stdio.h>
void
foo(int x){
if ( x == x + 1)
printf ("Hello\n") ; // jamais exécuté
}