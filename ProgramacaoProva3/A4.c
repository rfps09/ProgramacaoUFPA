#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int number;
    char romano;
}Arab_To_Roma;

Arab_To_Roma table[] = {
    {1,'I'},
    {5,'V'},
    {10,'X'},
    {50,'L'},
    {100,'C'},
    {500,'D'},
    {1000,'M'}
};

#define tableBegin table
#define tableEnd table+7

Arab_To_Roma* upper_bound(Arab_To_Roma* begin, Arab_To_Roma* end, int val) {
    int len = end - begin;
    int mid = len / 2;
    int l = 0, r = len-1;
    int ans = len;

    while(l<=r) {
        mid = (l+r) / 2;

        if(table[mid].number <= val) {
            l = mid+1;
        }
        else {
            ans = mid;
            r = mid-1;
        }
    }

    return tableBegin+ans;
}

const char * converter_para_romano(char* number) {
    char *ans = (char*)malloc(50*sizeof(char));
    memset(ans,'\0',sizeof(ans));
    int len = strlen(number);
    int base = pow(10,len-1);

    for(int i=0; i<len; i++) {
        int alg = number[i] - '0';

        int idx = upper_bound(tableBegin,tableEnd,alg*base) - tableBegin;
        
        if(alg != 0) {
            int i = 1;

            if(table[idx].number < table[idx-1].number*3) i = 2;

            if(table[idx].number - table[idx-i].number == alg*base) {
                strncat(ans, &table[idx-i].romano, 1);
                strncat(ans, &table[idx].romano, 1);
            }
            else {
                int sum = 0;
                if(table[idx].number < table[idx-1].number*3) {
                    sum += table[idx-1].number;
                    strncat(ans, &table[idx-1].romano, 1);
                }
                while(sum < alg*base) {
                    sum += table[idx-i].number;
                    strncat(ans, &table[idx-i].romano, 1);
                }
            }
        }

        base /= 10;
    }

    return ans;
}

int main() {
    char number[32];

    while(scanf("%s",number) != EOF) {
        printf("%s\n",converter_para_romano(number));
    }

    return 0;
}