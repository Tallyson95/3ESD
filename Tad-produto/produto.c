// Aluno: Tallyson Pereira da Silva
#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    char *ident;
    char *codBarras;
    float preco;
    int qtUnidades;
    Unidade **unidades;
};

Produto *prod_cria(const char *ident, const char *codBarras, float preco, int qtUnidades)
{
    Produto *p = (Produto *)malloc(sizeof(Produto));
    p->ident = strdup(ident ? ident : "Produto");
    p->codBarras = strdup(codBarras ? codBarras : "");
    p->preco = preco;
    p->qtUnidades = qtUnidades;
    p->unidades = (Unidade **)malloc(qtUnidades * sizeof(Unidade *));
    for (int i = 0; i < qtUnidades; i++)
        p->unidades[i] = NULL;
    return p;
}

void prod_libera(Produto *p)
{
    if (p)
    {
        free(p->ident);
        free(p->codBarras);
        for (int i = 0; i < p->qtUnidades; i++)
            if (p->unidades[i])
                uni_libera(p->unidades[i]);
        free(p->unidades);
        free(p);
    }
}

void prod_exibe(Produto *p)
{
    printf("Identificação: %s | Código: %s | Preço: %.2f | Qtde: %d\n", p->ident, p->codBarras, p->preco, p->qtUnidades);
    for (int i = 0; i < p->qtUnidades; i++)
    {
        printf("  Unidade %d: ", i + 1);
        if (p->unidades[i])
            uni_exibe(p->unidades[i]);
        else
            printf("NULL\n");
    }
}

int prod_ehSemelhante(Produto *p1, Produto *p2)
{
    return strcmp(p1->ident, p2->ident) == 0;
}

void prod_reajuste(Produto *p, float percentual)
{
    p->preco = p->preco * (1.0 - percentual / 100.0);
}

char *prod_getIdent(Produto *p) { return p->ident; }
char *prod_getCodBarras(Produto *p) { return p->codBarras; }
float prod_getPreco(Produto *p) { return p->preco; }
int prod_getQtUnidades(Produto *p) { return p->qtUnidades; }
Unidade **prod_getUnidades(Produto *p) { return p->unidades; }

void prod_setIdent(Produto *p, const char *ident)
{
    free(p->ident);
    p->ident = strdup(ident);
}
void prod_setCodBarras(Produto *p, const char *codBarras)
{
    free(p->codBarras);
    p->codBarras = strdup(codBarras);
}
void prod_setPreco(Produto *p, float preco) { p->preco = preco; }
void prod_setQtUnidades(Produto *p, int qtUnidades) { p->qtUnidades = qtUnidades; }
void prod_setUnidade(Produto *p, int idx, Unidade *u) { p->unidades[idx] = u; }

char *prod_getProduto(Produto *p)
{
    char *str = (char *)malloc(256);
    sprintf(str, "Ident: %s | Código: %s | Preço: %.2f | Qtde: %d", p->ident, p->codBarras, p->preco, p->qtUnidades);
    return str;
}

int prod_iguais(Produto *p1, Produto *p2)
{
    if (strcmp(p1->ident, p2->ident) != 0)
        return 0;
    if (strcmp(p1->codBarras, p2->codBarras) != 0)
        return 0;
    if (p1->preco != p2->preco)
        return 0;
    if (p1->qtUnidades != p2->qtUnidades)
        return 0;

    for (int i = 0; i < p1->qtUnidades; i++)
    {
        if (!p1->unidades[i] || !p2->unidades[i])
            return 0;
        if (uni_getLote(p1->unidades[i]) != uni_getLote(p2->unidades[i]))
            return 0;
        tData *d1 = uni_getDataFab(p1->unidades[i]);
        tData *d2 = uni_getDataFab(p2->unidades[i]);
        int dia1, mes1, ano1, dia2, mes2, ano2;
        dta_acessa(d1, &dia1, &mes1, &ano1);
        dta_acessa(d2, &dia2, &mes2, &ano2);
        if (dia1 != dia2 || mes1 != mes2 || ano1 != ano2)
            return 0;
    }
    return 1;
}