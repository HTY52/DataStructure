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
			}else if(add1.data[k].r == i+1 && add1.data[k].c == j+1) {
				sum.data[m].r = i+1;
				sum.data[m].c = j+1;
				sum.data[m].elem = add1.data[k].elem;
				k++;
				m++;
			}else if(add2.data[l].r == i+1 && add2.data[l].c == j+1) {
				sum.data[m].r = i+1;
				sum.data[m].c = j+1;
				sum.data[m].elem = add2.data[l].elem;
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
				if(result.data[m].elem) {
					m++;
				}
			}else if(sub1.data[k].r == i+1 && sub1.data[k].c == j+1) {
				result.data[m].r = i+1;
				result.data[m].c = j+1;
				result.data[m].elem = sub1.data[k].elem;
				k++;
				m++;
			}else if(sub2.data[l].r == i+1 && sub2.data[l].c == j+1) {
				result.data[m].r = i+1;
				result.data[m].c = j+1;
				result.data[m].elem = -1 * sub2.data[l].elem;
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
	int t = a;
	a = b;
	b = t;
}

void Transposed(Matrix matrix1, Matrix &matrix2) {
    int q = 0;
    matrix2.rows = matrix1.cols;
    matrix2.cols = matrix1.rows;
    matrix2.nums = matrix1.nums;
    if (matrix1.nums) {
        for (int i = 0; i < matrix1.cols; ++i) {
            for (int j = 0; j < matrix1.nums; ++j) {
                if (matrix1.data[j].c == i + 1) {
                    matrix2.data[q].r = matrix1.data[j].c;
                    matrix2.data[q].c = matrix1.data[j].r;
                    matrix2.data[q].elem = matrix1.data[j].elem;
                    ++q;
                }
            }
        }
    }
}

int GetValue(Matrix matrix, int i, int j) {
    int k = 0;
    while (k < matrix.nums && (matrix.data[k].r != i || matrix.data[k].c != j)) {
        ++k;
    }
    if (k < matrix.nums) {
        return matrix.data[k].elem;
    } else {
        return 0;
    }
}

void Multi(Matrix multi1, Matrix multi2, Matrix &sigma) {
	int p = 0;
    int s;
    for (int i = 0; i < multi1.rows; ++i) {
        for (int j = 0; j < multi2.cols; ++j) {
            s = 0;
            for (int k = 0; k < multi1.cols; ++k) {
                s += GetValue(multi1, i + 1, k + 1) * GetValue(multi2, k + 1, j + 1);
            }
            if (s) {
                sigma.data[p].r = i + 1;
                sigma.data[p].c = j + 1;
                sigma.data[p].elem = s;
                ++p;
            }
        }
    }
    sigma.rows = multi1.rows;
    sigma.cols = multi2.cols;
    sigma.nums = p;
}

void PrintTup(Matrix matrix) {
	printf("打印三元组表：\n");
	printf("\t%d\t%d\t%d\n", matrix.rows, matrix.cols, matrix.nums);
	printf("\t-----------------\n");
	for(int i = 0; i < matrix.nums; i++) {
		printf("   %2d : %d\t%d\t%d\n", i+1, matrix.data[i].r, matrix.data[i].c, matrix.data[i].elem);
	}
}

void PrintMatrix(Matrix matrix) {
	printf("打印矩阵：\n");
	int k = 0;
	for(int i = 0; i < matrix.rows; i++, printf("\n")) {
		for(int j = 0; j < matrix.cols; j++) {
			if(i+1 == matrix.data[k].r && j+1 == matrix.data[k].c) {
				printf("%d ", matrix.data[k++].elem);
			}else {
				printf("0 ");
			}
		}
	}
}


int main() {

	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	Matrix a, b, c;
	char ch;
	int temp;
	int k;

	printf("请输入你想要进行的运算('+'表示矩阵加法、'-'表示矩阵减法、'*'表示矩阵乘法、'#'表示矩阵转置)：");
	scanf("%c", &ch);

	printf("请输入待运算的稀疏矩阵的行数和列数及非零元个数：\n");
	printf("\t行数：");
	scanf("%d", &a.rows);
	printf("\t列数：");
	scanf("%d", &a.cols);
	do {
		printf("\t非零元个数(小于100的正整数)：");
		scanf("%d", &a.nums);
	}while(a.nums > MaxSize && a.nums <= 0);
	printf("请输入矩阵：\n");
	k = 0;
	for(int i = 0; i < a.rows; i++) {
		for(int j = 0; j < a.cols; j++) {
			scanf("%d", &temp);
			if(temp) {
				a.data[k].r = i+1;
				a.data[k].c = j+1;
				a.data[k].elem = temp;
				k++;
			}
		}
	}
	if(ch != '#') {
		printf("请输入的第二个稀疏矩阵的行数和列数：\n");
		printf("\t行数：");
		scanf("%d", &b.rows);
		printf("\t列数：");
		scanf("%d", &b.cols);
		if(ch == '*') {
			if(a.cols != b.rows) {
				printf("忠告：建议出门左转学习一下线性代数，你输入的两个矩阵无法相乘！\n");
				printf("拜了个拜，强行停止程序运行。出门右转，告辞，不送！\n");
				return 0;
			}
		}else {
			if(a.rows != b.rows || a.cols != b.cols) {
				printf("忠告：建议出门左转学习一下线性代数，你输入的两个矩阵无法相加减！\n");
				printf("拜了个拜，强行停止程序运行。出门右转，告辞，不送！\n");
				return 0;
			}
		}
		do {
			printf("\t非零元个数(小于100的正整数)：");
			scanf("%d", &b.nums);
		}while(b.nums > MaxSize && b.nums <= 0);
		printf("请输入矩阵：\n");
		k = 0;
		for(int i = 0; i < b.rows; i++) {
			for(int j = 0; j < b.cols; j++) {
				scanf("%d", &temp);
				if(temp) {
					b.data[k].r = i+1;
					b.data[k].c = j+1;
					b.data[k].elem = temp;
					k++;
				}
			}
		}
	}

	if(ch == '+') {
		Add(a, b, c);
		PrintTup(c);
		PrintMatrix(c);
	}else if(ch == '-'){
		Sub(a, b, c);
		PrintTup(c);
		PrintMatrix(c);
	}else if(ch == '#') {
		Transposed(a, c);
		PrintTup(c);
		PrintMatrix(c);
	}else if(ch == '*') {
		Multi(a, b, c);
		PrintTup(c);
		PrintMatrix(c);
	}

	return 0;
}
