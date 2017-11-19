#ifndef POLYNOMIAL_EQUATION_CALCULATOR_ANASINT_H
#define POLYNOMIAL_EQUATION_CALCULATOR_ANASINT_H

#include "Analex.h"
#include "calculator.h"

typedef
enum {
    FALSE = 0, TRUE = 1
}
        Boolean;

void erro_sintatico();
void equacao();
Boolean expr();
Boolean termo();
Boolean literal();

#endif //POLYNOMIAL_EQUATION_CALCULATOR_ANASINT_H
