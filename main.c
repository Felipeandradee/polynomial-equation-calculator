#include <stdio.h>
#include "Analex.h"

int main() {

    printf("\nDigite a expressao \n");
    scanf("\n%s", string_entrada);
//
//    printf("\nExpressao: %s\n", string_entrada);
    while(Token.cat != END){
        analexico();
    }

}
