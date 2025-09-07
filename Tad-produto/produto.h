#include "unidade.h"

typedef struct produto Produto;

Produto *prod_cria(const char *ident, const char *codBarras, float preco, int qtUnidades);
void prod_libera(Produto *p);
void prod_exibe(Produto *p);
int prod_ehSemelhante(Produto *p1, Produto *p2);
void prod_reajuste(Produto *p, float percentual);
char *prod_getIdent(Produto *p);
char *prod_getCodBarras(Produto *p);
float prod_getPreco(Produto *p);
int prod_getQtUnidades(Produto *p);
Unidade **prod_getUnidades(Produto *p);
void prod_setIdent(Produto *p, const char *ident);
void prod_setCodBarras(Produto *p, const char *codBarras);
void prod_setPreco(Produto *p, float preco);
void prod_setQtUnidades(Produto *p, int qtUnidades);
void prod_setUnidade(Produto *p, int idx, Unidade *u);
char *prod_getProduto(Produto *p);
int prod_iguais(Produto *p1, Produto *p2);