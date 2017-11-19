#include "calculator.h"

int n_fun = 0;

void adiciona_funcao() {
//    TODO: search if has any function with a same id
    funcoes[n_fun] = funcaoAux;
    n_fun++;
}

void imprime_funcoes(){
//    TODO: print more informations
    int n=0;
    while (funcoes[n].id != '\0') {
        printf("\n%c", funcoes[n].id);
        n++;
    }
}