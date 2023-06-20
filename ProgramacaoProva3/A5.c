#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* trim(char* str) {
    int countLetters = 0;
    for(int i=0;i<strlen(str);i++) {
        if(isalpha(str[i]) != 0) {
            countLetters++;
        }
    }

    char* strOnlyLetters = (char*)malloc(countLetters*sizeof(char));
    int idx = 0;

    for(int i=0;i<strlen(str);i++) {
        if(isalpha(str[i]) != 0) {
            strOnlyLetters[idx] = str[i];
            idx++;
        }
    }
    strOnlyLetters[idx] = '\0';

    return strOnlyLetters;
}

char* reverse(char* str) {
    char* strReverse = (char*)malloc(strlen(str)+1*sizeof(char));
    int len = strlen(str)-1;

    for(int i=0;i<=len;i++) {
        strReverse[i] = str[len-i];
    }
    strReverse[len+1] = '\0';

    return strReverse;
}

int is_palindrome(char* str) {
    char* new_str = trim(str);
    int len = strlen(new_str)-1;
    int isPalindrome = 1;

    for(int i=0;i<=len;i++) {
        if(new_str[i] != new_str[len-i])
            isPalindrome = 0;
    }

    return isPalindrome;
}

int main() {
    char teste[] =  "I ROAMED UNDER IT, A TIRED NUDE MAORI";

    printf("%s\n", teste);
    printf("%d\n", is_palindrome(teste));

    return 0;
}