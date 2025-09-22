//Copyright David-Ioan Stancu 312CAb 2023-2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 10007
typedef struct {//matrcele de memorie
	int **mat;
	int l;
	int c;
} matrix;

typedef struct {//array de pointeri
	matrix *matnr;
	int size;//cate matrice sunt in array
	int cap;//cate matrice suporta array-ul
} array;

void arraysize_double(array *list)
{
	list->cap *= 2;
	list->matnr = (matrix *)realloc(list->matnr, sizeof(matrix) * list->cap);
}//se va dubla resizable array-ul cand va fi nevoie

void matrix_loader(int lines, int cols, array *list)
{
	matrix newmat;
	newmat.l = lines;
	newmat.c = cols;
	newmat.mat = (int **)malloc(sizeof(int *) * lines);
	for (int i = 0; i < lines; i++)
		newmat.mat[i] = (int *)malloc(sizeof(int) * cols);
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < cols; j++)
			scanf("%d", &newmat.mat[i][j]);
	if (list->size + 1 == list->cap)
		arraysize_double(list);
	list->matnr[list->size] = newmat;
	list->size++;
}//se introduce matricea in memorie

void matrix_dim(int x, array *list)
{
	if (x < 0 || x >= list->size) {
		printf("No matrix with the given index\n");
		return;
	}
	printf("%d %d\n", list->matnr[x].l, list->matnr[x].c);
}//se afiseaza dimensiunile matriciei selectate

void matrix_show(int x, array *list)
{
	if (x < 0 || x >= list->size) {
		printf("No matrix with the given index\n");
		return;
	}
		matrix matcommand;
		matcommand = list->matnr[x];
		for (int i = 0; i < matcommand.l; i++) {
			for (int j = 0; j < matcommand.c; j++)
				printf("%d ", matcommand.mat[i][j]);
			printf("\n");
		}
}//se afiseaza matricea dorita

void matrix_rearrange(int x, array *list)
{
	int i, j;
	scanf("%d", &i);
	int *newmatl = (int *)malloc(sizeof(int) * i);
	for (int k = 0; k < i; k++)
		scanf("%d", &newmatl[k]);
	scanf("%d", &j);
	int *newmatc = (int *)malloc(sizeof(int) * j);
	for (int k = 0; k < j; k++)//co
		scanf("%d", &newmatc[k]);
	if (x < 0 || x >= list->size) {
		printf("No matrix with the given index\n");
		free(newmatl);
		free(newmatc);
		return;
	}
	matrix newmat;
	newmat.l = i;
	newmat.c = j;
	newmat.mat = (int **)malloc(sizeof(int *) * i);
	for (int k = 0; k < i; k++)
		newmat.mat[k] = (int *)malloc(sizeof(int) * j);
	for (int k = 0; k < i; k++)
		for (int g = 0; g < j; g++)
			newmat.mat[k][g] = list->matnr[x].mat[newmatl[k]][newmatc[g]];
	for (int k = 0; k < list->matnr[x].l; k++)
		free(list->matnr[x].mat[k]);
	free(list->matnr[x].mat);
	list->matnr[x].l = i;
	list->matnr[x].c = j;
	list->matnr[x].mat = newmat.mat;
	free(newmatl);
	free(newmatc);
}//se modifica matricea dorita in functie de cerintele tastaturii

void matrix_multiply(int x, int y, array *list)
{
	if ((x < 0 || y < 0) || (x >= list->size || y >= list->size)) {
		printf("No matrix with the given index\n");
		return;
	}
	if (list->matnr[x].c != list->matnr[y].l) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	matrix multmat;
	multmat.l = list->matnr[x].l;
	multmat.c = list->matnr[y].c;
	multmat.mat = (int **)malloc(sizeof(int *) * multmat.l);
	for (int i = 0; i < multmat.l; i++)
		multmat.mat[i] = (int *)malloc(sizeof(int) * multmat.c);
	for (int i = 0; i < multmat.l; i++) {
		for (int j = 0; j < multmat.c; j++) {
			multmat.mat[i][j] = 0;
			for (int k = 0; k < list->matnr[x].c; k++)
				multmat.mat[i][j] = (multmat.mat[i][j] +
									 list->matnr[x].mat[i][k] *
									 list->matnr[y].mat[k][j]) % MOD;
			if (multmat.mat[i][j] < 0)
				multmat.mat[i][j] += MOD;
		}
	}
	if (list->size + 1 == list->cap)
		arraysize_double(list);
	list->matnr[list->size] = multmat;
	list->size++;
}//se inmultesc doua matrice intr-una care se plaseaza la sfarsit de array

