#include "unidade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct unidade
{
    tData *dataFab;
    int lote;
};

Unidade *uni_cria(tData *dataFab, int lote)
{
    Unidade *u = (Unidade *)malloc(sizeof(Unidade));
    int dia, mes, ano;
    if (dataFab)
    {
        dta_acessa(dataFab, &dia, &mes, &ano);
        u->dataFab = dta_cria(dia, mes, ano);
    }
    else
    {
        u->dataFab = dta_cria(1, 1, 2020);
    }
    u->lote = lote;
    return u;
}

void uni_libera(Unidade *u)
{
    if (u)
    {
        dta_libera(u->dataFab);
        free(u);
    }
}

void uni_exibe(Unidade *u)
{
    printf("Data Fab: ");
    dta_exibe(u->dataFab);
    printf(" | Lote: %d\n", u->lote);
}

tData *uni_getDataFab(Unidade *u)
{
    return u->dataFab;
}

int uni_getLote(Unidade *u)
{
    return u->lote;
}

void uni_setDataFab(Unidade *u, tData *dataFab)
{
    int dia, mes, ano;
    dta_acessa(dataFab, &dia, &mes, &ano);
    dta_libera(u->dataFab);
    u->dataFab = dta_cria(dia, mes, ano);
}

void uni_setLote(Unidade *u, int lote)
{
    u->lote = lote;
}

int uni_idade(Unidade *u, tData *dataAlvo)
{
    return dta_diferenca(u->dataFab, dataAlvo);
}

int uni_menor(Unidade *u1, Unidade *u2, tData *dataAlvo)
{
    int idade1 = uni_idade(u1, dataAlvo);
    int idade2 = uni_idade(u2, dataAlvo);
    if (idade1 < idade2)
        return 1;
    else if (idade1 == idade2)
        return u1->lote < u2->lote;
    else
        return 0;
}

char *uni_getUnidade(Unidade *u)
{
    char *dataStr = dta_getData(u->dataFab);
    char *str = (char *)malloc(strlen(dataStr) + 20);
    sprintf(str, "Data: %s | Lote: %d", dataStr, u->lote);
    free(dataStr);
    return str;
}