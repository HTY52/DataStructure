#include <stdio.h>

#define N 20//建议程序处理的矩阵行数列数均不超过20
#define MaxSize 100//建议程序处理的稀疏矩阵的非零元个数不超过100 

typedef struct {
	int r;//元素行号 
	int c;//元素列号 
	int elem;//元素值 
}TupNode;

typedef struct {
	int rows;//该矩阵行数 
	int cols;//该矩阵列数 
	int nums;//该矩阵非零元个数 
	TupNode data[MaxSize];
}Matrix;

void Add(Matrix add1, Matrix add2, Matrix &sum) {
	int k = 0;
	int l = 0;
	int m = 0;
	
	for(int i = 0; i < add1.rows; i++) {
		for(int j = 0; j < add1.cols; j++) {
			if(add1.data[k].r == i+1 && add1.data[k].c == j+1 && add2.data[l].r == i+1 && add2.data[l].c == j+1) {
				sum.data[m].r = i+1;
				sum.data[m].c = j+1;
				sum.data[m].elem = add1.data[k].elem + add2.data[l].elem;
				k++;
				l++;
				m++; 
			}
			else if(add1.data[k].r == i+1 && add1.data[k].c == j+1) {
				sum.data[m].r = i+1;
				sum.data[m].c = j+1;
				sum.data[m].elem = add1.data[k].elem;
				k++;
				m++;
			}
			else if(add2.data[l].r == i+1 && add2.data[l].c == j+1) {
				sum.data[m].r = i+1;
				sum.data[m].c = j+1;
				sum.data[m].elem = add2.data[k].elem;
				l++;
				m++;
			}
		}
	}
	
	sum.cols = add2.cols;
	sum.rows = add2.rows;
	sum.nums = m; 
}

void Sub(Matrix sub1, Matrix sub2, Matrix &result) {
	int k = 0;
	int l = 0;
	int m = 0;
	
	for(int i = 0; i < sub1.rows; i++) {
		for(int j = 0; j < sub1.cols; j++) {
			if(sub1.data[k].r == i+1 && sub1.data[k].c == j+1 && sub2.data[l].r == i+1 && sub2.data[l].c == j+1) {
				result.data[m].r = i+1;
				result.data[m].c = j+1;
				result.data[m].elem = sub1.data[k].elem - sub2.data[l].elem;
				k++;
				l++;
				m++; 
			}
			else if(sub1.data[k].r == i+1 && sub1.data[k].c == j+1) {
				result.data[m].r = i+1;
				result.data[m].c = j+1;
				result.data[m].elem = sub1.data[k].elem;
				k++;
				m++;
			}
			else if(sub2.data[l].r == i+1 && sub2.data[l].c == j+1) {
				result.data[m].r = i+1;
				result.data[m].c = j+1;
				result.data[m].elem = -1 * sub2.data[k].elem;
				l++;
				m++;
			}
		}
	}
	
	result.cols = sub2.cols;
	result.rows = sub2.rows;
	result.nums = m; 
}

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void Transposed(Matrix matrix) {
	for(int i = 0; i < matrix.nums; i++) {
		Swap(matrix.data[i].c, matrix.data[i].r);
	}
}

int main() {
	
	Matrix a, b, c;
	char ch;
	
	printf("请输入你想要进行的运算('+'表示矩阵加法、'-'表示矩阵减法、'*'表示矩阵乘法、'#'表示矩阵转置)：");
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
