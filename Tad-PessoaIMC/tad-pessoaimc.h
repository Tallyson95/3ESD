// Aluno: Tallyson Pereira da Silva

#include "tad-altura.h"
#include "tad-peso.h"

typedef struct pessoa PessoaIMC;

PessoaIMC *pessoa_cria(char *nome, Altura *altura, Peso *peso);
void pessoa_libera(PessoaIMC *p);
void pessoa_exibe(PessoaIMC *p);
void pessoa_alteraPeso(PessoaIMC *p, int g);
void pessoa_alteraAltura(PessoaIMC *p, int cm);
float pessoa_calculaIMC(PessoaIMC *p);
char *pessoa_categoriaIMC(PessoaIMC *p);