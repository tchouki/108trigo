/*
** EPITECH PROJECT, 2018
** 108trigo
** File description:
** main.c
*/

#include "../include/my.h"

int my_strlen(char *str)
{
	int size = 0;

	for (int i = 0; str[i] != '\0'; i++, size++);
	return (size);
}

int my_strcmp(char *str1, char *str2)
{
	int size1 = my_strlen(str1);
	int size2 = my_strlen(str2);

	if (size1 != size2)
		return (0);
	for (int i = 0; str1[i] != '\0'; i++)
		if (str1[i] != str2[i])
			return (0);
	return (1);
}

static int check_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
			return (0);
	return (1);
}

static int print_help(void)
{
	printf("USAGE\n");
	printf("\t./108trigo fun a0 a1 a2 ...\n\n");
	printf("DESCRIPTION\n");
	printf("\tfun\tfunction to be applied, among at least \"EXP\", \"COS\", \"SIN\", \"COSH\" and \"SINH\"\n");
	printf("\tai\tcoeficients of the matrix\n");
	return (0);
}

static int check_param(int argc, char **argv)
{
	if (argc == 1)
		return (84);
	if (my_strcmp(argv[1], "EXP") == 0 && my_strcmp(argv[1], "COS") == 0 &&
		my_strcmp(argv[1], "SIN") == 0 && my_strcmp(argv[1], "COSH") == 0
		&& my_strcmp(argv[1], "SINH") == 0)
		return (84);
	for (int i = 2; i < argc; i++)
		if (check_number(argv[i]) == 0)
			return (84);
	if ((argc - 2) != 1 && (argc - 2) != 4 && (argc - 2) != 9
		&& (argc - 2) != 16 && (argc - 2) != 25)
		return (84);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (84);
	if (argv[1][0] == '-' && argv[1][1] == 'h' && argc == 2 && argv[1][2] == '\0')
		return (print_help());
	if (check_param(argc, argv) == 84)
		return (84);
	if (my_strcmp(argv[1], "EXP"))
		return (my_exp(argc, argv));
	if (my_strcmp(argv[1], "COS"))
		return (my_cos(argc, argv));
	if (my_strcmp(argv[1], "SIN"))
		return (my_sin(argc, argv));
	if (my_strcmp(argv[1], "COSH"))
		return (my_cosh(argc, argv));
	if (my_strcmp(argv[1], "SINH"))
		return (my_sinh(argc, argv));
	return (84);
}