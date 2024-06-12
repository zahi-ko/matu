#include <string.h>
#include <stdlib.h>

void strip_backspace(char* s) {
    // ʹ��ջ�ķ�ʽʵ�֣���ջ��Ϊ#ʱ������ջ��Ԫ���Ҳ����н�ջ����
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