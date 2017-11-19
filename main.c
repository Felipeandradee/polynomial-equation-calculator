#include <stdio.h>
#include <string.h>
#include "AnaSint.h"

int main() {
    int option;

    while (TRUE) {
        system("cls");
        printf("\n\t###########################################");
        printf("\n\t###########################################");
        printf("\n\t##                                       ##");
        printf("\n\t##      -=|Polynomial Calculator|=-      ##");
        printf("\n\t##                                       ##");
        printf("\n\t###########################################");
        printf("\n\t##                                       ##");
        printf("\n\t##              |OPTIONS|                ##");
        printf("\n\t##                                       ##");
        printf("\n\t##  1. Insert a Polynomial               ##");
        printf("\n\t##  2. Print all Polynomials             ##");
        printf("\n\t##  3. Make Operations with Polynomials  ##");
        printf("\n\t##  0. Exit                              ##");
        printf("\n\t##                                       ##");
        printf("\n\t###########################################");
        printf("\n\t###########################################");
        printf("\n");
        printf("\tOPTION: ");
        scanf("%d", &option);

        switch (option){

            case 1:
            {
                printf("\nDigite uma expressao: \n");
                scanf("\n%s", string_entrada);

                equacao();

                printf("\nExpressao esta correta.\n");
                adiciona_funcao();
                p_string = 0;
                memset(&Token, 0, sizeof(Token));
                memset(&funcaoAux, 0, sizeof(funcaoAux));
                system("pause");
                break;
            }

            case 2:
            {
                imprime_funcoes();
                printf("\n");
                system("pause");
                break;
            }

            case 3:
            {
                //TODO: functions to make calculations
                printf("\n\t\t!NOT IMPLEMENTED!\n\n");
                system("pause");

                break;
            }

            case 0:
            {
                exit(1);
            }

            default:
            {
                printf("\n\t\t!INVALID OPTION!\n\n");
                system("pause");
            }
        }
    }

}
