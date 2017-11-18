#include "AnaSint.h"

//TODO: Need improve error message.
void erro_sintatico() {
    printf("\nErro sintatico na posicao %d.\n", p_string-1);
    exit(0);
}

void equacao() {
    analexico();
    if(Token.cat == END) {
        printf("\nExpressao esta correta.\n");
        exit(1);
    }

    if (Token.cat == FUN) {
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
    if ((Token.cat == SN && Token.tipo.codigo == SOMA) || (Token.cat == SN && Token.tipo.codigo == SUBTRACAO)) {
        analexico();
    }
    if (termo()) {
        while ((Token.cat == SN && Token.tipo.codigo == SOMA) || (Token.cat == SN && Token.tipo.codigo == SUBTRACAO)) {
            analexico();
            if (!termo())
                erro_sintatico();
        }
    } else
        erro_sintatico();

    return TRUE;
}

Boolean termo() {
    Boolean eh_termo = FALSE;
    if (Token.cat == NUM) {
        analexico();
        eh_termo = TRUE;
    }
    while(literal()) {
        eh_termo = TRUE;
    }

    return eh_termo;
}

Boolean literal() {
    if(Token.cat == VAR){
        analexico();
        if(Token.cat == SN && Token.tipo.codigo == POTENCIA){
            analexico();
            if(Token.cat == NUM){
                analexico();
            } else
                erro_sintatico();
        }
        return TRUE;
    } else
        return FALSE;
}
