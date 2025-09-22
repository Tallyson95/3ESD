#include <stdio.h>
#include "LDECC.h"

int main(void)
{
    tListaDE *pL;
    pL = listaDE_cria(1, 0); // classificada, sem repetição
    listaDE_imprime(pL);
    listaDE_inclui(pL, 10);
    listaDE_inclui(pL, 10);
    listaDE_inclui(pL, 10);
    listaDE_inclui(pL, 1);
    listaDE_inclui(pL, 100);
    listaDE_inclui(pL, 1);
    listaDE_imprime(pL);
    listaDE_inclui(pL, 100);
    listaDE_inclui(pL, 100);
    listaDE_exclui(pL, 10);
    listaDE_imprime(pL);

    listaDE_libera(pL); // Libera toda a memória da lista

    return 0;
}