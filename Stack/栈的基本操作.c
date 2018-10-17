#include <stdio.h>
#include <malloc.h>

#define MaxSize 100

typedef struct {
	int data[MaxSize];
	int top;
}SqStack;

/**
 * 初始化栈
 */
void InitStack(SqStack * s) {
	s = (SqStack *) malloc(sizeof(SqStack));
	s->top = -1;
}

/**
 * 销毁栈
 */
void DestoryStack(SqStack * s) {
	free(s);
}

/**
 * 判断栈是否为空
 */
int StackEmpty(SqStack * s) {
	return s->top == -1;
}

int Push(SqStack * s, int e) {
	if(s->top == MaxSize - 1)
		return 0;
	s->top++;
	s->data[s->top] = e;
	return 1;
}

int Pop(SqStack * s, int * e) {
	if(s->top == -1)
		return 0;
	e = s->data[s->top];
	s->top--;
	return 1;
}

int GetTop(SqStack *s) {
	if(s->top == -1)
		return 0;
	return s->data[s->top];
	
}

int main() {
	
	
	
	return 0;
}
