#include "data.h"

typedef struct unidade Unidade;

Unidade *uni_cria(tData *dataFab, int lote);
void uni_libera(Unidade *u);
void uni_exibe(Unidade *u);
tData *uni_getDataFab(Unidade *u);
int uni_getLote(Unidade *u);
void uni_setDataFab(Unidade *u, tData *dataFab);
void uni_setLote(Unidade *u, int lote);
int uni_idade(Unidade *u, tData *dataAlvo);
int uni_menor(Unidade *u1, Unidade *u2, tData *dataAlvo);
char *uni_getUnidade(Unidade *u);