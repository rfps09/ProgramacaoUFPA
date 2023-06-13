#include <stdio.h>
#include <stdlib.h>

int seg_to_seg(int tempo_em_segundos) {
    int segundos = tempo_em_segundos % 60;
}

int seg_to_min(int tempo_em_segundos) {
    return tempo_em_segundos / 60 % 60;
}

int seg_to_hour(int tempo_em_segundos) {
    return tempo_em_segundos / 60 / 60 % 24;
}

int main() {
    float massa_inicial = 0;
    float massa_final = 0;
    int tempo_em_segundos = 0;

    scanf("%f",&massa_inicial);

    massa_final = massa_inicial;

    while(massa_final >= 0.5) {
        massa_final /= 2.0;
        tempo_em_segundos += 50;
    }

    printf("Massa Inicial: %.2f\n", massa_inicial);
    printf("Massa Final: %.2f\n", massa_final);
    printf("Tempo: %02d:%02d:%02d\n",
        seg_to_hour(tempo_em_segundos),
        seg_to_min(tempo_em_segundos),
        seg_to_seg(tempo_em_segundos)
    );

    return 0;
}