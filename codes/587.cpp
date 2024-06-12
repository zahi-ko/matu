#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX_INPUT 101

int main() {
	size_t len;
	char input[MAX_INPUT];

	scanf("%s", input);
	len = strlen(input);

	for (int i=0; i<len; i++) {
		if (isalpha(input[i]) || input[i] == '*') {
			continue;
		}
		printf("error\n");
		return 1;
	}

	int start;
	int end;

	start = 0;
	end = len-1;

	while (start < len && input[start] == '*') {
		putchar('*');
		start++;
	}
	while (end >= 0 && input[end] == '*') {
		end--;
	}

	for (int i=start; i<=end; i++) {
		if (input[i] == '*') {
			continue;
		}
		else {
			putchar(input[i]);
		}
	}

	while (end < len && input[++end] == '*') {
		putchar('*');
	}
	putchar('\n');
	return 0;

}