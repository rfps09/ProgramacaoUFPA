#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int altura;
    int peso;
    char endereco[150];
} criminoso;

typedef struct {
    int altura_estimada;
    int peso_estimado;
    char descricao_do_crime[150];
} crime_nao_resolvido;

void resolve_case(crime_nao_resolvido crime, criminoso *suspeitos, int qtd_suspeitos) {
    for(int i=0; i<qtd_suspeitos; i++) {
        if( suspeitos[i].altura >= crime.altura_estimada-5 && suspeitos[i].altura <= crime.altura_estimada+5
            &&
            suspeitos[i].peso >= crime.peso_estimado-5 && suspeitos[i].peso <= crime.peso_estimado+5
        )
        {
            printf("Suspeito: %s\n", suspeitos[i].nome);
        }
    }
}

int main() {
    criminoso criminosos_conhecidos[100];

    int qtdCrimonososConhecidos = 0;

    scanf("%d",&qtdCrimonososConhecidos);
    getchar();

    for(int i=0; i<qtdCrimonososConhecidos; i++) {
        scanf(
            "%[^;] ; %d ; %d ; %[^\n]",
            criminosos_conhecidos[i].nome,
            &criminosos_conhecidos[i].altura,
            &criminosos_conhecidos[i].peso,
            criminosos_conhecidos[i].endereco
        );
        getchar();
    }

    // for(int i=0; i<qtdCrimonososConhecidos; i++) {
    //     printf(
    //         "nome: %s \naltura: %d \npeso: %d \nendereco: %s\n",
    //         criminosos_conhecidos[i].nome,
    //         criminosos_conhecidos[i].altura,
    //         criminosos_conhecidos[i].peso,
    //         criminosos_conhecidos[i].endereco
    //     );
    // }

    crime_nao_resolvido crime;

    int qtdCrimesNaoResolvidos = 0;

    scanf("%d",&qtdCrimesNaoResolvidos);
    getchar();

    for(int i=0; i<qtdCrimesNaoResolvidos; i++) {
        scanf("%[^;] ; %d ; %d",crime.descricao_do_crime,&crime.altura_estimada,&crime.peso_estimado);
        getchar();

        resolve_case(crime,criminosos_conhecidos,qtdCrimonososConhecidos);
    }

    return 0;
}