// main.c
#include <stdio.h>
#include <string.h>
#include "copy.h"   // MAXLINE, copy() 제공

char line[MAXLINE];

int main(void) {
    char str[5][MAXLINE] = {{0}};
    int i = 0;

    while (i < 5) {
        if (fgets(line, MAXLINE, stdin) == NULL) break;
        line[strcspn(line, "\n")] = '\0';
        copy(line, str[i]);
        i++;
    }
    int n = i;

    for (int a = 0; a < n - 1; a++) {
        int max_idx = a;
        for (int b = a + 1; b < n; b++) {
            if (strlen(str[b]) > strlen(str[max_idx])) {
                max_idx = b;
            }
        }
        if (max_idx != a) {
            char tmp[MAXLINE];
            copy(str[a], tmp);
            copy(str[max_idx], str[a]);
            copy(tmp, str[max_idx]);
        }
    }

    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    return 0;
}

