#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solve(char *str) {
    char* ans = (char*)malloc(strlen(str)*sizeof(char));
    int letters[30];
    memset(letters,-1,sizeof(letters));

    for(int i=0; i<strlen(str); i++) {
        if(letters[str[i]-'A'] != -1 && i - letters[str[i]-'A'] < 10) {
            ans[i] = '0' + i - letters[str[i]-'A'];
        }
        else {
            ans[i] = '0';
        }
        letters[str[i]-'A'] = i;
    }

    return ans;
}

int main() {
    char teste[] = "AABCDBEFFEABGHIJKXYLMNOPQRSTUBWB";
    
    printf("%s\n",solve(teste));

    return 0;
}