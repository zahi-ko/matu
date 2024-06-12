#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ERR = 0;

typedef struct TreeNode {
	char data;
	struct TreeNode* lson;
	struct TreeNode* rson;
} TreeNode;

static void copy(char* fore, char* mid, char* ltf, char* ltm, char* rtf, char* rtm, int i) {
	strncpy(ltf, fore + 1, i);
	ltf[i] = '\0';
	strncpy(ltm, mid, i);
	ltm[i] = '\0';
	
	strncpy(rtf, fore + i + 1, strlen(fore) - i - 1);
	rtf[(strlen(fore) - i - 1)] = '\0';
	strncpy(rtm, mid + i + 1, strlen(mid) - i - 1);
	rtm[strlen(mid) - i - 1] = '\0';
}

static TreeNode* restore(char* fore, char* mid) {
	if (strlen(fore) == 0 && strlen(mid) == 0) { return NULL; }

	if (strlen(fore) != strlen(mid)) {
		fprintf(stdout, "error\n");
		ERR = -1;
		return NULL;
	}

	char ltf[2048];
	char ltm[2048];
	char rtf[2048];
	char rtm[2048];
	char tmp = fore[0];

	TreeNode* Head = (TreeNode*)malloc(sizeof(TreeNode));
	if (Head == NULL) {
		fprintf(stdout, "error\n");
		ERR = -1;
		return NULL;
	}
	Head->data = tmp;
	ERR = -1;
	
	int i = 0;
	for (; i < strlen(mid); i++) {
		if (mid[i] == tmp) {
			ERR = 0;
			break;
		}
	}

	if (ERR != 0) {
		fprintf(stdout, "error\n");
		return NULL;
	}

	copy(fore, mid, ltf, ltm, rtf, rtm, i);
	Head->lson = restore(ltf, ltm);
	if (ERR != 0) { return NULL; }
	Head->rson = restore(rtf, rtm);
	if (ERR != 0) { return NULL; }
	
	return Head;
}

static void back(TreeNode* root) {
	if (root == NULL) { return; }
	back(root->lson);
	back(root->rson);
	fprintf(stdout, "%c", root->data);
}

int main() {
	char fore[2048];
	char mid[2048];
	int res;

	res = scanf("%s", fore);
	res = scanf("%s", mid);

	TreeNode* root = restore(fore, mid);
	back(root);

	free(root);

	return 0;
}