#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

long long fat(long long x) {
    if(x == 0) return 1;
    return x * fat(x-1);
}

double erf_aproximacao(double x) {
    double prev = x;
    double next = prev + (-1*pow(x,3) / 3.0);

    long long n = 2;

    while(fabs((prev-next)*M_2_SQRTPI) >= 1e-3) {
        prev = next;
        next = prev + (pow(-1,n)*pow(x,2*n+1)/(fat(n)*2*n+1));
        n++;
    }

    double ans = next*M_2_SQRTPI;

    return ans;
}

int main() {
    double x;

    scanf("%lf", &x);

    printf("aproximacao: %lf\n",erf_aproximacao(x));

    return 0;
}