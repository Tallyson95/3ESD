// Aluno: Tallyson Pereira da Silva

#include "tad-peso.h"
#include <stdio.h>
#include <stdlib.h>

struct peso
{
    int kg, g;
};

int converteParaGr(Peso *p) { return p->kg * 1000 + p->g; }

Peso *peso_cria(int kg, int g)
{
    Peso *p = (Peso *)malloc(sizeof(Peso));
    if (p == NULL)
    {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    p->kg = kg;
    p->g = g;
    return p;
}

void peso_libera(Peso *p) { free(p); }

void peso_acessa(Peso *p, int *kg, int *g)
{
    *kg = p->kg;
    *g = p->g;
}

void peso_atribui(Peso *p, int kg, int g)
{
    p->kg = kg;
    p->g = g;
}

void peso_exibe(Peso *p)
{
    printf("%d,%03dg", p->kg, p->g);
}

char *peso_getPeso(Peso *p)
{
    char *pt = (char *)malloc(16);
    sprintf(pt, "%d,%03dg", p->kg, p->g);
    return pt;
}

int peso_compara(Peso *p1, Peso *p2)
{
    return converteParaGr(p1) - converteParaGr(p2);
}

Peso *peso_soma(Peso *p, int g)
{
    int total_g = converteParaGr(p) + g;
    int novos_kg = total_g / 1000;
    int novos_g = total_g % 1000;
    return peso_cria(novos_kg, novos_g);
}

Peso *peso_copia(Peso *p)
{
    if (p == NULL)
        return NULL;
    return peso_cria(p->kg, p->g);
}