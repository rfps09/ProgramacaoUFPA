#include <stdio.h>
#include <stdlib.h>

int** allocMatriz(int m,int n) {
    int **matriz = (int**)malloc(m*sizeof(int*));

    for(int i=0; i<m; i++) {
        matriz[i] = (int*)malloc(n*sizeof(int));
    }

    return matriz;
}

int** dot(int **A, int **B, int m, int p, int n) {
    int **matriz = allocMatriz(m,n);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<p; k++) {
                matriz[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    return matriz;
}

void readMatriz(int **matriz, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main() {
    int m,p,n;

    scanf("%d%d%d",&m,&p,&n);

    int **A = allocMatriz(m,p);
    int **B = allocMatriz(p,n);

    readMatriz(A,m,p);
    readMatriz(B,p,n);

    int** ans = dot(A,B,m,p,n);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}