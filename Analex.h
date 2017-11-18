#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define TAM 1001

char string_entrada[TAM];
int p_string;

typedef enum {
    NUM, VAR, FUN, SN, END
} Categoria;

typedef enum {
    IGUAL,
    POTENCIA,
    MULTIPLICACAO,
    DIVISAO,
    SOMA,
    SUBTRACAO,
    ABRE_PARENTESES,
    FECHA_PARENTESES
} Sinais;


typedef struct t {
    Categoria cat;

    union {
        char valor_char;
        int codigo;
        int valor_int;
    } tipo;
} TOKEN;

char ch;

TOKEN Token;

void error_lexico();

void montaToken(Categoria cat, char token[], int pos);

void analexico();

#endif
