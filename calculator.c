#include "calculator.h"

int n_fun = 0;

int pesquisa_funcao(char id){
    int n = 0;
    while (funcoes[n].id != '\0') {
        if(funcoes[n].id == id){
            return n;
        }
        n++;
    }
    return -1;
}

void adiciona_funcao() {
    if(pesquisa_funcao(funcaoAux.id) != -1){
        printf("\nJa existe uma funcao %c\n", funcaoAux.id);
        return;
    }
    funcoes[n_fun] = funcaoAux;
    n_fun++;
}

void imprime_funcoes() {
    int n = 0;
    while (funcoes[n].id != '\0') {
        int i = 0;
        printf("\n%c=", funcoes[n].id);
        while (funcoes[n].monomio[i].sinal != 0) {
            if (i != 0 && funcoes[n].monomio[i].sinal == SOMA)
                printf("+");
            else if (funcoes[n].monomio[i].sinal == SUBTRACAO)
                printf("-");
            printf("%d", funcoes[n].monomio[i].coeficiente);
            int j = 0;
            while (funcoes[n].monomio[i].literal[j].variavel != '\0') {
                printf("%c", funcoes[n].monomio[i].literal[j].variavel);
                if (funcoes[n].monomio[i].literal[j].grau != 1) {
                    printf("^");
                    printf("%d", funcoes[n].monomio[i].literal[j].grau);
                }
                j++;
            }
            i++;
        }
        n++;
    }
}