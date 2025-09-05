#include "tad-pessoaimc.h"
#include <stdio.h>

int main()
{
    PessoaIMC *vetor[4];

    vetor[0] = pessoa_cria("Ana", alt_cria(1, 65), peso_cria(60, 0));
    vetor[1] = pessoa_cria("Beto", alt_cria(1, 70), peso_cria(80, 0));
    vetor[2] = pessoa_cria("Carla", alt_cria(1, 60), peso_cria(45, 0));
    vetor[3] = pessoa_cria("Davi", alt_cria(1, 75), peso_cria(110, 0));

    printf("Pessoas que estão aptas para o emprego: \n");
    for (int i = 0; i < 4; i++)
    {
        float imc = pessoa_calculaIMC(vetor[i]);
        char *cat = pessoa_categoriaIMC(vetor[i]);
        if (imc >= 18.5 && imc < 30.0)
        {
            pessoa_exibe(vetor[i]);
        }
    }

    for (int i = 0; i < 4; i++)
        pessoa_libera(vetor[i]);
    return 0;
}