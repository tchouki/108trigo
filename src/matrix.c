/*
** EPITECH PROJECT, 2018
** 108trigo
** File description:
** main.c
*/

#include "../include/my.h"

void print_matrix(double **matrix, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (j < size - 1)
				printf("%.2f\t", matrix[i][j]);
			else
				printf("%.2f\n", matrix[i][j]);
}

double **create_null_matrix(int size)
{
    double **matrix = malloc(sizeof(double*) * size);

    for (int i = 0; i < size; i++)
        matrix[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
    return (matrix);
}

double **div_matrix(double **matrix, int size, double div)
{
    double **result_matrix = malloc(sizeof(double*) * size);

    for (int i = 0; i < size; i++)
        result_matrix[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result_matrix[i][j] = matrix[i][j] / div;
    return (result_matrix);
}

double **mul_matrix(double **matrix1, double **matrix2, int size)
{
    double **result_matrix = malloc(sizeof(double*) * size);

    for (int i = 0; i < size; i++)
    	result_matrix[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return (result_matrix);
}

double **pow_matrix(double **matrix, int size, int pow)
{
    double **result_matrix = malloc(sizeof(double*) * size);

    for (int i = 0; i < size; i++)
        result_matrix[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result_matrix[i][j] = matrix[i][j];
    for (int i = 1; i < pow; i++)
        result_matrix = mul_matrix(result_matrix, matrix, size);
    return (result_matrix);
}

double **sou_matrix(double **matrix1, double **matrix2, int size)
{
    double **result_matrix = malloc(sizeof(double*) * size);

    for (int i = 0; i < size; i++)
        result_matrix[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
    return (result_matrix);
}

double **add_matrix(double **matrix1, double **matrix2, int size)
{
    double **result_matrix = malloc(sizeof(double*) * size);

    for (int i = 0; i < size; i++)
        result_matrix[i] = malloc(sizeof(double) * size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
    return (result_matrix);
}

double **create_matrix_neg(int argc, char **argv, int size)
{
    double **matrix = create_matrix(argc, argv, size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] *= -1;
    return (matrix);
}

double **create_matrix(int argc, char **argv, int size)
{
	double **matrix = malloc(sizeof(double*) * size);
	int x = 0;
	int y = 0;

	for (int i = 0; i < size; i++)
		matrix[i] = malloc(sizeof(double) * size);
	for (int i = 0; argv[i + 2] != NULL; i++) {
		if (y == size) {
			y = 0;
			x++;
		}
		matrix[x][y] = atoi(argv[i + 2]);
		y++;
	}
	return (matrix);
}