// Aluno: Tallyson Pereira da Silva

#include "tad-pessoaimc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa
{
    char *nome;
    Altura *altura;
    Peso *peso;
};

PessoaIMC *pessoa_cria(char *nome, Altura *altura, Peso *peso)
{
    PessoaIMC *p = (PessoaIMC *)malloc(sizeof(PessoaIMC));
    p->nome = (char *)malloc(strlen(nome) + 1);
    strcpy(p->nome, nome);
    p->altura = alt_copia(altura);
    p->peso = peso_copia(peso);
    return p;
}

void pessoa_libera(PessoaIMC *p)
{
    free(p->nome);
    alt_libera(p->altura);
    peso_libera(p->peso);
    free(p);
}

void pessoa_exibe(PessoaIMC *p)
{
    printf("Nome: %s | Altura: ", p->nome);
    alt_exibe(p->altura);
    printf(" | Peso: ");
    peso_exibe(p->peso);
    printf(" | IMC: %.2f | Categoria: %s\n", pessoa_calculaIMC(p), pessoa_categoriaIMC(p));
}

void pessoa_alteraPeso(PessoaIMC *p, int g)
{
    Peso *novo = peso_soma(p->peso, g);
    peso_libera(p->peso);
    p->peso = novo;
}

void pessoa_alteraAltura(PessoaIMC *p, int cm)
{
    Altura *nova = alt_soma(p->altura, cm);
    alt_libera(p->altura);
    p->altura = nova;
}

float pessoa_calculaIMC(PessoaIMC *p)
{
    int m, cm, kg, g;
    alt_acessa(p->altura, &m, &cm);
    peso_acessa(p->peso, &kg, &g);
    float altura_m = m + ((float)cm / 100);
    float peso_kg = kg + ((float)g / 1000);
    if (altura_m <= 0)
        return 0;
    return peso_kg / (altura_m * altura_m);
}

char *pessoa_categoriaIMC(PessoaIMC *p)
{
    float imc = pessoa_calculaIMC(p);
    if (imc < 18.5)
        return "Abaixo do peso";
    else if (imc < 25.0)
        return "Normal";
    else if (imc < 30.0)
        return "Sobrepeso";
    else
        return "Obesidade";
}