void matrix_sort(array *list)
{
	for (int i = 0; i < list->size; i++) {
		for (int j = i + 1; j < list->size; j++) {
			int sum1 = 0, sum2 = 0;
			for (int lines = 0; lines < list->matnr[i].l; lines++)
				for (int cols = 0; cols < list->matnr[i].c; cols++)
					sum1 = (sum1 + list->matnr[i].mat[lines][cols]) % MOD;
			for (int lines = 0; lines < list->matnr[j].l; lines++)
				for (int cols = 0; cols < list->matnr[j].c; cols++)
					sum2 = (sum2 + list->matnr[j].mat[lines][cols]) % MOD;
			if (sum1 < 0)
				sum1 += MOD;
			if (sum2 < 0)
				sum2 += MOD;
			if (sum1 > sum2) {
				matrix aux = list->matnr[i];
				list->matnr[i] = list->matnr[j];
				list->matnr[j] = aux;
			}
		}
	}
}//se sorteaza tot array-ul de matrice

void matrix_flip(int x, array *list)
{
	if (x < 0 || x >= list->size) {
		printf("No matrix with the given index\n");
		return;
	}
	matrix flippedmat;
	flippedmat.l = list->matnr[x].c;
	flippedmat.c = list->matnr[x].l;
	flippedmat.mat = (int **)malloc(sizeof(int *) * flippedmat.l);
	for (int i = 0; i < flippedmat.l; i++)
		flippedmat.mat[i] = (int *)malloc(sizeof(int) * flippedmat.c);
	for (int i = 0; i < list->matnr[x].l; i++)
		for (int j = 0; j < list->matnr[x].c; j++)
			flippedmat.mat[j][i] = list->matnr[x].mat[i][j];
	for (int i = 0; i < list->matnr[x].l; i++)
		free(list->matnr[x].mat[i]);
	free(list->matnr[x].mat);
	list->matnr[x] = flippedmat;
}//se transpune matricea dorita

void matrix_power(int x, int p, array *list)
{
	if (x < 0 || x >= list->size) {
		printf("No matrix with the given index\n");
		return;
	}
	if (p < 0) {
		printf("Power should be positive\n");
		return;
	}
	if (list->matnr[x].l != list->matnr[x].c) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}
	matrix multmat, newmat;
	multmat.l = list->matnr[x].l;
	multmat.c = list->matnr[x].c;
	multmat.mat = (int **)malloc(sizeof(int *) * multmat.l);
	for (int i = 0; i < multmat.l; i++) {
		multmat.mat[i] = (int *)malloc(sizeof(int) * multmat.c);
		for (int j = 0; j < multmat.c; j++) {
			multmat.mat[i][j] = 0;
			if (i == j)
				multmat.mat[i][j] = 1;
		}
	}
	newmat.l = list->matnr[x].l;
	newmat.c = list->matnr[x].c;
	newmat.mat = (int **)malloc(sizeof(int *) * multmat.l);
	for (int i = 0; i < multmat.l; i++) {
		newmat.mat[i] = (int *)malloc(sizeof(int) * multmat.c);
	}
	while (p > 0) {
		if (p % 2 == 1) {
			for (int i = 0; i < multmat.l; i++) {
				for (int j = 0; j < multmat.c; j++) {
					newmat.mat[i][j] = multmat.mat[i][j];
				}
			}
			for (int i = 0; i < multmat.l; i++) {
				for (int j = 0; j < multmat.c; j++) {
					multmat.mat[i][j] = 0;
					for (int k = 0; k < list->matnr[x].c; k++) {
						multmat.mat[i][j] += newmat.mat[i][k] *
											 list->matnr[x].mat[k][j];
						multmat.mat[i][j] %= 10007;
					}
					if (multmat.mat[i][j] < 0)
						multmat.mat[i][j] += 10007;
				}
			}
		}
		for (int i = 0; i < list->matnr[x].l; i++) {
				for (int j = 0; j < list->matnr[x].c; j++) {
					newmat.mat[i][j] = list->matnr[x].mat[i][j];
				}
			}
		for (int i = 0; i < list->matnr[x].l; i++) {
			for (int j = 0; j < list->matnr[x].c; j++) {
				list->matnr[x].mat[i][j] = 0;
				for (int k = 0; k < list->matnr[x].c; k++) {
					list->matnr[x].mat[i][j] += newmat.mat[i][k] *
												newmat.mat[k][j];
					list->matnr[x].mat[i][j] %= 10007;
				}
				if (list->matnr[x].mat[i][j] < 0)
					list->matnr[x].mat[i][j] += 10007;
			}
		}
		p /= 2;
	}
	for (int i = 0; i < multmat.l; i++) {
		for (int j = 0; j < multmat.c; j++) {
			list->matnr[x].mat[i][j] = multmat.mat[i][j];
		}
	}
	for (int i = 0; i < multmat.l; i++) {
		free(multmat.mat[i]);
		free(newmat.mat[i]);
	}
	free(multmat.mat);
	free(newmat.mat);
}//se ridica la putere matricea dorita

