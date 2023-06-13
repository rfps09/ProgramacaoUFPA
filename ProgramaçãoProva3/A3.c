#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
    char *content;
    int size;
}String;

String string(char *vetor, int l, int r) {
    String new;
    int len = r-l;
    new.content = (char*)malloc(len*sizeof(char));
    memcpy(new.content,vetor+l,len);
    new.content[len] = '\0';
    new.size = len;

    return new;
}

typedef struct Vector {
    int size;
    int len;
    String *strs;
    void (*push)(struct Vector*,String);
    void (*pop)(struct Vector*);
    void (*resize)(struct Vector*);
} Vector;

void resize(Vector *vector) {
    vector->len = vector->len*2;
    vector->strs = (String*)realloc(vector->strs,vector->len*sizeof(String));
}

void vector_push(Vector *vector, String str) {
    if(vector->size == vector->len) vector->resize(vector);
    vector->strs[vector->size].content = (char*)malloc(sizeof(str.content));
    vector->strs[vector->size] = str;
    vector->size++;
}

void vector_pop(Vector *vector) {
    if(vector->size > 0)
        vector->size--;
}

Vector vector() {
    Vector vector;
    vector.len = 2;
    vector.strs = (String*)malloc(vector.len*sizeof(String));
    vector.size = 0;
    vector.push = vector_push;
    vector.pop = vector_pop;
    vector.resize = resize;

    return vector;
}

float media_de_letras_por_palavras(char text[]) {
    int start = 0;
    int end = 0;

    Vector vetor = vector();

    int len = strlen(text);
    for(int i=0; i<len; i++) {
        if(text[i] != ' ' && text[start] == ' ') {
            start = i;
        }
        else if (text[i] != ' ' && text[start] != ' ') {
            if(i+1 != len) {
                end = i;
            } else {
                String str = string(text,start,len);
                vetor.push(&vetor,str);
            }
        }
        else if(text[i] == ' ' && text[start] != ' ') {
            end = i;
            String str = string(text,start,end);
            vetor.push(&vetor,str);
            start = i;
        }
    }

    int sum = 0;

    for(int i=0; i<vetor.size; i++) {
        sum += vetor.strs[i].size;
    }

    float ans = sum/(float)vetor.size;

    return ans;
}

int main() {
    char text[] = "   1bcd       2bcd 3bcd  4bcd     ";

    printf("media de letras por palavras: %.2f\n", media_de_letras_por_palavras(text));

    return 0;
}