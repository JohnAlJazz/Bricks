#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <array>
#include <algorithm>

int main() {
    
    int table[256] = {0};
    int idx = 0;
    int arr[8] = {12, 2, 43, 5, 1, 6, 4, 4};
    for(int i = 0; i < 8; ++i) {
        if(table[arr[i]] != 0) {
            idx = table[arr[i]] - 1;            
            break;
        }
        table[arr[i]] = i + 1;
    }
    printf("non unique idx: %d\n", idx);
    //////////////////////////////////////
    const char* S = "hello";
    const char* T = "world";
    const char* W = "table";
    int counter = 0;
    int TLen = strlen(T);
    for(int i = 0; i < TLen; ++i) {
        if(strchr(S, T[i]) && !(strchr(W, T[i]))) {
            ++counter;
        }
    }
    printf("three strings: %d\n", counter);
    ///////////////////////////////////////
    // long longArr[1000000];
    // long tableOfLongs[100000] = {0};
    // for(long i = 0; i < 1000000; ++i) {
    //     longArr[i] = rand();
    //     ++tableOfLongs[longArr[i]];
    // }
    ///////////////////////////////////
    char trimmed[100];
    char string[100] = "Hello world!    from   Java!";
    char* tok;
    char spaces[3] = "  ";
    tok = strtok(string, spaces);
    strcat(trimmed, tok);
    // while(tok != NULL) {
    //     while(tok == " ") {
    //         ++tok;
    //     }
    //     tok = strtok(string, spaces);
    //     strcat(trimmed, tok);
    // }
    // printf("%s\n", trimmed);

    return 0;
}