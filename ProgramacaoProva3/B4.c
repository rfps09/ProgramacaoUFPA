#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU 0
#define INSERIR_CRIMINOSO 1
#define INSERIR_CRIME 2
#define END 3

typedef struct {
    char nome[50];
    int altura;
    int peso;
    char endereco[150];
} criminoso;

typedef struct {
    int id;
    int altura_estimada;
    int peso_estimado;
    char descricao_do_crime[150];
} crime_nao_resolvido;

int get_id() {
    int id = 0;
    int file_exist = 0;

    FILE* file = fopen("crimes_id.txt", "r");

    if (file != NULL) {
        fscanf(file,"%d", &id);
        fclose(file);
    }

    file = fopen("crimes_id.txt", "w");

    fprintf(file,"%d", id+1);

    fclose(file);

    return id;
}

void resolve_case(crime_nao_resolvido crime) {
    criminoso vagabundo;
    
    FILE* file_read = fopen ("criminosos_conhecidos.txt","r");
    FILE* file_write = fopen ("suspeitos.txt","a");
    
    while(
        fscanf(file_read,
            "%[^;]; %d ; %d ; %[^\n]\n",
            vagabundo.nome,
            &vagabundo.altura,
            &vagabundo.peso,
            vagabundo.endereco
        ) != EOF
    ) {
        if( vagabundo.altura >= crime.altura_estimada-5 && vagabundo.altura <= crime.altura_estimada+5
            &&
            vagabundo.peso >= crime.peso_estimado-5 && vagabundo.peso <= crime.peso_estimado+5
        )
        {
            printf("%s\n",vagabundo.nome);
            fprintf(file_write,"%d;%s\n",crime.id,vagabundo.nome);
        }
    }

    fclose(file_read);
    fclose(file_write);
}

int main() {
    int opcao = MENU;

    while(opcao < END && opcao >= MENU) {
        printf("Sistema de Identificação de Criminosos\n");
        if(opcao == MENU) {
            printf("Digite o numero da opção desejada:\n");
            printf("1 - Inserir criminoso conhecido\n");
            printf("2 - Identificar possivel suspeito de crime nao resolvido\n");
            printf("3 - Sair\n");
            scanf("%d",&opcao);
            getchar();

            printf("\n\n");
        }
        if(opcao == INSERIR_CRIMINOSO) {
            criminoso vagabundo;

            printf("Digite o nome do criminoso: ");
            scanf("%[^\n]",vagabundo.nome);
            getchar();

            printf("Digite a altura do criminoso em centimetros: ");
            scanf("%d",&vagabundo.altura);
            getchar();

            printf("Digite o peso do criminoso em kilogramas: ");
            scanf("%d",&vagabundo.peso);
            getchar();

            printf("Digite o endereço do criminoso (o antigo, pois o novo é a prisao): ");
            scanf("%[^\n]",vagabundo.endereco);
            getchar();

            FILE* file = fopen("criminosos_conhecidos.txt","a");
            fprintf(file,"%s;%d;%d;%s\n",vagabundo.nome,vagabundo.altura,vagabundo.peso,vagabundo.endereco);
            fclose(file);

            printf("\n\n");

            opcao = MENU;
        }
        if(opcao == INSERIR_CRIME) {
            crime_nao_resolvido crime;

            crime.id = get_id();

            printf("Digite a descricao do crime: ");
            scanf("%[^\n]",crime.descricao_do_crime);
            getchar();

            printf("Digite a altura do criminoso em centimetros: ");
            scanf("%d",&crime.altura_estimada);
            getchar();

            printf("Digite o peso do criminoso em kilogramas: ");
            scanf("%d",&crime.peso_estimado);
            getchar();

            FILE* file = fopen("crimes_nao_resolvidos.txt","a");
            fprintf(file,"%d;%s;%d;%d\n",crime.id,crime.descricao_do_crime,crime.altura_estimada,crime.peso_estimado);
            fclose(file);

            printf("\nSuspeitos:\n");

            resolve_case(crime);

            printf("\n\n");

            opcao = MENU;
        }
    }

    return 0;
}