// Aluno: Tallyson Pereira da Silva

typedef struct peso Peso;

Peso *peso_cria(int kg, int g);
void peso_libera(Peso *p);
void peso_acessa(Peso *p, int *kg, int *g);
void peso_atribui(Peso *p, int kg, int g);
void peso_exibe(Peso *p);
char *peso_getPeso(Peso *p);
int peso_compara(Peso *p1, Peso *p2);
Peso *peso_soma(Peso *p, int g);
Peso *peso_copia(Peso *p);