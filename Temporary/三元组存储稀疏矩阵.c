#include <stdio.h>


#define N 20//建议程序处理的矩阵行数列数均不超过20
#define MaxSize 100//建议程序处理的稀疏矩阵的非零元个数不超过100 

typedef struct {
	int r;
	int c;
	int data1;
}TupNode;

typedef struct {
	int rows;//该矩阵行数 
	int cols;//该矩阵列数 
	int nums;//该矩阵非零元个数 
	TupNode data[MaxSize];
}Matrix;

int main() {
	printf("请输入你想要进行的运算('+'表示矩阵加法、'-'表示矩阵减法、'*'表示矩阵乘法、'#'表示矩阵转置)：");
	char ch;
	scanf("%c", &ch);
	
	int r1, c1, r2, c2;
	printf("请输入待运算的稀疏矩阵的行数和列数：\n");
	printf("\t请输入的第一个稀疏矩阵的行数和列数：\n");
	printf("\t\t行数：");
	scanf("%d", &r1);
	printf("\t\t列数：");
	scanf("%d", &c1);

	printf("\t请输入的第二个稀疏矩阵的行数和列数：\n");
	printf("\t\t行数：");
	scanf("%d", &r2);
	printf("\t\t列数：");
	scanf("%d", &c2);
	printf("请输入你想要进行的运算('+'表示矩阵加法、'-'表示矩阵减法、'*'表示矩阵乘法、'#'表示矩阵转置)：\n");
	switch(ch) {
		case '+':
			if(r1 != r2 && c1 != c2) {
				printf("警告：行数列数不匹配，程序运行结束！\n");
				return 0;
			}
			break;
		case '-':
			break;
		case '*':
			break;
		case '#':
			break;
	}
	
	return 0;
}
