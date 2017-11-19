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

        equacao();

        printf("\nExpressao esta correta.\n");
        adiciona_funcao();
        p_string = 0;
        memset(&Token, 0, sizeof(Token));
        memset(&funcaoAux, 0, sizeof(funcaoAux));
    };

}
