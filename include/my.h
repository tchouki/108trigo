/*
** EPITECH PROJECT, 2018
** 108trigo
** File description:
** my.h
*/

#ifndef MY_H_
	#define MY_H_

	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>

//calc.c
double factorielle(double x);
double **my_exp_calc(int argc, char **argv, double **matrix);
int my_exp(int argc, char **argv);
int my_cos(int argc, char **argv);
int my_sin(int argc, char **argv);
int my_cosh(int argc, char **argv);
int my_sinh(int argc, char **argv);

//main.c
int my_strcmp(char *str1, char *str2);

//matrix.c
void print_matrix(double **matrix, int size);
double **create_null_matrix(int size);
double **div_matrix(double **matrix, int size, double div);
double **mul_matrix(double **matrix1, double **matrix2, int size);
double **pow_matrix(double **matrix, int size, int pow);
double **sou_matrix(double **matrix1, double **matrix2, int size);
double **add_matrix(double **matrix1, double **matrix2, int size);
double **create_matrix_neg(int argc, char **argv, int size);
double **create_matrix(int argc, char **argv, int size);

#endif