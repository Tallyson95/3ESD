#include "produto.h"
#include "data.h"
#include <stdio.h>

int main()
{
    tData *dataAlvo = dta_cria(10, 9, 2025);

    Produto *produtos[2];
    produtos[0] = prod_cria("PS4", "SONY-PS4-001", 2500.0, 3);
    produtos[1] = prod_cria("PS5", "SONY-PS5-002", 4000.0, 2);

    // Unidades do PS4
    prod_setUnidade(produtos[0], 0, uni_cria(dta_cria(7, 9, 2025), 101));
    prod_setUnidade(produtos[0], 1, uni_cria(dta_cria(1, 9, 2025), 102));
    prod_setUnidade(produtos[0], 2, uni_cria(dta_cria(1, 8, 2025), 103));

    // Unidades do PS5
    prod_setUnidade(produtos[1], 0, uni_cria(dta_cria(8, 9, 2025), 201));
    prod_setUnidade(produtos[1], 1, uni_cria(dta_cria(1, 7, 2025), 202));

    for (int i = 0; i < 2; i++)
    {
        printf("\nProduto: %s\n", prod_getIdent(produtos[i]));
        for (int j = 0; j < prod_getQtUnidades(produtos[i]); j++)
        {
            Unidade *u = prod_getUnidades(produtos[i])[j];
            int dias = uni_idade(u, dataAlvo);
            if (dias <= 0)
            {
                printf("  Unidade %d vence na data alvo: ", j + 1);
                uni_exibe(u);
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        int desconto = 0;
        for (int j = 0; j < prod_getQtUnidades(produtos[i]); j++)
        {
            Unidade *u = prod_getUnidades(produtos[i])[j];
            int dias = uni_idade(u, dataAlvo);
            if (dias <= 3 && dias >= 0)
            {
                desconto = 1;
                break;
            }
        }
        if (desconto)
        {
            prod_reajuste(produtos[i], 25.0);
            printf("\nDesconto aplicado ao produto %s! Novo preço: %.2f\n", prod_getIdent(produtos[i]), prod_getPreco(produtos[i]));
        }
    }

    for (int i = 0; i < 2; i++)
        prod_libera(produtos[i]);
    dta_libera(dataAlvo);

    return 0;
}