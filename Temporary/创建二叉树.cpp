#include <cstdio>
#include <iostream>
#include <malloc.h>

#define MaxSize 100

typedef struct node {
	char data;
	struct node * lchild;
	struct node * rchild;
}BTNode;

void CreateBTree(BTNode *&b, char str[]) {
	BTNode * St[MaxSize], * p;
	int top = -1, k, j = 0;
	char ch = str[j];
	b = NULL;
	while (ch) {
		switch (ch) {
			case '(':
				++top;
				St[top] = p;
				k = 1;
				break;
			case ')':
				--top;
				break;
			case ',':
				k = 2;
				break;
			default:
				p = (BTNode *) malloc(sizeof(BTNode));
				if (b) {
					b = p;
				} else {
					switch (k) {
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;							
					}
				}
		}
		++j;
		ch = str[j];
	}
}

void DestoryTree(BTNode *&b) {
	if (b) {
		DestoryTree(b->lchild);
		DestoryTree(b->rchild);
		free(b);
	}
}

int main() {
		
	printf("Hello World!");
	
	return 0;
}
