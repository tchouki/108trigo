/*
** EPITECH PROJECT, 2030
** 108trigo
** File description:
** main.c
*/

#include "../include/my.h"

double factorielle(double x)
{
	double tmp = x;
	double result = 1;

	for (int i = 1; i <= tmp; i++)
		result *= i;
	return (result);
}

double **my_exp_calc(int argc, char **argv, double **matrix)
{
	int size = sqrt(argc - 2);
    double **null_matrix = create_null_matrix(size);
    double **result_matrix = NULL;

    result_matrix = malloc(sizeof(double*) * size);
    for (int i = 0; i < size; i++)
        result_matrix[i] = malloc(sizeof(double) * size);
    result_matrix = add_matrix(null_matrix, matrix, size);
    for (int i = 2; i < 50; i++) {
    	result_matrix = add_matrix(div_matrix(pow_matrix(matrix, size, i), size, factorielle(i)), result_matrix, size);
    }
    return (result_matrix);
}

int my_exp(int argc, char **argv)
{
	int size = sqrt(argc - 2);
	double **matrix = create_matrix(argc, argv, size);
	double **result_matrix = my_exp_calc(argc, argv, matrix);

	print_matrix(result_matrix, size);
	return (0);
}

int my_cos(int argc, char **argv)
{
	int size = sqrt(argc - 2);
	double **matrix = create_matrix(argc, argv, size);
	double **result_matrix = create_null_matrix(size);

	for (int i = 1; i < 50; i++) {
		if (i % 2 == 0)
			result_matrix = add_matrix(div_matrix(pow_matrix(matrix, size, i * 2), size, factorielle(i * 2)), result_matrix, size);
		else
			result_matrix = sou_matrix(result_matrix, div_matrix(pow_matrix(matrix, size, i * 2), size, factorielle(i * 2)), size);
	}
	print_matrix(result_matrix, size);
	return (0);
}

int my_sin(int argc, char **argv)
{
	int size = sqrt(argc - 2);
	double **matrix = create_matrix(argc, argv, size);
	double **result_matrix = create_matrix(argc, argv, size);

	for (int i = 1; i < 50; i++) {
		if (i % 2 == 0)
			result_matrix = add_matrix(div_matrix(pow_matrix(matrix, size, i * 2 + 1), size, factorielle(i * 2 + 1)), result_matrix, size);
		else
			result_matrix = sou_matrix(result_matrix, div_matrix(pow_matrix(matrix, size, i * 2 + 1), size, factorielle(i * 2 + 1)), size);
	}
	print_matrix(result_matrix, size);
	return (0);
}

int my_cosh(int argc, char **argv)
{
	int size = sqrt(argc - 2);
	double **matrix = my_exp_calc(argc, argv, create_matrix(argc, argv, size));
	double **matrix_neg = my_exp_calc(argc, argv, create_matrix_neg(argc, argv, size));
	double **result_matrix = div_matrix(add_matrix(matrix, matrix_neg, size), size, 2);

	print_matrix(result_matrix, size);
	return (0);
}

int my_sinh(int argc, char **argv)
{
	int size = sqrt(argc - 2);
	double **matrix = my_exp_calc(argc, argv, create_matrix(argc, argv, size));
	double **matrix_neg = my_exp_calc(argc, argv, create_matrix_neg(argc, argv, size));
	double **result_matrix = div_matrix(sou_matrix(matrix, matrix_neg, size), size, 2);

	print_matrix(result_matrix, size);
	return (0);
}