#include <string.h>
#include <stdlib.h>

void strip_backspace(char* s) {
    // 使用栈的方式实现，当栈顶为#时，弹出栈顶元素且不进行进栈操作
    char* stack = (char*) calloc(strlen(s), sizeof(char));

    for (int i=0, j=0; i<strlen(s); i++) {
        if (s[i] == '#') {
            if (--j < 0) { j = 0; }
            stack[j] = '\0';
        }
        else {
            stack[j++] = s[i];
        }
    }

    strcpy(s, stack);
    free(stack);
}

int backspace_compare(char *s, char *t) {
    if (!s || !t) {return -1;}
    strip_backspace(s);
    strip_backspace(t);

    if (strlen(s) != strlen(t)) { return 0; }
    if (!strcmp(s, t)) {return 1;}
    return 0;
}