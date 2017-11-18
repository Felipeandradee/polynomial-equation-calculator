#include <stdio.h>
#include "AnaSint.h"

int main() {

    printf("\nDigite a expressao \n");
    scanf("\n%s", string_entrada);

    while(Token.cat != END){
        equacao();
    }
    printf("\nExpressao esta correta.\n");

}
