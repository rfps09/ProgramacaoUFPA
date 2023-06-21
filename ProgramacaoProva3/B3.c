#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// double f(double x) {
//     return 3*x*x + 5*x - 10;
// }

double f(double x) {
    return 15*x*x*x*x + 3*x*x*x - 5*x*x;
}

void swap(double *a,double *b) {
    double aux = *a;
    *a = *b;
    *b = aux;
}

double binary_search(double a, double b) {
    if(f(a) > f(b)) swap(&a,&b);
    double mid = (a+b)/2;

    while(f(mid) != 0 && f(b)-f(a) >= 1e-6) {
        if(f(mid) > 0) b = mid;
        else a = mid;
        mid = (a+b)/2;
    }

    return mid;
}

int main() {
    double a,b;

    scanf("%lf%lf",&a,&b);

    double ans = binary_search(a,b);

    printf("x = %lf\n", ans);
    printf("f(%lf) = %lf\n", ans, f(ans));

    return 0;
}