#include <stdio.h>
#include <string.h>
#include "AnaSint.h"

int main() {

    while (TRUE) {
        printf("\nDigite uma expressao: \n");
        scanf("\n%s", string_entrada);

        if (!strcmp(string_entrada, "-1")) {
            system("cls");
            imprime_funcoes();
            exit(1);
        }

        while (Token.cat != END) {
            equacao();
        }
        printf("\nExpressao esta correta.\n");
        adiciona_funcao();
        Token.cat = 0;
        p_string = 0;
    };

}
