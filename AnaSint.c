#include "AnaSint.h"

//TODO: Need improve error message.
void erro_sintatico() {
    printf("\nErro sintatico na posicao %d.\n", p_string-1);
    exit(0);
}

int n_exp;
int n_lit;

void equacao() {
    analexico();

    if (Token.cat == FUN) {
        funcaoAux.id = Token.tipo.valor_char;
        analexico();
        if (Token.cat == SN && Token.tipo.codigo == IGUAL) {
            analexico();
            if (!expr()) {
                erro_sintatico();
            }
        } else
            erro_sintatico();

    } else
        erro_sintatico();
}

Boolean expr() {
    n_exp = 0;
    if ((Token.cat == SN && Token.tipo.codigo == SOMA) || (Token.cat == SN && Token.tipo.codigo == SUBTRACAO)) {
        funcaoAux.monomio[n_exp].sinal = Token.tipo.codigo;
        analexico();
    } else
        funcaoAux.monomio[n_exp].sinal = SOMA;

    if (termo()) {
        while ((Token.cat == SN && Token.tipo.codigo == SOMA) || (Token.cat == SN && Token.tipo.codigo == SUBTRACAO)) {
            n_exp++;
            funcaoAux.monomio[n_exp].sinal = Token.tipo.codigo;
            analexico();
            if (!termo())
                erro_sintatico();
        }
    } else
        erro_sintatico();

    return TRUE;
}

Boolean termo() {
    n_lit = 0;
    Boolean eh_termo = FALSE;
    if (Token.cat == NUM) {
        funcaoAux.monomio[n_exp].coeficiente = Token.tipo.valor_int;
        analexico();
        eh_termo = TRUE;
    } else
        funcaoAux.monomio[n_exp].coeficiente = 1;
    while(literal()) {
        eh_termo = TRUE;
        n_lit++;
    }

    return eh_termo;
}

Boolean literal() {

    if(Token.cat == VAR){
        funcaoAux.monomio[n_exp].literal[n_lit].variavel = Token.tipo.valor_char;
        analexico();
        if(Token.cat == SN && Token.tipo.codigo == POTENCIA){
            analexico();
            if(Token.cat == NUM){
                funcaoAux.monomio[n_exp].literal[n_lit].grau = Token.tipo.valor_int;
                analexico();
            } else
                erro_sintatico();
        } else
            funcaoAux.monomio[n_exp].literal[n_lit].grau = 1;
        return TRUE;
    } else
        return FALSE;
}
