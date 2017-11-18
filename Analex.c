#include <stdio.h>
#include <ctype.h>
#include <mem.h>
#include "Analex.h"

int p_string = 0;

char pSinais[100][18] = {
        {"igual"},
        {"potencia"},
        {"multiplicacao"},
        {"divisao"},
        {"soma"},
        {"subtracao"},
        {"abre_parenteses"},
        {"fecha_parenteses"}
};

void error_lexico() {
    printf("\nErro lexico no caracter %c\n", ch);
    exit(1);
}

void montaToken(Categoria cat, char token[], int pos) {
    int convert;

    switch (cat) {

        case NUM: {
            convert = atoi(token);
            printf("<NUM, %d>\n", convert);
            Token.cat = cat;
            Token.tipo.valor_int = convert;
            break;
        }

        case VAR: {
            printf("<VAR, %s>\n", token);
            Token.cat = cat;
            Token.tipo.valor_char = token[0];
            break;
        }

        case FUN: {
            printf("<FUN, %s>\n", token);
            Token.cat = cat;
            Token.tipo.valor_char = token[0];
            break;
        }

        case SN: {
            printf("<SN, %s>\n", pSinais[pos]);
            Token.cat = cat;
            Token.tipo.valor_char = token[0];
            break;
        }

    }
}

void analexico() {
    int estado = 0;
    char lexema[TAM];
    int cont = 0;
    ch = string_entrada[p_string];
    p_string++;

    while (1) {

        switch (estado) {
            case 0: {
                memset(lexema, 0, TAM);
                cont = 0;

                if (ch == '\0') {
                    Token.cat = END;
                    return;
                } else if (isdigit(ch)) {
                    estado = 1;
                    lexema[cont] = ch;
                    cont++;
                } else if (islower(ch)) {
                    estado = 3;
                    lexema[cont] = ch;
                } else if (isupper(ch)) {
                    estado = 4;
                    lexema[cont] = ch;
                } else if ((ch == '=') || (ch == '^') || (ch == '*')
                           || (ch == '/') || (ch == '+') || (ch == '-')
                           || (ch == '(') || (ch == ')')) {
                    estado = 5;
                } else {
                    error_lexico();
                }

                break;
            }
            case 1: {
                ch = string_entrada[p_string];
                if (isdigit(ch)) {
                    estado = 1;
                    lexema[cont] = ch;
                    cont++;
                    p_string++;
                } else {
                    estado = 2;
                }
                break;
            }
            case 2: {
                montaToken(NUM, lexema, 0);
                return;
            }
            case 3: {
                montaToken(VAR, lexema, 0);
                return;
            }
            case 4: {
                montaToken(FUN, lexema, 0);
                return;
            }
            case 5: {
                char str[2];
                str[0] = ch;
                str[1] = '\0';
                if (ch == '=') {
                    montaToken(SN, str, IGUAL);
                } else if (ch == '^') {
                    montaToken(SN, str, POTENCIA);
                } else if (ch == '*') {
                    montaToken(SN, str, MULTIPLICACAO);
                } else if (ch == '/') {
                    montaToken(SN, str, DIVISAO);
                } else if (ch == '+') {
                    montaToken(SN, str, SOMA);
                } else if (ch == '-') {
                    montaToken(SN, str, SUBTRACAO);
                } else if (ch == '(') {
                    montaToken(SN, str, ABRE_PARENTESES);
                } else if (ch == ')') {
                    montaToken(SN, str, FECHA_PARENTESES);
                } else {
                    error_lexico();
                }
                return;
            }
        }
    }
}
