#ifndef POLYNOMIAL_EQUATION_CALCULATOR_CALCULATOR_H
#define POLYNOMIAL_EQUATION_CALCULATOR_CALCULATOR_H

#include "Analex.h"
#include "AnaSint.h"

typedef struct l {
    char variavel;
    int grau;
} LITERAL;

typedef struct m {
    Sinais sinal;
    int coeficiente;
    LITERAL literal[10];
} MONOMIO;

typedef struct f {
    char id;
    MONOMIO monomio[10];
} FUNCAO;


FUNCAO funcoes[10];
FUNCAO funcaoAux;
FUNCAO funcao_resultado;
int n_fun;

void adiciona_funcao();
void imprime_funcoes();
int pesquisa_funcao(char id);

#endif //POLYNOMIAL_EQUATION_CALCULATOR_CALCULATOR_H
