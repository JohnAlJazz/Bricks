#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* allocArray(int a, int b) {
    int* array = (int*)malloc((a * b) * sizeof(int));
    return array;
}


int count(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int counter = 0;
    for(int i = 0; i < len2; ++i) {
        for(int j = 0; j < len1; ++j) {
            if(s1[j] == s2[i]) {
                ++counter;
            }
        }
    }
    return counter;
}

int Strcmp(const char* s1, const char* s2) {
   
    if(s1[0] != '\n' && s2[0] != '\n') {
        if(s1[0] != s2[0]) {
            return -1;
        }
        return Strcmp(s1 + 1, s2 + 1);
    }
    return 0;
}

int main() {

    // int* array;
    // array = allocArray(10, 5);
    // for(int i = 0; i < 10; ++i) {
    //     for(int j = 0; j < 5; ++j) {
    //         array[j][i] = 42;
    //     }
    // }
    //////////////////////////////////
    int res = count("abracadabra", "bax");
    printf("count res: %d\n", res);
    /////////////////////////////////
    int cmp = Strcmp("hello", "hello");
    printf("is equal rec: %d\n", cmp);
    /////////////////////////////////
    

    return 0;
}