void matrix_free(int x, array *list)
{
	if (x < 0 || x >= list->size) {
		printf("No matrix with the given index\n");
		return;
	}
	for (int i = 0; i < list->matnr[x].l; i++)
		free(list->matnr[x].mat[i]);
	free(list->matnr[x].mat);
	for (int i = x; i < list->size - 1; i++)
		list->matnr[i] = list->matnr[i + 1];
	list->size--;
}//se elibereaza din memorie matricea dorita

void free_all(array *list)
{
	while (list->size > 0)
		matrix_free(list->size - 1, list);
	free(list->matnr);
}//se elibereaza toata memoria folosita

int main(void)
{
	array *list = (array *)malloc(sizeof(array));
	list->size = 0;
	list->cap = 1;
	list->matnr = (matrix *)malloc(sizeof(matrix) * list->cap);
	char commands[] = "LDPCMOTRFQS";
	char cmd;
	do {
		scanf("%c", &cmd);
		char *c = strchr(commands, cmd);
		if (!c) {
			printf("Unrecognized command\n");
		} else {
			if (cmd == 'L') {
				int l, c;
				scanf("%d%d", &l, &c);
				matrix_loader(l, c, list);
			}
			if (cmd == 'D') {
				int mat_nr;
				scanf("%d", &mat_nr);
				matrix_dim(mat_nr, list);
			}
			if (cmd == 'P') {
				int mat_nr;
				scanf("%d", &mat_nr);
				matrix_show(mat_nr, list);
			}
			if (cmd == 'C') {
				int mat_nr;
				scanf("%d", &mat_nr);
				matrix_rearrange(mat_nr, list);
			}
			if (cmd == 'M') {
				int mat_nr1, mat_nr2;
				scanf("%d%d", &mat_nr1, &mat_nr2);
				matrix_multiply(mat_nr1, mat_nr2, list);
			}
			if (cmd == 'O')
				matrix_sort(list);
			if (cmd == 'T') {
				int mat_nr;
				scanf("%d", &mat_nr);
				matrix_flip(mat_nr, list);
			}
			if (cmd == 'R') {
				int mat_nr, pow;
				scanf("%d%d", &mat_nr, &pow);
				matrix_power(mat_nr, pow, list);
			}
			if (cmd == 'F') {
				int mat_nr;
				scanf("%d", &mat_nr);
				matrix_free(mat_nr, list);
			}
			if (cmd == 'Q')
				free_all(list);
		}
		scanf("\n");
	} while (cmd != 'Q');
	free(list);
	return 0;
}
